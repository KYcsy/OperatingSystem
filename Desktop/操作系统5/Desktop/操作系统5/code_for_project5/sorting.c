/**
 * Solution to exercise project 2
 *
 * Operating System Concepts - Ninth Edition
 * John Wiley & Sons - 2013.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE				10
#define NUMBER_OF_THREADS	3

void *sorter(void *params);	/* thread that performs basic sorting algorithm */
void *merger(void *params);	/* thread that performs merging of results */

pthread_t thread0, thread1;
char *message0 = "thread0";
char *message1 = "thread1";
int ret_thrd0, ret_thrd1;
ret_thrd0 = pthread_create(&thread0, NULL, (void*)&print_message_function, (void *) message0);
ret_thrd1 = pthread_create(&thread1, NULL, (void*)&print_message_function, (void *) message1);




int list[SIZE] = {7,12,19,3,18,4,2,6,15,8};
int result[SIZE];

typedef struct
{
	int from_index;
	int to_index;
} parameters;

int main (int argc, const char * argv[]) 
{

	
    return 0;
}

/**
 * Sorting thread.
 *
 * This thread can essentially use any algorithm for sorting
 */

void *sorter(void *params)
{
    /* Bubble sort */
    int len=(int)sizeof(list)/sizeof(int);
    int i,j,tmp;
    for (i=0; i<len-1; i++) {
        for (j=0; j<len-1-i; j++) {
            if (list[j]>list[j+1]) {
                tmp=list[j];
                list[j]=list[j+1];
                list[j+1]=tmp;
            }
        }
    }
    

	pthread_exit(0);
}


/**
 * Merge thread
 *
 * Uses simple merge sort for merging two sublists
 */

void *merger(void *params)
{

		
	
	pthread_exit(0);
}

