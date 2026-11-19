#pragma once
#include "../../string/bits/char_traits.hxx"

namespace std {

template<typename CharT>
class basic_streambuf;

template<
    typename CharT,
    typename Traits = char_traits<CharT>
>
class basic_ostream {
public:
    using char_type = CharT;
    using streambuf_type = basic_streambuf<CharT>;

protected:
    streambuf_type* buffer;

public:
    explicit basic_ostream(streambuf_type* buf)
        : buffer(buf) {}

    virtual ~basic_ostream() = default;

    basic_ostream& put(char_type ch) {
        if (buffer != nullptr) {
            buffer->sputc(ch);
        }

        return *this;
    }

    basic_ostream& write(
        const char_type* data,
        long size
    ) {
        if (buffer != nullptr && data != nullptr) {
            buffer->sputn(data, size);
        }

        return *this;
    }

    basic_ostream& operator<<(char_type ch) {
        return put(ch);
    }

    basic_ostream& operator<<(const char_type* str) {
        if (str == nullptr)
            return *this;

        long length = 0;

        while (str[length] != char_type{})
            ++length;

        return write(str, length);
    }
};

using ostream = basic_ostream<char>;

}
