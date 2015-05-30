//-----------------------------------------------------------------------------
// Copyright 2012-2015 Masanori Morise. All Rights Reserved.
// Author: mmorise [at] yamanashi.ac.jp (Masanori Morise)
//-----------------------------------------------------------------------------
#ifndef WORLD_SYNTHESIS_H_
#define WORLD_SYNTHESIS_H_

#include "./dllexport.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Synthesis() synthesize the voice based on f0, spectrogram and
// aperiodicity (not excitation signal).
// Input:
//   f0                   : f0 contour
//   f0_length            : Length of f0
//   spectrogram          : Spectrogram estimated by CheapTrick
//   fft_size             : FFT size
//   aperiodicity         : Aperiodicity spectrogram based on D4C
//   frame_period         : Temporal period used for the analysis
//   fs                   : Sampling frequency
//   y_length             : Length of the output signal (Memory of y has been
//                          allocated in advance)
// Output:
//   y                    : Calculated speech
//-----------------------------------------------------------------------------
DLLEXPORT void Synthesis(double *f0, int f0_length, double **spectrogram,
    double **aperiodicity, int fft_size, double frame_period, int fs,
    int y_length, double *y);

#ifdef __cplusplus
}
#endif

#endif  // WORLD_SYNTHESIS_H_
