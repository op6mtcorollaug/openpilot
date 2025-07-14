#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_4190163838388709403);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4047551892391189593);
void car_H_mod_fun(double *state, double *out_4078273290791504056);
void car_f_fun(double *state, double dt, double *out_9009648031843895427);
void car_F_fun(double *state, double dt, double *out_8180209588490338407);
void car_h_25(double *state, double *unused, double *out_7452504674613984578);
void car_H_25(double *state, double *unused, double *out_4953582035130507036);
void car_h_24(double *state, double *unused, double *out_6860052178335798425);
void car_H_24(double *state, double *unused, double *out_8511507633932830172);
void car_h_30(double *state, double *unused, double *out_7727698736898490467);
void car_H_30(double *state, double *unused, double *out_7471914993637755663);
void car_h_26(double *state, double *unused, double *out_8114640016002363498);
void car_H_26(double *state, double *unused, double *out_8258108004891307637);
void car_h_27(double *state, double *unused, double *out_5992566131434721393);
void car_H_27(double *state, double *unused, double *out_5297151681837330752);
void car_h_29(double *state, double *unused, double *out_4690912685454157782);
void car_H_29(double *state, double *unused, double *out_7982146337952147847);
void car_h_28(double *state, double *unused, double *out_6936075984336383828);
void car_H_28(double *state, double *unused, double *out_2899747320882617273);
void car_h_31(double *state, double *unused, double *out_2497578717831827046);
void car_H_31(double *state, double *unused, double *out_7631899902657956161);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}