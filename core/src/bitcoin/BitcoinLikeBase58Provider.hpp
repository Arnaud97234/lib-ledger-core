/*
 *
 * BitcoinLikeBase58Provider
 * ledger-core
 *
 * Created by Pierre Pollastri on 01/03/2017.
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
#ifndef LEDGER_CORE_BITCOINLIKEBASE58PROVIDER_HPP
#define LEDGER_CORE_BITCOINLIKEBASE58PROVIDER_HPP

#include "BitcoinLikeExtendedPublicKeyProvider.hpp"

namespace ledger {
    namespace core {
        class BitcoinLikeBase58Provider : public BitcoinLikeExtendedPublicKeyProvider {
        public:
            BitcoinLikeBase58Provider(std::shared_ptr<api::BitcoinLikeBase58ExtendedPublicKeyProvider> provider);
            Future<std::shared_ptr<BitcoinLikeExtendedPublicKey>>
            get(std::shared_ptr<api::ExecutionContext> context, const std::string& deviceId, const std::string &path,
                const api::BitcoinLikeNetworkParameters &params) override;

        private:
            std::shared_ptr<api::BitcoinLikeBase58ExtendedPublicKeyProvider> _provider;
        };
    }
}


#endif //LEDGER_CORE_BITCOINLIKEBASE58PROVIDER_HPP
