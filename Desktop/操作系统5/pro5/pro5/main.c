
//不使用多线程

/**
 * Solution to exercise project 2
 *
 * Operating System Concepts - Ninth Edition
 * John Wiley & Sons - 2013.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define SIZE                10
#define NUMBER_OF_THREADS    3

void sorter0(void);    /* thread that performs basic sorting algorithm */
void sorter1(void);    /* thread that performs basic sorting algorithm */
void merger(void);    /* thread that performs merging of results */
void parlist(void);       /* function that partition the list*/

int list[SIZE] = {7,12,19,3,18,4,2,6,15,8};
int result[SIZE];
int fin0[SIZE/2];
int fin1[SIZE/2];

    



int main (int argc, const char * argv[])
{
    clock_t start, finish;
    double duration;
    parlist();
    
    start = clock();
    sorter0();
    sorter1();
    merger();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "\n%f seconds/n", duration );
    
    //打印result的值，验证排序结果
    printf("\nThe result of list:\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d\t",result[i]);
    }
    return 0;
}

/**
 * Sorting thread.
 *
 * This thread can essentially use any algorithm for sorting
 */

void sorter0()
{
    int len=SIZE/2;
    /* Bubble sort */
    int i,j,tmp;
    for (i=0; i<len-1; i++) {
        for (j=0; j<len-1-i; j++) {
            if (fin0[j]>fin0[j+1]) {
                tmp=fin0[j];
                fin0[j]=fin0[j+1];
                fin0[j+1]=tmp;
            }
        }
    }
    printf("\nThe list of thread 0 after sorting:\n");
    for (int i=0; i<SIZE/2; i++) {
        printf("%d\t",fin0[i]);
    }
}



void sorter1(){
    int len=SIZE/2;
    /* Bubble sort */
    int i,j,tmp;
    for (i=0; i<len-1; i++) {
        for (j=0; j<len-1-i; j++) {
            if (fin1[j]>fin1[j+1]) {
                tmp=fin1[j];
                fin1[j]=fin1[j+1];
                fin1[j+1]=tmp;
            }
        }
    }
    printf("\nThe list of thread 1 after sorting:\n");
    for (int i=0; i<SIZE/2; i++) {
        printf("%d\t",fin1[i]);
    }
}





/**
 * Merge thread
 *
 * Uses simple merge sort for merging two sublists
 */

void merger()
{
    int i=0;
    int j=0;
    while (i<SIZE/2 && j<SIZE/2) {
        if (fin0[i]<fin1[j]) {
            result[i+j]=fin0[i];
            i++;
            continue;
        }
        if (fin0[i]>=fin1[j]) {
            result[i+j]=fin1[j];
            j++;
        }
    }
    
    while (i<SIZE/2) {
        result[i+j]=fin0[i];
        i++;
    }
    while (j<SIZE/2) {
        result[i+j]=fin1[j];
        j++;
    }
}



/**
 * Partiton list
 *
 * Function that partition the list
 */

void parlist(void)
{
    int n;
    for (n=0; n<SIZE/2; n++) { //将list前半部分赋给fin0
        fin0[n]=list[n];
    }
    while (n>=SIZE/2&&n<SIZE) { //将list后半部分赋给fin1
        fin1[n-SIZE/2]=list[n];
        n++;
    }
    /*
    //打印fin0和fin1的值，验证是否分好
    printf("The list of thread 0:\n");
    for (int i=0; i<SIZE/2; i++) {
        printf("%d\t",fin0[i]);
    }
    
    printf("\nThe list of thread 1:\n");
    for (int i=0; i<SIZE/2; i++) {
        printf("%d\t",fin1[i]);
    }
     */
}
