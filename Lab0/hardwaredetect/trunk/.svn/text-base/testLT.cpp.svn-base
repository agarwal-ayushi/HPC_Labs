#include <stdio.h> 
#include <stdlib.h>
#include <xmmintrin.h>
#include "latthpt_gnu.h"
#include "testop.h"


int main( ) 
{ 

	float f; 
	LatThpt_Init(); 
	// 
	// Perform xmm integer latency tests. 
	// 
	LatThpt_PrepInt128(); 
	printf("\n");
	printf( "XMM i128 Latency:\n");
	printf( "----------------\n");
	printName( "MOVDQA");  
	printName( "MOVDQU");  
	printName( "PSHUFD");  
	printName( "PMULLW");  
	printName( "POR"); 
	printName( "PMADDWD"); 
	printName( "PUNPCKLQDQ"); 
	printf("\n"); 
	printf( "Reg<-Reg    \n" ); 
    pstestLatc(X2X, movdqa);
	pstestLatc(X2X,movdqu ); 
	pstestLatc(Xi2X,pshufd, 0xE4 ); 
	pstestLatc(X2X,pmullw ); 
	pstestLatc(X2X,por ); 
	pstestLatc(X2X,pmaddwd ); 
	pstestLatc(X2X,punpcklqdq ); 
	printf( "\nMem<-Reg<-Mem \n" ); 
    pstestLatc(mXm, movdqa);
	pstestLatc(mXm, movdqu ); 

	// 

	// Perform xmm integer throughput tests. 

	// 

	LatThpt_PrepInt128(); 
	printf("\n");
	printf( "XMM i128 Throughput:  \n" ); 
	printf( "--------------------  \n" );
	printf( "MOVDQA  MOVDQU  PSHUFD  PMULLW  POR PMADDWD PUNPCKLQDQ  \n" ); 
	printf( "Reg<-Reg    \n" ); 
	pstestThpt(X2X, movdqa ); 
	pstestThpt(X2X, movdqu ); 
	pstestThpt(Xi2X, pshufd ,0xE4); 
	pstestThpt(X2X, pmullw ); 
	pstestThpt(X2X, por ); 
	pstestThpt(X2X, pmaddwd ); 
	pstestThpt(X2X, punpcklqdq ); 
	printf("\n");
	printf( "Reg<-Mem \n" ); 
	pstestThpt(m2X, movdqa ); 
	pstestThpt(m2X, movdqu ); 
	pstestThpt(mi2X, pshufd, 0xE4 ); 
	pstestThpt(m2X, pmullw ); 
	pstestThpt(m2X, por ); 
	pstestThpt(m2X, pmaddwd ); 
	pstestThpt(m2X, punpcklqdq ); 
	printf( "\nMem<-Reg\n " ); 
	pstestThpt(X2m, movdqa ); 
	pstestThpt(X2m, movdqu ); 
	// 
	// Perform xmm SPFP latency tests. 
	// 
	LatThpt_PrepSPFP(); 
	printf("\n");
	printf( "XMM SPFP Latency:    \n" ); 
	printf( "-----------------  \n" ); 
	printf( "MOVAPS  MOVUPS  SHUFPS  MULPS   DIVPS   MOVHLPS MOVLHPS  \n" ); 
	printf( "Reg<-Reg    \n" ); 
	pstestLatc(X2X,movaps ); 
	pstestLatc(X2X,movups ); 
	pstestLatc(Xi2X,shufps,0xE4); 
	pstestLatc(X2X,mulps ); 
	pstestLatc(X2X,divps ); 
	pstestLatc(X2X,movhlps ); 
	pstestLatc(X2X,movlhps ); 
	printf("\n");
	printf( "Mem<-Reg<-Mem \n" ); 
	pstestLatc(mXm, movaps ); 
	pstestLatc(mXm, movups ); 
	
	// 
	// Perform xmm SPFP throughput tests. 
	// 
	LatThpt_PrepSPFP(); 

	printf("\n");
	printf( "XMM SPFP Throughput:  \n" ); 
	printf( "--------------------  \n" ); 
	printf( "MOVAPS  MOVUPS  SHUFPS  MULPS   DIVPS   MOVHLPS MOVLHPS  \n" ); 
	printf( "Reg<-Reg    \n" ); 
	pstestThpt(X2X, movaps ); 
	pstestThpt(X2X, movups ); 
	pstestThpt(Xi2X, shufps, 0xE4 ); 
	pstestThpt(X2X, mulps ); 
	pstestThpt(X2X, divps ); 
	pstestThpt(X2X, movhlps ); 
	pstestThpt(X2X, movlhps ); 
	printf("\n");
	printf( "reg<-Mem \n" ); 

	pstestThpt(m2X, movaps ); 
	pstestThpt(m2X, movups ); 
	pstestThpt(mi2X, shufps, 0xE4 ); 
	pstestThpt(m2X, mulps ); 
	pstestThpt(m2X, divps ); 

	printf("\n");
	printf( "Mem<-Reg \n" ); 

	pstestThpt(X2m, movaps ); 
	pstestThpt(X2m, movups ); 
	printf("\n");
	ptestThpt(X2m, movups);
	printf("\n");

	printf("general purpose register\n");
	//ptestThptn(m2E, mov);

#ifdef X64
	//ptestThptn(m2R, mov);
#endif
	ptestThptn(E2m, mov);
	//ptestThptn(m2E, mov);
	ptestThptn(m2E, add);
	ptestThptn(m2EDA, mul);
	ptestThptn(E2EDA, mul);
	ptestThptGn(E2E, mov);
    ptestThptFn(m2F, fadd);
    ptestThptFn(F2m, fst);
    ptestThptFn(m2D, fadd);
    ptestThptFn(D2m, fst);
    ptestThptFn(F2F, fadd);
    ptestThptFn(F2F, fmul);
    ptestThptFn(D2D, fadd);
    ptestThptFn(F2m, fist);
    printf("\n");

	LatThpt_Free(); 
	printf("freq:%f\n",FREQ);
	printf("\n");
#define testCSize 512 
	pctestFrameWork(testAdd3<unsigned int>, "+", testCSize);
	pctestFrameWork(testMul3<unsigned int>, "*", testCSize);
	//pctestFrameWork(testDiv3<unsigned int>, "/", testCSize);

	pctestFrameWork(testAdd3i3<unsigned int>, "+3", testCSize);
	pctestFrameWork(testMul3i3<unsigned int>, "*3", testCSize);

	pctestFrameWork(testAdd3<float>, "+", testCSize);
	pctestFrameWork(testMul3<float>, "*", testCSize);
	pctestFrameWork(testDiv3<float>, "/", testCSize);

	pctestFrameWork(testAdda2<unsigned int>, "+=", testCSize);
	pctestFrameWork(testMula2<unsigned int>, "*=", testCSize);
	pctestFrameWork(testDiva2<unsigned int>, "/=", testCSize);
	pctestFrameWork(testAssign2<unsigned int>, "=", testCSize);

	pctestFrameWork(testAdda2i2<unsigned int>, "+=2", testCSize);
	pctestFrameWork(testMula2i2<unsigned int>, "*=2", testCSize);

	pctestFrameWork(testAdd2i2<unsigned int>, "+2", testCSize);
	pctestFrameWork(testMul2i2<unsigned int>, "*2", testCSize);

	pctestFrameWork(asmI32testAdd2i2<unsigned int>, "+2", testCSize);
	pctestFrameWork(asmI32testAdd2i3<unsigned int>, "+3", testCSize);

	pctestFrameWork(testMul3<unsigned int>, "exit", testCSize);
	pctestFrameWork(testAdda2<unsigned int>, "exit", testCSize);
	return 0; 

}  
