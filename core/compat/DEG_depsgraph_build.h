#ifndef __DEG_DEPSGRAPH_BUILD_H__
#define __DEG_DEPSGRAPH_BUILD_H__

#ifdef __cplusplus
extern "C" {
#endif

enum {
    DEG_OB_COMP_TRANSFORM = 0,
    DEG_OB_COMP_EVAL_POSE = 1,
    DEG_OB_COMP_GEOMETRY = 2,
};

void DEG_add_build_relation(struct DepsRelation *relation);
void DEG_graph_build_finalize(struct Depsgraph *graph);

#ifdef __cplusplus
}
#endif

#endif
