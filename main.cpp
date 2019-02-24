#include <iostream>
#include "JobScheduler.h"


#define NUMBER_OF_TASKS 8
#define FAST_TAG 1
#define SLOW_TAG 2


using namespace std;


/* Example */
class HelloWorldJob : public Job {
	int taskid;
public:
	HelloWorldJob(int id) : Job(), taskid(id) {}
	void run() override {
		printf("Hello World from task %d\n", taskid);
	}
};

class SlowJob : public Job {
	int taskid;
public:
	SlowJob(int id, int tag = NOTAG) : Job(tag), taskid(id) {}
	void run() override {
		for (int i = 0 ; i >= 0 ; i++);                // waste quite some time
		printf("Slow job with task id %d finished!\n", taskid);
	}
};

class FastJob : public Job {
	int taskid;
public:
	FastJob(int id, int tag = NOTAG) : Job(tag), taskid(id) {}
	void run() override {
		for (int i = 0 ; i < 1000 ; i++);              // waste less time
		printf("Fast job with task id %d finished!\n", taskid);
	}
};


int main(){
	JobScheduler scheduler;                            // use default number of threads
	for (int i = 0 ; i < NUMBER_OF_TASKS ; i++){
		scheduler.schedule(new HelloWorldJob(i));      // schedule new jobs
	}
	scheduler.waitUntilJobsHaveFinished();             // block (if needed) until all jobs have finished
	/////////////////////////////////////////////
	for (int i = 0 ; i < NUMBER_OF_THREADS ; i++){
		if (i % 2 == 0){
			scheduler.schedule(new SlowJob(i, SLOW_TAG));      // schedule new slow job
		} else {
			scheduler.schedule(new FastJob(i, FAST_TAG));      // schedule new fast job
		}
	}
	scheduler.waitUntilJobsHaveFinished(FAST_TAG);
	printf("Waited for FAST jobs!\n");
	scheduler.waitUntilJobsHaveFinished();
	printf("Waited for all remaining jobs!\n");
	return 0;
}
