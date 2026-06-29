#ifndef __BLI_UTILITY_MIXINS_HH__
#define __BLI_UTILITY_MIXINS_HH__

#include <type_traits>

namespace BLI {

template<typename T>
struct NonCopyable {
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
    NonCopyable(NonCopyable &&) = default;
    NonCopyable &operator=(NonCopyable &&) = default;
};

template<typename T>
struct NonMovable {
    NonMovable() = default;
    NonMovable(const NonMovable &) = default;
    NonMovable &operator=(const NonMovable &) = default;
    NonMovable(NonMovable &&) = delete;
    NonMovable &operator=(NonMovable &&) = delete;
};

}  // namespace BLI

#endif
