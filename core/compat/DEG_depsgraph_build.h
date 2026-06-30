#ifndef __DEG_DEPSGRAPH_BUILD_H__
#define __DEG_DEPSGRAPH_BUILD_H__

#ifdef __cplusplus
extern "C" {
#endif

void DEG_add_build_relation(struct DepsRelation *relation);
void DEG_graph_build_finalize(struct Depsgraph *graph);

#ifdef __cplusplus
}
#endif

#endif
