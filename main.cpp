#include <iostream>
#include "JobScheduler.h"


#define NUMBER_OF_TASKS 16


using namespace std;


/* Example */
class HelloWorldJob : public Job {
	int taskid;
public:
	HelloWorldJob(int id) : taskid(id) {}
	void run() override {
		printf("Hello World from task %d\n", taskid);
	}
};


int main(){
	JobScheduler scheduler;                          // use default number of threads
	for (int i = 0 ; i < NUMBER_OF_TASKS ; i++){
		scheduler.schedule(new HelloWorldJob(i));    // schedule new jobs
	}
	scheduler.waitUntilAllJobsHaveFinished();        // block (if needed) until all jobs have finished
	return 0;
}
