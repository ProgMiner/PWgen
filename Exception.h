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

#pragma once

#include <exception>
#include <string>

class Exception {

public:
    Exception(std::string && msg):
        msg(std::move(msg))
    {}

    Exception(std::string && msg, Exception && previous):
        msg(std::move(msg)),
        previous(new Exception(std::move(previous)))
    {}

    Exception(const std::exception & ex):
        Exception(ex.what())
    {}

    Exception(const Exception & ex):
        msg(ex.msg),
        previous(ex.previous)
    {}
    Exception(Exception && ex):
        msg(std::move(ex.msg)),
        previous(std::move(ex.previous))
    {}

    virtual ~Exception() {
        delete previous;
    }

    inline const std::string & getMessage() const {
        return msg;
    }

    inline const Exception * getPrevious() const {
        return previous;
    }

protected:
    std::string msg;

    Exception * previous = nullptr;
};
