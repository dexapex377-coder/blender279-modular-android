#ifndef __EIGEN_CAPI_H__
#define __EIGEN_CAPI_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LinearSolver LinearSolver;

LinearSolver *EIG_linear_least_squares_solver_new(int num_rows, int num_cols, int num_rhs);
void EIG_linear_solver_delete(LinearSolver *solver);
void EIG_linear_solver_matrix_add(LinearSolver *solver, int row, int col, float value);
void EIG_linear_solver_right_hand_side_add(LinearSolver *solver, int rhs, int row, float value);
int EIG_linear_solver_solve(LinearSolver *solver);
float EIG_linear_solver_variable_get(LinearSolver *solver, int rhs, int col);

#ifdef __cplusplus
}
#endif

#endif
