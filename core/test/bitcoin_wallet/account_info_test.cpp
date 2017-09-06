/*
 *
 * bitcoin_like_account_info_test.cpp.cpp
 * ledger-core
 *
 * Created by Pierre Pollastri on 06/09/2017.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Ledger
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

#include <gtest/gtest.h>
#include <async/QtThreadDispatcher.hpp>
#include <src/database/DatabaseSessionPool.hpp>
#include <NativePathResolver.hpp>
#include <unordered_set>
#include <src/wallet/pool/WalletPool.hpp>
#include <CoutLogPrinter.hpp>
#include <src/api/DynamicObject.hpp>
#include <wallet/common/CurrencyBuilder.hpp>
#include <wallet/bitcoin/BitcoinLikeWallet.hpp>
#include <wallet/bitcoin/database/BitcoinLikeWalletDatabase.h>
#include <wallet/bitcoin/database/BitcoinLikeTransactionDatabaseHelper.h>
#include <wallet/common/database/AccountDatabaseHelper.h>
#include <wallet/pool/database/PoolDatabaseHelper.hpp>
#include <utils/JSONUtils.h>
#include <wallet/bitcoin/explorers/api/TransactionParser.hpp>
#include <async/async_wait.h>
#include <BitcoinLikeStringXpubProvider.h>
#include <api/BitcoinLikeExtendedPublicKeyProvider.hpp>
#include <wallet/bitcoin/BitcoinLikeAccount.hpp>
#include <api/BitcoinLikeOperation.hpp>
#include <api/BitcoinLikeTransaction.hpp>
#include <api/BitcoinLikeInput.hpp>
#include <api/BitcoinLikeOutput.hpp>
#include <api/BigInt.hpp>

using namespace ledger::core;
using namespace ledger::qt;

#include "../fixtures/fixtures_1.h"
#include "../fixtures/bitcoin_helpers.h"

TEST(BitcoinLikeAccountInfo, FirstAccountInfo) {
    auto dispatcher = std::make_shared<QtThreadDispatcher>();
    auto resolver = std::make_shared<NativePathResolver>();
    auto backend = std::static_pointer_cast<DatabaseBackend>(DatabaseBackend::getSqlite3Backend());
    auto printer = std::make_shared<CoutLogPrinter>(dispatcher->getMainExecutionContext());
    auto newPool = [&]() -> std::shared_ptr<WalletPool> {
        return WalletPool::newInstance(
                "my_pool",
                Option<std::string>::NONE,
                nullptr,
                nullptr,
                resolver,
                printer,
                dispatcher,
                nullptr,
                backend,
                api::DynamicObject::newInstance()
        );
    };
    {
        auto pool = newPool();
        auto wallet = wait(pool->createWallet("my_wallet", "bitcoin", api::DynamicObject::newInstance()));
        auto nextIndex = wait(wallet->getNextAccountIndex());
        EXPECT_EQ(nextIndex, 0);
        {
            auto info = wait(std::dynamic_pointer_cast<BitcoinLikeWallet>(wallet)->getNextAccountInfo());
            EXPECT_EQ(info.xpubPath, "44'/0'/0'");
            EXPECT_EQ(info.parentNodePath, "44'/0'");
            EXPECT_EQ(info.index, 0);
            EXPECT_EQ(info.accountNodePath, "44'/0'/0'");
        }
        auto account = std::dynamic_pointer_cast<BitcoinLikeAccount>(wait(std::dynamic_pointer_cast<BitcoinLikeWallet>(wallet->asBitcoinLikeWallet())->createNewAccount(nextIndex, XPUB_PROVIDER)));
        {
            auto info = wait(std::dynamic_pointer_cast<BitcoinLikeWallet>(wallet)->getNextAccountInfo());
            EXPECT_EQ(info.xpubPath, "44'/0'/1'");
            EXPECT_EQ(info.parentNodePath, "44'/0'");
            EXPECT_EQ(info.index, 1);
            EXPECT_EQ(info.accountNodePath, "44'/0'/1'");
        }
    }
    resolver->clean();
}