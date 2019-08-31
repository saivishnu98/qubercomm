#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* sub_thread(void* arg) {
	/* detach the current thread from the calling thread */
	pthread_detach(pthread_self());

	printf("Inside the thread\n");
	/*exit the current thread*/
	pthread_exit(NULL);
}

void start_thread() {
	pthread_t pthread_id;
	/*creating a new thread*/
	pthread_create(&pthread_id,NULL,&sub_thread,NULL);

	printf("This lines may be printed before the thread terminates\n");

	/*the fallowing line terminates the thread manually pthread_cancel(pthread_id)*/
	if(pthread_equal(pthread_id,pthread_self())) {
		printf("Threads are equal\n");
	}
	else {
		printf("Threads are not equal\n");
	} 
	/*waiting for the created thread to terminate*/
	pthread_join(pthread_id,NULL);

	printf("This line will be printed after thread ends\n");

	pthread_exit(NULL);
}

/*main code*/

int main() {
	start_thread();
	return 0;
}
