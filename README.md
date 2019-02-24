# Job-Scheduler
A pthread implementation of a Job Scheduler in C++, using a static pool of threads. Jobs can be scheduled to be run by a thread in a FIFO manner as well as waited (blocking) for. The user can choose to wait for all jobs or for jobs with a specific (int) tag. Tags can be used to group Jobs that we want to be waited for separately.

# Set up
To set up this Job Scheduler one simply needs to add its source files (JobScheduler.cpp, JobScheduler.h) to their project, along with the "-pthread" flag to g++ at compilation.

# Usage
To use it simply extend the Job abstract class and override the run() method with the job you wish scheduled. 

A Job Scheduler object is allocated with the desired size of the static thread pool (or with its default value). With it, you can schedule dynamically allocated objects of your derived classes (the scheduler deletes them when their run() has finished), check if all jobs or jobs with a certain tag are finished or block waiting for them to finish.

# Example
The given main.cpp demonstrates two simple usage examples. 

Firstly, it extents the Job class with a HelloWorldJob class whose run() method prints "Hello World" on std::out. In the main() function, it allocates a JobScheduler object on the stack and schedules a #defined number of different - dynamically allocated - HelloWorldJob jobs. It then waits (blocking) for all of them to finish.

Secondly, it extends the Job class with a SlowJob and a FastJob class who are given their own different tags (must not conflict with #defined NOTAG). After scheduling NUMBER_OF_THREADS different jobs as such, it waits for the fast jobs! This waiting will probably be done before (all) the slow jobs are done. This is to show the benefits of using tags for different groups of jobs.
