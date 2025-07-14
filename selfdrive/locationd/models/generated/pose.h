#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_94094168798460134);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3348610880049505179);
void pose_H_mod_fun(double *state, double *out_7120226160270434944);
void pose_f_fun(double *state, double dt, double *out_6729064377130509881);
void pose_F_fun(double *state, double dt, double *out_256971012135667059);
void pose_h_4(double *state, double *unused, double *out_8596587095692993094);
void pose_H_4(double *state, double *unused, double *out_8318173642153333048);
void pose_h_10(double *state, double *unused, double *out_8419119128219239034);
void pose_H_10(double *state, double *unused, double *out_2391957346662021133);
void pose_h_13(double *state, double *unused, double *out_2811919948298635006);
void pose_H_13(double *state, double *unused, double *out_6916296606223885767);
void pose_h_14(double *state, double *unused, double *out_7300738768633822776);
void pose_H_14(double *state, double *unused, double *out_6165329575216734039);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}