
//******************************************************************************
// DEFINES
//******************************************************************************
//
// XMM Macros
//
#define	LAT_XX( x )				__asm x	xmm0,xmm7		\
								__asm x	xmm1,xmm0		\
								__asm x	xmm2,xmm1		\
								__asm x	xmm3,xmm2		\
								__asm x	xmm4,xmm3		\
								__asm x	xmm5,xmm4		\
								__asm x	xmm6,xmm5		\
								__asm x	xmm7,xmm6

#define	LAT_XXi( x,imm )		__asm x	xmm0,xmm7,imm	\
								__asm x	xmm1,xmm0,imm	\
								__asm x	xmm2,xmm1,imm	\
								__asm x	xmm3,xmm2,imm	\
								__asm x	xmm4,xmm3,imm	\
								__asm x	xmm5,xmm4,imm	\
								__asm x	xmm6,xmm5,imm	\
								__asm x	xmm7,xmm6,imm

#define	LAT_mXm( x )			__asm x	xmm0,aZero		\
								__asm x	aZero,xmm0		\
								__asm x	xmm1,aZero		\
								__asm x	aZero,xmm1		\
								__asm x	xmm2,aZero		\
								__asm x	aZero,xmm2		\
								__asm x	xmm3,aZero		\
								__asm x	aZero,xmm3

#define	THPT_XX( x )			__asm x	xmm0,xmm1		\
								__asm x	xmm2,xmm3		\
								__asm x	xmm4,xmm5		\
								__asm x	xmm6,xmm7		\
								__asm x	xmm0,xmm1		\
								__asm x	xmm2,xmm3		\
								__asm x	xmm4,xmm5		\
								__asm x	xmm6,xmm7

#define	THPT_XXi( x,imm )		__asm x	xmm0,xmm1,imm	\
								__asm x	xmm2,xmm3,imm	\
								__asm x	xmm4,xmm5,imm	\
								__asm x	xmm6,xmm7,imm	\
								__asm x	xmm0,xmm1,imm	\
								__asm x	xmm2,xmm3,imm	\
								__asm x	xmm4,xmm5,imm	\
								__asm x	xmm6,xmm7,imm

#define	THPT_Xm( x )			__asm x	xmm0,aZero		\
								__asm x	xmm1,aZero		\
								__asm x	xmm2,aZero		\
								__asm x	xmm3,aZero		\
								__asm x	xmm4,aZero		\
								__asm x	xmm5,aZero		\
								__asm x	xmm6,aZero		\
								__asm x	xmm7,aZero

#define	THPT_Xmi( x,imm )		__asm x	xmm0,aZero,imm	\
								__asm x	xmm1,aZero,imm	\
								__asm x	xmm2,aZero,imm	\
								__asm x	xmm3,aZero,imm	\
								__asm x	xmm4,aZero,imm	\
								__asm x	xmm5,aZero,imm	\
								__asm x	xmm6,aZero,imm	\
								__asm x	xmm7,aZero,imm

#define	THPT_mX( x )			__asm x	aStore,xmm0		\
								__asm x	aStore+16,xmm1	\
								__asm x	aStore+32,xmm2	\
								__asm x	aStore+48,xmm3	\
								__asm x	aStore+64,xmm4	\
								__asm x	aStore+80,xmm5	\
								__asm x	aStore+96,xmm6	\
								__asm x	aStore+112,xmm7

#define	THPT_XM( x )			__asm x	xmm0,mm0		\
								__asm x	xmm1,mm1		\
								__asm x	xmm2,mm2		\
								__asm x	xmm3,mm3		\
								__asm x	xmm4,mm4		\
								__asm x	xmm5,mm5		\
								__asm x	xmm6,mm6		\
								__asm x	xmm7,mm7

#define	THPT_MX( x )			__asm x	mm0,xmm0		\
								__asm x	mm1,xmm1		\
								__asm x	mm2,xmm2		\
								__asm x	mm3,xmm3		\
								__asm x	mm4,xmm4		\
								__asm x	mm5,xmm5		\
								__asm x	mm6,xmm6		\
								__asm x	mm7,xmm7

#define	THPT_XR( x )			__asm x	xmm0,eax		\
								__asm x	xmm1,eax		\
								__asm x	xmm2,eax		\
								__asm x	xmm3,eax		\
								__asm x	xmm4,eax		\
								__asm x	xmm5,eax		\
								__asm x	xmm6,eax		\
								__asm x	xmm7,eax

#define	THPT_RX( x )			__asm x	eax,xmm0		\
								__asm x	eax,xmm1		\
								__asm x	eax,xmm2		\
								__asm x	eax,xmm3		\
								__asm x	eax,xmm4		\
								__asm x	eax,xmm5		\
								__asm x	eax,xmm6		\
								__asm x	eax,xmm7

#define	THPT_XRi( x,imm )		__asm x	xmm0,eax,imm	\
								__asm x	xmm1,eax,imm	\
								__asm x	xmm2,eax,imm	\
								__asm x	xmm3,eax,imm	\
								__asm x	xmm4,eax,imm	\
								__asm x	xmm5,eax,imm	\
								__asm x	xmm6,eax,imm	\
								__asm x	xmm7,eax,imm

#define	THPT_RXi( x,imm )		__asm x	eax,xmm0,imm	\
								__asm x	eax,xmm1,imm	\
								__asm x	eax,xmm2,imm	\
								__asm x	eax,xmm3,imm	\
								__asm x	eax,xmm4,imm	\
								__asm x	eax,xmm5,imm	\
								__asm x	eax,xmm6,imm	\
								__asm x	eax,xmm7,imm

//
// MMX Macros
//
#define	LAT_MM( x )				__asm x	mm0,mm7			\
								__asm x	mm1,mm0			\
								__asm x	mm2,mm1			\
								__asm x	mm3,mm2			\
								__asm x	mm4,mm3			\
								__asm x	mm5,mm4			\
								__asm x	mm6,mm5			\
								__asm x	mm7,mm6

#define	LAT_MMi( x,imm )		__asm x	mm0,mm7,imm		\
								__asm x	mm1,mm0,imm		\
								__asm x	mm2,mm1,imm		\
								__asm x	mm3,mm2,imm		\
								__asm x	mm4,mm3,imm		\
								__asm x	mm5,mm4,imm		\
								__asm x	mm6,mm5,imm		\
								__asm x	mm7,mm6,imm

#define	LAT_mMm( x )			__asm x	mm0,aZero		\
								__asm x	aZero,mm0		\
								__asm x	mm1,aZero		\
								__asm x	aZero,mm1		\
								__asm x	mm2,aZero		\
								__asm x	aZero,mm2		\
								__asm x	mm3,aZero		\
								__asm x	aZero,mm3

#define	THPT_MM( x )			__asm x	mm0,mm1			\
								__asm x	mm2,mm3			\
								__asm x	mm4,mm5			\
								__asm x	mm6,mm7			\
								__asm x	mm0,mm1			\
								__asm x	mm2,mm3			\
								__asm x	mm4,mm5			\
								__asm x	mm6,mm7

#define	THPT_MMi( x,imm )		__asm x	mm0,mm1,imm		\
								__asm x	mm2,mm3,imm		\
								__asm x	mm4,mm5,imm		\
								__asm x	mm6,mm7,imm		\
								__asm x	mm0,mm1,imm		\
								__asm x	mm2,mm3,imm		\
								__asm x	mm4,mm5,imm		\
								__asm x	mm6,mm7,imm

#define	THPT_Mm( x )			__asm x	mm0,aZero		\
								__asm x	mm1,aZero		\
								__asm x	mm2,aZero		\
								__asm x	mm3,aZero		\
								__asm x	mm4,aZero		\
								__asm x	mm5,aZero		\
								__asm x	mm6,aZero		\
								__asm x	mm7,aZero

#define	THPT_Mmi( x,imm )		__asm x	mm0,aZero,imm	\
								__asm x	mm1,aZero,imm	\
								__asm x	mm2,aZero,imm	\
								__asm x	mm3,aZero,imm	\
								__asm x	mm4,aZero,imm	\
								__asm x	mm5,aZero,imm	\
								__asm x	mm6,aZero,imm	\
								__asm x	mm7,aZero,imm

#define	THPT_mM( x )			__asm x	aStore,mm0		\
								__asm x	aStore+8,mm1	\
								__asm x	aStore+16,mm2	\
								__asm x	aStore+24,mm3	\
								__asm x	aStore+32,mm4	\
								__asm x	aStore+40,mm5	\
								__asm x	aStore+48,mm6	\
								__asm x	aStore+56,mm7

#define	THPT_MR( x )			__asm x	mm0,eax			\
								__asm x	mm1,eax			\
								__asm x	mm2,eax			\
								__asm x	mm3,eax			\
								__asm x	mm4,eax			\
								__asm x	mm5,eax			\
								__asm x	mm6,eax			\
								__asm x	mm7,eax

#define	THPT_RM( x )			__asm x	eax,mm0			\
								__asm x	eax,mm1			\
								__asm x	eax,mm2			\
								__asm x	eax,mm3			\
								__asm x	eax,mm4			\
								__asm x	eax,mm5			\
								__asm x	eax,mm6			\
								__asm x	eax,mm7

#define	THPT_MRi( x,imm )		__asm x	mm0,eax,imm		\
								__asm x	mm1,eax,imm		\
								__asm x	mm2,eax,imm		\
								__asm x	mm3,eax,imm		\
								__asm x	mm4,eax,imm		\
								__asm x	mm5,eax,imm		\
								__asm x	mm6,eax,imm		\
								__asm x	mm7,eax,imm

#define	THPT_RMi( x,imm )		__asm x	eax,mm0,imm		\
								__asm x	eax,mm1,imm		\
								__asm x	eax,mm2,imm		\
								__asm x	eax,mm3,imm		\
								__asm x	eax,mm4,imm		\
								__asm x	eax,mm5,imm		\
								__asm x	eax,mm6,imm		\
								__asm x	eax,mm7,imm


#define ReadTSC( x )			__asm xor eax, eax          \
                                __asm cpuid					\
								__asm rdtsc					\
								__asm mov dword ptr x,eax	\
								__asm mov dword ptr x+4,edx \
                                __asm xor eax, eax          \
                                __asm cpuid


#define LATTHPT_CLEAR_XMM_I128	__asm pxor xmm0,xmm0	\
								__asm pxor xmm1,xmm1	\
								__asm pxor xmm2,xmm2	\
								__asm pxor xmm3,xmm3	\
								__asm pxor xmm4,xmm4	\
								__asm pxor xmm5,xmm5	\
								__asm pxor xmm6,xmm6	\
								__asm pxor xmm7,xmm7

#define LATTHPT_CLEAR_XMM_I64	__asm pxor mm0,mm0		\
								__asm pxor mm1,mm1		\
								__asm pxor mm2,mm2		\
								__asm pxor mm3,mm3		\
								__asm pxor mm4,mm4		\
								__asm pxor mm5,mm5		\
								__asm pxor mm6,mm6		\
								__asm pxor mm7,mm7

#define LATTHPT_CLEAR_XMM_SPFP	__asm movaps xmm0,aOnesPS \
								__asm movaps xmm1,xmm0	\
								__asm movaps xmm2,xmm0	\
								__asm movaps xmm3,xmm0	\
								__asm movaps xmm4,xmm0	\
								__asm movaps xmm5,xmm0	\
								__asm movaps xmm6,xmm0	\
								__asm movaps xmm7,xmm0

#define LATTHPT_CLEAR_XMM_DPFP	__asm movapd xmm0,aOnesPD \
								__asm movapd xmm1,xmm0	\
								__asm movapd xmm2,xmm0	\
								__asm movapd xmm3,xmm0	\
								__asm movapd xmm4,xmm0	\
								__asm movapd xmm5,xmm0	\
								__asm movapd xmm6,xmm0	\
								__asm movapd xmm7,xmm0


#define LATTHPT_LOOPCOUNT		8000
#define LATTHPT_DIVISOR			1600000.0f

#define LATTHPT_MACROx25( x )	x x x x x x x x x x x x x x x x x x x x x x x x x


//
// General purpose macros.
//

#define LatThpt_Init()			int iLatThpt;														\
								__int64 LatThptStartTime, LatThptEndTime, timeOverhead;  			\
								__declspec( align( 16 ) ) static int aZero[] = { 0, 0, 0, 0 };		\
								__declspec( align( 16 ) ) static float aOnesPS[] = { 1, 1, 1, 1 };	\
								__declspec( align( 16 ) ) static double aOnesPD[] = { 1, 1 };		\
								__declspec( align( 16 ) ) static int aStore[ 32 ];                  \
                                {ReadTSC(LatThptStartTime)}                                        \
                                {ReadTSC(LatThptEndTime)}                                           \
                                timeOverhead = getRdtscOverhead(); 

#define LatThpt_Free()			__asm emms

//#define LatThpt_PrepInt64()		{ LATTHPT_CLEAR_XMM_I64 }
#define LatThpt_PrepInt128()	{ LATTHPT_CLEAR_XMM_I128 }
#define LatThpt_PrepSPFP()		{ LATTHPT_CLEAR_XMM_SPFP }
#define LatThpt_PrepDPFP()		{ LATTHPT_CLEAR_XMM_DPFP }

#define	LatThpt_GetClocks()		((float)(LatThptEndTime-LatThptStartTime - timeOverhead) / LATTHPT_DIVISOR)
inline __int64 getRdtscOverhead()
{
    int i;
    __int64 startTime, endTime, tmpOverhead;
    ReadTSC( startTime) ;
    ReadTSC( endTime) ;
    tmpOverhead = endTime - startTime;
    for(i =0;i<1000;i++){
        ReadTSC( startTime) ;
        ReadTSC( endTime) ;
        if(tmpOverhead > (endTime - startTime)){
            tmpOverhead=  endTime - startTime;
        }
    }
    return tmpOverhead;
}


//
// XMM Latency macros.
//

#define testLatc_Xmm( x )																	\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( LAT_XX( x ) )									\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testLatc_XmmImm( x )																\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( LAT_XXi( x, 0xE4 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testLatc_XmmMem( x )																\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( LAT_mXm( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }


//
// XMM Throughput macros.
//

#define testThpt_Xmm( x )																	\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_XX( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_XmmImm( x )																\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_XXi( x, 0xE4 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_XmmMemLoad( x )															\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_Xm( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_XmmImmMemLoad( x )														\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_Xmi( x, 0xE4 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_XmmMemStore( x )															\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_mX( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_Mmx2Xmm( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_XM( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_Xmm2Mxx( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_MX( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_Reg2Xmm( x )																\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_XR( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_Xmm2Reg( x )																\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_RX( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_Reg2XmmImm( x )															\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_XRi( x, 0 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }

#define testThpt_Xmm2RegImm( x )															\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_RXi( x, 0 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }


//
// MMX Latency macros.
//

#define testLatc_Mmx( x )																	\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( LAT_MM( x ) )									\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testLatc_MmxImm( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( LAT_MMi( x, 0xE4 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testLatc_MmxMem( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( LAT_mMm( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms


//
// MMX Throughput macros.
//

#define testThpt_Mmx( x )																	\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_MM( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_MmxImm( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_MMi( x, 0xE4 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_MmxMemLoad( x )															\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_Mm( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_MmxImmMemLoad( x )														\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_Mmi( x, 0xE4 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_MmxMemStore( x )															\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_mM( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_Reg2Mmx( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_MR( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_Mmx2Reg( x )																\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_RM( x ) )								\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_Reg2MmxImm( x )															\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_MRi( x, 0 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define testThpt_Mmx2RegImm( x )															\
								{ LATTHPT_CLEAR_XMM_I64 }											\
								{ ReadTSC( LatThptStartTime ) }										\
								for ( iLatThpt=0; iLatThpt < LATTHPT_LOOPCOUNT; iLatThpt++ )		\
								{																	\
									LATTHPT_MACROx25( THPT_RMi( x, 0 ) )							\
								}																	\
								{ ReadTSC( LatThptEndTime ) }										\
								__asm emms

#define printf10(x)   printf("%-10.1f", x)                              
#define printfname(x) printf("%-10s", x)                                
#define test(p,x) {p(x); printf("<"); printfname(Str(x)); printf10(LatThpt_GetClocks()); printf(">");}
