# Project 5
## Programming requirements

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates.
- The programs have to be documented! Any file that you edit should have preamble
 including your name as the author, description of the purpose of the program and
 inline comments in the functions that you implement. All functions except for `main()` should
 have descriptions of function parameters, returned value and a summary of what the function does.

- The code has to follow C programming conventions.
- The code has to be formatted properly.  

## Problem 1
Write a C Program that writes all the odd numbers from 1 to 100,000 to the output file. Open the file, write the next value, and close the file.  Measure how much elapsed time it takes to complete this processing. The process should open and close the file 50000 times. Yes, it is inefficient, but we are trying to force some I/O usage.

Next have the program fork and create 10 separate processes. Each process would process a range of 1 to 100,000 . One process would process 1 to 10000, another 10001 to 20000 etc. . Each process performs the exact same tasks , in the same way, as the first part of the problem, but write the output to 10 separate files, one for each process. Next read the ten files to make one file with all the number.. Measure the elapsed time it takes for all 10 processes to complete, and to create the output file.

The goal is to show that by breaking up the task across processes (that do I/O), the total elapsed needed will be shorter. Make sure you choose elapsed time function in C to track time, versus CPU Clock time.
If your program is not finding a difference between the approaches or is taking too long, you can modify the 100,000 up or down.
## Problem 2
Enhance the program shown in class to be a more robust quiz program. Have the parent program pick numbers between in some range, and an operator (`+`, `-`, or `*`), and see if the person can answer correctly within 5 seconds. If a correct answer is provided within 5 seconds, show the next question and set the timer back to 0. An incorrect answer redisplays the question. If no answer with 10 seconds, the timer process should notify  the parent class, indicating that time is up. When the time is up, add 1 to the count the number of missed questions and go to the next question. 

You may need to notify the timer to start.

The parent program should prompt the user at the beginning of the program for the number of questions in the quiz. At the end of the questions, the program should print correct answers, incorrect answer (wrong answers within time frame), and missed questions (no correct answer within timeframe).

__Deliverables:__
Implementation of the programs in `problem1.c` and `problem2.c` files.
