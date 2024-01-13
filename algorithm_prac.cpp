#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

// 자동 정렬 shift + alt + F
#define INTPRINT(x)                  \
    do                            \
    {                             \
        printf(#x " is %d\n", x); \
    } while (0)
#define FLOATPRINT(x)                  \
    do                            \
    {                             \
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
void Swap(int *a, int *b)
{
    if (a != b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

typedef struct Tree{
    int key;
    struct Tree* left;
    struct Tree* right;
}Tree;
Tree* createNode(int key){
    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Tree* Insert(Tree* root, int key){
    if(root == NULL)
        return createNode(key);
    if(key < root->key)
        root->left = Insert(root->left, key);
    else if(key > root->key)
        root->right = Insert(root->right, key);
    return root;
}
void InorderTraversal(Tree* root, int* arr, int* idx){
    if(root != NULL){
        // 1) printf() 없이 array에 정렬된 배열 저장

        InorderTraversal(root->left, arr, idx);
        arr[(*idx)++] = root->key;
        InorderTraversal(root->right, arr, idx);

        /* 2) pritnf()를 이용하여 정렬된 배열 출력

        InorderTraversal(root->left);
        printf("%d ", root->key);
        InorderTraversal(root->right);
        */
    }
}

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
        arr[j + 1] = key;        // Insert key value(if key is lowest value, j = -1, So, j+1 = 0)
    }
}
void PartialInsertion(int* arr, int first, int last, int gap){
    int i, j, key;
    for(i = first+gap; i<=last; i+=gap){
        key = arr[i];
        for(j=i-gap; j>=first && arr[j] > key; j-=gap)
            arr[j+gap] = arr[j];
        arr[j+gap] = key;
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
 * 2) Insert the number of element's value into temperary array
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
void FBucketSort(float* farr, int fn){
    std::vector<float> b[fn];
    int i=0, bi, idx, j;
    for(i=0; i<fn; i++){
        bi = fn * farr[i];
        b[bi].push_back(farr[i]);
    }
    for(i=0; i<fn; i++)
        std::sort(b[i].begin(), b[i].end());
    idx = 0;
    for(i=0; i<fn; i++)
        for(j=0; j<b[i].size(); j++)
            farr[idx++] = b[i][j];
}

/* 1) Find min, max value in array
 * 2) Find bingo in array
 * 3) Swap bingo and arr[i](i= 0, 1, 2, ..., size-1)
 * 
*/
void BingoSort(int* arr, int size){
    int b = arr[0];
    int nb = arr[0];
    int i;
    int max, n_pos, s_pos;
    for(i=1; i < size; i++){
        b = (b < arr[i]) ? b : arr[i];//min value
        nb = (nb > arr[i]) ? nb : arr[i];//max value
    }
    max = nb;
    n_pos = 0;
    while(b < nb){
        s_pos = n_pos;
        for(i=s_pos; i<size; i++){
            if(arr[i] == b){
                Swap(&arr[i], &arr[n_pos]);
                n_pos++;
            }
            else if(arr[i] < nb)
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
//Using interval sequence for calculating interval
int CalculateGap(int size){
    int h = 1;
    while(h<size/3)
        h = 3*h +1;
    return h;
}
void ShellSort(int* arr, int size){
    int gap, i, key, j;
    //If not use CalculateGap(), use "gap = size/2; gap > 0; gap/=2" in for()
    //If use CalculateGap(), use "gap = CalculateGap(size); gap > 0; gap /= 3" in for()
    for(gap = size/2; gap > 0; gap/=2){
        for(i=gap; i<size; i++){
            key = arr[i];
            for(j=i; j>=gap && arr[j-gap] > key; j -=gap)
                arr[j] = arr[j-gap];
            arr[j]=key;
        }
    }
}

/* 1) Execute partial insertion sort
 * 2) Execute merge() 
*/
void TimSort(int* arr, int size) {
    int i, j, left, mid, right;
    for (i = 0; i < size; i += THRESHOLD)
        PartialInsertion(arr, i, (i+THRESHOLD-1 < size-1) ? (i+THRESHOLD-1) : (size-1), 1);
    for (j = THRESHOLD; j < size; j *= 2) {
        for (left = 0; left < size; left += 2 * j) {
            mid = left + j - 1;
            right = (left+2*j-1 < size-1) ? (left+2*j-1) : (size-1);
            Merge(arr, left, mid, right);
        }
    }
}

/*
 *
 *
 * 
*/
void CombSort(int* arr, int size) {
    int gap = size;
    int i;
    bool swapped = true;
    while (gap > 1 || swapped) {
        if (gap > 1)
            gap = gap * 10 / 13;
        else
            gap = 1;
        swapped = false;
        for (i = 0; i + gap < size; i++) {
            if (arr[i] > arr[i + gap]) {
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
void PigeonholeSort(int arr[], int size) {
    int min = arr[0], max = arr[0];
    int i, index;
    int p_size;
    int* p_hole;
    for (i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    p_size = max - min + 1;
    p_hole = (int*)malloc(p_size * sizeof(int));
    for ( i = 0; i < p_size; i++)
        p_hole[i] = 0;
    for ( i = 0; i < size; i++)
        p_hole[arr[i] - min]++;
    index = 0;
    for (i = 0; i <p_size; i++) {
        while (p_hole[i] > 0) {
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
void CycleSort(int* arr, int size) {
    int c_start, item, pos, i;
    for (c_start = 0; c_start < size - 1; c_start++) {
        item = arr[c_start];
        pos = c_start;
        for (i = c_start + 1; i < size; i++)// 해당 원소의 정확한 위치 찾기 
            if (arr[i] < item) 
                pos++;
        if (pos == c_start)// 이미 제자리에 있는 경우 건너뛰기
            continue;
        while (item == arr[pos])// 현재 원소를 올바른 위치로 이동
            pos++;
        Swap(&arr[pos], &item);
        while (pos != c_start) {// 나머지 순환 도는 부분 처리
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
void CycleSort2(int* arr, int size){
    int i=0;
    int correct=1;
    while(i < size){
        correct = arr[i]-1;
        if(i != correct)
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
void cocktailSort(int* arr, int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {// 오른쪽 방향으로 배열을 통과하면서 큰 값들을 정렬
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                Swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        // 가장 큰 값이 마지막에 위치하도록 end 값을 감소
        end--;
        // 왼쪽 방향으로 배열을 통과하면서 작은 값들을 정렬
        swapped = false;
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                Swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        // 가장 작은 값이 첫 번째에 위치하도록 start 값을 증가
        start++;
    }
}


void BitonicMerge(int arr[], int low, int cnt, int dir) {
    int i, k;
    if (cnt > 1) {
        k = cnt / 2;
        for (i = low; i < low + k; i++)
            if ( (arr[i] > arr[i + k]) == (dir == 1))
                Swap(&arr[i], &arr[i+k]);
        BitonicMerge(arr, low, k, dir);
        BitonicMerge(arr, low + k, k, dir);
    }
}
void BitonicSort(int* arr, int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        // 비트단위로 정렬하는 함수 호출 (증가하는 순서)
        BitonicSort(arr, low, k, 1);
        // 비트단위로 정렬된 배열을 역순으로 정렬하는 함수 호출 (감소하는 순서)
        BitonicSort(arr, low + k, k, 0);
        // 비트단위로 정렬된 두 배열을 합병
        BitonicMerge(arr, low, cnt, dir);
    }
}

void TreeSort(int* arr, int size){
    int i = 0, index = 0;
    Tree* root = NULL;
    for(i=0; i<size; i++)
        root = Insert(root, arr[i]);
    InorderTraversal(root, arr, &index);
}

void TowerOfHanoi(int num, char from, char temp, char to){
    if(!num)
        return;
    TowerOfHanoi(num-1, from, to, temp);
    printf("Move %d from %c to %c\n",num, from, to);
    TowerOfHanoi(num-1, temp, from, to);
}

int main()
{
    int temp = 0;
    int arr[] = {64, 25, 12, 22, 11, 52, 29, 10};
    int n = sizeof(arr) / sizeof(int);
    int tags[n];
    for (int i = 0; i < n; i++)
        tags[i] = i;
    TowerOfHanoi(3,'A','B','C');
    TreeSort(arr, n);
    while (temp < n)
        INTPRINT(arr[temp++]);
    return 0;
}