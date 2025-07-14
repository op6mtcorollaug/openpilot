#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_94094168798460134) {
   out_94094168798460134[0] = delta_x[0] + nom_x[0];
   out_94094168798460134[1] = delta_x[1] + nom_x[1];
   out_94094168798460134[2] = delta_x[2] + nom_x[2];
   out_94094168798460134[3] = delta_x[3] + nom_x[3];
   out_94094168798460134[4] = delta_x[4] + nom_x[4];
   out_94094168798460134[5] = delta_x[5] + nom_x[5];
   out_94094168798460134[6] = delta_x[6] + nom_x[6];
   out_94094168798460134[7] = delta_x[7] + nom_x[7];
   out_94094168798460134[8] = delta_x[8] + nom_x[8];
   out_94094168798460134[9] = delta_x[9] + nom_x[9];
   out_94094168798460134[10] = delta_x[10] + nom_x[10];
   out_94094168798460134[11] = delta_x[11] + nom_x[11];
   out_94094168798460134[12] = delta_x[12] + nom_x[12];
   out_94094168798460134[13] = delta_x[13] + nom_x[13];
   out_94094168798460134[14] = delta_x[14] + nom_x[14];
   out_94094168798460134[15] = delta_x[15] + nom_x[15];
   out_94094168798460134[16] = delta_x[16] + nom_x[16];
   out_94094168798460134[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3348610880049505179) {
   out_3348610880049505179[0] = -nom_x[0] + true_x[0];
   out_3348610880049505179[1] = -nom_x[1] + true_x[1];
   out_3348610880049505179[2] = -nom_x[2] + true_x[2];
   out_3348610880049505179[3] = -nom_x[3] + true_x[3];
   out_3348610880049505179[4] = -nom_x[4] + true_x[4];
   out_3348610880049505179[5] = -nom_x[5] + true_x[5];
   out_3348610880049505179[6] = -nom_x[6] + true_x[6];
   out_3348610880049505179[7] = -nom_x[7] + true_x[7];
   out_3348610880049505179[8] = -nom_x[8] + true_x[8];
   out_3348610880049505179[9] = -nom_x[9] + true_x[9];
   out_3348610880049505179[10] = -nom_x[10] + true_x[10];
   out_3348610880049505179[11] = -nom_x[11] + true_x[11];
   out_3348610880049505179[12] = -nom_x[12] + true_x[12];
   out_3348610880049505179[13] = -nom_x[13] + true_x[13];
   out_3348610880049505179[14] = -nom_x[14] + true_x[14];
   out_3348610880049505179[15] = -nom_x[15] + true_x[15];
   out_3348610880049505179[16] = -nom_x[16] + true_x[16];
   out_3348610880049505179[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7120226160270434944) {
   out_7120226160270434944[0] = 1.0;
   out_7120226160270434944[1] = 0.0;
   out_7120226160270434944[2] = 0.0;
   out_7120226160270434944[3] = 0.0;
   out_7120226160270434944[4] = 0.0;
   out_7120226160270434944[5] = 0.0;
   out_7120226160270434944[6] = 0.0;
   out_7120226160270434944[7] = 0.0;
   out_7120226160270434944[8] = 0.0;
   out_7120226160270434944[9] = 0.0;
   out_7120226160270434944[10] = 0.0;
   out_7120226160270434944[11] = 0.0;
   out_7120226160270434944[12] = 0.0;
   out_7120226160270434944[13] = 0.0;
   out_7120226160270434944[14] = 0.0;
   out_7120226160270434944[15] = 0.0;
   out_7120226160270434944[16] = 0.0;
   out_7120226160270434944[17] = 0.0;
   out_7120226160270434944[18] = 0.0;
   out_7120226160270434944[19] = 1.0;
   out_7120226160270434944[20] = 0.0;
   out_7120226160270434944[21] = 0.0;
   out_7120226160270434944[22] = 0.0;
   out_7120226160270434944[23] = 0.0;
   out_7120226160270434944[24] = 0.0;
   out_7120226160270434944[25] = 0.0;
   out_7120226160270434944[26] = 0.0;
   out_7120226160270434944[27] = 0.0;
   out_7120226160270434944[28] = 0.0;
   out_7120226160270434944[29] = 0.0;
   out_7120226160270434944[30] = 0.0;
   out_7120226160270434944[31] = 0.0;
   out_7120226160270434944[32] = 0.0;
   out_7120226160270434944[33] = 0.0;
   out_7120226160270434944[34] = 0.0;
   out_7120226160270434944[35] = 0.0;
   out_7120226160270434944[36] = 0.0;
   out_7120226160270434944[37] = 0.0;
   out_7120226160270434944[38] = 1.0;
   out_7120226160270434944[39] = 0.0;
   out_7120226160270434944[40] = 0.0;
   out_7120226160270434944[41] = 0.0;
   out_7120226160270434944[42] = 0.0;
   out_7120226160270434944[43] = 0.0;
   out_7120226160270434944[44] = 0.0;
   out_7120226160270434944[45] = 0.0;
   out_7120226160270434944[46] = 0.0;
   out_7120226160270434944[47] = 0.0;
   out_7120226160270434944[48] = 0.0;
   out_7120226160270434944[49] = 0.0;
   out_7120226160270434944[50] = 0.0;
   out_7120226160270434944[51] = 0.0;
   out_7120226160270434944[52] = 0.0;
   out_7120226160270434944[53] = 0.0;
   out_7120226160270434944[54] = 0.0;
   out_7120226160270434944[55] = 0.0;
   out_7120226160270434944[56] = 0.0;
   out_7120226160270434944[57] = 1.0;
   out_7120226160270434944[58] = 0.0;
   out_7120226160270434944[59] = 0.0;
   out_7120226160270434944[60] = 0.0;
   out_7120226160270434944[61] = 0.0;
   out_7120226160270434944[62] = 0.0;
   out_7120226160270434944[63] = 0.0;
   out_7120226160270434944[64] = 0.0;
   out_7120226160270434944[65] = 0.0;
   out_7120226160270434944[66] = 0.0;
   out_7120226160270434944[67] = 0.0;
   out_7120226160270434944[68] = 0.0;
   out_7120226160270434944[69] = 0.0;
   out_7120226160270434944[70] = 0.0;
   out_7120226160270434944[71] = 0.0;
   out_7120226160270434944[72] = 0.0;
   out_7120226160270434944[73] = 0.0;
   out_7120226160270434944[74] = 0.0;
   out_7120226160270434944[75] = 0.0;
   out_7120226160270434944[76] = 1.0;
   out_7120226160270434944[77] = 0.0;
   out_7120226160270434944[78] = 0.0;
   out_7120226160270434944[79] = 0.0;
   out_7120226160270434944[80] = 0.0;
   out_7120226160270434944[81] = 0.0;
   out_7120226160270434944[82] = 0.0;
   out_7120226160270434944[83] = 0.0;
   out_7120226160270434944[84] = 0.0;
   out_7120226160270434944[85] = 0.0;
   out_7120226160270434944[86] = 0.0;
   out_7120226160270434944[87] = 0.0;
   out_7120226160270434944[88] = 0.0;
   out_7120226160270434944[89] = 0.0;
   out_7120226160270434944[90] = 0.0;
   out_7120226160270434944[91] = 0.0;
   out_7120226160270434944[92] = 0.0;
   out_7120226160270434944[93] = 0.0;
   out_7120226160270434944[94] = 0.0;
   out_7120226160270434944[95] = 1.0;
   out_7120226160270434944[96] = 0.0;
   out_7120226160270434944[97] = 0.0;
   out_7120226160270434944[98] = 0.0;
   out_7120226160270434944[99] = 0.0;
   out_7120226160270434944[100] = 0.0;
   out_7120226160270434944[101] = 0.0;
   out_7120226160270434944[102] = 0.0;
   out_7120226160270434944[103] = 0.0;
   out_7120226160270434944[104] = 0.0;
   out_7120226160270434944[105] = 0.0;
   out_7120226160270434944[106] = 0.0;
   out_7120226160270434944[107] = 0.0;
   out_7120226160270434944[108] = 0.0;
   out_7120226160270434944[109] = 0.0;
   out_7120226160270434944[110] = 0.0;
   out_7120226160270434944[111] = 0.0;
   out_7120226160270434944[112] = 0.0;
   out_7120226160270434944[113] = 0.0;
   out_7120226160270434944[114] = 1.0;
   out_7120226160270434944[115] = 0.0;
   out_7120226160270434944[116] = 0.0;
   out_7120226160270434944[117] = 0.0;
   out_7120226160270434944[118] = 0.0;
   out_7120226160270434944[119] = 0.0;
   out_7120226160270434944[120] = 0.0;
   out_7120226160270434944[121] = 0.0;
   out_7120226160270434944[122] = 0.0;
   out_7120226160270434944[123] = 0.0;
   out_7120226160270434944[124] = 0.0;
   out_7120226160270434944[125] = 0.0;
   out_7120226160270434944[126] = 0.0;
   out_7120226160270434944[127] = 0.0;
   out_7120226160270434944[128] = 0.0;
   out_7120226160270434944[129] = 0.0;
   out_7120226160270434944[130] = 0.0;
   out_7120226160270434944[131] = 0.0;
   out_7120226160270434944[132] = 0.0;
   out_7120226160270434944[133] = 1.0;
   out_7120226160270434944[134] = 0.0;
   out_7120226160270434944[135] = 0.0;
   out_7120226160270434944[136] = 0.0;
   out_7120226160270434944[137] = 0.0;
   out_7120226160270434944[138] = 0.0;
   out_7120226160270434944[139] = 0.0;
   out_7120226160270434944[140] = 0.0;
   out_7120226160270434944[141] = 0.0;
   out_7120226160270434944[142] = 0.0;
   out_7120226160270434944[143] = 0.0;
   out_7120226160270434944[144] = 0.0;
   out_7120226160270434944[145] = 0.0;
   out_7120226160270434944[146] = 0.0;
   out_7120226160270434944[147] = 0.0;
   out_7120226160270434944[148] = 0.0;
   out_7120226160270434944[149] = 0.0;
   out_7120226160270434944[150] = 0.0;
   out_7120226160270434944[151] = 0.0;
   out_7120226160270434944[152] = 1.0;
   out_7120226160270434944[153] = 0.0;
   out_7120226160270434944[154] = 0.0;
   out_7120226160270434944[155] = 0.0;
   out_7120226160270434944[156] = 0.0;
   out_7120226160270434944[157] = 0.0;
   out_7120226160270434944[158] = 0.0;
   out_7120226160270434944[159] = 0.0;
   out_7120226160270434944[160] = 0.0;
   out_7120226160270434944[161] = 0.0;
   out_7120226160270434944[162] = 0.0;
   out_7120226160270434944[163] = 0.0;
   out_7120226160270434944[164] = 0.0;
   out_7120226160270434944[165] = 0.0;
   out_7120226160270434944[166] = 0.0;
   out_7120226160270434944[167] = 0.0;
   out_7120226160270434944[168] = 0.0;
   out_7120226160270434944[169] = 0.0;
   out_7120226160270434944[170] = 0.0;
   out_7120226160270434944[171] = 1.0;
   out_7120226160270434944[172] = 0.0;
   out_7120226160270434944[173] = 0.0;
   out_7120226160270434944[174] = 0.0;
   out_7120226160270434944[175] = 0.0;
   out_7120226160270434944[176] = 0.0;
   out_7120226160270434944[177] = 0.0;
   out_7120226160270434944[178] = 0.0;
   out_7120226160270434944[179] = 0.0;
   out_7120226160270434944[180] = 0.0;
   out_7120226160270434944[181] = 0.0;
   out_7120226160270434944[182] = 0.0;
   out_7120226160270434944[183] = 0.0;
   out_7120226160270434944[184] = 0.0;
   out_7120226160270434944[185] = 0.0;
   out_7120226160270434944[186] = 0.0;
   out_7120226160270434944[187] = 0.0;
   out_7120226160270434944[188] = 0.0;
   out_7120226160270434944[189] = 0.0;
   out_7120226160270434944[190] = 1.0;
   out_7120226160270434944[191] = 0.0;
   out_7120226160270434944[192] = 0.0;
   out_7120226160270434944[193] = 0.0;
   out_7120226160270434944[194] = 0.0;
   out_7120226160270434944[195] = 0.0;
   out_7120226160270434944[196] = 0.0;
   out_7120226160270434944[197] = 0.0;
   out_7120226160270434944[198] = 0.0;
   out_7120226160270434944[199] = 0.0;
   out_7120226160270434944[200] = 0.0;
   out_7120226160270434944[201] = 0.0;
   out_7120226160270434944[202] = 0.0;
   out_7120226160270434944[203] = 0.0;
   out_7120226160270434944[204] = 0.0;
   out_7120226160270434944[205] = 0.0;
   out_7120226160270434944[206] = 0.0;
   out_7120226160270434944[207] = 0.0;
   out_7120226160270434944[208] = 0.0;
   out_7120226160270434944[209] = 1.0;
   out_7120226160270434944[210] = 0.0;
   out_7120226160270434944[211] = 0.0;
   out_7120226160270434944[212] = 0.0;
   out_7120226160270434944[213] = 0.0;
   out_7120226160270434944[214] = 0.0;
   out_7120226160270434944[215] = 0.0;
   out_7120226160270434944[216] = 0.0;
   out_7120226160270434944[217] = 0.0;
   out_7120226160270434944[218] = 0.0;
   out_7120226160270434944[219] = 0.0;
   out_7120226160270434944[220] = 0.0;
   out_7120226160270434944[221] = 0.0;
   out_7120226160270434944[222] = 0.0;
   out_7120226160270434944[223] = 0.0;
   out_7120226160270434944[224] = 0.0;
   out_7120226160270434944[225] = 0.0;
   out_7120226160270434944[226] = 0.0;
   out_7120226160270434944[227] = 0.0;
   out_7120226160270434944[228] = 1.0;
   out_7120226160270434944[229] = 0.0;
   out_7120226160270434944[230] = 0.0;
   out_7120226160270434944[231] = 0.0;
   out_7120226160270434944[232] = 0.0;
   out_7120226160270434944[233] = 0.0;
   out_7120226160270434944[234] = 0.0;
   out_7120226160270434944[235] = 0.0;
   out_7120226160270434944[236] = 0.0;
   out_7120226160270434944[237] = 0.0;
   out_7120226160270434944[238] = 0.0;
   out_7120226160270434944[239] = 0.0;
   out_7120226160270434944[240] = 0.0;
   out_7120226160270434944[241] = 0.0;
   out_7120226160270434944[242] = 0.0;
   out_7120226160270434944[243] = 0.0;
   out_7120226160270434944[244] = 0.0;
   out_7120226160270434944[245] = 0.0;
   out_7120226160270434944[246] = 0.0;
   out_7120226160270434944[247] = 1.0;
   out_7120226160270434944[248] = 0.0;
   out_7120226160270434944[249] = 0.0;
   out_7120226160270434944[250] = 0.0;
   out_7120226160270434944[251] = 0.0;
   out_7120226160270434944[252] = 0.0;
   out_7120226160270434944[253] = 0.0;
   out_7120226160270434944[254] = 0.0;
   out_7120226160270434944[255] = 0.0;
   out_7120226160270434944[256] = 0.0;
   out_7120226160270434944[257] = 0.0;
   out_7120226160270434944[258] = 0.0;
   out_7120226160270434944[259] = 0.0;
   out_7120226160270434944[260] = 0.0;
   out_7120226160270434944[261] = 0.0;
   out_7120226160270434944[262] = 0.0;
   out_7120226160270434944[263] = 0.0;
   out_7120226160270434944[264] = 0.0;
   out_7120226160270434944[265] = 0.0;
   out_7120226160270434944[266] = 1.0;
   out_7120226160270434944[267] = 0.0;
   out_7120226160270434944[268] = 0.0;
   out_7120226160270434944[269] = 0.0;
   out_7120226160270434944[270] = 0.0;
   out_7120226160270434944[271] = 0.0;
   out_7120226160270434944[272] = 0.0;
   out_7120226160270434944[273] = 0.0;
   out_7120226160270434944[274] = 0.0;
   out_7120226160270434944[275] = 0.0;
   out_7120226160270434944[276] = 0.0;
   out_7120226160270434944[277] = 0.0;
   out_7120226160270434944[278] = 0.0;
   out_7120226160270434944[279] = 0.0;
   out_7120226160270434944[280] = 0.0;
   out_7120226160270434944[281] = 0.0;
   out_7120226160270434944[282] = 0.0;
   out_7120226160270434944[283] = 0.0;
   out_7120226160270434944[284] = 0.0;
   out_7120226160270434944[285] = 1.0;
   out_7120226160270434944[286] = 0.0;
   out_7120226160270434944[287] = 0.0;
   out_7120226160270434944[288] = 0.0;
   out_7120226160270434944[289] = 0.0;
   out_7120226160270434944[290] = 0.0;
   out_7120226160270434944[291] = 0.0;
   out_7120226160270434944[292] = 0.0;
   out_7120226160270434944[293] = 0.0;
   out_7120226160270434944[294] = 0.0;
   out_7120226160270434944[295] = 0.0;
   out_7120226160270434944[296] = 0.0;
   out_7120226160270434944[297] = 0.0;
   out_7120226160270434944[298] = 0.0;
   out_7120226160270434944[299] = 0.0;
   out_7120226160270434944[300] = 0.0;
   out_7120226160270434944[301] = 0.0;
   out_7120226160270434944[302] = 0.0;
   out_7120226160270434944[303] = 0.0;
   out_7120226160270434944[304] = 1.0;
   out_7120226160270434944[305] = 0.0;
   out_7120226160270434944[306] = 0.0;
   out_7120226160270434944[307] = 0.0;
   out_7120226160270434944[308] = 0.0;
   out_7120226160270434944[309] = 0.0;
   out_7120226160270434944[310] = 0.0;
   out_7120226160270434944[311] = 0.0;
   out_7120226160270434944[312] = 0.0;
   out_7120226160270434944[313] = 0.0;
   out_7120226160270434944[314] = 0.0;
   out_7120226160270434944[315] = 0.0;
   out_7120226160270434944[316] = 0.0;
   out_7120226160270434944[317] = 0.0;
   out_7120226160270434944[318] = 0.0;
   out_7120226160270434944[319] = 0.0;
   out_7120226160270434944[320] = 0.0;
   out_7120226160270434944[321] = 0.0;
   out_7120226160270434944[322] = 0.0;
   out_7120226160270434944[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6729064377130509881) {
   out_6729064377130509881[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6729064377130509881[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6729064377130509881[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6729064377130509881[3] = dt*state[12] + state[3];
   out_6729064377130509881[4] = dt*state[13] + state[4];
   out_6729064377130509881[5] = dt*state[14] + state[5];
   out_6729064377130509881[6] = state[6];
   out_6729064377130509881[7] = state[7];
   out_6729064377130509881[8] = state[8];
   out_6729064377130509881[9] = state[9];
   out_6729064377130509881[10] = state[10];
   out_6729064377130509881[11] = state[11];
   out_6729064377130509881[12] = state[12];
   out_6729064377130509881[13] = state[13];
   out_6729064377130509881[14] = state[14];
   out_6729064377130509881[15] = state[15];
   out_6729064377130509881[16] = state[16];
   out_6729064377130509881[17] = state[17];
}
void F_fun(double *state, double dt, double *out_256971012135667059) {
   out_256971012135667059[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_256971012135667059[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_256971012135667059[2] = 0;
   out_256971012135667059[3] = 0;
   out_256971012135667059[4] = 0;
   out_256971012135667059[5] = 0;
   out_256971012135667059[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_256971012135667059[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_256971012135667059[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_256971012135667059[9] = 0;
   out_256971012135667059[10] = 0;
   out_256971012135667059[11] = 0;
   out_256971012135667059[12] = 0;
   out_256971012135667059[13] = 0;
   out_256971012135667059[14] = 0;
   out_256971012135667059[15] = 0;
   out_256971012135667059[16] = 0;
   out_256971012135667059[17] = 0;
   out_256971012135667059[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_256971012135667059[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_256971012135667059[20] = 0;
   out_256971012135667059[21] = 0;
   out_256971012135667059[22] = 0;
   out_256971012135667059[23] = 0;
   out_256971012135667059[24] = 0;
   out_256971012135667059[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_256971012135667059[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_256971012135667059[27] = 0;
   out_256971012135667059[28] = 0;
   out_256971012135667059[29] = 0;
   out_256971012135667059[30] = 0;
   out_256971012135667059[31] = 0;
   out_256971012135667059[32] = 0;
   out_256971012135667059[33] = 0;
   out_256971012135667059[34] = 0;
   out_256971012135667059[35] = 0;
   out_256971012135667059[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_256971012135667059[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_256971012135667059[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_256971012135667059[39] = 0;
   out_256971012135667059[40] = 0;
   out_256971012135667059[41] = 0;
   out_256971012135667059[42] = 0;
   out_256971012135667059[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_256971012135667059[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_256971012135667059[45] = 0;
   out_256971012135667059[46] = 0;
   out_256971012135667059[47] = 0;
   out_256971012135667059[48] = 0;
   out_256971012135667059[49] = 0;
   out_256971012135667059[50] = 0;
   out_256971012135667059[51] = 0;
   out_256971012135667059[52] = 0;
   out_256971012135667059[53] = 0;
   out_256971012135667059[54] = 0;
   out_256971012135667059[55] = 0;
   out_256971012135667059[56] = 0;
   out_256971012135667059[57] = 1;
   out_256971012135667059[58] = 0;
   out_256971012135667059[59] = 0;
   out_256971012135667059[60] = 0;
   out_256971012135667059[61] = 0;
   out_256971012135667059[62] = 0;
   out_256971012135667059[63] = 0;
   out_256971012135667059[64] = 0;
   out_256971012135667059[65] = 0;
   out_256971012135667059[66] = dt;
   out_256971012135667059[67] = 0;
   out_256971012135667059[68] = 0;
   out_256971012135667059[69] = 0;
   out_256971012135667059[70] = 0;
   out_256971012135667059[71] = 0;
   out_256971012135667059[72] = 0;
   out_256971012135667059[73] = 0;
   out_256971012135667059[74] = 0;
   out_256971012135667059[75] = 0;
   out_256971012135667059[76] = 1;
   out_256971012135667059[77] = 0;
   out_256971012135667059[78] = 0;
   out_256971012135667059[79] = 0;
   out_256971012135667059[80] = 0;
   out_256971012135667059[81] = 0;
   out_256971012135667059[82] = 0;
   out_256971012135667059[83] = 0;
   out_256971012135667059[84] = 0;
   out_256971012135667059[85] = dt;
   out_256971012135667059[86] = 0;
   out_256971012135667059[87] = 0;
   out_256971012135667059[88] = 0;
   out_256971012135667059[89] = 0;
   out_256971012135667059[90] = 0;
   out_256971012135667059[91] = 0;
   out_256971012135667059[92] = 0;
   out_256971012135667059[93] = 0;
   out_256971012135667059[94] = 0;
   out_256971012135667059[95] = 1;
   out_256971012135667059[96] = 0;
   out_256971012135667059[97] = 0;
   out_256971012135667059[98] = 0;
   out_256971012135667059[99] = 0;
   out_256971012135667059[100] = 0;
   out_256971012135667059[101] = 0;
   out_256971012135667059[102] = 0;
   out_256971012135667059[103] = 0;
   out_256971012135667059[104] = dt;
   out_256971012135667059[105] = 0;
   out_256971012135667059[106] = 0;
   out_256971012135667059[107] = 0;
   out_256971012135667059[108] = 0;
   out_256971012135667059[109] = 0;
   out_256971012135667059[110] = 0;
   out_256971012135667059[111] = 0;
   out_256971012135667059[112] = 0;
   out_256971012135667059[113] = 0;
   out_256971012135667059[114] = 1;
   out_256971012135667059[115] = 0;
   out_256971012135667059[116] = 0;
   out_256971012135667059[117] = 0;
   out_256971012135667059[118] = 0;
   out_256971012135667059[119] = 0;
   out_256971012135667059[120] = 0;
   out_256971012135667059[121] = 0;
   out_256971012135667059[122] = 0;
   out_256971012135667059[123] = 0;
   out_256971012135667059[124] = 0;
   out_256971012135667059[125] = 0;
   out_256971012135667059[126] = 0;
   out_256971012135667059[127] = 0;
   out_256971012135667059[128] = 0;
   out_256971012135667059[129] = 0;
   out_256971012135667059[130] = 0;
   out_256971012135667059[131] = 0;
   out_256971012135667059[132] = 0;
   out_256971012135667059[133] = 1;
   out_256971012135667059[134] = 0;
   out_256971012135667059[135] = 0;
   out_256971012135667059[136] = 0;
   out_256971012135667059[137] = 0;
   out_256971012135667059[138] = 0;
   out_256971012135667059[139] = 0;
   out_256971012135667059[140] = 0;
   out_256971012135667059[141] = 0;
   out_256971012135667059[142] = 0;
   out_256971012135667059[143] = 0;
   out_256971012135667059[144] = 0;
   out_256971012135667059[145] = 0;
   out_256971012135667059[146] = 0;
   out_256971012135667059[147] = 0;
   out_256971012135667059[148] = 0;
   out_256971012135667059[149] = 0;
   out_256971012135667059[150] = 0;
   out_256971012135667059[151] = 0;
   out_256971012135667059[152] = 1;
   out_256971012135667059[153] = 0;
   out_256971012135667059[154] = 0;
   out_256971012135667059[155] = 0;
   out_256971012135667059[156] = 0;
   out_256971012135667059[157] = 0;
   out_256971012135667059[158] = 0;
   out_256971012135667059[159] = 0;
   out_256971012135667059[160] = 0;
   out_256971012135667059[161] = 0;
   out_256971012135667059[162] = 0;
   out_256971012135667059[163] = 0;
   out_256971012135667059[164] = 0;
   out_256971012135667059[165] = 0;
   out_256971012135667059[166] = 0;
   out_256971012135667059[167] = 0;
   out_256971012135667059[168] = 0;
   out_256971012135667059[169] = 0;
   out_256971012135667059[170] = 0;
   out_256971012135667059[171] = 1;
   out_256971012135667059[172] = 0;
   out_256971012135667059[173] = 0;
   out_256971012135667059[174] = 0;
   out_256971012135667059[175] = 0;
   out_256971012135667059[176] = 0;
   out_256971012135667059[177] = 0;
   out_256971012135667059[178] = 0;
   out_256971012135667059[179] = 0;
   out_256971012135667059[180] = 0;
   out_256971012135667059[181] = 0;
   out_256971012135667059[182] = 0;
   out_256971012135667059[183] = 0;
   out_256971012135667059[184] = 0;
   out_256971012135667059[185] = 0;
   out_256971012135667059[186] = 0;
   out_256971012135667059[187] = 0;
   out_256971012135667059[188] = 0;
   out_256971012135667059[189] = 0;
   out_256971012135667059[190] = 1;
   out_256971012135667059[191] = 0;
   out_256971012135667059[192] = 0;
   out_256971012135667059[193] = 0;
   out_256971012135667059[194] = 0;
   out_256971012135667059[195] = 0;
   out_256971012135667059[196] = 0;
   out_256971012135667059[197] = 0;
   out_256971012135667059[198] = 0;
   out_256971012135667059[199] = 0;
   out_256971012135667059[200] = 0;
   out_256971012135667059[201] = 0;
   out_256971012135667059[202] = 0;
   out_256971012135667059[203] = 0;
   out_256971012135667059[204] = 0;
   out_256971012135667059[205] = 0;
   out_256971012135667059[206] = 0;
   out_256971012135667059[207] = 0;
   out_256971012135667059[208] = 0;
   out_256971012135667059[209] = 1;
   out_256971012135667059[210] = 0;
   out_256971012135667059[211] = 0;
   out_256971012135667059[212] = 0;
   out_256971012135667059[213] = 0;
   out_256971012135667059[214] = 0;
   out_256971012135667059[215] = 0;
   out_256971012135667059[216] = 0;
   out_256971012135667059[217] = 0;
   out_256971012135667059[218] = 0;
   out_256971012135667059[219] = 0;
   out_256971012135667059[220] = 0;
   out_256971012135667059[221] = 0;
   out_256971012135667059[222] = 0;
   out_256971012135667059[223] = 0;
   out_256971012135667059[224] = 0;
   out_256971012135667059[225] = 0;
   out_256971012135667059[226] = 0;
   out_256971012135667059[227] = 0;
   out_256971012135667059[228] = 1;
   out_256971012135667059[229] = 0;
   out_256971012135667059[230] = 0;
   out_256971012135667059[231] = 0;
   out_256971012135667059[232] = 0;
   out_256971012135667059[233] = 0;
   out_256971012135667059[234] = 0;
   out_256971012135667059[235] = 0;
   out_256971012135667059[236] = 0;
   out_256971012135667059[237] = 0;
   out_256971012135667059[238] = 0;
   out_256971012135667059[239] = 0;
   out_256971012135667059[240] = 0;
   out_256971012135667059[241] = 0;
   out_256971012135667059[242] = 0;
   out_256971012135667059[243] = 0;
   out_256971012135667059[244] = 0;
   out_256971012135667059[245] = 0;
   out_256971012135667059[246] = 0;
   out_256971012135667059[247] = 1;
   out_256971012135667059[248] = 0;
   out_256971012135667059[249] = 0;
   out_256971012135667059[250] = 0;
   out_256971012135667059[251] = 0;
   out_256971012135667059[252] = 0;
   out_256971012135667059[253] = 0;
   out_256971012135667059[254] = 0;
   out_256971012135667059[255] = 0;
   out_256971012135667059[256] = 0;
   out_256971012135667059[257] = 0;
   out_256971012135667059[258] = 0;
   out_256971012135667059[259] = 0;
   out_256971012135667059[260] = 0;
   out_256971012135667059[261] = 0;
   out_256971012135667059[262] = 0;
   out_256971012135667059[263] = 0;
   out_256971012135667059[264] = 0;
   out_256971012135667059[265] = 0;
   out_256971012135667059[266] = 1;
   out_256971012135667059[267] = 0;
   out_256971012135667059[268] = 0;
   out_256971012135667059[269] = 0;
   out_256971012135667059[270] = 0;
   out_256971012135667059[271] = 0;
   out_256971012135667059[272] = 0;
   out_256971012135667059[273] = 0;
   out_256971012135667059[274] = 0;
   out_256971012135667059[275] = 0;
   out_256971012135667059[276] = 0;
   out_256971012135667059[277] = 0;
   out_256971012135667059[278] = 0;
   out_256971012135667059[279] = 0;
   out_256971012135667059[280] = 0;
   out_256971012135667059[281] = 0;
   out_256971012135667059[282] = 0;
   out_256971012135667059[283] = 0;
   out_256971012135667059[284] = 0;
   out_256971012135667059[285] = 1;
   out_256971012135667059[286] = 0;
   out_256971012135667059[287] = 0;
   out_256971012135667059[288] = 0;
   out_256971012135667059[289] = 0;
   out_256971012135667059[290] = 0;
   out_256971012135667059[291] = 0;
   out_256971012135667059[292] = 0;
   out_256971012135667059[293] = 0;
   out_256971012135667059[294] = 0;
   out_256971012135667059[295] = 0;
   out_256971012135667059[296] = 0;
   out_256971012135667059[297] = 0;
   out_256971012135667059[298] = 0;
   out_256971012135667059[299] = 0;
   out_256971012135667059[300] = 0;
   out_256971012135667059[301] = 0;
   out_256971012135667059[302] = 0;
   out_256971012135667059[303] = 0;
   out_256971012135667059[304] = 1;
   out_256971012135667059[305] = 0;
   out_256971012135667059[306] = 0;
   out_256971012135667059[307] = 0;
   out_256971012135667059[308] = 0;
   out_256971012135667059[309] = 0;
   out_256971012135667059[310] = 0;
   out_256971012135667059[311] = 0;
   out_256971012135667059[312] = 0;
   out_256971012135667059[313] = 0;
   out_256971012135667059[314] = 0;
   out_256971012135667059[315] = 0;
   out_256971012135667059[316] = 0;
   out_256971012135667059[317] = 0;
   out_256971012135667059[318] = 0;
   out_256971012135667059[319] = 0;
   out_256971012135667059[320] = 0;
   out_256971012135667059[321] = 0;
   out_256971012135667059[322] = 0;
   out_256971012135667059[323] = 1;
}
void h_4(double *state, double *unused, double *out_8596587095692993094) {
   out_8596587095692993094[0] = state[6] + state[9];
   out_8596587095692993094[1] = state[7] + state[10];
   out_8596587095692993094[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8318173642153333048) {
   out_8318173642153333048[0] = 0;
   out_8318173642153333048[1] = 0;
   out_8318173642153333048[2] = 0;
   out_8318173642153333048[3] = 0;
   out_8318173642153333048[4] = 0;
   out_8318173642153333048[5] = 0;
   out_8318173642153333048[6] = 1;
   out_8318173642153333048[7] = 0;
   out_8318173642153333048[8] = 0;
   out_8318173642153333048[9] = 1;
   out_8318173642153333048[10] = 0;
   out_8318173642153333048[11] = 0;
   out_8318173642153333048[12] = 0;
   out_8318173642153333048[13] = 0;
   out_8318173642153333048[14] = 0;
   out_8318173642153333048[15] = 0;
   out_8318173642153333048[16] = 0;
   out_8318173642153333048[17] = 0;
   out_8318173642153333048[18] = 0;
   out_8318173642153333048[19] = 0;
   out_8318173642153333048[20] = 0;
   out_8318173642153333048[21] = 0;
   out_8318173642153333048[22] = 0;
   out_8318173642153333048[23] = 0;
   out_8318173642153333048[24] = 0;
   out_8318173642153333048[25] = 1;
   out_8318173642153333048[26] = 0;
   out_8318173642153333048[27] = 0;
   out_8318173642153333048[28] = 1;
   out_8318173642153333048[29] = 0;
   out_8318173642153333048[30] = 0;
   out_8318173642153333048[31] = 0;
   out_8318173642153333048[32] = 0;
   out_8318173642153333048[33] = 0;
   out_8318173642153333048[34] = 0;
   out_8318173642153333048[35] = 0;
   out_8318173642153333048[36] = 0;
   out_8318173642153333048[37] = 0;
   out_8318173642153333048[38] = 0;
   out_8318173642153333048[39] = 0;
   out_8318173642153333048[40] = 0;
   out_8318173642153333048[41] = 0;
   out_8318173642153333048[42] = 0;
   out_8318173642153333048[43] = 0;
   out_8318173642153333048[44] = 1;
   out_8318173642153333048[45] = 0;
   out_8318173642153333048[46] = 0;
   out_8318173642153333048[47] = 1;
   out_8318173642153333048[48] = 0;
   out_8318173642153333048[49] = 0;
   out_8318173642153333048[50] = 0;
   out_8318173642153333048[51] = 0;
   out_8318173642153333048[52] = 0;
   out_8318173642153333048[53] = 0;
}
void h_10(double *state, double *unused, double *out_8419119128219239034) {
   out_8419119128219239034[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8419119128219239034[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8419119128219239034[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2391957346662021133) {
   out_2391957346662021133[0] = 0;
   out_2391957346662021133[1] = 9.8100000000000005*cos(state[1]);
   out_2391957346662021133[2] = 0;
   out_2391957346662021133[3] = 0;
   out_2391957346662021133[4] = -state[8];
   out_2391957346662021133[5] = state[7];
   out_2391957346662021133[6] = 0;
   out_2391957346662021133[7] = state[5];
   out_2391957346662021133[8] = -state[4];
   out_2391957346662021133[9] = 0;
   out_2391957346662021133[10] = 0;
   out_2391957346662021133[11] = 0;
   out_2391957346662021133[12] = 1;
   out_2391957346662021133[13] = 0;
   out_2391957346662021133[14] = 0;
   out_2391957346662021133[15] = 1;
   out_2391957346662021133[16] = 0;
   out_2391957346662021133[17] = 0;
   out_2391957346662021133[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2391957346662021133[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2391957346662021133[20] = 0;
   out_2391957346662021133[21] = state[8];
   out_2391957346662021133[22] = 0;
   out_2391957346662021133[23] = -state[6];
   out_2391957346662021133[24] = -state[5];
   out_2391957346662021133[25] = 0;
   out_2391957346662021133[26] = state[3];
   out_2391957346662021133[27] = 0;
   out_2391957346662021133[28] = 0;
   out_2391957346662021133[29] = 0;
   out_2391957346662021133[30] = 0;
   out_2391957346662021133[31] = 1;
   out_2391957346662021133[32] = 0;
   out_2391957346662021133[33] = 0;
   out_2391957346662021133[34] = 1;
   out_2391957346662021133[35] = 0;
   out_2391957346662021133[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2391957346662021133[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2391957346662021133[38] = 0;
   out_2391957346662021133[39] = -state[7];
   out_2391957346662021133[40] = state[6];
   out_2391957346662021133[41] = 0;
   out_2391957346662021133[42] = state[4];
   out_2391957346662021133[43] = -state[3];
   out_2391957346662021133[44] = 0;
   out_2391957346662021133[45] = 0;
   out_2391957346662021133[46] = 0;
   out_2391957346662021133[47] = 0;
   out_2391957346662021133[48] = 0;
   out_2391957346662021133[49] = 0;
   out_2391957346662021133[50] = 1;
   out_2391957346662021133[51] = 0;
   out_2391957346662021133[52] = 0;
   out_2391957346662021133[53] = 1;
}
void h_13(double *state, double *unused, double *out_2811919948298635006) {
   out_2811919948298635006[0] = state[3];
   out_2811919948298635006[1] = state[4];
   out_2811919948298635006[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6916296606223885767) {
   out_6916296606223885767[0] = 0;
   out_6916296606223885767[1] = 0;
   out_6916296606223885767[2] = 0;
   out_6916296606223885767[3] = 1;
   out_6916296606223885767[4] = 0;
   out_6916296606223885767[5] = 0;
   out_6916296606223885767[6] = 0;
   out_6916296606223885767[7] = 0;
   out_6916296606223885767[8] = 0;
   out_6916296606223885767[9] = 0;
   out_6916296606223885767[10] = 0;
   out_6916296606223885767[11] = 0;
   out_6916296606223885767[12] = 0;
   out_6916296606223885767[13] = 0;
   out_6916296606223885767[14] = 0;
   out_6916296606223885767[15] = 0;
   out_6916296606223885767[16] = 0;
   out_6916296606223885767[17] = 0;
   out_6916296606223885767[18] = 0;
   out_6916296606223885767[19] = 0;
   out_6916296606223885767[20] = 0;
   out_6916296606223885767[21] = 0;
   out_6916296606223885767[22] = 1;
   out_6916296606223885767[23] = 0;
   out_6916296606223885767[24] = 0;
   out_6916296606223885767[25] = 0;
   out_6916296606223885767[26] = 0;
   out_6916296606223885767[27] = 0;
   out_6916296606223885767[28] = 0;
   out_6916296606223885767[29] = 0;
   out_6916296606223885767[30] = 0;
   out_6916296606223885767[31] = 0;
   out_6916296606223885767[32] = 0;
   out_6916296606223885767[33] = 0;
   out_6916296606223885767[34] = 0;
   out_6916296606223885767[35] = 0;
   out_6916296606223885767[36] = 0;
   out_6916296606223885767[37] = 0;
   out_6916296606223885767[38] = 0;
   out_6916296606223885767[39] = 0;
   out_6916296606223885767[40] = 0;
   out_6916296606223885767[41] = 1;
   out_6916296606223885767[42] = 0;
   out_6916296606223885767[43] = 0;
   out_6916296606223885767[44] = 0;
   out_6916296606223885767[45] = 0;
   out_6916296606223885767[46] = 0;
   out_6916296606223885767[47] = 0;
   out_6916296606223885767[48] = 0;
   out_6916296606223885767[49] = 0;
   out_6916296606223885767[50] = 0;
   out_6916296606223885767[51] = 0;
   out_6916296606223885767[52] = 0;
   out_6916296606223885767[53] = 0;
}
void h_14(double *state, double *unused, double *out_7300738768633822776) {
   out_7300738768633822776[0] = state[6];
   out_7300738768633822776[1] = state[7];
   out_7300738768633822776[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6165329575216734039) {
   out_6165329575216734039[0] = 0;
   out_6165329575216734039[1] = 0;
   out_6165329575216734039[2] = 0;
   out_6165329575216734039[3] = 0;
   out_6165329575216734039[4] = 0;
   out_6165329575216734039[5] = 0;
   out_6165329575216734039[6] = 1;
   out_6165329575216734039[7] = 0;
   out_6165329575216734039[8] = 0;
   out_6165329575216734039[9] = 0;
   out_6165329575216734039[10] = 0;
   out_6165329575216734039[11] = 0;
   out_6165329575216734039[12] = 0;
   out_6165329575216734039[13] = 0;
   out_6165329575216734039[14] = 0;
   out_6165329575216734039[15] = 0;
   out_6165329575216734039[16] = 0;
   out_6165329575216734039[17] = 0;
   out_6165329575216734039[18] = 0;
   out_6165329575216734039[19] = 0;
   out_6165329575216734039[20] = 0;
   out_6165329575216734039[21] = 0;
   out_6165329575216734039[22] = 0;
   out_6165329575216734039[23] = 0;
   out_6165329575216734039[24] = 0;
   out_6165329575216734039[25] = 1;
   out_6165329575216734039[26] = 0;
   out_6165329575216734039[27] = 0;
   out_6165329575216734039[28] = 0;
   out_6165329575216734039[29] = 0;
   out_6165329575216734039[30] = 0;
   out_6165329575216734039[31] = 0;
   out_6165329575216734039[32] = 0;
   out_6165329575216734039[33] = 0;
   out_6165329575216734039[34] = 0;
   out_6165329575216734039[35] = 0;
   out_6165329575216734039[36] = 0;
   out_6165329575216734039[37] = 0;
   out_6165329575216734039[38] = 0;
   out_6165329575216734039[39] = 0;
   out_6165329575216734039[40] = 0;
   out_6165329575216734039[41] = 0;
   out_6165329575216734039[42] = 0;
   out_6165329575216734039[43] = 0;
   out_6165329575216734039[44] = 1;
   out_6165329575216734039[45] = 0;
   out_6165329575216734039[46] = 0;
   out_6165329575216734039[47] = 0;
   out_6165329575216734039[48] = 0;
   out_6165329575216734039[49] = 0;
   out_6165329575216734039[50] = 0;
   out_6165329575216734039[51] = 0;
   out_6165329575216734039[52] = 0;
   out_6165329575216734039[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_94094168798460134) {
  err_fun(nom_x, delta_x, out_94094168798460134);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3348610880049505179) {
  inv_err_fun(nom_x, true_x, out_3348610880049505179);
}
void pose_H_mod_fun(double *state, double *out_7120226160270434944) {
  H_mod_fun(state, out_7120226160270434944);
}
void pose_f_fun(double *state, double dt, double *out_6729064377130509881) {
  f_fun(state,  dt, out_6729064377130509881);
}
void pose_F_fun(double *state, double dt, double *out_256971012135667059) {
  F_fun(state,  dt, out_256971012135667059);
}
void pose_h_4(double *state, double *unused, double *out_8596587095692993094) {
  h_4(state, unused, out_8596587095692993094);
}
void pose_H_4(double *state, double *unused, double *out_8318173642153333048) {
  H_4(state, unused, out_8318173642153333048);
}
void pose_h_10(double *state, double *unused, double *out_8419119128219239034) {
  h_10(state, unused, out_8419119128219239034);
}
void pose_H_10(double *state, double *unused, double *out_2391957346662021133) {
  H_10(state, unused, out_2391957346662021133);
}
void pose_h_13(double *state, double *unused, double *out_2811919948298635006) {
  h_13(state, unused, out_2811919948298635006);
}
void pose_H_13(double *state, double *unused, double *out_6916296606223885767) {
  H_13(state, unused, out_6916296606223885767);
}
void pose_h_14(double *state, double *unused, double *out_7300738768633822776) {
  h_14(state, unused, out_7300738768633822776);
}
void pose_H_14(double *state, double *unused, double *out_6165329575216734039) {
  H_14(state, unused, out_6165329575216734039);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
