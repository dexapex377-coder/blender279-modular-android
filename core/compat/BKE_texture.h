#ifndef __BKE_TEXTURE_H__
#define __BKE_TEXTURE_H__

struct Tex;
struct Scene;
struct TexResult;
struct ImagePool;

bool BKE_texture_dependsOnTime(const struct Tex *texture);

void BKE_texture_get_value_ex(
        const struct Scene *scene, struct Tex *texture,
        float *tex_co, struct TexResult *texres,
        struct ImagePool *pool,
        bool use_color_management);

void BKE_texture_fetch_images_for_pool(struct Tex *texture, struct ImagePool *pool);

#endif
