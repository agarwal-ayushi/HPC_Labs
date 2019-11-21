https://iitd-plos.github.io/col718/labs/Lab3/Lab3.html

# COL718 Lab 3 : Measuring Different Configuration Parameters of Memory Hierarchy by Running a Program
Due date - 23:55, 11 October 2019

In this assignment, we will try to measure different parameters of cache configurations along with some parameters of the memory hierarchy.

## Instructions
- To get an overview of the program, you could refer to Exercise 5.2 of "Computer Architecture: A Quantitative Approach (Third Edition)" by J. Hennessy and D. Patterson. Refer to:
http://www.cse.iitd.ac.in/~sbansal/os/previous_years/2010/hw1/H&P-5.2-1.jpg
http://www.cse.iitd.ac.in/~sbansal/os/previous_years/2010/hw1/H&P-5.2-2.jpg

- Plot the experimental results in a suitable way which helps you analyze the results.
- The program assumes that the program addresses track physical addresses which is true on machines that use virtually addressed caches. In general, virtual addresses tend to follow physical adddresses shortly after rebooting. You might have to reboot the machine in order to get smooth lines in your results.
- You have to measure the following things:
* The no. of levels of cache
* Sizes of each level of cache
* Cache line sizes(or, block sizes) of each level of cache
* The system page size
* The no. of entries in the TLB
* The associativities of each cache level
* The miss penalties for each level of cache
* Page fault time to the secondary memorye
- You have to properly justify how you have analyzed the experimental results and obtained the values of these architectural parameters.
- What else do you think you could measure about the memory hierarchy with the help of this program? How?
- In "Computer Architecture: A Quantitative Approach (Fourth Edition)" by J. Hennessy and D. Patterson, you could find a slightly modified version of the program though the central methodological theme remains the same. To obtain better results on your target machine, you could certainly modify the progrm by keeping the methodology same.
- Perform the experiment on multiple machines. Validate your findings with the actual values of the parameters for different machines you use. Your report should contain: all the experimental results along with their validation, your analysis of those results to obtain the parameter values, additional parameter(s) you think could be measured, and how.
