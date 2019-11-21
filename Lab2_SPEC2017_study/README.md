https://iitd-plos.github.io/col718/labs/Lab2/lab2.html

# COL718 Lab 2 : Comparative Study of Performance of SPEC Benchmarks Running on Different Types of Cores: SMT, CMP & SMP
Due date - 23:55, 26 September 2019

The ideas of Chip Multiprocessing(CMP), Symmetric Multiprocessing(SMP) and Simultaneous Multithreading/Hyperthreading (SMT) are discussed in class. Each of these employ different extents of Resource Sharing. In this assignment we will try to observe their comparative imapacts on the peformance of standard applications selected from the SPEC 2017 Benchmarks Suit.

## Instructions
Download and Install SPEC CPU 2017 benchmark suite. 

- Follow instructions at https://www.spec.org/cpu2017/Docs/install-guide-unix.html to install and run the CPU 2017 benchmark suite
you can use the commands in this file to run any benchmark individually: cpu2017_cmdlines.sh.

- Run two copies of the same benchmarks on different SMT Cores, different CMP Cores and Different SMP Cores.
- As a baseline of performance comparison, run the benchmarks in a stand-alone mode, giving them accesses to all the necessary system resources. These stand-alone performance values could be used as references to observe how much slowdown each benchmarks experience in each case.
- Does the types/characteristics of benchmarks have an impact on the performance differences(or, slowdowns)?
- Do comparative study of performances for the aforementioned four cases with possible explanations. Analyze how these slowdowns varies across different benchmarks. If possible, try to argue why does they vary that way.
- Your Report should be succinct. It should suitably captures the essence of all your findings.

This repository only contains the final report which reports all the findings on SPEC 2017 benchmarks. 
P.S. We are not entitled to distribute the SPEC suite. 
