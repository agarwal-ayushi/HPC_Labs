/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年03月29日 13时33分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai (Zhenghua Dai), djx.zhenghua@gmail.com
 *        Company:  dzh
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define ReadTSC32(x) __asm__ __volatile__("rdtsc" : "=a" (x.low), "=d" (x.high));
//
//#define ReadTSC32(x) \
    __asm__ __volatile__("xorl %%eax, %%eax; cpuid; rdtsc; movl %%eax, (%%edi); movl %%edx, 4(%%edi); xorl %%eax, %%eax; cpuid;" \
            ::"D"(&(x.low)):"%eax","%ebx","%ecx","%edx");
typedef union {
    unsigned long long u64;
    struct {
        unsigned low;
        unsigned high;
    };
} _U64;
inline _U64 getRdtscOverhead()
{
    int i;
    _U64 startTime, endTime, tmpOverhead;
    tmpOverhead.u64 = 0;
    ReadTSC32( startTime) ;
    ReadTSC32( endTime) ;
    tmpOverhead.u64 = endTime.u64 - startTime.u64;

    for(i =0;i<1000;i++){
        _U64 tmp;
        ReadTSC32( startTime) ;
        ReadTSC32( endTime) ;
        tmp.u64 = endTime.u64 - startTime.u64;
        if(tmpOverhead.u64 > ( tmp.u64)){
            tmpOverhead.u64 =  tmp.u64;
        }
        printf("%u %u - %u %u = %u %u\n", endTime.high, endTime.low, startTime.high, startTime.low, tmp.high,tmp.low);
        printf("%lu - %lu = %lu \n", endTime.u64, startTime.u64, tmpOverhead.u64);
    }
    return tmpOverhead;
}

int main()
{
    _U64 startT,endT;
    printf("size:%d\n",sizeof(long long));
    ReadTSC32(startT);
    printf("%d %0x\n", startT.high, startT.low);
    endT = getRdtscOverhead();
}
