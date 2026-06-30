#ifndef __BLI_THREADS_H__
#define __BLI_THREADS_H__

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef pthread_rwlock_t ThreadRWMutex;

#define PTHREAD_RWLOCK_INITIALIZER PTHREAD_RWLOCK_INITIALIZER

enum {
    THREAD_LOCK_READ = 0,
    THREAD_LOCK_WRITE = 1,
};

typedef struct SpinLock {
    pthread_spinlock_t lock;
} SpinLock;

typedef pthread_mutex_t BLI_mutex;
typedef pthread_cond_t BLI_cond;

void BLI_spin_init(SpinLock *spin);
void BLI_spin_lock(SpinLock *spin);
void BLI_spin_unlock(SpinLock *spin);
void BLI_spin_end(SpinLock *spin);

int BLI_thread_is_main(void);
void BLI_thread_profiling_begin(int *line);
void BLI_thread_profiling_end(int line);
void BLI_thread_profiling_remove_thread(void);

struct TaskPool;
typedef struct TaskPool TaskPool;

typedef void (*TaskRunFunction)(TaskPool *pool, void *taskdata, int threadid);
typedef void (*TaskFreeFunction)(TaskPool *pool, void *taskdata, int threadid);

TaskPool *BLI_task_pool_create(int numthreads);
void BLI_task_pool_free(TaskPool *pool);
void BLI_task_pool_push(TaskPool *pool, TaskRunFunction run, void *taskdata, int flag, TaskFreeFunction free_func);
void BLI_task_pool_work_and_wait(TaskPool *pool);

int BLI_available_num_threads(void);
void BLI_init_threads(void);

#ifdef __cplusplus
}
#endif

#endif
