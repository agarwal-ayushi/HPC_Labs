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
	long int a_count = REPETITIONS;		//Array Size equal to loop iterations
	long long int* a;			//Dynamic Array
	a = (long long int*) malloc(REPETITIONS*sizeof(long long int));	//Memory allocation
	register long int j=0, k=0, hi, loop; //Register hints to compiler
	for (int i = 0; i < a_count; i++) {
		a[i] = i;			//Array initialization
	}	
	std::default_random_engine ran;
	ran.seed(0);
	std::shuffle(&a[0], &a[a_count], ran);	//Random shuffling of array
	
	double diff = 0.0;
	for (int i = 0; i < 10; i++) {
		uint64_t start = rdtsc();	//timestamp read
		for (loop = 0; loop < REPETITIONS; loop++) {		
			__asm__ __volatile ("rdtsc": "=a" (k), "=d" (hi));
			k = k & 0x007FFFFF;	//To bring index within range
			j = j + a[k] + 1;	//read a[k] in register j -> only load, no store
		       	REP(0, 1, 0, 0, __asm__ __volatile__("nop");) //Add NOPS
		}
		uint64_t end = rdtsc();	//Read Timestamp
		diff = diff + double((end - start))/REPETITIONS; //Average
	}
	printf("%0.10f\n", diff/10);
	return 0;
}
