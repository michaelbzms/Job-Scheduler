# Job-Scheduler
A pthread implementation of a Job Scheduler in C++, using a static pool of threads. Jobs can be scheduled to be run by a thread in a FIFO manner as well as waited (blocking) for.

# Set up
To set up this Job Scheduler one simply needs to add its source files (JobScheduler.cpp, JobScheduler.h) to their project, along with the "-pthread" flag to g++ at compilation.

# Usage
To use it simply extend the Job abstract class and override the run() method with the job you wish scheduled.
A Job Scheduler object is allocated with the desired size of the static thread pool (or with its default value).  
With it, you can schedule dynamically allocated objects of your derived classes (the scheduler deletes them when their run() has finished), check if all jobs are finished or block waiting for them to finish.

