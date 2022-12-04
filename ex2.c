#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int);

int main(){
	signal(SIGALRM,signal_handler);
	alarm(0.5);
	printf("Loading program...\n");
	
	int c = 5;
	for(int i = 0;i < 20;i++){
		printf("# %d%c\n",c,37);
		c+=5;
		sleep(1);
	}
	
	printf("Progress bar ended succesfully\n");
	
	return 0;
}

void signal_handler(int signum){
	static int cont = 0;
	printf("Inside handler\n");
}
