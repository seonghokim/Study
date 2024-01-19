#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>

// 자동 정렬 shift + alt + F
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
typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;
typedef struct Tree
{
    int key;
    struct Tree *left;
    struct Tree *right;
} Tree;
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void InitStack(Stack **s)
{
    *s = NULL;
}
int isEmpty(Stack *s)
{
    if (s == NULL)
        return 1;
    return 0;
}
void Push(Stack **s, int x)
{
    Stack *p = (Stack *)malloc(sizeof(*p));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    p->data = x;
    p->next = *s;
    *s = p;
}
int Pop(Stack **s)
{
    int x;
    Stack *temp;
    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    return x;
}
int Top(Stack *s)
{
    return s->data;
}
void SortedInsert(Stack **s, int x)
{
    int temp;
    if (isEmpty(*s) || x > Top(*s))
    {
        Push(s, x);
        return;
    }
    temp = Pop(s);
    SortedInsert(s, x);
    Push(s, temp);
}
void SortStack(Stack **s)
{
    int x;
    if (!isEmpty(*s))
    {
        x = Pop(s);
        SortStack(s);
        SortedInsert(s, x);
    }
}
void PrintStack(Stack *s)
{
    while (s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

Tree *createNode(int key)
{
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Tree *Insert(Tree *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = Insert(root->left, key);
    else if (key > root->key)
        root->right = Insert(root->right, key);
    return root;
}
void InorderTraversal(Tree *root, int *arr, int *idx)
{
    if (root != NULL)
    {
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

void TreeSort(int *arr, int size)
{
    int i = 0, index = 0;
    Tree *root = NULL;
    for (i = 0; i < size; i++)
        root = Insert(root, arr[i]);
    InorderTraversal(root, arr, &index);
}

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
void ReverseString(char* str){
    int n = strlen(str);
    int i, j;
    for(i=0, j=n-1; i<j; i++, j--){
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
int arr[MAXN];      // original array
int block[SQRSIZE]; // decomposed array
int blk_sz;         // block size
void UpdateBlock(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}
int ArrayQuery(int l, int r)
{
    int sum = 0;
    while (l < r and l % blk_sz != 0 and l != 0)
        sum += arr[l++];
    while (l + blk_sz - 1 <= r)
    {
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
        sum += arr[l++];
    return sum;
}
void BlockPreprocess(int input[], int n)
{
    int blk_idx = -1, i;
    blk_sz = sqrt(n);
    for (i = 0; i < n; i++)
    {
        arr[i] = input[i];
        if (i % blk_sz == 0)
            blk_idx++;
        block[blk_idx] += arr[i];
    }
}

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
        last = arr[i];
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
int CountLongestCommonSubsequence(char *str1, char *str2){
    int n = strlen(str1);
    int m = strlen(str2);
    int prev[m + 1], cur[m + 1];
    int min = (n > m) ? m : n;
    bool isduplication[m] = {false, };
    int i, j;
    memset(isduplication, false, sizeof(isduplication));
    memset(prev, 0, sizeof(prev));
    memset(cur, 0, sizeof(cur));
    for (i = 1; i < n + 1; i++){
        for (j = 1; j < m + 1; j++){
            if (str1[i - 1] == str2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = 0 + __max(cur[j - 1], prev[j]);
        }
        memcpy(prev, cur, sizeof(cur));
    }
    for (i = 1, j = 0; i < m + 1; i++, j++){ // Print LCS
        if (isduplication[cur[i]] == false){
            printf("%c", str2[j]);
            isduplication[cur[i]] = true;
        }
    }
    printf("\n");
    return cur[m]; // Return LCS's length
}
int CountLongestCommonSubsequence2(char* str1, char* str2){
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m+1][n+1];
    int i, j;
    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = __max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
char* PrintLongestCommonSubsequence3(char* str1, char* str2){
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m+1][n+1];
    int i, j;
    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = __max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int idx = dp[m][n];
    char* lcs = (char*)malloc((idx+1) * sizeof(char));
    lcs[idx] = '\0';
    i=m;
    j=n;
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            lcs[idx-1] = str1[i-1];
            i--;
            j--;
            idx--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}
char* ShortestCommonSupersequence(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1+1][len2+1];
    int count  = 0;
    int i, j, idx;
    int scslen;
    //Initialize
    for(i=0; i<=len1; i++){
        for(j=0; j<=len2; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1+ __min(dp[i-1][j] , dp[i][j-1]);
        }
    }
    printf("dp[len1][len2] of SCS: %d\n", dp[len1][len2]);
    scslen = (len1 + len2+1);
    char* scs = (char*)malloc((scslen+1) * sizeof(char));
    i = len1;
    j = len2;
    idx = scslen;
    //Compose Shortest Common Sequence
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            scs[idx--] = str1[i-1];
            i--;
            j--;
            count++;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            scs[idx--] = str2[j-1];//scs[idx--] = str2[j-1];
            j--;
            count++;
        }
        else{
            scs[idx--] = str1[i-1];
            i--;
            count++;
        }
    }
    while(i>0){
        scs[idx--] = str1[i-1];
        i--;
        count++;
    }
    while(j>0){
        scs[idx--] = str2[j-1];
        j--;
        count++;
    }
    printf("Number of SCS: %d\n", count);
    return scs;
}
int ShortestCommonSupersequence2(char* str1, char* str2){
    int m  = strlen(str1);
    int n = strlen(str2);
    int k = CountLongestCommonSubsequence2(str1, str2);
    return (m+n-k);
}
int CalculateOverlappingInString(char *str1, char *str2, char *overlap)
{
    int max = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i;
    for (i = 1; i <= len1; i++){
        if (strncmp(str1 + len1 - i, str2, i) == 0){
            if (i > max){
                max = i;
                strcpy(overlap, str1);
                strcat(overlap, str2 + i);
            }
        }
    }
    for (i = 1; i <= len2; i++){
        if (strncmp(str1, str2 + len2 - i, i) == 0){
            if (i > max){
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
    while (len > 1){
        int max = -1;
        int idx1 = 0, idx2 = 0, i = 0, j = 0;
        int cur_overlap = 0;
        for (i = 0; i < len; i++){
            for (j = i + 1; j < len; j++){
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
            strcpy(arr[i - 1],arr[i]);
        len--; 
    }
    free(overlap);
    free(merge_str);
    return arr[0];
}
char* FindLongestRepeatingSubsequence(char *str){
    int n = strlen(str);
    int dp[n+1][n+1];
    int i, j, idx;
    memset(dp, 0, sizeof(dp));
    // Counting Number of LRS
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(str[i-1]==str[j-1] && i!=j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = __max(dp[i][j-1], dp[i-1][j]);
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    //return dp[n][n]; --> Function type : int
    // Print LRS
    int lrslen = dp[n][n];
    char* lrs = (char*)malloc((lrslen+1) * sizeof(char));
    i = j = n;
    idx = lrslen;
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j-1]+1){
            lrs[idx--] = str[i-1];
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j])
            i--;
        else
            j--;
    }
    return lrs;
}
int CountLongestPalindromicSubsequence(char* str){
    int n = strlen(str);
    char temp[n];
    int i, j;
    strcpy(temp, str); //--> result: 5
    //memcpy(temp, str, n); // --> result: 5
    ReverseString(temp);
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(str[i-1] == temp[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = __max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}
char* PrintLongestPalindromicSubsequence(char* str){
    int n = strlen(str);
    char rev[n];
    memcpy(rev, str, sizeof(rev));
    ReverseString(rev);
    return PrintLongestCommonSubsequence3(str, rev);
}
void PrintLongestPalindromicSubString(char* str, int low, int high){
    for(int i =low; i<=high; i++)
        printf("%c",str[i]);
    printf("\n");
}
int CountLongestPalindromicSubString(char* str){
    int n = strlen(str);
    int start=0, end =1;
    int low, high;
    int i;
    for(i=0; i<n; i++){
        low = i-1;
        high = i;
        while(low >= 0 && high < n && str[low] == str[high]){
            if(high-low+1 > end){
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
        low = i-1;
        high = i+1;
        while(low >= 0 && high < n && str[low] == str[high]){
            if(high-low+1 > end){
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
    }
    PrintLongestPalindromicSubString(str, start, start+end-1);
    return end;
}

// Condition of Palindrome:
// 1) At most, one character occurs an odd number of times
// 2) All characters occur an even number of times
// Character number = 26
bool IsPalindrome(char* str){
    int l = 0;
    int r = strlen(str)-1;
    while(l < r)
        if(str[l++] != str[r--])
            return false;
    return true;
}
bool CanPalindrome(char* str){
    int bit = 0, mask =0;
    int i, x;
    for(i=0; str[i]!='\0'; i++){
        if((str[i]-'A') < 32)
            str[i] = tolower(str[i]);
        x = str[i]-'a';
        mask = 1 << x;//문자 번호에 해당하는 bit = 1
        bit ^= mask;// bit는 문자 번호에 해당하는 bit 값 변화시킴(문자 개수 홀수: 1, 짝수: 0)
    }
    return (bit & (bit-1) == 0);//최종적으로 bit에는 1이 1개 있어야 함
}
bool IsRotationOfPalindrome(char* str){
    if(IsPalindrome(str))
        return true;
    int n = strlen(str);
    int i, j, idx;
    for(i=0; i<n; i++){
        char r_str[n+1];
        strncpy(r_str, (str+i), n-i);
        strncpy((r_str+n-i), str, i);
        if(IsPalindrome(r_str))
            return true;
    }
    return false;
}

int CountStringPalindromeByAddingMinChar(char* str){
    int n = strlen(str);
    int start = 0, end = n-1, res = 0;
    while(start < end){
        if(str[start] == str[end]){
            start++;
            end--;
        }
        else{
            res++;
            start = 0;
            end = n-1-res;
        }
    }
    return res;
}

char* MaxPalindromeUsingKChange(char* str, int k){
    int n = strlen(str);
    char* pal = (char*)malloc( n * sizeof(char));
    strcpy(pal, str);
    int l=0, r = n-1;
    while(l < r){
        if(str[l] != str[r]){
            pal[l] = pal[r] = __max(str[l], str[r]);
            k--;
        }
        l++;
        r--;
    }
/*     if(k < 0)
        return "Not Possible"; */
    l = 0;
    r = n-1;
    while(l < r){
        if(l == r && k > 0)
            pal[l] = '9';
        if(pal[l] < '9'){
            if(k >=2 && pal[l] == str[l] && pal[r] == str[r]){
                k -= 2;
                pal[l] = pal[r] = '9';
            }
            else if(k >= 1 && pal[l] != str[l] || pal[r] != str[r]){
                k--;
                pal[l] = pal[r] = '9';
            }
        }
        l++;
        r--;
    }
    return pal;
}

int CountMinDelCharInStrForPalindrome(char* str){
    int n = strlen(str);
    int L[n];
    int i, j, backup, temp;
    for(i=n-1; i>=0; i--){
        backup = 0;
        for(j=i; j<n; j++){
            if(j==i)
                L[j] = 1;
            else if(str[i] == str[j]){
                temp = L[j];
                L[j] = backup+2;
                backup = temp;
            }
            else{
                backup = L[j];
                L[j] = __max(L[j], L[j-1]);
            }
        }
    }
    return (n - L[n-1]);
}

int CountMinInsertForPalinWithPermut(char* str){
    int n = strlen(str);
    int mask = 0;
    int i, count=0;
    for(i=0; i<n;i++)
        mask ^= (1<<(str[i]-'a'));
    if(mask == 0)
        return 0;
    while(mask){
        count += mask&1;// Adding 1 bit(number of character)
        mask >>= 1;// Divide 2
    }
    return count-1;
}


// Pattern Searching
void PatternSearchingWithNaive(char* str, char* pat){
    //All print index of patter found
    int m = strlen(str);
    int n = strlen(pat);
    int i, j;
    for(i=0; i<=m-n; i++){
        for(j=0; j<n; j++){
            if(str[i+j] != pat[j])
                break;
        }
        if(j == n)
            printf("Pattern found at index %d\n", i);
    }
    /* !! Caution !!
        Naive Algorithm may be not work if many matching char followed by a mismatching char
        Ex)
        if str = "AAAAAAAAAAAAAAAAAB", pattern = "AAAAB" ==> Error
        if str = "ABABABCABABABCABBABABC", pattern = "ABABAC" ==> Error
    */
}
void ComputeLPSArray(char* pat, int m, int* lps){
    //LPS array = Failure Function F
    lps[0] = 0;
    int i = 1, j = 0;
    while(i < m){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0)
                j = lps[j-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
void PatternSearchingWithKMP(char* str, char* pat){
    //If KMP finds mismatching char, KMP knows next char
    // LPS = Longest Prefix which is also Suffix)
    int m = strlen(str);
    int n = strlen(pat);
    int lps[n];
    ComputeLPSArray(pat, n, lps);
    int i=0, j=0;
    while((m-i) >= (n-j)){ // i < m
        if(pat[j] == str[i]){
            i++;
            j++;
        }
        if(j == n){
            printf("Found pattern at index %d\n", i-j);
            j = lps[j-1];
        }
        else if(i < m && pat[j] != str[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}
void ComputeZ(char* str, int* z){
    int n = strlen(str);
    int l, r, k;
    int i;
    l = r = 0;
    for(i=1; i<n; i++){
        if(i > r){
            l = r = i;
            while(r < n && str[r-l] == str[r])
                r++;
            z[i] = r-l;
            r--;
        }
        else{
            k = i-l;
            if(z[k] < r-i+1)
                z[i] = z[k];
            else{
                l=i;
                while(r<n && str[r-l] == str[r])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
}
void PatternSearchingWithZ(char* str, char* pat){
    int plen = strlen(pat);
    int slen = strlen(str);
    int concatlen = slen+plen+1;
    char* concat = (char*)malloc(concatlen);
    int Z[concatlen];
    int i;
    strcpy(concat, pat);
    strcat(concat, "$");
    strcat(concat, str);
    ComputeZ(concat, Z);
    for(i=0; i<concatlen; i++)
        if(Z[i] == plen)
            printf("Pattern found at index %d\n", i-plen-1);
    
    free(concat);
}
bool Search2DGrid(char* grid, char* word, int ridx, int cidx, int R, int C){
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int len = strlen(word), dir, k, rdir, cdir;
    if(*(grid+ridx*C+cidx) != word[0])
        return false;
    for(dir=0; dir<8; dir++){
        rdir = ridx + x[dir], cdir = cidx + y[dir];
        for(k=1; k<len; k++){
            if(rdir >= R || rdir<0 || cdir >= C || cdir<0)
                break;
            if(*(grid+rdir*C+cdir) != word[k])
                break;
            rdir += x[dir], cdir += y[dir];
        }
        if(k==len)
            return true; 
    }
    return false;
}
void PatternSearchWith2DGrid(char* grid, char* word, int r, int c){
    int i, j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            if(Search2DGrid(grid, word, i, j, r, c))
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



int main()
{
    char str1[] = "AGGTAB";//AGGTAB ,geek
    char str2[] = "GXTXAYB";//GXTXAYB , eke
    char str3[] = "axxxy";
    char str4[] = "geeksforgeeks";//forgeeksskeegfor, geeksforgeeks, abcde
    char str5[] = "GEEKS FOR GEEKS";// AAAAAAAAAAAAAAAAAB, AABAACAADAABAAABAA
    char str6[] = "GEEK";// AAAAB, AABA,


    return 0;
}
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