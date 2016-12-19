/*
 *
 * BitcoinLikeExtendedPublicKey
 * ledger-core
 *
 * Created by Pierre Pollastri on 14/12/2016.
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
#ifndef LEDGER_CORE_BITCOINLIKEEXTENDEDPUBLICKEY_HPP
#define LEDGER_CORE_BITCOINLIKEEXTENDEDPUBLICKEY_HPP

#include "../api/BitcoinLikeExtendedPublicKey.hpp"
#include "../crypto/DeterministicPublicKey.hpp"
#include "../api/BitcoinLikeNetworkParameters.hpp"
#include <memory>
#include "../utils/optional.hpp"

namespace ledger {
    namespace core {
        class BitcoinLikeExtendedPublicKey : public api::BitcoinLikeExtendedPublicKey {
        public:
            BitcoinLikeExtendedPublicKey(const api::BitcoinLikeNetworkParameters& params,
                                         const DeterministicPublicKey& key, const std::string& path = "m/");
            virtual std::shared_ptr<api::BitcoinLikeAddress> derive(const std::string &path) override;
            virtual std::string toBase58() override;

        public:
            static std::shared_ptr<api::BitcoinLikeExtendedPublicKey> fromPublicKeyCouple(
                    const api::BitcoinLikeNetworkParameters& params,
                    const optional<std::vector<uint8_t>>& parentPublicKey,
                    const std::vector<uint8_t>& publicKey,
                    const std::string& path
            );

        private:
            const api::BitcoinLikeNetworkParameters _params;
            const std::string _path;
            const DeterministicPublicKey _key;
        };
    }
}


#endif //LEDGER_CORE_BITCOINLIKEEXTENDEDPUBLICKEY_HPP