
//******************************************************************************
// DEFINES
//******************************************************************************

//
// XMM Macros
//
/*********************************************************
 *E 	:  32-bit GRP 
 *R   	:  64-bit GRP
 *m 	:  memory
 *M 	:  MMX 
 *X 	:  XMM
 *i 	:  immediate
 *F 	:  float 
 *D 	:  double
 *Y	:  YMM
 * ******************************************************/
/*********************************************************
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
//! pay attention: asm a, b is  b->a;
 * ******************************************************/
#include "macro_asm.h"
#include "lat_rdtsc.h"
#define LOOP8(x) x x x x x x x x

#define __THPT_E2EDA(__decl__E2EDA, x) \
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			
#define THPT_E2EDA(x)     __THPT_E2EDA(masm__E2EDA, x)								
#define asmTHPT_E2EDA(x)  __THPT_E2EDA(__mcode__E2EDA, x)								

#define __THPT_m2EDA(__decl__m2EDA, x) \
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			\
								__decl__m2EDA(x, aPtr) 			
#define THPT_m2EDA(x)     __THPT_m2EDA(masm__m2EDA, x)								
#define asmTHPT_m2EDA(x)  __THPT_m2EDA(__mcode__m2EDA, x)								


#define	THPT_m2E( x )			masm__m2E(x,	eax , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	eax , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	eax , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	eax , aZero)		\
								masm__m2E(x,	edx , aZero)		

#define	__THPT_E2E( __decl__E2E, x)	\
                                __decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		\
								__decl__E2E(x,	eax , eax)		
#define THPT_E2E( x)    __THPT_E2E( masm__E2E, x)
#define asmTHPT_E2E( x) __THPT_E2E( __mcode__E2E, x)

#define	THPT_m2R( x )			masm__m2R(x,	rax , aZero)		\
								masm__m2R(x,	rdx , aZero)		\
								masm__m2R(x,	rax , aZero)		\
								masm__m2R(x,	rdx , aZero)		\
								masm__m2R(x,	rax , aZero)		\
								masm__m2R(x,	rdx , aZero)		\
								masm__m2R(x,	rax , aZero)		\
								masm__m2R(x,	rdx , aZero)		

#define	THPT_E2m( x )			masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		\
								masm__E2m(x, aZero,	eax )		

#define	THPT_R2m( x )			masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		\
								masm__R2m(x, aZero,	rax )		

#define THPT_m2F(x)             masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \
                                masm__m2F(x, aOnesPS)            \

#define THPT_F2m(x)             masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            \
                                masm__F2m(x, aOnesPS)            

#define THPT_m2D(x)             masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \
                                masm__m2D(x, aOnesPD)            \

#define THPT_D2m(x)             masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            \
                                masm__D2m(x, aOnesPD)            

#define THPT_F2F(x)             masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            \
                                masm__F2F(x, 1, 0)            

#define THPT_D2D(x)             masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            \
                                masm__D2D(x, 1, 0)            

#define THPT_F2E(x)             masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            \
                                masm__F2E(x, eax)            



//----------------------Added by Ayushi------------------------------------------

#define __LAT_E2EDA(__decl__E2EDA, x) \
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 			\
								__decl__E2EDA(x, eax) 	


#define LAT_E2EDA(x)     __LAT_E2EDA(masm__E2EDA, x)								

#define LAT_R2m( x )			 masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )		\
							masm__R2m(x, aZero,	rax )	
	
#define LAT_m2R( x ) 			 masm__m2R(x,    rax , aZero)            \
							masm__m2R(x,    rax , aZero)            \
							masm__m2R(x,    rax , aZero)            \
							masm__m2R(x,    rax , aZero)            \
							masm__m2R(x,    rax , aZero)            \
							masm__m2R(x,    rax , aZero)            \	
							masm__m2R(x,    rax , aZero)            \
							masm__m2R(x,    rax , aZero)            
#define LAT_mRm( x ) 			 masm__m2R(x,    rax , aZero)            \
							masm__R2m(x,    aZero, 	rax)            \
							masm__m2R(x,    rax , aZero)            \
							masm__R2m(x,    aZero, 	rax)            \
							masm__m2R(x,    rax , aZero)            \
							masm__R2m(x,    aZero, 	rax)            \
							masm__m2R(x,    rax , aZero)            \	
							masm__R2m(x,    aZero, 	rax)            \

#define	LAT_E2m( x )			masm__E2m(x, aZero,	eax )		\
							masm__E2m(x, aZero,     eax )           \
							masm__E2m(x, aZero,     eax )           \
							masm__E2m(x, aZero,     eax )           \
							masm__E2m(x, aZero,     eax )           \
							masm__E2m(x, aZero,     eax )           \
							masm__E2m(x, aZero,     eax )           \
							masm__E2m(x, aZero,     eax )           

#define LAT_m2E( x )			masm__m2E(x,	eax , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	edx , aZero)		\
								masm__m2E(x,	edx , aZero)		

#define LAT_m2F(x)             masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            \
								masm__m2F(x, aOnesPS)            

#define LAT_F2m(x)             masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            \
					masm__F2m(x, aOnesPS)            

//---//Added by Ayushi-----------------------------------------------------------------------------------------------------------------------
#define	LAT_Y2m( x )			masm__Y2m(x,	aMem,ymm0)		\
								masm__Y2m(x, aMem+32	,ymm1)		\
								masm__Y2m(x, aMem+64	,ymm2)		\
								masm__Y2m(x, aMem+96	,ymm3)		\
								masm__Y2m(x, aMem+128	,ymm4)		\
								masm__Y2m(x, aMem+160	,ymm5)		\
								masm__Y2m(x, aMem+192	,ymm6)		\
								masm__Y2m(x, aMem+224	,ymm7)

#define	LAT_m2Y( x )			masm__m2Y(x,ymm0, aZero)		\
								masm__m2Y(x, ymm1, aZero)		\
								masm__m2Y(x, ymm2, aZero)		\
								masm__m2Y(x, ymm3, aZero)		\
								masm__m2Y(x, ymm4, aZero)		\
								masm__m2Y(x, ymm5, aZero)		\
								masm__m2Y(x, ymm6, aZero)		\
								masm__m2Y(x, ymm7, aZero)

#define	LAT_X2X( x )			masm__X2X(x,	xmm0,xmm7)		\
								masm__X2X(x,	xmm1,xmm0)		\
								masm__X2X(x,	xmm2,xmm1)		\
								masm__X2X(x,	xmm3,xmm2)		\
								masm__X2X(x,	xmm4,xmm3)		\
								masm__X2X(x,	xmm5,xmm4)		\
								masm__X2X(x,	xmm6,xmm5)		\
								masm__X2X(x,	xmm7,xmm6)

#define	LAT_Xi2X( x,imm )		masm__Xi2X(x,	xmm0,xmm7,imm)	\
								masm__Xi2X(x,	xmm1,xmm0,imm)	\
								masm__Xi2X(x,	xmm2,xmm1,imm)	\
								masm__Xi2X(x,	xmm3,xmm2,imm)	\
								masm__Xi2X(x,	xmm4,xmm3,imm)	\
								masm__Xi2X(x,	xmm5,xmm4,imm)	\
								masm__Xi2X(x,	xmm6,xmm5,imm)	\
								masm__Xi2X(x,	xmm7,xmm6,imm)

#define	LAT_mXm( x )			masm__m2X(x,	xmm0,aZero)		\
								masm__X2m(x,	aZero,xmm0)		\
								masm__m2X(x,	xmm1,aZero)		\
								masm__X2m(x,	aZero,xmm1)		\
								masm__m2X(x,	xmm2,aZero)		\
								masm__X2m(x,	aZero,xmm2)		\
								masm__m2X(x,	xmm3,aZero)		\
								masm__X2m(x,	aZero,xmm3)
//Added by Ayushi
#define	LAT_mYm( x )			masm__m2Y(x,	ymm0,aZero)		\
								masm__Y2m(x,	aZero,ymm0)		\
								masm__m2Y(x,	ymm1,aZero)		\
								masm__Y2m(x,	aZero,ymm1)		\
								masm__m2Y(x,	ymm2,aZero)		\
								masm__Y2m(x,	aZero,ymm2)		\
								masm__m2Y(x,	ymm3,aZero)		\
								masm__Y2m(x,	aZero,ymm3)

#define	LAT_mMm( x )			masm__m2M(x,	mm0,aZero)		\
								masm__M2m(x,	aZero,mm0)		\
								masm__m2M(x,	mm1,aZero)		\
								masm__M2m(x,	aZero,mm1)		\
								masm__m2M(x,	mm2,aZero)		\
								masm__M2m(x,	aZero,mm2)		\
								masm__m2M(x,	mm3,aZero)		\
								masm__M2m(x,	aZero,mm3)

#define	THPT_X2X( x )			masm__X2X(x,	xmm0,xmm1)		\
								masm__X2X(x,	xmm2,xmm3)		\
								masm__X2X(x,	xmm4,xmm5)		\
								masm__X2X(x,	xmm6,xmm7)		\
								masm__X2X(x,	xmm0,xmm1)		\
								masm__X2X(x,	xmm2,xmm3)		\
								masm__X2X(x,	xmm4,xmm5)		\
								masm__X2X(x,	xmm6,xmm7)

#define	THPT_Xi2X( x,imm )		masm__Xi2X(x,	xmm0,xmm1,imm)	\
								masm__Xi2X(x,	xmm2,xmm3,imm)	\
								masm__Xi2X(x,	xmm4,xmm5,imm)	\
								masm__Xi2X(x,	xmm6,xmm7,imm)	\
								masm__Xi2X(x,	xmm0,xmm1,imm)	\
								masm__Xi2X(x,	xmm2,xmm3,imm)	\
								masm__Xi2X(x,	xmm4,xmm5,imm)	\
								masm__Xi2X(x,	xmm6,xmm7,imm)

#define	THPT_m2X( x )			masm__m2X(x,	xmm0,aZero)		\
								masm__m2X(x,	xmm1,aZero)		\
								masm__m2X(x,	xmm2,aZero)		\
								masm__m2X(x,	xmm3,aZero)		\
								masm__m2X(x,	xmm4,aZero)		\
								masm__m2X(x,	xmm5,aZero)		\
								masm__m2X(x,	xmm6,aZero)		\
								masm__m2X(x,	xmm7,aZero)

//Ayushi Latency for m2X
#define	LAT_m2X( x )			masm__m2X(x,	xmm0,aZero)		\
								masm__m2X(x,	xmm1,aZero)		\
								masm__m2X(x,	xmm2,aZero)		\
								masm__m2X(x,	xmm3,aZero)		\
								masm__m2X(x,	xmm4,aZero)		\
								masm__m2X(x,	xmm5,aZero)		\
								masm__m2X(x,	xmm6,aZero)		\
								masm__m2X(x,	xmm7,aZero)

#define	THPT_mi2X( x,imm )		masm__mi2X(x,	xmm0,aZero,imm)	\
								masm__mi2X(x,	xmm1,aZero,imm)	\
								masm__mi2X(x,	xmm2,aZero,imm)	\
								masm__mi2X(x,	xmm3,aZero,imm)	\
								masm__mi2X(x,	xmm4,aZero,imm)	\
								masm__mi2X(x,	xmm5,aZero,imm)	\
								masm__mi2X(x,	xmm6,aZero,imm)	\
								masm__mi2X(x,	xmm7,aZero,imm)

#define	THPT_X2m( x )			masm__X2m(x,	aMem,xmm0		)\
								masm__X2m(x,	aMem+16,xmm1	)\
								masm__X2m(x,	aMem+32,xmm2	)\
								masm__X2m(x,	aMem+48,xmm3	)\
								masm__X2m(x,	aMem+64,xmm4	)\
								masm__X2m(x,	aMem+80,xmm5	)\
								masm__X2m(x,	aMem+96,xmm6	)\
								masm__X2m(x,	aMem+112,xmm7 )

//Ayushi Latency for X2m
#define	LAT_X2m( x )			masm__X2m(x,	aMem,xmm0		)\
								masm__X2m(x,	aMem+16,xmm1	)\
								masm__X2m(x,	aMem+32,xmm2	)\
								masm__X2m(x,	aMem+48,xmm3	)\
								masm__X2m(x,	aMem+64,xmm4	)\
								masm__X2m(x,	aMem+80,xmm5	)\
								masm__X2m(x,	aMem+96,xmm6	)\
								masm__X2m(x,	aMem+112,xmm7 )

#define	THPT_M2X( x )			masm__X2X(x,	xmm0,mm0)		\
								masm__X2X(x,	xmm1,mm1)		\
								masm__X2X(x,	xmm2,mm2)		\
								masm__X2X(x,	xmm3,mm3)		\
								masm__X2X(x,	xmm4,mm4)		\
								masm__X2X(x,	xmm5,mm5)		\
								masm__X2X(x,	xmm6,mm6)		\
								masm__X2X(x,	xmm7,mm7)

#define	THPT_X2M( x )			masm__X2X(x,	mm0,xmm0)		\
								masm__X2X(x,	mm1,xmm1)		\
								masm__X2X(x,	mm2,xmm2)		\
								masm__X2X(x,	mm3,xmm3)		\
								masm__X2X(x,	mm4,xmm4)		\
								masm__X2X(x,	mm5,xmm5)		\
								masm__X2X(x,	mm6,xmm6)		\
								masm__X2X(x,	mm7,xmm7)

#define	THPT_R2X( x )			masm__X2X(x,	xmm0,eax)		\
								masm__X2X(x,	xmm1,eax)		\
								masm__X2X(x,	xmm2,eax)		\
								masm__X2X(x,	xmm3,eax)		\
								masm__X2X(x,	xmm4,eax)		\
								masm__X2X(x,	xmm5,eax)		\
								masm__X2X(x,	xmm6,eax)		\
								masm__X2X(x,	xmm7,eax)

#define	THPT_X2R( x )			masm__X2X(x,	eax,xmm0)		\
								masm__X2X(x,	eax,xmm1)		\
								masm__X2X(x,	eax,xmm2)		\
								masm__X2X(x,	eax,xmm3)		\
								masm__X2X(x,	eax,xmm4)		\
								masm__X2X(x,	eax,xmm5)		\
								masm__X2X(x,	eax,xmm6)		\
								masm__X2X(x,	eax,xmm7)

#define	THPT_R2Xi( x,imm )		masm__Xi2X(x,	xmm0,eax,imm)	\
								masm__Xi2X(x,	xmm1,eax,imm)	\
								masm__Xi2X(x,	xmm2,eax,imm)	\
								masm__Xi2X(x,	xmm3,eax,imm)	\
								masm__Xi2X(x,	xmm4,eax,imm)	\
								masm__Xi2X(x,	xmm5,eax,imm)	\
								masm__Xi2X(x,	xmm6,eax,imm)	\
								masm__Xi2X(x,	xmm7,eax,imm)

#define	THPT_X2Ri( x,imm )		masm__Xi2X(x,	eax,xmm0,imm)	\
								masm__Xi2X(x,	eax,xmm1,imm)	\
								masm__Xi2X(x,	eax,xmm2,imm)	\
								masm__Xi2X(x,	eax,xmm3,imm)	\
								masm__Xi2X(x,	eax,xmm4,imm)	\
								masm__Xi2X(x,	eax,xmm5,imm)	\
								masm__Xi2X(x,	eax,xmm6,imm)	\
								masm__Xi2X(x,	eax,xmm7,imm)

//
// MMX Macros
//
#define	LAT_M2M( x )				masm__X2X(x,	mm0,mm7	)		\
								masm__X2X(x,	mm1,mm0	)		\
								masm__X2X(x,	mm2,mm1	)		\
								masm__X2X(x,	mm3,mm2	)		\
								masm__X2X(x,	mm4,mm3	)		\
								masm__X2X(x,	mm5,mm4	)		\
								masm__X2X(x,	mm6,mm5	)		\
								masm__X2X(x,	mm7,mm6 )

#define	LAT_M2Mi( x,imm )		masm__Xi2X(x,	mm0,mm7,imm	)	\
								masm__Xi2X(x,	mm1,mm0,imm	)	\
								masm__Xi2X(x,	mm2,mm1,imm	)	\
								masm__Xi2X(x,	mm3,mm2,imm	)	\
								masm__Xi2X(x,	mm4,mm3,imm	)	\
								masm__Xi2X(x,	mm5,mm4,imm	)	\
								masm__Xi2X(x,	mm6,mm5,imm	)	\
								masm__Xi2X(x,	mm7,mm6,imm )

#define	LAT_mMm( x )			masm__m2X(x,	mm0,aZero	)	\
								masm__X2m(x,	aZero,mm0	)	\
								masm__m2X(x,	mm1,aZero	)	\
								masm__X2m(x,	aZero,mm1	)	\
								masm__m2X(x,	mm2,aZero	)	\
								masm__X2m(x,	aZero,mm2	)	\
								masm__m2X(x,	mm3,aZero	)	\
								masm__X2m(x,	aZero,mm3   )

#define	THPT_M2M( x )			masm__X2X(x,	mm0,mm1		)	\
								masm__X2X(x,	mm2,mm3		)	\
								masm__X2X(x,	mm4,mm5		)	\
								masm__X2X(x,	mm6,mm7		)	\
								masm__X2X(x,	mm0,mm1		)	\
								masm__X2X(x,	mm2,mm3		)	\
								masm__X2X(x,	mm4,mm5		)	\
								masm__X2X(x,	mm6,mm7     )

#define	THPT_M2Mi( x,imm )		masm__Xi2X(x,	mm0,mm1,imm		)\
								masm__Xi2X(x,	mm2,mm3,imm		)\
								masm__Xi2X(x,	mm4,mm5,imm		)\
								masm__Xi2X(x,	mm6,mm7,imm		)\
								masm__Xi2X(x,	mm0,mm1,imm		)\
								masm__Xi2X(x,	mm2,mm3,imm		)\
								masm__Xi2X(x,	mm4,mm5,imm		)\
								masm__Xi2X(x,	mm6,mm7,imm     )

#define	THPT_m2M( x )			masm__m2X(x,	mm0,aZero		)\
								masm__m2X(x,	mm1,aZero		)\
								masm__m2X(x,	mm2,aZero		)\
								masm__m2X(x,	mm3,aZero		)\
								masm__m2X(x,	mm4,aZero		)\
								masm__m2X(x,	mm5,aZero		)\
								masm__m2X(x,	mm6,aZero		)\
								masm__m2X(x,	mm7,aZero       )
//ADded by AYushi
#define	LAT_m2M( x )			masm__m2X(x,	mm0,aZero		)\
								masm__m2X(x,	mm1,aZero		)\
								masm__m2X(x,	mm2,aZero		)\
								masm__m2X(x,	mm3,aZero		)\
								masm__m2X(x,	mm4,aZero		)\
								masm__m2X(x,	mm5,aZero		)\
								masm__m2X(x,	mm6,aZero		)\
								masm__m2X(x,	mm7,aZero       )

#define	THPT_mi2M( x,imm )		masm__mi2M(x,	mm0,aZero,imm	)\
								masm__mi2M(x,	mm1,aZero,imm	)\
								masm__mi2M(x,	mm2,aZero,imm	)\
								masm__mi2M(x,	mm3,aZero,imm	)\
								masm__mi2M(x,	mm4,aZero,imm	)\
								masm__mi2M(x,	mm5,aZero,imm	)\
								masm__mi2M(x,	mm6,aZero,imm	)\
								masm__mi2M(x,	mm7,aZero,imm   )

#define	THPT_M2m( x )			masm__X2m(x,	aMem,mm0		)\
								masm__X2m(x,	aMem+8,mm1	)\
								masm__X2m(x,	aMem+16,mm2	)\
								masm__X2m(x,	aMem+24,mm3	)\
								masm__X2m(x,	aMem+32,mm4	)\
								masm__X2m(x,	aMem+40,mm5	)\
								masm__X2m(x,	aMem+48,mm6	)\
								masm__X2m(x,	aMem+56,mm7   )

//Added by Ayushi for Latency of M2m
#define	LAT_M2m( x )			masm__X2m(x,	aMem,mm0		)\
								masm__X2m(x,	aMem+8,mm1	)\
								masm__X2m(x,	aMem+16,mm2	)\
								masm__X2m(x,	aMem+24,mm3	)\
								masm__X2m(x,	aMem+32,mm4	)\
								masm__X2m(x,	aMem+40,mm5	)\
								masm__X2m(x,	aMem+48,mm6	)\
								masm__X2m(x,	aMem+56,mm7   )
	

#define	THPT_R2M( x )			masm__X2X(x,	mm0,eax)			\
								masm__X2X(x,	mm1,eax)			\
								masm__X2X(x,	mm2,eax)			\
								masm__X2X(x,	mm3,eax)			\
								masm__X2X(x,	mm4,eax)			\
								masm__X2X(x,	mm5,eax)			\
								masm__X2X(x,	mm6,eax)			\
								masm__X2X(x,	mm7,eax)

#define	THPT_M2R( x )			masm__X2X(x,	eax,mm0)			\
								masm__X2X(x,	eax,mm1)			\
								masm__X2X(x,	eax,mm2)			\
								masm__X2X(x,	eax,mm3)			\
								masm__X2X(x,	eax,mm4)			\
								masm__X2X(x,	eax,mm5)			\
								masm__X2X(x,	eax,mm6)			\
								masm__X2X(x,	eax,mm7)

#define	THPT_R2Mi( x,imm )		masm__Xi2X(x,	mm0,eax,imm)		\
								masm__Xi2X(x,	mm1,eax,imm)		\
								masm__Xi2X(x,	mm2,eax,imm)		\
								masm__Xi2X(x,	mm3,eax,imm)		\
								masm__Xi2X(x,	mm4,eax,imm)		\
								masm__Xi2X(x,	mm5,eax,imm)		\
								masm__Xi2X(x,	mm6,eax,imm)		\
								masm__Xi2X(x,	mm7,eax,imm)

#define	THPT_M2Ri( x,imm )		masm__Xi2X(x,	eax,mm0,imm)		\
								masm__Xi2X(x,	eax,mm1,imm)		\
								masm__Xi2X(x,	eax,mm2,imm)		\
								masm__Xi2X(x,	eax,mm3,imm)		\
								masm__Xi2X(x,	eax,mm4,imm)		\
								masm__Xi2X(x,	eax,mm5,imm)		\
								masm__Xi2X(x,	eax,mm6,imm)		\
								masm__Xi2X(x,	eax,mm7,imm)



#define LATTHPT_CLEAR_XMM_I128	masm__X2X( pxor, xmm0,xmm0)	\
								masm__X2X( pxor, xmm1,xmm1)	\
								masm__X2X( pxor, xmm2,xmm2)	\
								masm__X2X( pxor, xmm3,xmm3)	\
								masm__X2X( pxor, xmm4,xmm4)	\
								masm__X2X( pxor, xmm5,xmm5)	\
								masm__X2X( pxor, xmm6,xmm6)	\
								masm__X2X( pxor, xmm7,xmm7)


#define LATTHPT_CLEAR_XMM_I64	masm__X2X( pxor ,mm0,mm0	)	\
								masm__X2X( pxor ,mm1,mm1	)	\
								masm__X2X( pxor ,mm2,mm2	)	\
								masm__X2X( pxor ,mm3,mm3	)	\
								masm__X2X( pxor ,mm4,mm4	)	\
								masm__X2X( pxor ,mm5,mm5	)	\
								masm__X2X( pxor ,mm6,mm6	)	\
								masm__X2X( pxor ,mm7,mm7  )

#define LATTHPT_CLEAR_XMM_SPFP	masm__m2X( movaps, xmm0,aOnesPS )\
								masm__X2X( movaps, xmm1,xmm0)	\
								masm__X2X( movaps, xmm2,xmm0)	\
								masm__X2X( movaps, xmm3,xmm0)	\
								masm__X2X( movaps, xmm4,xmm0)	\
								masm__X2X( movaps, xmm5,xmm0)	\
								masm__X2X( movaps, xmm6,xmm0)	\
								masm__X2X( movaps, xmm7,xmm0)
                                                      
#define LATTHPT_CLEAR_XMM_DPFP	masm__m2X( movapd ,xmm0,aOnesPD) \
								masm__X2X( movapd ,xmm1,xmm0)	\
								masm__X2X( movapd ,xmm2,xmm0)	\
								masm__X2X( movapd ,xmm3,xmm0)	\
								masm__X2X( movapd ,xmm4,xmm0)	\
								masm__X2X( movapd ,xmm5,xmm0)	\
								masm__X2X( movapd ,xmm6,xmm0)	\
								masm__X2X( movapd ,xmm7,xmm0)
                                                      

#define LATTHPT_LOOPCOUNT		8000
#define LATTHPT_DIVISOR			1600000.0f

#define LATTHPT_MACROx25( x )	x x x x x x x x x x x x x x x x x x x x x x x x x


//
// General purpose macros.
//
#define LatThpt_Init()			int iLatThpt;					\
double LatThptUesedTimeD; \
__ALIGN__	 static int aZero[] = { 0, 0, 0, 0 };		\
__ALIGN__	 static float aOnesPS[] = { 1, 1, 1, 1 };	\
__ALIGN__	 static double aOnesPD[] = { 1, 1 };		\
__ALIGN__	 static int aMem[1024 ];                  	\
void *aPtr = aMem; 										\
LatThptTimeOverhead = getRdtscOverhead();


#define LatThpt_Free()			masm__(emms)

#define LatThpt_PrepInt64()		{ LATTHPT_CLEAR_XMM_I64 }
#define LatThpt_PrepInt128()	{ LATTHPT_CLEAR_XMM_I128 }
#define LatThpt_PrepSPFP()		{ LATTHPT_CLEAR_XMM_SPFP }
#define LatThpt_PrepDPFP()		{ LATTHPT_CLEAR_XMM_DPFP }
#define TestKernel( testCase, ...)                                  \
for ( iLatThpt=LATTHPT_LOOPCOUNT; iLatThpt > 0 ; iLatThpt-- )		\
{																	\
	LATTHPT_MACROx25( testCase( __VA_ARGS__ ) )						\
}																	

#define TestFrame( testCase, ...) \
{ ReadTSC( LatThptStartTime ) }										\
TestKernel(testCase, __VA_ARGS__)                                   \
{ ReadTSC( LatThptEndTime ) }

#define TestThpt( InstrType, ...) \
TestFrame(THPT_##InstrType , __VA_ARGS__)                                   \

#define TestLatc( InstrType, ...) \
TestFrame(LAT_##InstrType , __VA_ARGS__)                                   \


#define TestThptF( InstrType, ...) \
{masm__(emms)}\
{masm__m2F(fld, aOnesPS)}             \
{masm__m2F(fld, aOnesPS)}             \
TestThpt( InstrType,__VA_ARGS__) \
{masm__m2F(fstp, aOnesPS)}             \
{masm__m2F(fstp, aOnesPS)}             \
{masm__(emms)}

#define TestLatcF( InstrType, ...) \
{masm__(emms)}\
{masm__m2F(fld, aOnesPS)}             \
{masm__m2F(fld, aOnesPS)}             \
TestLatc( InstrType,__VA_ARGS__) \
{masm__m2F(fstp, aOnesPS)}             \
{masm__m2F(fstp, aOnesPS)}             \
{masm__(emms)}



#include "latthpt_asm.h"
//
#define printl10(x)   printf("%-10.1f", x)								
#define printf5(x)   printf("%5.1f", x)								
#define printf10(x)   printf("%10.1f", x)								
#define printName(x) printf("%-10s", x)								
#define printStr(x) printf("%s", x)								

/***********************************************************
 *ptest     : test and print in format <(T/L) E2E 2.1>
 *pstest    : test and print time
 *ptest...n : test and print in format <(T/L) E2E 2.1> enter
 *ptest...Fn: test float
 *ptest...Gn: test general purpose instruction
 * *********************************************************/
#define ptest(testType, t, x,...) \
{testType(t,x,##__VA_ARGS__); printf("<(T)"); printf("%-5s",Str(t)); printf(":");printName(Str(x));  printf5(LatThpt_GetClocks()); printf(">");}
#define ptestThpt(t,x, ...) ptest( TestThpt, t, x, ##__VA_ARGS__) 
#define ptestLatc(t,x, ...) ptest( TestLatc, t, x, ##__VA_ARGS__)
#define ptestThptn(t,x, ...) {ptestThpt(t, x, ##__VA_ARGS__) printf("\n");}
#define ptestLatcn(t,x, ...) {ptestLatc(t, x, ##__VA_ARGS__) printf("\n");}
#define ptestThptFn(t,x, ...) {ptest( TestThptF, t, x, ##__VA_ARGS__) printf("\n");}
#define ptestLatcFn(t,x, ...) {ptest( TestLatcF, t, x, ##__VA_ARGS__) printf("\n");}
#define ptestThptGn(t,x, ...) {ptest( asmTestThpt,t, x, ##__VA_ARGS__) printf("\n");}

#define pstest(testType, t, x, ...) \
{testType(t,x, ##__VA_ARGS__); printf10(LatThpt_GetClocks()); }
#define pstestThpt(t,x, ...) pstest( TestThpt, t, x, ##__VA_ARGS__) 
#define pstestLatc(t,x, ...) pstest( TestLatc, t, x, ##__VA_ARGS__)
