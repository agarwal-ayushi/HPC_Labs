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
	//Perform MMX integer Latency tests
	// Added by Ayushi
	LatThpt_PrepInt64(); //for initializing and setting mm registers to 0 
	printf("\n");
	printf( "MMX i64 Latency:\n");
	printf( "----------------\n");
	printName( "MOVQ");   
	printf("\n\n"); 
	printf( "Reg<-Reg (M <- M)  \t \t" ); 
	pstestLatc(M2M, movq); //Move Quadword to and from various mm registers
	printf( "\nMem<-Reg<-Mem (mem <- M <- mem) " ); //This is a better way to understand the latency of memory operations on MMX registers as creating dependency chains is possible 
	pstestLatc(mMm, movq); //Move from mem->MMX -> memory 
	printf("\n"); 
	printf( "Reg<- Mem  (M <- mem)  \t\t" ); 
	pstestLatc(m2M, movq); //Move Quadword to and from mm and memory
	printf("\n"); 
	printf( "Mem <- Reg (mem <- M)   \t" ); 
	pstestLatc(M2m, movq);
	printf("\n"); 
	//Added by Ayushi
	//Perform MMX integer throuhput Tests
	//
	LatThpt_PrepInt64();
	printf("\n");
	printf( "MMX i64 Throughput:\n");
	printf( "----------------\n");
	printName( "MOVQ2DQ");   //Move Quadword from mm to xmm
	printf("\n\n"); 
	printf( "Reg<-Reg (X <- M)   \t" ); 
	pstestThpt(M2X, movq2dq); 
	printf("\n\n"); 
	printName( "MOVQ");   //Move Quadword to and from memory into mm
	printf("\n\n"); 
	printf( "Reg<-Reg (M <- M)   \t" ); 
	pstestThpt(M2M, movq);
	printf("\n"); 
	printf( "Reg<- Mem (M <- mem)   \t" ); 
	pstestThpt(m2M, movq);
	printf("\n"); 
	printf( "Mem <- Reg (mem <- M)   " ); 
	pstestThpt(M2m, movq);
	printf("\n");

	//
	// Perform ymm integer latency tests
	//
	//Added by Ayushi	
	printf("\n");
	printf( "YMM i256 Latency:\n");
	printf( "----------------\n");
	printName( "VMOVDQA");  
	printf("\nMem <- Reg (mem <- Y) \t\t");
	pstestLatc(Y2m, vmovdqa); // Added by Ayushi
	printf("\n");
	printf( "Reg<- Mem (Y <- mem) \t\t" ); 
	pstestLatc(m2Y, vmovdqa); // Added by Ayushi
	printf("\n");
	printf( "Mem<-Reg<-Mem (mem <- Y <- mem)" ); 
	pstestLatc(mYm, vmovdqa);
	printf("\n"); 
	//
	// Perform xmm integer latency tests. 
	//
	LatThpt_PrepInt128(); 
	printf("\n\n");
	printf( "XMM i128 Latency:\n");
	printf( "----------------\n\t");
	printName( "MOVDQA");  
	printName( "VMOVDQA"); //Added by Ayushi  
	printName( "MOVDQU");  
	printName( "PSHUFD");  
	printName( "PMULLW");  
	printName( "POR"); 
	printName( "PMADDWD"); 
	printName( "PUNPCKLQDQ");
	printf("\n"); 
	printf( "Reg<-Reg (X <- X)  \n" ); 
	pstestLatc(X2X, movdqa);
	pstestLatc(X2X, vmovdqa); // Added by Ayushi
	pstestLatc(X2X,movdqu ); 
	pstestLatc(Xi2X,pshufd, 0xE4 ); 
	pstestLatc(X2X,pmullw ); 
	pstestLatc(X2X,por ); 
	pstestLatc(X2X,pmaddwd ); 
	pstestLatc(X2X,punpcklqdq ); 
	printf( "\nMem<-Reg<-Mem (mem <- X <- mem)\n" ); 
    	pstestLatc(mXm, movdqa);
    	pstestLatc(mXm, vmovdqa); //Added by Ayushi
	pstestLatc(mXm, movdqu ); 
//---------------Added by Ayushi------------
	printf("\n Reg <- Mem (X <- mem)\n");
	pstestLatc(m2X, movdqa); //Ayushi - Store vmovdqa from memory to X
	pstestLatc(m2X, vmovdqa); //Ayushi - Store vmovdqa from memory to X
	printf("\n Mem <- Reg (mem <- X)\n");
	pstestLatc(X2m, movdqa); //Ayushi - Store vmovdqa from X to memory
	pstestLatc(X2m, vmovdqa); //Ayushi - Store vmovdqa from X to memory
//-------------------------------------------
	// --------------------------

	// Perform xmm integer throughput tests. 

	// 

	LatThpt_PrepInt128(); 
	printf("\n\n");
	printf( "XMM i128 Throughput:  \n" ); 
	printf( "--------------------  \n\t" );
	printf( "MOVDQA   VMOVDQA   MOVDQU   PSHUFD   PMULLW    POR    PMADDWD   PUNPCKLQDQ   MOVDQ2Q(M<-X)\n" ); 
	printf( "Reg<-Reg (X <- X)  \n" ); 
	pstestThpt(X2X, movdqa ); 
	pstestLatc(X2X, vmovdqa); // Added by Ayushi
	pstestThpt(X2X, movdqu ); 
	pstestThpt(Xi2X, pshufd ,0xE4); 
	pstestThpt(X2X, pmullw ); 
	pstestThpt(X2X, por ); 
	pstestThpt(X2X, pmaddwd ); 
	pstestThpt(X2X, punpcklqdq );
	pstestThpt(X2M, movdq2q );//Added by Ayushi 
	
	printf("\n");
	printf( "Reg<-Mem (X <- mem) \n" ); 
	pstestThpt(m2X, movdqa ); 
	pstestLatc(m2X, vmovdqa); //Ayushi - Store vmovdqa from memory to X
	pstestThpt(m2X, movdqu ); 
	pstestThpt(mi2X, pshufd, 0xE4 ); 
	pstestThpt(m2X, pmullw ); 
	pstestThpt(m2X, por ); 
	pstestThpt(m2X, pmaddwd ); 
	pstestThpt(m2X, punpcklqdq ); 

	printf( "\nMem<-Reg (mem <- X)\n " ); 
	pstestThpt(X2m, movdqa ); 
	pstestLatc(X2m, vmovdqa); //Ayushi - Store vmovdqa from X to memory
	pstestThpt(X2m, movdqu ); 

	// 
	// Perform xmm SPFP latency tests. 
	// 
	LatThpt_PrepSPFP(); 
	printf("\n");
	printf( "XMM SPFP Latency:    \n" ); 
	printf( "-----------------  \n\t" ); 
	printf( "MOVAPS  MOVUPS   MOVAPD   SHUFPS   MULPS    DIVPS    MOVHLPS   MOVLHPS  \n" ); 
	printf( "Reg<-Reg (X <- X)   \n" ); 
	pstestLatc(X2X,movaps ); 
	pstestLatc(X2X,movups ); 
	pstestLatc(X2X,movapd );//Added by Ayushi	
	pstestLatc(Xi2X,shufps,0xE4); 
	pstestLatc(X2X,mulps ); 
	pstestLatc(X2X,divps ); 
	pstestLatc(X2X,movhlps ); 
	pstestLatc(X2X,movlhps ); 
	printf("\n");
	printf( "Mem<-Reg<-Mem (mem <- X <- mem) \n" ); 
	pstestLatc(mXm, movaps ); 
	pstestLatc(mXm, movups ); 
	pstestLatc(mXm, movapd );//Added by Ayushi
//----------------Added by Ayushi-------------	
	printf("\nReg <- Mem (X <- mem)\n \t  \t");
	pstestLatc(m2X, movapd); //Added by Ayushi - Store movapd from memory to X
	printf("\nMem <- Reg (mem <- X) \n \t  \t");
	pstestLatc(X2m, movapd); //Added by Ayushi - Store movapd from X to memory
//---------------------------------------------------
	// 
	// Perform xmm SPFP throughput tests. 
	// 
	LatThpt_PrepSPFP(); 

	printf("\n");
	printf( "XMM SPFP Throughput:  \n" ); 
	printf( "--------------------  \n\t" ); 
	printf( "MOVAPS   MOVUPS   MOVAPD    SHUFPS    MULPS    DIVPS    MOVHLPS    MOVLHPS  \n" ); 
	printf( "Reg<-Reg (X <- X)   \n" ); 
	pstestThpt(X2X, movaps ); 
	pstestThpt(X2X, movups ); 
	pstestThpt(X2X, movapd); //Added by Ayushi
	pstestThpt(Xi2X, shufps, 0xE4 ); 
	pstestThpt(X2X, mulps ); 
	pstestThpt(X2X, divps ); 
	pstestThpt(X2X, movhlps ); 
	pstestThpt(X2X, movlhps ); 
	printf("\n");
	printf( "reg<-Mem (X <- mem)\n" ); 

	pstestThpt(m2X, movaps ); 
	pstestThpt(m2X, movups ); 
	pstestThpt(mi2X, shufps, 0xE4 ); 
	pstestThpt(m2X, mulps ); 
	pstestThpt(m2X, divps ); 
	pstestThpt(m2X, movapd); //Added by Ayushi
	printf("\n");
	printf( "Mem<-Reg (mem <- X)\n" ); 

	pstestThpt(X2m, movaps ); 
	pstestThpt(X2m, movups ); 
	pstestThpt(X2m, movapd); //Added by Ayushi
	printf("\n");
//	ptestThpt(X2m, movups);
	printf("\n");

	printf("general purpose register\n");
	printf("---------------------------");
	//ptestThptn(m2E, mov);

#ifdef X64
	//ptestThptn(m2R, mov);
#endif
	printf("\n<>Throughput\n\n");
	ptestThptn(E2EDA, bswap); //Added by Ayushi
	ptestThptn(m2R, bsf); 
	ptestThptn(E2m, mov);
	ptestThptn(E2E, mov);
	ptestThptn(m2R, and); //Logical AND
	ptestThptn(R2m, and); //Logical AND when stored into memory has higher latency 
	ptestThptn(m2E, add);
	ptestThptn(E2m, add);
	ptestThptn(m2EDA, mul);
	ptestThptn(E2EDA, mul);
	ptestThptn(m2R, xchg);
	ptestThptn(E2E, xchg);
	ptestThptGn(E2E, mov);
	printf("\n<>Latency\n\n");
	ptestLatcn(E2EDA, bswap); //operates only on GPR
	ptestLatcn(m2R, bsf); //reads value from memory into GPR R'64 bit and scans the bit and save to register
	ptestLatcn(m2R, and); //Logical AND
	ptestLatcn(R2m, and); //Logical AND when stored into memory has higher latency 
	ptestLatcn(m2E, add); 
	ptestLatcn(E2m, add); 
	ptestLatcn(E2m, mov); //latency of store from EAX to memory
	ptestLatcn(m2E, mov); //latency of load from memory to EAX
	ptestLatcn(R2m, mov); //latency of store from RAX to memory
	ptestLatcn(m2R, mov); //latency of load from memory to RAX
	ptestLatcn(mRm, mov); //latency of mem -> R -> mem 
	ptestLatcn(E2EDA, mul);
	ptestLatcn(m2R, xchg); // Take around 15 cycles because LOCK is implemented for the time xchg takes
//	ptestThptn(m2m, add); //Add memory to memory
	printf("\nFloating point Insts\n");
	printf("\n<>Throughput\n\n");
    	ptestThptFn(m2F, fadd);
    	ptestThptFn(F2m, fst);
    	ptestThptFn(m2D, fadd);
    	ptestThptFn(D2m, fst);
    	ptestThptFn(F2F, fadd);
    	ptestThptFn(F2F, fmul);
    	ptestThptFn(D2D, fadd);
    	ptestThptFn(F2m, fist);
	ptestThptFn(F2m, fstp);
    	ptestThptFn(m2F, fld); //Load
    	ptestThptFn(D2D, fadd); //Add instruction after store takes more time?
    	printf("\n<>Latency\n\n");
	ptestLatcFn(m2F, fadd);
    	ptestLatcFn(m2F, fld); //Load
    	ptestLatcFn(F2m, fstp); //Store
    	ptestLatcFn(F2m, fst); //Store

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
