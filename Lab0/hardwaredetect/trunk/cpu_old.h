
namespace CPU{
typedef char  I8;
typedef short I16;
typedef int   I32;
typedef long long I64;
typedef unsigned char  U8;
typedef unsigned short U16;
typedef unsigned int   U32;
typedef unsigned long long U64;
typedef float F32;
typedef double F64;
typedef long double F80;
typedef union {
	unsigned long long v64;
	struct {
		unsigned int low;
		unsigned int high;
	};
} _U64;

typedef U32 register_t;

#define register64 \
union{\
	I8   civec[8];\
	I16  wivec[4];\
	I32  divec[3];\
	I64  qivec[1];\
	U8   cuvec[8];\
	U16  wuvec[4];\
	U32  duvec[2];\
	U64  quvec[1];\
	F32  fvec[2];\
	F64  dvec[1];\
}


#define register128 \
union{\
	I8   civec[16];\
	I16  wivec[8];\
	I32  divec[4];\
	I64  qivec[2];\
	U8   cuvec[16];\
	U16  wuvec[8];\
	U32  duvec[4];\
	U64  quvec[2];\
	F32  fvec[4];\
	F64  dvec[2];\
}

#define registerGroupMMS  \
union{ \
    m64 mms[8]; \
    m64 sts[8]; \
    struct{ \
        F64 st0; \
        F64 st1; \
        F64 st2; \
        F64 st3; \
        F64 st4; \
        F64 st5; \
        F64 st6; \
        F64 st7; \
    }; \
    struct{ \
        m64 mm0; \
        m64 mm1; \
        m64 mm2; \
        m64 mm3; \
        m64 mm4; \
        m64 mm5; \
        m64 mm6; \
        m64 mm7; \
    }; \
}


#define registerGroupXMMS  \
    union{ \
        m128	xmms[8]; \
        struct{ \
            m128 xmm0; \
            m128 xmm1; \
            m128 xmm2; \
            m128 xmm3; \
            m128 xmm4; \
            m128 xmm5; \
            m128 xmm6; \
            m128 xmm7; \
        }; \
    }

#define registerGroupGRPS  \
    union{ \
        U32 GRP[8]; \
        struct { \
            U32 eax; \
            U32 ebx; \
            U32 ecx; \
            U32 edx; \
            U32 esi; \
            U32 edi; \
            U32 esp; \
            U32 ebp; \
        }; \
    }

#define registerGroupSeg\
    union{ \
        U16 seg[6]; \
        struct { \
            U32 cs; \
            U32 ds; \
            U32 ss; \
            U32 es; \
            U32 fs; \
            U32 gs; \
        }; \
    }

#define registerGroupFPU  \
    union{ \
        unsigned int fpu[8]; \
    }

class m64{
    public:
        register64;
    public:	
};

class m128 {
    public:
        register128 ;
    public:	
};

class SIMD {
    public:
        registerGroupXMMS;
};

class LU {
    public:
        registerGroupGRPS;
};

/*
 * =====================================================================================
 *        Class:  registers
 *  Description:  32-bit arch
 * =====================================================================================
 */
class registers
{
    public:
        registerGroupGRPS;
        registerGroupXMMS;	
        registerGroupMMS;	
        U32 eflags;
        U32 eip;
        registerGroupSeg;
    public:
        registers(){}
        void	print(){
            for(int i=0;i<4;i++)
                printf("%08x\t", GRP[i]);
            printf("\n");
        }
        void	printn(){
            for(int i=0;i<4;i++)
                printf("%08x\n", GRP[i]);
        }
} ;


/*
 * =====================================================================================
 *        Class:  CPU
 *  Description:  32-bit CPU
 * =====================================================================================
 */
class CPU 
{
    public:
        union{
            registerGroupGRPS;
            LU lu;
        };
        union{
            registerGroupXMMS;	
            SIMD simd;
        };

    public:
        CPU(){}
        void	print(){
            for(int i=0;i<4;i++)
                printf("%08x\t", GRP[i]);
            printf("\n");
        }
        void	printn(){
            for(int i=0;i<4;i++)
                printf("%08x\n", GRP[i]);
        }
} ;


}
