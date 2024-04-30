/*
* C Program to Implement Selection Sort using Recursion
*/

#include <stdio.h>
#include<stdlib.h> //header file for calloc function we used

void SelectionSort(int*,int,int); //function declaration

int main()
{
    int *arr;  //Pointer variable for the array.
    int size;  //Size of the array block.
    printf("Enter the Size of an Array: ");
    scanf("%d",&size);
    int temp=0;
    arr=(int*)calloc(size,sizeof(int));

    //Allocates as many as size number of blocks and returns the base address.
    if(arr==NULL)
    {
        //If space is insufficient, allocation fails and returns a NULL pointer.
        printf("SPACE COULD NOT BE ALLOCATED\n");
        return 1;  //abnormal termination is specified
    }
    while(temp<size)
    {
        printf("arr[%d] =\t",temp);
        scanf(" %d",&arr[temp]);
        printf("\n");
        temp++;
    }
    printf("\n");
    temp=0;

    //Printing the array before storing of the array.
    printf("Before Sorting\n");
    while(temp<size)
    {
        printf("arr[%d]=%d\n",temp,arr[temp]);
        temp++;
    }
    printf("\n");

    // calling the selection sort function start=0, end=size-1
    SelectionSort(arr,0,size-1);

    printf("After Sorting\n");
    temp=0;
    while(temp<size)
    {
        printf("arr[%d]=%d\n",temp,arr[temp]);
        temp++;
    }
    free(arr);  //free the pointer referenced to blocks of memory in array.
    return 0;
}

//recursive function for selection sort

void SelectionSort(int *arr,int start,int end)
{
    int j;
    int temp;
    int min;  // minimum element of the unordered list is stored in this variable
    //Base case is when start is increased up to end
    if (start==end)
    {
        return ;
    } else {
        min=start;
        //Loop to find minimum element in the unordered set of group.
        for(j=start+1;j<=end;j++) {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
            if(start!=min)
            {
                temp=arr[min];
                arr[min]=arr[start];
                arr[start]=temp;
            }
            //list is ordered by one index and further sorting is done through successive calls.
            SelectionSort(arr,start+1,end);
    }
}
