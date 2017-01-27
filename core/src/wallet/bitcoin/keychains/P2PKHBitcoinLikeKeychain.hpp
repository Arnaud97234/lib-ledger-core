/*
 *
 * P2PKHBitcoinLikeKeychain
 * ledger-core
 *
 * Created by Pierre Pollastri on 25/01/2017.
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
#ifndef LEDGER_CORE_P2PKHBITCOINLIKEKEYCHAIN_HPP
#define LEDGER_CORE_P2PKHBITCOINLIKEKEYCHAIN_HPP

#include "BitcoinLikeKeychain.hpp"

namespace ledger {
    namespace core {
        class P2PKHBitcoinLikeKeychain : public BitcoinLikeKeychain {
        public:
            P2PKHBitcoinLikeKeychain(const std::shared_ptr<api::Configuration> &configuration,
                                     const api::BitcoinLikeNetworkParameters &params, int account,
                                     const std::shared_ptr<api::BitcoinLikeExtendedPublicKey> &xpub,
                                     const std::shared_ptr<Preferences> &preferences);
            bool markAsUsed(const std::string &address) override;
            std::string getFreshAddress(KeyPurpose purpose) const override;
            std::vector<std::string> getAllObservableAddresses(off_t from, off_t to) const override;
            std::vector<std::string> getFreshAddresses(KeyPurpose purpose, size_t n) const override;
            Option<KeyPurpose> getAddressPurpose(const std::string &address) const override;
            Option<std::string> getAddressDerivationPath(const std::string &address) const override;
            std::vector<std::string> getAllObservableAddresses(KeyPurpose purpose, off_t from, off_t to) const override;

            bool isEmpty() const override;
        };
    }
}


#endif //LEDGER_CORE_P2PKHBITCOINLIKEKEYCHAIN_HPP
