#ifndef __LAT_RDTCSC_HEADER__
#define __LAT_RDTCSC_HEADER__
#include "macro_asm.h"
#ifdef  INTEL_ASM
/***********************************************************************
 * intel ASM
 * *********************************************************************/
/*---------------masm-----------------------------------*/
#define ReadTSC( x )		    __asm xor eax, eax \
								__asm cpuid					\
								__asm rdtsc					\
								__asm mov dword ptr x,eax	\
								__asm mov dword ptr x + 4,edx

#else

/***********************************************************************
 * gnu ASM
 * *********************************************************************/
#ifdef X64
#define ReadTSC ReadTSC64
#else 
#define ReadTSC ReadTSC32
#endif 
/*-------------------------------------------------------------------------------------*/
//#define ReadTSC(x) __asm__ __volatile__("rdtsc" : "=a" (x.low), "=d" (x.high));

#define ReadTSC32(x) \
__asm__ __volatile__("xorl %%eax, %%eax; cpuid; rdtsc; movl %%eax, (%%edi); movl %%edx, 4(%%edi); xorl %%eax, %%eax; cpuid;" \
::"D"(&(x.low)):"%eax","%ebx","%ecx","%edx");
//#define ReadTSC32(x) \
//__asm__ __volatile__("xorl %%eax, %%eax; cpuid; rdtsc; pushl %%eax; pushl %%edx; xorl %%eax, %%eax; cpuid; popl %%edx; popl %%eax;" \
:"=a"(x.low),"=d"(x.high)::"%ebx","%ecx");

#define ReadTSC64(x) \
__asm__ __volatile__("xorl %%eax, %%eax; cpuid; rdtsc; shlq $32, %%rdx; orq %%rdx, %%rax; movq %%rax, (%%rdi); xorl %%eax, %%eax; cpuid;" \
::"D"(&(x.low)):"%eax","%ebx","%ecx","%edx");
//#define ReadTSC64(x) \
__asm__ __volatile__("xorl %%eax, %%eax; cpuid; rdtsc; shlq $32, %%rdx; orq %%rdx, %%rax; pushq %%rax; xorl %%eax, %%eax; cpuid; popq %%rax;" \
:"=a"(x.u64)::"%ebx","%ecx","%edx");
#endif

typedef union {
	unsigned long long u64;
	struct {
		unsigned low;
		unsigned high;
	};
} _U64;

inline _U64 getRdtscOverhead()
{
	int i;
	_U64 startTime, endTime, tmpOverhead;
	ReadTSC( startTime) ;
	ReadTSC( endTime) ;
	tmpOverhead.u64 = endTime.u64 - startTime.u64;
	for(i =0;i<1000;i++){
		ReadTSC( startTime) ;
		ReadTSC( endTime) ;
		if(tmpOverhead.u64 > (endTime.u64 - startTime.u64)){
			tmpOverhead.u64 =  endTime.u64 - startTime.u64;
		}
	}
	return tmpOverhead;
}

static _U64 LatThptStartTime, LatThptEndTime, LatThptTimeOverhead= getRdtscOverhead(), LatThptUesedTime ;	
#define startTSC() { ReadTSC( LatThptStartTime ) }
#define endTSC()   { ReadTSC( LatThptEndTime ) }
#define	getTSC()   ((double)(LatThptEndTime.u64-LatThptStartTime.u64 - LatThptTimeOverhead.u64) )
#define	LatThpt_GetClocks()		(((double)(LatThptEndTime.u64-LatThptStartTime.u64 - LatThptTimeOverhead.u64)) / LATTHPT_DIVISOR)
#define	LatThpt_GetUsed()		LatThptUesedTime.u64 =(LatThptEndTime.u64-LatThptStartTime.u64 - LatThptTimeOverhead.u64); \
LatThptUesedTimeD = 1.0* LatThptUesedTime.u64;
#endif
