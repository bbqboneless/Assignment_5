#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

int fork_exec(const char *);

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("Usage: %s...\n",argv[0]);
		return(-1);
	}
	int i;
	
	for(i = 0; i < argc;i++){
		fork_exec(argv[i]);
		return 0;
	}
}

int fork_exec(const char *com){
	int status;
	pid_t pid;
	
	pid = fork();
	
	if(pid == 0){
		//child process
		system(com);
		//when child process is completed
		exit(EXIT_SUCCESS);
	}else if(pid < 0){
		printf("Fork failed: %s\n",com);
		status = -1;
	}else if(waitpid(pid,&status,0) != pid){
		status = -1;
		return status;
	}
}
