#include "include/string/bits/char_traits.hxx"

std::char_traits<char>::int_type std::char_traits<char>::to_int_type(char ch) {
        return static_cast<unsigned char>(ch);
}


char std::char_traits<char>::to_char_type(int ch) {
    return static_cast<char>(ch);
}

std::char_traits<char>::int_type std::char_traits<char>::eof() {
    return -1;
}

bool std::char_traits<char>::eq_int_type(int c1, int c2) {
    return c1 == c2;
}

std::char_traits<char>::int_type std::char_traits<char>::not_eof(
    std::char_traits<char>::int_type ch) {
        return eq_int_type(ch, eof()) ? 0 : ch;
    }

    