#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUMBER_OF_PRODUCERS  2
#define NUMBER_OF_CONSUMERS  1
#define NUM_THREADS ((NUMBER_OF_PRODUCERS) + (NUMBER_OF_CONSUMERS))
#define MESSAGE_SLOTS 5

int main (int argc, char *argv[])
{
    int i, rc;
    long t0=0;
    pthread_t threads[NUM_THREADS];
    thread_specific_data_t thread_state[NUM_THREADS];
    pthread_attr_t attr;

     mailbox_t* mailbox = mailbox_new(NUM_THREADS, MESSAGE_SLOTS);
