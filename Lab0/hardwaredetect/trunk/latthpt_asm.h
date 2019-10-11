
//******************************************************************************
// DEFINES
//******************************************************************************

//
// XMM Macros
//
/*********************************************************
 *E 	:  32-bit GRP 
 *R   	:  64-bit GRP
 *m 	:  memory
 *M 	:  MMX 
 *X 	:  XMM
 *i 	:  immediate
 *F 	:  float 
 *D 	:  double
 * ******************************************************/
#ifdef INTEL_ASM
/***********************************************************************
 * intel ASM
 * *********************************************************************/
#define _Label(x) label##x
#define Label(x) _Label(x)
#define asmTestKernel( testCase, x, ...)                                	\
__asm { __asm mov ecx, 7999 												\
__asm Label(__LINE__) :  													\
    LATTHPT_MACROx25( testCase( x, ##__VA_ARGS__ ) )                      	\
__asm sub ecx, 1 __asm jne Label(__LINE__)} 

#else
/***********************************************************************
 * gnu ASM
 * *********************************************************************/
#define _Label(x) Str(label##x)
#define Label(x) _Label(x)

#define asmTestKernel( testCase, x, ...)                                  	\
__asm__("movl $7999, %%ecx;" Label(__LINE__)":" 							\
    LATTHPT_MACROx25( testCase( x, ##__VA_ARGS__ ) )                      	\
   "subl $1, %%ecx;" "jne " Label(__LINE__) " ;" \
   ::"S"(aPtr):"%eax", "%ecx", "%ebx","%edx");
#endif

#define asmTestFrame( testCase, ...) 	\
{ ReadTSC( LatThptStartTime ) }			\
asmTestKernel(testCase, __VA_ARGS__)    \
{ ReadTSC( LatThptEndTime ) }

#define asmTestThpt( InstrType, ...) 				\
asmTestFrame(asmTHPT_##InstrType , __VA_ARGS__)    	\

#define asmTestLatc( InstrType, ...) 				\
asmTestFrame(asmLAT_##InstrType , __VA_ARGS__)     	\


#define asmTestThptF( InstrType, ...) 	\
{__masm(emms)} 							\
{__masmFm(fld, aOnesPS)}             	\
{__masmFm(fld, aOnesPS)}             	\
asmTestThpt( InstrType,__VA_ARGS__) 	\
{__masmFm(fstp, aOnesPS)}             	\
{__masmFm(fstp, aOnesPS)}             	\
{__masm(emms)}
