#ifndef __BLI_ARRAY_H__
#define __BLI_ARRAY_H__

#define BLI_array_declare(arr)
#define BLI_array_init(arr)
#define BLI_array_free(arr)
#define BLI_array_reserve(arr, num)
#define BLI_array_reserve_data(arr, num)
#define BLI_array_append(arr, item) ((arr) = (arr), (void)(item))
#define BLI_array_len(arr) 0
#define BLI_array_size(arr) 0
#define BLI_array_grow_items(arr, num) ((void)(arr), (void)(num), 0)
#define BLI_array_count(arr) 0
#define BLI_array_fromstring(arr, str) ((void)(arr), (void)(str))
#define BLI_array_static_declare(arr, n)

#endif
