#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4190163838388709403) {
   out_4190163838388709403[0] = delta_x[0] + nom_x[0];
   out_4190163838388709403[1] = delta_x[1] + nom_x[1];
   out_4190163838388709403[2] = delta_x[2] + nom_x[2];
   out_4190163838388709403[3] = delta_x[3] + nom_x[3];
   out_4190163838388709403[4] = delta_x[4] + nom_x[4];
   out_4190163838388709403[5] = delta_x[5] + nom_x[5];
   out_4190163838388709403[6] = delta_x[6] + nom_x[6];
   out_4190163838388709403[7] = delta_x[7] + nom_x[7];
   out_4190163838388709403[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4047551892391189593) {
   out_4047551892391189593[0] = -nom_x[0] + true_x[0];
   out_4047551892391189593[1] = -nom_x[1] + true_x[1];
   out_4047551892391189593[2] = -nom_x[2] + true_x[2];
   out_4047551892391189593[3] = -nom_x[3] + true_x[3];
   out_4047551892391189593[4] = -nom_x[4] + true_x[4];
   out_4047551892391189593[5] = -nom_x[5] + true_x[5];
   out_4047551892391189593[6] = -nom_x[6] + true_x[6];
   out_4047551892391189593[7] = -nom_x[7] + true_x[7];
   out_4047551892391189593[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4078273290791504056) {
   out_4078273290791504056[0] = 1.0;
   out_4078273290791504056[1] = 0.0;
   out_4078273290791504056[2] = 0.0;
   out_4078273290791504056[3] = 0.0;
   out_4078273290791504056[4] = 0.0;
   out_4078273290791504056[5] = 0.0;
   out_4078273290791504056[6] = 0.0;
   out_4078273290791504056[7] = 0.0;
   out_4078273290791504056[8] = 0.0;
   out_4078273290791504056[9] = 0.0;
   out_4078273290791504056[10] = 1.0;
   out_4078273290791504056[11] = 0.0;
   out_4078273290791504056[12] = 0.0;
   out_4078273290791504056[13] = 0.0;
   out_4078273290791504056[14] = 0.0;
   out_4078273290791504056[15] = 0.0;
   out_4078273290791504056[16] = 0.0;
   out_4078273290791504056[17] = 0.0;
   out_4078273290791504056[18] = 0.0;
   out_4078273290791504056[19] = 0.0;
   out_4078273290791504056[20] = 1.0;
   out_4078273290791504056[21] = 0.0;
   out_4078273290791504056[22] = 0.0;
   out_4078273290791504056[23] = 0.0;
   out_4078273290791504056[24] = 0.0;
   out_4078273290791504056[25] = 0.0;
   out_4078273290791504056[26] = 0.0;
   out_4078273290791504056[27] = 0.0;
   out_4078273290791504056[28] = 0.0;
   out_4078273290791504056[29] = 0.0;
   out_4078273290791504056[30] = 1.0;
   out_4078273290791504056[31] = 0.0;
   out_4078273290791504056[32] = 0.0;
   out_4078273290791504056[33] = 0.0;
   out_4078273290791504056[34] = 0.0;
   out_4078273290791504056[35] = 0.0;
   out_4078273290791504056[36] = 0.0;
   out_4078273290791504056[37] = 0.0;
   out_4078273290791504056[38] = 0.0;
   out_4078273290791504056[39] = 0.0;
   out_4078273290791504056[40] = 1.0;
   out_4078273290791504056[41] = 0.0;
   out_4078273290791504056[42] = 0.0;
   out_4078273290791504056[43] = 0.0;
   out_4078273290791504056[44] = 0.0;
   out_4078273290791504056[45] = 0.0;
   out_4078273290791504056[46] = 0.0;
   out_4078273290791504056[47] = 0.0;
   out_4078273290791504056[48] = 0.0;
   out_4078273290791504056[49] = 0.0;
   out_4078273290791504056[50] = 1.0;
   out_4078273290791504056[51] = 0.0;
   out_4078273290791504056[52] = 0.0;
   out_4078273290791504056[53] = 0.0;
   out_4078273290791504056[54] = 0.0;
   out_4078273290791504056[55] = 0.0;
   out_4078273290791504056[56] = 0.0;
   out_4078273290791504056[57] = 0.0;
   out_4078273290791504056[58] = 0.0;
   out_4078273290791504056[59] = 0.0;
   out_4078273290791504056[60] = 1.0;
   out_4078273290791504056[61] = 0.0;
   out_4078273290791504056[62] = 0.0;
   out_4078273290791504056[63] = 0.0;
   out_4078273290791504056[64] = 0.0;
   out_4078273290791504056[65] = 0.0;
   out_4078273290791504056[66] = 0.0;
   out_4078273290791504056[67] = 0.0;
   out_4078273290791504056[68] = 0.0;
   out_4078273290791504056[69] = 0.0;
   out_4078273290791504056[70] = 1.0;
   out_4078273290791504056[71] = 0.0;
   out_4078273290791504056[72] = 0.0;
   out_4078273290791504056[73] = 0.0;
   out_4078273290791504056[74] = 0.0;
   out_4078273290791504056[75] = 0.0;
   out_4078273290791504056[76] = 0.0;
   out_4078273290791504056[77] = 0.0;
   out_4078273290791504056[78] = 0.0;
   out_4078273290791504056[79] = 0.0;
   out_4078273290791504056[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_9009648031843895427) {
   out_9009648031843895427[0] = state[0];
   out_9009648031843895427[1] = state[1];
   out_9009648031843895427[2] = state[2];
   out_9009648031843895427[3] = state[3];
   out_9009648031843895427[4] = state[4];
   out_9009648031843895427[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_9009648031843895427[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_9009648031843895427[7] = state[7];
   out_9009648031843895427[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8180209588490338407) {
   out_8180209588490338407[0] = 1;
   out_8180209588490338407[1] = 0;
   out_8180209588490338407[2] = 0;
   out_8180209588490338407[3] = 0;
   out_8180209588490338407[4] = 0;
   out_8180209588490338407[5] = 0;
   out_8180209588490338407[6] = 0;
   out_8180209588490338407[7] = 0;
   out_8180209588490338407[8] = 0;
   out_8180209588490338407[9] = 0;
   out_8180209588490338407[10] = 1;
   out_8180209588490338407[11] = 0;
   out_8180209588490338407[12] = 0;
   out_8180209588490338407[13] = 0;
   out_8180209588490338407[14] = 0;
   out_8180209588490338407[15] = 0;
   out_8180209588490338407[16] = 0;
   out_8180209588490338407[17] = 0;
   out_8180209588490338407[18] = 0;
   out_8180209588490338407[19] = 0;
   out_8180209588490338407[20] = 1;
   out_8180209588490338407[21] = 0;
   out_8180209588490338407[22] = 0;
   out_8180209588490338407[23] = 0;
   out_8180209588490338407[24] = 0;
   out_8180209588490338407[25] = 0;
   out_8180209588490338407[26] = 0;
   out_8180209588490338407[27] = 0;
   out_8180209588490338407[28] = 0;
   out_8180209588490338407[29] = 0;
   out_8180209588490338407[30] = 1;
   out_8180209588490338407[31] = 0;
   out_8180209588490338407[32] = 0;
   out_8180209588490338407[33] = 0;
   out_8180209588490338407[34] = 0;
   out_8180209588490338407[35] = 0;
   out_8180209588490338407[36] = 0;
   out_8180209588490338407[37] = 0;
   out_8180209588490338407[38] = 0;
   out_8180209588490338407[39] = 0;
   out_8180209588490338407[40] = 1;
   out_8180209588490338407[41] = 0;
   out_8180209588490338407[42] = 0;
   out_8180209588490338407[43] = 0;
   out_8180209588490338407[44] = 0;
   out_8180209588490338407[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8180209588490338407[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8180209588490338407[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8180209588490338407[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8180209588490338407[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8180209588490338407[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8180209588490338407[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8180209588490338407[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8180209588490338407[53] = -9.8000000000000007*dt;
   out_8180209588490338407[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8180209588490338407[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8180209588490338407[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8180209588490338407[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8180209588490338407[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8180209588490338407[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8180209588490338407[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8180209588490338407[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8180209588490338407[62] = 0;
   out_8180209588490338407[63] = 0;
   out_8180209588490338407[64] = 0;
   out_8180209588490338407[65] = 0;
   out_8180209588490338407[66] = 0;
   out_8180209588490338407[67] = 0;
   out_8180209588490338407[68] = 0;
   out_8180209588490338407[69] = 0;
   out_8180209588490338407[70] = 1;
   out_8180209588490338407[71] = 0;
   out_8180209588490338407[72] = 0;
   out_8180209588490338407[73] = 0;
   out_8180209588490338407[74] = 0;
   out_8180209588490338407[75] = 0;
   out_8180209588490338407[76] = 0;
   out_8180209588490338407[77] = 0;
   out_8180209588490338407[78] = 0;
   out_8180209588490338407[79] = 0;
   out_8180209588490338407[80] = 1;
}
void h_25(double *state, double *unused, double *out_7452504674613984578) {
   out_7452504674613984578[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4953582035130507036) {
   out_4953582035130507036[0] = 0;
   out_4953582035130507036[1] = 0;
   out_4953582035130507036[2] = 0;
   out_4953582035130507036[3] = 0;
   out_4953582035130507036[4] = 0;
   out_4953582035130507036[5] = 0;
   out_4953582035130507036[6] = 1;
   out_4953582035130507036[7] = 0;
   out_4953582035130507036[8] = 0;
}
void h_24(double *state, double *unused, double *out_6860052178335798425) {
   out_6860052178335798425[0] = state[4];
   out_6860052178335798425[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8511507633932830172) {
   out_8511507633932830172[0] = 0;
   out_8511507633932830172[1] = 0;
   out_8511507633932830172[2] = 0;
   out_8511507633932830172[3] = 0;
   out_8511507633932830172[4] = 1;
   out_8511507633932830172[5] = 0;
   out_8511507633932830172[6] = 0;
   out_8511507633932830172[7] = 0;
   out_8511507633932830172[8] = 0;
   out_8511507633932830172[9] = 0;
   out_8511507633932830172[10] = 0;
   out_8511507633932830172[11] = 0;
   out_8511507633932830172[12] = 0;
   out_8511507633932830172[13] = 0;
   out_8511507633932830172[14] = 1;
   out_8511507633932830172[15] = 0;
   out_8511507633932830172[16] = 0;
   out_8511507633932830172[17] = 0;
}
void h_30(double *state, double *unused, double *out_7727698736898490467) {
   out_7727698736898490467[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7471914993637755663) {
   out_7471914993637755663[0] = 0;
   out_7471914993637755663[1] = 0;
   out_7471914993637755663[2] = 0;
   out_7471914993637755663[3] = 0;
   out_7471914993637755663[4] = 1;
   out_7471914993637755663[5] = 0;
   out_7471914993637755663[6] = 0;
   out_7471914993637755663[7] = 0;
   out_7471914993637755663[8] = 0;
}
void h_26(double *state, double *unused, double *out_8114640016002363498) {
   out_8114640016002363498[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8258108004891307637) {
   out_8258108004891307637[0] = 0;
   out_8258108004891307637[1] = 0;
   out_8258108004891307637[2] = 0;
   out_8258108004891307637[3] = 0;
   out_8258108004891307637[4] = 0;
   out_8258108004891307637[5] = 0;
   out_8258108004891307637[6] = 0;
   out_8258108004891307637[7] = 1;
   out_8258108004891307637[8] = 0;
}
void h_27(double *state, double *unused, double *out_5992566131434721393) {
   out_5992566131434721393[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5297151681837330752) {
   out_5297151681837330752[0] = 0;
   out_5297151681837330752[1] = 0;
   out_5297151681837330752[2] = 0;
   out_5297151681837330752[3] = 1;
   out_5297151681837330752[4] = 0;
   out_5297151681837330752[5] = 0;
   out_5297151681837330752[6] = 0;
   out_5297151681837330752[7] = 0;
   out_5297151681837330752[8] = 0;
}
void h_29(double *state, double *unused, double *out_4690912685454157782) {
   out_4690912685454157782[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7982146337952147847) {
   out_7982146337952147847[0] = 0;
   out_7982146337952147847[1] = 1;
   out_7982146337952147847[2] = 0;
   out_7982146337952147847[3] = 0;
   out_7982146337952147847[4] = 0;
   out_7982146337952147847[5] = 0;
   out_7982146337952147847[6] = 0;
   out_7982146337952147847[7] = 0;
   out_7982146337952147847[8] = 0;
}
void h_28(double *state, double *unused, double *out_6936075984336383828) {
   out_6936075984336383828[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2899747320882617273) {
   out_2899747320882617273[0] = 1;
   out_2899747320882617273[1] = 0;
   out_2899747320882617273[2] = 0;
   out_2899747320882617273[3] = 0;
   out_2899747320882617273[4] = 0;
   out_2899747320882617273[5] = 0;
   out_2899747320882617273[6] = 0;
   out_2899747320882617273[7] = 0;
   out_2899747320882617273[8] = 0;
}
void h_31(double *state, double *unused, double *out_2497578717831827046) {
   out_2497578717831827046[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7631899902657956161) {
   out_7631899902657956161[0] = 0;
   out_7631899902657956161[1] = 0;
   out_7631899902657956161[2] = 0;
   out_7631899902657956161[3] = 0;
   out_7631899902657956161[4] = 0;
   out_7631899902657956161[5] = 0;
   out_7631899902657956161[6] = 0;
   out_7631899902657956161[7] = 0;
   out_7631899902657956161[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4190163838388709403) {
  err_fun(nom_x, delta_x, out_4190163838388709403);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4047551892391189593) {
  inv_err_fun(nom_x, true_x, out_4047551892391189593);
}
void car_H_mod_fun(double *state, double *out_4078273290791504056) {
  H_mod_fun(state, out_4078273290791504056);
}
void car_f_fun(double *state, double dt, double *out_9009648031843895427) {
  f_fun(state,  dt, out_9009648031843895427);
}
void car_F_fun(double *state, double dt, double *out_8180209588490338407) {
  F_fun(state,  dt, out_8180209588490338407);
}
void car_h_25(double *state, double *unused, double *out_7452504674613984578) {
  h_25(state, unused, out_7452504674613984578);
}
void car_H_25(double *state, double *unused, double *out_4953582035130507036) {
  H_25(state, unused, out_4953582035130507036);
}
void car_h_24(double *state, double *unused, double *out_6860052178335798425) {
  h_24(state, unused, out_6860052178335798425);
}
void car_H_24(double *state, double *unused, double *out_8511507633932830172) {
  H_24(state, unused, out_8511507633932830172);
}
void car_h_30(double *state, double *unused, double *out_7727698736898490467) {
  h_30(state, unused, out_7727698736898490467);
}
void car_H_30(double *state, double *unused, double *out_7471914993637755663) {
  H_30(state, unused, out_7471914993637755663);
}
void car_h_26(double *state, double *unused, double *out_8114640016002363498) {
  h_26(state, unused, out_8114640016002363498);
}
void car_H_26(double *state, double *unused, double *out_8258108004891307637) {
  H_26(state, unused, out_8258108004891307637);
}
void car_h_27(double *state, double *unused, double *out_5992566131434721393) {
  h_27(state, unused, out_5992566131434721393);
}
void car_H_27(double *state, double *unused, double *out_5297151681837330752) {
  H_27(state, unused, out_5297151681837330752);
}
void car_h_29(double *state, double *unused, double *out_4690912685454157782) {
  h_29(state, unused, out_4690912685454157782);
}
void car_H_29(double *state, double *unused, double *out_7982146337952147847) {
  H_29(state, unused, out_7982146337952147847);
}
void car_h_28(double *state, double *unused, double *out_6936075984336383828) {
  h_28(state, unused, out_6936075984336383828);
}
void car_H_28(double *state, double *unused, double *out_2899747320882617273) {
  H_28(state, unused, out_2899747320882617273);
}
void car_h_31(double *state, double *unused, double *out_2497578717831827046) {
  h_31(state, unused, out_2497578717831827046);
}
void car_H_31(double *state, double *unused, double *out_7631899902657956161) {
  H_31(state, unused, out_7631899902657956161);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
