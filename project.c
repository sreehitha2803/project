#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 12
#define DELAY_MICROSECONDS 100000
 
void printArray(int arr[],int size,int selected1,int selected2){
    for(int i=0;i<size;i++){
        if(i==selected1||i==selected2){
            printf("\x1b[31m%d \x1b[0m",arr[i]);
        } else{
            printf("%d ", arr[i]);
        }
    }
    printf("\r"); //to move cursor to the front
    fflush(stdout); //removes buffer caudes by the printf statement and prints the next line
} 


void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
} 

void delay(int microseconds) {
    int nanoseconds=microseconds*1000;
    for(int i=0;i<nanoseconds;i++);
}

void bubbleSort(int arr[],int size) {
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]); //swap is user defined function used to swap when if condition is true
                printArray(arr,size,j,j+1); //user defined fn
                delay(DELAY_MICROSECONDS);  //user defined fn
            }
        }
    }
}

int main() {
    srand(time(NULL)); //srand is the built-in function
    int arr[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++) {
        arr[i]=rand()%100; //generates random integer for the array
    }
    printf("original array:");
    printArray(arr,ARRAY_SIZE,-1,-1); //prints the original random array
    printf("\n"); //printing new line

    printf("Sorting array:\n");
    bubbleSort(arr,ARRAY_SIZE);

    printf("\nSorted array:");
    printArray(arr,ARRAY_SIZE,-1,-1);
    printf("\n");

    return 0;
}