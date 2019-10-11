https://iitd-plos.github.io/col718/labs/lab0/lab0.html

# COL718 Lab 0 : Measuring Instruction Latency and Throughput
Due date - 23:55, 15 August 2019

Latency and throughput are typically used as the basis for instruction performance on a microprocessor. In this assignment, we will measure the latency and throughput of different x86 instructions. This assignment would also give a gentle overview of x86 ISA.

## Instructions
- Go to this page for a general overview of what exactly Latency and Throughput of an instruction mean: https://software.intel.com/en-us/articles/measuring-instruction-latency-and-throughput.
- Download the latThpt.zip file from the References section of the course webpage.
- First, try to compile the test program and see the latency and throughput of the instructions which are specified in that program.
- The macros for the instructions are defined in 'macro_asm.h' and 'lathpt_gnu.h' file. See those to know for which all operand types/addressing fomats macros are defined. Use new instructions(which are not there in the test program) to measure the latency and/or throughput of each of them. You could use some instructions which were discussed in the class.
- New instructions might, or might not have suitable macros defined for them. Try to use such instruction(s) for which the macros are defined but not used. If possible, try to use some instruction(s) for which the macros are not defined.
- Measure the load and store latencies for the general-purpose registers, floating-point registers, mmx, xmm and ymm registers.
- Express all your findings in a report. Why do you think two different metrics(latency & throughput) are required to measure the performance? Also compare your measured latencies and throughputs against the Agner Fog's Manual which is provided in the reference section.
