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
	long int a[100000], loop = 0; 		//Static Array of less size so we need clflush
	double diff = 0.0;			//To record average
	register long int j=0, k=0, p = 1; 	//Register hints for compiler to avoid allocating memory to variables
	register unsigned long int hi;
	for (int i = 0; i < 100000; i++) {
		a[i] = i;			//Array Initialization
	}	
	for (int i = 0; i < 10; i++) {
		uint64_t start = rdtsc();	//Start timer
		for (loop = 0; loop < REPETITIONS; loop++) {		
			__asm__ __volatile ("rdtsc": "=a" (k), "=d" (hi)); 	//reads the TSC counter from hardware
			k = k & 0x0000FFFF;					//Brings the index into array range
			j = j + a[k] + 1;					//We have to add a[k] into j as memory loads dont happen into registers allocated directly by compiler. 
		       	REP(0, 1, 6, 0, j = hi + p + 1;) 			//We keep changing these values to note data points. This statement creates enough false dependency for register renaming
			_mm_clflush(&a[k]);					//cache line flush
		}
		uint64_t end = rdtsc();						//Take end timer
		diff = diff + double((end - start))/REPETITIONS;		//Average Time
	}
		
	printf("%0.10f\n", diff/10);
	return 0;
}
