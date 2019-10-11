#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <map>
#include "cpu.h"
using namespace std;
using namespace CPU;
registers R;
int cpuVendor;
#ifndef WIN32
void cpuid(int m_eax)
{
	__asm__(
			"cpuid;"
			:"=a"(R.GRP[0]),"=b"(R.GRP[1]),"=c"(R.GRP[2]),"=d"(R.GRP[3])
			:"0"(m_eax)
			:
		   );
}

void cpuid(int m_eax, int m_ecx)
{
	__asm__(
			"cpuid;"
			:"=a"(R.GRP[0]),"=b"(R.GRP[1]),"=c"(R.GRP[2]),"=d"(R.GRP[3])
			:"0"(m_eax),"2"(m_ecx)
			:
		   );
}
#else

void cpuid(int m_eax)
{
	__asm mov eax,  dword ptr  m_eax  
	__asm cpuid 
	__asm mov  dword ptr R.GRP, eax  
	__asm mov  dword ptr R.GRP + 4, ebx  
	__asm mov  dword ptr R.GRP + 8, ecx  
	__asm mov  dword ptr R.GRP + 12, edx  
}

void cpuid(int m_eax, int m_ecx)
{
	__asm mov eax,  dword ptr  m_eax  
	__asm mov ecx,  dword ptr  m_ecx  
	__asm cpuid 
	__asm mov  dword ptr R.GRP, eax  
	__asm mov  dword ptr R.GRP + 4, ebx  
	__asm mov  dword ptr R.GRP + 8, ecx  
	__asm mov  dword ptr R.GRP + 12, edx  
}


#endif
#define declareCacheType \
	declare(NOTYPE,NOTYPE) \
declare(ITLB,  L  Instr  TLB) \
declare(DTLB,  L  Data   TLB) \
declare(I0TLB, L0 Instr  TLB) \
declare(D0TLB, L0 Data   TLB) \
declare(L1TLB, L1        TLB) \
declare(L1IC,  L1 Inst Cache) \
declare(L1DC,  L1 Data Cache) \
declare(L2DC,  L2 Data Cache) \
declare(L3DC,  L3 Data Cache) \
declare(TRACEC,TRACE   Cache) 

#define declare(type, name) type,
typedef enum {
	declareCacheType 
} cacheType;

#undef declare
#define declare( type, desc) (char*) #desc ,
char* nameDes[256]={declareCacheType};

template< cacheType type> 
class name 
{
	public:
		static const int  des=0;
};

#undef declare
#define declare( type, desc) \
	template<>\
class name<type>\
{\
	public:\
		   static const int des = 0; \
};



class cacheDes{
	public:
		cacheType type;
		int size;
		int way;
		int line;
		char* descriptor;
	public:
		cacheDes(cacheType t, int n, int w, int l,char* s):type(t),size(n),way(w),line(l),descriptor(s){}
		cacheDes(cacheType t, int n, int w, int l):type(t),size(n),way(w),line(l),descriptor(0){}
		cacheDes(char* s):type(NOTYPE),size(0),way(0),line(0){ descriptor = strdup(s);};
		cacheDes():type(NOTYPE),size(0),way(0),line(0),descriptor(0){}
	public:
		void printdes() {
			printf("%s\n", descriptor);
		}
		void print() {
			printf("%s ", nameDes[type]);
			if(type< L1IC){ // TLB
				printf("%d entries, %d Way, %d kBytes page \n", size, way, line);
			}else
				printf("%dk Bytes, %d Way, %d Bytes Line \n", size, way, line);
		}
};

map<unsigned int, cacheDes> cache;
int getCacheDes()
{
	cpuid(2);
		R.print();
	for(int i=0;i<4;i++)
		if((R.GRP[i] & ( 1<<31) ) == 1) R.GRP[i] = 0;
	unsigned char* desbytes = (unsigned char*) R.GRP;
	for(int i=1;i<16;i++){
		unsigned int desc = desbytes[i];	
		printf("%2x: ", desc);
		if( cache.find(desc) != cache.end()){
			cache[desc].printdes();
		}else 
			printf("\n");
	}
	return 1;
}

void getCacheDetail()
{
	for(int i=0;i<9;i++){
		cpuid(4,i);
		if(R.eax == 0) break;
		R.print();
	}
}


#include "cacheDes.h"
void initCacheDes()
{

	//cache[0x01] = cacheDes(ITLB, 32, 4, 4*10241); 
	//cache[0x02] = cacheDes(ITLB, 2, 0, 4*1024*1024); 
	//cache[0x05] = cacheDes(L1DTLB, 32, 4, 4*1024*1024); 
	//cache[0x2c] = cacheDes(L1DC, 32, 8, 64); 
#define defineCache(idx, type, des) cache[idx]= cacheDes((char*) des); 
	DeclareIntelCacheDesc();
}

int getCPUVendor()
{
	unsigned int vendor[5];
	cpuid(0);
	vendor[0] = R.eax;
	vendor[1] = R.ebx;
	vendor[2] = R.edx;
	vendor[3] = R.ecx;
	vendor[4] =0;
	printf("Vendor:%s\n", (char*)&vendor[1]);
	if(R.ebx == 0x756e6547) return 0;
	if(R.ebx == 0x68747541) return 1;
	if(R.ebx == 0x69727943) return 2;
	return -1;
}

int main()
{
	cpuVendor = getCPUVendor();
	initCacheDes();
	getCacheDes();
	getCacheDetail();
}
