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


#include <iostream> 
  
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
}