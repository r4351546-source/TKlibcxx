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

    static char_type* copy(
    char_type* dest,
    const char_type* src,
    unsigned long count
    ) {
    for (unsigned long i = 0; i < count; ++i) {
        dest[i] = src[i];
    }

    return dest;
    }

    static char_type* assign(
    char_type* dest,
    unsigned long count,
    char_type ch
    ) {
    for (unsigned long i = 0; i < count; ++i) {
        dest[i] = ch;
    }

    return dest;
}


    static char_type* move(
    char_type* dest,
    const char_type* src,
    unsigned long count
    ) {
    if (dest > src) {
        for (unsigned long i = count; i > 0; --i) {
            dest[i - 1] = src[i - 1];
        }
    } 
    else {
        for (unsigned long i = 0; i < count; ++i) {
            dest[i] = src[i];
        }
    }

    return dest;
    }

    static const char_type* find(
    const char_type* str,
    unsigned long count,
    const char_type& ch
    ) {
    for (unsigned long i = 0; i < count; ++i) {
        
        if(str[i] == ch) {
            return &str[i];
        }
        
    }

    return nullptr;
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
    static int_type to_int_type(char_type ch);

    static char_type to_char_type(int_type ch);

    static bool eq_int_type(int_type c1, int_type c2);

    static int_type eof();

    static int_type not_eof(int_type ch);
    
        };
};



