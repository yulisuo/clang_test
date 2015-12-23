#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void thread1();
void thread2();
int num = 100;
int main(void){
	pthread_t pid1,pid2;
	pthread_create(&pid1,NULL,(void *)thread1,NULL);
	pthread_create(&pid2,NULL,(void *)thread2,NULL);
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	printf("num = %d\n",num);
	return 0;
}
void thread1(){
	int i = 0;
	while(i < 10){
		int temp = num + 1;
		sleep(1);
		num = temp;
		i++;
	}
}
void thread2(){
	int i = 0;
	while(i < 10){
		int temp = num - 1;
		sleep(1);
		num = temp;
		i++;
	}
}
