/*
Counting sort 1
Comparison Sorting 
Quicksort usually has a running time of , but is there an algorithm that can sort even faster? In general, 
this is not possible. Most sorting algorithms are comparison sorts, i.e. they sort a list just by comparing 
the elements to one another. A comparison sort algorithm cannot beat  (worst-case) running time, since  
represents the minimum number of comparisons needed to know where to place each element. For more details, 
you can see these notes (PDF).

Alternative Sorting 
However, for certain types of input, it is more efficient to use a non-comparison sorting algorithm. This will 
make it possible to sort lists even in linear time. These challenges will cover Counting Sort, a fast way to 
sort lists where the elements have a small number of possible values, such as integers within a certain range. 
We will start with an easy task - counting.

Challenge 
Given a list of integers, can you count and output the number of times each value appears?

Hint: There is no need to sort the data, you just need to count it.

Input Format 
There will be two lines of input:

 - the size of the list
 -  space-separated numbers that make up the list
Output Format 
Output the number of times every number from  to  (inclusive) appears on the list.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int *ptr;
    int i;
    int n;

    scanf("%d",&n);
    int arr[n];

    ptr = (int *)calloc(n,sizeof(int));

    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    	ptr[arr[i]]++;
    }

    for(i=0;i<n;i++)
    	printf("%d ",ptr[i]);


    return 0;
}

