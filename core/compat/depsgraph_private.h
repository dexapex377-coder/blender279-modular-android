#ifndef __DEPSGRAPH_PRIVATE_H__
#define __DEPSGRAPH_PRIVATE_H__

#include "BKE_main.h"
#include "DNA_listBase.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Old DAG (dependency graph) types */
typedef struct DagAdjList {
    struct DagNode *node;
    short type;
    int count;
    unsigned int lay;
    const char *name;
    struct DagAdjList *next;
} DagAdjList;

typedef struct DagNode {
    int color;
    short type;
    float x, y, k;
    void *ob;
    void *first_ancestor;
    int ancestor_count;
    unsigned int lay;
    unsigned int scelay;
    uint64_t customdata_mask;
    int lasttime;
    int BFS_dist;
    int DFS_dist;
    int DFS_dvtm;
    int DFS_fntm;
    struct DagAdjList *child;
    struct DagAdjList *parent;
    struct DagNode *next;
    uint32_t num_pending_parents;
    bool scheduled;
    short eval_flags;
} DagNode;

typedef struct DagForest {
    ListBase DagNode;
    void *nodeHash;
    int numNodes;
    bool is_acyclic;
    int time;
    bool ugly_hack_sorry;
    bool need_update;
} DagForest;

DagNode *dag_get_node(DagForest *forest, void *fob);
void dag_add_relation(DagForest *forest, DagNode *fob1, DagNode *fob2, short rel, const char *name);

#define DAG_RL_OB_OB        (1 << 1)
#define DAG_RL_DATA_OB      (1 << 2)
#define DAG_RL_OB_DATA      (1 << 3)
#define DAG_RL_DATA_DATA    (1 << 5)

/* New depsgraph types */
typedef struct Depsgraph Depsgraph;
typedef struct DepsNode DepsNode;
typedef struct DepsRelation DepsRelation;

enum {
    DAG_EVAL_NEED_CURVE_PATH = 1,
};

void DEG_id_type_tag(struct Main *bmain, int id_type);
void DEG_relations_tag_update(struct Main *bmain);
void DEG_add_special_eval_flag(struct Depsgraph *depsgraph, struct ID *id, short flag);

#ifdef __cplusplus
}
#endif

#endif