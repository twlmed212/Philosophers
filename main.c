#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

int main(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	printf("%ld\n", tv.tv_sec * 1000);
	printf("%ld\n", tv.tv_usec/1000);
	

	// converting to the milliseconds
	long int milsec = (tv.tv_sec * 100) + (tv.tv_usec / 1000);
	printf("milliseconds passed since 1970 %ld", milsec);
	return (0);
}