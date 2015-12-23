#include <stdio.h>
#include <pthread.h>

void th_fun1();
void th_fun2();
void th_fun3();
void th_fun4();
void th_fun5();
void th_fun_struct(void * arg);
int num = 0;

struct Stu{
	int num;
	char c;
};


int main(void){
	pthread_t pid1,pid2,pid3,pid4,pid5,pid6;
	int n1 = 1,n2 = 2,n3 = 3,n4 = 4,n5 = 5;
	pthread_create(&pid1,NULL,(void *)th_fun1,&n1);
	pthread_create(&pid2,NULL,(void *)th_fun2,&n2);
	pthread_create(&pid3,NULL,(void *)th_fun3,&n3);
	pthread_create(&pid4,NULL,(void *)th_fun4,&n4);
	pthread_create(&pid5,NULL,(void *)th_fun5,&n5);
	struct Stu s1;
	s1.num = 9;
	pthread_create(&pid6,NULL,(void *)th_fun_struct,(void *)&s1);
	
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	pthread_join(pid3,NULL);
	pthread_join(pid4,NULL);
	pthread_join(pid5,NULL);
	
	printf("main num:%d\n",num);

	return 0;
}
void th_fun_struct(void * arg){
	struct Stu * sp = (struct Stu *)arg;
	int n = sp->num;
	printf("-------th_fun_struct------:%d\n",n);
}
void th_fun1(void * arg){
	int arg_num = *(int *)arg;
	int i = 0;
	while(i < 10){
		printf("thread function %d ,i:%d.\n",arg_num,i);
		//sleep(1);
		num += 1;
		i++;
	}
	printf("thread function %d end.\n",arg_num);
}
void th_fun2(void * arg){
	int arg_num = *(int *)arg;
	int i = 0;
	while(i < 10){
		printf("thread function %d ,i:%d.\n",arg_num,i);
		//sleep(1);
		num += 1;
		i++;
	}
	printf("thread function %d end.\n",arg_num);
}
void th_fun3(void * arg){
	int arg_num = *(int *)arg;
	int i = 0;
	while(i < 10){
		printf("thread function %d ,i:%d.\n",arg_num,i);
		//sleep(1);
		num += 1;
		i++;
	}
	printf("thread function %d end.\n",arg_num);
}
void th_fun4(void * arg){
	int arg_num = *(int *)arg;
	int i = 0;
	while(i < 10){
		printf("thread function %d ,i:%d.\n",arg_num,i);
		//sleep(1);
		num += 1;
		i++;
	}
	printf("thread function %d end.\n",arg_num);
}
void th_fun5(void * arg){
	int arg_num = *(int *)arg;
	int i = 0;
	while(i < 10){
		printf("thread function %d ,i:%d.\n",arg_num,i);
		//sleep(1);
		num += 1;
		i++;
	}
	printf("thread function %d end.\n",arg_num);
}
