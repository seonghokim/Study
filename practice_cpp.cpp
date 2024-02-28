/* #include <iostream>
#include <sstream>
using namespace std;
 
class Point {
private:
    int x, y;
 
public:
    Point(int i = 0, int j = 0)
    {
        x = i;
        y = j;
    }
    void print()
    {
        cout << "x = " << x << ", y = " << y << '\n';
    }
    Point& operator=(const string& values) {
        stringstream ss(values);
        ss >> x;
        if (ss.peek() == ',') {
            ss.ignore(); // 쉼표는 무시
            ss >> y;
        } else {
            y = x; // 쉼표가 없으면 y에도 x의 값 복사
        }
        return *this;
    }
};
 
int main()
{
    Point t(20, 20);
    t.print();
    t = "30, 5"; // Member x of t becomes 30
    t.print();
    return 0;
} */
/* #include <iostream>
using namespace std;
 
class overload {
private:
    int count;
 
public:
    overload(int i)
        : count(i)
    {
    }
 
    overload operator++(int) { return (count++); }
    overload operator++()
    {
        count = count + 1;
        return count;
    }
    void Display() { cout << "Count: " << count << endl; }
};
// Driver code
int main()
{
    overload i(5);
    overload post(5);
    overload pre(5);
 
    // this calls "function overload operator ++()" function
    pre = ++i;
    cout << "results of I   =   ";
    i.Display();
    cout << "results of preincrement   =  ";
    pre.Display();
    // this call "function overload operator ++()"function
    i++; // just to show diff
    i++; // just to show diff
    post = i++;
    cout << "Results of post increment   =   ";
    post.Display();
    cout << "And results of i , here we see difference   : "
            "  ";
    i.Display();
    return 0;
} */


/* #include <iostream> 
  
using namespace std; 
  
template <class T> class Test 
{   
private: 
  T val;  
public: 
  static int count; 
  Test() 
  { 
    count++; 
  } 
  // some other stuff in class 
}; 
  
template<class T> 
int Test<T>::count = 0; 
  
int main() 
{ 
  Test<int> a, b;
  //Test<int> b;  // value of count for Test<int> is 1 now 
  Test<double> c;  // value of count for Test<double> is 1 now 
  cout << Test<int>::count   << endl;  // prints 2   
  cout << Test<double>::count << endl; //prints 1 
     
  //getchar(); 
  return 0; 
} */
/* #include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    // Initializing vector with array values
    int arr[] = { 5, 10, 15, 20, 20, 20, 23, 42, 42, 42, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
 
    cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";
 
    vect.erase(find(vect.begin(),vect.end(),10));
    cout << "\nVector after erasing element:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
 
    vect.erase(unique(vect.begin(), vect.end()),
               vect.end());
    cout << "\nVector after removing duplicates:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
 
    return 0;
} */
/* #include <forward_list>
#include <iostream>
using namespace std;

int main()
{
    forward_list<int> flist1 = {10, 20, 30};
    forward_list<int> flist2 = {40, 50, 60};

    // Reverse the elements of flist1
    flist1.reverse();

    // Shifting elements from first to second
    // forward list after 1st position
    flist2.splice_after(flist2.before_begin(), flist1);

    // Displaying the forward list
    cout << "The forward list after splice_after operation: ";
    for (int& c : flist2)
        cout << c << " ";
    cout << endl;

    return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
int GetRightPosition(int A[], int l, int r, int key)
{
    int m;
    cout << endl;
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
        cout<< "Get right position!" <<" m: " << m<< " Arr[m]: "<< A[m] <<  " left: "<<l << " right: " << r << endl;
    }
 
    return l;
}
 
// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetLeftPosition(int A[], int l, int r, int key)
{
    int m;
    cout << endl;
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] >= key )
            r = m;
        else
            l = m;
        cout<< "Get left position!" <<" m: " << m << " Arr[m]: "<< A[m] << " left: "<<l << " right: " << r << endl;
    }
 
    return r;
}
 
int CountOccurrences(int A[], int size, int key)
{
    // Observe boundary conditions
    int left = GetLeftPosition(A, 0, size-1, key);
    int right = GetRightPosition(A, 0, size-1, key);
    cout<<"left: "<<left << endl;
    cout<<"right: "<< right << endl;
    // What if the element doesn't exists in the array?
    // The checks helps to trace that element exists
    return (A[left] == key && key == A[right])?
           (right - left + 1) : 0;
}
 
int main()
{
    int A[] = {1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int key = 3;
 
    std::cout << "Number of occurances of " << key << ": " << CountOccurrences(A, size, key) << std::endl;
 
    return 0;
} */
#include <iostream>
using namespace std;
 
int main() {
   
    // Matrix for storing Process Id, Burst
    // Time, Average Waiting Time & Average
    // Turn Around Time.
    int A[100][4];
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
 
    cout << "Enter number of process: ";
    cin >> n;
 
    cout << "Enter Burst Time:" << endl;
   
    // User Input Burst Time and alloting Process Id.
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> A[i][1];
        A[i][0] = i + 1;
    }
 
    // Sorting process according to their Burst Time.
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                index = j;
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
 
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
 
    A[0][2] = 0;
    // Calculation of Waiting Times
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
 
    avg_wt = (float)total / n;
    total = 0;
    cout << "P     BT     WT     TAT" << endl;
   
    // Calculation of Turn Around Time and printing the
    // data.
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        cout << "P" << A[i][0] << "     " << A[i][1] << "     " << A[i][2] << "      " << A[i][3] << endl;
    }
 
    avg_tat = (float)total / n;
    cout << "Average Waiting Time= " << avg_wt << endl;
    cout << "Average Turnaround Time= " << avg_tat << endl;
}