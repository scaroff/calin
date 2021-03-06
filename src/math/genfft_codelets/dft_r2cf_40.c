/* Generated by: /Users/sfegan/GitHub/fftw3/genfft/gen_r2cf.native -n 40 -standalone -fma -generic-arith -compact -name dft_codelet_r2cf_40 */

/*
 * This function contains 220 FP additions, 88 FP multiplications,
 * (or, 136 additions, 4 multiplications, 84 fused multiply/add),
 * 76 stack variables, 5 constants, and 80 memory accesses
 */
void dft_codelet_r2cf_40(R * R0, R * R1, R * Cr, R * Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DK(KP707106781, +0.707106781186547524400844362104849039284835938);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP618033988, +0.618033988749894848204586834365638117720309180);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(160, rs), MAKE_VOLATILE_STRIDE(160, csr), MAKE_VOLATILE_STRIDE(160, csi)) {
      E T1x, T20, T1E, T9, T1D, T1A, T21, T1H, Ti, T1G, T1t, T24, T1O,
       TB, T1N;
      E T1q, T23, T1L, Ts, T1K, T2j, T2k, T2I, T2L, T2M, T39, T3a, T3b,
       T1l, T1U;
      E T1a, T1T, T2g, T2h, T2z, T2C, T2D, T3e, T3f, T3g, TY, T1X, TN,
       T1W;
      {
        E T1, T7, T1w, T4, T1v, T8;
        T1 = R0[0];
        {
          E T5, T6, T2, T3;
          T5 = R0[WS(rs, 8)];
          T6 = R0[WS(rs, 12)];
          T7 = ADD(T5, T6);
          T1w = SUB(T5, T6);
          T2 = R0[WS(rs, 4)];
          T3 = R0[WS(rs, 16)];
          T4 = ADD(T2, T3);
          T1v = SUB(T2, T3);
        }
        T1x = FMA(KP618033988, T1w, T1v);
        T20 = FNMS(KP618033988, T1v, T1w);
        T1E = SUB(T4, T7);
        T8 = ADD(T4, T7);
        T9 = ADD(T1, T8);
        T1D = FNMS(KP250000000, T8, T1);
      }
      {
        E Ta, Tg, T1z, Td, T1y, Th;
        Ta = R0[WS(rs, 10)];
        {
          E Te, Tf, Tb, Tc;
          Te = R0[WS(rs, 18)];
          Tf = R0[WS(rs, 2)];
          Tg = ADD(Te, Tf);
          T1z = SUB(Te, Tf);
          Tb = R0[WS(rs, 14)];
          Tc = R0[WS(rs, 6)];
          Td = ADD(Tb, Tc);
          T1y = SUB(Tb, Tc);
        }
        T1A = FMA(KP618033988, T1z, T1y);
        T21 = FNMS(KP618033988, T1y, T1z);
        T1H = SUB(Td, Tg);
        Th = ADD(Td, Tg);
        Ti = ADD(Ta, Th);
        T1G = FNMS(KP250000000, Th, Ta);
      }
      {
        E Tt, Tz, T1s, Tw, T1r, TA;
        Tt = R0[WS(rs, 15)];
        {
          E Tx, Ty, Tu, Tv;
          Tx = R0[WS(rs, 3)];
          Ty = R0[WS(rs, 7)];
          Tz = ADD(Tx, Ty);
          T1s = SUB(Tx, Ty);
          Tu = R0[WS(rs, 19)];
          Tv = R0[WS(rs, 11)];
          Tw = ADD(Tu, Tv);
          T1r = SUB(Tu, Tv);
        }
        T1t = FMA(KP618033988, T1s, T1r);
        T24 = FNMS(KP618033988, T1r, T1s);
        T1O = SUB(Tw, Tz);
        TA = ADD(Tw, Tz);
        TB = ADD(Tt, TA);
        T1N = FNMS(KP250000000, TA, Tt);
      }
      {
        E Tk, Tq, T1p, Tn, T1o, Tr;
        Tk = R0[WS(rs, 5)];
        {
          E To, Tp, Tl, Tm;
          To = R0[WS(rs, 13)];
          Tp = R0[WS(rs, 17)];
          Tq = ADD(To, Tp);
          T1p = SUB(To, Tp);
          Tl = R0[WS(rs, 9)];
          Tm = R0[WS(rs, 1)];
          Tn = ADD(Tl, Tm);
          T1o = SUB(Tl, Tm);
        }
        T1q = FMA(KP618033988, T1p, T1o);
        T23 = FNMS(KP618033988, T1o, T1p);
        T1L = SUB(Tn, Tq);
        Tr = ADD(Tn, Tq);
        Ts = ADD(Tk, Tr);
        T1K = FNMS(KP250000000, Tr, Tk);
      }
      {
        E T10, T1b, T13, T16, T17, T2H, T2G, T1e, T1h, T1i, T2K, T2J;
        T10 = R1[WS(rs, 17)];
        T1b = R1[WS(rs, 7)];
        {
          E T11, T12, T14, T15;
          T11 = R1[WS(rs, 1)];
          T12 = R1[WS(rs, 13)];
          T13 = ADD(T11, T12);
          T14 = R1[WS(rs, 5)];
          T15 = R1[WS(rs, 9)];
          T16 = ADD(T14, T15);
          T17 = ADD(T13, T16);
          T2H = SUB(T15, T14);
          T2G = SUB(T12, T11);
        }
        {
          E T1c, T1d, T1f, T1g;
          T1c = R1[WS(rs, 11)];
          T1d = R1[WS(rs, 3)];
          T1e = ADD(T1c, T1d);
          T1f = R1[WS(rs, 15)];
          T1g = R1[WS(rs, 19)];
          T1h = ADD(T1f, T1g);
          T1i = ADD(T1e, T1h);
          T2K = SUB(T1g, T1f);
          T2J = SUB(T1d, T1c);
        }
        T2j = ADD(T10, T17);
        T2k = ADD(T1b, T1i);
        T2I = FMA(KP618033988, T2H, T2G);
        T2L = FMA(KP618033988, T2K, T2J);
        T2M = SUB(T2I, T2L);
        T39 = FNMS(KP618033988, T2G, T2H);
        T3a = FNMS(KP618033988, T2J, T2K);
        T3b = SUB(T39, T3a);
        {
          E T1j, T1k, T18, T19;
          T1j = FNMS(KP250000000, T1i, T1b);
          T1k = SUB(T1e, T1h);
          T1l = FMA(KP559016994, T1k, T1j);
          T1U = FNMS(KP559016994, T1k, T1j);
          T18 = FNMS(KP250000000, T17, T10);
          T19 = SUB(T13, T16);
          T1a = FMA(KP559016994, T19, T18);
          T1T = FNMS(KP559016994, T19, T18);
        }
      }
      {
        E TD, TO, TG, TJ, TK, T2B, T2A, TR, TU, TV, T2y, T2x;
        TD = R1[WS(rs, 2)];
        TO = R1[WS(rs, 12)];
        {
          E TE, TF, TH, TI;
          TE = R1[WS(rs, 6)];
          TF = R1[WS(rs, 18)];
          TG = ADD(TE, TF);
          TH = R1[WS(rs, 10)];
          TI = R1[WS(rs, 14)];
          TJ = ADD(TH, TI);
          TK = ADD(TG, TJ);
          T2B = SUB(TH, TI);
          T2A = SUB(TE, TF);
        }
        {
          E TP, TQ, TS, TT;
          TP = R1[WS(rs, 16)];
          TQ = R1[WS(rs, 8)];
          TR = ADD(TP, TQ);
          TS = R1[0];
          TT = R1[WS(rs, 4)];
          TU = ADD(TS, TT);
          TV = ADD(TR, TU);
          T2y = SUB(TS, TT);
          T2x = SUB(TP, TQ);
        }
        T2g = ADD(TD, TK);
        T2h = ADD(TO, TV);
        T2z = FMA(KP618033988, T2y, T2x);
        T2C = FMA(KP618033988, T2B, T2A);
        T2D = SUB(T2z, T2C);
        T3e = FNMS(KP618033988, T2x, T2y);
        T3f = FNMS(KP618033988, T2A, T2B);
        T3g = SUB(T3e, T3f);
        {
          E TW, TX, TL, TM;
          TW = FNMS(KP250000000, TV, TO);
          TX = SUB(TR, TU);
          TY = FMA(KP559016994, TX, TW);
          T1X = FNMS(KP559016994, TX, TW);
          TL = FNMS(KP250000000, TK, TD);
          TM = SUB(TG, TJ);
          TN = FMA(KP559016994, TM, TL);
          T1W = FNMS(KP559016994, TM, TL);
        }
      }
      {
        E Tj, TC, T2p, T2q, T2r, T2s;
        Tj = ADD(T9, Ti);
        TC = ADD(Ts, TB);
        T2p = ADD(Tj, TC);
        T2q = ADD(T2g, T2h);
        T2r = ADD(T2j, T2k);
        T2s = ADD(T2q, T2r);
        Cr[WS(csr, 10)] = SUB(Tj, TC);
        Ci[WS(csi, 10)] = SUB(T2r, T2q);
        Cr[WS(csr, 20)] = SUB(T2p, T2s);
        Cr[0] = ADD(T2p, T2s);
      }
      {
        E T2f, T2n, T2m, T2o, T2i, T2l;
        T2f = SUB(Ts, TB);
        T2n = SUB(T9, Ti);
        T2i = SUB(T2g, T2h);
        T2l = SUB(T2j, T2k);
        T2m = SUB(T2i, T2l);
        T2o = ADD(T2i, T2l);
        Ci[WS(csi, 5)] = NEG(FNMS(KP707106781, T2m, T2f));
        Cr[WS(csr, 5)] = FNMS(KP707106781, T2o, T2n);
        Ci[WS(csi, 15)] = FMA(KP707106781, T2m, T2f);
        Cr[WS(csr, 15)] = FMA(KP707106781, T2o, T2n);
      }
      {
        E T2u, T2Q, T2E, T2V, T2N, T2U, T1n, T1S, T1J, T2t, T32, T34,
         T1C, T2Z, T1Q;
        E T2P, T1R;
        {
          E T2w, T2F, T30, T31;
          T2u = SUB(T1t, T1q);
          T2Q = SUB(T1A, T1x);
          T2w = SUB(TN, TY);
          T2E = FMA(KP951056516, T2D, T2w);
          T2V = FNMS(KP951056516, T2D, T2w);
          T2F = SUB(T1a, T1l);
          T2N = FNMS(KP951056516, T2M, T2F);
          T2U = FMA(KP951056516, T2M, T2F);
          {
            E TZ, T1m, T1F, T1I;
            TZ = ADD(TN, TY);
            T1m = ADD(T1a, T1l);
            T1n = SUB(TZ, T1m);
            T1S = ADD(TZ, T1m);
            T1F = FMA(KP559016994, T1E, T1D);
            T1I = FMA(KP559016994, T1H, T1G);
            T1J = ADD(T1F, T1I);
            T2t = SUB(T1F, T1I);
          }
          T30 = ADD(T2I, T2L);
          T31 = ADD(T2C, T2z);
          T32 = SUB(T30, T31);
          T34 = ADD(T31, T30);
          {
            E T1u, T1B, T1M, T1P;
            T1u = ADD(T1q, T1t);
            T1B = ADD(T1x, T1A);
            T1C = SUB(T1u, T1B);
            T2Z = ADD(T1B, T1u);
            T1M = FMA(KP559016994, T1L, T1K);
            T1P = FMA(KP559016994, T1O, T1N);
            T1Q = ADD(T1M, T1P);
            T2P = SUB(T1M, T1P);
          }
        }
        Ci[WS(csi, 6)] = FMA(KP951056516, T1C, T1n);
        Ci[WS(csi, 4)] = MUL(KP951056516, ADD(T2Z, T32));
        Ci[WS(csi, 16)] = MUL(KP951056516, SUB(T32, T2Z));
        Ci[WS(csi, 14)] = FNMS(KP951056516, T1C, T1n);
        T1R = ADD(T1J, T1Q);
        Cr[WS(csr, 4)] = SUB(T1R, T1S);
        Cr[WS(csr, 16)] = ADD(T1R, T1S);
        {
          E T33, T2X, T2Y, T2R, T2S;
          T33 = SUB(T1J, T1Q);
          Cr[WS(csr, 14)] = FNMS(KP951056516, T34, T33);
          Cr[WS(csr, 6)] = FMA(KP951056516, T34, T33);
          T2X = FNMS(KP951056516, T2u, T2t);
          T2Y = ADD(T2V, T2U);
          Cr[WS(csr, 11)] = FNMS(KP707106781, T2Y, T2X);
          Cr[WS(csr, 9)] = FMA(KP707106781, T2Y, T2X);
          T2R = FMA(KP951056516, T2Q, T2P);
          T2S = SUB(T2N, T2E);
          Ci[WS(csi, 9)] = NEG(FNMS(KP707106781, T2S, T2R));
          Ci[WS(csi, 11)] = FMA(KP707106781, T2S, T2R);
          {
            E T2v, T2O, T2T, T2W;
            T2v = FMA(KP951056516, T2u, T2t);
            T2O = ADD(T2E, T2N);
            Cr[WS(csr, 19)] = FNMS(KP707106781, T2O, T2v);
            Cr[WS(csr, 1)] = FMA(KP707106781, T2O, T2v);
            T2T = FNMS(KP951056516, T2Q, T2P);
            T2W = SUB(T2U, T2V);
            Ci[WS(csi, 1)] = NEG(FNMS(KP707106781, T2W, T2T));
            Ci[WS(csi, 19)] = FMA(KP707106781, T2W, T2T);
          }
        }
      }
      {
        E T36, T3k, T3c, T3p, T3h, T3o, T1Z, T2e, T29, T3j, T3w, T3x,
         T26, T3y, T2c;
        E T35, T3t;
        {
          E T38, T3d, T3u, T3v;
          T36 = SUB(T21, T20);
          T3k = SUB(T24, T23);
          T38 = SUB(T1T, T1U);
          T3c = FNMS(KP951056516, T3b, T38);
          T3p = FMA(KP951056516, T3b, T38);
          T3d = SUB(T1W, T1X);
          T3h = FMA(KP951056516, T3g, T3d);
          T3o = FNMS(KP951056516, T3g, T3d);
          {
            E T1V, T1Y, T27, T28;
            T1V = ADD(T1T, T1U);
            T1Y = ADD(T1W, T1X);
            T1Z = SUB(T1V, T1Y);
            T2e = ADD(T1Y, T1V);
            T27 = FNMS(KP559016994, T1E, T1D);
            T28 = FNMS(KP559016994, T1H, T1G);
            T29 = ADD(T27, T28);
            T3j = SUB(T27, T28);
          }
          T3u = ADD(T3f, T3e);
          T3v = ADD(T39, T3a);
          T3w = ADD(T3u, T3v);
          T3x = SUB(T3v, T3u);
          {
            E T22, T25, T2a, T2b;
            T22 = ADD(T20, T21);
            T25 = ADD(T23, T24);
            T26 = SUB(T22, T25);
            T3y = ADD(T22, T25);
            T2a = FNMS(KP559016994, T1L, T1K);
            T2b = FNMS(KP559016994, T1O, T1N);
            T2c = ADD(T2a, T2b);
            T35 = SUB(T2a, T2b);
          }
        }
        Ci[WS(csi, 2)] = FMA(KP951056516, T26, T1Z);
        Ci[WS(csi, 18)] = FNMS(KP951056516, T26, T1Z);
        Ci[WS(csi, 12)] = MUL(KP951056516, ADD(T3y, T3x));
        Ci[WS(csi, 8)] = MUL(KP951056516, SUB(T3x, T3y));
        T3t = SUB(T29, T2c);
        Cr[WS(csr, 18)] = FNMS(KP951056516, T3w, T3t);
        Cr[WS(csr, 2)] = FMA(KP951056516, T3w, T3t);
        {
          E T2d, T3n, T3q, T3l, T3m;
          T2d = ADD(T29, T2c);
          Cr[WS(csr, 12)] = SUB(T2d, T2e);
          Cr[WS(csr, 8)] = ADD(T2d, T2e);
          T3n = FNMS(KP951056516, T36, T35);
          T3q = SUB(T3o, T3p);
          Ci[WS(csi, 7)] = FMA(KP707106781, T3q, T3n);
          Ci[WS(csi, 13)] = NEG(FNMS(KP707106781, T3q, T3n));
          T3l = FMA(KP951056516, T3k, T3j);
          T3m = ADD(T3h, T3c);
          Cr[WS(csr, 13)] = FNMS(KP707106781, T3m, T3l);
          Cr[WS(csr, 7)] = FMA(KP707106781, T3m, T3l);
          {
            E T37, T3i, T3r, T3s;
            T37 = FMA(KP951056516, T36, T35);
            T3i = SUB(T3c, T3h);
            Ci[WS(csi, 3)] = FMA(KP707106781, T3i, T37);
            Ci[WS(csi, 17)] = NEG(FNMS(KP707106781, T3i, T37));
            T3r = FNMS(KP951056516, T3k, T3j);
            T3s = ADD(T3o, T3p);
            Cr[WS(csr, 3)] = FNMS(KP707106781, T3s, T3r);
            Cr[WS(csr, 17)] = FMA(KP707106781, T3s, T3r);
          }
        }
      }
    }
  }
}
