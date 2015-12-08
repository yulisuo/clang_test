#include <stdio.h>
#include <pthread.h>

void th_fun1();
int main(void){
	pthread_t pid1,pid2,pid3,pid4,pid5;
	int n1 = 1,n2 = 2,n3 = 3,n4 = 4,n5 = 5;
	pthread_create(&pid1,NULL,(void *)th_fun1,&n1);
	pthread_create(&pid2,NULL,(void *)th_fun1,&n2);
	pthread_create(&pid3,NULL,(void *)th_fun1,&n3);
	pthread_create(&pid4,NULL,(void *)th_fun1,&n4);
	pthread_create(&pid5,NULL,(void *)th_fun1,&n5);
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	pthread_join(pid3,NULL);
	pthread_join(pid4,NULL);
	pthread_join(pid5,NULL);

	return 0;
}
void th_fun1(void * arg){
	int arg_num = *(int *)arg;
	printf("thread function %d\n",arg_num);
}
