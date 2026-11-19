#pragma once

namespace std {

template<typename CharT>
struct char_traits;

template<>
struct char_traits<char> {
    using char_type = char;
    using int_type = int;

    static void assign(char_type& c1, const char_type& c2) {
        c1 = c2;
    }

    static bool eq(const char_type& c1, const char_type& c2) {
        return c1 == c2;
    }

    static bool lt(const char_type& c1, const char_type& c2) {
        return c1 < c2;
    }

    static unsigned long length(const char_type* str) {
        unsigned long count = 0;
        while(str[count] != '\0') {
            count++;
        }
        return count;
    }

    static int compare(
    const char_type* s1,
    const char_type* s2,
    unsigned long count
    ) {
        for (unsigned long i = 0; i < count; ++i) {
        if (eq(s1[i], s2[i]))
            continue;

        if (lt(s1[i], s2[i]))
            return -1;

        return 1;
    }

    return 0;
    }
};

}
