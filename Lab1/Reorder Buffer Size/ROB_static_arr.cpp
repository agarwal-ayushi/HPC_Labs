#include <stdio.h>
#include <iostream>
#include <time.h>
#include <x86intrin.h> 

using namespace std;

#ifndef REPETITIONS
    #define REPETITIONS 100000000
#endif
// taken from https://stackoverflow.com/a/8556436/1107768
#define REP0(X)
#define REP1(X) X
#define REP2(X) REP1(X) X
#define REP3(X) REP2(X) X
#define REP4(X) REP3(X) X
#define REP5(X) REP4(X) X
#define REP6(X) REP5(X) X
#define REP7(X) REP6(X) X
#define REP8(X) REP7(X) X
#define REP9(X) REP8(X) X
#define REP10(X) REP9(X) X

#define REP(THOUSANDS,HUNDREDS,TENS,ONES,X) \
  REP##THOUSANDS(REP10(REP10(REP10(X)))) \
  REP##HUNDREDS(REP10(REP10(X))) \
  REP##TENS(REP10(X)) \
  REP##ONES(X)

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main()
{
	long int a[100000], loop = 0;
	register long int j=0, k=0;
	register unsigned long int hi;
	for (int i = 0; i < 100000; i++) {
		a[i] = i;
	}	
	uint64_t start = rdtsc();
	for (loop = 0; loop < REPETITIONS; loop++) {		
		__asm__ __volatile ("rdtsc": "=a" (k), "=d" (hi));
		k = k & 0x0000FFFF;
		j = j + a[k] + 1;
	       	REP(0, 2, 0, 8, __asm__ __volatile__("nop");)
		_mm_clflush(&a[k]);
	}
	uint64_t end = rdtsc();
	printf("%0.10f\n", double((end - start))/REPETITIONS);
	
	return 0;
}
