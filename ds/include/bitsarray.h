#ifndef __BITSARRAY_H__
#define __BITSARRAY_H__

typedef size_t bitsarr_t;

int SetAll(size_t *bits);
int ResetAll(size_t *bits);
int IsOn(size_t *bits, int position);
int IsOff(size_t *bits, int position);
int CountOn(size_t *bits);
int CountOff(size_t *bits);
int SetOn(size_t *bits, int position);
int SetOff(size_t *bits, int position);
int SetBit(size_t *bits, int position, int status);
int FlipBit(size_t *bits, int position);
int RotateLeft(size_t *bits, int num_of_rotation);
int RotateRight(size_t *bits, int num_of_rotation);
char* ToStr(size_t *bits);
int mirror(size_t *bits);

#endif
