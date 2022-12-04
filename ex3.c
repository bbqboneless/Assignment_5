#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

void MyAlarm(int);

int main(){
	time_t t;
	time(&t);
	
	printf("Starting time %s\n",ctime(&t));
	
	alarm(30); //timeout after 30 s
	signal(SIGALRM,MyAlarm);
	int c = getchar();
	printf("MyGetchar returned %x\n",c);
	return 0;
}

void MyAlarm(int signum){
	time_t t;
	time(&t);
	printf("Timeout achieved %s:%d\n",ctime(&t),signum);
	exit(1);
}
