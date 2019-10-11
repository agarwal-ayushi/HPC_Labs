https://iitd-plos.github.io/col718/labs/Lab1/Lab1.html

# COL718 Lab 1 : Measuring the ROB Capacity, PRF Size and MLP
Due date - 23:55, 7 September 2019

In this assignment, we will try to measure the capacity of ROB(Re-Order Buffer) which is, as discussed in the class, a central element in OOO Processor architecture. We will also measure the number of speculative and non-speculative registers. We will try to measure the degree of MLP(Memory Level Parallelism) as well. We will write our own microbenchmarks to measure all these parameters. The guiding principle of writing suitable microbenchmarks will be discussed in the following section.

## Instructions
- Please have a look at the paper(only Para 5,6 of Section 3(Hardware Callibration), Page 5)for a general outline of how to write microbenchmark(s) to measure the ROB Capacity and MLP : http://www.cse.iitd.ac.in/~sbansal/pubs/bacus.pdf.
- For more detailed understanding, please have a look at the blog http://blog.stuffedcow.net/2013/05/measuring-rob-capacity/.
- You have to measure ROB Capacity, Number of Speculative and Non-Speculative Regsters(including floating-point), Degree of MLP for different machines like, your laptop, your lab machine and a server machine(you would be given access to a server, if needed)
- To write a microbenchmark for measuring the ROB Capacity and MLP, you have to use long-latency instruction seperated by several NOPs. As described in the above links, you could use memory load instruction. But, you have to make sure that everytime the load is executed, it is a cache-miss. Only then, you could guarantee that the instruction doesn't committ early and occupies ROB. You could use CLFLUSH, or may be, non-temporal memory loads to ensure cache-misses everytime. Please refer to the manual to know more about CLFLUSH: https://www.cse.iitd.ernet.in/~sbansal/os/ref/ia32-2.pdf
- You can use inline assemblies, intrinsics to write your own microbenchmarks.
- Express all your findings in a report. Your report should contain all the graphs, reported ROB capacity, degree of MLP, numbers of speculative and non-speculative registers for all the different machines you have used.
- Please do not reuse the code that is available on the link that is provided with the assignment description.Please code your own original solution. Your submission would be graded on your original exploration and investigations; copied answers will receive zero and potentially disciplinary action. In your report, you are expected to describe your experiences (including failed attempts, etc.).
- Submit the report along with your microbenchmarks.
