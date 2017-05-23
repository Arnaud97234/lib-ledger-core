/*
 *
 * PoolDatabaseHelper
 * ledger-core
 *
 * Created by Pierre Pollastri on 16/05/2017.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#include "PoolDatabaseHelper.hpp"
#include <utils/DateUtils.hpp>

using namespace soci;

namespace ledger {
    namespace core {

        void PoolDatabaseHelper::putWallet(soci::session &sql, const WalletDatabaseEntry &wallet) {

            auto serializeConfig = wallet.configuration->serialize();
            auto configuration = hex::toString(serializeConfig);
            if (walletExists(sql, wallet)) {
                sql << "INSERT INTO wallets VALUES(:uid, :name, :currency_name, :pool_name, :configuration)",
                        use(wallet.uid), use(wallet.name), use(wallet.currencyName), use(wallet.poolName), use(configuration);
            } else {
                sql << "UPDATE wallets SET configuration = :configuration, WHERE uid = :uid",
                use(wallet.uid), use(configuration);
            }
        }

        int64_t PoolDatabaseHelper::getWalletCount(soci::session &sql, const WalletPool &pool) {
            int64_t count;
            sql << "SELECT COUNT(*) FROM wallets WHERE pool_name = :pool", use(pool.getName()), into(count);
            return count;
        }

        int64_t PoolDatabaseHelper::getWallets(soci::session &sql, const WalletPool &pool, int64_t offset,
                                               std::vector<WalletDatabaseEntry> &wallets) {
            rowset<row> rows = (sql.prepare <<  "SELECT uid, name, currency_name, configuration WHERE pool_name = :pool "
                                                "OFFSET :offset LIMIT :count", use(pool.getName()), use(offset), use(wallets.size())
            );
            int64_t index = 0;
            for (auto& row : rows) {
                WalletDatabaseEntry entry;
                inflateWalletEntry(row, pool, entry);
                wallets[index] = entry;
                index += 1;
            }
            return index;
        }

        bool PoolDatabaseHelper::getWallet(soci::session &sql, const WalletPool &pool, const std::string &walletName,
                                           WalletDatabaseEntry &entry) {
            auto walletUid = WalletDatabaseEntry::createWalletUid(pool.getName(), walletName, entry.currencyName);
            rowset<row> rows = (sql.prepare << "SELECT uid, name, currency_name, configuration WHERE uid = :uid", use(walletUid));
            if (rows.begin() == rows.end()) {
                return false;
            } else {
                auto& row = *rows.begin();
                inflateWalletEntry(row, pool, entry);
                return true;
            }
        }

        void
        PoolDatabaseHelper::inflateWalletEntry(soci::row &row, const WalletPool &pool, WalletDatabaseEntry &entry) {
            entry.name = row.get<std::string>(0);
            entry.currencyName = row.get<std::string>(1);
            entry.poolName = pool.getName();
            auto serializedConfig = hex::toByteArray(row.get<std::string>(2));
            entry.configuration = std::static_pointer_cast<ledger::core::DynamicObject>(DynamicObject::load(serializedConfig));
        }

        bool PoolDatabaseHelper::insertPool(soci::session &sql, const WalletPool &pool) {
            auto count = 0;
            sql << "SELECT COUNT(*) FROM pools WHERE name = :name", use(pool.getName()), into(count);
            if (count == 0) {
                sql << "INSERT INTO pools VALUES(:name, :created_at)", use(pool.getName()), use(DateUtils::toJSON(DateUtils::now()));
                return true;
            }
            return false;
        }

        bool PoolDatabaseHelper::walletExists(soci::session &sql, const WalletDatabaseEntry &entry) {
            int count = 0;
            sql << "SELECT COUNT(*) FROM wallets WHERE uid = :uid", use(entry.uid), into(count);
            return count != 1;
        }

        bool PoolDatabaseHelper::removeWallet(soci::session &sql, const WalletDatabaseEntry &entry) {
            if (!walletExists(sql, entry))
                return false;
            sql << "DELETE FROM wallets WHERE uid = :uid", use(entry.uid);
            return true;
        }

    }
}