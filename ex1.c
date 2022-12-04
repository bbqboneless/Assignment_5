#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void MyAlarm(int);

int main(){
	struct sigaction sa;
	struct itimerval timer;
	struct itimerval otimer;

	time_t t;
	time(&t);
	
	printf("Starting time %s\n",ctime(&t));
	
	memset(&sa,0,sizeof(sa));
	sa.sa_handler = &MyAlarm;
	sigaction(SIGVTALRM,&sa,NULL);
	
	timer.it_value.tv_sec = 3;
	timer.it_value.tv_usec = 0; //3 seconds
	
	setitimer(ITIMER_REAL,&timer,NULL);
	
	while(1){}
}

void MyAlarm(int signum){
	time_t t;
	time(&t);
	static int count = 0;
	printf("timer expired %d times (current time %s) \n",++count,ctime(&t));
}
