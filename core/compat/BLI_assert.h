#ifndef __BLI_ASSERT_H__
#define __BLI_ASSERT_H__

#include <cassert>

#define BLI_assert(assertion) assert(assertion)
#define BLI_assert_msg(assertion, msg) assert(assertion)
#define BLI_STATIC_ASSERT(assertion, msg) static_assert(assertion, msg)
#define BLI_assert_unreachable() assert(0)

#endif
