/* Generated by: /Users/sfegan/GitHub/fftw3/genfft/gen_r2cf.native -n 32 -standalone -fma -generic-arith -compact -name dft_codelet_r2cf_32 */

/*
 * This function contains 156 FP additions, 68 FP multiplications,
 * (or, 88 additions, 0 multiplications, 68 fused multiply/add),
 * 54 stack variables, 7 constants, and 64 memory accesses
 */
void dft_codelet_r2cf_32(R * R0, R * R1, R * Cr, R * Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
  DK(KP831469612, +0.831469612302545237078788377617905756738560812);
  DK(KP668178637, +0.668178637919298919997757686523080761552472251);
  DK(KP980785280, +0.980785280403230449126182236134239036973933731);
  DK(KP198912367, +0.198912367379658006911597622644676228597850501);
  DK(KP923879532, +0.923879532511286756128183189396788286822416626);
  DK(KP707106781, +0.707106781186547524400844362104849039284835938);
  DK(KP414213562, +0.414213562373095048801688724209698078569671875);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(128, rs), MAKE_VOLATILE_STRIDE(128, csr), MAKE_VOLATILE_STRIDE(128, csi)) {
      E T7, T2b, Tv, T1h, Te, T2n, Ty, T1i, Tt, T2d, TF, T1l, Tm, T2c,
       TC;
      E T1k, T1Z, T22, T2k, T2j, T1e, T1C, T19, T1B, T1S, T1V, T2h,
       T2g, TX, T1z;
      E TS, T1y;
      {
        E T1, T2, T3, T4, T5, T6;
        T1 = R0[0];
        T2 = R0[WS(rs, 8)];
        T3 = ADD(T1, T2);
        T4 = R0[WS(rs, 4)];
        T5 = R0[WS(rs, 12)];
        T6 = ADD(T4, T5);
        T7 = ADD(T3, T6);
        T2b = SUB(T3, T6);
        Tv = SUB(T1, T2);
        T1h = SUB(T4, T5);
      }
      {
        E Ta, Tw, Td, Tx;
        {
          E T8, T9, Tb, Tc;
          T8 = R0[WS(rs, 2)];
          T9 = R0[WS(rs, 10)];
          Ta = ADD(T8, T9);
          Tw = SUB(T8, T9);
          Tb = R0[WS(rs, 14)];
          Tc = R0[WS(rs, 6)];
          Td = ADD(Tb, Tc);
          Tx = SUB(Tb, Tc);
        }
        Te = ADD(Ta, Td);
        T2n = SUB(Td, Ta);
        Ty = ADD(Tw, Tx);
        T1i = SUB(Tx, Tw);
      }
      {
        E Tp, TD, Ts, TE;
        {
          E Tn, To, Tq, Tr;
          Tn = R0[WS(rs, 15)];
          To = R0[WS(rs, 7)];
          Tp = ADD(Tn, To);
          TD = SUB(Tn, To);
          Tq = R0[WS(rs, 3)];
          Tr = R0[WS(rs, 11)];
          Ts = ADD(Tq, Tr);
          TE = SUB(Tq, Tr);
        }
        Tt = ADD(Tp, Ts);
        T2d = SUB(Tp, Ts);
        TF = FMA(KP414213562, TE, TD);
        T1l = FNMS(KP414213562, TD, TE);
      }
      {
        E Ti, TA, Tl, TB;
        {
          E Tg, Th, Tj, Tk;
          Tg = R0[WS(rs, 1)];
          Th = R0[WS(rs, 9)];
          Ti = ADD(Tg, Th);
          TA = SUB(Tg, Th);
          Tj = R0[WS(rs, 5)];
          Tk = R0[WS(rs, 13)];
          Tl = ADD(Tj, Tk);
          TB = SUB(Tj, Tk);
        }
        Tm = ADD(Ti, Tl);
        T2c = SUB(Ti, Tl);
        TC = FNMS(KP414213562, TB, TA);
        T1k = FMA(KP414213562, TA, TB);
      }
      {
        E T11, T1X, T1c, T1Y, T14, T20, T17, T21, T1d, T18;
        {
          E TZ, T10, T1a, T1b;
          TZ = R1[WS(rs, 15)];
          T10 = R1[WS(rs, 7)];
          T11 = SUB(TZ, T10);
          T1X = ADD(TZ, T10);
          T1a = R1[WS(rs, 11)];
          T1b = R1[WS(rs, 3)];
          T1c = SUB(T1a, T1b);
          T1Y = ADD(T1b, T1a);
        }
        {
          E T12, T13, T15, T16;
          T12 = R1[WS(rs, 1)];
          T13 = R1[WS(rs, 9)];
          T14 = SUB(T12, T13);
          T20 = ADD(T12, T13);
          T15 = R1[WS(rs, 13)];
          T16 = R1[WS(rs, 5)];
          T17 = SUB(T15, T16);
          T21 = ADD(T15, T16);
        }
        T1Z = ADD(T1X, T1Y);
        T22 = ADD(T20, T21);
        T2k = SUB(T21, T20);
        T2j = SUB(T1X, T1Y);
        T1d = SUB(T17, T14);
        T1e = FMA(KP707106781, T1d, T1c);
        T1C = FNMS(KP707106781, T1d, T1c);
        T18 = ADD(T14, T17);
        T19 = FMA(KP707106781, T18, T11);
        T1B = FNMS(KP707106781, T18, T11);
      }
      {
        E TK, T1Q, TV, T1R, TN, T1T, TQ, T1U, TW, TR;
        {
          E TI, TJ, TT, TU;
          TI = R1[0];
          TJ = R1[WS(rs, 8)];
          TK = SUB(TI, TJ);
          T1Q = ADD(TI, TJ);
          TT = R1[WS(rs, 4)];
          TU = R1[WS(rs, 12)];
          TV = SUB(TT, TU);
          T1R = ADD(TT, TU);
        }
        {
          E TL, TM, TO, TP;
          TL = R1[WS(rs, 2)];
          TM = R1[WS(rs, 10)];
          TN = SUB(TL, TM);
          T1T = ADD(TL, TM);
          TO = R1[WS(rs, 14)];
          TP = R1[WS(rs, 6)];
          TQ = SUB(TO, TP);
          T1U = ADD(TO, TP);
        }
        T1S = ADD(T1Q, T1R);
        T1V = ADD(T1T, T1U);
        T2h = SUB(T1U, T1T);
        T2g = SUB(T1Q, T1R);
        TW = SUB(TN, TQ);
        TX = FMA(KP707106781, TW, TV);
        T1z = FNMS(KP707106781, TW, TV);
        TR = ADD(TN, TQ);
        TS = FMA(KP707106781, TR, TK);
        T1y = FNMS(KP707106781, TR, TK);
      }
      {
        E Tf, Tu, T27, T28, T29, T2a;
        Tf = ADD(T7, Te);
        Tu = ADD(Tm, Tt);
        T27 = ADD(Tf, Tu);
        T28 = ADD(T1S, T1V);
        T29 = ADD(T1Z, T22);
        T2a = ADD(T28, T29);
        Cr[WS(csr, 8)] = SUB(Tf, Tu);
        Ci[WS(csi, 8)] = SUB(T29, T28);
        Cr[WS(csr, 16)] = SUB(T27, T2a);
        Cr[0] = ADD(T27, T2a);
      }
      {
        E T1P, T25, T24, T26, T1W, T23;
        T1P = SUB(T7, Te);
        T25 = SUB(Tt, Tm);
        T1W = SUB(T1S, T1V);
        T23 = SUB(T1Z, T22);
        T24 = ADD(T1W, T23);
        T26 = SUB(T23, T1W);
        Cr[WS(csr, 12)] = FNMS(KP707106781, T24, T1P);
        Ci[WS(csi, 12)] = NEG(FNMS(KP707106781, T26, T25));
        Cr[WS(csr, 4)] = FMA(KP707106781, T24, T1P);
        Ci[WS(csi, 4)] = FMA(KP707106781, T26, T25);
      }
      {
        E T2f, T2v, T2p, T2r, T2m, T2q, T2u, T2w, T2e, T2o;
        T2e = ADD(T2c, T2d);
        T2f = FMA(KP707106781, T2e, T2b);
        T2v = FNMS(KP707106781, T2e, T2b);
        T2o = SUB(T2d, T2c);
        T2p = FNMS(KP707106781, T2o, T2n);
        T2r = FMA(KP707106781, T2o, T2n);
        {
          E T2i, T2l, T2s, T2t;
          T2i = FMA(KP414213562, T2h, T2g);
          T2l = FNMS(KP414213562, T2k, T2j);
          T2m = ADD(T2i, T2l);
          T2q = SUB(T2l, T2i);
          T2s = FNMS(KP414213562, T2g, T2h);
          T2t = FMA(KP414213562, T2j, T2k);
          T2u = ADD(T2s, T2t);
          T2w = SUB(T2t, T2s);
        }
        Cr[WS(csr, 14)] = FNMS(KP923879532, T2m, T2f);
        Ci[WS(csi, 14)] = NEG(FNMS(KP923879532, T2u, T2r));
        Cr[WS(csr, 2)] = FMA(KP923879532, T2m, T2f);
        Ci[WS(csi, 2)] = FMA(KP923879532, T2u, T2r);
        Ci[WS(csi, 6)] = NEG(FNMS(KP923879532, T2q, T2p));
        Cr[WS(csr, 6)] = FMA(KP923879532, T2w, T2v);
        Ci[WS(csi, 10)] = FMA(KP923879532, T2q, T2p);
        Cr[WS(csr, 10)] = FNMS(KP923879532, T2w, T2v);
      }
      {
        E TH, T1t, T1s, T1u, T1g, T1o, T1n, T1p;
        {
          E Tz, TG, T1q, T1r;
          Tz = FMA(KP707106781, Ty, Tv);
          TG = ADD(TC, TF);
          TH = FMA(KP923879532, TG, Tz);
          T1t = FNMS(KP923879532, TG, Tz);
          T1q = FMA(KP198912367, T19, T1e);
          T1r = FMA(KP198912367, TS, TX);
          T1s = SUB(T1q, T1r);
          T1u = ADD(T1r, T1q);
        }
        {
          E TY, T1f, T1j, T1m;
          TY = FNMS(KP198912367, TX, TS);
          T1f = FNMS(KP198912367, T1e, T19);
          T1g = ADD(TY, T1f);
          T1o = SUB(T1f, TY);
          T1j = FNMS(KP707106781, T1i, T1h);
          T1m = ADD(T1k, T1l);
          T1n = FNMS(KP923879532, T1m, T1j);
          T1p = FMA(KP923879532, T1m, T1j);
        }
        Cr[WS(csr, 15)] = FNMS(KP980785280, T1g, TH);
        Ci[WS(csi, 15)] = FMA(KP980785280, T1s, T1p);
        Cr[WS(csr, 1)] = FMA(KP980785280, T1g, TH);
        Ci[WS(csi, 1)] = NEG(FNMS(KP980785280, T1s, T1p));
        Ci[WS(csi, 7)] = FMA(KP980785280, T1o, T1n);
        Cr[WS(csr, 7)] = FMA(KP980785280, T1u, T1t);
        Ci[WS(csi, 9)] = NEG(FNMS(KP980785280, T1o, T1n));
        Cr[WS(csr, 9)] = FNMS(KP980785280, T1u, T1t);
      }
      {
        E T1x, T1N, T1M, T1O, T1E, T1I, T1H, T1J;
        {
          E T1v, T1w, T1K, T1L;
          T1v = FNMS(KP707106781, Ty, Tv);
          T1w = SUB(T1k, T1l);
          T1x = FMA(KP923879532, T1w, T1v);
          T1N = FNMS(KP923879532, T1w, T1v);
          T1K = FNMS(KP668178637, T1y, T1z);
          T1L = FNMS(KP668178637, T1B, T1C);
          T1M = SUB(T1K, T1L);
          T1O = ADD(T1K, T1L);
        }
        {
          E T1A, T1D, T1F, T1G;
          T1A = FMA(KP668178637, T1z, T1y);
          T1D = FMA(KP668178637, T1C, T1B);
          T1E = ADD(T1A, T1D);
          T1I = SUB(T1D, T1A);
          T1F = FMA(KP707106781, T1i, T1h);
          T1G = SUB(TF, TC);
          T1H = FNMS(KP923879532, T1G, T1F);
          T1J = FMA(KP923879532, T1G, T1F);
        }
        Cr[WS(csr, 13)] = FNMS(KP831469612, T1E, T1x);
        Ci[WS(csi, 13)] = NEG(FNMS(KP831469612, T1M, T1J));
        Cr[WS(csr, 3)] = FMA(KP831469612, T1E, T1x);
        Ci[WS(csi, 3)] = FMA(KP831469612, T1M, T1J);
        Ci[WS(csi, 5)] = NEG(FNMS(KP831469612, T1I, T1H));
        Cr[WS(csr, 5)] = FNMS(KP831469612, T1O, T1N);
        Ci[WS(csi, 11)] = FMA(KP831469612, T1I, T1H);
        Cr[WS(csr, 11)] = FMA(KP831469612, T1O, T1N);
      }
    }
  }
}
