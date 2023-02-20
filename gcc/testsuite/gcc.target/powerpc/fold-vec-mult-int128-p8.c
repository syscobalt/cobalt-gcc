/* Verify that overloaded built-ins for vec_mul with __int128
   inputs produce the right results.  */

/* { dg-do compile } */
/* { dg-require-effective-target powerpc_p8vector_ok } */
/* { dg-require-effective-target int128 } */
/* { dg-require-effective-target lp64 } */
/* { dg-options "-mpower8-vector -mdejagnu-cpu=power8 -O2" } */
/* { dg-additional-options "-maix64" { target powerpc-ibm-aix* } } */

#include "altivec.h"

vector signed __int128
test1 (vector signed __int128 x, vector signed __int128 y)
{
  return vec_mul (x, y);
}

vector unsigned __int128
test2 (vector unsigned __int128 x, vector unsigned __int128 y)
{
  return vec_mul (x, y);
}

/* { dg-final { scan-assembler-times {\mmulld\M} 6 } } */
/* { dg-final { scan-assembler-times {\mmulhdu\M} 2 } } */
