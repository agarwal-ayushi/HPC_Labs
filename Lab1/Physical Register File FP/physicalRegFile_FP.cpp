#include <stdio.h>
#include <iostream>
#include <time.h>
#include <x86intrin.h> 
#include <algorithm>
#include <random>

using namespace std;

#ifndef REPETITIONS
    #define REPETITIONS 10000000
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
	double* a;
	long int a_count = REPETITIONS;			//Size of array equal to loop iterations
	long int loop = 0;
	a = (double*) malloc(a_count*sizeof(double));	//Double type array 

	register double p = 1.0, j=0.0;			//Register hint to compiler
	register long int k=0, hi;
	for (int i = 0; i < a_count ; i++) {
		a[i] = double(i);			//Initialize array with double type data
	}
	
	std::default_random_engine ran;
	ran.seed(0);
	std::shuffle(&a[0], &a[a_count], ran);		//Random shuffle of array
	

	double diff = 0.0;			//To record average
	for (int i = 0; i < 10; i++) {
		uint64_t start = rdtsc();
		for (loop = 0; loop < REPETITIONS; loop++) {		
			__asm__ __volatile ("rdtsc": "=a" (k), "=d" (hi));
			k = k & 0x007FFFFF;
			j = j + a[k] + 1;
		       	REP(0, 1, 9, 0, j = hi + p + 1.0;) //We keep changing these values to note data points
			_mm_clflush(&a[k]);
		}
		uint64_t end = rdtsc();
		diff = diff + double((end - start))/REPETITIONS;
	}
		
	printf("%0.10f\n", diff/10);
	
	return 0;
}
