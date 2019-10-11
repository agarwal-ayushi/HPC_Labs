#include <stdio.h>
#include <iostream>
#include <time.h>
#include <x86intrin.h> 
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

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

int main()
{
    	long int a_count = REPETITIONS;
	long long int* a;
	a = (long long int*) malloc(REPETITIONS*sizeof(long long int));
	register long int j=0, k = 0, hi, loop;
	for (k=0; k <a_count; k++) {
		a[k] = k;
	}
	std::default_random_engine ran;
	ran.seed(0);
	std::shuffle(&a[0], &a[a_count], ran); //Random Array shuffle
	
	double diff = 0.0;
	for (int i = 0; i < 10; i++) {
		uint64_t start = rdtsc(); //Start timer read
		for (loop = 0; loop < REPETITIONS; loop++) {	
			REP(0, 0, 0, 1, __asm__ __volatile__("rdtsc": "=a" (k), "=d" (hi)); k = k& 0x007FFFFF; j = j + a[k] + 1;)
			//Change above to put N memory loads
			REP(0, 1, 0, 0, __asm__ __volatile__("nop");) //Change this to add k nops, here k = 100
		}
		uint64_t end = rdtsc(); //End timer read
		diff = diff + double((end - start))/REPETITIONS;
	}
	printf("%0.10f\n", diff/10);
	return 0;
}
