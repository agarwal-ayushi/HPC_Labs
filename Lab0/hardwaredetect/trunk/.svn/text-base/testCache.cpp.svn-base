#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "macro_asm.h"
#include "lat_rdtsc.h"
#define Type unsigned int 
#define MAX_MEM (1024 * 1024 *32)
#define __STR(x) #x
//Type data[1024 * 1024 *32];
//Type  datab[1024 * 64*1024];
int verbose = 1;
#define ODETAIL 1
Type *data;
Type *datab;
unsigned long long *usedT= (unsigned long long *)data;
unsigned long long *startT = ((unsigned long long *)data)+1;
unsigned long long *endT= ((unsigned long long *)data)+2;

/*****************************
 *
 *
 * ***************************/
int L1Size;
int L2Size;
int L3Size;
int TLB1Size;
int TLB2Size;

double L1Thr;
double L2Thr;
double memLatency;

int L1Line;
double L1panel;

unsigned long long rdtcOverhead;
unsigned long long rdtcLowBOverhead;
#define LOOPS 100
#define LOOPSBIG 100
#define LOOPSS 10
#define LOOPSK 1000
#define loops for(int loopj =0;loopj < LOOPS;loopj++)
#define loopsBig for(int loopj =0;loopj < LOOPSBIG;loopj++)
#define loopss for(int loopj =0;loopj < LOOPSS;loopj++)
#define loopsk for(int loopj =0;loopj < LOOPSK;loopj++)
#define forall(a) for(i=0;i<a;i++)
#define foralld(a) for(i=a-1;i>=0;i--)

//#define Str(x) #x
#define ___asmE2E(x , s, d) Str(x) "l %%" Str(s) ",%%" Str(d) ";"

//#define ReadTSC32(x) \
__asm__ __volatile__("xorl %%eax, %%eax; cpuid;" "rdtsc" : "=a" (x.low), "=d" (x.high)::"%ebx","%ecx")
//#define ReadTSC64(x) \
__asm__ __volatile__("xorl %%eax, %%eax; cpuid; rdtsc; shlq $32, %%rdx; orq %%rdx, %%rax; movq %%rax, (%%rdi); xorl %%eax, %%eax; cpuid;" \
::"D"(&(x.low)):"%eax","%ebx","%ecx","%edx");


#ifdef X64
#define __asmStartRdtsc() \
	__gcode_e2e(xor, eax, eax) \
	__asmx(cpuid) \
	__asmx(rdtsc) \
	__gcode_i2g(sal, 32, gdx)\
	__gcode_g2g(or, gdx, gax)\
	__gcode_g(push, gax)

#define __asmStartRdtscB()\
	__gcode_g(push, gbx)\
	__gcode_e2e(xor, eax, eax) \
	__asmx(cpuid) \
	__asmx(rdtsc) \
	__gcode_i2g(sal, 32, gdx)\
	__gcode_g2g(or, gdx, gax)\
	__gcode_g(pop, gbx)\
	__gcode_g(push, gax)

#define __asmEndRdtsc() 		\
	__asmx(rdtsc) \
	__gcode_i2g(sal, 32, gdx)\
	__gcode_g2g(or, gdx, gax)\
	__gcode_g(pop, gdx)\
	__gcode_g2g(sub, gdx, gax)

#define storeClock( m) __gcode_r2m(mov, rax, gsi)

#define ReadTSC ReadTSC64 
#else 
#define __asmStartRdtsc() \
	__gcode_e2e(xor, eax, eax) \
	__asmx(cpuid) \
	__asmx(rdtsc) \
	__gcode_g(push, gax)\
	__gcode_g(push, gdx)

#define __asmStartRdtscB()\
	__gcode_g(push, gbx)\
	__gcode_e2e(xor, eax, eax) \
	__asmx(cpuid) \
	__asmx(rdtsc) \
	__gcode_g(pop, gbx)\
	__gcode_g(push, gax)\
	__gcode_g(push, gdx)

#define __asmEndRdtsc() 		\
	__asmx(rdtsc) \
	__gcode_g(pop, gbx)\
	__gcode_g(pop, gcx)\
	__gcode_g2g(sub, gcx, gax)\
	__gcode_g2g(sbb, gbx, gdx)

#define storeClock( m) __gcode_e2m(mov, eax, m)\
StoreL2(4, m, edx)

#define ReadTSC ReadTSC32 
#endif

#define __asmStartRdtscLow() \
	__gcode_e2e(xor, eax, eax) \
	__asmx(cpuid) \
	__asmx(rdtsc) \
	__gcode_e(push, eax)\

#define __asmEndRdtscLow() 		\
	__asmx(rdtsc) \
	__gcode_e(pop, edx)\
	__gcode_e2e(sub, edx, eax)\
	__gcode_e2e(xor, edx, edx)


#define __asmStartRdtscLowB() \
	__gcode_e2e(xor, eax, eax) \
	/*__asmx(cpuid)*/ \
	__asmx(rdtsc) \
	__gcode_e2e(mov, eax,ebx)\

#define __asmEndRdtscLowB() 		\
	__asmx(rdtsc) \
	__gcode_e2e(sub, ebx, eax)\
	__gcode_e2e(xor, edx, edx)

typedef struct {
	int size;
	double time;
}record_t;

_U64 time_start, time_end;
#define getclocks( start, end) (end.u64 - start.u64)

#define start_tsc() ReadTSC(time_start) 
#define end_tsc()   ReadTSC(time_end)
#define get_tsc() getclocks(time_start, time_end)
#define get_start_tsc() time_start.u64 
#define get_end_tsc()   time_end.u64
#define get_start_int() time_start.low
#define get_end_int()   time_end.low

void resetRdtcOverhead();

_U64 read_tsc()
{
	_U64 clockticks ;
	ReadTSC(clockticks);
	return clockticks;
}

void testRdtcOverhead(unsigned long long& t)
{
	int i2[2];
	__asm__ __volatile__ (
			__asmStartRdtsc() 
			__asmEndRdtsc()
			storeClock(gsi)
			://"=a"(t)
			:"S"(i2)
			:"%ebx","%edx","%ecx","%eax"
			);

	t = *(unsigned long long *) i2;
}

void testRdtcLowBOverhead(unsigned long long& t)
{
	int i2[2];
	__asm__ __volatile__ (
			__asmStartRdtscLowB() 
			__asmEndRdtscLowB()
			storeClock(gsi)
			://"=a"(t)
				:"S"(data),"D"(0)
				  :"%ebx","%edx","%ecx","%eax"
					 );

	t = *(unsigned long long *) data;
}

/*************************************************
 *
 * *********************************************/
void copyMem(int* mem, int* dst, int N, unsigned long long& t)
{
#if 1
	__asm__(
			__asmStartRdtscB()
			__gcode_g2g(xor, gcx, gcx)
			"1: "
			LoadL4 ( 0, gsi, gcx, 4, eax)
			StoreL4( 0, gdi, gcx, 4, eax)
			LoadL4 ( 4, gsi, gcx, 4, eax)
			StoreL4( 4, gdi, gcx, 4, eax)
			LoadL4 ( 8, gsi, gcx, 4, eax)
			StoreL4( 8, gdi, gcx, 4, eax)
			LoadL4 (12, gsi, gcx, 4, eax)
			StoreL4(12, gdi, gcx, 4, eax)
			LoadL4 (16, gsi, gcx, 4, eax)
			StoreL4(16, gdi, gcx, 4, eax)
			LoadL4 (20, gsi, gcx, 4, eax)
			StoreL4(20, gdi, gcx, 4, eax)
			LoadL4 (24, gsi, gcx, 4, eax)
			StoreL4(24, gdi, gcx, 4, eax)
			LoadL4 (28, gsi, gcx, 4, eax)
			StoreL4(28, gdi, gcx, 4, eax)
			__gcode_i2g(add, 8, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne 1b;"
			__asmEndRdtsc()
			storeClock(gsi)
			://"=a"(t)
			:"S"(mem),"D"(dst),"b"(N)
			:"%ecx","%edx", "%eax"
		   );
	t = *(unsigned long long *) mem;
#endif
}


/*************************************************
 *
 * *********************************************/
void readMem(int* mem, int N, unsigned long long& t)
{
#if 1
	__asm__(
			__asmStartRdtscB()
			__gcode_g2g(xor, gcx, gcx)
			"1: "
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			LoadL4(16, gsi, gcx, 4, eax)
			LoadL4(20, gsi, gcx, 4, eax)
			LoadL4(24, gsi, gcx, 4, eax)
			LoadL4(28, gsi, gcx, 4, eax)
			__gcode_i2g(add, 8, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne 1b;"
			__asmEndRdtsc()
			storeClock(gsi)
			://"=a"(t)
			:"S"(mem),"b"(N)
			:"%ecx","%edx", "%eax"
		   );
	t = *(unsigned long long *) mem;
#endif
}



//unsigned int time_high,time_low;
/*
   void __asmreadi(int i)
   {
   int time_elaps;
   int *ref = data + i;
   ____asm("	movl %1,%%esi; rdtsc;	movl %%eax ,%%ecx;	movl (%%esi),%%ebx;	rdtsc;	sub %%ecx,%%eax;	movl %%eax,%0;	"
   :"=r"(time_elaps)
   :"m"(ref)
   :"%edx","%eax","%ecx","%edx","%esi");
   printf("%4d Execution Time = %d\n",i, time_elaps);
   }
   */
void readi(Type * data,int i)
{
	unsigned long long  start,finish;
	int a;
	static unsigned int sum = 0;
	sum = rand();
	start_tsc();
	start = sum + get_start_tsc() ;
	a = data[i + (start *2)&1];
	end_tsc();
	finish = get_end_tsc() + a;
	printf("%4d Execution Time = %lld\n",i, finish-start + sum - a);
	sum += a;
}
void reads(int start,int end,int pos)
{
	int i;
	int sum = 0;
	int index,value;
	int startT,endT;
	for(i =start;i<=end;i++){
		index = i;
		sum += data[i];
		if(i==end){
			start_tsc();
			startT = get_start_int()  + sum;
			pos +=(((startT +8 )*2) &1);
			value = data[pos];
			end_tsc();
			endT = get_end_int() +value;
		}
	}
	printf("%4d Execution Time = %d\n",pos, (endT-value) - (startT - sum));
}
void testL2Size()
{
	int i;
	int iteration =1;
	int BN = 1024 * 8 ;
	int N;
	unsigned long long  t= 0;
	for(iteration =2; iteration < 128; iteration ++){
		t = 0;
		N = iteration * BN;
		{
			forall(	N){
				data[i] =0;
			}
			start_tsc();
			forall((1024*8)){
				data[i] =data[i] + 1;
			}
			end_tsc();
			t += get_tsc();
		}

		//printf("[%dk %lld]\n",N*4/1024,t/1024/8);
		if(verbose >= ODETAIL)
			printf("[%4dk %f]\n",N*4/1024,(double)t/(double)8192);
	}
}
void testTLBSize()
{
	int i;
	int iteration =1;
	int BN = 1024 ;
	int N;
	unsigned long long  t= 0;
	for(iteration =9; iteration < 64; iteration ++){
		N = iteration * BN;
		t = 0;
		loops{
			forall(	N){
				data[i] =0;
			}
			start_tsc();
			forall(1024){
				data[i]++ ; 
			}
			end_tsc();
			t += get_tsc(); 
		}
		t /=LOOPS;
		//printf("[%d %lld]\n",iteration,t/1024);
		if(verbose >= ODETAIL)
			printf("[%4d %f]\n",iteration,(double)t/(double)1024);
	}
}

void testL1CacheSizeC()
{
	int i;
	int iteration =1;
	int N = 1024;
	int n = 1024;
	unsigned long long  t= 0;
	for(iteration =1; iteration < 8; iteration ++){
		t = 0;
		loops{
			forall(	N){
				data[i] =0;
			}
			start_tsc();
			forall(n){
				data[i++]++ ;
				data[i++]++ ;
				data[i++]++ ;
				data[i]++ ;
			}
			end_tsc();
			t += get_tsc(); 
		}
		t /=LOOPS;
		//printf("[%dk %lld]\n",N*sizeof(Type)/1024,t/N);
		printf("[%4dk %f]\n",N*sizeof(Type)/1024,((double)t)/n);
		N = N *2;
	}
}
/***********************************************************
 *L1 
 * *******************************************************/
void testL1CacheSizeKernel(int N, unsigned long long& t)
{
#if 1
	__asm__(
			__gcode_g2g(xor, gcx, gcx)
			"1: "
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			__gcode_i2g(add, 4, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne 1b;"

			__asmStartRdtsc()

			__gcode_g2g(xor, gcx, gcx)
			__gcode_i2g(mov, 4096, gbx)
			"1: "
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			LoadL4(16, gsi, gcx, 4, eax)
			LoadL4(20, gsi, gcx, 4, eax)
			LoadL4(24, gsi, gcx, 4, eax)
			LoadL4(28, gsi, gcx, 4, eax)
			__gcode_i2g(add, 8, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne 1b;"

			__asmEndRdtsc()
			storeClock(gsi)
			://"=a"(t)
				:"S"(data),"b"(N)
				  :"%rdi","%rcx","%rdx","%eax"
					);
	t = *(unsigned long long *) data;
#endif
}

void testL1CacheSize()
{
	int i;
	int iteration =1;
	int N = 1024 ;
	unsigned long long  t= 0;
	int n=4096;
	record_t res[100];
	int testnum=0;

	for(iteration =0; N < 1024 * 256; iteration ++){
		t = 0;
		loopsk{
			unsigned long long curt;
			testL1CacheSizeKernel(N, curt);
			t += curt; 
		}
		t /=LOOPSK;
		res[iteration ].size = N * sizeof(Type);
		res[iteration ].time = ((double)t)/n;
		N = N *2;
		if(N> MAX_MEM) break;
	}

	N = 1024;
	resetRdtcOverhead();

	for(iteration =0; N < 1024 * 128; iteration ++){
		t = 0;
		loops{
			unsigned long long curt;
			testL1CacheSizeKernel(N, curt);
			t += curt; 
		}
		t /=LOOPS;
		res[iteration ].size = N * sizeof(Type);
		res[iteration ].time = ((double)t)/n;

		printf("[%4dk %5.1f]\n",N*sizeof(Type)/1024,((double)t)/n);
		N = N *2;
		if(N> MAX_MEM) break;
	}

	double biggest = 0.0;
	for(i =0;i< iteration -1; i++){
		double diff = res[i+1].time - res[i]. time;
		if(diff > biggest) {
			biggest = diff;
			L1Size = res[i].size;
			L1Thr  = res[i].time;
		}
	}
	printf("L1 Size is:%d=%dk Bytes\n", (int) L1Size, L1Size/1024);
	printf("L1 throughput is:%f circle/(per int)\n", L1Thr);
}

/*******************************
 *L1 cache Line
 * ****************************/
void testL1CacheLineKernel(int stride,unsigned long long& t)
{
	__asm__ __volatile__ (
			//"wbinvd;"	
			CLFLUSH2(   0, gsi)
			CLFLUSH2( 256, gsi)
			CLFLUSH2( 512, gsi)
			CLFLUSH2( 768, gsi)
			CLFLUSH2(1024, gsi)
			CLFLUSH2(1280, gsi)
			CLFLUSH2(1536, gsi)
			CLFLUSH2(1792, gsi)
			CLFLUSH3(   0, gsi, gdi)
			CLFLUSH3( 256, gsi, gdi)
			CLFLUSH3( 512, gsi, gdi)
			CLFLUSH3( 768, gsi, gdi)
			CLFLUSH3(1024, gsi, gdi)
			CLFLUSH3(1280, gsi, gdi)
			CLFLUSH3(1536, gsi, gdi)
			CLFLUSH3(1792, gsi, gdi)
			CLFLUSH3(2048, gsi, gdi)
			CLFLUSH3(2304, gsi, gdi)
			CLFLUSH3(2560, gsi, gdi)
			CLFLUSH3(2816, gsi, gdi)
			CLFLUSH3(3072, gsi, gdi)
			CLFLUSH3(3328, gsi, gdi)
			CLFLUSH3(3584, gsi, gdi)
			CLFLUSH3(3840, gsi, gdi)
			__gcode_g2g(xor, gax, gax)
			__asmx(cpuid)
			__gcode_g2g(xor, gcx, gcx)
			LoadL3(   0, gsi, gcx, eax)
			LoadL3( 256, gsi, gcx, eax)
			LoadL3( 512, gsi, gcx, eax)
			LoadL3( 768, gsi, gcx, eax)
			//LoadL3(1024, gsi, gcx, eax)
			//LoadL3(1280, gsi, gcx, eax)
			//LoadL3(1536, gsi, gcx, eax)
			//LoadL3(1792, gsi, gcx, eax)


			__gcode_g2g(mov,gdi, gcx)
			__asmStartRdtscLowB()

			LoadL3(   0, gsi, gcx, eax)
			LoadL3( 256, gsi, gcx, eax)
			LoadL3( 512, gsi, gcx, eax)
			LoadL3( 768, gsi, gcx, eax)
			//LoadL3(1024, gsi, gcx, eax)
			//LoadL3(1280, gsi, gcx, eax)
			//LoadL3(1536, gsi, gcx, eax)
			//LoadL3(1792, gsi, gcx, eax)
			__asmEndRdtscLowB()
			storeClock(gsi)
			//"movq %%rax, (%%rsi);"
			://"=a"(t)
				:"S"(data),"D"(stride)
				  :"%ebx","%ecx","%eax","%edx"
					 );
	t = *(unsigned long long *) data;
}
double middle(double f1, double f2, double f3)
{
	double minf, maxf;
	minf = f1<f2?f1:f2;
	minf = minf<f3?minf:f3;
	maxf = f1<f2?f2:f1;
	maxf = maxf<f3?f3:maxf;
	if((f1 !=minf) &&(f1 !=maxf)) return f1;	
	if((f2 !=minf) &&(f1 !=maxf)) return f2;	
	if((f2 !=minf) &&(f1 !=maxf)) return f3;	
}
void testL1CacheLine()
{
	int i;
	int stride;
	double t;
	record_t res[100];
	int iteration = 32;
	const int n = 4;
	unsigned long long hitOverhead = 0;
	resetRdtcOverhead();

	{
		stride = 0;
		hitOverhead = 0;
		loopsBig{
			unsigned long long curt;
			testL1CacheLineKernel(stride, curt);
			hitOverhead  += curt; 
		}
		hitOverhead  /=LOOPSBIG;
	}

	if(verbose >= ODETAIL)
		printf("L1 hit overhead:%f\n", (double) (hitOverhead - rdtcLowBOverhead)/n);
retestcacheline:	
	for(i=0; i< iteration ; i++){
		stride = i * 4;
		t = 0;
		loopsBig{
			unsigned long long curt;
			testL1CacheLineKernel(stride, curt);
			t += curt; 
		}
		t /=LOOPSBIG;
		t -= hitOverhead ;
		res[i].size = stride ;
		res[i].time = ((double)t)/n;

	}

	double biggest = 0.0;
	{
		i = 0;
		if((res[i+1].time - res[i]. time ) / res[i]. time  > 2) 
			goto retestcacheline;
	}
	for(i=1;i< iteration -1; i++){
		//! if test passed
		double diff1 = (res[i].time - res[i-1]. time);
		double diff2 = (res[i+1].time - res[i]. time);
		double diff3 = (res[i+1].time - res[i-1].time);
		double diff4 = fabs (diff2 -diff2);
		double base = fabs(middle(res[i-1].time, res[i].time, res[i+1].time));

		if(base =0) base = 0.1;
		if((diff4 / base > 0.25) &&( diff4/ diff3 > 2) ){
			goto retestcacheline;
		}
	}

	biggest = 0.0;
	for(i =0;i< iteration -1 ; i++){
		double diff = res[i+1].time - res[i]. time;
		if(diff > biggest) {
			biggest = diff;
			L1Line = res[i+1].size;
			L1panel = res[i+1].time;
		}
	}
	for(i=0;i< iteration ; i++){
		if(verbose >= ODETAIL)
			printf("[%4d %5.1f]\n",res[i].size ,res[i].time );
	}
	printf("L1 cache Line is:%d Bytes\n", (int) L1Line );
	printf("L1 cache panelty is:%5.1f circle/(per int)\n", L1panel);
}

void testL2CacheSizeKernel(int N, int L1,unsigned long long& t)
{
#if 1
	__asm__(
			__gcode_g2g(xor, gcx, gcx)
			"1:"
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			__gcode_i2g(add, 4, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne 1b;"
			:
			:"S"(data),"b"(N)
			:"%edx", "%ecx","eax"
		   );

	__asm__(
			__asmStartRdtscB()

			__gcode_g2g(xor, gcx, gcx)
			"1: "
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			LoadL4(16, gsi, gcx, 4, eax)
			LoadL4(20, gsi, gcx, 4, eax)
			LoadL4(24, gsi, gcx, 4, eax)
			LoadL4(28, gsi, gcx, 4, eax)
			__gcode_i2g(add, 8, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne 1b;"

			__asmEndRdtsc()
			storeClock(gsi)
			://"=a"(t)
			:"S"(data),"b"(L1)
			  :"%edx","%ecx","%eax"
				 );
	t = *(unsigned long long *) data;
#endif
}


void testL2CacheSize()
{
	int i;
	int iteration =0;
	int N = 1024;
	unsigned long long  t= 0;
	int n= 8192;
	record_t res[100];
	int testnum=0;
	//for(iteration =0; iteration < 20; iteration ++){
	//	t = 0;
	//	loops{
	//		unsigned long long curt;
	//		testL2CacheSizeKernel(N, curt);
	//		t += curt; 
	//	}
	//	t /=LOOPS;
	//	res[iteration ].size = N * sizeof(Type);
	//	res[iteration ].time = ((double)t)/n;
	//	N = N *2;
	//	if(N> MAX_MEM) break;
	//}

	N = 16* 1024;
	for(iteration =0; N < 32 * 1024 * 1024 / 4; iteration ++){
		t = 0;
		loops{
			unsigned long long curt;
			testL2CacheSizeKernel(N, L1Size/4,curt);
			t += curt; 
		}
		t /=LOOPS;
		t -= rdtcOverhead;
		res[iteration ].size = N * sizeof(Type);
		res[iteration ].time = ((double)t)/(L1Size/4);

		if(verbose >= ODETAIL)
			printf("[%4dk %f]\n",N*sizeof(Type)/1024,((double)t)/(L1Size/4));
		N = N *2;
		if(N> MAX_MEM) break;
	}


	double biggest = 0.0;
	for(i =0;i< iteration -1; i++){
		double diff = res[i+1].time - res[i]. time;
		if(diff > biggest) {
			biggest = diff;
			L2Size = res[i].size;
			L2Thr  = res[i].time;
		}
	}
	printf("L2 Size is:%d=%dk Bytes\n", (int) L2Size, L2Size/1024);
	printf("L2 throughput is:%5.1f circle/(per int)\n", L2Thr);
}



void testCacheLine()
{
	int i;
	int step =1;
	int N = 8192;
	int N2 = N * 2;
	for(step =4; step < 1024; step *=2 ){
		forall(	(4*N)){
			data[i] =0;
		}
		forall(	N){
			data[i] =0;
		}
		for(i =N; i < N2; i+= step){
			data[i] = data[i] +1;
		}
		start_tsc();
		forall(N){
			data[i] =data[i] + 1;
		}
		end_tsc();
		unsigned long long  t = get_tsc();
		//printf("[%3d %lld]\n",step*sizeof(Type),t/N);
		if(verbose >= ODETAIL)
			printf("[%4d %5.1f]\n",step*sizeof(Type),(double)t/(double)N);
	}

}

void testCacheSet()
{
	int i;
	int way =2;
	int N = 8192;
	int N2 = N * 2;
	int Block = N /2;
	int Block2;
	int bid;
	for(way =1; way < 128; way *=2 ){
		Block = N/way;
		Block2 = Block/2;
		forall(	65536*2){
			data[i] =0;
		}
		forall(	(N)){
			data[i] =0;
		}
		i = N;
		/*
		   for(i = N;i<N+N/4;i++)
		   data[i] = 0;
		   for(i = 2*N;i<2*N+N/4;i++)
		   data[i] = 0;
		   for(i = 3*N;i<3*N+N/4;i++)
		   data[i] = 0;
		   for(i = 4*N;i<4*N+N/4;i++)
		   data[i] = 0;
		   */
		for(bid =1;bid <= 2*way; bid++)
		{
			for(i= bid*N  ; i < bid*N + Block2; i++){
				data[i] = data[i] +1;
			}
		}
		start_tsc();
		for(i =Block2;i<Block;i++){
			data[i] =data[i] + 1;
		}
		end_tsc();
		unsigned long long  t = get_tsc();
		printf("[%3d %lld]\n",way,t/Block2);
		//printf("[%3d %f]\n",way,(double)t/(double)Block2);
	}

}

/*************************************************
 *
 * *********************************************/
void testMemLatencyKernel(int N, unsigned long long& t)
{
#if 1
	//__asm__(
	//		"wbinvd;"
	//		:
	//		:
	//		:"%rax","rbx","rcx","rdx"
	//);
	__asm__(
			__gcode_g2g(xor, gcx, gcx)
			__gcode_i2g(mov, 4194304, gbx)
			//"movq $4194304,%%rbx;" // 1024*1024*4
			//"movq $65536 ,%%rbx;" // 1024*64
			"Mem_lat_startLoop1:"
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			__gcode_i2g(add, 4, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne Mem_lat_startLoop1;"
			:
			:"S"(data),"b"(N)
			:"%ecx","%eax"

		   );
	__asm__(
			__asmStartRdtscB()
			__gcode_g2g(xor, gcx, gcx)
			"Mem_lat_startLoop2: "
			LoadL4( 0, gsi, gcx, 4, eax)
			LoadL4( 4, gsi, gcx, 4, eax)
			LoadL4( 8, gsi, gcx, 4, eax)
			LoadL4(12, gsi, gcx, 4, eax)
			LoadL4(16, gsi, gcx, 4, eax)
			LoadL4(20, gsi, gcx, 4, eax)
			LoadL4(24, gsi, gcx, 4, eax)
			LoadL4(28, gsi, gcx, 4, eax)
			__gcode_i2g(add, 8, gcx)
			__gcode_g2g(cmp, gbx, gcx)
			"jne Mem_lat_startLoop2;"

			//__gcode_e2e(mov, eax, ecx)

			__asmEndRdtsc()
			//__gcode_r2m(mov, rax, rsi)
			storeClock(gsi)
			//"movl %%ecx, 32(%%rsi);"


			://"=a"(t)
			:"S"(data),"D"(datab),"b"(N)
			:"%ecx","%edx","%eax"
			);
	t = *(unsigned long long *) data;
#endif
}
/*************************************************
 *
 * *********************************************/


void testMemCopy()
{
	int i;
	int iteration =1;
	int N = 1024 ;
	unsigned long long  t= 0;
	int n=2048;
	record_t res[100];
	int testnum=0;

	N = 1024;

	for(iteration =0; N < 1024 * 1024 * 4; iteration ++){
		readMem((int*)data, N, t);
		t = 0;
		loopss{
			unsigned long long curt;
			//testMemLatencyKernel(N, curt);
			copyMem((int*)data,(int*)datab, N,curt);
			t += curt; 
		}
		t /=LOOPSS;
		t -= rdtcOverhead;
		res[iteration ].size = N * sizeof(Type);
		res[iteration ].time = ((double)t)/N;

		printf("[%4dk %f]\n",N*sizeof(Type)/1024,((double)t)/N);
		N = N *2;
		if(N> MAX_MEM) break;
	}
}




void testMemLatency()
{
	int i;
	int iteration =1;
	int N = 1024 ;
	unsigned long long  t= 0;
	int n=2048;
	record_t res[100];
	int testnum=0;

	N = 1024;

	for(iteration =0; N < 1024 * 1024 * 4; iteration ++){
		readMem((int*)data, N, t);
		t = 0;
		loopss{
			unsigned long long curt;
			//testMemLatencyKernel(N, curt);
			readMem((int*)data,N,curt);
			t += curt; 
		}
		t /=LOOPSS;
		t -= rdtcOverhead;
		res[iteration ].size = N * sizeof(Type);
		res[iteration ].time = ((double)t)/N;

		printf("[%4dk %f]\n",N*sizeof(Type)/1024,((double)t)/N);
		N = N *2;
		if(N> MAX_MEM) break;
	}
}


/*************************************************
 *
 * *********************************************/
void resetRdtcOverhead()
{
#if 1
	rdtcOverhead = 0;
	rdtcLowBOverhead = 0;
	loopsk{
		unsigned long long t1, t2;
		testRdtcOverhead(t1);
		testRdtcLowBOverhead(t2);
		rdtcOverhead += t1;
		rdtcLowBOverhead += t2;
	}
	rdtcOverhead /= LOOPSK; 
	rdtcLowBOverhead /= LOOPSK;
#else 
	testRdtcOverhead(rdtcOverhead);
	testRdtcLowBOverhead(rdtcLowBOverhead);
	loopsk{
		unsigned long long t1, t2;
		testRdtcOverhead(t1);
		testRdtcLowBOverhead(t2);
		rdtcOverhead= t1< rdtcOverhead   ? t1: rdtcOverhead;
		rdtcLowBOverhead =t2 <rdtcLowBOverhead? t2:rdtcLowBOverhead; 
	}	
#endif
	printf("rdtcOverhead:%d\n",rdtcOverhead);
	printf("rdtcLowBOverhead:%d\n",rdtcLowBOverhead);

}
void warmup()
{

}

void initData()
{
	Type *memData, *memDatab;
	memData = (Type*) malloc( sizeof(Type) * (MAX_MEM+128));
	memDatab = (Type*) malloc( sizeof(Type) *( MAX_MEM+128));
	data = (Type*) (((unsigned long long)memData) & ~127) ;
	datab = (Type*) (((unsigned long long)memDatab) & ~127);
	usedT= (unsigned long long *)data;
	startT = ((unsigned long long *)data)+1;
	endT= ((unsigned long long *)data)+2;
	//printf("data : %0x\n", data);
	//printf("datab: %0x\n", datab);
	resetRdtcOverhead();
	warmup();
	resetRdtcOverhead();
}

int main(int argc,char **argv)
{
	int i = 0;
	int pos  = 0;
	int pos2 = 0;
	if(argc>1){
		for(i=1; i<argc; i++){
			if(argv[i][0] != '-') continue;
			switch(argv[i][1]){
				case '-':{
						 }
						 break;
				case 'v':
						 if(argv[i][2] != 0) 
							 verbose = atoi(argv[i] +2);
						 else 
							 verbose = atoi(argv[i++]);
						 break;
				default:
						 break;
			}
		}
	}
	initData();	
	for(i =0;i<65536;i++) data[i] =0;
	printf("/***********************************/\n");
	printf("test L1 cache size:\n");
	testL1CacheSize();
	printf("/***********************************/\n");
	printf("test L1 cache line:\n");
	testL1CacheLine();

	printf("/***********************************/\n");
	printf("test mem latency:\n");
	testMemLatency();

	printf("/***********************************/\n");
	printf("test mem copy:\n");
	testMemCopy();


	printf("/***********************************/\n");
	printf("test L2 cache size:\n");
	testL2CacheSize();
	//printf("test cache line size:\n");
	//testCacheLine();
	//printf("test cache set size:\n");
	//testCacheSet();
	//printf("test TLB  size:\n");
	//testTLBSize();
	//	printf("test L2  size:\n");
	//	testL2Size();
	printf("freq:%f\n",FREQ);
	return 1;
	//	reads(0,pos,pos2);
	//for(i =4;i<pos;i+=1024)
	//	readi(data,i);
	//for(i =4;i<pos;i+=1024)
	//	readi(datab,i);
}
