#ifndef __NOD_SHADER_H__
#define __NOD_SHADER_H__

#ifdef __cplusplus
extern "C" {
#endif

struct bNodeTree;

void ntreeShaderUpdateGPUPass(struct bNodeTree *ntree, void *data);
void ntreeShaderGPUNodesPoll(struct bNodeTree *ntree);

#ifdef __cplusplus
}
#endif

#endif
