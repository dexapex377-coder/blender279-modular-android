#ifndef __BKE_IMAGE_H__
#define __BKE_IMAGE_H__

struct ImagePool;

struct ImagePool *BKE_image_pool_new(void);
void BKE_image_pool_free(struct ImagePool *pool);

#endif
