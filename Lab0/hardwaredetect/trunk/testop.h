#ifndef __TEST_OP__HEADER__
#define __TEST_OP__HEADER__
#include <stdio.h>
#include "macro_asm.h"
#include "string.h"
#include "testopasm.h"
template<typename T>
class typestr{
};

#define decalreTypeName( type, name) \
template<>class typestr<type> {\
	public:static char * val(){ return name;} ;\
};
decalreTypeName(unsigned int, "I32");
decalreTypeName(float, "F32");

typedef void (* OP3)(int, unsigned int*, unsigned int*, unsigned int*);
typedef void (* OP2)(int, unsigned int*, unsigned int*);

#define declareOP3( opName, op)\
	template<typename T>\
inline void test##opName##3(int n, T *a, T* b, T* c)\
{\
	for(int i=0;i<n;i++){\
		a[i+0] =( b[i+0] op  c[i+0]);\
	}\
};
declareOP3(Add, +);
declareOP3(Mul, *);
declareOP3(Div, /);

#define declareOP3i3( opName, op)\
	template<typename T>\
inline void test##opName##3i3(int n, T *a, T* b, T* c)\
{\
	for(int i=0;i<n;i++){\
		a[i+0] =( b[i+0] op  c[i+0] op  b[i+0] op  c[i+0]);\
	}\
};
declareOP3i3(Add, +);
declareOP3i3(Mul, *);
declareOP3i3(Div, /);


#define declareOP2( opName, op)\
	template<typename T>\
inline void test##opName##2(int n, T *a, T* b )\
{\
	for(int i=0;i<n;i++){\
		a[i] = a[i] op  b[i];\
	}\
};

declareOP2(Add, +);
declareOP2(Mul, *);
declareOP2(Div, /);
//declareOP2(Assign, =);


#define declareOP2i2( opName, op)\
	template<typename T>\
inline void test##opName##2i2(int n, T *a, T* b )\
{\
	for(int i=0;i<n;i++){\
		a[i] = a[i] op  b[i] op b[i];\
	}\
};

declareOP2i2(Add, +);
declareOP2i2(Mul, *);
declareOP2i2(Div, /);


#define declareOPa2( opName, op)\
	template<typename T>\
inline void test##opName##2(int n, T *a, T* b )\
{\
	for(int i=0;i<n;i++){\
		a[i]  op  b[i];\
	}\
};

declareOPa2(Adda, +=);
declareOPa2(Mula, *=);
declareOPa2(Diva, /=);
declareOPa2(Assign, =);


#define declareOPa2i2( opName, op)\
	template<typename T>\
inline void test##opName##2i2(int n, T *a, T* b )\
{\
	for(int i=0;i<n;i++){\
		a[i]  op  b[i];\
		a[i]  op  b[i];\
	}\
};

declareOPa2i2(Adda, +=);
declareOPa2i2(Mula, *=);
declareOPa2i2(Diva, /=);
declareOPa2i2(Assign, =);

//template<typename T>
//void testAdd(int n, T *a, T* b)
//{
//	for(int i=0;i<n;i++)
//		a[i] += b[i];
//}

	template<typename T>
inline void pctestFrameWork(void (* fptr)(int, T*, T*), char* msg, int n)
{
	static T *Veci1=0, *Veci2=0;
	static T *memVeci1=0, *memVeci2=0;
	static int first = 1;
	static int maxn = 1024 * 1024 * 4;
	if( first) {
		first = 0;
		Veci1 = (T*) malloc(maxn *sizeof(T));
		Veci2 = (T*) malloc(maxn *sizeof(T));
		memVeci1 = (T*) malloc(maxn *sizeof(T));
		memVeci2 = (T*) malloc(maxn *sizeof(T));
		Veci1 = memVeci1 ; 
		Veci2 = memVeci2 ;
		for(int i=0;i<maxn;i++) Veci1[i] = 1;
		for(int i=0;i<maxn;i++) Veci2[i] = 1;
	}

	if( strcmp(msg, "exit") == 0){
		free(memVeci1);
		free(memVeci2);
		return ;
	}


	fptr(n, Veci1, Veci2);
	fptr(n, Veci1, Veci2);

	_U64 startTime, endTime, tmpOverhead;
	ReadTSC( startTime) ;
	fptr(n, Veci1, Veci2);
	fptr(n, Veci1, Veci2);
	fptr(n, Veci1, Veci2);
	fptr(n, Veci1, Veci2);
	ReadTSC( endTime) ;
	tmpOverhead.u64 = endTime.u64 - startTime.u64  - LatThptTimeOverhead.u64;
	printf("<%s a %3s b %f>\n", typestr<T>::val(),  msg,(double) tmpOverhead.u64 / (4*n));
}


	template<typename T>
inline void pctestFrameWork(void (* fptr)(int, T*, T*, T*), char* msg, int n)
{
	static T *Veci1=0, *Veci2=0, *Veci3=0 ;
	static T *memVeci1=0, *memVeci2=0, *memVeci3=0 ;
	static int first = 1;
	static int maxn = 1024 * 1024 * 4;
	if( first) {
		first = 0;
		memVeci1 = (T*) malloc(maxn *sizeof(T));
		memVeci2 = (T*) malloc(maxn *sizeof(T));
		memVeci3 = (T*) malloc(maxn *sizeof(T));
		Veci1 = memVeci1 ; 
		Veci2 = memVeci2 ;
		Veci3 = memVeci3 ;
		for(int i=0;i<maxn;i++) Veci1[i] = 1;
		for(int i=0;i<maxn;i++) Veci2[i] = 1;
		for(int i=0;i<maxn;i++) Veci2[i] = 1;
	}

	if( strcmp(msg, "exit") == 0){
		free(memVeci1);
		free(memVeci2);
		free(memVeci3);
		return ;
	}

	fptr(n, Veci1, Veci2, Veci3);
	fptr(n, Veci1, Veci2, Veci3);

	_U64 startTime, endTime, tmpOverhead;
	ReadTSC( startTime) ;
	fptr(n, Veci1, Veci2, Veci3);
	fptr(n, Veci1, Veci2, Veci3);
	fptr(n, Veci1, Veci2, Veci3);
	fptr(n, Veci1, Veci2, Veci3);
	ReadTSC( endTime) ;
	tmpOverhead.u64 = endTime.u64 - startTime.u64  - LatThptTimeOverhead.u64;
	printf("<%s c = a %3s b %f>\n",  typestr<T>::val(),msg,(double) tmpOverhead.u64 / (4*n));
	//startTSC();
	//ReadTSC( LatThptStartTime ); 
	//ReadTSC( LatThptEndTime ) ;
	//endTSC();
	//printf("%f\n",(getTSC()/n));

}

#define TestIntOpFrame( op) \
{}
#endif
