/*
	线程属性
	1.属性对象主要包括是否绑定、是否分离、堆栈地址、堆栈大小、优先级。默认的属性为非绑定、非分离、缺省1M的堆栈、与父进程同样级别的优先级。
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void thread1(){
	int i = 0;
	sleep(2);
	for(;i <= 3;i++){
		printf("this is thread function.\n");
	}
}
/*
int main(void){
	pthread_t pid1;
	pthread_create(&pid1,NULL,(void *)thread1,NULL);
	int i;
	for(i = 0;i <= 3;i++){
		printf("this is main function.\n");
	}
	pthread_join(pid1,NULL);
	return 0;
}
*/
//线程属性：绑定
int main(void){
	pthread_t pid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	pthread_create(&pid,&attr,(void *)thread1,NULL);
	pthread_join(pid,NULL);
	return 0;
}
