

#include <iostream>
using namespace std;
void fun(int);
void fun(int*);
int main()
{
    int a = 10;
    fun(&a); // error, which fun()?
    return 0;
}
void fun(int x) { cout << "Value of x is : " << x << endl; }
void fun(int* b)
{
    cout << "Value of b is : " << b << endl;
}