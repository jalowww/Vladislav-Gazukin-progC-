#include "hash.hpp"

#if defined(__has_include)
#if __has_include("fast_hash.hpp")
#include "fast_hash.hpp"
#define USE_FAST_HASH 1
#else
#define USE_FAST_HASH 0
#endif
#else
#error "Компилятор не поддерживает __has_include"
#endif

std::uint32_t hash32(std::string_view s){
#if USE_FAST_HASH
    return fast_hash32(s);
#else
    std::uint32_t h = 0;
    for (unsigned char c : s){
        h = h * 2u + c;
    }
    return h;
#endif
}