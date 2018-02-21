/* Generated by: /Users/sfegan/GitHub/fftw3/genfft/gen_r2cb.native -n 30 -standalone -fma -generic-arith -compact -name dft_codelet_r2cb_30 */

/*
 * This function contains 158 FP additions, 86 FP multiplications,
 * (or, 72 additions, 0 multiplications, 86 fused multiply/add),
 * 60 stack variables, 9 constants, and 60 memory accesses
 */
void dft_codelet_r2cb_30(R * R0, R * R1, R * Cr, R * Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
  DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
  DK(KP618033988, +0.618033988749894848204586834365638117720309180);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(120, rs), MAKE_VOLATILE_STRIDE(120, csr), MAKE_VOLATILE_STRIDE(120, csi)) {
      E TC, T1k, T5, Tz, T1j, TJ, T1n, Ta, TG, T1m, T1L, TV, T1X, T1r,
       T1K;
      E T1W, T1Q, T16, T24, T1u, T1P, T23, Tt, T2o, T28, TZ, T1t, Tk,
       T2l, T21;
      E TO, T1q;
      {
        E TA, TB, TH, TI;
        TA = Ci[WS(csi, 6)];
        TB = Ci[WS(csi, 12)];
        TC = FMA(KP618033988, TB, TA);
        T1k = FNMS(KP618033988, TA, TB);
        {
          E T1, T4, Ty, T2, T3, Tx;
          T1 = Cr[0];
          T2 = Cr[WS(csr, 6)];
          T3 = Cr[WS(csr, 12)];
          T4 = ADD(T2, T3);
          Ty = SUB(T2, T3);
          T5 = FMA(KP2_000000000, T4, T1);
          Tx = FNMS(KP500000000, T4, T1);
          Tz = FMA(KP1_118033988, Ty, Tx);
          T1j = FNMS(KP1_118033988, Ty, Tx);
        }
        TH = Ci[WS(csi, 9)];
        TI = Ci[WS(csi, 3)];
        TJ = FMA(KP618033988, TI, TH);
        T1n = FMS(KP618033988, TH, TI);
        {
          E T6, T9, TF, T7, T8, TE;
          T6 = Cr[WS(csr, 15)];
          T7 = Cr[WS(csr, 9)];
          T8 = Cr[WS(csr, 3)];
          T9 = ADD(T7, T8);
          TF = SUB(T7, T8);
          Ta = FMA(KP2_000000000, T9, T6);
          TE = FNMS(KP500000000, T9, T6);
          TG = FMA(KP1_118033988, TF, TE);
          T1m = FNMS(KP1_118033988, TF, TE);
        }
      }
      {
        E TU, T1J, TR, T1I;
        T1L = Ci[WS(csi, 10)];
        {
          E TS, TT, TP, TQ;
          TS = Ci[WS(csi, 2)];
          TT = Ci[WS(csi, 8)];
          TU = SUB(TS, TT);
          T1J = ADD(TS, TT);
          TP = Ci[WS(csi, 14)];
          TQ = Ci[WS(csi, 4)];
          TR = ADD(TP, TQ);
          T1I = SUB(TQ, TP);
        }
        TV = FNMS(KP618033988, TU, TR);
        T1X = ADD(T1I, T1J);
        T1r = FMA(KP618033988, TR, TU);
        T1K = SUB(T1I, T1J);
        T1W = FNMS(KP250000000, T1K, T1L);
      }
      {
        E T15, T1O, T12, T1N;
        T1Q = Ci[WS(csi, 5)];
        {
          E T13, T14, T10, T11;
          T13 = Ci[WS(csi, 7)];
          T14 = Ci[WS(csi, 13)];
          T15 = SUB(T13, T14);
          T1O = ADD(T13, T14);
          T10 = Ci[WS(csi, 1)];
          T11 = Ci[WS(csi, 11)];
          T12 = ADD(T10, T11);
          T1N = SUB(T10, T11);
        }
        T16 = FMA(KP618033988, T15, T12);
        T24 = SUB(T1N, T1O);
        T1u = FNMS(KP618033988, T12, T15);
        T1P = ADD(T1N, T1O);
        T23 = FMA(KP250000000, T1P, T1Q);
      }
      {
        E Tl, To, Tr, Ts, T27, T26, TX, TY;
        Tl = Cr[WS(csr, 5)];
        {
          E Tm, Tn, Tp, Tq;
          Tm = Cr[WS(csr, 1)];
          Tn = Cr[WS(csr, 11)];
          To = ADD(Tm, Tn);
          Tp = Cr[WS(csr, 7)];
          Tq = Cr[WS(csr, 13)];
          Tr = ADD(Tp, Tq);
          Ts = ADD(To, Tr);
          T27 = SUB(Tp, Tq);
          T26 = SUB(Tm, Tn);
        }
        Tt = ADD(Tl, Ts);
        T2o = FNMS(KP618033988, T26, T27);
        T28 = FMA(KP618033988, T27, T26);
        TX = FNMS(KP250000000, Ts, Tl);
        TY = SUB(To, Tr);
        TZ = FMA(KP559016994, TY, TX);
        T1t = FNMS(KP559016994, TY, TX);
      }
      {
        E Tc, Tf, Ti, Tj, T20, T1Z, TM, TN;
        Tc = Cr[WS(csr, 10)];
        {
          E Td, Te, Tg, Th;
          Td = Cr[WS(csr, 14)];
          Te = Cr[WS(csr, 4)];
          Tf = ADD(Td, Te);
          Tg = Cr[WS(csr, 8)];
          Th = Cr[WS(csr, 2)];
          Ti = ADD(Tg, Th);
          Tj = ADD(Tf, Ti);
          T20 = SUB(Tg, Th);
          T1Z = SUB(Td, Te);
        }
        Tk = ADD(Tc, Tj);
        T2l = FNMS(KP618033988, T1Z, T20);
        T21 = FMA(KP618033988, T20, T1Z);
        TM = FNMS(KP250000000, Tj, Tc);
        TN = SUB(Tf, Ti);
        TO = FMA(KP559016994, TN, TM);
        T1q = FNMS(KP559016994, TN, TM);
      }
      {
        E Tb, Tu, T1T, Tv, Tw, T1H, T1S, T1U, T1M, T1R;
        Tb = ADD(T5, Ta);
        Tu = ADD(Tk, Tt);
        T1T = SUB(Tb, Tu);
        Tv = SUB(T5, Ta);
        Tw = SUB(Tt, Tk);
        T1H = ADD(Tv, Tw);
        T1M = ADD(T1K, T1L);
        T1R = SUB(T1P, T1Q);
        T1S = SUB(T1M, T1R);
        T1U = ADD(T1M, T1R);
        R0[0] = FMA(KP2_000000000, Tu, Tb);
        R1[WS(rs, 7)] = FNMS(KP2_000000000, Tw, Tv);
        R0[WS(rs, 5)] = FMA(KP1_732050807, T1U, T1T);
        R0[WS(rs, 10)] = FNMS(KP1_732050807, T1U, T1T);
        R1[WS(rs, 12)] = FMA(KP1_732050807, T1S, T1H);
        R1[WS(rs, 2)] = FNMS(KP1_732050807, T1S, T1H);
      }
      {
        E T2m, T2u, T2p, T2v, T1p, T1x, T1E, T1G, T1B, T1F, T1w, T1y,
         T1C, T1D;
        {
          E T2k, T2n, T1l, T1o;
          T2k = FNMS(KP559016994, T1X, T1W);
          T2m = FMA(KP951056516, T2l, T2k);
          T2u = FNMS(KP951056516, T2l, T2k);
          T2n = FMA(KP559016994, T24, T23);
          T2p = FNMS(KP951056516, T2o, T2n);
          T2v = FMA(KP951056516, T2o, T2n);
          T1l = FNMS(KP1_902113032, T1k, T1j);
          T1o = FNMS(KP1_902113032, T1n, T1m);
          T1p = ADD(T1l, T1o);
          T1x = SUB(T1l, T1o);
        }
        T1C = FMA(KP951056516, T1r, T1q);
        T1D = FMA(KP951056516, T1u, T1t);
        T1E = ADD(T1C, T1D);
        T1G = SUB(T1D, T1C);
        {
          E T1z, T1A, T1s, T1v;
          T1z = FMA(KP1_902113032, T1k, T1j);
          T1A = FMA(KP1_902113032, T1n, T1m);
          T1B = ADD(T1z, T1A);
          T1F = SUB(T1z, T1A);
          T1s = FNMS(KP951056516, T1r, T1q);
          T1v = FNMS(KP951056516, T1u, T1t);
          T1w = ADD(T1s, T1v);
          T1y = SUB(T1v, T1s);
        }
        R0[WS(rs, 6)] = FMA(KP2_000000000, T1w, T1p);
        R0[WS(rs, 9)] = FMA(KP2_000000000, T1E, T1B);
        R1[WS(rs, 1)] = FNMS(KP2_000000000, T1G, T1F);
        R1[WS(rs, 13)] = FNMS(KP2_000000000, T1y, T1x);
        {
          E T2j, T2q, T2t, T2w;
          T2j = SUB(T1p, T1w);
          T2q = SUB(T2m, T2p);
          R0[WS(rs, 1)] = FNMS(KP1_732050807, T2q, T2j);
          R0[WS(rs, 11)] = FMA(KP1_732050807, T2q, T2j);
          T2t = SUB(T1B, T1E);
          T2w = SUB(T2u, T2v);
          R0[WS(rs, 4)] = FNMS(KP1_732050807, T2w, T2t);
          R0[WS(rs, 14)] = FMA(KP1_732050807, T2w, T2t);
        }
        {
          E T2x, T2y, T2r, T2s;
          T2x = ADD(T1F, T1G);
          T2y = ADD(T2u, T2v);
          R1[WS(rs, 11)] = FNMS(KP1_732050807, T2y, T2x);
          R1[WS(rs, 6)] = FMA(KP1_732050807, T2y, T2x);
          T2r = ADD(T1x, T1y);
          T2s = ADD(T2m, T2p);
          R1[WS(rs, 8)] = FNMS(KP1_732050807, T2s, T2r);
          R1[WS(rs, 3)] = FMA(KP1_732050807, T2s, T2r);
        }
      }
      {
        E T22, T2e, T29, T2f, TL, T19, T1g, T1i, T1d, T1h, T18, T1a,
         T1e, T1f;
        {
          E T1Y, T25, TD, TK;
          T1Y = FMA(KP559016994, T1X, T1W);
          T22 = FNMS(KP951056516, T21, T1Y);
          T2e = FMA(KP951056516, T21, T1Y);
          T25 = FNMS(KP559016994, T24, T23);
          T29 = FMA(KP951056516, T28, T25);
          T2f = FNMS(KP951056516, T28, T25);
          TD = FNMS(KP1_902113032, TC, Tz);
          TK = FMA(KP1_902113032, TJ, TG);
          TL = ADD(TD, TK);
          T19 = SUB(TD, TK);
        }
        T1e = FNMS(KP951056516, TV, TO);
        T1f = FMA(KP951056516, T16, TZ);
        T1g = ADD(T1e, T1f);
        T1i = SUB(T1f, T1e);
        {
          E T1b, T1c, TW, T17;
          T1b = FMA(KP1_902113032, TC, Tz);
          T1c = FNMS(KP1_902113032, TJ, TG);
          T1d = ADD(T1b, T1c);
          T1h = SUB(T1b, T1c);
          TW = FMA(KP951056516, TV, TO);
          T17 = FNMS(KP951056516, T16, TZ);
          T18 = ADD(TW, T17);
          T1a = SUB(T17, TW);
        }
        R0[WS(rs, 12)] = FMA(KP2_000000000, T18, TL);
        R0[WS(rs, 3)] = FMA(KP2_000000000, T1g, T1d);
        R1[WS(rs, 10)] = FNMS(KP2_000000000, T1i, T1h);
        R1[WS(rs, 4)] = FNMS(KP2_000000000, T1a, T19);
        {
          E T1V, T2a, T2d, T2g;
          T1V = SUB(T1d, T1g);
          T2a = SUB(T22, T29);
          R0[WS(rs, 13)] = FNMS(KP1_732050807, T2a, T1V);
          R0[WS(rs, 8)] = FMA(KP1_732050807, T2a, T1V);
          T2d = SUB(TL, T18);
          T2g = SUB(T2e, T2f);
          R0[WS(rs, 7)] = FNMS(KP1_732050807, T2g, T2d);
          R0[WS(rs, 2)] = FMA(KP1_732050807, T2g, T2d);
        }
        {
          E T2h, T2i, T2b, T2c;
          T2h = ADD(T19, T1a);
          T2i = ADD(T2e, T2f);
          R1[WS(rs, 14)] = FNMS(KP1_732050807, T2i, T2h);
          R1[WS(rs, 9)] = FMA(KP1_732050807, T2i, T2h);
          T2b = ADD(T1h, T1i);
          T2c = ADD(T22, T29);
          R1[WS(rs, 5)] = FNMS(KP1_732050807, T2c, T2b);
          R1[0] = FMA(KP1_732050807, T2c, T2b);
        }
      }
    }
  }
}
