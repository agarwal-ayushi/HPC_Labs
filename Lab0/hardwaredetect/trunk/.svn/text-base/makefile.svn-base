FLAG= -O2
arch=$(shell uname -m)
#the cpu MHz will change when running 
#get the frequency
scaling_max_freq_fn=/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq

ifeq ($(scaling_max_freq_fn), $(wildcard ${scaling_max_freq_fn}))
scaling_max_freq_exist=yes
coreFrequencyK=$(shell cat ${scaling_max_freq_fn})
#coreFrequencyM=$(shell expr ${coreFrequencyK} / 1000)
coreFrequencyM=$(shell echo "scale=1; ${coreFrequencyK} / 1000.0" | bc -l )
FLAG+= -DFREQ=$(coreFrequencyM) 
else
scaling_max_freq_exist=no
coreFrequencyM=$(shell grep MHz /proc/cpuinfo | uniq | sed "s/[\\t\\n: a-zA-Z]//g")
FLAG+= -DFREQ=$(coreFrequencyM) 
endif


ifeq "$(arch)" "x86_64"
FLAG+= -DX64
else 
FLAG+= -m32 
endif

ICCFLAG=${FLAG}
GCCFLAG=${FLAG} -msse2

all : gnuLT testCache cpuid
testLT:testLT.cpp latthpt_gnu.h latthpt_asm.h
	icc ${ICCFLAG} -use-msasm -o $@ -DINTEL_ASM $<
gnuLT:testLT.cpp latthpt_gnu.h latthpt_asm.h testop.h testopasm.h macro_asm.h
	g++ ${GCCFLAG} -o $@  $<
cpuid:cpuid.cpp cpu.h	
	g++ ${GCCFLAG}  -o $@ $<
testLT.s:testLT.cpp
	icc -S ${ICCFLAG} -o $@.s $<
	objdump -S $@ > $@.S
testCache:testCache.cpp	
	g++ ${GCCFLAG} -o $@ $<
testCache.s:testCache.cpp	
	g++ -S ${GCCFLAG} -o $@.s $<
	objdump -S $@ > $@.S
testLT.obj:testLT.cpp
	icc ${ICCFLAG} -c  -use-msasm -o $@ -DINTEL_ASM $<

clean:
	rm -rf testLT testCache test gnuLT cpuid *.s *.S	
