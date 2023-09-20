#ifndef BASE_LAYER_H
#define BASE_LAYER_H

// basic types
#include <stdint.h>
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

#define Bytes(n) n
#define KiloBytes(n) Bytes(n) * 1024
#define MegaBytes(n) KiloBytes(n) * 1024
#define GigaBytes(n) MegaBytes(n) * 1024

#define Stringify(s) #s

#define AssertBreak()                                                                                                  \
    {                                                                                                                  \
        char* c = NULL;                                                                                                \
        *c = 0;                                                                                                        \
    }

#define Assert(e)                                                                                                      \
    if (!(e)) {                                                                                                        \
        printf("%s failed\n", #e);                                                                                     \
        AssertBreak();                                                                                                 \
    }

#define ArrayCount(a) (sizeof(a) / sizeof(*(a)))

#define IntFromPtr(p) (unsigned long long)((char*)p - (char*)0)

#define Member(T, m) (((T*)0)->m)
#define OffsetOfMember(T, m) IntFromPtr(&Member(T, m))

#define Min(a, b) (((a) < (b)) ? (a) : (b))
#define Max(a, b) (((a) > (b)) ? (a) : (b))

// debug printing
#define EvalPrintInt(x) printf("%s = %d\n", #x, x)
#define EvalPrintUInt(x) printf("%s = %u\n", #x, x)
#define EvalPrintFloat(x) printf("%s = %f\n", #x, x)
#define EvalPrintPtr(x) printf("%s = %p\n", #x, (void*)x)
#define EvalPrintChar(x) printf("%s = '%c'\n", #x, x)
#define EvalPrintString(x) printf("%s = \"%s\"\n", #x, x)

#endif // !BASE_LAYER_H
