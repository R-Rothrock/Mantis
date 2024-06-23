// testing the `setpriority` syscall

#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

#define NICE_VAL -20

int main(int argc, char **argv)
{
	setpriority(PRIO_PROCESS, getpid(), 20);
	perror("test");

	int i;
	long lim = 1000000000; // 1 billion
	while(1)
	{
		printf("Using CPU\n");
		while(1)
		{
			i++;
			if(i >= lim)
				break;
		}
		i = 0;

		printf("Not using CPU\n");
		sleep(2);
	}
}

