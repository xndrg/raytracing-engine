#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include "vec.h"

#define Q(x) #x
#define STR(x) Q(x)
#define UNUSED(x) (void)x

typedef char           i8;
typedef unsigned char  u8;
typedef short         i16;
typedef unsigned char u16;
typedef int           i32;
typedef unsigned int  u32;
typedef long          i64;
typedef unsigned long u64;
typedef float         f32;
typedef double        f64;

typedef vec3 color;

#endif // TYPEDEFS_H_
