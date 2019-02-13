# Job-Scheduler
A pthread implementation of a Job Scheduler in C++, using a static pool of threads. Jobs can be scheduled to be ran by a thread in a FIFO manner as well as waited (blocking) for. To use one simply needs to extend the Job abstract class and override the run() method with the work load you wish scheduled.
