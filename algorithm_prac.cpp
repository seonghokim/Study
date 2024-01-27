#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <queue>
using namespace std;
//#include <bits/stdc++.h>
// 자동 정렬 shift + alt + F
// 커서영역 선택 Shft + alt + left 
// 1수준 접기 ctrl shift alt a  --> 모든 수준 ( 모든 커서 닫기 ctrl shift alt s)
// 모두 펼치기 ctrl shift alt d
#define INTPRINT(x)               \
    do                            \
    {                             \
        printf(#x " is %d\n", x); \
    } while (0)
#define FLOATPRINT(x)               \
    do                              \
    {                               \
        printf(#x " is %.3f\n", x); \
    } while (0)
#define THRESHOLD 2
// int depth = 0;
// int l_count = 0;
// int r_count = 0;
int FindMax(int *arr, int size)
{
    int i;
    int max = arr[0];
    for (i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

typedef int (*CompareFunction)(const void *, const void *);

int CompareInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int CompareFloat(const void *a, const void *b)
{
    float diff = (*(float *)a - *(float *)b);
    return ((diff > 0) ? 1 : ((diff < 0) ? -1 : 0));
}
int CompareDouble(const void *a, const void *b)
{
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0 ? 1 : (diff < 0 ? -1 : 0));
}

// If a and b indicate same memory, A XOR B is 0
void Swap(void *a, void *b)
{
    if ((a != b))
    {
        *(int *)a = *(int *)a ^ *(int *)b;
        *(int *)b = *(int *)a ^ *(int *)b;
        *(int *)a = *(int *)a ^ *(int *)b;
    }
}

int Min(void *a, void *b)
{
    return *(int *)a < *(int *)b ? *(int *)a : *(int *)b;
}
int Max(void *a, void *b)
{
    return *(int *)a > *(int *)b ? *(int *)a : *(int *)b;
}
void CompSwap(int *a, int *b)
{
    if (*a > *b)
    {
        Swap(a, b);
    }
}

typedef struct Tree
{
    int key;
    struct Tree *left;
    struct Tree *right;
    struct Tree *nextRight;
} Tree;
typedef struct DNode // Double Linked List Node
{
    int data;
    struct DNode *next;
    struct DNode *prev;
} DNode;


//----------------------------------------
//----------------- Sort -----------------
//----------------------------------------
/* Feature: During Sorting, Don't manipulate sorted array(left)
 * 1) Find a min value in array
 * 2) Swap the min value and i-element(i=0, 1, ..., max)
 * 3) i++
 * 4) Repeat 1)~3) until ( i >= size of array)
 */
void SelectionSort(int *arr, int size)
{
    int i, j, min = 0;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            Swap(&arr[i], &arr[min]);
    }
}

/* Feature: During Sorting, Don't manipulate sorted array(right)
 * 1) Compare adjacent elements
 * 2) Large number moves to right(if left element is bigger than right, swap elements)
 * 3) Largest number is set right(there is no necessity of comparing right element)
 * 4) Repeat 1)~3) until completion of sort
 */
void BubbleSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
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
void InsertionSort(int *arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i]; // Initailly, 2nd element is key(last key is arr[size-1])
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j]; // move element to right
        arr[j + 1] = key;        // InsertTree key value(if key is lowest value, j = -1, So, j+1 = 0)
    }
}
void PartialInsertion(int *arr, int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i += gap)
    {
        key = arr[i];
        for (j = i - gap; j >= first && arr[j] > key; j -= gap)
            arr[j + gap] = arr[j];
        arr[j + gap] = key;
    }
}

/* 1) Divide the range of array and call the function by recursion
 * 2) Store the element in temperary array
 * 3) Store the lowest value in origin array
 * 4) Store the remainder of elements in origin array
 */
void Merge(int *arr, int left, int mid, int right)
{
    int i, j, k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int larr[n1], rarr[n2];

    for (i = 0; i < n1; i++) // Copy array
        larr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rarr[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    { // Merge of 2 subarray
        if (larr[i] <= rarr[j])
            arr[k++] = larr[i++];
        else
            arr[k++] = rarr[j++];
    }
    while (i < n1) // Copy Remainder
        arr[k++] = larr[i++];
    while (j < n2)
        arr[k++] = rarr[j++];
}
void MergeSort(int *arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2; //== (begin+end)/2   (begin+end)>>1
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, begin, mid, end);
    }
}

/* 1) Based on the pivot, values smaller than the pivot move to the left, and values larger than the pivot move to the right.
 * 2) Divide the array into 2 section.
 * 3) In each section, set the new pivot and repeat 1)~2) progress.
 * 4) In section, if element is only one, exit after sorting.
 */
int Partition(int *arr, int low, int high)
{
    // If pivot is last element
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high; j++)
    {
        // printf("Progress Partition: i= %d, j= %d \n", i, j);
        if (arr[j] < pivot)
        {
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
    // printf("Before Last Swap: i= %d, high= %d, arr[i]=%d, arr[high]=%d \n", i, high, arr[i], arr[high]);
    Swap(&arr[i], &arr[high]);
    /*printf("After Last Swap: i= %d, high= %d, arr[i]=%d, arr[high]=%d \n", i, high, arr[i], arr[high]);
    printf("End Partition Array: ");
    for(int t=0; t<=high; t++)
        printf("%d ", arr[t]);
    printf("\n");
    */
    return (i);
    // If pivot is first element
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

    // If pivot is random, Generate int Partition_r(int* arr, int low, int high);
    /*
     srand(time(NULL));
     int random = low + rand() % (high-low);
     Swap(&arr[random], &arr[high]);
     return Partition(arr, low, high);
    */
}
void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        // printf("Before Partition: low= %d, high= %d \n", low, high);
        int pi = Partition(arr, low, high);
        // printf("After Partition: low= %d, high= %d, pivot=%d\n", low, high, arr[pi]);
        // printf("l_count = %d\n",l_count++);
        QuickSort(arr, low, pi - 1);
        // printf("Left QuickSort: low= %d, high(pi-1)= %d \n", low, pi-1);
        // printf("R_count= %d\n",r_count++);
        QuickSort(arr, pi + 1, high);
        // printf("Right QuickSort: low(pi+1)= %d, high= %d \n", pi+1, high);
    }
    // If pivot is middle element
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

/* 1) Build Heap by Heapify()
 * 2) In Heapify(), current element is lower than child Tree, swap value
 * 3) Repeat 2) by recursion
 * 4) Extract root element(max value) by swap root Tree and last Tree, and execute heapify() except last element.
 */
void Heapify(int *arr, int size, int cur_idx)
{
    int max = cur_idx;
    int left = 2 * cur_idx + 1;
    int right = 2 * cur_idx + 2;
    if (left < size && arr[left] > arr[max])
        max = left;
    if (right < size && arr[right] > arr[max])
        max = right;
    if (max != cur_idx)
    {
        Swap(&arr[cur_idx], &arr[max]);
        Heapify(arr, size, max);
    }
}
void HeapSort(int *arr, int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        Heapify(arr, size, i);
    for (i = size - 1; i > 0; i--)
    {
        Swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}

/* 1) Find max value in array
 * 2) InsertTree the number of element's value into temperary array
 * 3) Find the cumlative sum of temperary array by arr[i] +=arr[i-1];
 * 4) Trace the location that input-array element's value equal to temperary array's index.
 * 5) Find the index of output-array that is same as the result of (element's value of temperary array -1), copy the value of input array element
 * */
void CountingSort(int *arr, int size)
{
    int max = FindMax(arr, size);
    int i;
    int count[max + 1] = {
        0,
    };
    int result[size] = {
        0,
    };
    for (i = 0; i < size; i++)
        count[arr[i]]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < size; i++)
        arr[i] = result[i];
}

/* 1) Using units digit, execute CountingSort()
 * 2) Multiple exponential to 10 until reaching most significant digit
 */
void ExpCountSort(int *arr, int size, int exp)
{
    const int radix = 10;
    int i;
    int count[radix] = {
        0,
    };
    int result[size] = {
        0,
    };

    for (i = 0; i < size; i++)
        count[(arr[i] / exp) % radix]++;
    for (i = 1; i < radix; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
    {
        result[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }
    for (i = 0; i < size; i++)
        arr[i] = result[i];
}
void RadixSort(int *arr, int size)
{
    int max = FindMax(arr, size);
    int exp = 1;
    while (max / exp > 0)
    {
        ExpCountSort(arr, size, exp);
        exp *= 10;
    }
}

/* 1) Make bucket array
 * 2) Inset element in bucket array
 * 3) In each bucket array, sort elements
 * 4) Assign the sorted element in array sequentially
 */
void BucketSort(int *arr, int size, int type_size, CompareFunction cmp)
{
    // 최댓값과 최솟값을 찾아 범위를 구합니다.
    int max = 0, min = 0;
    for (int i = 1; i < size; i++)
    {
        if (cmp((char *)arr + i * type_size, (char *)arr + max * type_size) > 0)
            max = i;
        if (cmp((char *)arr + i * type_size, (char *)arr + min * type_size) < 0)
            min = i;
    }

    // 최댓값과 최솟값을 각각 복사합니다.
    void *maxElem = malloc(type_size);
    void *minElem = malloc(type_size);
    memcpy(maxElem, (char *)arr + max * type_size, type_size);
    memcpy(minElem, (char *)arr + min * type_size, type_size);

    // 범위의 크기 (최댓값과 최솟값을 모두 포함)
    int range = *(int *)maxElem - *(int *)minElem + 1;

    // 범위에 해당하는 각각의 버킷을 생성하고 초기화합니다.
    void **b = (void **)malloc(range * sizeof(void *));
    int *b_size = (int *)malloc(range * sizeof(int)); // 각 버킷의 크기를 저장하는 배열
    for (int i = 0; i < range; i++)
    {
        b[i] = malloc(size * type_size);
        b_size[i] = 0; // 초기화
    }

    // 각 요소를 적절한 버킷에 할당합니다.
    for (int i = 0; i < size; i++)
    {
        int b_idx = cmp((char *)arr + i * type_size, minElem);
        memcpy((char *)b[b_idx] + b_size[b_idx] * type_size, (char *)arr + i * type_size, type_size);
        b_size[b_idx]++;
    }

    // 각 버킷을 정렬합니다.
    for (int i = 0; i < range; i++)
        qsort(b[i], b_size[i], type_size, cmp);

    // 정렬된 각 버킷을 원래 배열에 복사합니다.
    int idx = 0;
    for (int i = 0; i < range; i++)
    {
        memcpy((char *)arr + idx * type_size, b[i], b_size[i] * type_size);
        idx += b_size[i];
    }

    // 메모리를 해제합니다.
    free(maxElem);
    free(minElem);
    for (int i = 0; i < range; i++)
        free(b[i]);
    free(b);
    free(b_size);
}
void FBucketSort(float *farr, int fn)
{
    std::vector<float> b[fn];
    int i = 0, bi, idx, j;
    for (i = 0; i < fn; i++)
    {
        bi = fn * farr[i];
        b[bi].push_back(farr[i]);
    }
    for (i = 0; i < fn; i++)
        std::sort(b[i].begin(), b[i].end());
    idx = 0;
    for (i = 0; i < fn; i++)
        for (j = 0; j < b[i].size(); j++)
            farr[idx++] = b[i][j];
}

/* 1) Find min, max value in array
 * 2) Find bingo in array
 * 3) Swap bingo and arr[i](i= 0, 1, 2, ..., size-1)
 *
 */
void BingoSort(int *arr, int size)
{
    int b = arr[0];
    int nb = arr[0];
    int i;
    int max, n_pos, s_pos;
    for (i = 1; i < size; i++)
    {
        b = (b < arr[i]) ? b : arr[i];    // min value
        nb = (nb > arr[i]) ? nb : arr[i]; // max value
    }
    max = nb;
    n_pos = 0;
    while (b < nb)
    {
        s_pos = n_pos;
        for (i = s_pos; i < size; i++)
        {
            if (arr[i] == b)
            {
                Swap(&arr[i], &arr[n_pos]);
                n_pos++;
            }
            else if (arr[i] < nb)
                nb = arr[i];
        }
        b = nb;
        nb = max;
    }
}

/* 1) Divide array by gap
 * 2) In each section, execute sorting
 * 3) Divide gap by 2
 * 4) Repeat 2)~3) until gap is 0
 */
// Using interval sequence for calculating interval
int CalculateGap(int size)
{
    int h = 1;
    while (h < size / 3)
        h = 3 * h + 1;
    return h;
}
void ShellSort(int *arr, int size)
{
    int gap, i, key, j;
    // If not use CalculateGap(), use "gap = size/2; gap > 0; gap/=2" in for()
    // If use CalculateGap(), use "gap = CalculateGap(size); gap > 0; gap /= 3" in for()
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            key = arr[i];
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = key;
        }
    }
}

/* 1) Execute partial insertion sort
 * 2) Execute merge()
 */
void TimSort(int *arr, int size)
{
    int i, j, left, mid, right;
    for (i = 0; i < size; i += THRESHOLD)
        PartialInsertion(arr, i, (i + THRESHOLD - 1 < size - 1) ? (i + THRESHOLD - 1) : (size - 1), 1);
    for (j = THRESHOLD; j < size; j *= 2)
    {
        for (left = 0; left < size; left += 2 * j)
        {
            mid = left + j - 1;
            right = (left + 2 * j - 1 < size - 1) ? (left + 2 * j - 1) : (size - 1);
            Merge(arr, left, mid, right);
        }
    }
}

/*
 *
 *
 *
 */
void CombSort(int *arr, int size)
{
    int gap = size;
    int i;
    bool swapped = true;
    while (gap > 1 || swapped)
    {
        if (gap > 1)
            gap = gap * 10 / 13;
        else
            gap = 1;
        swapped = false;
        for (i = 0; i + gap < size; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                Swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}

/*
 *
 *
 *
 */
void PigeonholeSort(int arr[], int size)
{
    int min = arr[0], max = arr[0];
    int i, index;
    int p_size;
    int *p_hole;
    for (i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    p_size = max - min + 1;
    p_hole = (int *)malloc(p_size * sizeof(int));
    for (i = 0; i < p_size; i++)
        p_hole[i] = 0;
    for (i = 0; i < size; i++)
        p_hole[arr[i] - min]++;
    index = 0;
    for (i = 0; i < p_size; i++)
    {
        while (p_hole[i] > 0)
        {
            arr[index++] = i + min;
            p_hole[i]--;
        }
    }
    free(p_hole);
}

/*
 *
 *
 *
 */
void CycleSort(int *arr, int size)
{
    int c_start, item, pos, i;
    for (c_start = 0; c_start < size - 1; c_start++)
    {
        item = arr[c_start];
        pos = c_start;
        for (i = c_start + 1; i < size; i++) // 해당 원소의 정확한 위치 찾기
            if (arr[i] < item)
                pos++;
        if (pos == c_start) // 이미 제자리에 있는 경우 건너뛰기
            continue;
        while (item == arr[pos]) // 현재 원소를 올바른 위치로 이동
            pos++;
        Swap(&arr[pos], &item);
        while (pos != c_start)
        { // 나머지 순환 도는 부분 처리
            pos = c_start;
            for (i = c_start + 1; i < size; i++)
                if (arr[i] < item)
                    pos++;
            while (item == arr[pos])
                pos++;
            Swap(&arr[pos], &item);
        }
    }
}
// Condition: Array size: N
//            Input range: 1~N or 0~N
void CycleSort2(int *arr, int size)
{
    int i = 0;
    int correct = 1;
    while (i < size)
    {
        correct = arr[i] - 1;
        if (i != correct)
            Swap(&arr[i], &arr[correct]);
        else
            i++;
    }
}

/*
 *
 *
 *
 */
void cocktailSort(int *arr, int size)
{
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped)
    { // 오른쪽 방향으로 배열을 통과하면서 큰 값들을 정렬
        swapped = false;
        for (int i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                Swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        // 가장 큰 값이 마지막에 위치하도록 end 값을 감소
        end--;
        // 왼쪽 방향으로 배열을 통과하면서 작은 값들을 정렬
        swapped = false;
        for (int i = end - 1; i >= start; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                Swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        // 가장 작은 값이 첫 번째에 위치하도록 start 값을 증가
        start++;
    }
}

void BitonicMerge(int arr[], int low, int cnt, int dir)
{
    int i, k;
    if (cnt > 1)
    {
        k = cnt / 2;
        for (i = low; i < low + k; i++)
            if ((arr[i] > arr[i + k]) == (dir == 1))
                Swap(&arr[i], &arr[i + k]);
        BitonicMerge(arr, low, k, dir);
        BitonicMerge(arr, low + k, k, dir);
    }
}
void BitonicSort(int *arr, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        // 비트단위로 정렬하는 함수 호출 (증가하는 순서)
        BitonicSort(arr, low, k, 1);
        // 비트단위로 정렬된 배열을 역순으로 정렬하는 함수 호출 (감소하는 순서)
        BitonicSort(arr, low + k, k, 0);
        // 비트단위로 정렬된 두 배열을 합병
        BitonicMerge(arr, low, cnt, dir);
    }
}



//----------------------------------------
//----------------- Array ----------------
//----------------------------------------
void TowerOfHanoi(int num, char from, char temp, char to)
{
    if (!num)
        return;
    TowerOfHanoi(num - 1, from, to, temp);
    printf("Move %d from %c to %c\n", num, from, to);
    TowerOfHanoi(num - 1, temp, from, to);
}

void ReverseArray(int *arr, int start, int end)
{
    int temp;
    while (start < end)
    {
        Swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}
void ReverseString(char *str)
{
    int n = strlen(str);
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}
void RotateArray(int *arr, int dist, int size, bool dir, bool temp_arr)
{
    int i, j;
    int temp[dist];
    int last;
    dist %= size;
    if (dist > (size / 2))
    {
        dir = !dir;
        dist = size - dist;
    }
    if (temp_arr == false)
    {
        if (dir == false)
        {
            for (i = 0; i < dist; i++)
            { // Direction: left
                last = arr[0];
                for (j = 0; j < size - 1; j++)
                    arr[j] = arr[j + 1];
                arr[size - 1] = last;
            }
        }
        else if (dir == true)
        { // Direction: right
            for (i = 0; i < dist; i++)
            {
                last = arr[size - 1];
                for (j = size - 1; j > 0; j--)
                    arr[j] = arr[j - 1];
                arr[0] = last;
            }
        }
    }
    else if (temp_arr == true)
    {
        if (dir == 0)
        {
            for (i = 0; i < dist; i++) // Direction: left
                temp[i] = arr[i];
            for (i = 0; i < size - dist; i++)
                arr[i] = arr[i + dist];
            for (i = size - dist; i < size; i++)
                arr[i] = temp[i - (size - dist)];
        }
        else if (dir == 1)
        { // Direction: right
            for (i = 0; i < dist; i++)
                temp[i] = arr[size - dist + i];
            for (i = size - 1; i >= dist; i--)
                arr[i] = arr[i - dist];
            for (i = 0; i < dist; i++)
                arr[i] = temp[i];
        }
    }
}
/* Supoose size = 15, dist = 10, arr[i]
 * arr[0] = arr[10] <-- move right like arr[0] -> arr[5] -> arr[10] -> arr[0]
 * arr[10] = arr[5]
 * arr[5] = arr[0]
 * i++
 */
void RotateArrayJuggling(int *arr, int dist, int size, bool dir)
{
    int interval = GCD(size, dist);
    int i, j, k, temp;
    dist %= size;
    if (dist > (size / 2))
    {
        dir = !dir;
        dist = size - dist;
    }
    if (dir == false)
    { // Direction: left
        for (i = 0; i < interval; i++)
        {
            temp = arr[i];
            j = i;
            while (1)
            {
                k = (j + dist) % size;
                if (k == i)
                    break;
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }
    }
    else if (dir == true)
    { // Direction: right
        for (i = 0; i < interval; i++)
        {
            temp = arr[size - 1 - i];
            j = size - 1 - i;
            while (1)
            {
                k = (j - dist + size) % size;
                if (k == size - 1 - i)
                    break;
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }
    }
}
void RotateArrayReversal(int *arr, int dist, int size, bool dir)
{
    dist %= size;
    if (dist > (size / 2))
    {
        dir = !dir;
        dist = size - dist;
    }
    // left d + right d' = size, ex) size = 6, d=2, d'=4
    if (dir == false)
    { // Direction: left
        ReverseArray(arr, 0, dist - 1);
        ReverseArray(arr, dist, size - 1);
        ReverseArray(arr, 0, size - 1); // Location: last
    }
    else if (dir == true)
    {                                   // Direction: right
        ReverseArray(arr, 0, size - 1); // Location: first
        ReverseArray(arr, 0, dist - 1);
        ReverseArray(arr, dist, size - 1);
    }
}

// Even element is bigger than adjacent odd element
void WaveSort(int *arr, int size)
{
    int i;
    BubbleSort(arr, size);
    for (i = 0; i < size - 1; i += 2)
        Swap(&arr[i], &arr[i + 1]);
}

int BinarySearch(int *arr, int low, int high, int key)
{
    int mid = (low + high) / 2;
    if (high < low)
        return -1;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return BinarySearch(arr, mid + 1, high, key);
    return BinarySearch(arr, low, mid - 1, key);
}
int InsertSortedArray(int *arr, int size, int key, int cap)
{
    int i;
    if (size > cap)
        return size;
    for (i = size - 1; (i >= 0 && arr[i] > key); i--)
        arr[i + 1] = arr[i];
    arr[i + 1] = key;
    return (size + 1);
}
int DeleteElement(int *arr, int size, int key)
{
    int pos = BinarySearch(arr, 0, size - 1, key);
    int i;
    if (pos == -1)
        return size;
    for (i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    return size - 1;
}
void RemoveCharInString(char *s, char c)
{
    int i, j, n = strlen(s);
    for (i = j = 0; i < n; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int *CreateDiffArray(int *arr, int size)
{
    int *diffarr = (int *)malloc(size * sizeof(int));
    int i;
    diffarr[0] = arr[0];
    for (i = 0; i < size; i++)
        diffarr[i] = arr[i] - arr[i - 1];
    return diffarr;
}
void UpdateDiffArray(int *arr, int left, int right, int value, int size)
{
    arr[left] += value;
    if (right + 1 < size)
        arr[right + 1] -= value;
}
void PrintDiffArray2Array(int *arr, int size)
{
    int i;
    printf("%d ", arr[0]);
    for (i = 1; i < size; i++)
    {
        arr[i] += arr[i - 1];
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int MaxProfit2BuySell(int *price, int size, int option)
{
    if (option == 0)
    {
        int *profit = (int *)malloc(size * sizeof(int));
        int i, result;
        int max = price[size - 1];
        int min = price[0];
        for (i = 0; i < size; i++)
            profit[i] = 0;
        for (i = size - 2; i >= 0; i--)
        {
            if (price[i] > max)
                max = price[i];
            profit[i] = __max(profit[i + 1], max - price[i]);
        }
        for (i = 1; i < size; i++)
        {
            if (price[i] < min)
                min = price[i];
            profit[i] = __max(profit[i - 1], profit[i] + (price[i] - min));
        }
        result = profit[size - 1];
        free(profit);
        return result;
    }
    if (option == 1)
    {
        int first_buy = INT_MIN;
        int first_sell = 0;
        int second_buy = INT_MIN;
        int second_sell = 0;
        int i;
        /* 이해하기
         1) 대출을 통해 첫 주식 구매 ==> first_buy 음수값(최솟 값으로 구매)
         2) 첫 주식 판매 ==> first_buy 양수(차액을 max로)
         3) 2번째 주식 구매 ==> 주식 구매 대출(min)+1차 차액(max)
         4) 2번째 주식 판매 ==> 최대 이익
        */
        for (i = 0; i < size; i++)
        {                                                              // buy value is negative number
            first_buy = __max(first_buy, -price[i]);                   // 제일 작은 값
            first_sell = __max(first_sell, (price[i] + first_buy));    // max 차액
            second_buy = __max(second_buy, (-price[i] + first_sell));  //  첫 차액 최대값-작은 값으로 구매
            second_sell = __max(second_sell, (price[i] + second_buy)); // max 차액
        }
        return second_sell;
    }
    return 0;
}

int SubArraySum(int *arr, int size, int sum)
{
    int c_sum = arr[0], start = 0, i;
    for (i = 1; i <= size; i++)
    {
        while (c_sum > sum && start < i - 1)
        {
            c_sum -= arr[start];
            start++;
        }
        if (c_sum == sum)
            return 1;
        if (i < size)
            c_sum += arr[i];
    }
    return 0;
}
int SmallestSubArraySum(int *arr, int size, int sum)
{
    int c_sum = 0, min_len = size + 1;
    int start = 0, end = 0;
    while (end < size)
    {
        while (c_sum <= sum && end < size)
            c_sum += arr[end++];
        while (c_sum > sum && start < size)
        {
            if (end - start < min_len)
                min_len = end - start;
            c_sum -= arr[start++];
        }
    }
    return min_len;
}

void Sort012(int *arr, int size)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            Swap(&arr[low++], &arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            Swap(&arr[mid], &arr[high--]);
            break;
        }
    }
}

void TwoArrayMerge(int *arr1, int *arr2, int size1, int size2)
{
    int len = size1 + size2;
    int gap = len / 2 + (len % 2); // ceiling gap
    int left, right;
    while (gap > 0)
    {
        left = 0;
        right = left + gap;
        while (right < len)
        {
            if (left < size1 && right >= size1)
                CompSwap(&arr1[left], &arr2[right - size1]);
            else if (left >= size1 && right >= size1)
                CompSwap(&arr2[left - size1], &arr2[right - size1]);
            else
                CompSwap(&arr1[left], &arr1[right]);
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int PairSum(int *arr, int size, int x)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return 1;
        else if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }
    return 0;
}
int FindPeak(int *arr, int size)
{
    int l = 0;
    int r = size - 1;
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == size - 1 || arr[mid + 1] <= arr[mid]))
            break;
        if (mid > 0 && arr[mid - 1] > arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return mid;
}
int *FindAllPeak(int *arr, int size, int *count)
{
    int *peak = NULL;
    int i;
    *count = 0;
    for (i = 0; i < size; i++)
    {
        if ((i == 0 || arr[i - 1] <= arr[i]) && (i == size - 1 || arr[i] >= arr[i + 1]))
        {
            (*count)++;
            peak = (int *)realloc(peak, (*count) * sizeof(int));
            peak[(*count) - 1] = arr[i];
        }
    }
    return peak;
}

int Equilibrium(int *arr, int size)
{
    int sum = 0;
    int l_sum = 0;
    int i;
    for (i = 0; i < size; i++)
        sum += arr[i];
    for (i = 0; i < size; i++)
    {
        // input array example: 1 2 3 4 5 10
        sum -= arr[i]; // 25--> 24 22 19 15 10 0
        if (l_sum == sum)
            return i;
        l_sum += arr[i]; //      1  3  6 10 15
    }
    return -1;
}

#define MAXN 10000
#define SQRSIZE 100
int oarr[MAXN];     // original array
int block[SQRSIZE]; // decomposed array
int blk_sz;         // block size
void UpdateBlock(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - oarr[idx];
    oarr[idx] = val;
}
int ArrayQuery(int l, int r)
{
    int sum = 0;
    while (l < r and l % blk_sz != 0 and l != 0)
        sum += oarr[l++];
    while (l + blk_sz - 1 <= r)
    {
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
        sum += oarr[l++];
    return sum;
}
void BlockPreprocess(int input[], int n)
{
    int blk_idx = -1, i;
    blk_sz = sqrt(n);
    for (i = 0; i < n; i++)
    {
        oarr[i] = input[i];
        if (i % blk_sz == 0)
            blk_idx++;
        block[blk_idx] += oarr[i];
    }
}

//----------------------------------------
//---------------- String ----------------
//----------------------------------------
bool IsSameBitBySingleFlip(char *str, int size)
{
    int zero = 0, one = 0;
    char *ch;
    for (ch = str; *ch != '\0'; ++ch)
        (*ch == '0') ? ++zero : ++one;
    return (zero == 1 || one == 1);
}

int FindFlips(char *str, int n)
{
    char last = ' ';
    int count = 0, i;
    for (i = 0; i < n; i++)
    {
        if (last != str[i])
            count++;
        last = str[i];
    }
    return count / 2;
}

void Int2Gray(int n)
{
    int i, j, val;
    for (i = 0; i < (1 << n); i++)
    {
        val = (i ^ (i >> 1)); // Gray code Transform
        for (j = n - 1; j >= 0; j--)
            printf("%d", (val >> j) & 1);
        printf(" ");
    }
    printf("\n");
}
int GrayDecimal2Decimal(int gray)
{
    int inv = 0;
    for (; gray != 0; gray >>= 1)
        inv ^= gray;
    return inv;
}

void Int2BinChar(char *s, int n)
{
    int temp, index = 0, start, end;
    while (n)
    {
        temp = n % 2;
        s[index++] = temp + '0';
        n >>= 1;
    }
    s[index] = '\0';
    for (start = 0, end = index - 1; start < end; ++start, --end)
        Swap(&s[start], &s[end]);
}
int FindChar(int input, int nRepeat, int f_index)
{
    char str[100];
    char temp[200];
    int i, j, t_index;
    Int2BinChar(str, input);
    for (i = 0; i < nRepeat; i++)
    {
        t_index = 0;
        for (j = 0; j < f_index; j++)
        {
            if (str[j] == '1')
            {
                temp[t_index++] = '1';
                temp[t_index++] = '0';
            }
            else
            {
                temp[t_index++] = '0';
                temp[t_index++] = '1';
            }
        }
        temp[t_index] = '\0';
        strcpy(str, temp);
    }
    return str[f_index] - '0';
}

void PrintAllSubString(char *str, int len)
{
    int i, j, idx = 0;
    for (i = 0; i < len; i++)
    {
        char temp[len - i + 1];
        idx = 0;
        for (j = i; j < len; j++)
        {
            temp[idx++] = str[j];
            temp[idx] = '\0';
            printf("%s\n", temp);
        }
    }
}
void PrintAllSubSequence(char *str, int len)
{
    int total = (1 << len) - 1;
    int i, j;
    for (i = 1; i <= total; i++)
    {
        printf("{ ");
        for (j = 0; j < len; j++)
            if (i & (1 << j))
                printf("%c ", str[j]);
        printf("}\n");
    }
}
int CountDistinctSubSequence(char *str, int len)
{
    int dp[len + 1];
    int last[256]; // 각 문자의 마지막 위치 저장, 현재 문자의 이전 위치 확인 -> 이전에 있었다면 중복 부분 수열 제거
    int i;
    memset(last, -1, sizeof(last));
    dp[0] = 1; // 빈 문자열의 경우, 서로 다른 수열이 하나임
    for (i = 1; i <= len; i++)
    {
        dp[i] = 2 * dp[i - 1];
        // printf("1 dP[%d]=%-4d, dp[%d]=%-4d\n", i, dp[i], i-1, dp[i-1]);
        if (last[str[i - 1]] != -1)
        {
            dp[i] -= dp[last[str[i - 1]]];
            // printf("2 dP[%d]=%-4d, dp[%d]=%4d,  last[str[%d]]=%-4d, str[%d]=%c\n", i, dp[i], last[str[i-1]], dp[last[str[i-1]]], i-1, last[str[i-1]], i-1, str[i-1]);
        }
        // printf("Before last[str[%d]]=%-4d \n", i-1, last[str[i-1]]);
        last[str[i - 1]] = i - 1;
        // printf("After last[%d]=%-4d, dp[%d]=%-4d\n", str[i-1], last[str[i-1]], len, dp[len] );
    }
    return dp[len];
}
void PrintAllDistinctSubsequences(char *str, int len)
{
    int dp[len + 1];
    int last[256];
    int i, j, mask, index;
    char sub[1 << len][len + 1];
    // char sub[1 << len][len + 1];
    bool printed[len + 1];
    memset(printed, false, sizeof(printed));
    int count = 0;
    memset(last, -1, sizeof(last));
    dp[0] = 1;
    for (i = 1; i <= len; i++)
    {
        dp[i] = 2 * dp[i - 1];
        if (last[str[i - 1]] != -1)
            dp[i] -= dp[last[str[i - 1]]];
        last[str[i - 1]] = i - 1;
    }
    printf("Number of Distinct Sub Sequence: %d\n", dp[len]);
    for (mask = 0; mask < (1 << len); mask++)
    {
        index = 0;
        for (j = 0; j < len; j++)
            if (mask & (1 << j))
                sub[count][index++] = str[j];
        sub[count++][index] = '\0';
    }
    for (i = 0; i < count; i++)
    {
        if (!printed[i])
        {
            printf("%s\n", sub[i]);
            for (j = i + 1; j < count; j++)
                if (strcmp(sub[i], sub[j]) == 0)
                    printed[j] = true;
        }
    }
}

// Sequence = 문자열 중 일부 문자를 제거하거나 제거하지 않고도 얻을 수 있는 문자열
// SubString = 문자열에서 일부 연속된 문자로 이루어진 문자열
// ex) ATBCEF
// Sequence: ATCF
// SubString: ATBC
int CountLongestCommonSubsequence(char *str1, char *str2)
{
    int n = strlen(str1);
    int m = strlen(str2);
    int prev[m + 1], cur[m + 1];
    int min = (n > m) ? m : n;
    bool isduplication[m] = {
        false,
    };
    int i, j;
    memset(isduplication, false, sizeof(isduplication));
    memset(prev, 0, sizeof(prev));
    memset(cur, 0, sizeof(cur));
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = 0 + __max(cur[j - 1], prev[j]);
        }
        memcpy(prev, cur, sizeof(cur));
    }
    for (i = 1, j = 0; i < m + 1; i++, j++)
    { // Print LCS
        if (isduplication[cur[i]] == false)
        {
            printf("%c", str2[j]);
            isduplication[cur[i]] = true;
        }
    }
    printf("\n");
    return cur[m]; // Return LCS's length
}
int CountLongestCommonSubsequence2(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = __max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
char *PrintLongestCommonSubsequence3(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = __max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int idx = dp[m][n];
    char *lcs = (char *)malloc((idx + 1) * sizeof(char));
    lcs[idx] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[idx - 1] = str1[i - 1];
            i--;
            j--;
            idx--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return lcs;
}
char *ShortestCommonSupersequence(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1 + 1][len2 + 1];
    int count = 0;
    int i, j, idx;
    int scslen;
    // Initialize
    for (i = 0; i <= len1; i++)
    {
        for (j = 0; j <= len2; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + __min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("dp[len1][len2] of SCS: %d\n", dp[len1][len2]);
    scslen = (len1 + len2 + 1);
    char *scs = (char *)malloc((scslen + 1) * sizeof(char));
    i = len1;
    j = len2;
    idx = scslen;
    // Compose Shortest Common Sequence
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            scs[idx--] = str1[i - 1];
            i--;
            j--;
            count++;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            scs[idx--] = str2[j - 1]; // scs[idx--] = str2[j-1];
            j--;
            count++;
        }
        else
        {
            scs[idx--] = str1[i - 1];
            i--;
            count++;
        }
    }
    while (i > 0)
    {
        scs[idx--] = str1[i - 1];
        i--;
        count++;
    }
    while (j > 0)
    {
        scs[idx--] = str2[j - 1];
        j--;
        count++;
    }
    printf("Number of SCS: %d\n", count);
    return scs;
}
int ShortestCommonSupersequence2(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);
    int k = CountLongestCommonSubsequence2(str1, str2);
    return (m + n - k);
}
int CalculateOverlappingInString(char *str1, char *str2, char *overlap)
{
    int max = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i;
    for (i = 1; i <= len1; i++)
    {
        if (strncmp(str1 + len1 - i, str2, i) == 0)
        {
            if (i > max)
            {
                max = i;
                strcpy(overlap, str1);
                strcat(overlap, str2 + i);
            }
        }
    }
    for (i = 1; i <= len2; i++)
    {
        if (strncmp(str1, str2 + len2 - i, i) == 0)
        {
            if (i > max)
            {
                max = i;
                strcpy(overlap, str2);
                strcat(overlap, str1 + i);
            }
        }
    }
    return max;
}
char *FindShortestSuperstring(char arr[][20], int len)
{
    char *merge_str = (char *)malloc(2 * 1000);
    char *overlap = (char *)malloc(2 * 1000);
    while (len > 1)
    {
        int max = -1;
        int idx1 = 0, idx2 = 0, i = 0, j = 0;
        int cur_overlap = 0;
        for (i = 0; i < len; i++)
        {
            for (j = i + 1; j < len; j++)
            {
                cur_overlap = CalculateOverlappingInString(arr[i], arr[j], overlap);
                if (cur_overlap > max)
                {
                    max = cur_overlap;
                    idx1 = i;
                    idx2 = j;
                    strcpy(merge_str, overlap);
                }
            }
        }
        strcpy(arr[idx1], merge_str);
        for (i = idx2 + 1; i < len; i++)
            strcpy(arr[i - 1], arr[i]);
        len--;
    }
    free(overlap);
    free(merge_str);
    return arr[0];
}
char *FindLongestRepeatingSubsequence(char *str)
{
    int n = strlen(str);
    int dp[n + 1][n + 1];
    int i, j, idx;
    memset(dp, 0, sizeof(dp));
    // Counting Number of LRS
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = __max(dp[i][j - 1], dp[i - 1][j]);
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    // return dp[n][n]; --> Function type : int
    //  Print LRS
    int lrslen = dp[n][n];
    char *lrs = (char *)malloc((lrslen + 1) * sizeof(char));
    i = j = n;
    idx = lrslen;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            lrs[idx--] = str[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }
    return lrs;
}
int CountLongestPalindromicSubsequence(char *str)
{
    int n = strlen(str);
    char temp[n];
    int i, j;
    strcpy(temp, str); //--> result: 5
    // memcpy(temp, str, n); // --> result: 5
    ReverseString(temp);
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (str[i - 1] == temp[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = __max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][n];
}
char *PrintLongestPalindromicSubsequence(char *str)
{
    int n = strlen(str);
    char rev[n];
    memcpy(rev, str, sizeof(rev));
    ReverseString(rev);
    return PrintLongestCommonSubsequence3(str, rev);
}
void PrintLongestPalindromicSubString(char *str, int low, int high)
{
    for (int i = low; i <= high; i++)
        printf("%c", str[i]);
    printf("\n");
}
int CountLongestPalindromicSubString(char *str)
{
    int n = strlen(str);
    int start = 0, end = 1;
    int low, high;
    int i;
    for (i = 0; i < n; i++)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }
    PrintLongestPalindromicSubString(str, start, start + end - 1);
    return end;
}

// Condition of Palindrome:
// 1) At most, one character occurs an odd number of times
// 2) All characters occur an even number of times
// Character number = 26
bool IsPalindrome(char *str)
{
    int l = 0;
    int r = strlen(str) - 1;
    while (l < r)
        if (str[l++] != str[r--])
            return false;
    return true;
}
bool CanPalindrome(char *str)
{
    int bit = 0, mask = 0;
    int i, x;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] - 'A') < 32)
            str[i] = tolower(str[i]);
        x = str[i] - 'a';
        mask = 1 << x; // 문자 번호에 해당하는 bit = 1
        bit ^= mask;   // bit는 문자 번호에 해당하는 bit 값 변화시킴(문자 개수 홀수: 1, 짝수: 0)
    }
    return (bit & (bit - 1) == 0); // 최종적으로 bit에는 1이 1개 있어야 함
}
bool IsRotationOfPalindrome(char *str)
{
    if (IsPalindrome(str))
        return true;
    int n = strlen(str);
    int i, j, idx;
    for (i = 0; i < n; i++)
    {
        char r_str[n + 1];
        strncpy(r_str, (str + i), n - i);
        strncpy((r_str + n - i), str, i);
        if (IsPalindrome(r_str))
            return true;
    }
    return false;
}

int CountStringPalindromeByAddingMinChar(char *str)
{
    int n = strlen(str);
    int start = 0, end = n - 1, res = 0;
    while (start < end)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            res++;
            start = 0;
            end = n - 1 - res;
        }
    }
    return res;
}

char *MaxPalindromeUsingKChange(char *str, int k)
{
    int n = strlen(str);
    char *pal = (char *)malloc(n * sizeof(char));
    strcpy(pal, str);
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (str[l] != str[r])
        {
            pal[l] = pal[r] = __max(str[l], str[r]);
            k--;
        }
        l++;
        r--;
    }
    /*     if(k < 0)
            return "Not Possible"; */
    l = 0;
    r = n - 1;
    while (l < r)
    {
        if (l == r && k > 0)
            pal[l] = '9';
        if (pal[l] < '9')
        {
            if (k >= 2 && pal[l] == str[l] && pal[r] == str[r])
            {
                k -= 2;
                pal[l] = pal[r] = '9';
            }
            else if (k >= 1 && pal[l] != str[l] || pal[r] != str[r])
            {
                k--;
                pal[l] = pal[r] = '9';
            }
        }
        l++;
        r--;
    }
    return pal;
}

int CountMinDelCharInStrForPalindrome(char *str)
{
    int n = strlen(str);
    int L[n];
    int i, j, backup, temp;
    for (i = n - 1; i >= 0; i--)
    {
        backup = 0;
        for (j = i; j < n; j++)
        {
            if (j == i)
                L[j] = 1;
            else if (str[i] == str[j])
            {
                temp = L[j];
                L[j] = backup + 2;
                backup = temp;
            }
            else
            {
                backup = L[j];
                L[j] = __max(L[j], L[j - 1]);
            }
        }
    }
    return (n - L[n - 1]);
}

int CountMinInsertForPalinWithPermut(char *str)
{
    int n = strlen(str);
    int mask = 0;
    int i, count = 0;
    for (i = 0; i < n; i++)
        mask ^= (1 << (str[i] - 'a'));
    if (mask == 0)
        return 0;
    while (mask)
    {
        count += mask & 1; // Adding 1 bit(number of character)
        mask >>= 1;        // Divide 2
    }
    return count - 1;
}

// Pattern Searching
void PatternSearchingWithNaive(char *str, char *pat)
{
    // All print index of patter found
    int m = strlen(str);
    int n = strlen(pat);
    int i, j;
    for (i = 0; i <= m - n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (str[i + j] != pat[j])
                break;
        }
        if (j == n)
            printf("Pattern found at index %d\n", i);
    }
    /* !! Caution !!
        Naive Algorithm may be not work if many matching char followed by a mismatching char
        Ex)
        if str = "AAAAAAAAAAAAAAAAAB", pattern = "AAAAB" ==> Error
        if str = "ABABABCABABABCABBABABC", pattern = "ABABAC" ==> Error
    */
}
void ComputeLPSArray(char *pat, int m, int *lps)
{
    // LPS array = Failure Function F
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < m)
    {
        if (pat[i] == pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void PatternSearchingWithKMP(char *str, char *pat)
{
    // If KMP finds mismatching char, KMP knows next char
    //  LPS = Longest Prefix which is also Suffix)
    int m = strlen(str);
    int n = strlen(pat);
    int lps[n];
    ComputeLPSArray(pat, n, lps);
    int i = 0, j = 0;
    while ((m - i) >= (n - j))
    { // i < m
        if (pat[j] == str[i])
        {
            i++;
            j++;
        }
        if (j == n)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < m && pat[j] != str[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}
void ComputeZ(char *str, int *z)
{
    int n = strlen(str);
    int l, r, k;
    int i;
    l = r = 0;
    for (i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && str[r - l] == str[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}
void PatternSearchingWithZ(char *str, char *pat)
{
    int plen = strlen(pat);
    int slen = strlen(str);
    int concatlen = slen + plen + 1;
    char *concat = (char *)malloc(concatlen);
    int Z[concatlen];
    int i;
    strcpy(concat, pat);
    strcat(concat, "$");
    strcat(concat, str);
    ComputeZ(concat, Z);
    for (i = 0; i < concatlen; i++)
        if (Z[i] == plen)
            printf("Pattern found at index %d\n", i - plen - 1);

    free(concat);
}
bool Search2DGrid(char *grid, char *word, int ridx, int cidx, int R, int C)
{
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int len = strlen(word), dir, k, rdir, cdir;
    if (*(grid + ridx * C + cidx) != word[0])
        return false;
    for (dir = 0; dir < 8; dir++)
    {
        rdir = ridx + x[dir], cdir = cidx + y[dir];
        for (k = 1; k < len; k++)
        {
            if (rdir >= R || rdir < 0 || cdir >= C || cdir < 0)
                break;
            if (*(grid + rdir * C + cdir) != word[k])
                break;
            rdir += x[dir], cdir += y[dir];
        }
        if (k == len)
            return true;
    }
    return false;
}
void PatternSearchWith2DGrid(char *grid, char *word, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (Search2DGrid(grid, word, i, j, r, c))
                printf("Pattern found at (%d,%d)\n", i, j);
    /* Input data In main()
    int r=3, c=13;
    char grid[r][c] =  {"GEEKSFORGEEKS",
                        "GEEKSQUIZGEEK",
                        "IDEQAPRACTICE" };
    char pattern1[] = "GEEKS";
    char pattern2[] = "EEE";
    PatternSearchWith2DGrid((char*)grid, pattern1, r, c);
    */
}
void PatterSearchWithWildCard(char *str, char *pat, bool *ismatch)
{
    int n = strlen(str);
    int m = strlen(pat);
    int i = 0, j = 0, sidx = -1, match = 0;
    while (i < n)
    {
        if (j < m && (pat[j] == '?' || pat[j] == str[i]))
        {
            i++;
            j++;
        }
        else if (j < m && pat[j] == '*')
        {
            sidx = j;
            match = i;
            j++;
        }
        else if (sidx != -1)
        {
            j = sidx + 1;
            match++;
            i = match;
        }
        else
            *ismatch = false;
    }
    while (j < m && pat[j] == '*')
        j++;
    *ismatch = !!(j == m);
}

int GetNextStateForFA(char *pat, int len, int state, int x)
{
    int ns, i;
    if (state < len && x == pat[state])
        return state + 1;
    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns - 1] == x)
        {
            for (i = 0; i < ns - 1; i++)
                if (pat[i] != pat[state - ns + 1 + i])
                    break;
            if (i == ns - 1)
                return ns;
        }
    }
    return 0;
}
void ComputeTF(char *pat, int len, int TF[][256])
{
    int state, x;
    for (state = 0; state <= len; state++)
        for (x = 0; x < 256; x++)
            TF[state][x] = GetNextStateForFA(pat, len, state, x);
}
void PatternSearchWithFiniteAutomata(char *str, char *pat)
{
    int m = strlen(str);
    int n = strlen(pat);
    int TF[n + 1][256];
    int i, state = 0;
    ComputeTF(pat, n, TF);
    for (i = 0; i < m; i++)
    {
        state = TF[state][str[i]];
        if (state == n)
            printf("Pattern found at index %d\n", i - n + 1);
    }
}
void PatternSearchWithRabinKarp(char *str, char *pat, int prime)
{
    int plen = strlen(pat);
    int slen = strlen(str);
    int i, j;
    int p = 0, t = 0, h = 1;
    for (i = 0; i < plen - 1; i++)
        h = (h * 256) % prime;
    for (i = 0; i < plen; i++)
    {
        p = (256 * p + pat[i]) % prime;
        t = (256 * t + str[i]) % prime;
    }
    for (i = 0; i <= slen - plen; i++)
    {
        if (p == t)
        {
            for (j = 0; j < plen; j++)
                if (str[i + j] != pat[j])
                    break;
            if (j == plen)
                printf("Pattern found at index %d\n", i);
        }
        if (i < slen - plen)
        {
            t = (256 * (t - str[i] * h) + str[i + plen]) % prime;
            if (t < 0)
                t += prime;
        }
    }
}
void PatternSearchWithBoyerMoore(char *str, char *pat)
{
    // Bad char Heuristic
    int m = strlen(str);
    int n = strlen(pat);
    int ch[256];
    int i, j, s = 0;
    for (i = 0; i < 256; i++)
        ch[i] = -1;
    for (i = 0; i < n; i++)
        ch[(int)pat[i]] = i;
    while (s <= (m - n))
    {
        j = n - 1;
        while (j >= 0 && pat[j] == str[s + j])
            j--;
        if (j < 0)
        {
            printf("Pattern occurs at shift %d\n", s);
            s += (s + n < m) ? n - ch[str[s + n]] : 1;
        }
        else
            s += __max(1, j - ch[str[s + j]]);
    }
}

typedef struct TrieNode
{
    struct TrieNode *child[26];
    struct TrieNode *failurelink;
    int isEndOfWord;
} TrieNode;
typedef struct QueueNode
{
    TrieNode *data;
    struct QueueNode *next;
} QueueNode;
typedef struct TrieQueue
{
    QueueNode *front;
    QueueNode *rear;
} TrieQueue;
TrieQueue *CreateTrieQueue()
{
    TrieQueue *que = (TrieQueue *)malloc(sizeof(TrieQueue));
    que->front = que->rear = NULL;
    return que;
}
void EnqueueTrie(TrieQueue *que, TrieNode *data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (que->rear == NULL)
        que->front = que->rear = newNode;
    else
    {
        que->rear->next = newNode;
        que->rear = newNode;
    }
}
TrieNode *DequeueTrie(TrieQueue *que)
{
    if (que->front == NULL)
        return NULL;
    else
    {
        QueueNode *temp = que->front;
        TrieNode *data = temp->data;
        que->front = temp->next;
        free(temp);
        if (que->front == NULL)
            que->rear = NULL;
        return data;
    }
}
TrieNode *CreateTrieNode()
{
    int i;
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    for (i = 0; i < 26; i++)
        node->child[i] = NULL;
    node->failurelink = NULL;
    node->isEndOfWord = 0;
    return node;
}
void InsertPatternInTrie(TrieNode *root, char *pat)
{
    int i, idx;
    int plen = strlen(pat);
    TrieNode *cur = root;
    for (i = 0; i < plen; i++)
    {
        idx = pat[i] - 'A';
        if (!cur->child[idx])
            cur->child[idx] = CreateTrieNode();
        cur = cur->child[idx];
    }
    cur->isEndOfWord = 1;
}
void BuildAhoCorasick(TrieNode *root)
{
    int i;
    TrieQueue *que = CreateTrieQueue();
    for (i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            EnqueueTrie(que, root->child[i]);
            root->child[i]->failurelink = root;
        }
    }
    while (que->front)
    {
        TrieNode *cur = DequeueTrie(que);
        for (i = 0; i < 26; i++)
        {
            TrieNode *child = cur->child[i];
            if (child)
            {
                EnqueueTrie(que, child);
                TrieNode *fail = cur->failurelink;
                while (fail && !fail->child[i])
                    fail = fail->failurelink;
                if (fail)
                    child->failurelink = fail->child[i];
                else
                    child->failurelink = root;
            }
        }
    }
    free(que);
}
void SearchAhoCorasick(TrieNode *root, char *str)
{
    int i, idx;
    int slen = strlen(str);
    TrieNode *cur = root;
    for (i = 0; i < slen; i++)
    {
        idx = str[i] - 'A';
        while (cur && !cur->child[idx])
            cur = cur->failurelink;
        if (cur)
            cur = cur->child[idx];
        else
            cur = root;
        TrieNode *temp = cur;
        while (temp)
        {
            if (temp->isEndOfWord)
                printf("Pattern found at index %d\n", i);
            temp = temp->failurelink;
        }
    }
}
void FreeTrie(TrieNode *node)
{
    int i;
    if (!node)
        return;
    for (i = 0; i < 26; i++)
        FreeTrie(node->child[i]);
    free(node);
}

bool IsSamePattern(char *str, char *pat)
{
    int slen = strlen(str);
    int plen = strlen(pat);
    int i;
    char ch[128] = {
        0,
    };
    char map[128] = {
        0,
    };
    if (plen != slen)
        return false;
    for (i = 0; i < slen; i++)
    {
        if (ch[pat[i]] == 0 && map[str[i]] == 0)
        {
            ch[pat[i]] = str[i];
            map[str[i]] = pat[i];
        }
        else if (ch[pat[i]] != str[i] || map[str[i]] != pat[i])
            return false;
    }
    return true;
}
void PatternMatch(char str[5][5], char *pat)
{
    int slen = 5;
    int i;
    for (i = 0; i < slen; i++)
    {
        if (IsSamePattern(str[i], pat))
            printf("%s ", str[i]);
    }
    printf("\n");
}
bool CheckPattern(char *str, char *pat)
{
    int order = 1;
    int last_order = -1;
    int i;
    int label[256];
    int m = strlen(str);
    int n = strlen(pat);
    memset(label, -1, sizeof(label));
    for (i = 0; i < n; i++)
    {
        label[pat[i]] = order;
        order++;
    }
    for (i = 0; i < m; i++)
    {
        if (label[str[i]] != -1)
        {
            if (label[str[i]] < last_order)
                return false;
            last_order = label[str[i]];
        }
    }
    return true;
}
//----------------------------------------
//-------------- Linked List -------------
//----------------------------------------
typedef struct SNode
{
    int data;
    struct SNode *next;
    SNode(int val)
    {
        this->data = val;
        this->next = NULL;
    }
} SNode;
int SNodeLength(SNode *head)
{
    SNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int DNodeLength(DNode *head)
{
    DNode *temp = head;
    int count = 0;
    if (temp == NULL)
        return 0;
    else
    {
        while (head != temp->next)
        {
            count++;
            temp = temp->next;
        }
        return count + 1;
    }
}
void InsertFrontSNode(SNode **head_ref, int data)
{
    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    new_node->data = data;
    new_node->next = (*head_ref); // Node that head pointed
    (*head_ref) = new_node;       // Head Node points new node
}
void InsertMidSNode(SNode *prev, int data)
{
    if (prev == NULL)
        return;
    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}
void InsertEndSNode(SNode **head_ref, int data)
{
    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    SNode *last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    { // If Linked List is empty
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) // IF Linked List is full some elemnets.
        last = last->next;     // Shift pointer to last node
    last->next = new_node;
    return;
}
void DeletionFrontSNode(SNode **head, int pos)
{ // Last inserted element's node is head node
    SNode *temp;
    SNode *prev;
    int i;
    temp = *head;
    prev = *head;
    for (i = 0; i < pos; i++)
    {
        if (i == 0 && pos == 1)
        {
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            if (i == pos - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void InsertionFrontDNode(DNode **head, int data)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = data;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}
void InsertionMidBehindDNode(DNode *prev, int data)
{
    if (prev == NULL)
        return;
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    new_node->prev = prev;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void InsetionMidFrontDNode(DNode *next, int data, DNode *head)
{
    if (next == NULL)
        return;
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = data;
    new_node->prev = next->prev;
    next->prev = new_node;
    new_node->next = next;
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        head = new_node;
}
void InsertionEndDNode(DNode **head, int data)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    DNode *last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}
void DeletionEndDNode(DNode **head, DNode *del)
{
    DNode *cur = *head;
    int i;

    if (*head == NULL || del == NULL)
        return;
    if (*head == del)
        *head = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}
void DeletionPosDNode(DNode **head, int pos)
{
    if (*head == NULL || pos <= 0)
        return;
    DNode *cur = *head;
    int i;
    for (i = 1; cur != NULL && i < pos; i++)
        cur = cur->next;
    if (cur == NULL)
        return;
    DeletionEndDNode(head, cur);
}

void InsertionEmptyCNode(SNode *last, int data)
{
    if (last != NULL)
        return;
    SNode *temp = (SNode *)malloc(sizeof(SNode));
    temp->data = data;
    last = temp;
    temp->next = last;
}
void InsertionFrontCNode(SNode *last, int data)
{
    if (last == NULL)
        return InsertionEmptyCNode(last, data);
    SNode *temp = (SNode *)malloc(sizeof(SNode));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
}
void InsertionEndCNode(SNode *last, int data)
{
    if (last == NULL)
        return InsertionEmptyCNode(last, data);
    SNode *temp = (SNode *)malloc(sizeof(SNode));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
}
void InsertionMidCNode(SNode *last, int data, int item)
{
    if (last == NULL)
        return;
    SNode *temp, *p;
    p = last->next;
    do
    {
        if (p->data == item)
        {
            temp = (SNode *)malloc(sizeof(SNode));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            if (p == last)
                last = temp;
            return;
        }
        p = p->next;
    } while (p != last->next);
    return;
}
void DeletionFrontCNode(SNode **head)
{
    SNode *prev = *head, *first = *head;
    if (*head == NULL)
        return;
    if (prev->next == prev)
    {
        *head = NULL;
        return;
    }
    while (prev->next != *head)
        prev = prev->next;
    prev->next = first->next;
    *head = prev->next;
    free(first);
    return;
}
void DeletionEndCNode(SNode **head)
{
    SNode *cur = *head, *temp = *head, *prev;
    if (*head == NULL)
        return;
    if (cur->next == cur)
    {
        *head = NULL;
        return;
    }
    while (cur->next != *head)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    *head = prev->next;
    free(cur);
    return;
}
void DeletionIdxCNode(SNode **head, int idx)
{
    int len = SNodeLength(*head);
    int count = 1;
    SNode *prev = *head, *next = *head;
    if (*head == NULL)
        return;
    if (idx >= len | idx < 0)
        return;
    if (idx == 0)
    {
        DeletionFrontCNode(head);
        return;
    }
    while (len > 0)
    {
        if (idx == count)
        {
            prev->next = next->next;
            free(next);
            return;
        }
        prev = prev->next;
        next = prev->next;
        len--;
        count++;
    }
    return;
}

void InsertEndDCNode(DNode **start, int data)
{
    if (*start == NULL)
    {
        DNode *new_node = (DNode *)malloc(sizeof(DNode));
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    DNode *last = (*start)->prev;
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = data;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}
void InsertionFrontDCNode(DNode **start, int data)
{
    DNode *last = (*start)->prev;
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = data;
    new_node->next = *start;
    new_node->prev = last;
    last->next = (*start)->prev = new_node;
    *start = new_node;
}
void InsertionValBehindDCNode(DNode **start, int data, int base_val)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = data;
    DNode *temp = *start;
    while (temp->data != base_val)
        temp = temp->next;
    DNode *next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}
void InsertionIdxDCNode(DNode *start, int data, int idx)
{
    DNode *temp, *new_node;
    int i, count;
    new_node = (DNode *)malloc(sizeof(DNode));
    temp = start;
    count = DNodeLength(start);
    if (temp == NULL || count < idx)
        return;
    else
    {
        new_node->data = data;
        for (i = 1; i < idx - 1; i++)
            temp = temp->next;
        new_node->next = temp->next;
        (temp->next)->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}
void DeletionValDCNode(DNode **start, int val)
{
    if (*start == NULL)
        return;
    DNode *cur = *start, *prev = NULL;
    while (cur->data != val)
    {
        if (cur->next == *start)
            return;
        prev = cur;
        cur = cur->next;
    }
    if (cur == *start)
    {
        prev = (*start)->prev;
        *start = (*start)->next;
        prev->next = *start;
        (*start)->prev = prev;
        free(cur);
    }
    else if (cur->next == *start)
    {
        prev->next = *start;
        (*start)->prev = prev;
        free(cur);
    }
    else
    {
        DNode *temp = cur->next;
        prev->next = temp;
        temp->prev = prev;
        free(cur);
    }
}
void ReverseDCNode(DNode **head)
{
    if (*head == NULL)
        return;
    DNode *cur = *head;
    while (cur->next != *head)
    {
        DNode *temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = temp;
    }
    DNode *temp = cur->next;
    cur->next = cur->prev;
    cur->prev = temp;
    *head = cur;
}
void SearchDCNode(DNode *start, int val)
{
    DNode *temp = start;
    int count = 0;
    bool flag = false;
    if (temp == NULL)
        return;
    else
    {
        while (temp->next != start)
        {
            if (temp->data == val)
            {
                flag = true;
                count++;
                break;
            }
            count++;
            temp = temp->next;
        }
        if (temp->data == val)
        {
            count++;
            flag = true;
        }
        if (flag)
            printf("%d found at index %d\n", val, count);
        else
            printf("There is no %d in Doubly Circular Linked List\n", val);
    }
}
DNode *BinaryTree2DNode(DNode *root, DNode **head)
{
    if (root == NULL)
        return root;
    static DNode *prev = NULL;
    BinaryTree2DNode(root->prev, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->prev = prev;
        prev->next = root;
    }
    prev = root;
    BinaryTree2DNode(root->next, head);
    return prev;
}
DNode *BinaryTree2DCNode(DNode *root)
{
    DNode *head = NULL;
    DNode *tail = BinaryTree2DNode(root, &head);

    tail->next = head;
    head->prev = tail;
    return head;
}
void Array2DCLL(int *arr, int size, DNode **start)
{
    DNode *new_node, *temp;
    int i;
    for (i = 0; i < size; i++)
    {
        new_node = (DNode *)malloc(sizeof(DNode));
        new_node->data = arr[i];
        if (i == 0)
        {
            *start = new_node;
            new_node->prev = *start;
            new_node->next = *start;
        }
        else
        {
            temp = (*start)->prev;
            temp->next = new_node;
            new_node->next = *start;
            new_node->prev = temp;
            temp = *start;
            temp->prev = new_node;
        }
    }
}

//----------------------------------------
//----------------- Stack ----------------
//----------------------------------------
typedef struct LLStack
{
    int data;
    struct LLStack *next;
} LLStack;
void InitLLStack(LLStack **s)
{
    *s = NULL;
}
bool isEmptyLLStack(LLStack *s)
{
    if (s == NULL)
        return true;
    return false;
}
void PushLLStack(LLStack **s, int x)
{
    LLStack *p = (LLStack *)malloc(sizeof(*p));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    p->data = x;
    p->next = *s;
    *s = p;
}
int PopLLStack(LLStack **s)
{
    int x = (*s)->data;
    LLStack *temp = *s;
    (*s) = (*s)->next;
    free(temp);
    return x;
}
int TopLLStack(LLStack *s)
{
    return s->data;
}
void SortedInsertLLStack(LLStack **s, int x)
{
    int temp;
    if (isEmptyLLStack(*s) || x > TopLLStack(*s))
    {
        PushLLStack(s, x);
        return;
    }
    temp = PopLLStack(s);
    SortedInsertLLStack(s, x);
    PushLLStack(s, temp);
}
void SortLLStack(LLStack **s)
{
    int x;
    if (!isEmptyLLStack(*s))
    {
        x = PopLLStack(s);
        SortLLStack(s);
        SortedInsertLLStack(s, x);
    }
}
void PrintLLStack(LLStack *s)
{
    while (s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

typedef struct Stack
{
    int top;
    unsigned int cap;
    int *arr;
} Stack;
Stack *CreateStack(unsigned cap)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->cap = cap;
    st->top = -1;
    st->arr = (int *)malloc(st->cap * sizeof(int));
    return st;
}
bool IsFullStack(Stack *st)
{
    return st->top == st->cap - 1;
}
bool IsEmptyStack(Stack *st)
{
    return st->top == -1;
}
void PushStack(Stack *st, int data)
{
    if (IsFullStack(st))
        return;
    st->arr[++st->top] = data;
}
int PopStack(Stack *st)
{
    if (IsEmptyStack(st))
        return INT_MIN;
    return st->arr[st->top--];
}
int PeekStack(Stack *st)
{
    if (IsEmptyStack(st))
        return INT_MIN;
    return st->arr[st->top];
}
void DecMonotonicStack(int *arr, int n)
{
    Stack *st = CreateStack(n);
    int i;
    for (i = 0; i < n; i++)
    {
        while (!IsEmptyStack(st) && arr[i] > PeekStack(st))
            PopStack(st);
        PushStack(st, arr[i]);
    }
    int n2 = st->top + 1;
    int *ans = (int *)malloc(n2 * sizeof(int));
    int j = n2 - 1;
    while (!IsEmptyStack(st))
    {
        ans[j] = PopStack(st);
        j--;
    }
    for (i = 0; i < n2; i++)
        printf("%d ", ans[i]);

    free(st->arr);
    // free(st);
    free(ans);
}
void IncMonotonicStack(int *arr, int n)
{
    Stack *st = CreateStack(n);
    int i;
    for (i = 0; i < n; i++)
    {
        while (!IsEmptyStack(st) && arr[i] < PeekStack(st))
            PopStack(st);
        PushStack(st, arr[i]);
    }
    int n2 = st->top + 1;
    int *ans = (int *)malloc(n2 * sizeof(int));
    int j = n2 - 1;
    while (!IsEmptyStack(st))
    {
        ans[j] = PopStack(st);
        j--;
    }
    for (i = 0; i < n2; i++)
        printf("%d ", ans[i]);

    free(st->arr);
    // free(st);
    free(ans);
}

typedef struct QueueByStack
{
    LLStack *st1;
    LLStack *st2;
} SQue;
void EnqueueByStack(SQue *q, int x)
{
    PushLLStack(&q->st1, x);
}
int DequeueByStack(SQue *q)
{
    int x;
    if (q->st1 == NULL && q->st2 == NULL)
        return -1;
    if (q->st2 == NULL)
        while (q->st1 != NULL)
        {
            x = PopLLStack(&q->st1);
            PushLLStack(&q->st2, x);
        }
    x = PopLLStack(&q->st2);
    return x;
}

typedef struct SpecialStack
{
    int min;
    int demo_val;
    int *arr;
    int top;
} SStack;
#define DEMO_VAL 9999
SStack *CreateSStack()
{
    SStack *s = (SStack *)malloc(sizeof(SStack));
    s->min = -1;
    s->demo_val = DEMO_VAL;
    s->arr = NULL;
    s->top = -1;
    return s;
}
void GetMinSStack(SStack *s)
{
    printf("Min: %d\n", s->min);
}
void PushSStack(SStack *s, int val)
{
    if (s->arr == NULL || val < s->min)
        s->min = val;
    s->top++;
    s->arr = (int *)realloc(s->arr, (s->top + 1) * sizeof(int));
    s->arr[s->top] = val * s->demo_val + s->min;
}
int PopSStack(SStack *s)
{
    if (s->top == -1)
        return -1;
    int val = s->arr[s->top];
    s->top--;
    if (s->top != -1)
        s->min = s->arr[s->top] % s->demo_val;
    else
        s->min = -1;
    s->arr = (int *)realloc(s->arr, (s->top + 1) * sizeof(int));
    return val / s->demo_val;
}
int PeekSStack(SStack *s)
{
    return s->arr[s->top] / s->demo_val;
}
void DestroySStack(SStack *s)
{
    free(s->arr);
    free(s);
}

typedef struct TwoStack
{
    int *arr;
    int size;
    int top1;
    int top2;
} TStack;
TStack *CreateTStack(int n)
{
    TStack *ts = (TStack *)malloc(sizeof(TStack));
    ts->size = n;
    ts->arr = (int *)malloc(n * sizeof(int));
    ts->top1 = -1;
    ts->top2 = n;
    return ts;
}
void Push1TStack(TStack *ts, int x)
{
    if (ts->top1 < ts->top2 - 1)
    {
        ts->top1++;
        ts->arr[ts->top1] = x;
    }
    else
        exit(1);
}
void Push2TStack(TStack *ts, int x)
{
    if (ts->top1 < ts->top2 - 1)
    {
        ts->top2--;
        ts->arr[ts->top2] = x;
    }
    else
        exit(1);
}
int Pop1TStack(TStack *ts)
{
    if (ts->top1 >= 0)
    {
        int x = ts->arr[ts->top1];
        ts->top1--;
        return x;
    }
    else
        exit(1);
}
int Pop2TStack(TStack *ts)
{
    if (ts->top2 < ts->size)
    {
        int x = ts->arr[ts->top2];
        ts->top2++;
        return x;
    }
    else
        exit(1);
}
void DestroyTStack(TStack *ts)
{
    free(ts->arr);
    free(ts);
}

typedef struct
{
    int *arr;
    int front;
    int rear;
    int cap;
} Que;
typedef struct StackByQueue
{
    Que q1, q2;
} QStack;
Que *CreateQue(int cap)
{
    Que *q = (Que *)malloc(sizeof(Que));
    q->arr = (int *)malloc(cap * sizeof(int));
    q->front = q->rear = -1;
    q->cap = cap;
    return q;
}
bool IsEmptyQue(Que *q)
{
    return (q->front == -1);
}
bool IsFullQue(Que *q)
{
    return (q->rear + 1) % q->cap == q->front;
}
void EnqueueQue(Que *q, int x)
{
    if (IsFullQue(q))
        return;
    if (IsEmptyQue(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = x;
}
int DequeueQue(Que *q)
{
    if (IsEmptyQue(q))
        return INT_MIN;
    int x = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->cap;
    return x;
}

QStack *CreateQStack(int cap)
{
    QStack *s = (QStack *)malloc(sizeof(QStack));
    s->q1 = *CreateQue(cap);
    s->q2 = *CreateQue(cap);
    return s;
}
void PushQStack(QStack *s, int x)
{
    EnqueueQue(&(s->q2), x);
    while (!IsEmptyQue(&(s->q1)))
        EnqueueQue(&(s->q2), DequeueQue(&(s->q1)));
    Que temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}
void PopQStack(QStack *s)
{
    if (IsEmptyQue(&(s->q1)))
        exit(1);
    DequeueQue(&(s->q1));
}
int TopQStack(QStack *s)
{
    if (IsEmptyQue(&(s->q1)))
        return -1;
    return s->q1.arr[s->q1.front];
}
int size(QStack *s)
{
    return IsEmptyQue(&(s->q1)) ? 0 : s->q1.cap;
}

typedef struct DequeNode
{
    int val;
    struct DequeNode *next;
    struct DequeNode *prev;
} DQNode;
typedef struct Deque
{
    DQNode *head;
    DQNode *tail;
} DQ;
DQ *CreateDeque()
{
    DQ *dq = (DQ *)malloc(sizeof(DQ));
    dq->head = dq->tail = NULL;
    return dq;
}
int IsEmptyDeque(DQ *dq)
{
    return (dq->head == NULL);
}
int SizeDeque(DQ *dq)
{
    if (IsEmptyDeque(dq))
    {
        DQNode *temp = dq->head;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    return 0;
}
void InsertFisrtDeque(DQ *dq, int val)
{
    DQNode *temp = (DQNode *)malloc(sizeof(DQNode));
    temp->val = val;
    if (IsEmptyDeque(dq))
    {
        dq->head = dq->tail = temp;
        temp->next = temp->prev = NULL;
    }
    else
    {
        dq->head->prev = temp;
        temp->next = dq->head;
        temp->prev = NULL;
        dq->head = temp;
    }
}
void InsertLastDeque(DQ *dq, int val)
{
    DQNode *temp = (DQNode *)malloc(sizeof(DQNode));
    temp->val = val;
    if (IsEmptyDeque(dq))
    {
        dq->head = dq->tail = temp;
        temp->next = temp->prev = NULL;
    }
    else
    {
        dq->tail->next = temp;
        temp->next = NULL;
        temp->prev = dq->tail;
        dq->tail = temp;
    }
}
void RemoveFirstDeque(DQ *dq)
{
    if (!IsEmptyDeque(dq))
    {
        DQNode *temp = dq->head;
        dq->head = dq->head->next;
        if (dq->head)
            dq->head->prev = NULL;
        free(temp);
        if (dq->head == NULL)
            dq->tail = NULL;
        return;
    }
}
void RemoveLastDeque(DQ *dq)
{
    if (!IsEmptyDeque(dq))
    {
        DQNode *temp = dq->tail;
        dq->tail = dq->tail->prev;
        if (dq->tail)
            dq->tail->next = NULL;
        free(temp);
        if (dq->tail == NULL)
            dq->head = NULL;
        return;
    }
}
typedef struct StackByDeque
{
    DQ *dq;
} DStack;
void PushDStack(DStack *st, int val)
{
    InsertLastDeque(st->dq, val);
}
void PopDStack(DStack *st)
{
    RemoveLastDeque(st->dq);
}
typedef struct QueueByDeque
{
    DQ *dq;
} DQue;
void EnqueueDQue(DQue *q, int val)
{
    InsertLastDeque(q->dq, val);
}
void DequeueDQue(DQue *q)
{
    RemoveFirstDeque(q->dq);
}

//----------------------------------------
//----------------- Queue ----------------
//----------------------------------------
typedef struct
{
    int *arr;
    int front;
    int rear;
    unsigned int cap;
    int size;
} Queue;
Queue *CreateQueue(unsigned int cap)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(cap * sizeof(int));
    q->front = q->size = 0;
    q->cap = cap;
    q->rear = cap - 1;
    q->arr = (int *)malloc(sizeof(int));
    return q;
}
bool IsEmptyQueue(Queue *q)
{
    return (q->size == 0);
}
bool IsFullQueue(Queue *q)
{
    return (q->size == q->cap);
}
void EnqueueQueue(Queue *q, int x)
{
    if (IsFullQueue(q))
        return;
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = x;
    q->size = q->size + 1;
}
int DequeueQueue(Queue *q)
{
    if (IsEmptyQueue(q))
        return INT_MIN;
    int x = q->arr[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size = q->size - 1;
    return x;
}
int FrontQueue(Queue *q)
{
    if (IsEmptyQueue(q))
        return INT_MIN;
    return q->arr[q->front];
}
int RearQueue(Queue *q)
{
    if (IsEmptyQueue(q))
        return INT_MIN;
    return q->arr[q->rear];
}
int SizeQueue(Queue *q)
{
    return q->size;
}

// Priority Queue using Max Heap
int PQH[50];
int PQsize = -1;
int PQParentNode(int i)
{
    return (i - 1) >> 1;
}
int PQLeftChild(int i)
{
    return ((i << 1) + 1);
}
int PQRightChild(int i)
{
    return ((i << 1) + 2);
}
void PQShiftUp(int i)
{
    while (i > 0 && PQH[PQParentNode(i)] < PQH[i])
    {
        Swap(&PQH[PQParentNode(i)], &PQH[i]);
        i = PQParentNode(i);
    }
}
void PQShiftDown(int i)
{
    int max_idx = i;
    int l = PQLeftChild(i);
    if (l <= PQsize && PQH[l] > PQH[max_idx])
        max_idx = l;
    int r = PQRightChild(i);
    if (r <= PQsize && PQH[r] > PQH[max_idx])
        max_idx = r;
    if (i != max_idx)
    {
        Swap(&PQH[i], &PQH[max_idx]);
        PQShiftDown(max_idx);
    }
}
void PQInsert(int p)
{
    PQsize = PQsize + 1;
    PQH[PQsize] = p;
    PQShiftUp(PQsize);
}
int PQGetMaxPriorityElement()
{
    int result = PQH[0];
    PQH[0] = PQH[PQsize];
    PQsize = PQsize - 1;
    PQShiftDown(0);
    return result;
}
void PQChangePriority(int i, int p)
{
    int oldp = PQH[i];
    PQH[i] = p;
    if (p > oldp)
        PQShiftUp(i);
    else
        PQShiftDown(i);
}
int PQGetMaxValue()
{
    return PQH[0];
}
void PQRemove(int i)
{
    PQH[i] = PQGetMaxValue() + 1;
    PQShiftUp(i);
    PQGetMaxPriorityElement();
}
// Priority Queue using Max Heap Template
template <typename T>
class PriorityQueue
{
private:
    vector<T> data;

public:
    PriorityQueue() {}
    void EnqueueTemplate(T item)
    {
        data.push_back(item);
        int ci = data.size() - 1;
        while (ci > 0)
        {
            int pi = (ci - 1) >> 1;
            if (data[ci] <= data[pi])
                break;
            T temp = data[ci];
            data[ci] = data[pi];
            data[pi] = temp;
            ci = pi;
        }
    }
    T Dequeue()
    {
        int li = data.size() - 1;
        T front_item = data[0];
        data[0] = data[li];
        data.pop_back();
        --li;
        int pi = 0;
        while (true)
        {
            int ci = pi * 2 + 1;
            if (ci > li)
                break;
            int rc = ci + 1;
            if (rc <= li && data[rc] < data[ci])
                ci = rc;
            if (data[pi] >= data[ci])
                break;
            T tmp = data[pi];
            data[pi] = data[ci];
            data[ci] = tmp;
            pi = ci;
        }
        return frontItem;
    }
    T Peek()
    {
        T frontItem = data[0];
        return frontItem;
    }

    int Count()
    {
        return data.size();
    }
};

typedef struct CharLLNode{
    char* data;
    struct CharLLNode* next;
}CNode;
typedef struct {
    CNode* front;
    CNode* rear;
}LLQue;
CNode* CreateCNode(char* data){
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}
void InitLLQ(LLQue* q){
    q->front = q->rear = NULL;
}
bool IsEmptyLLQ(LLQue* q){
    return q->front == NULL;
}
void EnqueueLLQ(LLQue* q, char* data){
    CNode* newNode = CreateCNode(data);
    if (IsEmptyLLQ(q))
        q->front = q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
char* DequeueLLQ(LLQue* q){
    if (IsEmptyLLQ(q))
        return NULL;
    CNode* fnode = q->front;
    char* data = fnode->data;
    q->front = fnode->next;
    free(fnode);
    if (q->front == NULL)
        q->rear = NULL;
    return data;
}
void DecimalN2BinaryF0TN(int n){
    LLQue q;
    InitLLQ(&q);
    EnqueueLLQ(&q, "1");
    while (n--) {
        char* s1 = DequeueLLQ(&q);
        printf("%s\n", s1);
        free(s1);
        char* s2 = strdup(s1);
        strcat(s1, "0");
        EnqueueLLQ(&q, s1);
        strcat(s2, "1");
        EnqueueLLQ(&q, s2);
    }
}

//----------------------------------------
//----------------- Tree -----------------
//----------------------------------------

Tree* CreateTree(int data){
    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    newNode->key = data;
    newNode->left = newNode->right = NULL;
    return newNode;
 }
void PreorderTree(Tree* t, int* arr=NULL, int* idx=NULL, bool option){
    if(t == NULL)
        return;
    if(option){
        arr[(*idx)++] = t->key;
        PreorderTree(t->left);
        PreorderTree(t->right);
    }
    if(!option){
        printf("%d ", t->key);
        PreorderTree(t->left);
        PreorderTree(t->right);
    }
 }
void InorderTree(Tree* t, int* arr=NULL, int* idx=NULL, bool option){
    if(t == NULL)
        return;
    // 1) printf() 없이 array에 정렬된 배열 저장
    if(option){
        InorderTree(t->left, arr, idx, true);
        arr[(*idx)++] = t->key;
        InorderTree(t->right, arr, idx, true);
    }
    //2) pritnf()를 이용하여 정렬된 배열 출력
    if(!option){
        InorderTree(t->left, arr, idx, false);
        printf("%d ", t->key);
        InorderTree(t->right, arr, idx, false);
    }
}
void PostorderTree(Tree* t, int* arr=NULL, int* idx=NULL, bool option){
    if(t == NULL)
        return;
    if(option){
        PostorderTree(t->left, arr, idx, true);
        PostorderTree(t->right, arr, idx, true);
        arr[(*idx)++] = t->key;
    }
    if(!option){
        PostorderTree(t->left, arr, idx, true);
        PostorderTree(t->right, arr, idx, true);
        printf("%d ", t->key);
    }
}
void LevelorderTree(Tree* t){
    int h = GetDepthTree(t);
    int i;
    for(i=1; i<=h; i++){
        GetAllNodeAtSameLevelTree(t, i);
        printf("\n");
    }
}
void LevelorderTreeUsingQueue(Tree* t){
    if(t == NULL)
        return;
    queue<Tree*> q;
    q.push(t);
    while(!q.empty()){
        Tree* node = q.front();
        cout << node->key << " ";
        q.pop();
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
}
int SizeRecursiveTree(Tree* t){
    if(t==NULL)
        return 0;
    else
        return (SizeRecursiveTree(t->left)+1+SizeRecursiveTree(t->right));
}
//Inorder Traversal without recursion and stack
int SizeMorrisTree(Tree* t){
    int count = 0;
    Tree* cur = t;
    while(cur != NULL){
        if(cur->left == NULL){
            count++;
            cur = cur->right;
        }
        else{
            Tree* child = cur->left;
            while(child->right != NULL && child->right != cur)
                child = child->right;
            if(child->right == NULL){
                child->right = cur;
                cur = cur->left;
            }
            else{
                child->right = NULL;
                count++;
                cur = cur->right;
            }
        }
    }
    return count;
}
void ViewRightNodeTree(Tree* t, int level, int* max_level){
    if(t == NULL)
        return;
    if(*max_level < level){
        printf("%d ", t->key);
        *max_level = level;
    }
    ViewRightNodeTree(t->right, level+1, max_level);
    ViewRightNodeTree(t->left, level+1, max_level);
}
void ViewLeftNodeTree(Tree* t, int level, int* max_level){
    if(t == NULL)
        return;
    if(*max_level < level){
        printf("%d ", t->key);
        *max_level = level;
    }
    ViewLeftNodeTree(t->left, level+1, max_level);
    ViewLeftNodeTree(t->right, level+1, max_level);
}
int GetDiameterTree(Tree* t){
    // Diameter is the longest distance between nodes 
     int result = 0;
    Tree* cur = t;
    while(cur != NULL){
        if(cur->left == NULL)
            cur = cur->right;
        else{
            Tree* child = cur->left;
            while(child->right != NULL && child->right != cur)
                child = child->right;
            if(child->right == NULL){
                child->right = cur;
                cur = cur->left;
            }
            else{
                child->right = NULL;
                int lh = 0 , rh = 0;
                Tree* temp = cur->left;
                while(temp != NULL){
                    lh++;
                    temp = temp->right;
                }
                temp = cur->right;
                while(temp != NULL){
                    rh++;
                    temp = temp->left;
                }
                result = __max(result, lh+rh+1);
                cur = cur->right;
            }
        }
    }
    return result;
}
int GetMaxValTree(Tree* t){
    if(t == NULL)
        return INT_MIN;
    int max = t->key;
    int lmax = GetMaxValTree(t->left);
    int rmax = GetMaxValTree(t->right);
    if(lmax > max)
        max = lmax;
    if(rmax > max)
        max = rmax;
    return max;
}
int GetMinValTree(Tree* t){
    if(t == NULL)
        return INT_MAX;
    int min = t->key;
    int lmin = GetMinValTree(t->left);
    int rmin = GetMinValTree(t->right);
    if(lmin < min)
        min = lmin;
    if(rmin < min)
        min = rmin;
    return min;
}
Tree* GetMinValNodeBinaryTree(Tree* t){
    Tree* cur = t;
    while(cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}
int GetDepthTree(Tree* t){
    if(t == NULL)
        return 0;
    else{
        int ldepth = GetDepthTree(t->left);
        int rdepth = GetDepthTree(t->right);
        return (ldepth > rdepth) ? ldepth+1 : rdepth+1;  
    }
}
void GetAllNodeAtSameLevelTree(Tree* t, int level){
    if(t == NULL)
        return;
    if(level == 1)
        printf("%d ", t->key);
    if(level > 1){
        GetAllNodeAtSameLevelTree(t->left, level-1);
        GetAllNodeAtSameLevelTree(t->right, level-1);
    }
}
void GetAllLeafNodeTree(Tree* t){
    if(!t)
        return;
    if(!t->left && !t->right){
        printf("%d ", t->key);
        return;
    }
    if(t->left)
        GetAllLeafNodeTree(t->left);
    if(t->right)
        GetAllLeafNodeTree(t->right);
}
void GetAllInternalNodeTree(Tree* t){
    if(t == NULL || (t->left == NULL && t->right == NULL))
        return;
    if(t->left != NULL|| t->right != NULL)
        printf("%d ", t->key);
    GetAllInternalNodeTree(t->left);
    GetAllInternalNodeTree(t->right);
}
int GetIndexTree(char* arr, int sidx, int eidx, char val){
    int i;
    for(i=sidx; i<=eidx; i++)
        if(arr[i] == val)
            return i;
}
int GetNumNodeTree(Tree* t){
    if(t == NULL)
        return 0;
    else
        return GetNumNodeTree(t->left) + GetNumNodeTree(t->right) + 1;
}
Tree* CompoundInPreTree(char* in, char* pre, int sidx, int eidx){
    // Compound Inorder-Preorder Traversal Trees to 1 tree
    static int preidx = 0;
    if(sidx > eidx)
        return NULL;
    Tree* t = CreateTree(pre[preidx++]);
    if(sidx == eidx)
        return t;
    int inidx = GetIndexTree(in, sidx, eidx, t->key);
    t->left = CompoundInPreTree(in, pre, sidx, inidx-1);
    t->right = CompoundInPreTree(in, pre, inidx+1, eidx);
    return t;
}
int GetWidthTree(Tree* t, int level){
    if(t == NULL)
        return 0;
    if(level == 1)
        return 1;
    if(level > 1)
        return GetWidthTree(t->left, level-1)+GetWidthTree(t->right, level-1);
}
int GetMaxValArray(int* arr, int n){
    int max = arr[0];
    int i;
    for(i=0; i<n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}
void GetMaxWidthRecursionTree(Tree* t, int* count, int level){
    if(t){
        count[level]++;
        GetMaxWidthRecursionTree(t->left, count, level+1);
        GetMaxWidthRecursionTree(t->right, count, level+1);
    }
}
int GetMaxWidthTree(Tree* t){
    int level = 0;
    int width;
    int h = GetDepthTree(t);
    int* count = (int*)calloc(sizeof(int), h);
    GetMaxWidthRecursionTree(t, count, level);
    return GetMaxValArray(count, h);
}
void GetDistFromRootTree(Tree* t, int dist){
    if(t == NULL || dist < 0)
        return;
    if(dist == 0){
        printf("%d ", t->key);
        return;
    }
    GetDistFromRootTree(t->left, dist-1);
    GetDistFromRootTree(t->right, dist-1);
}
bool GetAncestorsFromKey(Tree* t, int key){
    if(t == NULL)
        return false;
    if(t->key == key)
        return true;
    if(GetAncestorsFromKey(t->left, key)|| GetAncestorsFromKey(t->right, key) ){
        printf("%d ", t->key);
        return true;
    }
    return false;
}
bool IsIdenticalTree(Tree* t1, Tree* t2){
    if(t1 == NULL && t2 == NULL)
        return true;
    if(t1 == NULL || t2 == NULL)
        return false;
    return (t1->key == t2->key && IsIdenticalTree(t1->left, t2->left) && IsIdenticalTree(t1->right, t2->right));
}
bool IsSubTree(Tree* t1, Tree* t2){
    if(t2 == NULL)//Subtree
        return true;
    if(t1 == NULL)//Tree
        return false;
    if(IsIdenticalTree(t1, t2))
        return true;
    return IsSubTree(t1->left, t2) || IsSubTree(t1->right, t2);
}
void ConnectSameLevelNodeTree(Tree* t){
    if(t == NULL)
        return;
    queue<Tree*> q;
    q.push(t);
    while(!q.empty()){
        int size = q.size();
        Tree* prev = NULL;
        while(size--){
            Tree* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            if(prev != NULL)
                prev->nextRight = temp;
            prev = temp;
        }
        prev->nextRight = NULL;
    }
}
Tree* DeletionTree(Tree* t, int key){
    if(t == NULL)
        return NULL;
    if(t->left == NULL && t->right == NULL){
        if(t->key == key)
            return NULL;
        else
            return t;
    }
    Tree* key_node = NULL;
    Tree* temp = NULL;
    Tree* last = NULL;
    Tree* q[100];
    int front = 0, rear = 0;
    q[rear++] = t;
    while(front < rear){
        temp = q[front++];
        if(temp->key == key)
            key_node = temp;
        if(temp->left){
            last = temp;
            q[rear++] = temp->left;
        }
        if(temp->right){
            last = temp;
            q[rear++] = temp->right;
        }
    }
    if(key_node != NULL){
        key_node->key = temp->key;
        if(last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        free(temp);
    }
    return t;
}
Tree* DeletionBinaryTree(Tree* t, int key){
    if(t == NULL)
        return t;
    if(t->key > key)
        t->left = DeletionBinaryTree(t->left, key);
    else if(t->key < key)
        t->right = DeletionBinaryTree(t->right, key);
    else{
        if(t->left == NULL){
            Tree* temp = t->right;
            free(t);
            return temp;
        }
        else if(t->right == NULL){
            Tree* temp = t->left;
            free(t);
            return temp;
        }
        Tree* temp = GetMinValNodeBinaryTree(t->right);
        t->key = temp->key;
        t->right = DeletionBinaryTree(t->right, temp->key);
    }
    return t;
}
Tree* DeletionAllBinaryTree(Tree* t){
    Tree* temp;
    if(t != NULL){
        DeletionAllBinaryTree(t->left);
        DeletionAllBinaryTree(t->right);
        temp = t;
        free(temp);
    }
    return t;
}
Tree* InsertBinaryTree(Tree *root, int key)
{
    if (root == NULL)
        return CreateTree(key);
    if (key < root->key)
        root->left = InsertBinaryTree(root->left, key);
    else if (key > root->key)
        root->right = InsertBinaryTree(root->right, key);
    return root;
}
void InsertBinaryTreeByIterative(Tree* t, int key){
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->key = key;
    node->left = node->right = NULL;
    if(!t){
        t = node;
        return;
    }
    Tree* prev = NULL;
    Tree* temp = t;
    while(temp){
        if(temp->key > key){
            prev = temp;
            temp = temp->left;
        }
        else if(temp->key < key){
            prev = temp;
            temp = temp->right;
        }
    }
    if(prev->key > key)
        prev->left = node;
    else
        prev->right = node;
}
void TreeSort(int *arr, int size)
{
    int i = 0, index = 0;
    Tree *root = NULL;
    for (i = 0; i < size; i++)
        root = InsertBinaryTree(root, arr[i]);
    InorderTree(root, arr, &index, true);
}
Tree* SearchNodeBinaryTree(Tree* t, int key){
    if(t == NULL || t->key == key)
        return t;
    if(t->key < key)
        return SearchNodeBinaryTree(t->right, key);
    return SearchNodeBinaryTree(t->left, key);
}
//Threaded Binary Tree
/* 장점
 * - 메모리 절약, NULL 포인터 없음
 * 단점
 * - 삽입/삭제 복잡성, 디버깅 어려움, 균형이 안잡히면 메모리 사용량 증가
*/ 
typedef struct ThreadedBinaryTree{
    int data;
    struct ThreadedBinaryTree* left;
    struct ThreadedBinaryTree* right;
    bool rightTread;
}TBTree;
TBTree* LeftMostTBTree(TBTree* t){
    if(t == NULL)
        return NULL;
    while(t->left != NULL)
        t = t->left;
    return t;
}
void InorderTBTree(TBTree* t){
    TBTree* cur = LeftMostTBTree(t);
    while(cur != NULL){
        printf("%d ", cur->data);
        if(cur->rightTread)
            cur = cur->right;
        else
            cur = LeftMostTBTree(cur->right);
    }
}

//Ternary Search Tree
// Trie 의 자식 노드가 이진 검색 트리로 정렬되는 트리
typedef struct TernarySearchTree{
    char data;
    int end;
    int isleaf;
    unsigned int isEndofString = 1;
    TSTree* left, *eq, *right;
}TSTree;
TSTree* CreateTSTree(char data){
    TSTree* temp = (TSTree*)malloc(sizeof(TSTree));
    temp->data = data;
    temp->isEndofString = 0;
    temp->end = 0;
    temp->isleaf = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
void InsertTSTree(TSTree** tst, char* str){
    if(!(*tst))
        *tst = CreateTSTree(*str);
    if((*str) < (*tst)->data)
        InsertTSTree(&((*tst)->left), str);
    else if((*str) > (*tst)->data)
        InsertTSTree(&((*tst)->right), str);
    else{// if((*str) == (*tst)->data)
        if(*(str+1))
            InsertTSTree(&((*tst)->eq), str+1);
        else{
            (*tst)->isEndofString = 1;
            (*tst)->isleaf = 1;
        }
    }
}
void InsertPosTSTree(TSTree** tst, char* str, int pos=0){
    if(!(*tst))
        *tst = CreateTSTree(str[pos]);
    if((str[pos]) < (*tst)->data)
        InsertPosTSTree(&((*tst)->left), str, pos);
    else if((str[pos]) > (*tst)->data)
        InsertPosTSTree(&((*tst)->right), str, pos);
    else{// if((*str) == (*tst)->data)
        if(str[pos+1] == '\0')
            (*tst)->end = 1;
        else
            InsertPosTSTree(&((*tst)->eq), str, pos+1);
    }
}
int IsLeafTSTree(TSTree* tst){
    return tst->isleaf == 1;
}
int IsFreeNodeTSTree(TSTree* tst){
    if(tst->left || tst->eq || tst->right)
        return 0;
    return 1;
}
int DeletionNodeTSTree(TSTree* tst, char* str, int level, int n){
    if(tst == NULL)
        return 0;
    if(str[level+1] == '\0'){
        if(IsLeafTSTree(tst)){
            tst->isleaf = 0;
            return IsFreeNodeTSTree(tst);
        }
        else
            return 0;
    }
    else{
        if(str[level] < tst->data)
            DeletionNodeTSTree(tst->left, str, level, n);
        else if(str[level] > tst->data)
            DeletionNodeTSTree(tst->right,str, level, n);
        else if(str[level] == tst->data){
            if(DeletionNodeTSTree(tst->eq, str, level+1, n)){
                free(tst->eq);
                return !IsLeafTSTree(tst) && IsFreeNodeTSTree(tst);
            }
        }
    }
    return 0;
}
void PrintAllDataTSTRee(TSTree* tst, char* str, int level){
    if(!tst)
        return;
    PrintAllDataTSTRee(tst->left, str, level);
    str[level] = tst->data;
    if(tst->isleaf == 1){
        str[level+1] = '\0';
        printf("%s\n", str);
    }
    PrintAllDataTSTRee(tst->eq, str, level+1);
    PrintAllDataTSTRee(tst->right, str, level);
}
void PrintAllCharTSTree(char** sug, int size, char* pat){
    if(size == 0)
        printf("None\n");
    else{
        for(int i =0; i<size; i++){
            printf("%s%s\n", pat, sug[i]);
            free(sug[i]);
        }
    }
    free(sug);
}
void TraversalTSTree(TSTree* tst, char* buffer, int depth, char* ret[], int* count){
    if(tst){
        TraversalTSTree(tst->left, buffer, depth, ret, count);
        buffer[depth] = tst->data;
        if(tst->end || tst->isEndofString){
            buffer[depth+1] = '\0';
            ret[*count] = strdup(buffer);
            (*count)++;
            printf("%s\n", buffer);
        }
        TraversalTSTree(tst->eq, buffer, depth+1, ret, count);
        TraversalTSTree(tst->right, buffer, depth, ret, count);
    }
}
char** TraversalUtilTSTree(TSTree* tst, char* pat, int* count){
    char buffer[1001];
    char** ret = (char**)malloc(1000 * sizeof(char*));
    TraversalTSTree(tst, buffer, 0, ret, count);
    if(tst->end == 1){
        ret[*count] = strdup(pat);
        (*count)++;
    }
    return ret;
}
int SearchTSTree(TSTree* tst, char* str){
    if(!tst)
        return 0;
    if(*str < tst->data)
        return SearchTSTree(tst->left, str);
    else if(*str > tst->data)
        return SearchTSTree(tst->right, str);
    else{
        if(*(str+1) == '\0')
            return tst->isEndofString;
        return SearchTSTree(tst->eq, str+1);
    }
}
char** TextAutoCompleteFeatureTSTree(TSTree* tst, char* pat, int* count){
    char** words;
    int pos;
    if(strlen(pat) == 0)
        return NULL;
    while(tst && pos < strlen(pat)){
        if(tst->data > pat[pos])
            tst = tst->left;
        else if(tst->data < pat[pos])
            tst = tst->right;
        else if(tst->data == pat[pos]){
            tst = tst->eq;
            pos++;
        }
        else
            return NULL;
    }
    words = TraversalUtilTSTree(tst, pat, count);
    return words;
}
int MaxValAmongThreeVal(int a, int b, int c){
    int max;
    if(a >= b && a >= c)
        max = a;
    else if( b >= a && b >= c)
        max = b;
    else
        max = c;
}
int MaxlengthWordTSTree(TSTree* tst){
    if(tst == NULL)
        return 0;
    return MaxValAmongThreeVal(MaxlengthWordTSTree(tst->left), MaxlengthWordTSTree(tst->eq), MaxlengthWordTSTree(tst->right));
}

typedef struct AVLTree{
    int key, height; 
    struct AVLTree *left;
    struct AVLTree *right; 
}AVL; 
int GetHeightAVLTree(AVL* avl){ 
    if (avl == NULL) 
        return 0; 
    return avl->height; 
} 
AVL* CreateAVLTree(int key){
    AVL* avl = (AVL*)malloc(sizeof(AVL)); 
    avl->key = key;
    avl->height = 1; 
    avl->left = avl->right = NULL;
    return(avl); 
}
AVL* RRotateAVLTree(AVL* avl){
    AVL* internal = avl->left; 
    AVL* leaf = internal->right;
    internal->right = avl;
    avl->left = leaf; 
    avl->height = __max(GetHeightAVLTree(avl->left), GetHeightAVLTree(avl->right)) + 1;
    internal->height = __max(GetHeightAVLTree(internal->left), GetHeightAVLTree(internal->right)) + 1;
    return internal;
} 
AVL* LRotateAVLTree(AVL* avl){
    AVL* internal = avl->right;
    AVL* terminal = internal->left;
    internal->left = avl;
    avl->right = terminal;
    avl->height = __max(GetHeightAVLTree(avl->left), GetHeightAVLTree(avl->right)) + 1;
    internal->height = __max(GetHeightAVLTree(internal->left), GetHeightAVLTree(internal->right)) + 1;
    return internal;
}
int GetBalanceAVLTree(AVL* avl){
    if (avl == NULL)
        return 0;
    return GetHeightAVLTree(avl->left) - GetHeightAVLTree(avl->right);
} 
AVL* InsertAVLTree(AVL* avl, int key){
    if (avl == NULL)
        return CreateAVLTree(key);
    if (key < avl->key)
        avl->left  = InsertAVLTree(avl->left, key);
    else if (key > avl->key)
        avl->right = InsertAVLTree(avl->right, key);
    else
        return avl;
    avl->height = 1 + __max(GetHeightAVLTree(avl->left), GetHeightAVLTree(avl->right));
    int bal = GetBalanceAVLTree(avl);
    if (bal > 1 && key < avl->left->key)
        return RRotateAVLTree(avl);
    if (bal < -1 && key > avl->right->key)
        return LRotateAVLTree(avl);
    if (bal > 1 && key > avl->left->key){
        avl->left =  LRotateAVLTree(avl->left); 
        return RRotateAVLTree(avl); 
    }
    if (bal < -1 && key < avl->right->key){ 
        avl->right = RRotateAVLTree(avl->right);
        return LRotateAVLTree(avl);
    }
    return avl;
}
AVL* GetMinValNodeAVLTree(AVL* avl){
    AVL* cur = avl;
    while(cur->left != NULL)
        cur = cur->left;
    return cur;
}
AVL* DeletionAVLTree(AVL* avl, int key){
    if(avl == NULL)
        return avl;
    if(avl->key > key)
        avl->left = DeletionAVLTree(avl->left, key);
    else if(avl->key < key)
        avl->right = DeletionAVLTree(avl->right, key);
    else{
        if(avl->left == NULL || avl->right == NULL){
            AVL* temp = avl->left ? avl->left : avl->right;
            if(temp == NULL){
                temp = avl;
                avl = NULL;
            }
            else
                *avl = *temp;
            free(temp);
        }
        else{
            AVL* temp = GetMinValNodeAVLTree(avl->right);
            avl->key = temp->key;
            avl->right = DeletionAVLTree(avl->right, temp->key);
        }
    }
    if(avl == NULL)
        return avl;
    avl->height = 1+ __max(GetHeightAVLTree(avl->left), GetHeightAVLTree(avl->right));
    int bal = GetBalanceAVLTree(avl);
    if(bal > 1 && GetBalanceAVLTree(avl->left) >= 0)
        return RRotateAVLTree(avl);
    if(bal > 1 && GetBalanceAVLTree(avl->left) < 0){
        avl->left = LRotateAVLTree(avl->left);
        return RRotateAVLTree(avl);
    }
    if(bal < -1 && GetBalanceAVLTree(avl->right) <= 0)
        return LRotateAVLTree(avl);
    if(bal < -1 && GetBalanceAVLTree(avl->right) > 0){
        avl->right = RRotateAVLTree(avl->right);
        return LRotateAVLTree(avl);
    }
    return avl;
}
void PreorderAVLTree(AVL* avl){
    if(avl != NULL){
        printf("%d ", avl->key);
        PreorderAVLTree(avl->left);
        PreorderAVLTree(avl->right);
    }
}















































//Queue Using Linked List and data type is char
int main(){
    SStack *s = CreateSStack();
    int arr[] = {3, 2, 6, 1, 8, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        PushSStack(s, arr[i]);
        GetMinSStack(s);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        PopSStack(s);
        GetMinSStack(s);
    }
    DestroySStack(s);
    return 0;
}
/* char str1[] = "AGGTAB";//AGGTAB ,geek
char str2[] = "GXTXAYB";//GXTXAYB , eke
char str3[] = "axxxy";
char str4[] = "geeksforgeeks";//forgeeksskeegfor, geeksforgeeks, abcde
char str5[] = "baaabab";// AAAAAAAAAAAAAAAAAB, AABAACAADAABAAABAA
char str6[] = "GEEKS FOR GEEKS";// AAAAB, AABA,
char dic[5][5] = {"abb", "abc", "xyz", "xyy", "bbb"};
char pat[] = "GEEK";
int arr[] = {1, 4, 5, 3, 12, 10};
int n = sizeof(arr)/sizeof(arr[0]);
IncMonotonicStack(arr, n); */
/* char *r1 = PrintLongestPalindromicSubsequence(str4);
int r2 = CountLongestCommonSubsequence(str1, str2);
printf("%s\n", r1);
printf("\n\n%d\n", r2);
PatternSearchingWithZ(str5, str6);

printf("r2 %d\n", r2);

free(r2); */
/*     int temp = 0;
    int arr[] = {11, 12, 11, 50, 8, 30, 1, 60, 2, 80, 0, 50, 5, 108};
    char arr2[][20] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"};

    int n = sizeof(arr) / sizeof(int);
    int m = sizeof(arr2) / sizeof(arr2[0]);
     int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
     while (temp < n)
         INTPRINT(arr[temp++]); */
/*     char str1[] = "AGGTAB";//AGGTAB ,geek
    char str2[] = "GXTXAYB";//GXTXAYB , eke
    char str3[] = "axxxy";
    char str4[] = "geeksforgeeks";//forgeeksskeegfor, geeksforgeeks, abcde
    char str5[] = "GEEKS FOR GEEKS";// AAAAAAAAAAAAAAAAAB, AABAACAADAABAAABAA
    char str6[] = "GEEK";// AAAAB, AABA, */

/*     int r1 = CountLongestCommonSubsequence(str1, str2);
    int r2 = CountLongestCommonSubsequence2(str1, str2);
    printf("r1=%d  r2=%d\n", r1, r2);
    int r3 = ShortestCommonSupersequence2(str1, str2);
    printf("r3=%d\n", r3);
    char *r4 = ShortestCommonSupersequence(str1, str2);
    printf("%s\n", r4);
    free(r4);
    char* r5 = FindLongestRepeatingSubsequence(str3);
    printf("%s\n", r5); */