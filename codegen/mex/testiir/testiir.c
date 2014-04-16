/*
 * testiir.c
 *
 * Code generation for function 'testiir'
 *
 * C source code generated on: Fri Mar 28 11:25:03 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testiir.h"
#include "setup.h"
#include "BiquadFilter.h"
#include "testiir_data.h"

/* Variable Definitions */
static dspcodegen_BiquadFilter Hd;
static boolean_T Hd_not_empty;
static emlrtRSInfo emlrtRSI = { 31, "testiir",
  "/Users/Johan/Documents/MATLAB/testiir.m" };

static emlrtRSInfo b_emlrtRSI = { 45, "testiir",
  "/Users/Johan/Documents/MATLAB/testiir.m" };

static emlrtRSInfo d_emlrtRSI = { 1, "SystemCore",
  "/Applications/MATLAB_R2013b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"
};

static emlrtRSInfo e_emlrtRSI = { 1, "SystemProp",
  "/Applications/MATLAB_R2013b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"
};

static emlrtRSInfo h_emlrtRSI = { 1, "Nondirect",
  "/Applications/MATLAB_R2013b.app/toolbox/shared/system/coder/+matlab/+system/+mixin/+coder/Nondirect.p"
};

static emlrtMCInfo emlrtMCI = { 1, 1, "SystemCore",
  "/Applications/MATLAB_R2013b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"
};

static emlrtRTEInfo emlrtRTEI = { 43, 1, "setup",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/scomp/setup.m" };

static emlrtRTEInfo b_emlrtRTEI = { 19, 1, "reset",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/scomp/reset.m" };

static emlrtRTEInfo c_emlrtRTEI = { 41, 1, "update",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/scomp/update.m" };

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", TRUE, location);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m2;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m2, 2, pArrays, "message", TRUE, location);
}

void Hd_not_empty_init(void)
{
  Hd_not_empty = FALSE;
}

void testiir(const emlrtStack *sp, const real_T x[512], real_T y[512])
{
  dspcodegen_BiquadFilter *obj;
  const mxArray *b_y;
  static const int32_T iv0[2] = { 1, 45 };

  const mxArray *m0;
  char_T cv0[45];
  int32_T i;
  static const char_T cv1[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y',
    's', 't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l',
    'e', 'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C',
    'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 4 };

  char_T cv2[4];
  static const char_T cv3[4] = { 's', 't', 'e', 'p' };

  const mxArray *d_y;
  static const int32_T iv2[2] = { 1, 51 };

  char_T cv4[51];
  static const char_T cv5[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y',
    's', 't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l',
    'e', 'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l',
    'e', 'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *e_y;
  static const int32_T iv3[2] = { 1, 5 };

  char_T cv6[5];
  static const char_T cv7[5] = { 's', 'e', 't', 'u', 'p' };

  static const int16_T value[8] = { 512, 1, 1, 1, 1, 1, 1, 1 };

  dsp_BiquadFilter_0 *b_obj;
  boolean_T anyInputSizeChanged;
  boolean_T exitg1;
  static const int16_T iv4[8] = { 512, 1, 1, 1, 1, 1, 1, 1 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;

  /* TESTIIR Filters input x and returns output y. */
  /*  MATLAB Code */
  /*  Generated by MATLAB(R) 8.2 and the DSP System Toolbox 8.5. */
  /*  Generated on: 28-Mar-2014 11:05:02 */
  /*  To generate C/C++ code from this function use the codegen command. */
  /*  Type 'help codegen' for more information. */
  if (!Hd_not_empty) {
    /*  The following code was used to design the filter coefficients: */
    /*  */
    /*  Fpass = 15000;   % Passband Frequency */
    /*  Fstop = 16000;   % Stopband Frequency */
    /*  Apass = 1;       % Passband Ripple (dB) */
    /*  Astop = 85;      % Stopband Attenuation (dB) */
    /*  Fs    = 480000;  % Sampling Frequency */
    /*  */
    /*  h = fdesign.lowpass('fp,fst,ap,ast', Fpass, Fstop, Apass, Astop, Fs); */
    /*  */
    /*  Hd = design(h, 'ellip', ... */
    /*      'MatchExactly', 'both', ... */
    /*      'SystemObject', true); */
    st.site = &emlrtRSI;
    BiquadFilter_BiquadFilter(&Hd);
    Hd_not_empty = TRUE;
  }

  st.site = &b_emlrtRSI;
  obj = &Hd;
  if (!obj->isReleased) {
  } else {
    b_y = NULL;
    m0 = mxCreateCharArray(2, iv0);
    for (i = 0; i < 45; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(&st, 45, m0, cv0);
    emlrtAssign(&b_y, m0);
    c_y = NULL;
    m0 = mxCreateCharArray(2, iv1);
    for (i = 0; i < 4; i++) {
      cv2[i] = cv3[i];
    }

    emlrtInitCharArrayR2013a(&st, 4, m0, cv2);
    emlrtAssign(&c_y, m0);
    b_st.site = &d_emlrtRSI;
    error(&b_st, message(&b_st, b_y, c_y, &emlrtMCI), &emlrtMCI);
  }

  if (!obj->isInitialized) {
    b_st.site = &d_emlrtRSI;
    if (!obj->isInitialized) {
    } else {
      d_y = NULL;
      m0 = mxCreateCharArray(2, iv2);
      for (i = 0; i < 51; i++) {
        cv4[i] = cv5[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 51, m0, cv4);
      emlrtAssign(&d_y, m0);
      e_y = NULL;
      m0 = mxCreateCharArray(2, iv3);
      for (i = 0; i < 5; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 5, m0, cv6);
      emlrtAssign(&e_y, m0);
      c_st.site = &d_emlrtRSI;
      error(&c_st, message(&c_st, d_y, e_y, &emlrtMCI), &emlrtMCI);
    }

    c_st.site = &d_emlrtRSI;
    obj->isInitialized = TRUE;
    d_st.site = &e_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    for (i = 0; i < 8; i++) {
      obj->inputVarSize1[i] = (uint32_T)value[i];
    }

    c_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    b_obj = &obj->cSFunObject;
    if (!b_obj->S0_isInitialized) {
      b_obj->S0_isInitialized = TRUE;
      if (b_obj->S1_isReleased) {
        emlrtErrorWithMessageIdR2012b(&d_st, &emlrtRTEI,
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen", 0);
      }

      /* System object Initialization function: dsp.BiquadFilter */
      for (i = 0; i < 12; i++) {
        b_obj->W0_FILT_STATES[i] = b_obj->P0_ICRTP;
      }
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &emlrtRTEI,
        "MATLAB:system:setupCalledWhenLockedCodegen", 0);
    }

    d_st.site = &f_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    b_obj = &obj->cSFunObject;
    if (b_obj->S1_isReleased) {
      emlrtErrorWithMessageIdR2012b(&d_st, &b_emlrtRTEI,
        "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }

    /* System object Initialization function: dsp.BiquadFilter */
    for (i = 0; i < 12; i++) {
      b_obj->W0_FILT_STATES[i] = b_obj->P0_ICRTP;
    }
  }

  b_st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &d_emlrtRSI;
  c_st.site = &d_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  anyInputSizeChanged = FALSE;
  i = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (i < 8)) {
    if (obj->inputVarSize1[i] != (uint32_T)iv4[i]) {
      anyInputSizeChanged = TRUE;
      c_st.site = &d_emlrtRSI;
      for (i = 0; i < 8; i++) {
        obj->inputVarSize1[i] = (uint32_T)value[i];
      }

      d_st.site = &e_emlrtRSI;
      exitg1 = TRUE;
    } else {
      i++;
    }
  }

  if (anyInputSizeChanged) {
    b_st.site = &d_emlrtRSI;
    b_st.site = &d_emlrtRSI;
  }

  b_st.site = &d_emlrtRSI;
  c_st.site = &d_emlrtRSI;
  c_st.site = &d_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &h_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  c_st.site = &h_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  c_st.site = &h_emlrtRSI;
  c_st.site = &h_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  c_st.site = &h_emlrtRSI;
  c_st.site = &h_emlrtRSI;
  BiquadFilter_outputImpl(&c_st, obj, x, y);
  c_st.site = &h_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  if (!obj->cSFunObject.S0_isInitialized) {
    emlrtErrorWithMessageIdR2012b(&d_st, &c_emlrtRTEI,
      "MATLAB:system:updateCalledBeforeSetup", 0);
  }
}

void testiir_free(void)
{
  Destructor(&Hd.cSFunObject);
}

/* End of code generation (testiir.c) */