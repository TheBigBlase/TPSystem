#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

void q1(int n);
void q2(int n);
void q3();
void q4();
void q5(int, char *[]);

int main(int argc, char* argv[]){
	//printf("#################Q1#################\n");
	//q1(atoi(argv[1]));
	printf("#################Q2#################\n");
	q2(atoi(argv[1]));
	printf("#################Q3#################\n");
	q3();
	//printf("#################Q4#################\n");
	//q4();
	//printf("#################Q5#################\n");
	//q5(argc - 2, argv);
}

void q1(int n){
	pid_t pid = 0;//not 0
	short k;//we need k outside the loop's scope
	for(k = 0; k < n ; k++){
		if((pid = fork()) == 0){//fancy fork
			printf("getpid %d parent %d: k %d\n", getpid(), getppid(), k);
		}
		else {
			break;
		}
	}
	wait(NULL);
	if(k > 0)
		exit(0);//eyy it works now
	//sleep(5); //for pstree / htop observations
}

void q2(int n){
	pid_t pid1;
	pid_t pid2;
	short k; //same as Q1
	for(k = 0 ; k < n ; k++){//depth
		pid1 = fork();
		printf("getpid %d parent %d: k %d\n", getpid(), getppid(), k);
		if(pid1 != 0){
			pid2 = fork();
			printf("getpid %d parent %d: k %d\n", getpid(), getppid(), k);
			if(pid2 != 0){
				break;
			}
		}
	} 
	while(wait(NULL)>0);//wait for both children
	if(k > 0)
		exit(0);
}

void q3(){
	pid_t pid = 0;
	pid = fork();
	if(pid != 0)
		sleep(5); //is it enough
	if(pid == 0)
		exit(0);
	wait(NULL);
}

void q4(){
	int state;
	pid_t pid = fork();
	if(pid ==0) exit(-1);
	wait(&state);
	if(WIFEXITED(state)) //useless since we exit before
		printf("%d\n", WEXITSTATUS(state));
}

void q5(int n, char* argv[]){
	//on utilise des pipes 
	char * pattern = argv[1];

	int fd[2];
	pipe(fd);
	pid_t pid = 0;

	for(char k = 0 ; k < n ; k++){
		char* file = argv[k + 2];
		pid = fork();//j'avais oublié le pid = ca m'a pris 1h
		if(pid == 0){
			dup2(fd[1], STDOUT_FILENO); // send stdout to the pipe
			close(fd[0]);
			close(fd[1]);
			execl("/usr/bin/grep", "grep", pattern, file, '\0');
			exit(0);
		}
		else{
			char buffer[1024];
			close(fd[1]);
			int nbytes = read(fd[0], buffer, sizeof(buffer));
			printf("%.*s\n", nbytes, buffer);
		}	//thx stackoverflow
	}
}
