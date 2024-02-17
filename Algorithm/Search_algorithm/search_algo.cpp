#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int LinearSearch(vector<int> arr, int key){
    for(int i=0; i<arr.size(); i++)
        if(arr[i] == key)
            return i;
    return -1;
}
int SentinelLinearSearch(vector<int> arr, int key){
    int size = arr.size();
    int last = arr[size-1];
    if(last == key)
        return size-1;
    arr[size-1] = key;
    int i = 0;
    while(arr[i] != key)
        i++;
    return (i<size-1) ? i : -1;
}
int IterativeBinarySearch(vector<int> arr, int l, int r, int key){
    while(l <= r){
        int m = (l+r) >> 1;
        if(arr[m] == key)
            return m;
        if(arr[m] < key)
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}
int ImprovedBinarySearch(vector<int> arr, int l, int r, int key){
    while(r-l > 1){
        int m = (r+l) >> 1;
        if(arr[m] <= key)
            l = m;
        else
            r = m;
    }
    // return arr[l]; ==> lower bound's value
    // return arr[r]; ==> Find the key value!
    // return l ==> key's last index(If it permit duplicate elements)
    // return r ==> upper bound(If it permit duplicate elements)
    // if(arr[m] >= key) r= m; else l = m; ==> key's first index(If it permit duplicate elements)
    if(arr[l] == key)
        return l;
    if(arr[r] == key)
        return r;
    else
        return -1;
}
int RecursiveBinarySearch(vector<int> arr, int l, int r, int key){
    if(l <= r){
        int m = (l+r) >> 1;
        if(arr[m] == key)
            return m;
        if(arr[m] < key)
            return RecursiveBinarySearch(arr, m+1, r, key);
        else
            return RecursiveBinarySearch(arr, l, m-1, key);
    }
    return -1;
}
int MetaBinarySearch(vector<int> arr, int key){
    int size = arr.size();
    int nBit = log2(size-1) + 1;
    int pos = 0;
    for(int i = nBit; i>=0; i--){
        if(arr[pos] == key)
            return pos;
        int new_pos = pos | (1 << i);// 1<<i = 2^i, Set bits to 1 sequentially starting from MSB 
        if((new_pos < size) && (key >= arr[new_pos]))
            pos = new_pos;//Set i-th bit based on MSB to 1 when key is bigger than arr[new_pos]
    }
    return (arr[pos] == key) ? pos : -1;
}
int IterativeTernarySearch(vector<int> arr, int l, int r, int key){
    while(l <= r){
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        if(arr[mid1] == key)
            return mid1;
        if(arr[mid2] == key)
            return mid2;
        if(key < arr[mid1])
            r = mid1-1;
        else if(key > arr[mid2])
            l = mid2+1;
        else{
            l = mid1+1;
            r = mid2-1;
        }
    }
    return -1;
}
int RecursiveTernarySearch(vector<int> arr, int l, int r, int key){
    if(l <= r){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1] == key)
            return mid1;
        if(arr[mid2] == key)
            return mid2;
        if(key < arr[mid1])
            return RecursiveTernarySearch(arr, l, mid1-1, key);
        else if(key > arr[mid2])
            return RecursiveTernarySearch(arr, mid2+1, r, key);
        else
            return RecursiveTernarySearch(arr, mid1+1, mid2-1, key);
    }
    return -1;
}
int JumpSearch(vector<int> arr, int key){
    int size = arr.size();
    int step = sqrt(size);
    int interval = step;
    int prev = 0;
    while(arr[min(step, size)-1] < key){//Move index by using step
        prev = step;
        step += interval;
        if(prev >= size)
            return -1;
    }
    while(arr[prev] < key){//Linear Search
        prev++;
        if(prev == min(step, size))
            return -1;
    }
    if(arr[prev] == key)
        return prev;
    return -1;
}
int RecursiveInterpolationSearch(vector<int> arr, int low, int high, int key){
    int pos;
    if(low <= high && key >= arr[low] && key <= arr[high]){
        pos = low + ((double)(key-arr[low])*(high-low)/(arr[high]-arr[low]));
        if(arr[pos] == key)
            return pos;
        if(key > arr[pos])
            return RecursiveInterpolationSearch(arr, pos+1, high, key);
        if(key < arr[pos])
            return RecursiveInterpolationSearch(arr, low, pos-1, key);
    }
    return -1;
}
int IterativeInterpolationSearch(vector<int> arr, int low, int high, int key){
    while(low <= high && key >= arr[low] && key <= arr[high]){
        if(low == high){
            if(arr[low] == key)
                return low;
            return -1;
        }
        int pos = low + ((double)(key-arr[low])*(high-low)/(arr[high]-arr[low]));
        if(arr[pos] == key)
            return pos;
        if(key > arr[pos])
            low = pos+1;
        else
            high = pos-1;
    }
    return -1;
}
int RecursiveExponentialSearch(vector<int> arr, int key){
    int size = arr.size();
    if(arr[0] == key)
        return 0;
    int i = 1;
    while(i<size && arr[i] <= key)
        i <<= 1;
    return RecursiveBinarySearch(arr, i/2, min(i, size-1), key);
}
int IterativeExponentialSearch(vector<int> arr, int key){
    int size = arr.size();
    int i = 1;
    if(size == 0)
        return -1;
    while(i<size && arr[i] < key)
        i <<= 1;
    int l = i/2;
    int r = min(i, size-1);
    while(l <= r){
        int mid = (l+r) >> 1;
        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int FibonacchiSearch(vector<int> arr, int key){
    int size = arr.size();
    int fib2 = 0;
    int fib1 = 1;
    int fib3 = fib1 + fib2;
    while(fib3 < size){
        fib2 = fib1;
        fib1 = fib3;
        fib3 = fib1 + fib2;
    }
    int offset = -1;
    while(fib3 > 1){
        int i = min(offset+fib2, size-1);
        if(key > arr[i]){
            fib3 = fib1;
            fib1 = fib2;
            fib2 = fib3 - fib1;
            offset = i;
        }
        else if(key < arr[i]){
            fib3 = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib3 - fib1;
        }
        else
            return i;
    }
    if(fib1 && arr[offset+1] == key)
        return offset+1;
    return -1;
}


int main(){
    vector<int> arr = {2, 3, 4, 10, 40, 50, 70, 80, 100, 200, 220, 250, 300};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 250;

    int res = FibonacchiSearch(arr, key);
    (res==-1)? cout<< "No Key in Array"<< endl : cout << "Key is located at index " << res;
    return 0;
}
//--------------------- main -----------------------

//Linear Search
/* int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = LinearSearch(arr,size,key);
    (res==-1)? cout<< "No Key in Array"<< endl : cout << "Key is located at index " << res; */

// Sentinel Linear Search
/* vector<int> arr = {2, 3, 4, 10, 40};
    int key = 40;

    int res = SentinelLinearSearch(arr, key);
    (res==-1)? cout<< "No Key in Array"<< endl : cout << "Key is located at index " << res; */

//MetaBinarySearch, Ternary Search, Interpolation Search
/* vector<int> arr = {2, 3, 4, 10, 40, 50, 70, 80, 100, 200, 220, 250, 300};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 200;

    int res = MetaBinarySearch(arr, key);
    (res==-1)? cout<< "No Key in Array"<< endl : cout << "Key is located at index " << res;
    return 0; */






































