#include "bor-util.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int octectLu = 0;

void gestionAlarm(int sig)
{
	
	if(sig == SIGALRM)
	{
		printf("Octect lu %d Ko\n", octectLu);
		alarm(1);
	}
}
int getMax(int p[][2], int size)
{
	int max = 0; 
	
	for(int i = 0; i < size; ++i)
		if(p[i][0] > max)
			max = p[i][0];
			
	return max;
}

int getMaxFils(int p[][2], int size)
{
	int max = 0; 
	
	for(int i = 0; i < size; ++i)
		if(p[i][0] > max)
			max = p[i][1];
			
	return max;
}

int main(int argc, char* argv[])
{
	if(argc != 3) return 1;
	
	int s = atoi(argv[1]);
	int nbtube = atoi(argv[2]);
	
	char buff[s];
	int p[nbtube][2];
	
	for(int i = 0; i < nbtube; ++i)
	{
		if(pipe(p[i]) < 0) {
			perror("pipe");
			return 1;
		}
	}
	
	pid_t pid = fork();
	
	if(pid < 0) 
	{
		perror("fork");
		return 1;
	}
	
	if(pid == 0) { // Fils
		
		bor_signal(SIGALRM, gestionAlarm, SA_RESTART); 
		alarm(1);

		for(int i = 0; i < nbtube; ++i)
			close(p[i][0]);
		
		fd_set set_read;

		while(1){
			
		FD_ZERO(&set_read);

		for(int i = 0; i < nbtube; ++i)
			FD_SET(p[i][1], &set_read);
		
		if(select(getMaxFils(p, nbtube) + 1, &set_read, NULL, NULL, NULL) > 0)
		{
			for(int i = 0; i < nbtube; ++i)
			{
				if(FD_ISSET(p[i][1], &set_read))
				{
					int r = bor_read(p[i][1], &buff, sizeof(buff));
					if(r > 0)
						octectLu = r;
					else
					{
						perror("read");
						exit(1);
					}
				}
			}
		}
	}
	
		for(int i = 0; i < nbtube; ++i)
			close(p[i][1]);
			
		exit(0);
	}
	
	for(int i = 0; i < nbtube; ++i)
		close(p[i][1]);
		
	fd_set set_write;
	
	while(1)
	{
		FD_ZERO(&set_write);
	
		for(int i = 0; i < nbtube; ++i)
			FD_SET(p[i][0], &set_write);
		
		if(select(getMax(p, nbtube) + 1, NULL, &set_write, NULL, NULL) > 0)
		{
			for(int i = 0; i < nbtube; ++i)
			{
				if(FD_ISSET(p[i][0], &set_write))
				{
					int r = bor_write(p[i][0], &buff, sizeof(buff));
					
					if(r < 0)
						exit(1);
				}
			}
		}
	}
	
	for(int i = 0; i < nbtube; ++i)
		close(p[i][0]);
	return 0;
}

