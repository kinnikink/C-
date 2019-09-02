
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <sys/time.h>

using namespace std;

//The number of threads to be created
#define NUMBER_OF_THREADS 4

//function that will serve a role of the thread
void * Sum(void* index);

// function that adds the first 1,000,000 numbers
long numbers[4] = {250000, 500000, 750000, 1000000};
long start_numbers[4] = {1, 250001, 500001, 750001};

//adds the first 10,000 numbers
//long numbers[4] = {2500, 5000, 7500, 10000};
//long start_numbers[4] = {1, 2501, 5001, 7501};

int thread_numbers[4] = {0, 1, 2, 3};

//mutex information
int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//int data_available = 0;
//pthread_cont_t data_cond = PTHREAD_COND_INITIALIZER;

long sum = 0;

int main() {
    pthread_t tid[NUMBER_OF_THREADS]; //thread ID for each thread
    int tn; //number of the thread that is being created
    //long sum = 0; //the final sum
    timeval start_time, end_time; //start time struct and end time struct used to track the microseconds passed during the computation
    double start_time_microseconds, end_time_microseconds;
    gettimeofday(&start_time, NULL);
    start_time_microseconds = start_time.tv_sec * 1000000 + start_time.tv_usec;
    
    //generates the thread
    for(tn = 0; tn < NUMBER_OF_THREADS; tn++) {
        //creates the thread
        if (pthread_create(&tid[tn], NULL, Sum, (void *)&thread_numbers[tn]) == -1 ) {
            perror("thread fail");
            exit(-1);
        }
    }
    
    long value[4]; //value of the sum for each individual thread.
    
    for(int i = 0; i < NUMBER_OF_THREADS; i++) {
        if(pthread_join(tid[i],(void**) &value[i]) == 0) {
            sum; //adds the four sums together
        }
        else {
            perror("Thread join failed");
            exit(-1);
        }
    }
    
    //gets the end time in microseconds
    gettimeofday(&end_time, NULL);
    end_time_microseconds = end_time.tv_sec * 1000000 + end_time.tv_usec;
    
    //calculates the time passed
    double time_passed = end_time_microseconds - start_time_microseconds;
    cout << "Sum is: " << sum << endl;
    cout << "Running time is: " << time_passed << " microseconds" << endl;
    exit(0);
}

//function that calculates the sum
void* Sum(void* index) {
    pthread_mutex_lock(&mutex);
    int temp_index;
    temp_index = *((int*)index);
    
    for(long i = start_numbers[temp_index]; i <= numbers[temp_index]; i++) {
        sum = sum + i;
    }
    cout << "Thread " << temp_index << " terminates" << endl;
    //data_available = 1;
    //pthread_condition_signal(&data_condition);
    pthread_mutex_unlock(&mutex);
    pthread_exit( (void*) sum);
}
void *thread_func(void *arg) {
    int val;
    pthread_mutex_lock(&mutex);
    val = counter;
    counter = val + 1;
    pthread_mutex_unlock(&mutex);
    return NULL;
}
