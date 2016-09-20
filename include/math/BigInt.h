/*
 *
 * BigInt
 * ledger-core
 *
 * Created by Pierre Pollastri on 15/09/2016.
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
#ifndef LEDGER_CORE_BIGINT_H
#define LEDGER_CORE_BIGINT_H

#include <string>
#include <vector>
#include <bigd.h>

namespace ledger {

    namespace core {

        class BigInt {

        public:
            static const BigInt ZERO;
            static const BigInt ONE;
            static const BigInt TEN;
            typedef unsigned int SimpleInt;
            typedef unsigned long DoubleInt;
            /**
             * Available digits for conversion to and from strings.
             */
            static const std::string DIGITS;
            /**
             * The maximum radix available for conversion to and from strings.
             */
            static const int MIN_RADIX;
            /**
             * The minimum radix available for conversion to and from strings.
             */
            static const int MAX_RADIX;

            /**
             * Creates a new BigInt from the given hexadecimal encoded string.
             * @param str The number encoded in hexadecimal (e.g. "E0A1B3")
             * @return An instance of BigInt
             */
            static BigInt* from_hex(const std::string& str);
            /**
             * Creates a new BigInt from the given decimal encoded string.
             * @param str The number encoded in decimal (e.g. "125")
             * @return
             */
            static BigInt* from_dec(const std::string& str);

        private:
            BigInt();
            BigInt(const std::string& str, int radix);

        public:
            BigInt(const BigInt& cpy);

            /**
             * Initializes a new BigInt with the given big endian data.
             * @param data The big integer data formatted in big endian
             * @param length The length of the data
             * @param negative true if the number is negative false otherwise
             */
            BigInt(const void *data, size_t length, bool negative);

            /**
             * Initializes a new BigInt with the runtime int.
             * @param value
             * @param bits
             * @return
             */
            BigInt(int value);

            /**
             * Initializes a new BigInt with the given string representation.
             * @param str
             * @return
             */
            BigInt(const std::string& str) : BigInt(str, 10) {};

            /**
             * Converts the BigInt to int
             * @return
             */
            int to_int() const;

            /**
             * Converts the BigInt to unsigned int
             * @return
             */
            unsigned to_uint() const;

            /**
             * Serializes the BigInt into a decimal std::string.
             * @param str
             * @param radix
             * @return
             */
            std::string to_string() const;

            /**
             * Serializes the BigInt into a hexadecimal std::string.
             * @return
             */
            std::string to_hex() const;

            BigInt operator+(const BigInt& rhs) const;
            BigInt operator-(const BigInt& rhs) const;
            BigInt operator*(const BigInt& rhs) const;
            BigInt operator/(const BigInt& rhs) const;
            BigInt operator%(const BigInt& rhs) const;

            const BigInt& operator++();
            const BigInt& operator--();

            const BigInt& operator=(unsigned int);
            const BigInt& operator=(unsigned long long);
            const BigInt& operator=(int);
            const BigInt& operator=(long long);
            const BigInt& operator=(unsigned long);
            const BigInt& operator=(long);

            const BigInt& operator=(const BigInt&);

            bool operator<(const BigInt&) const;
            bool operator<=(const BigInt&) const;
            bool operator==(const BigInt&) const;
            bool operator>(const BigInt&) const;
            bool operator>=(const BigInt&) const;

            unsigned long get_bit_size() const;
            bool is_negative() const;
            bool is_positive() const;

            BigInt negative() const;
            BigInt positive() const;

            virtual ~BigInt();


        private:
            BIGD _bigd;
            bool _negative;
        };
    }

}
#endif //LEDGER_CORE_BIGINT_H
