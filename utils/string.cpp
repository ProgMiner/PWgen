/* MIT License

Copyright (c) 2018 Eridan Domoratskiy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include "string.h"

#include <cstring>
#include <cstdio>

std::string Utils::stringGenerator(
        const std::string & source,
        const std::string & availableChars
) {
    auto availableCharsCount = availableChars.size();

    std::string ret;
    for (std::string::size_type i = 0; i < source.size(); ++i) {
        ret.push_back(availableChars[source[i] % availableCharsCount]);
    }

    return ret;
}

std::string Utils::formatBinaryString(
        const std::string & source,
        const std::string & format
) {
    std::string ret;

    for (char c: source) {
        static char buf[9];
        snprintf(buf, 9, format.c_str(), std::char_traits <char> ::to_int_type(c));

        ret.append(buf);
    }

    return ret;
}
