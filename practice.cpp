#include <stdio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define endl "\n"
/* void EvenOddCompare(long n);
void SumOfEachEvenOddNum(long n);
void CheckLargestNum(long n1, long n2, long n3);
void Swap(long* a, long* b);
long SumOfDigits(long n, char* str, long mode);
long FindMaxAmongSameDigitsNum(long n);
void NumVowelsNConsonants(char* str);
bool CheckPrimeNum(long n);
bool CheckPerfectNum(long n);
bool CheckStrongNum(long n);
bool CheckArmstrongNum(long n);
long ReverseNum(long n);
bool CheckPalindrome(long n);
long AddBinaryNum(long n1, long n2);
long Fibonacci(long n);
long Bin2Gray(long n);
long Gray2Bin(long n);
void TowerOfHanoi(int num, char from, char temp, char to);
 */

void EvenOddCompare(long n){
     if(n%2==0)// (n&1 == 1) is using bitwise operator 
        printf("%d is even number\n", n);
    else
        printf("%d is odd number\n", n);
}
void SumOfEachEvenOddNum(long n){
    long i;
    long sum_even = 0;
    long sum_odd = 0;

    for(i=1; i<=n; i++)
    {
        if((i & 1) == 0){ // =='s priority is higher than &. So, () is nessasary
            printf("1_%d\n",(i&1));
            sum_even+=i;
        }
        else{
            printf("2_%d\n",(i&1));
            sum_odd+=i;
        }
    }
    printf("Sum of odd numbers from 1 to N: %d\n", sum_odd);
    printf("Sum of even numbers from 1 to N: %d\n", sum_even);
}
void CheckLargestNum(long n1, long n2, long n3)
{
    long temp = (n1>n2) ? (n1>n3 ? n1 : n3) : (n2>n3 ? n2 : n3);
    printf("Largest number among 3 numbers is %d\n", temp);
}
void Swap(long* a, long* b)
{
    printf("Num A: %d, Num B: %d is swaped.\n", *a, *b);
    // Native approach
    long temp;
    temp = *a;
    *a = *b;
    *b = temp;
    // Without temperary variable
    *a = *a + *b;
    *b = *a - *b;// a = (a + b) - b;
    *a = *a - *b;// b = (a + b) - a;
    //Bitwise operator(XOR)
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    printf("After swapped,  A: %d, B: %d \n", *a, *b);
}
long SumOfDigits(long n, char* str, long mode)
{
    // Mode 0 isn't recursive, Mode 1 is recursive
    // Mode 2 is string version
    if(mode == 0){// Not recursive
        long sum1 = 0;
        while(n!=0){
            sum1 += n % 10;
            n /= 10;
        }
        printf("Sum of Digits = %d\n", sum1);
        return sum1;
    }
    if(mode == 1){// Recursive
        if(n == 0)
            return 0;
        else
            return (n % 10) + SumOfDigits((n/10), NULL, 1);
    }
    if(mode == 2)// For string
    {
        long i;
        long sum2 = 0;
        long len = strlen(str);

        for(i=0 ; i<len ; i++){
            if(str[i] >= '0' && str[i] <= '9')
                sum2 += (str[i]-'0');
        }
        printf("Sum2 of Digits = %d\n", sum2);
        return sum2;
    }

    return -1;// Error
}
long FindMaxAmongSameDigitsNum(long n)
{
    long temp[20]={0,};
    long i=0;
    long len = 0;
    long maxValue = 0;
    while(n!=0){
        temp[i++] = (n % 10);
        n /= 10;
    }
    len = i;
    printf("len: %d\n",len);
    
    for(i=0 ; i<len-2 ; i++){
        if(temp[i] > temp[i+1]){
            Swap(&temp[i], &temp[i+1]);
        }
    }
    for(i=len-1 ; i>=0 ; i--)
        maxValue += temp[i] * pow(10,i);
    
    return maxValue;
    return 0;
}
void NumVowelsNConsonants(char* str)
{
    long i = 0;
    long num_vowel = 0;
    long num_consonant = 0;
    long num_special = 0;
    
    for(i=0 ; str[i] != '\0' ; i++){
        switch(str[i]){
            case 'a':
            case 'o':
            case 'e':
            case 'u':
            case 'i':
                num_vowel++;
                break;
            case ' ':
            case '\t':
                num_special++;
                break;
            default:
                num_consonant++;
                break;
        }
    }
    printf("Number of vowels in sentence = %d\n", num_vowel);
    printf("Number of consonants in sentence = %d\n", num_consonant);
    printf("Number of special in sentence = %d\n", num_special);
}
bool CheckPrimeNum(long n)
{
    long i;
    if(n <= 1)
        return false;
    if(n%2 == 0)
        return n == 2 ? true : false;
    for(i=3 ; i<=sqrt(n) ; i++)
        if(n%i==0)
            return false;
    return true;
}
// PerfectNumber = 6 = 1 + 2 + 3 (integer factorization except itself)
bool CheckPerfectNum(long n)
{
    long i;
    long sum = 0;
    for(i=1; i<n ;i++){
        if(n%i == 0)
            sum += i;
    }
    if(sum == n)
        return true;
    else
        return false;
}
// StrongNumber = 145 = 1! + 4! + 5!
bool CheckStrongNum(long n)
{
    long i;
    long temp;
    long multiple;
    long sum = 0;
    long org = n;
    while(n!=0){
        temp = n%10;
        multiple = 1;
        for(i=1; i<=temp; i++)
            multiple *= i;
        sum += multiple;
        n /= 10;
    }
    if(sum == org)
        return true;
    else
        return false;
}
// ArmstrongNum = 407 = 4*4*4 + 0*0*0 + 7*7*7 (n-digits)
// x1x2x3x4 = pow(x1,4)+pow(x2,4)+pow(x3,4)+pow(x4,4) 
bool CheckArmstrongNum(long n)
{
    long i;
    long sum = 0;
    long count_digits = 0;
    long temp = n;
    while(temp!=0){
        temp /= 10;
        count_digits++;
    }
    temp = n;
    while(temp!=0){
        sum += pow(temp % 10, count_digits);
        temp /= 10;
    }
    if(sum == n)
        return true;
    else
        return false;
}
long ReverseNum(long n)
{
    long reversed = 0;
    while(n!=0){
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}
bool CheckPalindrome(long n)
{
    long revNum = ReverseNum(n);
    if(n == revNum)
        return true;
    else
        return false;
}
long AddBinaryNum(long n1, long n2)
{
    long temp = n1 + n2;
    long lsb_bit = 0;
    long i = 0, j = 0;
    long carry = 0;
    long result = 0;
    long buf[64] = {0,};

    while(temp != 0){
        lsb_bit =  (temp % 10) % 4 + carry;// LSB % 4 is for adding carry (LSB: temp % 10)
        (lsb_bit % 4 == 2 || lsb_bit % 4 == 3) ? carry = 1 : carry = 0;// If carry adds next digit, max value 3
        buf[i++] = lsb_bit % 2;// Store the calculated value in buffer.
        temp /= 10;
    }
    buf[i] = carry;// Adding carry in MSB

    while(i>=0){
        result += buf[i]*pow(10,i);
        i--;
    }
    return result;
}
long Fibonacci(long n)
{
    long fib1 = 0, fib2 = 1;
    long i = 3;
    if(n==1){
        printf("fibN: %ld\n", fib1);
        return fib1;
    }
    if(n==2){
        printf("fibN: %ld\n", fib2);
        return fib2;
    }
    if(n>=3){
        while(i <= n){
            fib1 = fib1 + fib2;
            Swap(&fib1, &fib2);
            i++;
        }
        printf("fibN: %ld\n", fib2);
        return fib2;
    }
    return 0;
}
long Bin2Gray(long n)
{
    // input is bit type like 1111001010(binary num), not 970(decimal num)
    // So, this source code differ other optimized source code.
    long a, b, result=0, i=0;
    while(n != 0){
        a = n % 10;
        n /= 10;
        b = n % 10;
        if(a^b)
            result += pow(10,i);
        i++;
    }
    return result;
}
long Gray2Bin(long n)
{
    // input is bit type like 1000(gray num), not 8(decimal num)
    // So, this source code differ other optimized source code.
    long a, b, result=1, i=0;
    long temp;
    temp = n;
    while(n!=0){//Calculate number(length) of bits
        n /= 10;
        i++;
    }
    temp = ReverseNum(temp);// Reversed number is used for easy calcuation
    while((i-1)>0){
        a = temp % 10;
        temp /= 10;
        b = temp % 10;
        //MSB is shifted by "result*10" into left side
        // "b^(result%10)" is binary number(1bit)
        result = result*10 + (b^(result % 10));
        i--;
    }
    return result;
}
long GetGCD(long n1, long n2)//Greatest Common Divisor 
{
    //This function use the Euclidean Algorithm)
    //n1 = numerator, n2 = denominator
    long high, low, remainder = 0;
    high = (n1 > n2) ? n1 : n2;
    low = (n1 < n2 ) ? n2 : n1;
    remainder = high % low;
    while(high % low != 0){
        remainder = high % low;
        high = low;
        low = remainder;
    }
    return remainder;
    // Recursive method
    /*
        while(n1 != n2){
            return n1 > n2 ? GetGCD(n1-n2, n2) : GetGCD(n1, n2-n1);
        }
        return n1;
    */
   // Recursivre and Euclidean method
   /*
        if(low==0)
            return 0;
        else
            return GetGCD(low, (high % low) );
   */
}
long GetLCM(long n1, long n2)//Least Common Multiple
{
    long high = (n1 > n2) ? n1 : n2;
    while(1){
        if(high % n1==0 && high % n2 ==0)
            return high;
        high++;
    }
    //return n1*n2/GetGCD(n1,n2); // LCM formula
}
void DeletefArrElement(int* arr, int element, bool option)
{
    int i;
    int size = sizeof(arr)/sizeof(int);
    // Delete by index(option = false)
    if(option == false){
        for(i=element; i<size-1; i++)
            arr[i] = arr[i+1];
    }
    // Delete by value(option = true)
    if(option == true){
        for(i=0; i<size; i++){
            if(arr[i] == element){
                for(; i<size-1; i++){
                    arr[i] = arr[i+1];
                    break;
                }
            }
        }
    }
}
void FindMissingNum(int* arr, int size)
{
    int i = 0;
    int a = 0, b = 0;
    // a0 xor a1 xor ... xor an-1 = a
    // a0 xor a1 xor ... xor an = b
    // a xor b = an
    for(; i<size-1 ; i++)
        a ^= i;
    for(i=0; i<size; i++)
        b ^= i;
    printf("Missing Number is %d\n", a^b);
}

void TowerOfHanoi(int num, char from, char temp, char to){
    if(!num)
        return;
    TowerOfHanoi(num-1, from, to, temp);
    printf("Move %d from %c to %c\n",num, from, to);
    TowerOfHanoi(num-1, temp, from, to);
}

int String2Int(string str){
    if(str.length()==1)
        return (str[0]-'0');
    double y = String2Int(str.substr(1));
    double x = str[0]-'0';
    x = x*pow(10, str.length()-1)+y;
    return int(x);
}

int FindFirstRepeatingElementWithNaive(vector<int> arr){
    int size = arr.size();
    for(int i=0; i<size; i++)
        for(int j=i+1; j<size; j++)
            if(arr[i] == arr[j])
                return i;
    return -1;
}
int FindFirstRepeatingElementWithHashSet(vector<int> arr){
    int min = -1;
    int size = arr.size();
    set<int> hashset;
    for(int i=size-1; i>=0; i--){
        if(hashset.find(arr[i]) != hashset.end())//find(x)는  x가 존재하면 return set.end()
            min = i;
        else
            hashset.insert(arr[i]);
    }
    if(min != -1)
        return min;
    return -1;
}
int FindFirstRepeatingElementWithHashing(vector<int> arr){
    bool isRepeat = false;
    int size = arr.size();
    int max = size;
    for(int i=0; i<size; i++)
        if(max < arr[i])
            max = arr[i];
    int a[max+1] = {};
    bool b[max+1] = {};
    for(int i=0; i<size; ++i){
        if(a[arr[i]]){
            b[arr[i]] = true;
            isRepeat = true;
            continue;
        }
        else
            //if i=0 and arr[0] = 0, we have to avoid a[0] = 0
            a[arr[i]] = i+1;
    }
    if(!isRepeat)
        return -1;
    else{
        int min = max+1;
        for(int i =0; i<max+1; i++)
            if(!!(a[i]) && min > a[i] && b[i])
                min = a[i];
        return min-1;
    }
}
int FindFirstRepeatingElementWithSingleHashArray(vector<int> arr){
    int max = -1;
    int size = arr.size();
    for(const auto &x : arr)
        if(max < x)
            max = x;
    int hash[max+1] = {};
    for(auto &x : arr)
        hash[x]++;
    for(int i=0; i<size; i++)
        if(hash[arr[i]] > 1)
            return i;
    return -1;
}

void FindLargest3Element(vector<int> arr){
    int first, second, third;
    int size = arr.size();
    if(size < 3)
        return;
    third = first = second = -INF;
    for(auto &x : arr){
        if(x > first)
            third = second, second = first, first = x;
        else if(x > second && x != first)
            third = second, second = x;
        else if(x>third && x !=second && x != first)
            third = x;
    }
    cout << first << ", " << second << ", " <<third << endl;
}
void FindLargest3ElementWithSort(vector<int> arr){
    int size = arr.size();
    sort(arr.begin(), arr.end());
    int repeatcheck=0, count = 1;
    for(int i=1; i<=size, count<4; i++){
        if(repeatcheck != arr[size-i]){
            cout << arr[size-i] << " ";
            repeatcheck = arr[size-i];
            count++;
        }
    }
}

int FindMissingNum(vector<int> arr){
    int size = arr.size();
    int x = arr[0], y=1;
    for(int i = 1; i<size; i++)
        x ^= arr[i];
    for(int i = 2; i<=size+1; i++)
        y ^= i;
    return x^y;
}
void FindMissingRepearingNum(vector<int>& arr){
    int n = arr.size();
    int xor1 = 0;
    int set_bit;
    int x = 0;
    int y = 0;
 
    xor1 = 0;
    for (int i = 0; i < n; i++){
        xor1 ^= arr[i];
        xor1 ^= (i+1);
    }
    set_bit = xor1 & ~(xor1 - 1);//Rightmost set bit
    // Divide 2 sets(one include set_bit, other doesn't include set_bit)
    for (int i = 0; i < n; i++) {
        if ((arr[i] & set_bit) != 0)
            x = x^ arr[i];
        else
            y = y ^ arr[i];
        if (((i+1) & set_bit) != 0)
            x ^= (i+1);
        else
            y ^= (i+1);
    }
    // we can't know whether x is a repeating number or not
    for(int i=0; i<n; i++){
        if(arr[i] == x)
            break;
        if(arr[i] == y)
            swap(x, y);
    }
    cout << x << " , " << y << endl;
    // x is repeating number
    // y is missing number
}

//Knight's tour algorithm
const int SIZE = 6;
bool IsSafeMovement(int x, int y, int arr[SIZE][SIZE]){
    return (x>=0 && x<SIZE && y>=0 && y<SIZE && arr[x][y] == -1);
}
void PrintKnightTourArr(int arr[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++)
            cout << setw(2) <<arr[i][j] << " ";
        cout << endl;
    }
}
bool KnightTourLoop(int x, int y, int move, int arr[SIZE][SIZE], int dx[8], int dy[8]){
    if(move == SIZE * SIZE)
        return true;
    for(int i = 0; i < 8; i++){
        int x_next = x + dx[i];
        int y_next = y + dy[i];
        if(IsSafeMovement(x_next, y_next, arr)){
            arr[x_next][y_next] = move;
            if(KnightTourLoop(x_next, y_next, move+1, arr, dx, dy))
                return true;
            else
                arr[x_next][y_next] = -1;
        }
    }
    return false;
}
void KnightTour(){
    int arr[SIZE][SIZE];
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            arr[i][j] = -1;
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2 , -1};
    int x = 0;
    int y = 0;
    arr[x][y] = 0;
    if(KnightTourLoop(x, y, 1, arr, dx, dy))
        PrintKnightTourArr(arr);
    else
        KnightTour();
}

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};
bool IsValidPath(int r, int c, vector<vector<int>>& maze){
    int size = maze.size();
    return r >= 0 && c >= 0 && r<size && c<size && maze[r][c];
}
bool FindMazePath(int r, int c, vector<vector<int>>& maze, vector<vector<int>>& path, vector<pair<int,int>>& sol){
    int size = maze.size();
    if(r == size-1 && c == size-1){
        path[r][c] = 1;
        return true;
    }
    maze[r][c] = 0, path[r][c] = 1;
    for(int i =0; i<4; i++){
        int r_next = r + dr[i];
        int c_next = c + dc[i];
        if(IsValidPath(r_next, c_next, maze)){
            sol.push_back({r_next, c_next});
            if(FindMazePath(r_next, c_next, maze, path, sol))
                return true;
            sol.pop_back(), path[r][c] = 0;
        }
    }
    return false;
}


/*
    To check output of PrintNQueen()
    cout << " i: "<< i << " solution i: "<< solution[i] << " J: "<< j;
    cout << " " << (j == solution[i] ? "Q" : ".") << endl;
*/

vector<vector<int>> NQresult;
void PrintNQueen(const vector<vector<int>>& result) {
    for (const auto &solution : result) {
        int size = solution.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << " " << (j == solution[i] ? "Q" : ".");
            cout << endl;
        }
        cout << endl;
    }
}
bool NQueenLoop(vector<vector<int>>& arr, vector<int>& ld, vector<int>& rd, vector<int>& col, int c){
    int size = arr.size();
    if(c == size){
        vector<int> v;
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                if(arr[i][j] == 1)
                    v.push_back(j);
        NQresult.push_back(v);
        return true;
    }
    bool res = false;
    for(int i=0; i<size; i++){
        //if(ld[i-c+size-1] != 1 && rd[i+c] != 1 && col[i] != 1){
        if(ld[i+c] != 1 && rd[i-c+size-1] != 1 && col[i] != 1){
            arr[i][c] = 1;
            ld[i+c] = rd[i-c+size-1] = col[i] = 1;
            res = NQueenLoop(arr, ld, rd, col, c+1) || res;
            arr[i][c] = 0;
            ld[i+c] = rd[i-c+size-1] = col[i] = 0;
        }
    }
    return res;
}
bool NQueen(int n){
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int max_range = 2*n-1;
    vector<int> ld(max_range, 0);
    vector<int> rd(max_range, 0);
    vector<int> col(max_range, 0);
    if(NQueenLoop(arr, ld, rd, col, 0) == false)
        return false;
    else{
        PrintNQueen(NQresult);
        return true;
    }
}

void SumofSubSet(vector<int>& arr, int sum, vector<int>& sub, int i, set<vector<int>>& subset){
    int size = arr.size();
    if(sum == 0){
        if(!sub.empty())
            subset.insert(sub);
        return;
    }
    if(i == size)
        return;
    SumofSubSet(arr, sum, sub, i+1, subset);//Exclude i th element
    if(arr[i] <= sum){//Include i th element
        sub.push_back(arr[i]);
        SumofSubSet(arr, sum-arr[i], sub, i+1, subset);
        sub.pop_back();
    }
}

void PrintUDGraphColoring(vector<vector<int>>& result){
    for(auto& x : result){
        for(auto& y : x)
            cout << y << " ";
        cout << endl;
    }
}
bool CanColoring(int vertex, vector<vector<bool>>& graph, vector<int>& color, int cur_color){
    int size = graph.size();
    for(int i=0; i<size; i++)
        if(graph[vertex][i] && (cur_color == color[i]))
            return false;
    return true;
}
bool UDGraphColoring(vector<vector<bool>>& graph, int m, vector<int>& color, int vertex, vector<vector<int>>& result){
    int size = graph.size();
    if(vertex == size){
        result.push_back(color);
        return true;
    }
    bool res = false;
    for(int i=0; i<m; i++){
        if(CanColoring(vertex, graph, color, i)){
            color[vertex] = i;
            res = UDGraphColoring(graph, m, color, vertex+1, result) || res;
            color[vertex] = -1;
        }
    }
    return res;
}

// Hamiltonian Cycle (it starts at any index)
void PrintHamiltonCycle(vector<int>& path, int size, int start_pos){
    int temp = size;
    for(int i = start_pos; temp >= 0 ; i=(i+1)%size, temp--)
        cout << path[i] << " ";
    cout << endl;
}
bool CheckPath(vector<vector<bool>>& graph, vector<int>& path, int cur_pos, int next_pos, int count){
    int size = graph.size();
    int start_pos = (size+cur_pos-count)%size;
    int before_pos = (size+cur_pos-1)%size;
    if(path[before_pos] != -1)//Check if new vertex can be connected to the last traversed vertex
        if(graph[path[before_pos]][next_pos] == 0)
            return false;
    int temp = count;
    for(int i=start_pos; temp > 0; i=(i+1)%size, temp--)//Check if vertex has been passed
        if(path[i] == next_pos)
            return false;
    return true;
}
bool HamiltonianCycle(vector<vector<bool>>& graph, vector<int>& path, int cur_pos, int count){
    int size = graph.size();
    int start_pos = (size+cur_pos-count)%size;
    if(count == size){
        int end_pos = (size+start_pos-1)%size;
        if(graph[path[end_pos]][path[start_pos]] == 1)
            return true;
        else
            return false;
    }
    int temp = size;
    for(int next_pos=start_pos; temp > 0 ; next_pos=(next_pos+1)%size, temp--){
        if(CheckPath(graph, path, cur_pos, next_pos, count)){
            path[cur_pos] = next_pos;
            if(HamiltonianCycle(graph, path, (cur_pos+1)%size, count+1))
                return true;
            path[cur_pos] = -1;
        }
    }
    return false;
}
// Same Function( Hapmiltonian Cycle). (it starts at index 0)
/* void PrintHamiltonCycle(vector<int>& path){
    for(auto i : path)
        cout << path[i] << " ";
    cout << endl;
}
bool CheckPath(vector<vector<bool>>& graph, vector<int>& path, int cur_pos, int next_pos){
    if(cur_pos-1 >= 0)
        if(path[cur_pos-1] != -1)//Check if new vertex can be connected to the last traversed vertex
            if(graph[path[cur_pos-1]][next_pos] == 0)
                return false;
    for(int i=0; i<cur_pos; i++)//Check if vertex has been passed
        if(path[i] == next_pos)
            return false;
    return true;
}
bool HamiltonianCycle(vector<vector<bool>>& graph, vector<int>& path, int cur_pos){
    int size = graph.size();
    if(cur_pos == size){
        if(graph[path[cur_pos-1]][path[0]] == 1){
            path[size] = 0;
            return true;
        }
        else
            return false;
    }
    for(int next_pos=0; next_pos<size; next_pos++){
        if(CheckPath(graph, path, cur_pos, next_pos)){
            path[cur_pos] = next_pos;
            if(HamiltonianCycle(graph, path, cur_pos+1))
                return true;
            path[cur_pos] = -1;
        }
    }
    return false;
} */



int main(void){

    return 0;
}


    /* vector<int> arr = {2, 3, 5, 5, 8, 12, 15, 17, 19};
    vector<int> arr2 = {1, 3, 4, 5, 1, 6, 2 };//1, 3, 4, 5, 1, 6, 2 
     1, 2, 3, 5, 3, 6
    int key = 5;
    int res = FindMissingNum(arr2);
    FindLargest3ElementWithSort(arr);
    (res==-1)? cout<< "No Key in Array"<< endl : cout << "Key is located at index " << res;

 */

// Rat in Maze
/*     vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> path(4, vector<int>(4, 0));
    vector<pair<int,int>> sol;
    int size = maze.size();
    // Print Coordinate of Solution Path
    sol.push_back({0,0});
    if(FindMazePath(0, 0, maze, path, sol)){
        for(auto& i : sol)
            cout << "(" << i.first << ", " << i.second << ")";
        cout << endl;
    }
    else
        cout << "Can't find solution\n";
    // Print Path to text image
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            cout << path[i][j] << " ";
        cout << endl;
    } */

// Sum of Subset
/*     vector<int> arr = {2, 3, 5, 5, 8, 12, 15, 17, 19};
    int sum = 18;
    vector<int> sub;
    set<vector<int>> subset;
    SumofSubSet(arr, sum, sub, 0, subset);
    cout<< endl;
    for(auto k: subset){
        for(auto t : k)
            cout << t << " ";
        cout << endl;
    } */

// UDGraph M Coloring
/*     vector<vector<bool>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    vector<vector<int>> result;
    int size = graph.size();
    int m = 3;
    vector<int> color(size, -1);
    
    if(UDGraphColoring(graph, m, color, 0, result))
        PrintUDGraphColoring(result);
    else
        cout << "No result" << endl;
 */

// Hamiltonian Cycle
/*     vector<vector<bool>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int size = graph.size();
    int start_pos = 4;
    vector<int> path(size+1, -1);
    if(HamiltonianCycle(graph, path, start_pos, 0))
        PrintHamiltonCycle(path, size, start_pos);
    else
        cout << "No result" << endl;
    cout << endl;
    vector<vector<bool>> graph2 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    int size2 = graph2.size();
    int start_pos2 = 0;
    vector<int> path2(size2+1, -1);
    if(HamiltonianCycle(graph2, path2, start_pos2, 0))
        PrintHamiltonCycle(path2, size2, start_pos2);
    else
        cout << "No result" << endl; */




/* long input;
    long input1, input2, input3;
    char i_str[100];
    long result1=0, result2=0;
    bool state1, state2, state3;
    long linput1, linput2;
    long lresult1;
    printf("Enter 1 number: ");
    scanf("%ld",&linput1);
    printf("Enter 2 number: ");
    scanf("%ld %ld",&linput1, &linput2);
    printf("Enter string: ");
    scanf("%[^\n]s",i_str);
    
    EvenOddCompare(input); // 1
    SumOfEachEvenOddNum(input); // 2
    scanf("%d %d %d",&input1, &input2, &input3); // 3
    CheckLargestNum(input1,input2,input3); // 3
    scanf("%d %d", &input1, &input2);
    Swap(&input1, &input2);
    result1 = SumOfDigits(input,NULL, 0);
    result2 = SumOfDigits(0, i_str, 2);
    printf("result: %d, result: %d\n", result1, result2);
    result1 = FindMaxAmongSameDigitsNum(input);
    p rintf("result: %d\n",result1);
    NumVowelsNConsonants(i_str);
    state1 = CheckPrimeNum(input);
    state2 = CheckPerfectNum(input);
    state3 = CheckStrongNum(input);
    printf("prime %d perfect %d stroing %d\n", state1, state2, state3);
    state1 = CheckArmstrongNum(input);
    printf("armstrongnum %d \n", state1);
    result1 = ReverseNum(input);
    state1 = CheckPalindrome(input);
    printf("reversed num %d is palindrome %d \n", result1, state1);
    lresult1 = AddBinaryNum(linput1, linput2);
    printf("Binarynum: %ld\n", lresult1);
    lresult1 = Fibonacci(linput1);
    lresult1 = Bin2Gray(linput1);
    lresult1 = Gray2Bin(linput1);
    printf("bin : %ld\n", lresult1);
    TowerOfHanoi(3,'A','B','C'); */


