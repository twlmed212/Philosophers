#include <stdio.h>
#include <pthread.h>

// SHARED DATA - All threads can access this!
int shared_counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*increment_counter(void *arg)
{
	int thread_id = *(int *)arg;
	
	// Each thread increments the counter 100,000 times
	for (int i = 0; i < 100000; i++)
	{
        pthread_mutex_lock(&counter_mutex);
        shared_counter++;  // ⚠️ DANGEROUS! Multiple threads touching same data!
        pthread_mutex_unlock(&counter_mutex);
    }
	
	printf("Thread %d finished\n", thread_id);
	return (NULL);
}

int main(void)
{
	pthread_t thread1, thread2, thread3;
	int id1 = 1, id2 = 2, id3 = 3;
    // ⚙️ Initialize the mutex (create the lock)
	printf("Starting counter at: %d\n", shared_counter);
	printf("Expected final value: 300,000 (3 threads × 100,000)\n\n");
	
	pthread_create(&thread1, NULL, increment_counter, &id1);
	pthread_create(&thread2, NULL, increment_counter, &id2);
	pthread_create(&thread3, NULL, increment_counter, &id3);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	
	if (shared_counter == 300000)
		printf("🎉 PERFECT! No increments lost!\n");
	else
		printf("❌ Still lost %d increments\n", 300000 - shared_counter);
	
	// 🧹 Clean up - destroy the mutex
	// pthread_mutex_destroy(&counter_mutex);
	pthread_mutex_destroy(&counter_mutex);
	
	return (0);
}