#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRINT(x) do{ \
    printf(#x " is %d\n", x); \
    }while(0)

int depth = 0;
int l_count = 0;
int r_count = 0;
// If a and b indicate same memory, A XOR B is 0
void Swap(int* a, int* b){
    if( a!= b){
        *a = *a^*b;
        *b = *a^*b;
        *a = *a^*b;
    }
}
/* Feature: During Sorting, Don't manipulate sorted array(left)
 * 1) Find a min value in array
 * 2) Swap the min value and i-element(i=0, 1, ..., max)
 * 3) i++
 * 4) Repeat 1)~3) until ( i >= size of array)
*/
void SelectionSort(int* arr, int size){
    int i, j, min = 0;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++)
            if(arr[j] < arr[min])
                min = j;
        if(min != i)
            Swap(&arr[i], &arr[min]);
    }
}

/* Feature: During Sorting, Don't manipulate sorted array(right)
 * 1) Compare adjacent elements 
 * 2) Large number moves to right(if left element is bigger than right, swap elements)
 * 3) Largest number is set right(there is no necessity of comparing right element) 
 * 4) Repeat 1)~3) until completion of sort
*/
void BubbleSort(int* arr, int size){
    int i, j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j] > arr[j+1])
                Swap(&arr[j], &arr[j+1]);
        }
    }
}

/* /* Feature: During sorting, key moves to right sequentially
 * 1) Set 2nd element as key value
 * 2) Compare adjacent(left) element
 * 3) If key value is lower than left element, move left element to right and move cursor(pointer, index) to left
 * 4) If key value is bigger than left element, insert key value
 * 5) Increase the key's index
 * 6) Repeat 2)~5) until key's index reaches array size 
*/
void InsertionSort(int* arr, int size){
    int i, j, key;
    for(i=1;i<size;i++){
        key = arr[i];//Initailly, 2nd element is key(last key is arr[size-1])
        for(j=i-1; j>=0 && arr[j] > key; j--)
                arr[j+1] = arr[j];// move element to right
        arr[j+1] = key;//Insert key value(if key is lowest value, j = -1, So, j+1 = 0)
    }
}
/* 1) Divide the range of array and call the function by recursion
 * 2) Store the element in temperary array
 * 3) Store the lowest value in origin array
 * 4) Store the remainder of elements in origin array
*/
void Merge(int* arr, int left, int mid, int right){
    int i, j, k=left;
    int n1 = mid -left +1;
    int n2 = right - mid;
    int larr[n1], rarr[n2];

    for(i=0; i<n1; i++)// Copy array
        larr[i] = arr[left+i];
    for(j=0; j<n2; j++)
        rarr[j] = arr[mid+1+j];
    i=0;
    j=0;
    while(i<n1 && j<n2){// Merge of 2 subarray
        if(larr[i] <= rarr[j])
            arr[k++] = larr[i++];
        else
            arr[k++] = rarr[j++];
    }
    while(i < n1)// Copy Remainder
        arr[k++] = larr[i++];
    while(j < n2)
        arr[k++] = rarr[j++];

}
void MergeSort(int* arr, int begin, int end){
    if(begin < end){
        int mid = (begin+end)/2; //== (begin+end)/2   (begin+end)>>1
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, begin, mid, end);
    }
}

int Partition(int* arr, int low, int high){
    //If pivot is last element
    int pivot = arr[high];
    int i = low;
    for(int j=low; j<=high; j++){
        //printf("Progress Partition: i= %d, j= %d \n", i, j);
        if(arr[j] < pivot){
            /*
            printf("Before Swaped Array: ");
            for(int k=0; k<=high; k++)
                printf("%d ", arr[k]);
            printf("\n");
            */
            Swap(&arr[i++], &arr[j]);
            /*
            printf("Swap: arr[i]= %d, arr[j]= %d \n", arr[i-1], arr[j]);
            printf("After Swaped Array: ");
            for(int k=0; k<=high; k++)
                printf("%d ", arr[k]);
            printf("\n");
            */
        }
    }
    //printf("Before Last Swap: i= %d, high= %d, arr[i]=%d, arr[high]=%d \n", i, high, arr[i], arr[high]);
    Swap(&arr[i], &arr[high]);
    /*printf("After Last Swap: i= %d, high= %d, arr[i]=%d, arr[high]=%d \n", i, high, arr[i], arr[high]);
    printf("End Partition Array: ");
    for(int t=0; t<=high; t++)
        printf("%d ", arr[t]);
    printf("\n");
    */
    return (i);
    //If pivot is first element
    /*
    int pivot = arr[low];
    int i = high;
    for(int j = high; j > low; j--){
        if(arr[j] > pivot)
            Swap(&arr[j], &arr[i--]);
    }
    Swap(&arr[low], &arr[i]);
    return i;
    */

   //If pivot is random, Generate int Partition_r(int* arr, int low, int high);
   /*
    srand(time(NULL));
    int random = low + rand() % (high-low);
    Swap(&arr[random], &arr[high]);
    return Partition(arr, low, high);
   */
}
void QuickSort(int* arr, int low, int high){
    if(low < high){
        //printf("Before Partition: low= %d, high= %d \n", low, high);
        int pi = Partition(arr, low, high);
        //printf("After Partition: low= %d, high= %d, pivot=%d\n", low, high, arr[pi]);
        //printf("l_count = %d\n",l_count++);
        QuickSort(arr, low, pi-1);
        //printf("Left QuickSort: low= %d, high(pi-1)= %d \n", low, pi-1);
        //printf("R_count= %d\n",r_count++);
        QuickSort(arr, pi+1, high);
        //printf("Right QuickSort: low(pi+1)= %d, high= %d \n", pi+1, high);
    }
   //If pivot is middle element
   /*
    int i = low, j = high;
    int pivot = arr[(low+high)/2];
    int temp;
    while( i <= j){
        while( arr[i] < pivot)
            i++;
        while( arr[j] > pivot)
            j--;
        if(i <= j){
            Swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if(low < j)
        QuickSort(arr, low, j);
    if( i < high)
        QuickSort(arr, i, high);
   */
}

int main(){
    int temp=0;
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(int);
    QuickSort(arr, 0, n-1);
    while(temp<n)
        PRINT(arr[temp++]);
    return 0;
}