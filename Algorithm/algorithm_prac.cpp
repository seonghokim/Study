#include <stdio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define endl "\n"
#define ALPHABET 26
#define CHAR_SIZE 256
#define EPS 1e-6

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

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// ------------------------------ BackTracking ----------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Knight's tour algorithm
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

// Rat In Maze
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};
bool IsValidPath(int r, int c, vector<vector<int>>& maze, vector<vector<int>>& path){
    int size = maze.size();
    return r >= 0 && c >= 0 && r<size && c<size && maze[r][c] && path[r][c]!=1;
}
bool FindMazePath(int r, int c, vector<vector<int>>& maze, vector<vector<int>>& path, vector<vector<vector<int>>>& all){
    int size = maze.size();
    if(r == size-1 && c == size-1){
        all.push_back(path);
        return true;
    }
    bool res = false;
    path[r][c] = 1;
    for(int i =0; i<4; i++){
        int r_next = r + dr[i];
        int c_next = c + dc[i];
        if(IsValidPath(r_next, c_next, maze, path)){
            path[r_next][c_next] = 1;
            res = FindMazePath(r_next, c_next, maze, path, all) || res;
            path[r_next][c_next] = 0;
        }
    }
    return res;
}

// N-Queen
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

// Sum of Subset
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

// M-Coloring
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

// Sudoku
void PrintSudoku(vector<vector<int>>& grid){
    int size = grid.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
bool FindUnassignedLoc(vector<vector<int>>& grid, int& row, int& col){
    int size = grid.size();
    for(row=0; row<size; row++)
        for(col=0; col<size; col++)
            if(!grid[row][col])
                return true;
    return false;
}
bool UsedInRow(vector<vector<int>>& grid, int row, int num){
    int size = grid.size();
    for(int col=0; col<size; col++)
        if(grid[row][col] == num)
            return true;
    return false;
}
bool UsedInCol(vector<vector<int>>& grid, int col, int num){
    int size = grid.size();
    for(int row=0; row<size; row++)
        if(grid[row][col] == num)
            return true;
    return false;
}
bool UsedInBox(vector<vector<int>>& grid, int row, int col, int num){
    for(int r=0; r<3; r++)
        for(int c=0; c<3; c++)
            if(grid[r+row][c+col] == num)
                return true;
    return false;
}
bool CanWriteNum(vector<vector<int>>& grid, int row, int col, int num){
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row-row%3, col-col%3, num) && grid[row][col] == 0;
}
bool Sudoku(vector<vector<int>>& grid){
    int size = grid.size();
    int row, col;
    if(!FindUnassignedLoc(grid, row, col))
        return true;
    for(int num=1; num<=9; num++){
        if(CanWriteNum(grid, row, col, num)){
            grid[row][col] = num;
            if(Sudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int GetIndexofBox(int r, int c){
    return r/3*3+c/3;
}
bool CanWriteNumWithBitMask(vector<int>& row, vector<int>& col, vector<int>& box, int r, int c, int num){
    return !((row[r] >> num) & 1) && !((col[c] >> num) & 1) && !((box[GetIndexofBox(r,c)] >> num) & 1);
}
void SetInitialSudoku(vector<vector<int>>& grid, vector<int>& row, vector<int>& col, vector<int>& box){
    int size = grid.size();
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            row[i] |= 1 << grid[i][j],
            col[j] |= 1 << grid[i][j],
            box[GetIndexofBox(i,j)] |= 1 << grid[i][j];
}
bool SudokuWithBitMask(vector<vector<int>>& grid, int r, int c, vector<int>& row, vector<int>& col, vector<int>& box){
    static bool seted = false;
    int size = grid.size();
    if(!seted)
        seted = true, SetInitialSudoku(grid, row, col, box);
    if(r == size-1 && c == size)
        return true;
    if(c == size)
        c = 0, r++;
    if(grid[r][c])
        return SudokuWithBitMask(grid, r, c+1, row, col, box);
    for(int i=1; i<=size; i++){
        if(CanWriteNumWithBitMask(row, col, box, r, c, i)){
            grid[r][c] = i;
            row[r] |= 1 << i;
            col[c] |= 1 << i;
            box[GetIndexofBox(r,c)] |= 1 << i;
            if(SudokuWithBitMask(grid, r, c+1, row, col, box))
                return true;
            row[r] &= ~(1 << i);
            col[c] &= ~(1 << i);
            box[GetIndexofBox(r,c)] &= ~(1 << i);
        }
        grid[r][c] = 0;
    }
    return false;
}

// Remove Invalid Parentheses in string
bool IsParenthesis(char c){
    return c=='(' || c==')';
}
bool IsValidParenthesis(string s){
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')')
            cnt--;
        if(cnt < 0)
            return false;
    }
    return (cnt==0);
}
void RemoveInvalidParentheses(string s){
    if(s.empty())
        return;
    unordered_set<string> visit;
    queue<string> q;
    string temp;
    bool level;
    q.push(s);
    visit.insert(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        if(IsValidParenthesis(s)){
            cout << s << endl;
            level = true;
        }
        if(level)
            continue;
        for(int i=0; i<s.length(); i++){
            if(!IsParenthesis(s[i]))
                continue;
            temp = s.substr(0, i) + s.substr(i+1);
            if(visit.find(temp) == visit.end()){
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
}

// Print Gray code from 0 to 2^n-1
void GraycodeToNBitNum(vector<int>& res, int n, int& cur){
    if(n==0){
        res.push_back(cur);
        return;
    }
    GraycodeToNBitNum(res, n-1, cur);
    cur ^= 1 << (n-1);
    GraycodeToNBitNum(res, n-1, cur);
}

// Permutation of String
void PermutateString(string& str, int l, int r){
    if(l == r)
        cout << str << endl;
    else{
        for(int i=l; i<=r ; i++){
            swap(str[l], str[i]);
            PermutateString(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}
void PermutateStringWithSTL(string str, string out){
    if(!str.size()){
        cout << out << endl;
        return;
    }
    for(int i=0; i<str.size(); i++){
        PermutateStringWithSTL(str.substr(1), out+str[0]);
        rotate(str.begin(), str.begin()+1, str.end());
    }
}
void PermutateStringWithNextPermutation(string str){
    //If cur string is lexicographically largest, next_permutation returns false
    sort(str.begin(), str.end());
    unordered_set<string> res;
    do{
        res.insert(str);
        //cout << str << endl;
    }while(next_permutation(str.begin(), str.end()));
    for(auto k : res)
        cout << k << endl;
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// --------------------------------- Greedy -------------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Acitivity Selection Problem
void PrintMaxActivities(vector<pair<int,int>>& work, vector<int>& result){
    // work.first = end time, work.second = start time
    if(!is_sorted(work.begin(), work.end()))
        sort(work.begin(), work.end());
    int i=0, j;
    int size = work.size();
    result.push_back(i);
    for(j=1; j<size; j++){
        if(work[j].second >= work[i].first){
            result.push_back(j);
            i = j;
        }
    }
}

// Job Sequencing Problem
struct Job{
    char id;
    int deadline;
    int profit;
};
bool CompareProfit(Job a, Job b){
    return a.profit > b.profit;
}
void PrintMaxProfitJobSequencing(Job* arr, int n, vector<char>& result){
    sort(arr, arr+n, CompareProfit);
    vector<bool> slot(n, false);
    vector<int> day(n, -1);
    for(int i=0; i<n; i++){// i = job number
        for(int j=min(n, arr[i].deadline)-1; j>=0; j--){// j = work day
            if(slot[j] == false){
                day[j] = i;
                result.push_back(arr[day[j]].id);
                slot[j] = true;
                break;
            }
        }
    }
}
struct JobProfit{
    bool operator()(Job const& a, Job const& b){
        return a.profit < b.profit;
    }
};
void PrintMaxProfitJobSequencingWithPriorityQueue(Job* arr, int n, vector<Job>& result){
    // Ascending order
    sort(arr, arr+n, [](Job a, Job b){return a.deadline < b.deadline;});
    // Descending order
    priority_queue<Job, vector<Job>, JobProfit> pq;
    for(int i = n-1; i>=0 ; i--){
        int slot;
        if(i==0)
            slot = arr[i].deadline;
        else
            slot = arr[i].deadline - arr[i-1].deadline;
        pq.push(arr[i]);
        while(slot > 0 && pq.size() > 0){
            Job job = pq.top();
            pq.pop();
            slot--;
            result.push_back(job);
        }
    }
    sort(result.begin(), result.end(), [&](Job a, Job b){return a.deadline < b.deadline;});
    for(int i=0; i<result.size(); i++)
        cout << result[i].id << ' ';
    cout << endl;
}

struct DisjointSetForJobSequencing{
    int* parent;
    DisjointSetForJobSequencing(int n){
        parent = new int[n+1];
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }
    int Find(int s){
        if(s == parent[s])
            return s;
        return parent[s] = Find(parent[s]);
    }
    void Merge(int u, int v){
        parent[v] = u;
    }
};
int FindMaxDeadline(Job* arr, int n){
    int result = INT_MIN;
    for(int i=0; i<n; i++)
        result = max(result, arr[i].deadline);
    return result;
}
void PrintMaxProfitJobSequencingWithDisjointSet(Job* arr, int n){
    sort(arr, arr+n, CompareProfit);
    int max_deadline = FindMaxDeadline(arr, n);
    DisjointSetForJobSequencing ds(max_deadline);
    for(int i=0; i<n ; i++){
        int slot = ds.Find(arr[i].deadline);
        if(slot > 0){
            ds.Merge(ds.Find(slot-1), slot);
            cout << arr[i].id << " ";
        }
    }
}

// Huffman coding
struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct CompareFrequency{
    //In priority queue, this function works in ascending order.
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return l->freq > r->freq;
    }
};
void PrintCode(MinHeapNode* root, string str){
    if(!root)
        return;
    if(root->data != '$')
        cout << root->data << ": " << str << endl;
    PrintCode(root->left, str+"0");
    PrintCode(root->right, str+"1");
}
void StoreCode(MinHeapNode* root, string str, map<char,string>& codes){
    if(root == NULL)
        return;
    if(root->data != '$')
        codes[root->data] = str;
    StoreCode(root->left, str+"0", codes);
    StoreCode(root->right, str+"1", codes);
}
void Huffman_Encoding(map<char, int>& freqTable, map<char, string>& codes, priority_queue<MinHeapNode*, vector<MinHeapNode*>, CompareFrequency>& minheap){
    MinHeapNode* left, *right, *top;
    int size = freqTable.size();
    for(map<char, int>::iterator i = freqTable.begin(); i!=freqTable.end() ;i++)
        minheap.push(new MinHeapNode(i->first, i->second));
    while(minheap.size() != 1){
        left = minheap.top();
        minheap.pop();
        right = minheap.top();
        minheap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minheap.push(top);
    }
    StoreCode(minheap.top(), "", codes);
}
void CalculateCharFrequency(map<char, int>& freqTable, string str){
    for(int i=0; i<str.size(); i++)
        freqTable[str[i]]++;
}
string Huffman_Decoding(MinHeapNode* root, string s){
    string result = "";
    MinHeapNode* cur = root;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0')
            cur = cur->left;
        else
            cur = cur->right;
        if(cur->left == NULL && cur->right == NULL){
            result += cur->data;
            cur = root;
        }
    }
    return result+'\0';
}

// Water Connection Problem
int DFS(int k, int& p, vector<int>& start,  vector<int>& pipe){
    if(start[k] == 0)// if End house
        return k;
    if(pipe[k] < p)
        p = pipe[k];
    return DFS(start[k], p, start, pipe);
}
void WaterConnection(vector<vector<int>>& arr, vector<int>& start, vector<int>& end, vector<int>& pipe){
    int n_house = start.size();
    int n_pipe = arr.size();
    vector<vector<int>> result;
    for(int i=0; i<n_pipe; i++){
        int h1=arr[i][0], h2=arr[i][1], diameter=arr[i][2];
        start[h1] = h2;
        pipe[h1] = diameter;
        end[h2] = h1;
    }
    for(int i=1; i<=n_house; i++){
        if(end[i] == 0 && start[i]){// Start house's Condition
            int p = INF;
            int end_point = DFS(i, p, start, pipe);
            result.push_back({i, end_point, p});
        }
    }
    cout << "Number of (tank, tap): "<< result.size() << endl;
    for(auto t : result){
        for(auto y : t)
            cout << y << " ";
        cout << endl;
    }
}

// Minumum Swap for Bracket Balancing
int MinSwapCount(string s){
    vector<int> pos;
    int size = s.size();
    for(int i=0; i<size; i++)
        if(s[i] == '[')
            pos.push_back(i);
    int count=0, n_swap =0, p=0;
    for(int i=0; i<size; i++){
        if(s[i] == '[')
            count++, p++;
        else
            count--;
        if(count < 0){
            n_swap += pos[p]-i;
            swap(s[i], s[pos[p]]);
            p++;
            count = 1;
        }
    }
    return n_swap;
}

// Egyptian Fraction
void EgyptianFraction(int n, int d){
    //n: numerator, d: denominator
    if(d==0 || n==0)
        return;
    if(d % n == 0){//simplify
        cout << "1/" << d/n;
        return;
    }
    if(n%d == 0){//not fraction(integer )
        cout << n/d;
        return;
    }
    if(n/d){// Improper fraction
        cout << n/d << " + ";
        EgyptianFraction(n%d, d);
        return;
    }
    int x = d/n+1;
    cout << "1/" << x << " + ";
    EgyptianFraction(n*x-d, d*x);
}
vector<int> GetEgyptianFraction(int n, int d, vector<int> d_list){
    if(n==0)
        return d_list;
    int x = ceil((double)d/n);
    d_list.push_back(x);
    d_list = GetEgyptianFraction(n*x-d, d*x, d_list);
    return d_list;
}

// Policemen catch thieves
int PoliceCatchThief(string str, int k){
    int result = 0;
    int size = str.length();
    for(auto& k : str)
        k = tolower(k);
    vector<int> pol;
    vector<int> thi;
    for(int i=0; i<size; i++){
        if(str[i] == 'p')
            pol.push_back(i);
        else if(str[i] == 't')
            thi.push_back(i);
    }
    int l=0, r=0;
    int t_size = thi.size(), p_size = pol.size();
    while(l<t_size && r<p_size){
        if(abs(thi[l] - pol[r]) <= k)
            l++, r++, result++;
        else if(thi[l] < pol[r])
            l++;
        else
            r++;
    }
    return result;
}

// Fitting Shelves Problem
void FittingShelves(int wall, int a, int b){
    int p = wall/a, q=0, rem=wall%a;
    int n_a=p, n_b=q, minspace = rem;
    while(wall >= b){
        q += 1;
        wall -= b;
        p = wall / a;
        rem = wall % a;
        if(rem <= minspace){
            n_a = p;
            n_b = q;
            minspace = rem;
        }
    }
    cout << n_a << " " << n_b << " " << minspace << endl;
}

// Assign Mice to Holes
int AssignMice2Hole(vector<int>& mice, vector<int>& hole){
    int n = mice.size();
    sort(mice.begin(), mice.end());
    sort(hole.begin(), hole.end());
    int max = 0;
    for(int i=0; i<n; i++)
        if(max < abs(mice[i]-hole[i]))
            max = abs(mice[i]-hole[i]);
    return max;
}

// Minimum Product Subset of Array
int MinProductSubset(vector<int> arr){
    int size = arr.size();
    int count_neg=0, count_zero=0, result=1;
    int max_neg = INT_MAX, min_pos = INT_MAX;
    if(size == 1)
        return arr[0];
    for(int i=0; i<size; i++){
        if(arr[i] == 0){
            count_zero++;
            continue;
        }
        else if(arr[i] < 0){
            count_neg++;
            max_neg = max(max_neg, arr[i]);
        }
        else if(arr[i] > 0)
            min_pos = min(min_pos, arr[i]);
        result *= arr[i];
    }
    if(count_zero == size || (count_neg == 0 && count_zero >0))
        return 0;
    if(count_neg == 0)
        return min_pos;
    if(!(count_neg & 1) && count_neg !=0)
        result /=max_neg;
    return result;
}

int SumArray(vector<int>& arr){
    int sum=0;
    for(auto& k : arr)
        sum += k;
    return sum;
}
int MaxArraySumKNegation(vector<int>& arr, int k){
    int size = arr.size();
    int sum=0, i=0;
    sort(arr.begin(), arr.end());
    for(i=0; i<size; i++){
        if(k && arr[i] < 0){
            arr[i] *= -1;
            --k;
            continue;
        }
        break;
    }
    if(i==size)
        --i;
    if(k==0 || k%2 == 0)
        return SumArray(arr);
    if(i != 0 && abs(arr[i]) >= abs(arr[i-1]))
        --i;
    arr[i] *= -1;
    return SumArray(arr);
}

// Min sum of proudct of 2 arrays
int MinSumOfProductOfTwoArray(vector<int>& a,vector<int>& b, int k){
    int diff = 0, result =0;
    int size = a.size();
    int tmp;
    for(int i=0 ; i<size; i++){
        int mult = a[i] * b[i];
        result += mult;
        if(mult <0 && b[i] <0)
            tmp = (a[i]+2*k) * b[i];
        else if(mult <0 && a[i] <0)
            tmp = (a[i]-2*k) * b[i]; 
        else if(mult >0 && a[i] <0)
            tmp = (a[i] +2*k) * b[i];
        else if(mult >0 && a[i] >0)
            tmp = (a[i]-2*k) * b[i];
        int d = abs(mult-tmp);
        if(d > diff)
            diff = d;
    }
    return result-diff;
}

// Min sum of absolute difference of pairs of 2 arrays
int MinSumOfAbsDiffOfPairTwoArr(vector<int>& a, vector<int>& b){
    int size = a.size();
    int sum = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<size; i++)
        sum += abs(a[i]-b[i]);
    return sum;
}

// Min Inc/Dec to make array non-inc
int TransformNonIncArr(vector<int>& arr){
    int result = 0;
    int size = arr.size();
    priority_queue<int> pq;
    for(int i=size-1; i>=0; --i){
        if(!pq.empty() && pq.top() > arr[i]){
            result += abs(arr[i]-pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        pq.push(arr[i]);
    }
    return result;
}

// Sorting Array with reverse around midlle
bool IsSortingWithOnlyReverse(vector<int>& arr){
    int size = arr.size();
    vector<int> temp(arr);
    sort(temp.begin(), temp.end());
    for(int i=0; i<size; ++i)
        if(!(arr[i] == temp[i]) && !(arr[size-1-i] == temp[i]))
            return false;
    return true;
}

// Sum of Areas of Rectangles Possible for an Array
int MaxSumAreaOfRectangle(vector<int>& arr){
    int size = arr.size();
    int sum = 0;
    bool flag = false;
    int len;
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0; i<size ; ++i){
        if((arr[i] == arr[i+1] || arr[i]-arr[i+1] == 1) && !flag){
            flag = !flag;
            len = arr[i+1];
            i++;
        }
        else if((arr[i] == arr[i+1] || arr[i]-arr[i+1] == 1) && flag){
            flag = !flag;
            sum += arr[i+1] * len;
            i++;
        }
    }
    return sum;
}

// Largest lexicographic array with at-most K consecutive swaps
void AtMostKSwap(vector<int>& arr, int k){
    int size = arr.size();
    for(int i=0; i<size-1 && k>0; i++){
        int pos = i;
        for(int j=i+1; j<size; j++){
            if(k <= j-i)
                break;
            if(arr[j] > arr[pos])
                pos = j;
        }
        for(int j=pos; j>i; j--)
            swap(arr[j], arr[j-1]);
        k -= pos-i;
    }
}

// Partition into two subsets of lengths K and (N – k) such that the difference of sums is maximum
int MaxDiffofSumOfSubset(vector<int>& arr, int k){
    int size = arr.size();
    int diff = 0, sum1=0, sum2=0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<k; i++)
        sum1 += arr[i];
    for(int i=k; i<size; i++)
        sum2 += arr[i];
    return diff = abs(sum1-sum2);
}

// First Fit in memory management
void FirstFit(vector<int>& block, vector<int>& process){
    int b_size = block.size();
    int p_size = process.size();
    vector<int> alloc(p_size, -1);
    for(int i=0; i<p_size; i++){
        for(int j=0; j<b_size; j++){
            if(block[j] >= process[i]){
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
    for(int i=0; i<p_size; i++){
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if(alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not allocated";
        cout << endl;
    }
}

// Best Fit in memory management
void BestFit(vector<int>& block, vector<int>& process){
    int b_size = block.size();
    int p_size = process.size();
    vector<int> alloc(p_size, -1);
    for(int i=0; i<p_size; i++){
        int best = -1;
        for(int j=0; j<b_size; j++){
            if(block[j] >= process[i]){
                if(best == -1)
                    best = j;
                else if(block[best] > block[j])
                    best = j;
            }
        }
        if(best != -1){
            alloc[i] = best;
            block[best] -= process[i];
        }
    }
    for(int i=0; i<p_size; i++){
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if(alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not allocated";
        cout << endl;
    }
}

// Worst Fit in memory management
void WorstFit(vector<int>& block, vector<int>& process){
    int b_size = block.size();
    int p_size = process.size();
    vector<int> alloc(p_size, -1);
    for(int i=0; i<p_size; i++){
        int worst = -1;
        for(int j=0; j<b_size; j++){
            if(block[j] >= process[i]){
                if(worst == -1)
                    worst = j;
                else if(block[worst] < block[j])
                    worst = j;
            }
        }
        if(worst != -1){
            alloc[i] = worst;
            block[worst] -= process[i];
        }
    }
    for(int i=0; i<p_size; i++){
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if(alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not allocated";
        cout << endl;
    }
}

// Non-preemptive Shortest Job First (CPU Scheduling)
bool CompareBurstTime(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
void NonPreempShortestJobFirst(vector<vector<int>>& process){
    int size = process.size();
    int time_total_wait = 0, time_total_tat=0;
    double time_avg_wait = 0, time_avg_tat = 0;
    sort(process.begin(), process.end(), CompareBurstTime);
    process[0].push_back(0);
    for(int i=1; i<size; i++){
        process[i].push_back(0);
        for(int j=0; j<i; j++)
            process[i][2] += process[j][1];
        time_total_wait += process[i][2];
    }
    time_avg_wait = (double)time_total_wait / size;
    cout << "P     BT     WT     TAT" << endl;
    for(int i=0; i<size; i++){
        process[i].push_back(process[i][1]+process[i][2]);
        time_total_tat += process[i][3];
        cout << "P" << process[i][0] << "     " << process[i][1] << "     " << process[i][2] << "      " << process[i][3] << endl;
    }
    time_avg_tat = (double)time_total_tat / size;
    cout << "Average Waiting Time= " << time_avg_wait << endl;
    cout << "Average Turnaround Time= " << time_avg_tat << endl;
}

// Job Scheduling with 2 jobs allowed at a time
bool CheckTwoJobsAtATime(vector<pair<int, int>>& job){
    int size = job.size();
    sort(job.begin(), job.end());
    int j1 = job[0].second, j2 = job[1].second;
    for(int i=2; i<size; i++){
        if(job[i].first >= j1){
            j1 = j2;
            j2 = job[i].second;
        }
        else if(job[i].first >= j2)
            j2 = job[i].second;
        else
            return false;
    }
    return true;
}

// Optimal Page replacement algorithm
bool SearchKey(vector<int>& frame, int key){
    for(int i=0; i<frame.size(); i++)
        if(frame[i] == key)
            return true;
    return false;
}
int PredictNotUsedInFuture(vector<int>& frame, vector<int>& page, int index){
    int result = -1, far = index;
    for(int i=0; i<frame.size(); i++){
        int j;
        for(j = index; j<page.size(); j++)
            if(frame[i] == page[j]){
                if(j > far){
                    far = j;
                    result = i;
                }
                break;
            }
        if(j == page.size())
            return i;
    }
    return result == -1 ? 0 : result;
}
void OptimalPageReplacement(vector<int>& page, int f_size){
    vector<int> frame;
    int hit = 0;
    int p_size = page.size();
    for(int i=0; i<p_size; i++){
        if(SearchKey(frame, page[i])){
            hit++;
            continue;
        }
        if(frame.size() < f_size)
            frame.push_back(page[i]);
        else{
            int j = PredictNotUsedInFuture(frame, page, i+1);
            frame[j] = page[i];
        }
    }
    cout << "hit= " << hit << endl;
    cout << "miss= " << p_size - hit << endl;
}
void OptimalPageReplacementWithUnorderedSet(vector<int>& page, int f_size){
    vector<int> frame(f_size, -1);
    int hit = 0;
    int p_size = page.size();
    for(int i=0 ; i<p_size ; i++){
        bool found = false;
        bool emptyFrame = false;
        int far = -1, repIdx = -1;
        for(int j=0; j<f_size; j++){
            int k;
            if(frame[j] == page[i]){// page found in a frame: hit
                hit++;
                found = true;
                break;
            }
            if(frame[j] == -1){// Page not found in a frame: miss
                frame[j] = page[i];
                emptyFrame = true;
                break;
            }
        }
        if(found || emptyFrame)
            continue;
        for(int j=0; j<f_size; j++){
            int k;
            for(k = i+1; k<p_size; k++){
                if(frame[j] == page[k]){
                    if(k > far){
                        far = k;
                        repIdx = j;
                    }
                    break;
                }
            }
            if(k == p_size){
                repIdx = j;
                break;
            }
        }
        frame[repIdx] = page[i];
    }
    cout << "hit = " << hit << endl;
    cout << "miss = " << p_size - hit << endl;
}

// Kruskal's Minimum Spanning Tree
class DSU{// Disjoint Set Union
    int* parent;
    int* rank;
public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int Find(int i){// Search element that connected others
        if(parent[i] == -1)
            return i;
        return parent[i] = Find(parent[i]);
    }
    void Unite(int x, int y){
        int s1 = Find(x);
        int s2 = Find(y);
        if(s1 != s2){
            if(rank[s1] < rank[s2])
                parent[s1] = s2;
            else if(rank[s1] > rank[2])
                parent[s2] = s1;
            else{// same rank
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};
class Graph{
    vector<vector<int>> edgelist;
    int v;
public:
    Graph(int v) { this->v = v;}
    void AddEdge(int x, int y, int w){
        edgelist.push_back({w, x, y});
    }
    void Kruskal_MST(){
        sort(edgelist.begin(), edgelist.end());
        DSU s(v);
        int result;
        for(auto edge : edgelist){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if(s.Find(x) != s.Find(y)){
                s.Unite(x, y);
                result += w;
                cout << x << "--" << y << "==" << w << endl;
            }
        }
        cout << "Min cost(weight) spanning tree: " << result;
    }
};

// Prim's Minimum Spanning Tree
int FindMinWeightVertexinFringeVertex(vector<int>& key, vector<bool>& mst){
    int min = INT_MAX, min_vertex_idx;
    int size = key.size();
    for(int i=0 ; i<size; i++)
        if(mst[i] == false && key[i] < min)// Find vertex that have min weight in fringe set
            min = key[i], min_vertex_idx = i;
    return min_vertex_idx;
}
void PrintMST(vector<int>& parent, vector<vector<int>>& graph){
    int size = graph.size();
    cout << "Edge \tWeight\n";
    for(int i=1; i<size; i++)
        cout << parent[i] << "-" << i << "\t" << graph[i][parent[i]] << endl;
}
void Prim_MSTwithAdjacencyMatrix(vector<vector<int>>& graph){
    int size = graph.size();
    vector<int> parent(size, -1);
    vector<int> key(size, INT_MAX);
    vector<bool> inMST(size, false);
    key[0] = 0;
    for(int count=0; count<size-1; count++){
        int u = FindMinWeightVertexinFringeVertex(key, inMST);
        inMST[u] = true;
        for(int v = 0; v<size; v++)
            if(graph[u][v] && inMST[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    PrintMST(parent, graph);
}

int Prim_MSTwithPriorityQueue(vector<vector<int>>& edge){
    int size = edge.size();
    int result = 0;
    vector<vector<int>> adj[size];
    for(int i=0; i<size; i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(size, false);
    pq.push({0,0});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        int u = p.second;
        if(visited[u] == true)
            continue;
        result += w;
        visited[u] = true;
        for(auto v : adj[u])
            if(visited[v[0]] == false)
                pq.push({v[1], v[0]});
    }
    return result;
}

// Boruvka's Minimum Spanning Tree
class BoruvkaGraph{
    int v;
    vector<vector<int>> graph;
    int Find(vector<int>& parent, int i){
        if(parent[i] == i)
            return i;
        return parent[i] = Find(parent, parent[i]);
    }
    void UnionSet(vector<int>& parent, vector<int>& rank, int x, int y){
        int xroot = Find(parent, x);
        int yroot = Find(parent, y);
        if(rank[xroot] < rank[yroot])
            parent[xroot] =yroot;
        else if(rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else{
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
public:
    BoruvkaGraph(int v){
        this->v = v;
        graph = vector<vector<int>> ();
    }
    void AddEdge(int u, int v, int w){
        graph.push_back({u, v, w});
    }
    void Boruvka_MST(){
        vector<int> parent(v);
        vector<int> rank(v);
        vector<vector<int>> cheapest(v, vector<int>(3, -1));
        int numTree = v;
        int MSTweight = 0;
        for(int i=0; i<v; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        while(numTree > 1){
            for(int i=0; i<graph.size(); i++){
                int u = graph[i][0], v = graph[i][1], w = graph[i][2];
                int set1 = Find(parent, u), set2 = Find(parent, v);
                if(set1 != set2){
                    if(cheapest[set1][2] == -1 || cheapest[set1][2] > w )
                        cheapest[set1] = {u, v, w};
                    if(cheapest[set2][2] == -1 || cheapest[set2][2] > w )
                        cheapest[set2] = {u, v, w};
                }
            }
            for(int i=0; i<v; i++){
                if(cheapest[i][2] != -1){
                    int u = cheapest[i][0], v = cheapest[i][1], w = cheapest[i][2];
                    int set1 = Find(parent, u), set2 = Find(parent, v);
                    if(set1 != set2){
                        MSTweight += w;
                        UnionSet(parent, rank, set1, set2);
                        printf("Edge %d-%d with weight %d included in MST\n", u, v, w);
                        numTree--;
                    }
                }
            }
            for(int i=0; i<v; i++)
                cheapest[i][2] = -1;
        }
        printf("Weight of MST is %d\n", MSTweight);
    }
};

// Dinic's Max FLow Problem
struct Edge{
    int v;
    int flow;
    int cap;
    int reverse;
};
class DinicGraph{
    int v;
    int* level;
    vector<Edge>* adj;
public:
    DinicGraph(int v){
        adj = new vector<Edge>[v];
        this->v = v;
        level = new int[v];
    }
    void AddEdge(int u, int v, int cap){
        Edge a{v, 0, cap, (int)adj[v].size()};
        Edge b{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);//reverse edge
    }
    bool BFS(int s, int t){
        for(int i=0; i<v; i++)
            level[i] = -1;
        level[s] = 0;
        list<int> q;
        q.push_back(s);
        vector<Edge>::iterator it;
        while(!q.empty()){
            int u = q.front();
            q.pop_front();
            for(it=adj[u].begin(); it!=adj[u].end(); it++){
                Edge& e = *it;
                if(level[e.v] < 0 && e.flow < e.cap){//if connected node from cur node
                    level[e.v] = level[u]+1;// connected node's level + 1 
                    q.push_back(e.v);
                }
            }
        }
        return level[t] < 0 ? false : true;
    }
    int SendFlow(int u, int flow, int t, vector<int>& next){
        if(u == t)
            return flow;
        for(; next[u] < adj[u].size(); next[u]++){
            Edge& e = adj[u][next[u]];
            if(level[e.v] == level[u]+1 && e.flow < e.cap){
                int cur_flow = min(flow, e.cap-e.flow);
                int temp_flow = SendFlow(e.v, cur_flow, t, next);
                if(temp_flow > 0){
                    e.flow += temp_flow;
                    adj[e.v][e.reverse].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }
    int Dinic_MaxFlow(int s, int t){
        if(s == t)
            return -1;
        int total = 0;
        while(BFS(s, t) == true){
            vector<int> next(v+1, 0);
            while(int flow = SendFlow(s, INT_MAX, t, next))
                total += flow;
        }
        return total;
    }
};

// Ford-Fulkerson's Max Flow Problem
bool Fulkerson_MaxFlow_BFS(vector<vector<int>>& graph, int s, int t, vector<int>& parent){
    int size = graph.size();
    vector<bool> visited(size, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<size; ++v){
            if(visited[v] == false && graph[u][v] > 0){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
int Fulkerson_MaxFlow(vector<vector<int>>& graph, int s, int t){
    int u, v;
    int size = graph.size();
    vector<int> parent(size);
    int max_flow = 0;
    while(Fulkerson_MaxFlow_BFS(graph, s, t, parent)){
        int path_flow = INT_MAX;
        for(v = t; v!=s; v=parent[v])
            path_flow = min(path_flow, graph[parent[v]][v]);
        for(v=t; v!=s; v=parent[v]){
            graph[parent[v]][v] -= path_flow;
            graph[v][parent[v]] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

// Number of Single Cycle Components in Undirected Graph
int degree[10000];
bool found[10000];
vector<int> cur_graph;
vector<int> adj_list[10000];
void Cycle_AddEdge(int src, int dest){
    src--, dest--;
    adj_list[src].push_back(dest);
    adj_list[dest].push_back(src);
    degree[src]++;
    degree[dest]++;
}
void Cycle_DFS(int v){
    found[v] = true;
    cur_graph.push_back(v);
    for(int it : adj_list[v])
        if(!found[it])
            Cycle_DFS(it);
}
int CountingCycle(int n, int m){
    int count = 0;
    for(int i =0; i<n; i++){
        if(!found[i]){
            cur_graph.clear();
            Cycle_DFS(i);
            bool flag = true;
            for(int v : cur_graph){
                if(degree[v] == 2)
                    continue;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                count++;
        }
    }
    return count;
}

// Bin Packing Problem(Minimize number of used bins)
int BinPakcing_NextFit(vector<int>& weight, int cap){
    int size = weight.size();
    int res = 0, bin_rem = cap;
    for(int i=0; i<size; i++){
        if(weight[i] > bin_rem){
            res++;
            bin_rem = cap-weight[i];
        }
        else
            bin_rem -= weight[i];
    }
    return res;
}
int BinPacking_FirstFit(vector<int>& weight, int cap){
    int size = weight.size();
    int res = 0;
    vector<int> bin_rem(size, cap);
    for(int i=0; i<size; i++){
        int j;
        for(j=0; j<res; j++)
            if(bin_rem[j] >= weight[i]){
                bin_rem[j] -= weight[i];
                break;
            }
        if(j == res){
            bin_rem[res] = cap - weight[i];
            res++;
        }
    }
    return res;
}
int BinPacking_BestFit(vector<int>& weight, int cap){
    int size = weight.size();
    int res = 0;
    vector<int> bin_rem(size, cap);
    for(int i=0 ; i<size; i++){
        int j;
        int min_space = cap +1, bestbin_idx = 0;
        for(j=0; j<res; j++)
            if(bin_rem[j] >= weight[i] && bin_rem[j]-weight[i] < min_space){
                bestbin_idx = j;
                min_space = bin_rem[j]-weight[i];
            }
        if(min_space == cap+1){
            bin_rem[res] = cap - weight[i];
            res++;
        }
        else
            bin_rem[bestbin_idx] -= weight[i];
    }
    return res;
}
int BinPacking_WorstFit(vector<int>& weight, int cap){
    int size = weight.size();
    int res = 0;
    vector<int> bin_rem(size, cap);
    for(int i=0; i<size; i++){
        int j;
        int max_space = -1, worst_idx = 0;
        for(j=0; j<res; j++)
            if(bin_rem[j] >= weight[i] && bin_rem[j]-weight[i] > max_space){
                worst_idx = j;
                max_space = bin_rem[j] - weight[i];
            }
        if(max_space == -1){
            bin_rem[res] = cap - weight[i];
            res++;
        }
        else
            bin_rem[worst_idx] -= weight[i];
    }
    return res;
}
int BinPacking_FirstFitDecreasing(vector<int>& weight, int cap){
    sort(weight.begin(), weight.end(), greater<int>());
    return BinPacking_FirstFit(weight, cap);
}

// Graph Coloring
class GraphColoring{
    int v;
    list<int> *adj;
public:
    GraphColoring(int v){this->v = v; adj=new list<int>[v];}
    ~GraphColoring(){delete [] adj;}
    void AddEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void Coloring(){
        vector<int> result(v, -1);
        vector<bool> available(v, false);
        result[0] = 0;
        for(int u=1; u<v; u++){
            list<int>::iterator it;
            for(it = adj[u].begin(); it!=adj[u].end(); ++it)
                if(result[*it] != -1)
                    available[result[*it]] = true;
            int color;
            for(color=0; color<v; color++)
                if(available[color] == false)
                    break;
            result[u] = color;
            for(it = adj[u].begin(); it!=adj[u].end(); ++it)
                if(result[*it] != -1)
                    available[result[*it]] = false;
        }
        for(int u=0; u<v; u++)
            cout << "vertex: " << u << "--> color: " << result[u] << endl;
    }
};

// K Centers Problem
int GetIndexOfFartestCity(vector<int>& dist){
    int size = dist.size();
    int idx = 0;
    for(int i=0; i<size; i++)
        if(dist[i] > dist[idx])
            idx = i;
    return idx;
}
void KCenter(vector<vector<int>>& weight, int k){
    int size = weight.size();
    vector<int> dist(size, INF);
    vector<int> center;
    int far_idx = 0;
    for(int i=0; i<k; i++){
        center.push_back(far_idx);
        for(int j=0; j<size; j++)
            dist[j] = min(dist[j], weight[far_idx][j]);
        far_idx = GetIndexOfFartestCity(dist);
    }
    cout << dist[far_idx] << endl;
    for(auto k: center)
        cout << k << " ";
    cout << endl;
}

// Shortest Superstring Problem
int min(int a, int b){
    return a < b ? a : b;
}
int FindOverlappingPair(string str1, string str2, string& str){
    int max = INT_MIN;
    int len1 = str1.length();
    int len2 = str2.length();
    for(int i=1; i<=min(len1,len2); i++){
        if(str1.compare(len1-i, i, str2, 0, i)==0){
            if(max < i){
                max = i;
                str = str1 + str2.substr(i);
            }
        }
    }
    for(int i=1; i<=min(len1, len2); i++){
        if(str1.compare(0, i, str2, len2-i, i)==0){
            if(max < i){
                max = i;
                str = str2 + str1.substr(i);
            }
        }
    }
    return max;
}
string FindShortestSuperstring(vector<string> arr){
    int size = arr.size();
    while(size != 1){
        int max = INT_MIN;
        int l, r;
        string res;
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                string str;
                int overlapped = FindOverlappingPair(arr[i], arr[j], str);
                if(max < overlapped){
                    max = overlapped;
                    res.assign(str);
                    l = i, r = j;
                }
            }
        }
        size--;
        if(max == INT_MIN)
            arr[0] += arr[size];
        else{
            arr[l] = res;
            arr[r] = arr[size];
        }
    }
    return arr[0];
}

// Fractional Knapsack Problem
struct Item{
    int profit, weight;
    Item(int profit, int weight){
        this->profit = profit;
        this->weight = weight;
    }
};
bool CompareItemProfit(Item a, Item b){
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
double FractionalKnapSack(int w, Item arr[], int n){
    sort(arr, arr+n, CompareItemProfit);
    double result = 0.0;
    for(int i=0; i<n; i++){
        if(arr[i].weight <= w){
            w -= arr[i].weight;
            result += arr[i].profit;
        }
        else{
            result += arr[i].profit * ((double)w/(double)arr[i].weight);
            break;
        }
    }
    return result;
}

// Minimum number of coins
void FindMinCoins(int v){
    vector<int> denomination = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int d_size = denomination.size();
    sort(denomination.begin(), denomination.end(), greater<int>());
    vector<int> result;
    for(int i=0; i<d_size; i++){
        while(v >= denomination[i]){
            v -= denomination[i];
            result.push_back(denomination[i]);
        }
    }
    for(auto k : result)
        cout << k << " ";
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// -------------------------- Dynamic Programming -------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Count ways to assign unique cap to every person
long long int CountWaysToAssignCap(int mask, int cap, vector<int> caplist[101], vector<vector<int>>& dp, int allmask){
    if(mask == allmask)
        return 1;
    if(cap > 100)
        return 0;
    if(dp[mask][cap] != -1)
        return dp[mask][cap];
    long long int ways = CountWaysToAssignCap(mask, cap+1, caplist, dp, allmask);
    int size = caplist[cap].size();
    for(int j=0; j<size; j++){
        if(mask & (1<<caplist[cap][j]) )
            continue;
        else
            ways += CountWaysToAssignCap(mask | (1<<caplist[cap][j]) , cap+1, caplist, dp, allmask);
        ways %= 1000000007;
    }
    return dp[mask][cap] = ways;
}

// Traverlling Salesman Problem
vector<pair<int,int>> dirty;
int X[] = {-1, 0, 0, 1};//top, right, left, bottom
int Y[] = {0, 1, -1, 0};
bool IsSafe_TravelSalesman(vector<vector<char>>& arr, int x, int y, int r, int c){
    if(x >= r || y >= c || x < 0 || y < 0 )
        return false;
    if(arr[x][y] == '#')
        return false;
    return true;
}
void GetDist_TravelSalesman(vector<vector<vector<int>>>& dist, vector<vector<char>>& arr, int r, int c, int idx){
    int size = dirty.size();
    vector<vector<bool>> visited(size, vector<bool>(size, false));
    int cx = dirty[idx].first;
    int cy = dirty[idx].second;
    queue<pair<int, int>> q;
    q.push({cx, cy});
    for(int i=0; i<=r ; i++)
        for(int j=0; j<=c; j++)
            dist[i][j][idx] = INF;
    visited[cx][cy] = false;
    dist[cx][cy][idx] = 0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            cx = x.first + X[i];
            cy = x.second + Y[i];
            if(IsSafe_TravelSalesman(arr, cx, cy, r, c)){
                if(visited[cx][cy])
                    continue;
                visited[cx][cy] = true;
                dist[cx][cy][idx] = dist[x.first][x.second][idx]+1;
                q.push({cx, cy});
            }
        }
    }
}
int TravelSalesman_Bitmasking(int idx, int mask, vector<vector<int>>& dp,  vector<vector<vector<int>>>& dist){
    int len = dirty.size();
    int limit = (1<<len) -1;
    if(mask == limit)
        return dist[0][0][idx];
    if(dp[idx][mask] != -1)
        return dp[idx][mask];
    int ret = INT_MAX;
    for(int i=0; i<len; i++){
        if( (mask & (1 << i))==0 ){
            int newMask = mask | (1<<i);
            ret = min(ret, TravelSalesman_Bitmasking(i, newMask, dp, dist)+dist[dirty[i].first][dirty[i].second][idx]);
        }
    }
    return dp[idx][mask] = ret;
}
int TravelSalesman_DP(int i, int mask, vector<vector<int>>& dist, vector<vector<int>>& memo){
    // (1 << n) -1 == ~(1 << n) ==> Set n bits to 1
    int n = dist.size()-1;
    if(mask == ((1<<i) | 3))// 1st bit and i bit
        return dist[1][i];
    if(memo[i][mask] != 0)// if distance is stored, not 0
        return memo[i][mask];
    int result = INF;
    for(int j=1; j<=n; j++)
        if((mask & (1 << j)) && j != i && j != 1)
            result = min(result, TravelSalesman_DP(j, mask & (~(1 << i)), dist, memo)+dist[j][i]);
    return memo[i][mask] = result;
}

// Sum Over Subset
void SumOverSubset_BruteForce(vector<int>& a, int n){
    int sum[1<<n] = {0};
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<(1<<n); j++)
            if((i & j) == j)
                sum[i] += a[j];
    for(int i=0; i<(1<<n); i++)
        cout << sum[i] << " ";
}
void SumOverSubset(vector<int>& a, int n){
    int sum[1<<n] = {0};
    for(int i=0; i<(1<<n); i++){
        sum[i] = a[0];
        for(int j=i; j>0; j=(j-1) & i)
            sum[i] += a[j];
    }
    for(int i=0; i<(1<<n); i++)
        cout << sum[i] << " ";
}

// Fibonacci
int Fibonacci_iterative(int n){// O(n)
    int a = 0, b = 1, c, i;
    if(n==0)
        return a;
    for(int i=2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return b;
}
int Fibonacci_recursion(int n){
    if(n <= 1)
        return n;
    return Fibonacci_recursion(n-1) + Fibonacci_recursion(n-2);
}
int Fibonacci_DP(int n){// O(n)
    int f[n+2];
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}
void MultiplyMatrix(int f[2][2], int m[2][2]){
    int x = f[0][0] * m[0][0] + f[0][1] * m[1][0];
    int y = f[0][0] * m[0][1] + f[0][1] * m[1][1];
    int z = f[1][0] * m[0][0] + f[1][1] * m[1][0];
    int w = f[1][0] * m[0][1] + f[1][1] * m[1][1];
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = w;
}
void Power_Matrix(int f[2][2], int n){
    if(n==0 || n==1)
        return;
    int m[2][2] = {{1, 1}, {1, 0}};
    Power_Matrix(f, n/2);
    MultiplyMatrix(f, f);
    if(n%2 != 0)
        MultiplyMatrix(f, m);
}
int Finonacci_PowerOfMatrix(int n){// O(log n)
    int f[2][2] = {{1, 1}, {1, 0}};
    if(n == 0)
        return 0;
    Power_Matrix(f, n-1);
    return f[0][0];
}
void MultiplyVariableMatrix(vector<vector<int>>& a, vector<vector<int>>& b){
    int r = a.size();
    int c = a[0].size();
    vector<vector<int>> result(r, vector<int>(c, 0));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            for(int k=0; k<r; k++)
                result[i][j] = a[i][k] * b[k][j];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            a[i][j] = result[i][j];
}
int PowerVariableMatrix(vector<vector<int>>& mat, int n){
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>> m(r, vector<int>(c, 0));
    m[0][0] = m[0][1] = m[1][0] = m[2][1] = 1;
    if(n == 1)
        return mat[0][0] + mat[0][1];
    PowerVariableMatrix(mat, n>>1);
    MultiplyVariableMatrix(mat, mat);
    if(n & 1)
        MultiplyVariableMatrix(mat, m);
    return mat[0][0] + mat[0][1];
}
int Finonacci_MatrixExponentiation(int n){
    vector<vector<int>> mat(3, vector<int>(3, 0));
    mat[0][0] = mat[0][1] = mat[1][0] = mat[2][1] = 1;
    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;
    return PowerVariableMatrix(mat, n-2);
}

// Catalan Number
unsigned long int CatalanNumber_Recursion(unsigned int n){
    if(n <= 1)
        return 1;
    unsigned long int result = 0;
    for(int i=0; i<n; i++)
        result += CatalanNumber_Recursion(i) * CatalanNumber_Recursion(n-i-1);
    return result;
}
unsigned long int CatalanNumber_DP(unsigned int n){
    unsigned long int catal[n+1];
    catal[0] = catal[1] = 1;
    for(int i=2; i<=n; i++){
        catal[i] = 0;
        for(int j=0; j<i; j++)
            catal[i] += catal[j] * catal[i-j-1];
    }
    return catal[n];
}
unsigned long int CatalanNumber_BinomialCoefficient(unsigned int n){// O(n)
    unsigned int k =  n;
    n <<= 1;// 2n
    unsigned long int result = 1;
    for(int i=0; i<k; i++){
        result *= (n-i);// (2n ~ n+1)
        result /= (i+1);// n!
    }
    result /= ((n >> 1)+1);
    return result;
}

// Binomial Coefficient
int BinomialCoeff_Recursion(int n, int k){// O(n * max(k, nk))
    if(k > n)
        return 0;
    if(k==0 || k == n)
        return 1;
    return BinomialCoeff_Recursion(n-1, k-1) + BinomialCoeff_Recursion(n-1, k);
}
int BinomialCoeff_DP1(int n, int k){// O(n*k)
    int dp[n+1][k+1];
    for(int i=0; i<=n; i++){// n
        for(int j=0; j<=min(i,k); j++){// k or n-k
            if(j==0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}
int BinomialCoeff_DP2(int n, int k){// O(n*k)
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++)// n
        for(int j=min(i,k); j>0 ;j--)
                dp[j] = dp[j] + dp[j-1];
    return dp[k];
}
int BinomialCoeff_DP3(int n, int k, vector<vector<int>>& dp){
    if(dp[n][k] != -1)
        return dp[n][k];
    if(k== 0 || k==n){
        dp[n][k] = 1;
        return dp[n][k];
    }
    dp[n][k] = BinomialCoeff_DP3(n-1, k-1, dp) + BinomialCoeff_DP3(n-1, k, dp);
    return dp[n][k];
}

// Count All Combination of coins to make sum
int CountAllCombiOfCoint_Recursion(vector<int>& coin, int n,  int sum){// O(2^sum)
    if(sum == 0)
        return 1;
    if(sum < 0 || n <= 0)
        return 0;
    return CountAllCombiOfCoint_Recursion(coin, n, sum-coin[n-1]) + CountAllCombiOfCoint_Recursion(coin, n-1, sum);
}
int CountAllCombiOfCoint_DPmemo(vector<int>& coin, int n,  int sum, vector<vector<int>>& dp){// O(n*sum)
    if(sum == 0)
        return 1;
    if(n == 0 || sum < 0)
        return 0;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    return dp[n][sum] = CountAllCombiOfCoint_DPmemo(coin, n, sum-coin[n-1], dp) + CountAllCombiOfCoint_DPmemo(coin, n-1, sum, dp);
}
int CountAllCombiOfCoint_DPtable(vector<int>& coin, int n,  int sum){// O(n*sum)
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            dp[i][j] += dp[i-1][j];
            if((j-coin[i-1]) >= 0)
                dp[i][j] += dp[i][j-coin[i-1]];
        }
    }
    return dp[n][sum];
}
int CountAllCombiOfCoint_DPoptimal(vector<int>& coin, int n,  int sum){// O(n*sum)
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++)
        for(int j=coin[i]; j<=sum; j++)
                dp[j] += dp[j-coin[i]];
    return dp[sum];
}

// Subset Sum Problem
bool IsSubsetSum_Recursion(vector<int>& set, int n, int sum){// O(2^n)
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(set[n-1] > sum)
        return IsSubsetSum_Recursion(set, n-1, sum);
    return IsSubsetSum_Recursion(set, n-1, sum) || IsSubsetSum_Recursion(set, n-1, sum-set[n-1]);
}
bool IsSubsetSum_DPmemo(vector<int>& set, int n, int sum, vector<vector<int>>& dp){// O(sum * n)
    if(sum == 0)
        return true;
    if(n <= 0)
        return false;
    if(dp[n-1][sum] != -1)
        return dp[n-1][sum];
    if(set[n-1] > sum)
        return dp[n-1][sum] = IsSubsetSum_DPmemo(set, n-1, sum, dp);
    return dp[n-1][sum] = IsSubsetSum_DPmemo(set, n-1, sum, dp) || IsSubsetSum_DPmemo(set, n-1, sum-set[n-1], dp);
}
bool IsSubsetSum_DPtable(vector<int>& set, int n, int sum){
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=sum; i++)
        dp[0][i] = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j < set[i-1])
                dp[i][j] = dp[i-1][j];
            if(j >= set[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }
    return dp[n][sum];
}

//Cutting a Rod
int CutRod_OptimalSubstructure(vector<int>& price, int index, int n){// O(2^n)
    if(index == 0)
        return n * price[0];
    int notCut = CutRod_OptimalSubstructure(price, index-1, n);
    int cut = INT_MIN;
    int rod_length = index+1;
    if(rod_length <= n)
        cut = price[index] + CutRod_OptimalSubstructure(price, index, n-rod_length);
    return max(notCut, cut);
}
int CutRod_OverlappingSubproblem(vector<int>& price, int index, int n, vector<vector<int>>& dp){// O(n^2)
    if(index == 0)
        return n * price[0];
    if(dp[index][n] != -1)
        return dp[index][n];
    int notCut = CutRod_OverlappingSubproblem(price, index-1, n, dp);
    int cut = INT_MIN;
    int rod_length = index + 1;
    if(rod_length <= n)
        cut = price[index] + CutRod_OverlappingSubproblem(price, index, n-rod_length, dp);
    return dp[index][n] = max(notCut, cut);
}
int CutRod_BottomUp(vector<int>& price, int n){// O(n^2)
    int result[n+1];
    result[0] = 0;
    for(int i=1; i<=n; i++){
        int max_val = INT_MIN;
        for(int j=0; j<i; j++)
            max_val = max(max_val, price[j] + result[i-j-1]);
        result[i] = max_val;
    }
    return result[n];
}
int CutRod_UnboundedKnapsack(vector<int>& price, vector<int>& length, int max_len, int n, vector<vector<int>>& dp){// O(n^2)
    if(n == 0 || max_len == 0)
        return 0;
    if(length[n-1] <= max_len)
        dp[n][max_len] = max(price[n-1]+CutRod_UnboundedKnapsack(price, length, max_len-length[n-1], n, dp), CutRod_UnboundedKnapsack(price, length, max_len, n-1, dp));
    else
        dp[n][max_len] = CutRod_UnboundedKnapsack(price, length, max_len, n-1, dp);
    return dp[n][max_len];
}
int CutRod_DPiterative(vector<int>& price, int n){// O(n^2)
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else{
                if(i == 1)
                    dp[i][j] = j * price[i-1];
                else{
                    if(i > j)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j] );
                }
            }
        }
    }
    return dp[n][n];
}

// Painting Fence Algorithm
long PaintingFenceWays(int n, int k){// O(n)
    vector<long> dp(n+1, 0);
    long long mod = 1000000007;
    dp[1] = k;
    dp[2] = k * k;
    for(int i=3; i<=n; i++)
        dp[i] = ((k-1) * (dp[i-1]+dp[i-2])) % mod;
    return dp[n];
}
long PaintingFenceWays_OptimalSpace(int n, int k){// O(n)
    long total = k;
    int mod = 1000000007;
    int same = 0, diff = k;
    for(int i=2; i<=n; i++){
        same = diff;
        diff = (total * (k-1)) % mod;
        total = (same+diff) % mod;
    }
    return total;
}

// Longest Common Subsequence(LCS)
int LCS_Recursion(string s1, string s2, int m, int n){// O(2^(m*n))
    if(m == 0 || n == 0)
        return 0;
    if(s1[m-1] == s2[n-1])
        return 1 + LCS_Recursion(s1, s2, m-1, n-1);
    return max(LCS_Recursion(s1, s2, m, n-1), LCS_Recursion(s1, s2, m-1, n));
}
int LCS_DPmemo(string s1, string s2, int m, int n, vector<vector<int>>& dp){// O(m*n)
    if(m == 0 || n == 0)
        return 0;
    if(s1[m-1] == s2[n-1])
        return dp[m][n] = 1 + LCS_DPmemo(s1, s2, m-1, n-1, dp);
    if(dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = max(LCS_DPmemo(s1, s2, m, n-1, dp), LCS_DPmemo(s1, s2, m-1, n, dp));
}
int LCS_DPtable(string s1, string s2, int m, int n){// O(m*n)
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int LCS_DPOptimalspace(string s1, string s2){// O(m*n)
    int m = s1.size();
    int n = s2.size();
    vector<int> prev(n+1, 0), cur(n+1, 0);
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(i == 0 || j == 0)
                prev[j] = 0;
            if(s1[i-1] == s2[j-1])
                cur[j] = 1 + prev[j-1];
            else
                cur[j] = 0 + max(cur[j-1], prev[j]);
        }
        prev = cur;
    }
    return cur[n];
}

// Longest Increasing Subsequence(LIS)
int LongestIncreasingSubsequence_Recursion(vector<int>& arr, int n, int& max_val){// O(2^n)
    if(n == 1)
        return 1;
    int result, max_end = 1;
    for(int i=1; i<n ; i++){
        result = LongestIncreasingSubsequence_Recursion(arr, i, max_val);
        if(arr[i-1] < arr[n-1] && result+1 > max_end)
            max_end = result + 1;
    }
    if(max_val < max_end)
        max_val = max_end;
    return max_end;
}
int LongestIncreasingSubsequence_DPmemo(int idx, int prev_idx, int n, vector<int>& arr, vector<vector<int>>& dp){// O(n^2)
    if(idx == n)
        return 0;
    if(dp[idx][prev_idx+1] != -1)
        return dp[idx][prev_idx+1];
    int notTake = 0 + LongestIncreasingSubsequence_DPmemo(idx+1, prev_idx, n, arr, dp);
    int take = INT_MIN;
    if(prev_idx == -1 || arr[idx] > arr[prev_idx])
        take = 1 + LongestIncreasingSubsequence_DPmemo(idx+1, idx, n, arr, dp);
    return dp[idx][prev_idx+1] = max(take, notTake);
}
int LongestIncreasingSubsequence_DPtable(vector<int>& arr, int n){// O(n^2)
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    return *max_element(dp, dp+n);
}
int LongestIncreasingSubsequence_BinarySearch(vector<int>& arr){
    int n = arr.size();
    vector<int> result;
    result.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] > result.back())
            result.push_back(arr[i]);
        else{
            int low = lower_bound(result.begin(), result.end(), arr[i])-result.begin();
            result[low] = arr[i];
        }
    }
    for(auto k : result)
        cout << k << " ";
    cout << endl;
    return result.size();
}

// Longest Subsequence that Difference between adjacents in 1
int LongestSubSequenceWithDiffOne_DP(vector<int>& arr, int n){// O(n^2)
    vector<int> dp(n, 1);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[i] == arr[j]+1 || arr[i] == arr[j]-1)
                dp[i] = max(dp[i], dp[j]+1);
    int result = 1;
    for(int i=0; i<n; i++)
        if(result < dp[i])
            result = dp[i];
    return result;
}
int LongestSubSequenceWithDiffOne_DP2(vector<int>& arr){// O(n)
    int n = arr.size();
    if(n==1)
        return 1;
    unordered_map<int, int> m;
    int result = 1;
    for(int i=0; i<n; i++){
        if(m.count(arr[i]+1) > 0 || m.count(arr[i]-1) > 0)
            m[arr[i]] = 1 + max(m[arr[i]+1], m[arr[i]-1]);
        else
            m[arr[i]] = 1;
        result = max(result, m[arr[i]]);
    }
    return result;
}

// Maximum size Square Sub-Matrix with all 1
void PrintMaxSizeSquareWithAllOne(vector<vector<int>>& grid){// O(m * n)
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dp(r, vector<int>(c, -1));
    for(int i=0; i<r; i++)
        dp[i][0] = grid[i][0];
    for(int j=0; j<c; j++)
        dp[0][j] = grid[0][j];
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(grid[i][j] == 1)
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            else
                dp[i][j] = 0;
        }
    }
    int max_dp = dp[0][0];
    int max_i = 0;
    int max_j = 0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(max_dp < dp[i][j]){
                max_dp = dp[i][j];
                max_i = i;
                max_j = j;
            }
    for(int i=max_i; i > max_i - max_dp; i--){
        for(int j=max_j; j > max_j - max_dp; j--)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    
}
void PrintMaxSizeSquareWithAllOne_OptimalSpace(vector<vector<int>>& grid){
    int r = grid.size();
    int c = grid[0].size();
    int max_val = 0;
    vector<vector<int>> dp(2, vector<int>(c, 0));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            int entry = grid[i][j];
            if(entry && j)
                entry = 1 + min(dp[1][j-1], min(dp[0][j-1], dp[1][j]));
            dp[0][j] = dp[1][j];
            dp[1][j] = entry;
            max_val = max(max_val, entry);
        }
    for(int i=0; i<max_val; i++, cout << endl)
        for(int j=0; j<max_val; j++)
            cout << "1 ";
}

// Min Cost Path
int MinCostPath_Recursion(vector<vector<int>>& cost, int m, int n){// O(m * n^3)
    if(n < 0 || m < 0)
        return INT_MAX;
    else if(m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + min(MinCostPath_Recursion(cost, m-1, n-1), min(MinCostPath_Recursion(cost, m, n-1), MinCostPath_Recursion(cost, m-1, n)));
}
int MinCostPath_DPmemo(vector<vector<int>>& cost, int m, int n, vector<vector<int>>& dp){// O(m * n)
    if(n < 0 || m < 0)
        return INT_MAX;
    else if(n == 0 && m == 0)
        return cost[m][n];
    if(dp[m][n] != -1)
        return dp[m][n];
    dp[m][n] = cost[m][n] + min(MinCostPath_DPmemo(cost, m-1, n-1, dp), min(MinCostPath_DPmemo(cost, m-1, n, dp), MinCostPath_DPmemo(cost, m, n-1, dp)));
    return dp[m][n];
}
int MinCostPath_DPtable(vector<vector<int>>& cost, int m, int n){// O(m * n)
    int r = cost.size();
    int c = cost[0].size();
    vector<vector<int>> dp(r, vector<int>(c, INF));
    dp[0][0] = cost[0][0];
    for(int i=1; i<=m ; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    for(int j=1; j<=n; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + cost[i][j];
    return dp[m][n];
}
struct Cell{
    int x, y, cost;
};
class CellCompare{
public:
    bool operator()(Cell& a, Cell& b){
        return a.cost > b.cost;
    }
};
bool MinCostPath_Safe(int x, int y, int r, int c){
    return x >= 0 && x < r && y >= 0 && y < c;
}
int MinCostPath_Dijkstra(vector<vector<int>>& cost, int m, int n){// O(V + E * log V) [V = E = n * m]
    int r = cost.size();
    int c = cost[0].size();
    vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};
    int dir = dx.size();
    vector<vector<int>> dp(r, vector<int>(c, INF));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    priority_queue<Cell, vector<Cell>, CellCompare> pq;
    dp[0][0] = cost[0][0];
    pq.push({0, 0, cost[0][0]});
    while(!pq.empty()){
        Cell cell = pq.top();
        pq.pop();
        int x = cell.x;
        int y = cell.y;
        if(visited[x][y])
            continue;
        visited[x][y] = true;
        for(int i=0; i<dir; i++){
            int x_next = x + dx[i];
            int y_next = y + dy[i];
            if(MinCostPath_Safe(x_next, y_next, r, c) && !visited[x_next][y_next]){
                dp[x_next][y_next] = min(dp[x_next][y_next], dp[x][y] + cost[x_next][y_next]);
                pq.push({x_next, y_next, dp[x_next][y_next]});
            }
        }
    }
    return dp[m][n];
}

// Minimum number of jumps to reach end
int MinJumpToEnd_Recursion(vector<int>& arr, int l, int r){// O(n^n)
    if(r == l)
        return 0;
    if(arr[l] == 0)
        return INT_MAX;
    int min_jump = INT_MAX;
    for(int i=l+1; i<=r && i<= l + arr[l]; i++){
        int jump = MinJumpToEnd_Recursion(arr, i, r);
        if(jump != INT_MAX && min_jump > jump +1)
            min_jump = jump + 1;
    }
    return min_jump;
}
int MinJumpToEnd_DPmemo(vector<int>& arr, int l, int r, vector<int>& dp){// O(n^2)
    if(l == r)
        return 0;
    if(dp[l] != -1)
        return dp[l];
    int min_jump = INT_MAX -1;
    for(int i=arr[l]; i>=1; --i)
        if(l + i <= r)
            min_jump = min(min_jump, 1 + MinJumpToEnd_DPmemo(arr, l+i, r, dp));
    return dp[l] = min_jump;
}
int MinJumpToEnd_DPtable(vector<int>& arr){// O(n^2)
    int n = arr.size();
    vector<int> jump(n, INF);
    if(n == 0 || arr[0] == 0)
        return INF;
    jump[0] = 0;
    for(int i=1; i<n; i++){
        jump[i] = INF;
        for(int j=0; j<i; j++)
            if(i <= j + arr[j] && jump[j] != INF){
                jump[i] = min(jump[i], jump[j] + 1);
                break;
            }
    }
    return jump[n-1];
}
int MinJumpToEnd_Greedy(vector<int>& arr){// O(n)
    int n = arr.size();
    if(n <= 1)
        return 0;
    if(arr[0] >= n-1)// if first element guarantees 1 jump
        return 1;
    if(arr[0] == 0)// can't jump
        return -1;
    int max_reach = arr[0];
    int step = arr[0];
    int jump = 1;
    for(int i=1; i<n; i++){// possible jump distance
        if(i == n-1)// end point
            return jump;
        if(arr[i] >= n-1-i)// can reach end point from arr[i]
            return jump + 1;
        max_reach = max(max_reach, i+arr[i]);
        step--;
        if(step == 0){
            jump++;
            if(i >= max_reach)
                return -1;
            step = max_reach - i;
        }
    }
    return -1;
}

// Longest Common Substring
int LongestCommonSubstring_OptimalSpace(string s1, string s2){// O(m * n)
    int m = s1.length();
    int n = s2.length();
    int result = 0;
    int len[2][n];
    int cur_r = 0;
    for(int i=0; i<=m ; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                len[cur_r][j] = 0;
            else if(s1[i-1] == s2[j-1]){
                len[cur_r][j] = len[1-cur_r][j-1] + 1;
                result = max(result, len[cur_r][j]);
            }
            else
                len[cur_r][j] = 0;
        }
        cur_r = 1 - cur_r;
    }
    return result;
}
int LongestCommonSubstring_OptimalSpace2(string s1, string s2){// O(m * n)
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int result = 0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > result)
                    result = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
}
int LongestCommonSubstring_DP(string s1, string s2){// O(m * n)
    int m = s1.length();
    int n = s2.length();
    int suffix[m+1][n+1];
    int result = 0;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                suffix[i][j] = 0;
            else if(s1[i-1] == s2[j-1]){
                suffix[i][j] = suffix[i-1][j-1] + 1;
                result = max(result, suffix[i][j]);
            }
            else
                suffix[i][j] = 0;
        }
    }
    return result;
}
int LongestCommonSubstring_Recursion(string s1, string s2, int m, int n, int count){// O(2^max(m,n))
    if(m == 0 || n == 0)
        return count;
    if(s1[m-1] == s2[n-1])
        count = LongestCommonSubstring_Recursion(s1, s2, m-1, n-1, count+1);
    count = max(count, max(LongestCommonSubstring_Recursion(s1, s2, m, n-1, 0), LongestCommonSubstring_Recursion(s1, s2, m-1, n, 0)));
    return count;
}

// Count ways to reach the nth stair using step 1, 2 or 3
int WaysToReachStairEnd_Recursion(int n){// O(3^n)
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    else
        return WaysToReachStairEnd_Recursion(n-3) + WaysToReachStairEnd_Recursion(n-2) + WaysToReachStairEnd_Recursion(n-1);
}
int WaysToReachStairEnd_DP(int n){// O(n)
    int result[n+1];
    result[0] = 1;
    result[1] = 1;
    result[2] = 2;
    for(int i=3; i<=n; i++)
        result[i] = result[i-1] + result[i-2] + result[i-3];
    return result[n];
}
vector<vector<int>> Mult(const vector<vector<int>>& a, const vector<vector<int>>& b, int k){
    vector<vector<int>> c(k+1, vector<int>(k+1));
    for(int i=1; i<=k; i++)
        for(int j=1; j<=k; j++)
            for(int z=1; z<=k; z++)
                c[i][j] = c[i][j] + a[i][z] * b[z][j];
    return c;
}
vector<vector<int>> Power_2DMatrix(const vector<vector<int>>& matrix, int n, int k){
    if(n == 1)
        return matrix;
    if(n & 1)
        return Mult(matrix, Power_2DMatrix(matrix, n-1, k), k);
    else{
        vector<vector<int>> x = Power_2DMatrix(matrix, n>>1, k);
        return Mult(x, x, k);
    }
}
int WaysToReachStairEnd_MatrixExponentiation(int n){// O(log n)
    int k = 3;
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    int f1[k+1] = {};
    f1[1] = 1;
    f1[2] = 2;
    f1[3] = 4;
    vector<vector<int>> matrix(k+1, vector<int>(k+1));
    for(int i=1; i<=k; i++)
        for(int j=1; j<=k; j++){
            if(i < k){
                if(j == i+1)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
                continue;
            }
            matrix[i][j] = 1;
        }
    matrix = Power_2DMatrix(matrix, n-1, k);
    int sum = 0;
    for(int i=1; i<=k; i++)
        sum += matrix[1][i] * f1[i];
    return sum;
}
int WaysToReachStairEnd_FourVar(int n){// O(n)
    int a = 1, b = 2,  c = 4, d = 0;
    if(n == 0 || n == 1 || n == 2)
        return n;
    if(n == 3)
        return c;
    for(int i=4; i<=n; i++){
        d = c + b + a;
        a = b;
        b = c;
        c = d;
    }
    return d;
}
int WaysToReachStairEnd_DPmemo(int n, vector<int>& dp){// O(n)
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = WaysToReachStairEnd_DPmemo(n-3, dp) + WaysToReachStairEnd_DPmemo(n-2, dp) + WaysToReachStairEnd_DPmemo(n-1, dp);
}

// Count Unique Paths in Matrix
int CountUniquePath_Recursion(int m, int n){// O(2^n)
    if(m == 1 || n == 1)
        return 1;
    return CountUniquePath_Recursion(m-1, n) + CountUniquePath_Recursion(m, n-1);
}
int CountUniquePath_DPmemo(int m, int n, vector<vector<int>>& dp){// O(m * n)
    if(m == 1 || n == 1)
        return dp[m][n] = 1;
    if(dp[m][n] == 0)
        dp[m][n] = CountUniquePath_DPmemo(m-1, n, dp) + CountUniquePath_DPmemo(m, n-1, dp);
    return dp[m][n];
}
int CountUniquePath_DPtable(int m, int n){// O(m * n)
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
        dp[i][0] = 1;
    for(int i=0; i<n; i++)
        dp[0][i] = 1;
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
}
int CountUniquePath_DPOptimalspace(int m, int n){
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=1; j<n; j++)
            dp[j] += dp[j-1];
    return dp[n-1];
}
int CountUniquePath_Combinatorics(int m, int n){// O(max(m, n))
    int path = 1;
    for(int i=n; i<(m+n-1); i++){
        path *= i;
        path /= (i-n+1);
    }
    return path;
}

// Unique Paths in a Grid with Obstables
int UniquePathWithObstacle_Recursion(vector<vector<int>>& grid, int i, int j){// O(2^(m*n))
    int r = grid.size();
    int c = grid[0].size();
    if(i == r || j == c)
        return 0;
    if(grid[i][j] == 1)
        return 0;
    if(i == r-1 && j == c-1)
        return 1;
    return UniquePathWithObstacle_Recursion(grid, i+1, j) + UniquePathWithObstacle_Recursion(grid, i, j+1);
}
int UniquePathWithObstacle_DPmemo(vector<vector<int>>& grid, vector<vector<int>>& path, int i, int j){// O(m*n)
    int r = grid.size();
    int c = grid[0].size();
    if(i == r || j == c)
        return 0;
    if(grid[i][j] == 1)
        return 0;
    if(i == r-1 && j == c-1)
        return 1;
    if(path[i][j] != -1)
        return path[i][j];
    return path[i][j] = UniquePathWithObstacle_DPmemo(grid, path, i+1, j) + UniquePathWithObstacle_DPmemo(grid, path, i, j+1);
}
int UniquePathWithObstacle_DPtable(vector<vector<int>>& grid){// O(m * n)
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    if(grid[0][0] == 0)
        dp[0][0] = 1;
    for(int i=1; i<r; i++)
        if(grid[i][0] == 0)
            dp[i][0] = dp[i-1][0];
    for(int i=1; i<c; i++)
        if(grid[0][i] == 0)
            dp[0][i] = dp[0][i-1];
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++)
            if(grid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[r-1][c-1];
}
int UniquePathWithObstacle_DPOptimalSpace(vector<vector<int>>& grid){// O(m * n)
    int r = grid.size();
    int c = grid[0].size();
    if(grid[0][0])
        return 0;
    grid[0][0] = 1;
    for(int i=1; i<r; i++){
        if(grid[i][0] == 0)
            grid[i][0] = grid[i-1][0];
        else
            grid[i][0] = 0;
    }
    for(int i=1; i<c; i++){
        if(grid[0][i] == 0)
            grid[0][i] = grid[0][i-1];
        else
            grid[0][i] = 0;
    }
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++){
            if(grid[i][j] == 0)
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            else
                grid[i][j] = 0;
        }
    return grid[r-1][c-1];
}

// 0/1 Knapsack Problem
int Knapsack_Recursion(int cap, vector<int>& weight, vector<int>& profit, int n){// O(2^n)
    if(n == 0 || cap == 0)
        return 0;
    if(weight[n-1] > cap)
        return Knapsack_Recursion(cap, weight, profit, n-1);
    return max(profit[n-1] + Knapsack_Recursion(cap-weight[n-1], weight, profit, n-1), Knapsack_Recursion(cap, weight, profit, n-1));
}
int Knapsack_DPmemo(int cap, vector<int>& weight, vector<int>& profit, int n, vector<vector<int>>& dp){// O(n * cap)
    if(n < 0)
        return 0;
    if(dp[n][cap] != -1)
        return dp[n][cap];
    if(weight[n] > cap){
        dp[n][cap] = Knapsack_DPmemo(cap, weight, profit, n-1, dp);
        return dp[n][cap];
    }
    return dp[n][cap] = max(profit[n] + Knapsack_DPmemo(cap-weight[n], weight, profit, n-1, dp), Knapsack_DPmemo(cap, weight, profit, n-1, dp));
}
int Knapsack_DPtable(int cap, vector<int>& weight, vector<int>& profit, int n){// O(n * cap)
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=0; i<=n ; i++){
        for(int j=0; j<=cap; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weight[i-1] <= j)
                dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> max_weight;
    int result = dp[n][cap];
    int w = cap;
    for(int i=n; i>0 && result > 0; i--){
        if(result == dp[i-1][w])
            continue;
        else{
            max_weight.push_back(weight[i-1]);
            result -= profit[i-1];
            w -= weight[i-1];
        }
    }
    for(auto t : max_weight)
        cout << t << " ";
    cout << endl;
    return dp[n][cap];
}
int Knapsack_DPOptimalSpace(int cap, vector<int>& weight, vector<int>& profit, int n){
    vector<int> dp(cap+1, 0);
    for(int i=1; i<=n; i++)
        for(int j=cap; j>=0; j--)
            if(weight[i-1] <= j)
                dp[j] = max(dp[j], dp[j-weight[i-1]]+profit[i-1]);
    return dp[cap];
}

// Unbounded Knapsack
int UnboundedKnapsack_Recursion(int cap, vector<int>& weight, vector<int>& profit, int n){// O(cap * n)
    if(n == 0)
        return cap/weight[0]*profit[0];
    int notTake = 0 + UnboundedKnapsack_Recursion(cap, weight, profit, n-1);
    int take = INT_MIN;
    if(weight[n] <= cap)
        take = profit[n] + UnboundedKnapsack_Recursion(cap-weight[n], weight, profit, n);
    return max(take, notTake);
}
int UnboundedKnapsack_DPmemo(int cap, vector<int>& weight, vector<int>& profit, int n, vector<vector<int>>& dp){// O(cap * n)
    if(n == 0)
        return cap/weight[0]*profit[0];
    if(dp[n][cap] != -1)
        return dp[n][cap];
    int notTake = 0 + UnboundedKnapsack_DPmemo(cap, weight, profit, n-1, dp);
    int take = INT_MIN;
    if(weight[n] <= cap)
        take = profit[n] + UnboundedKnapsack_DPmemo(cap-weight[n], weight, profit, n, dp);
    return dp[n][cap] = max(take, notTake);
}
int UnboundedKnapsack_DPOptimalSpace(int cap, vector<int>& weight, vector<int>& profit, int n){// O(cap * n)
    vector<int> dp(cap+1, 0);
    for(int i=0; i<=cap; i++)
        for(int j=0; j<n; j++)
            if(weight[j] <= i)
                dp[i] = max(dp[i], dp[i-weight[j]]+profit[j]);
    return dp[cap];
}

// Egg Dropping Puzzle
int EggDrop_Recursion(int n, int k){
    if(k == 1 || k == 0)
        return k;
    if(n == 1)
        return k;
    int min_val = INT_MAX, result;
    for(int i=1; i<=k; i++){
        result = max(EggDrop_Recursion(n-1, i-1), EggDrop_Recursion(n, k-i));
        if(result < min_val)
            min_val = result;
    }
    return min_val + 1;
}
int EggDrop_DPtable(int n, int k){// O(n * k^2)
    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
    int result;
    for(int i=1; i<=n ; i++){
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for(int i=1; i<=k; i++)
        dp[1][i] = i;
    for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            for(int x=1; x<=j; x++){
                result = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                if(result < dp[i][j])
                    dp[i][j] = result;
            }
        }
    }
    return dp[n][k];
}
int EggDrop_DPmemo(int n, int k, vector<vector<int>>& dp){// O(n * k^2)
    if(dp[n][k] != -1)
        return dp[n][k];
    if(k == 1 || k == 0)
        return k;
    if (n == 1)
        return k;
    int min_val = INT_MAX, result;
    for(int i=1; i<=k; i++){
        result = max(EggDrop_DPmemo(n-1, i-1, dp), EggDrop_DPmemo(n, k-i, dp));
        if(result < min_val)
            min_val = result;
    }
    return dp[n][k] = min_val + 1;
}
int EggDrop_DPOptimal(int n, int k){// O(n * k)
    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
    int m = 0;// num of move
    while(dp[m][n] < k){
        m++;
        for(int i=1; i<=n; i++)
            dp[m][i] = 1 + dp[m-1][i-1] + dp[m-1][i];
    }
    return m;
}
int EggDrop_DPOptimalSpace(int n, int k){// O(n * log k)
    vector<int> dp(n+1, 0);
    int i;
    for(i=0; dp[n] < k ; i++)
        for(int j=n; j>0; j--)
            dp[j] += 1 + dp[j-1];
    for(auto t : dp)
        cout << t << " ";
    return i;
}

// Word Break Problem
bool WordBreak_RecursionPrefix(const vector<string>& dic, const string& str){// O(2^n)
    if(str.empty())
        return true;
    int len = str.length();
    for(int i=1; i<=len; i++){
        string prefix = str.substr(0, i);
        if(find(dic.begin(), dic.end(), prefix) != dic.end() && WordBreak_RecursionPrefix(dic, str.substr(i)))
            return true;
    }
    return false;
}
bool CheckWordInDictionary(const string& str){
    vector<string> dic = {
        "mobile", "samsung", "sam", "sung", "man", "mango",
        "icecream", "and", "go", "i", "like", "ice", "cream",
        "love"
    };
    int size = dic.size();
    for(int i=0; i<size; i++)
        if(dic[i].compare(str) == 0)
            return true;
    return false;
}
bool WordBreak_RecursionSuffixPrefix(const string& str){// O(2^n)
    int size = str.size();
    if(size == 0)
        return true;
    for(int i=1; i<=size; i++){
        if(CheckWordInDictionary(str.substr(0, i)) && WordBreak_RecursionSuffixPrefix(str.substr(i, size-i)))
            return true;
    }
    return false;
}
bool WordBreak_DPtable(const string& str){// O(n^3)
    int size = str.size();
    if(size == 0)
        return true;
    vector<bool> dp(size+1, false);
    for(int i=1; i<=size; i++){
        if(dp[i] == false && CheckWordInDictionary(str.substr(0, i)))
            dp[i] = true;
        if(dp[i] == true){
            if(i == size)
                return true;
            for(int j=i+1; j<=size; j++){
                if(dp[j] == false && CheckWordInDictionary(str.substr(i, j-i)))
                    dp[j] = true;
                if(j==size && dp[j] == true)
                    return true;
            }
        }
    }
    return false;
}
bool WordBreak_DPOptimal(const string& str){// O(n^2) [n>s] or O(n*s) [s>n], [s = length of longest word in dic, n = length of input string]
    int n = str.size();
    if(n == 0)
        return true;
    vector<bool> dp(n+1, 0);
    vector<int> matched_idx;
    matched_idx.push_back(-1);
    for(int i=0; i<n; i++){
        int size_m = matched_idx.size();
        bool f = false;
        for(int j=size_m-1; j>=0; j--){
            string sub = str.substr(matched_idx[j]+1, i-matched_idx[j]);
            if(CheckWordInDictionary(sub)){
                f = true;
                break;
            }
        }
        if(f == true){
            dp[i] = 1;
            matched_idx.push_back(i);
        }
    }
    return dp[n-1];
}
bool WordBreak_HashMap(unordered_map<string, bool>& mp, const string& str){// O(2^n)
    int size = str.size();
    if(size == 0)
        return true;
    string temp = "";
    for(int i=0; i<size; i++){
        temp += str[i];
        if(mp.find(temp) != mp.end() && WordBreak_HashMap(mp, str.substr(i+1)))
            return true;
    }
    return false;
}
struct TrieNode{
    TrieNode* child[ALPHABET];
    bool isEnd;
};
TrieNode* GetTrieNode(){
    TrieNode* node = new TrieNode;
    node->isEnd = false;
    for(int i=0; i<ALPHABET; i++)
        node->child[i] = NULL;
    return node;
}
void Insert_Trie(TrieNode* root, string key){
    TrieNode* node = root;
    for(int i=0; i<key.length(); i++){
        int word = key[i] - 'a';
        if(!node->child[word])
            node->child[word] = GetTrieNode();
        node = node->child[word];
    }
    node->isEnd = true;
}
bool Search_Trie(TrieNode* root, string key){
    TrieNode* node = root;
    for(int i=0; i<key.length(); i++){
        int word = key[i] - 'a';
        if(!node->child[word])
            return false;
        node = node->child[word];
    }
    return node != NULL && node->isEnd;
}
bool WordBreak_Trie(const string& str, TrieNode* root){// O(m * n) [m: length of longest word in dic, n: length of input string]
    int size = str.size();
    if(size == 0)
        return true;
    for(int i=1; i<=size; i++)
        if(Search_Trie(root, str.substr(0, i)) && WordBreak_Trie(str.substr(i, size-i), root))
            return true;
    return false;
}
void WordBreak_Print_Backtracking(string str, int n, string result){// O(2^n)
    for(int i=1; i<=n; i++){
        string prefix = str.substr(0, i);
        if(CheckWordInDictionary(prefix)){
            if(i == n){
                result += prefix;
                cout << result << endl;
                return;
            }
            WordBreak_Print_Backtracking(str.substr(i,n-i), n-i, result + prefix + " ");
        }
    }
}

// Vertex Cover Problem
struct Node{
    int data;
    int vc;
    Node *left, *right;
};
Node* NewNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->vc = 0;
    new_node->left = new_node->right = nullptr;
    return new_node;
}
int VertexCoverBinaryTree_Recursion(Node* root){
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 0;
    int included = 1 + VertexCoverBinaryTree_Recursion(root->left) + VertexCoverBinaryTree_Recursion(root->right);
    int excluded = 0;
    if(root->left)
        excluded += 1 + VertexCoverBinaryTree_Recursion(root->left->left) + VertexCoverBinaryTree_Recursion(root->left->right);
    if(root->right)
        excluded += 1 + VertexCoverBinaryTree_Recursion(root->right->left) + VertexCoverBinaryTree_Recursion(root->right->right);
    return min(included, excluded);
}
int VertexCoverBinaryTree_DPtable(Node* root){// O(n)
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return 0;
    int included = 1 + VertexCoverBinaryTree_DPtable(root->left) + VertexCoverBinaryTree_DPtable(root->right);
    int excluded = 0;
    if(root->left)
        excluded += 1 + VertexCoverBinaryTree_DPtable(root->left->left) + VertexCoverBinaryTree_DPtable(root->left->right);
    if(root->right)
        excluded += 1 + VertexCoverBinaryTree_DPtable(root->right->left) + VertexCoverBinaryTree_DPtable(root->right->right);
    return min(included, excluded);
}
void AddEdge(vector<int> adj[], int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void TreeDFS(vector<int> adj[], vector<int> dp[], int src, int par){
    for(auto child : adj[src])
        if(child != par)
            TreeDFS(adj, dp, child, src);
    for(auto child : adj[src])
        if(child != par){
            dp[src][0] += dp[child][1];// Excluded
            dp[src][1] += min(dp[child][1], dp[child][0]);// Included
        }
}
void VertexCoverNormalTree_DPtable(vector<int> adj[], int n){
    vector<int> dp[n+1];
    for(int i=1; i<=n; i++){
        dp[i].push_back(0);// Excluded
        dp[i].push_back(1);// Included
    }
    TreeDFS(adj, dp, 1, -1);
    cout << min(dp[1][0], dp[1][1]) << endl;
}

// Tile Stacking Problem
int TileStacking_DPtable(int n, int m, int k){// O(m * n)
    //n: height, m: species of tile, k: max number of tile that we can use
    //dp[i][j] ==> i: kind of tile, j: height, dp = number of stacking method
    //sum[i][j] ==> sum of dp[i][0]~dp[i][j]
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++)//no tile
        sum[0][i] = 1;
    for(int i=0; i<=m; i++)//not stacking
        sum[i][0] = 1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = sum[i-1][j];
            if(j > k)
                dp[i][j] -= sum[i-1][j-k-1];
        }
        for(int j=1; j<=n; j++)
            sum[i][j] = dp[i][j] + sum[i][j-1];// 1+dp[i][1~n]
    }
    return dp[m][n];
}

// Box Stacking Problem
struct Box{
    int h, w, d;
};
int CompareBox(const void* a, const void* b){
    return (*(Box *)b).d * (*(Box *)b).w - (*(Box *)a).d * (*(Box *)a).w;
}
int BoxStacking_DPtable(Box arr[], int n){// O(n^2)
    Box dp[3*n];
    int idx = 0;
    for(int i=0; i<n; i++){
        dp[idx].h = arr[i].h;
        dp[idx].d = max(arr[i].d, arr[i].w);
        dp[idx].w = min(arr[i].d, arr[i].w);
        idx++;
        dp[idx].h = arr[i].w;
        dp[idx].d = max(arr[i].h, arr[i].d);
        dp[idx].w = min(arr[i].h, arr[i].d);
        idx++;
        dp[idx].h = arr[i].d;
        dp[idx].d = max(arr[i].h, arr[i].w);
        dp[idx].w = min(arr[i].h, arr[i].w);
        idx++;
    }
    n = 3 * n;
    qsort(dp, n, sizeof(dp[0]), CompareBox);// Dec order
    int max_h[n];//store only height
    for(int i=0; i<n; i++)
        max_h[i] = dp[i].h;// copy
    for(int i=1; i<n; i++)// i: top box's index(check if cur box can be put over bigger box)
        for(int j=0; j<i; j++)// j: bigger size box's index
            if(dp[i].w < dp[j].w && dp[i].d < dp[j].d && max_h[i] < max_h[j] + dp[i].h)
                max_h[i] = max_h[j] + dp[i].h;// if cur box place on top of bigger box, update max height
    int max_val = -1;
    for(int i=0; i<n; i++)
        if(max_val < max_h[i])
            max_val = max_h[i];
    return max_val;
}
int FindMaxHeight_BoxStacking(vector<Box>& boxes, int bottom, int idx, vector<int>& dp){
    if(idx < 0)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    int max_h = 0;
    for(int i=idx; i>=0; i--)
        if(bottom == -1 || boxes[i].d < boxes[bottom].d && boxes[i].w < boxes[bottom].w)
            max_h = max(max_h, FindMaxHeight_BoxStacking(boxes, i, i-1, dp)+boxes[i].h);
    return dp[idx] = max_h;
}
int BoxStacking_DPmemo(vector<int>& height, vector<int>& width, vector<int>& length, int n){// O(n^2)
    vector<Box> boxes;
    vector<int> dp(3*n+1, -1);
    Box box;
    for(int i=0; i<n; i++){
        box.h = height[i];
        box.d = max(length[i], width[i]);
        box.w = min(length[i], width[i]);
        boxes.push_back(box);
        box.h = width[i];
        box.d = max(length[i], height[i]);
        box.w = min(length[i], height[i]);
        boxes.push_back(box);
        box.h = length[i];
        box.d = max(height[i], width[i]);
        box.w = min(height[i], width[i]);
        boxes.push_back(box);
    }
    sort(boxes.begin(), boxes.end(), [](Box b1, Box b2){
        return (b1.d * b1.w) < (b2.d * b2.w);//Ascending order
    });
    return FindMaxHeight_BoxStacking(boxes, -1, boxes.size()-1, dp);
}

// Partition Problem
bool IsEqualSumOfSubset_Recursion(vector<int>& arr, int n, int sum){
    if(sum == 0)
        return true;
    if(n == 0 && sum != 0)
        return false;
    if(arr[n-1] > sum)// Ignore last element
        return IsEqualSumOfSubset_Recursion(arr, n-1, sum);
    return IsEqualSumOfSubset_Recursion(arr, n-1, sum) || IsEqualSumOfSubset_Recursion(arr, n-1, sum-arr[n-1]);
}
bool FindPartition_Recursion(vector<int>& arr, int n){
    int sum = 0;
    for(auto k : arr)
        sum += k;
    if(sum & 1)
        return false;
    return IsEqualSumOfSubset_Recursion(arr, n, sum/2);
}
bool IsEqualSumOfSubset_DPmemo(vector<int>& arr, int n, int sum, vector<vector<int>>& dp){
    if(sum == 0)
        return true;
    if(n == 0 && sum != 0)
        return false;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    if(arr[n-1] > sum)// Ignore last element
        return IsEqualSumOfSubset_DPmemo(arr, n-1, sum, dp);
    return dp[n][sum] = IsEqualSumOfSubset_DPmemo(arr, n-1, sum, dp) || IsEqualSumOfSubset_DPmemo(arr, n-1, sum-arr[n-1], dp);
}
bool FindPartition_DPmemo(vector<int>& arr, int n){
    int sum = 0;
    for(auto k : arr)
        sum += k;
    if(sum & 1)
        return false;
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    return IsEqualSumOfSubset_DPmemo(arr, n, sum/2, dp);
}
bool FindPartition_DPtable(vector<int>& arr, int n){
    int sum = 0;
    for(auto k : arr)
        sum += k;
    if(sum & 1)
        return false;
    vector<vector<bool>> dp((sum/2)+1, vector<bool>(n+1, false));
    for(int i=0; i<=n; i++)// sum == 0
        dp[0][i] = true;
    for(int i=1; i<= sum>>1; i++)// sum != 0 && n == 0
        dp[i][0] = false;
    for(int i=1; i<=sum>>1 ; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(i >= arr[j-1])
                dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
        }
    }
    return dp[sum>>1][n];
}
bool FindPartition_DPOptimalSpace(vector<int>& arr, int n){
    int sum = 0;
    for(auto k : arr)
        sum += k;
    if(sum & 1)
        return false;
    vector<bool> dp((sum>>1)+1, false);
    for(int i=0; i<n ; i++)
        for(int j=(sum>>1); j>=arr[i]; j--)
            if(dp[j-arr[i]] == true || j == arr[i])
                dp[j] = true;
    return dp[sum>>1];
}

// Longest Palindromic Subsequence(LPS)
int LongestPalindromicSubsequence_Recursion(string& str, int i, int j){// O(2^n)
    if(i == j)// one char
        return 1;
    if(str[i] == str[j] && i+1 == j)//only 2 char
        return 2;
    if(str[i] == str[j])
        return LongestPalindromicSubsequence_Recursion(str, i+1, j-1)+2;
    return max(LongestPalindromicSubsequence_Recursion(str, i, j-1), LongestPalindromicSubsequence_Recursion(str, i+1, j));
}
int LongestPalindromicSubsequence_DPmemo(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    if(i == 0 || j == 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s1[i-1] == s2[j-1])
        return dp[i][j] = 1 + LongestPalindromicSubsequence_DPmemo(s1, s2, i-1, j-1, dp);
    return dp[i][j] = max(LongestPalindromicSubsequence_DPmemo(s1, s2, i-1, j, dp), LongestPalindromicSubsequence_DPmemo(s1, s2, i, j-1, dp));
}
int LongestPalindromicSubsequence_DPtable(string& s){// O(n^2)
    int n = s.length();
    string s2 = s;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

// Longest Common Increasing Subsequence(LCS + LIS)
int LongestCommonIncSubsequence_DP(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int longlength_arr = n > m ? n : m;
    int shortlengt_arr = n > m ? m : n;
    vector<int> dp(longlength_arr, 0);
    for(int i=0; i<shortlengt_arr; i++){
        int curlength = 0;
        for(int j=0; j<longlength_arr; j++){
            if(arr1[i] == arr2[j] && curlength+1 > dp[j])// cur+1 > dp[i] ==> length of LCIS is not updated yet
                dp[j] = curlength + 1;
            if(arr1[i] > arr2[j] && dp[j] > curlength)// because subsequence is increasing , certainly updated dp's value(>0) is exist
                curlength = dp[j];
        }
    }
    int result = 0;
    for(int i=0; i<longlength_arr; i++)
        if(dp[i] > result)
            result = dp[i];
    return result;
}

// Find All Distinct Subset Sum of Array
void DistinctSubsetSum_Naive(vector<int>& arr, int sum, int cur_idx, set<int>& s){
    int n = arr.size();
    if(cur_idx > n)
        return;
    if(cur_idx == n){
        s.insert(sum);
        return;
    }
    DistinctSubsetSum_Naive(arr, sum + arr[cur_idx], cur_idx+1, s);
    DistinctSubsetSum_Naive(arr, sum, cur_idx+1, s);
}
void DistinctSubsetSum_DPtable(vector<int>& arr){// O(n * sum)
    int n = arr.size();
    int sum = 0;
    for(auto k : arr)
        sum += k;
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for(int i=0; i<=n; i++)// Sum is 0
        dp[i][0] = true;
    for(int i=1; i<=n ; i++){
        dp[i][arr[i-1]] = true;//element is only 1
        for(int j=1; j<=sum; j++){
            if(dp[i-1][j] == true){// if already subset's sum is calculated,
                dp[i][j] = true;// true if sum is the same even as the num of elements increases
                dp[i][j+arr[i-1]] = true;// and, true even if previous element is added to sum
            }
        }
    }
    for(int i=0; i<=sum; i++)
        if(dp[n][i] == true)
            cout << i << " ";
}
void DistinctSubsetSum_DPBitSet(vector<int>& arr){// O(n * s / w) [s: sum of array element, w: word size of system(32bit/64bit)]
    int n = arr.size();
    const int max_bit = 40;
    bitset<max_bit> dp;
    dp[0] = 1;// integer 0
    for(int i=0; i<n; i++)
        dp |= dp << arr[i];
    for(int i=0; i<max_bit ; i++)
        if(dp[i] == 1)
            cout << i << " ";
}

// Weighted Job Scheduling
struct Jobs{
    int start, end, profit;
};
bool CompareJobsEnd(Jobs s1, Jobs s2){
    return s1.end < s2.end;
}
int GetIndexOfNotConflictJob(vector<Jobs>& arr, int i){
    for(int j=i-1; j>=0 ; j--)
        if(arr[j].end <= arr[i-1].start)
            return j;
    return -1;
}
int GetMaxProfitJobs_Recursion(vector<Jobs>& arr, int n){
    if(n == 1)
        return arr[n-1].profit;
    int included = arr[n-1].profit;
    int i = GetIndexOfNotConflictJob(arr, n);
    if(i != -1)
        included += GetMaxProfitJobs_Recursion(arr, i+1);
    int excluded = GetMaxProfitJobs_Recursion(arr, n-1);
    return max(included, excluded);
}
int GetMaxProfitJobs_DPtable(vector<Jobs>& arr){// O(n^2)
    sort(arr.begin(), arr.end(), CompareJobsEnd);
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0].profit;
    for(int i=1; i<n; i++){
        int included = arr[i].profit;
        int l = GetIndexOfNotConflictJob(arr, i);
        if(l != -1)
            included += dp[l];
        dp[i] = max(included, dp[i-1]);
    }
    return dp[n-1];
}
int Jobs_BinarySearch(vector<Jobs>& arr, int i){
    // end is ordered in ascending
    // So, always arr[mid].end < arr[mid+1].end is true
    int l = 0, h = i-1;
    while(l <= h){
        int mid = (l+h)>>1;
        if(arr[mid].end <= arr[i].start){
            if(arr[mid+1].end <= arr[i].start)
                l = mid + 1;
            else
                return mid;
        }
        else
            h = mid - 1;
    }
    return -1;
}
int GetMaxProfitJobs_DPBinarySearch(vector<Jobs>& arr){// O(n log n)
    sort(arr.begin(), arr.end(), CompareJobsEnd);
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0].profit;
    for(int i=1; i<n; i++){
        int included = arr[i].profit;
        int l = Jobs_BinarySearch(arr, i);
        if(l != -1)
            included += dp[l];
        dp[i] = max(included, dp[i-1]);
    }
    return dp[n-1];
}

// Count Derangements
int CountDerangement_Recursion(int n){// O(2^n)
    if(n == 1 || n == 2)
        return n-1;
    return (n-1) * (CountDerangement_Recursion(n-1) + CountDerangement_Recursion(n-2));
}
int CountDerangement_DPtable(int n){// O(n)
    vector<int> dp(n+1, 0);
    dp[1] = 0, dp[2] = 1;
    for(int i=3; i<=n; i++)
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    return dp[n];
}
int CountDerangement_DPOptimalSpace(int n){// O(n)
    if(n == 1 || n == 2)
        return n-1;
    int a = 0, b = 1;
    for(int i=3; i<=n; i++){
        int cur = (i-1) * (a + b);
        a = b;
        b = cur;
    }
    return b;
}

// Minimum Insertion to Form a Palindrome
int CountMinInsertionForPalindrome_Recursion(string& str, int l, int r){// O(2^n)
    if(l > r)// not found
        return INT_MAX;
    if(l == r)// 1 char
        return 0;
    if(l == r-1)// 2 char
        return str[l] == str[r] ? 0 : 1;
    return str[l] == str[r] ? CountMinInsertionForPalindrome_Recursion(str, l+1, r-1):
                              min(CountMinInsertionForPalindrome_Recursion(str, l, r-1),
                              CountMinInsertionForPalindrome_Recursion(str, l+1, r))+1;
}
int CountMinInsertionForPalindrome_DPtable(string& str){// O(n^2)
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int gap=1; gap<n; ++gap)
        for(int l=0, r=gap; r<n; ++l, ++r)
            dp[l][r] = str[l] == str[r] ? dp[l+1][r+1] : min(dp[l][r-1], dp[l+1][r])+1;
    return dp[0][n-1];
}
int CountMinInsertionForPalindrome_LCS(string& str){// O(n^2)
    int n = str.size();
    string str2 = str;
    reverse(str2.begin(), str2.end());
    return (n-LCS_DPtable(str, str2, n, n));
}
int CountMinInsertionForPalindrome_LCSOptimalSpcae(string& str){// O(n^2)
    int n = str.size();
    string str2 = str;
    reverse(str2.begin(), str2.end());
    return (n-LCS_DPOptimalspace(str, str2));
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// ----------------------------- Pattern Search ---------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Naive Pattern Search
void NaivePatternSearch(string& s1, string& p1, vector<int>& result){// O(n^2)
    int n = s1.size();
    int m = p1.size();
    for(int i=0; i<n-m; i++){
        int j;
        for(j=0; j<m; j++)
            if(s1[i+j] != p1[j])
                break;
        if(j == m)
            result.push_back(i);
    }
}

// Rabin-Karp Pattern Search
void RabinKarpPatternSearch(string& s1, string& p1, int p, vector<int>& result){// O(n*m)
    // init hash = s1[i] * base^(m-1-i) % p ==> s1[i] * base^(i) (i= 0, 1, 2, ...);
    // hash = (hash-(s1[i-m] * base^(m-1))%p) * base + s1[i];
    int n = s1.size();
    int m = p1.size();
    int hash_s1 = 0;
    int hash_p1 = 0;
    int base = 256;
    int power = 1;
    // Pre-calculation of Hash
    for(int i=0; i<m-1; i++)
        power = (power * base) % p;// base^(m-1) % p
    for(int i=0; i<m; i++){
        // Normally, hash += s1[i] * base^(i) (i= 0, 1, 2, ...);
        // hash_p1 += p1[i] * pow(base , i);
        // hash_s1 += s1[i] * pow(base, i);
        // hash_p1 %= p; // prevent overflow
        // hash_s1 %= p; // prevent overflow
        // OR
        hash_p1 =(hash_p1 * base + p1[i])% p;
        hash_s1 =(hash_s1 * base + s1[i])% p;
    }
    for(int i=0; i<=n-m ; i++){
        int j;
        if(hash_p1 == hash_s1){// smae hash value
            for(j=0; j<m; j++)
                if(s1[i+j] != p1[j])// check if same char
                    break;
            if(j == m)
                result.push_back(i);
        }
        if(i <n-m){// if string's index increases, update hash value including (i+m) index and excluding current index
            hash_s1 = (base * (hash_s1 - s1[i] * power) + s1[i+m]) % p;
            if(hash_s1 < 0)
                hash_s1 = hash_s1 + p;
        }
    }
}

// Longest Prefix Suffix
int LongestPrefixSuffix(string s){
    int size = s.size();
    vector<int> arr(size, 0);
    int i = 1, j = 0;
    while(i<size){
        if(s[i] == s[j])
            arr[i++] = ++j;
        else{
            if(j == 0)
                i++;
            else
                j = arr[j-1];
        }
    }
    return arr[size-1];
}

// KMP(Knuth Morris Pratt) Pattern Search
void LongestPrefixSuffix(string& p1, vector<int>& lps){// O(n)
    int count = 0, i = 1;
    int m = p1.size();
    lps[0] = 0;
    while(i < m){
        if(p1[i] == p1[count])
            lps[i++] = ++count;// suffix's preffix
        else{// p1[i] != p1[len]
            if(count != 0)//Find start point(matching point)
                count = lps[count-1];//Find matching char from max length of suffix to 0
            else// if len == 0
                lps[i++] = 0;
        }
    }
}
void KMPPatternSearch(string& s1, string& p1, vector<int>& result){// O(n + m)
    int n = s1.size();
    int m = p1.size();
    vector<int> lps(m, 0);
    int i=0, j=0;
    LongestPrefixSuffix(p1, lps);
    while((n-i) >= (m-j)){
        if(p1[j] == s1[i])
            i++, j++;
        if(j == m){
            result.push_back(i-j);
            j = lps[j-1];
        }
        else if(i < n && p1[j] != s1[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

// Z Pattern Search(Longest Common Prefix)
void GetZArray(string& str, vector<int>& Z){
    int n = str.size();
    int L = 0, R = 0, k;
    for(int i=1; i<n; i++){
        if(i > R){// Not match & not included range [L, R]
            L = R = i;// Init L, R to current index
            while(R < n && str[R-L] == str[R])// Compare str[i]~ with pattern(from start to end) 
                R++;
            Z[i] = R - L;//matched substring(prefix) length
            R--;// Matched substring's last index
        }
        else{// L <= i <= R
            k = i - L;// k means patter's index (L<= k <= R)
            if(Z[k] < R-i+1)// no prefix substring/ substring length from index i to index R
                Z[i] = Z[k];// get pattern's Z value
            else{// Z[k] >= R-i+1
                L = i;
                while(R < n && str[R-L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}
vector<int> GetZArray2(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r)
            z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void ZPatternSearch(string& s1, string& p1, vector<int>& result){// O(n + m)
    string concat = p1 + "$" + s1;
    int size_concat = concat.size();
    vector<int> Z(size_concat, 0);
    GetZArray(concat, Z);
    for(int i=0; i<size_concat; i++)
        if(Z[i] == p1.size())
            result.push_back(i-p1.size()-1);
}

// Boyer Moore Pattern Search
void BadCharHeuristic(string& p1, int m, vector<int>& bad){
    for(int i=0; i<m; i++)// char of pattern's last occurence position
        bad[p1[i]] = i;
}
void BoyerMoorePatternSearch(string& s1, string& p1, vector<int>& result){// O(n * m)
    int n = s1.size();
    int m = p1.size();
    vector<int> bad(CHAR_SIZE, -1);// key: char, value: index
    BadCharHeuristic(p1, m, bad);
    int shift =0 ;
    while(shift <= (n-m)){
        int j = m-1;// pattern's last word
        while(j >= 0 && p1[j] == s1[shift+j])
            j--;
        if(j < 0){// Found pattern
            result.push_back(shift);
            shift += (shift+m < n) ? m - bad[s1[shift+m]] : 1;
        }
        else
            shift += max(1, j-bad[s1[shift+j]]);// max is used for avoiding negative value
    }
}

// C++ Library Pattern Search
void STLPatternSearch(string& s1, string& p1, vector<int>& result){
    int found = s1.find(p1);
    while(found != string::npos){
        result.push_back(found);
        found = s1.find(p1, found+1);
    }
}

// Aho-Corasick Pattern Search
int MatchingMachine(vector<string>& p1, int m, vector<vector<int>>& g, vector<int>& f, vector<int>& out){
    int state = 1;
    for(int i=0; i<m; i++){
        string word = p1[i];// get ith pattern
        int cur_state = 0;// it means node number for understanding
        for(int j=0; j<word.length(); j++){// in i th pattern
            int ch = word[j] - 'a';
            if(g[cur_state][ch] == -1)
                g[cur_state][ch] = state++;// store next state(next node)
            cur_state = g[cur_state][ch];// move next state(next node)
        }
        out[cur_state] |= (1 << i);// it means that pattern[i] is located at index cur_state 
    }
    for(int i=0; i<ALPHABET; i++)// it indicates word not included in pattern
        if(g[0][i] == -1)
            g[0][i] = 0;// next node of word not included in pattern is 0(root)
    queue<int> q;// have next node
    for(int i=0; i<ALPHABET; i++)
        if(g[0][i] != 0){//if word is included in Pattern
            f[g[0][i]] = 0; //if mismatching occurs, go to root(find index having Longest Prefix)
            q.push(g[0][i]);
        }
    while(!q.empty()){//BFS
        int next = q.front();
        q.pop();
        for(int i=0; i<ALPHABET; i++){
            if(g[next][i] != -1){// if next node connects next next node
                int fail = f[next];
                while(g[fail][i] == -1)
                    fail = f[fail];
                fail = g[fail][i];// Find index having Longest prefix
                f[g[next][i]] = fail;// failure function update
                out[g[next][i]] |= out[fail];
                q.push(g[next][i]);
            }
        }
    }
    return state;
}
void AhoCorasickPatternSearch(vector<string>& p1, string& s1, vector<pair<string, pair<int, int>>>& result){
    int m = p1.size();
    int totalLength_p1 = 0;
    for(auto k : p1)
        totalLength_p1 += k.length();
    int n = s1.size();
    vector<vector<int>> g(totalLength_p1+1, vector<int>(ALPHABET+1, -1));
    vector<int> f(totalLength_p1+1, -1);
    vector<int> out(totalLength_p1+1, 0);
    MatchingMachine(p1, m, g, f, out);
    int cur_state = 0;
    for(int i=0; i<n; i++){
        int ch = s1[i]-'a';
        while(g[cur_state][ch] == -1)// if word isn't exist in input string
            cur_state = f[cur_state];// find LP
        cur_state = g[cur_state][ch];// move next node
        if(out[cur_state] == 0)//if match not found, move next word in input string
            continue;
        for(int j=0; j<m; j++)
            if(out[cur_state] & (1 << j))
                //result.push_back(make_pair(p1[j], make_pair(i-p1[j].length()+1, i)));
                result.push_back({p1[j], make_pair(i-p1[j].length()+1, i)});
    }
}

// Anagram Substring Pattern Search
void AnagramSubstringPatternSearch_Brute(string& s1, string& p1, vector<int>& result){
    int m = p1.size();
    int n = s1.size();
    string sorted_p1 = p1;
    sort(sorted_p1.begin(), sorted_p1.end());
    string temp;
    for(int i=0; i<=n-m; i++){
        temp = "";
        for(int j=i; j<m+i; j++)
            temp.push_back(s1[j]);
        sort(temp.begin(), temp.end());
        if(sorted_p1 == temp)
            result.push_back(i);
    }
}
bool Compare_string(vector<char>& count_s1, vector<char>& count_p1){
    for(int i=0; i<CHAR_SIZE; i++)
        if(count_s1[i] != count_p1[i])
            return false;
    return true;
}
void AnagramSubstringPatternSearch_RabinKarp(string& s1, string& p1, vector<int>& result){// O(m * n)
    int m = p1.size();
    int n = s1.size();
    vector<char> count_p1(CHAR_SIZE, 0);
    vector<char> count_s1(CHAR_SIZE, 0);
    for(int i=0; i<m; i++){
        count_p1[p1[i]]++;
        count_s1[s1[i]]++;
    }
    for(int i=m; i<n; i++){
        if(Compare_string(count_s1, count_p1))// compare current block(pattern size)
            result.push_back(i-m);
        count_s1[s1[i]]++;//add next element
        count_s1[s1[i-m]]--;//remove first element in block
    }
    if(Compare_string(count_s1, count_p1))// compare last element
        result.push_back(n-m);
}

// Trie of all suffixes
class SuffixTrieNode{
    SuffixTrieNode* child[CHAR_SIZE];
    list<int>* index;
public:
    SuffixTrieNode(){
        index = new list<int>;
        for(int i=0; i<CHAR_SIZE; i++)
            child[i] = NULL;
    }
    ~SuffixTrieNode(){
        delete index;
    }
    void InsertSuffix(string s, int idx){
        index->push_back(idx);
        if(s.length() > 0){
            char c = s.at(0);
            if(child[c] == NULL)
                child[c] = new SuffixTrieNode();
            child[c]->InsertSuffix(s.substr(1), idx+1);
        }
    }
    list<int>* Search(string s){
        if(s.length() == 0)
            return index;
        if(child[s.at(0)] != NULL)
            return child[s.at(0)]->Search(s.substr(1));
        else return NULL;
    }
};
class SuffixTrie{
    SuffixTrieNode root;
public:
    SuffixTrie(string s){
        for(int i=0; i<s.length(); i++)
            root.InsertSuffix(s.substr(i), i);
    }
    void Search(string p){
        list<int> *result = root.Search(p);
        if(result == NULL)
            return;
        else{
            list<int>::iterator it;
            int m = p.length();
            for(it=result->begin(); it != result->end(); it++)
                cout << *it-m << endl;
        }
    }
};

// Wildcard Pattern Matching
bool WildcardPatternMatch_Backtracking(string& s, string& p){// O(m * n)
    int s_idx = 0, p_idx = 0;
    int m = p.size();
    int n = s.size();
    int wc_lastidx = -1, s_backidx = -1, wc_nextidx = -1;
    while(s_idx < n){
        if(p_idx < m && (p[p_idx] == '?' || p[p_idx] == s[s_idx]))
            ++s_idx, ++p_idx;
        else if(p_idx < m && p[p_idx] == '*'){
            wc_lastidx = p_idx;
            wc_nextidx = ++p_idx;
            s_backidx = s_idx;
        }
        else if(wc_lastidx == -1)// not match, no wildcard
            return false;
        else{// no match, * isn't empty sequence
            p_idx = wc_nextidx;
            s_idx = ++s_backidx;
        }
    }
    for(int i = p_idx; i<m; i++)//When '*' appears behind 
        if(p[i] != '*')
            return false;
    return true;
}
bool WildcardPatternMatch_DPtable(string& s, string& p){// O(m * n)
    int m = p.size();
    int n = s.size();
    if(m == 0)
        return n==0;
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;// empty pattern and input string
    for(int j=1; j<=m; j++)
        if(p[j-1] == '*')
            dp[0][j] = dp[0][j-1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[j-1] == '*')
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            else if(p[j-1] == '?' || s[i-1] == p[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}
bool WildcardPatternMatch_DPmemo(string& s, string& p, int n, int m, vector<vector<int>>& dp){// O(m * n)
    if(n < 0 && m < 0)
        return 1;
    if(m < 0)
        return 0;
    if(n < 0){
        while(m >= 0){
            if(p[m] != '*')
                return 0;
            m--;
        }
        return 1;
    }
    if(dp[n][m] == -1){
        if(p[m] == '*')
            return dp[n][m] = WildcardPatternMatch_DPmemo(s, p, n-1, m, dp) || WildcardPatternMatch_DPmemo(s, p, n, m-1, dp);
        else{
            if(p[m] != s[n] && p[m] != '?')
                return dp[n][m] = 0;
            else
                return dp[n][m] = WildcardPatternMatch_DPmemo(s, p, n-1, m-1, dp);
        }
    }
    return dp[n][m];
}
bool WildcardPatternMatch_DPOptimalSpace(string& s, string& p){// O(m * n)
    int m = p.size();
    int n = s.size();
    vector<bool> prev(n+1, false), cur(n+1, false);
    prev[0] = true;
    for(int i=1; i<=m; i++){
        bool flag = true;
        for(int k=1; k<i; k++)
            if(p[k-1] != '*'){
                flag = false;
                break;
            }
        cur[0] = flag;
        for(int j=1; j<=n; j++){
            if(p[i-1] == '*')
                cur[j] = cur[j-1] || prev[j];
            else if(p[i-1] == '?' || s[j-1] == p[i-1])
                cur[j] = prev[j-1];
            else
                cur[j] = false;
        }
        prev = cur;
    }
    return prev[n];
}
bool WildcardPatternMatch_Greedy(string& s, string& p){// O(n)
    int m = p.size();
    int n = s.size();
    int i = 0, j = 0, start = -1, match = 0;
    while(i < n){
        if(j<m && (p[j] == '?' || p[j] == s[i]))
            i++, j++;
        else if(j<m && p[j] == '*'){
            start = j;// keep position of last * in pattern
            match = i;// keep position of proper match started in input string
            j++;// move next word in pattern
        }
        else if(start != -1){// no match but * exists in pattern
            j = start + 1;
            match++;
            i = match;
        }
        else
            return false;
    }
    while(j<m && p[j] == '*')
        j++;
    return j == m;
}

// Wildcard Pattern Matching ver2
bool WildcardPatternMatch(string& s, string& p, int i, int j){// O(n)
    if(p[i] == '\0' && s[j] == '\0')// end of string
        return true;
    if(p[i] == '*')//remove consecutive * 
        while(p[i+1] == '*')
            i++;
    if(p[i] == '*' && p[i+1] != '\0' && s[j] == '\0')
        return false;
    if(p[i] == '?' || p[i] == s[j])
        return WildcardPatternMatch(s, p, i+1, j+1);
    if(p[i] == '*')
        return WildcardPatternMatch(s, p, i+1, j) || WildcardPatternMatch(s, p, i, j+1);
    return false;
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// ---------------------------- Divide & Conquer --------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Power(x, n)
long Power_Naive(int x, int n){// O(n)
    long long pow  = 1;
    for(int i=0; i<n; i++)
        pow *= x;
    return pow;
}
long Power_Recursion(int x, int n){// O(n)
    if(n == 0)
        return 1;
    if(x == 0)
        return 0;
    return x * Power_Recursion(x, n-1);
}
long Power_DivideConquer(int x, int n){// O(n)
    if(n == 0)
        return 1;
    else if(n & 1)
        return x * Power_DivideConquer(x, n/2) * Power_DivideConquer(x, n/2);
    else
        return Power_DivideConquer(x, n/2) * Power_DivideConquer(x, n/2);
}
long Power_DivideConquerOtp(int x, int n){// O(log n)
    long temp;
    if(n == 0)
        return 1;
    temp = Power_DivideConquer(x, n>>1);
    if(n & 1)
        return x * temp * temp;
    else
        return temp * temp;
}
double Power_DivideConquerOtpWithNeg(double x, int n){// O(log |n|)
    double temp;
    if(n == 0)
        return 1;
    temp = Power_DivideConquerOtpWithNeg(x, n/2);
    if((n & 1) == 0)// must insert () for opeartor precedence
        return temp * temp;
    else{
        if(n > 0)
            return x * temp * temp;
        else
            return temp * temp / x;
    }
}
long Power_InBuilt(int x, int n){// O(log n)
    return pow(x, n);
}
long Power_BinaryOperator(int x, int n){// O(log n)
    int result = 1;
    while(n > 0){
        if(n & 1)
            result *= x;
        x *= x;
        n >>= 1;
    }
    return result;
}
long Power_Log2(int x, int n){// O(1)
    return round(pow(2, log2(x)*n));
}
long Power_ExpoLog(int x, int n){// O(1)
    double res = exp(log(x) * n);
    res = round(res);
    return res;
}

// Karatsuba Algorithm for Fast Multiplication
int MakeEqualStringLength(string& s1, string& s2){
    int len1 = s1.size();
    int len2 = s2.size();
    if(len1 < len2){
        for(int i=0; i<len2-len1; i++)
            s1 = '0' + s1;
        return len2;
    }
    else if(len1 > len2)
        for(int i=0; i<len1-len2; i++)
            s2 = '0' + s2;
    return len1;
}
string AddBitToString(string s1, string s2){// Ripple Carry Adder
    string res;
    int len = MakeEqualStringLength(s1, s2);
    int carry = 0;
    for(int i=len-1; i>=0; i--){// from LSB
        int first = s1.at(i) - '0';
        int second = s2.at(i) -'0';
        int sum = first ^ second ^ carry + '0';// Sum = A xor B xor Carry (2bit adder), +'0' is used for converting integer to ASCII
        res = (char)sum + res;
        carry = (first & second) | (second & carry) | (first & carry);// Cout = A*B + A*Cin + B*Cin
    }
    if(carry)
        res = '1' + res;
    return res;
}
int MultipleSingleBit(string& s1, string& s2){
    return (s1[0]-'0') * (s2[0]-'0');
}
long int KaratsubaMultiple(string s1, string s2){
    // X = Xl * 2^(n/2) + Xr [ Xl and Xr contain leftmost and rightmost n/2 bits of X]
    // Y = Yl * 2^(n.2) + Yr [ Yl and Yr contain leftmost and rightmost n/2 bits of Y]
    // left = floor(n/2), right = ceil(n/2) [if n is odd, left < right]
    // XY = 2^(2ceil(n/2)) XlYl + 2^(ceil(n/2)) * [(Xl+Xr)(Yl+Yr) - XlYl - XrYr] + XrYr
    int n =MakeEqualStringLength(s1, s2);
    if(n == 0)
        return 0;
    if(n == 1)
        return MultipleSingleBit(s1, s2);
    int l = n/2;// auto floor()
    int r = n-l;// remainder / ceil()
    string xl = s1.substr(0, l);
    string xr = s1.substr(l, r);
    string yl = s2.substr(0, l);
    string yr = s2.substr(l, r);
    long int p1 = KaratsubaMultiple(xl, yl);// XlYl
    long int p2 = KaratsubaMultiple(xr, yr);// XrYr
    long int p3 = KaratsubaMultiple(AddBitToString(xl, xr), AddBitToString(yl, yr));// (Xl+Xr)(Yl+Yr)
    return p1 * (1<<(2*r)) + (p3-p1-p2) * (1<<r) + p2;
}
class BinaryMultiplier{// O(n^2)
public:
    string MakeMultiplication(string s1, string s2){
        string sum = "";
        for(int i=0; i<s2.length(); i++){
            int digit = s2[i] - '0';
            if(digit == 1){
                string shift = MakeShift(s1, s2.size()-(i+1));
                sum = AddBinary(shift, sum);
            }
            else
                continue;
        }
        return sum;
    }
    string MakeShift(string& s1, int n){
        string shift = s1;
        for(int i=0; i<n; i++)
            shift = shift + '0';
        return shift;
    }
    string AddBinary(string& s1, string& s2){
        string res = "";
        int s = 0;
        int i = s1.size()-1, j = s2.size()-1;
        while(i >= 0 || j >= 0 || s == 1){
            s += (i>=0) ? s1[i] - '0' : 0;
            s += (j>=0) ? s2[j] - '0' : 0;
            res = char(s % 2 + '0') + res;
            s >>= 1;
            i--;
            j--;
        }
        return res;
    }
    void BinaryStringToDecimal(string res){
        cout << "Binary: " << res << endl;
        unsigned long long int val = 0;
        for(int i=res.length()-1; i>=0; i--)
            if(res[i] == '1')
                val += pow(2, res.length()-1-i);
        cout << "Decimal: " << val << endl;
    }
};
class Karatsuba{// O(n^2)
public:
    int MakeEqualLength(string& s1, string& s2){
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 < len2){
            for(int i=0; i<len2-len1; i++)
                s1 = '0' + s1;
            return len2;
        }
        else if(len1 > len2)
            for(int i=0; i<len1-len2; i++)
                s2 = '0' + s2;
        return len1;
    }
    string AddString(string s1, string s2){
        string res;
        int n = MakeEqualLength(s1, s2);
        int carry = 0;
        for(int i=n-1; i>=0; i--){
            int first = s1.at(i)-'0';
            int second = s2.at(i)-'0';
            int sum = (first ^ second ^ carry) + '0';
            res = (char)sum + res;
            carry = (first & second) | (second & carry) | (first & carry);
        }
        if(carry)
            res = '1' + res;
        return res;
    }
    string Multiply(string s1, string s2){
        int n = MakeEqualLength(s1, s2);
        if(n == 1)
            return (s2[0]-'0' == 1) && (s1[0]-'0' == 1) ? "1" : "0";
        int l = n >> 1;
        int r = n - l;
        string xl = s1.substr(0, l);
        string xr = s1.substr(l, r);
        string yl = s2.substr(0, l);
        string yr = s2.substr(l, r);
        string p1 = Multiply(xl, yl);
        string p2 = Multiply(xr, yr);
        string p3 = Multiply(AddString(xl, xr), AddString(yl, yr));
        return AddString(AddString(MakeShift(p1, 2*(n-n/2)), p2), MakeShift(Substraction(p3, AddString(p1, p2)), n-(n/2)));
    }
    string DecimalToBinary(long long int n){
        string res = "";
        if(n <= 0)
            return "0";
        else{
            int i = 0;
            while(n > 0){
                long long int num = n % 2;
                stringstream ss;
                ss << num;
                res = ss.str() + res;
                n >>= 1;
                i++;
            }
            return res;
        }
    }
    string Substraction(string s1, string s2){
        int n = MakeEqualLength(s1, s2);
        int diff;
        string res;
        for(int i=n-1; i>=0; i--){
            diff = (s1[i]-'0') - (s2[i]-'0');
            if(diff >= 0)
                res = DecimalToBinary(diff) + res;
            else{
                for(int j=i-1; j>=0; j--){
                    s1[j] = (s1[j]-'0'-1) % 10 + '0';
                    if(s1[j] != '1')
                        break;
                }
                res = DecimalToBinary(diff+2) + res;
            }
        }
        return res;
    }
    string MakeShift(string s1, int n){
        string shift = s1;
        for(int i=0; i<n; i++)
            shift = shift + '0';
        return shift;
    }
};

// Convex Hull
pair<int, int> center;
int DetermineQuadrant(const pair<int, int>& point){
    if(point.first >= 0 && point.second >= 0)
        return 1;
    else if(point.first <= 0 && point.second >= 0)
        return 2;
    else if(point.first <= 0 && point.second <= 0)
        return 3;
    return 4;
}
int OrientationOfThreePoint(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int res = (b.second-a.second) * (c.first-b.first) - (c.second-b.second)*(b.first-a.first);
    if(res == 0)
        return 0;
    else if(res > 0)
        return 1;
    return -1;
}
bool ComparePoint(pair<int, int> p1, pair<int, int> p2){
    pair<int, int> temp1 = make_pair(p1.first-center.first, p1.second-center.second);
    pair<int, int> temp2 = make_pair(p2.first-center.first, p2.second-center.second);
    int one = DetermineQuadrant(temp1);
    int two = DetermineQuadrant(temp2);
    if(one != two)
        return one < two;
    return temp1.second * temp2.first < temp2.second * temp1.first;// P's orientation < Q's orientation
}
vector<pair<int, int>> Merger(vector<pair<int, int>> a, vector<pair<int, int>> b){// O(n)
    int n1 = a.size();
    int n2 = b.size();
    int ia = 0, ib = 0;
    for(int i=1; i<n1; i++)//rightmost point
        if(a[i].first > a[ia].first)
            ia = i;
    for(int i=1; i<n2; i++)//leftmost point
        if(b[i].first < b[ib].first)
            ib = i;
    int inda = ia, indb = ib;
    bool done = false;
    while(!done){// Find upper tangent
        done = true;
        while(OrientationOfThreePoint(b[indb], a[inda], a[(inda+1)%n1]) >= 0)
            inda = (inda + 1) % n1;
        while(OrientationOfThreePoint(a[inda], b[indb], b[(n2+indb-1)%n2]) <= 0){
            indb = (n2 + indb -1) % n2;
            done = false;
        }
    }
    int uppera = inda, upperb = indb;
    inda = ia, indb = ib;
    done = false;
    int g = 0;
    while(!done){// Find lower tangent
        done = true;
        while(OrientationOfThreePoint(a[inda], b[indb], b[(indb+1)%n2]) >= 0)
            indb = (indb + 1) % n2;
        while(OrientationOfThreePoint(b[indb], a[inda], a[(n1+inda-1)%n1]) <= 0){
            inda = (n1 + inda -1) % n1;
            done = false;
        }
    }
    int lowera = inda, lowerb = indb;
    vector<pair<int, int>> ret;// contain convex hull after merging two convex hulls in counterclockwise order
    int ind = uppera;
    ret.push_back(a[uppera]);
    while (ind != lowera){
        ind = (ind+1)%n1;
        ret.push_back(a[ind]);
    }
    ind = lowerb;
    ret.push_back(b[lowerb]);
    while (ind != upperb){
        ind = (ind+1)%n2;
        ret.push_back(b[ind]);
    }
    return ret;
}
vector<pair<int, int>> ConvexHull_Brute(vector<pair<int, int>> a){
    set<pair<int, int>> s;
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            int x1 = a[i].first, y1 = a[i].second;
            int x2 = a[j].first, y2 = a[j].second;
            int a1 = y1-y2;
            int b1 = x2-x1;
            int c1 = x1*y2-y1*x2;
            int pos = 0, neg = 0;
            for(int k =0; k<a.size(); k++){
                if(a1 * a[k].first + b1 * a[k].second + c1 <= 0)
                    neg++;
                if(a1 * a[k].first + b1 * a[k].second + c1 >= 0)
                    pos++;
            }
            if(pos == a.size() || neg == a.size()){
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }
    vector<pair<int, int>> ret;
    for(auto e : s)
        ret.push_back(e);
    center = {0, 0};
    int n = ret.size();
    for(int i=0; i<n; i++){
        center.first += ret[i].first;
        center.second += ret[i].second;
        ret[i].first *= n;
        ret[i].second *= n;
    }
    sort(ret.begin(), ret.end(), ComparePoint);// counterclockwise order sort
    for(int i=0; i<n; i++)
        ret[i] = make_pair(ret[i].first/n, ret[i].second/n);
    return ret;
}
vector<pair<int, int>> Divide(vector<pair<int, int>> a){// O(n log n)
    if(a.size() <= 5)
        return ConvexHull_Brute(a);
    vector<pair<int, int>> left, right;
    for(int i=0; i<a.size()/2; i++)
        left.push_back(a[i]);
    for(int i=a.size()/2; i<a.size(); i++)
        right.push_back(a[i]);
    vector<pair<int, int>> left_hull = Divide(left);
    vector<pair<int, int>> right_hull = Divide(right);
    return Merger(left_hull, right_hull);
}
vector<pair<int, int>> RemovePoint(vector<pair<int, int>> a, vector<pair<int, int>> hull, pair<int, int> p){
    bool found = false;
    for(int i=0; i<hull.size() && !found; i++)
        if(hull[i].first == p.first && hull[i].second == p.second)
            found = true;
    if(found == 0)
        return hull;
    for(int i=0; i<a.size(); i++)
        if(a[i].first == p.first && a[i].second == p.second){
            a.erase(a.begin()+i);
            break;
        }
    sort(a.begin(), a.end());
    return Divide(a);
}

// Jarvis's Convex Hull
struct Point{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y) {}
};
int Orientation(Point p, Point q, Point r){
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(val == 0)
        return 0;
    return val > 0 ? 1 : 2;
}
bool IntersectOnCollinear(Point p, Point q, Point r){
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}
void ConvexHull_Jarvis(vector<Point> p, int n){// O(m * n)/ O(n^2)
    if(n < 3)
        return;
    vector<Point> hull;
    int l = 0;
    for(int i=1; i<n; i++){
        if(p[i].x < p[l].x)
            l = i;
        else if(p[i].x == p[l].x && p[i].y < p[l].y)
            l = i;
    }
    int cur = l, q;
    do{
        hull.push_back(p[cur]);
        q = (cur + 1) % n;
        for(int i=0; i<n; i++){
            if(Orientation(p[cur], p[i], p[q]) == 2)
                q = i;
            if(cur != i && Orientation(p[cur], p[i], p[q]) == 0 && IntersectOnCollinear(p[cur], p[q], p[i]))
                q = i;
        }
        cur = q;
    } while(cur != l);
    for(auto k : hull)
        cout << "(" << k.x << "," << k.y << ")\n";
}

// Convex Hull using Graham Scan
Point p0;
Point NextToTop(stack<Point>& s){
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;//value under stack top
}
void PointSwap(Point& p1, Point& p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
int DistanceSquare(Point p1, Point p2){
    return (p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y);
}
int ComparePointOrient(const void *vp1, const void *vp2){
    Point *p1 = (Point*)vp1;
    Point *p2 = (Point*)vp2;
    int o = Orientation(p0, *p1, *p2);
    if(o == 0)
        return DistanceSquare(p0, *p2) >= DistanceSquare(p0, *p1) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}
void ConvexHull_GrahamScan(vector<Point>& p, int n){// O(n log n)
    int ymin = p[0].y, min = 0;
    for(int i=1; i<n; i++)//Find leftmost point
        if(p[i].y < ymin || ymin == p[i].y && p[i].x < p[min].x)
            ymin = p[i].y , min = i;
    swap(p[0], p[min]);
    p0 = p[0];
    qsort(&p[1], n-1, sizeof(Point), ComparePointOrient);
    int m = 1;
    for(int i=1; i<n; i++){// if points are located on same line, remove element
        while(i < n-1 && Orientation(p0, p[i], p[i+1]) == 0)
            i++;
        p[m] = p[i];
        m++; 
    }
    if(m < 3)
        return;
    stack<Point> s;
    s.push(p[0]);
    s.push(p[1]);
    s.push(p[2]);
    for(int i=3; i<m; i++){
        while(s.size() > 1 && Orientation(NextToTop(s), s.top(), p[i]) != 2)
            s.pop();
        s.push(p[i]);
    }
    while(!s.empty()){
        Point temp = s.top();
        cout << "(" << temp.x << "," << temp.y << ")\n";
        s.pop();
    }
}

// QuickHull for Convex Hull
set<pair<int,int>> hull;
int FindSide(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3){
    int val = (p3.second-p1.second)*(p2.first-p1.first) - (p2.second-p1.second)*(p3.first-p1.first);
    if(val > 0)
        return 1;
    else if(val < 0)
        return -1;
    return 0;
}
int LineDistance(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3){
    return abs((p3.second-p1.second)*(p2.first-p1.first) - (p2.second-p1.second)*(p3.first-p1.first));
}
void ConvexHull_Quick(vector<pair<int,int>> a, int n, pair<int,int> p1, pair<int,int> p2, int side){
    int ind = -1;
    int max_dist = 0;
    for(int i=0; i<n; i++){
        int temp = LineDistance(p1, p2, a[i]);
        if(FindSide(p1, p2, a[i]) == side && temp > max_dist){
            ind = i;
            max_dist = temp;
        }
    }
    if(ind == -1){
        hull.insert(p1);
        hull.insert(p2);
        return;
    }
    ConvexHull_Quick(a, n, a[ind], p1, -FindSide(a[ind], p1, p2));
    ConvexHull_Quick(a, n, a[ind], p2, -FindSide(a[ind], p2, p1));
}
void PrintHull(vector<pair<int,int>> a, int n){// O(n^2) / O(n log n)
    if(n < 3)
        return;
        int min_x = 0, max_x = 0;
        for(int i=1; i<n; i++){
            if(a[i].first < a[min_x].first)
                min_x = i;
            if(a[i].first > a[max_x].first)
                max_x = i;
        }
        ConvexHull_Quick(a, n, a[min_x], a[max_x], 1);
        ConvexHull_Quick(a, n, a[min_x], a[max_x], -1);
        for(auto k : hull)
            cout << "(" << k.first << "," << k.second << ")\n";
}

// Median of 2 Sorted Array of Same Size
int GetMedianOf2SortedSameSizeArr_ver1(vector<int>& a, vector<int>& b, int n){// O(n)
    int m1 = -1, m2 = -1;
    int i = 0, j = 0;
    for(int k = 0; k<=n ; k++){
        if(i == n){
            m1 = m2;
            m2 = b[0];
            break;
        }
        else if(j == n){
            m1 = m2;
            m2 = a[0];
            break;
        }
        if(a[i] <= b[j]){
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else{
            m1 = m2;
            m2 = b[j];
            j++;
        }
    }
    return (m1+m2)/2;
}
int GetMedianOf2SortedSameSizeArr_ver2(vector<int>& a, vector<int>& b, int n){// O(n log n)
    int i = n-1, j = 0;
    while(a[i] > b[j] && j < n && i > -1)
        swap(a[i--], b[j++]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return (a[n-1] + b[0]) / 2;
}
int GetMedianOf2SortedSameSizeArr_BinarySearch(vector<int>& a, vector<int>& b, int n){// O(log n)
    int low = (int)-1e9, high = (int)1e9;
    int pos = n;
    double ans = 0.0;
    while(low <= high){
        int mid = (low+high) >> 1;
        int ub = upper_bound(a.begin(), a.end(), mid) - a.begin() + upper_bound(b.begin(), b.end(), mid) - b.begin();
        if(ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    ans = low;
    pos--;
    low = (int)-1e9;
    high = (int) 1e9;
    while(low <= high){
        int mid = (low + high) >> 1;
        int ub = upper_bound(a.begin(), a.end(), mid) - a.begin() + upper_bound(b.begin(), b.end(), mid) - b.begin();
        if(ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    ans = (ans + low) / 2;
    return ans;
}

// Median of 2 Sorted Array of Different Size
int GetMedianOf2SortedDiffSizeArr_Naive(vector<int>& a, vector<int>& b){// O((n+m) * log(n+m))
    int n = a.size();
    int m = b.size();
    int t = n + m;
    vector<int> c(t, 0);
    for(int k=0; k<t; k++){
        if(k < n)
            c[k] = a[k];
        else
            c[k] = b[k-n];
    }
    sort(c.begin(), c.end());
    if(t % 2 == 0){
        int z = t / 2;
        int e = c[z];
        int q = c[z-1];
        return (e+q)/2;
    }
    else
        return c[round(t/2)];
}
int GetMedianOf2SortedDiffSizeArr_2Var(vector<int>& a, vector<int>& b){// O(m + n)
    int n = a.size();
    int m = b.size();
    int t = n + m;
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;
    for(int k=0; k<= t>>1; k++){
        m1 = m2;
        if(i != n && j != m)
            m2 = a[i] > b[j] ? b[j++] : a[i++];
        else if(i < n)
            m2 = a[i++];
        else
            m2 = b[j++];
    }
    if(t % 2 == 1)
        return m2;
    else
        return (m1 + m2) >> 1;
}
double GetMedianOf2SortedDiffSizeArr_BinarySearch(vector<int>& a, vector<int>& b){// O(min(log m, log n))
    int n = a.size();
    int m = b.size();
    if(n > m)
        return GetMedianOf2SortedDiffSizeArr_BinarySearch(b, a);
    int s = 0;
    int e = n;
    int mid_merged = (n + m + 1) / 2;
    while(s <= e){// for array a (n < m)
        int mid = (s+e) / 2;
        int la_size = mid;// array a's mid index
        int lb_size = mid_merged - mid;//array b's mid index
        int la = la_size > 0 ? a[la_size-1] : INT_MIN;// left a's last element
        int lb = lb_size > 0 ? b[lb_size-1] : INT_MIN;// left b's last element
        int ra = la_size < n ? a[la_size] : INT_MAX;// right a's first element
        int rb = lb_size < m ? b[lb_size] : INT_MAX;// right b's first element
        if(la <= rb && lb <= ra){
            if((n+m) % 2 == 0)// if merged array's size is even number 
                return (max(la, lb) + min(ra, rb)) / 2.0;
            return max(la, lb);
        }
        else if(la > rb)//value in left is bigger than value in right, move mid to left
            e = mid - 1;// small size arr's mid move left, big size arr's mid move right
        else//lb > ra
            s = mid + 1;
    }
    return 0.0;
}

// Painter's Partition Problem using Binary Search
int GetMaxValue(vector<int>& arr, int n){
    int max_val = INT_MIN;
    for(int i=0; i<n; i++)
        if(arr[i] > max_val)
            max_val = arr[i];
    return max_val;
}
int GetSumOfArray(vector<int>& arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    return sum;
}
int NumberOfPainter(vector<int>& arr, int n, int len){
    int sum = 0, painter = 1;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > len){
            sum = arr[i];
            painter++;
        }
    }
    return painter;
}
int PainterPartition(vector<int>& arr, int k){// O(n log (sum(arr)))
    int n = arr.size();
    int l = GetMaxValue(arr, n);
    int h = GetSumOfArray(arr, n);
    while(l < h){
        int mid = (l + h) >> 1;
        int painter = NumberOfPainter(arr, n, mid);
        if(painter <= k)//if target's value is close to low value,  
            h = mid;// Update search range closer to low 
        else
            l = mid + 1;
    }
    return l;
}

// Square Root of Integer
int SquareRoot_Naive(int x){// O(sqrt(x))
    if(x == 0 || x == 1)
        return x;
    int i = 1, res = 1;
    while(res <= x){
        i++;
        res = i * i;
    }
    return i-1;
}
int SquareRoot_BinarySearch(int x){// O(log x)
    if(x == 0 || x == 1)
        return x;
    int s = 1, e = x/2, ans;
    while(s <= e){
        int mid = (s+e) >> 1;
        int sqr = mid * mid;
        if(sqr == x)
            return mid;
        if(sqr <= x){
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    return ans;
}
int SquareRoot_BuiltIn(int x){// O(log x)
    return sqrt(x); 
}
int SquareRoot_Exponential(int x){// O(1)
    double res = exp(log(x)/2);
    return floor(res);
}

// Find frequency of each element in a limited range array in less than O(n) time
void FindFrequency_Naive(vector<int>& arr){// O(n)
    int n = arr.size();
    int freq = 1, idx = 1;
    while(idx < n){
        if(arr[idx-1] == arr[idx])
            freq++, idx++;
        else{
            cout << arr[idx-1] << " " << freq << endl;
            freq = 1, idx++;
        }
    }
    cout << arr[idx-1] << " " << freq << endl;
}
void FindFrequency_Hash(vector<int>& arr){// O(n)
    unordered_map<int, int> m;
    int n = arr.size();
    for(int i=0; i<n; i++)
        m[arr[i]]++;
    for(auto k : m)
        cout << k.first << " " << k.second << endl;
}
void FindFrequency_BinarySearch(vector<int>& arr, int low, int high, vector<int>& freq){
    if(arr[low] == arr[high])
        freq[arr[low]] += high - low + 1;
    else{
        int mid = (low + high) >> 1;
        FindFrequency_BinarySearch(arr, low, mid, freq);
        FindFrequency_BinarySearch(arr, mid+1, high, freq);
    }
}

// Tiling Problem using Divide & Conquer
int count_tile = 0;
void PlaceTileOnBoard(vector<vector<int>>& board, int x1, int y1, int x2, int y2, int x3, int y3){
    count_tile++;
    board[x1][y1] = board[x2][y2] = board[x3][y3] = count_tile;
}
int TilingBoard(vector<vector<int>>& board, int n, int x, int y){
    int r, c;
    if(n == 2){
        count_tile++;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(board[x+i][y+j] == 0)
                    board[x+i][y+j] = count_tile;
        return 0;
    }
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            if(board[i][j] != 0)
                r = i, c = j;
    // L tile's quadrant
    //  1 2
    //  3 4
    if(r<x+n/2 && c < y+n/2)// missing tile on quadrant 1
        PlaceTileOnBoard(board, x+n/2, y+n/2-1, x+n/2, y+n/2, x+n/2-1, y+n/2);
    else if(r >= x+n/2 && c < y+n/2)// missing tile on quadrant 2
        PlaceTileOnBoard(board, x+n/2-1, y+n/2, x+n/2, y+n/2, x+n/2-1, y+n/2-1);
    else if(r < x+n/2 && c >= y+n/2)// missing tile on quadrant 3
        PlaceTileOnBoard(board, x+n/2, y+n/2-1, x+n/2, y+n/2, x+n/2-1, y+n/2-1);
    else if(r >= x+n/2 && c>= y+n/2)// missing tile on quadrant 4
        PlaceTileOnBoard(board, x+n/2-1, y+n/2, x+n/2, y+n/2-1, x+n/2-1, y+n/2-1);
    
    TilingBoard(board, n/2, x, y);//Quadrant 1
    TilingBoard(board, n/2, x+n/2, y);//Quadrant 2
    TilingBoard(board, n/2 , x, y+n/2);//Quadrant 3
    TilingBoard(board, n/2, x+n/2, y+n/2);//Quadrant 4
    return 0;
}

// Skyline Problem
struct Building{
    int left, height, right;
};
class Strip{
    int left, height;
public:
    Strip(int l = 0, int h = 0){
        left = l;
        height = h;
    }
    friend class Skyline;
};
class Skyline{
    Strip* arr;
    int cap;
    int n;
public:
    Skyline(int c){
        cap = c;
        arr = new Strip[c];
        n = 0;
    }
    ~Skyline() {delete[] arr;}
    int count() {return n;}
    Skyline* Merge(Skyline* other){
        Skyline* res = new Skyline(this->n + other->n);
        int h1 = 0, h2 = 0;
        int i = 0, j = 0;
        while(i < this->n && j < other->n){
            if(this->arr[i].left < other->arr[j].left){
                int x1 = this->arr[i].left;
                h1 = this->arr[i].height;
                int maxh = max(h1, h2);
                res->Append(new Strip(x1, maxh));
                i++;
            }
            else{
                int x2 = other->arr[j].left;
                h2 = other->arr[j].height;
                int maxh = max(h1, h2);
                res->Append(new Strip(x2, maxh));
                j++;
            }
        }
        while(i < this->n){
            res->Append(&arr[i]);
            i++;
        }
        while(j < other->n){
            res->Append(&other->arr[j]);
            j++;
        }
        return res;
    }
    void Append(Strip* st){
        if(n > 0 && arr[n-1].height == st->height)
            return;
        if(n > 0 && arr[n-1].left == st->left){
            arr[n-1].height = max(arr[n-1].height, st->height);
            return;
        }
        arr[n] = *st;
        n++;
    }
    void Print(){
        for(int i=0; i<n; i++)
            cout << "(" << arr[i].left << "," << arr[i].height << ")\n";
    }
};
Skyline* FindSkyline(vector<Building> arr, int l, int h){
    if(l == h){
        Skyline* res = new Skyline(2);
        res->Append(new Strip(arr[l].left, arr[l].height));
        res->Append(new Strip(arr[l].right, 0));
        return res;
    }
    int mid = (l + h) / 2;
    Skyline* sl = FindSkyline(arr, l, mid);
    Skyline* sr = FindSkyline(arr, mid+1, h);
    Skyline* res = sl->Merge(sr);
    delete sl;
    delete sr;
    return res;
}

void Create_Skyline(vector<vector<int>>& b){
    int n = b.size();
    vector<pair<int, int>> wall;
    int l, h, r;
    for(int i=0; i<n; i++){
        l = b[i][0];
        h = b[i][1];
        r = b[i][2];
        wall.push_back({l, -h});
        wall.push_back({r, h});
    }
    sort(wall.begin(), wall.end());
    vector<pair<int, int>> skyline;
    multiset<int> wall_left_h = {0};
    int top = 0;
    for(auto w : wall){
        if(w.second < 0)
            wall_left_h.insert(-w.second);
        else
            wall_left_h.erase(wall_left_h.find(w.second));
        if(*wall_left_h.rbegin() != top){
            top = *wall_left_h.rbegin();
            skyline.push_back(make_pair(w.first, top));
        }
    }
    for(auto k: skyline)
        cout << "(" << k.first << "," << k.second << ")\n";
}

// Search in a row-wise and column-wise sorted 2D array
void SearchAllSorted(vector<vector<int>>& mat, int sr, int er, int sc, int ec, int key){
    int i = (sr + er) >> 1;
    int j = (sc + ec) >> 1;
    if(mat[i][j] == key)
        cout << key << "," << i<< ", " << j << endl;
    else{
        if(i != er || j != sc)
            SearchAllSorted(mat, sr, i, j, ec, key);
        if(sr == er && sc + 1 == ec && mat[sr][ec] == key)
            cout << key << "," << sr<< ", " << ec << endl;
        if(mat[i][j] < key && i+1 <= er)
            SearchAllSorted(mat, i+1, er, sc, ec, key);
        else if(j-1 >= sc)
            SearchAllSorted(mat, sr, er, sc, j-1, key);
    }
}
bool SearchAllSorted_BinarySearch(vector<vector<int>>& mat, int r, int l, int h, int key){
    while(l <= h){
        int mid = (l + h) >> 1;
        if(mat[r][mid] == key)
            return true;
        else if(mat[r][mid] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}
void SearchAllSorted(vector<vector<int>>& mat, int key){// O(r log c)
    int r = mat.size();
    int c = mat[0].size();
    for(int i=0; i<r; i++){
        if(mat[i][0] <= key && mat[i][c-1] >= key)
            if(SearchAllSorted_BinarySearch(mat, i, 0, c-1, key)){
                cout << key <<"," << i << endl;
            return;
            }
    }
    cout << "Not found\n";
}
int SearchAllSorted_Fast(vector<vector<int>>& mat, int key){// O(n)
    int n = mat.size();
    if(n == 0)
        return -1;
    int small = mat[0][0], large = mat[n-1][n-1];
    if(key < small || key > large)
        return -1;
    int i = 0, j = n-1;
    while(i < n & j >= 0){
        if(mat[i][j] == key){
            cout << i << "," << j << endl;
            return 1;
        }
        if(mat[i][j] > key)
            j--;
        else
            i++;
    }
    cout << "Not found\n";
    return 0;
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// ------------------------------- Geometric ------------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Check if point lies inside polygon
bool Point_in_polygon(Point point, vector<Point> polygon){
    int num_vertices = polygon.size();
    double x = point.x, y = point.y;
    bool inside = false;
    Point p1 = polygon[0], p2;
    for (int i = 1; i <= num_vertices; i++){
        p2 = polygon[i % num_vertices];
        if (y > min(p1.y, p2.y) && y <= max(p1.y, p2.y) && x <= max(p1.x, p2.x)) {
                    double x_intersection = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
                    if (p1.x == p2.x || x <= x_intersection)
                        inside = !inside;
        }
        p1 = p2;
    }
    return inside;
}

// Optimum Location of Point to Minimize Total Distance
struct Line{// ax+by+c = 0
    int a, b, c;
    Line(int a, int b, int c) : a(a), b(b), c(c){}
};
double Line_Distance(double x, double y, Point p){// dist (x,y) from p
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
}
double Compute_TotalDistance(Point p[], int n, Line l, double x){
    double res = 0;
    double y = -1 * (l.c + l.a * x) / l.b;// ax + by + c = 0
    for(int i=0; i<n; i++)
        res += Line_Distance(x, y, p[i]);// Sum of dist for all point set
    return res;
}
double OptimalPoint_TernarySearch(Point p[], int n, Line l){
    double low = -1e6;
    double high = 1e6;
    while((high-low) > EPS){
        double mid1 = (2*low+high)/3;// low + (high-low)/3
        double mid2 = (low+2*high)/3;// high - (high-low)/3
        double dist1 = Compute_TotalDistance(p, n, l, mid1);
        double dist2 = Compute_TotalDistance(p, n, l, mid2);
        if(dist1 < dist2)//U shape graph
            high = mid2;
        else
            low = mid1;
    }
    return Compute_TotalDistance(p, n, l, (low+high)/2);// average point of line(low~high)
}
double OptimalPoint(int points[5][2], Line l){
    Point p[5];
    for(int i=0; i<5; i++)
        p[i] = Point(points[i][0], points[i][1]);// point(x, y)
    return OptimalPoint_TernarySearch(p, 5, l);
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// ------------------------------- Randomized -----------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// CAPTCHA
bool CheckCaptcha(string& result, string& input){
    return result.compare(input) == 0;
}
string GenerateCaptcha(int n){
    time_t t;
    srand(unsigned(time(&t)));
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string captcha = "";
    while(n--)
        captcha.push_back(chars[rand()%chars.size()]);
    return captcha;
}

// Randomized Binary Search
int GetRandom(int x, int y){
    srand(time(NULL));
    return (x + rand() % (y-x+1));
}
int RnadomizedBinarySearch_Recursion(vector<int>& arr, int l, int r, int key){
    if(l <= r){
        int mid = GetRandom(l, r);
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > key)
            return RnadomizedBinarySearch_Recursion(arr, l, mid-1, key);
        return RnadomizedBinarySearch_Recursion(arr, mid+1, r, key);
    }
    return -1;
}
int RnadomizedBinarySearch_Iterative(vector<int>& arr, int l, int r, int key){
    while(l <= r){
        int mid = GetRandom(l, r);
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Strong Password Suggester
string AddCharToPassword(string str, int need){
    int pos = 0;
    string low = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<need; i++){
        pos = rand() % str.size();
        str.insert(pos, 1, low[rand() % 26]);
    }
    return str;
}
string PasswordSuggester(int l, int u, int d, int s, string str){
    string num = "0123456789";
    string low = "abcdefghijklmnopqrstuvwxyz";
    string up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special = "@#$_()!";
    int pos = 0;
    if(l == 0){
        pos = rand() % str.size();
        str.insert(pos, 1, low[rand() % 26]);
    }
    if(u == 0){
        pos = rand() % str.size();
        str.insert(pos, 1, up[rand() % 26]);
    }
    if(d == 0){
        pos = rand() % str.size();
        str.insert(pos, 1, num[rand() % 10]);
    }
    if(s == 0){
        pos = rand() % str.size();
        str.insert(pos, 1, special[rand() % 7]);
    }
    return str;
}
void JudgePassword(string p){
    int n = p.size();
    int strong = 8;
    int low = 0, up = 0, special = 0, num = 0, need = 0;
    string suggest;
    for(int i=0; i<n; i++){
        if(p[i] >= 97 && p[i] <=122)
            low = 1;
        else if(p[i] >= 65 && p[i] <= 90)
            up = 1;
        else if(p[i] >=48 && p[i] <= 57)
            num = 1;
        else
            special = 1;
    }
    if(low+up+num+special == 4){
        cout << "Strong" << endl;
        return;
    }
    else
        cout << "Suggested Password" << endl;
    for(int i=0; i<strong; i++){
        suggest = PasswordSuggester(low, up, num, special, p);
        need = 8 - suggest.size();
        if(need > 0)
            suggest = AddCharToPassword(suggest, need);
        cout << suggest << endl;
    }
}

// Karger's algorithm for minimum cut
struct PureEdge{
    int src, dest;
};
struct PureGraph{
    int v, e;
    PureEdge* edge;
};
struct Subset{
    int parent, rank;
};
PureGraph* CreatePureGraph(int v, int e){
    PureGraph* g = new PureGraph;
    g->v = v;
    g->e = e;
    g->edge = new PureEdge[e];
    return g;
}
int Karger_Find(vector<Subset>& subset, int i){
    if(subset[i].parent != i)
        subset[i].parent = Karger_Find(subset, subset[i].parent);
    return subset[i].parent;
}
void Karger_Union(vector<Subset>& subset, int x, int y){
    int xroot = Karger_Find(subset, x);
    int yroot = Karger_Find(subset, y);
    if(subset[xroot].rank < subset[yroot].rank)
        subset[xroot].parent = yroot;
    else if(subset[xroot].rank > subset[yroot].rank)
        subset[yroot].parent = xroot;
    else{
        subset[yroot].parent = xroot;
        subset[xroot].rank++;
    }
}
int KargerMinCut(PureGraph* g){
    int v = g->v, e = g->e;
    PureEdge* edge = g->edge;
    vector<Subset> subset(v);
    for(int i=0; i<v; i++){
        subset[i].parent = i;
        subset[i].rank = 0;
    }
    int vertices = v;
    while(vertices > 2){
        int i = rand() % e;
        int subset1 = Karger_Find(subset, edge[i].src);
        int subset2 = Karger_Find(subset, edge[i].dest);
        if(subset1 == subset2)
            continue;
        else{
            cout << "Contracting Edge: " << edge[i].src << "-" << edge[i].dest << endl;
            vertices--;
            Karger_Union(subset, subset1, subset2);
        }
    }
    int cut = 0;
    for(int i=0; i<e; i++){
        int subset1 = Karger_Find(subset, edge[i].src);
        int subset2 = Karger_Find(subset, edge[i].dest);
        if(subset1 != subset2)
            cut++;
    }
    return cut;
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// ----------------------------- Branch & Bound ---------------------------
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// 0/1 Knapsack
struct KnapsackItem{
    float weight;
    int val;// = profit
};
struct KnapsackNode{
    // level = level of node in tree / index in arr
    // bound = upper bound of max profit in subtree of cur node
    int level, profit, bound;
    float weight;
};
bool CompareKnapsackItem(KnapsackItem a, KnapsackItem b){
    // val / weight => max profit per unit weight 1 
    double r1 = (double)a.val / a.weight;
    double r2 = (double)b.val / b.weight;
    return r1 > r2;
}
int KnapsackBound(KnapsackNode cur, int n, int w, vector<KnapsackItem> arr){
    if(cur.weight >= w)//overflow knapsack capacity
        return 0;
    int profit_bound = cur.profit;
    int j = cur.level + 1;//cur node's sub node's index
    int total_weight = cur.weight;
    while((j < n) && (total_weight + arr[j].weight) <= w){
        total_weight += arr[j].weight;
        profit_bound += arr[j].val;
        j++;
    }
    if(j < n)// if next item can't be put in knapsack, include last item partially for upper bound
        profit_bound += (w-total_weight) * arr[j].val/arr[j].weight;
    return profit_bound;
}
int Knapsack_BranchNBound(int w, vector<KnapsackItem> arr, int n){// O(n^2)
    sort(arr.begin(), arr.end(), CompareKnapsackItem);
    queue<KnapsackNode> q;
    KnapsackNode u, v;// u = cur node , v = next node
    u.level = -1;//dummy node setting
    u.profit = u.weight = 0;
    q.push(u);
    int max_profit = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(u.level == -1)
            v.level = 0;
        if(u.level == n-1)
            continue;
        v.level = u.level + 1;//next node's level is increasing according to repetition of while statement
        v.weight = u.weight + arr[v.level].weight;// if we select next node
        v.profit = u.profit + arr[v.level].val;
        if(v.weight <= w && v.profit > max_profit)
            max_profit = v.profit;
        v.bound = KnapsackBound(v, n, w, arr);
        if(v.bound > max_profit)
            q.push(v);
        v.weight = u.weight;//if we don't select next node(level is increasing regardless of whether next node is selected or not)
        v.profit = u.profit;
        v.bound = KnapsackBound(v, n, w, arr);
        if(v.bound > max_profit)
            q.push(v);
    }
    return max_profit;
}

// 8 Puzzle
struct PuzzleNode{
    PuzzleNode* parent;
    int mat[3][3];
    int x, y, cost, level;
};
void Print8Puzzle(int mat[3][3]){
    for(int i=0; i<3; i++, cout << endl)
        for(int j=0; j<3; j++)
            cout << mat[i][j] << " ";
}
PuzzleNode* CreatePuzzleNode(int mat[3][3], int x, int y, int x_new, int y_new, int level, PuzzleNode* parent){
    PuzzleNode* node = new PuzzleNode;//x and y is coordinate of blank tile
    node->parent = parent;
    memcpy(node->mat, mat, sizeof(node->mat));
    swap(node->mat[x][y], node->mat[x_new][y_new]);//move tile 1 pos()
    node->cost = INT_MAX;
    node->level = level;
    node->x = x_new;
    node->y = y_new;
    return node;
}
int x_dir[] = {1, 0, -1, 0};//bottom, left, top, right;
int y_dir[] = {0, -1, 0, 1}; 
int CalcCostOfPuzzle(int input[3][3], int output[3][3]){
    int count = 0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(input[i][j] && input[i][j] != output[i][j])
                count++;
    return count;
}
bool IsTileMoveSafe(int x, int y){
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}
void PrintPuzzleMovementPath(PuzzleNode* cur){
    if(cur == NULL)
        return;
    PrintPuzzleMovementPath(cur->parent);//trace until arriving root node
    Print8Puzzle(cur->mat);//Print matrix progress from root to goal node 
    cout << endl;
}
struct ComparePuzzleCost{
    bool operator()(const PuzzleNode* l, const PuzzleNode* r)const{
        return (l->cost + l->level) > (r->cost + r->level);
    }
};
void EightPuzzle(int input[3][3], int output[3][3], int x, int y){
    priority_queue<PuzzleNode*, vector<PuzzleNode*>, ComparePuzzleCost> pq;
    PuzzleNode* root = CreatePuzzleNode(input, x, y, x, y, 0, NULL);
    root->cost = CalcCostOfPuzzle(input, output);
    pq.push(root);
    while(!pq.empty()){
        PuzzleNode* min = pq.top();
        pq.pop();
        if(min->cost == 0){
            PrintPuzzleMovementPath(min);
            return;
        }
        for(int i=0; i<4; i++){
            if(IsTileMoveSafe(min->x + x_dir[i], min->y + y_dir[i])){
                PuzzleNode* child = CreatePuzzleNode(min->mat, min->x, min->y, min->x+x_dir[i], min->y+y_dir[i], min->level+1, min);
                child->cost = CalcCostOfPuzzle(child->mat, output);
                pq.push(child);
            }
        }
    }
}

// N Queen
void PrintNQueen(vector<vector<int>>& board){
    int n = board.size();
    for(int i=0; i<n; i++, cout << endl)
        for(int j=0; j<n; j++)
            cout << board[i][j] << " ";
}
bool IsNQueenSafe(int r, int c, vector<bool>& rows, vector<bool>& ld, vector<bool>& rd){
    int n = rows.size();
    if(rows[r] == true || ld[r+c] == true || rd[r-c+n-1] == true)
        return false;
    return true;
}
bool NQueen_BNB(vector<vector<int>>& board, int c, vector<bool>& rows, vector<bool>& ld, vector<bool>& rd){
    int n = board.size();
    // number of diagonal = 2*n -1
    // slash diagonal = row + col [left up = 0, right up = 7]
    // backslash diagonal = row + (n-1) - col [left up = 7, right up = 0]
    if(c >= n)
        return true;
    for(int i=0; i<n; i++){
        if(IsNQueenSafe(i, c, rows, ld, rd) == true){
            rows[i] = ld[i+c] = rd[i-c+n-1] = true;
            board[i][c] = 1;
            if(NQueen_BNB(board, c+1, rows, ld, rd) == true)
                return true;
            rows[i] = ld[i+c] = rd[i-c+n-1] = false;//backtracking, //remove if fail path
            board[i][c] = 0;//remove if fail path
        }
    }
    return false;
}

// Traveling Salesman
void CopyTravelingPath(vector<int>& cur_path, vector<int>& final_path){
    int n = cur_path.size() - 1;
    for(int i=0; i<n; i++)
        final_path[i] = cur_path[i];
    final_path[n] = cur_path[0];
}
int GetFirstMinCostFromVertex(vector<vector<int>>& adj, int i){
    int n = adj.size();
    int min_val = INT_MAX;
    for(int k=0; k<n; k++)
        if(adj[i][k] < min_val && i != k)
            min_val = adj[i][k];
    return min_val;
}
int GetSecondMinCostFromVertex(vector<vector<int>>& adj, int i){
    int n = adj.size();
    int first = INT_MAX, second = INT_MAX;
    for(int j=0; j<n; j++){
        if(i == j)
            continue;
        if(adj[i][j] <= first){
            second = first;
            first = adj[i][j];
        }
        else if(adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}
void TravelingSalesman_BNB_Calc(vector<vector<int>>& adj, int cur_bound, int cur_weight, int level, vector<int>& cur_path, vector<int>& final_path, vector<bool>& visited){
    int n = adj.size();
    if(level == n){// base case
        if(adj[cur_path[level-1]][cur_path[0]] != 0){// if last node is connected start node
            int cur_res = cur_weight + adj[cur_path[level-1]][cur_path[0]];// update total weight
            if(cur_res < final_path[n+1]){
                CopyTravelingPath(cur_path,final_path);//change path
                final_path[n+1] = cur_res;//update min cost
            }
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(adj[cur_path[level-1]][i] != 0 && visited[i] == false){// if we don't visit node
            int temp = cur_bound;
            cur_weight += adj[cur_path[level-1]][i];
            if(level == 1)
                cur_bound -= (GetFirstMinCostFromVertex(adj, cur_path[level-1])+GetFirstMinCostFromVertex(adj, i)) / 2;
            else
                cur_bound -= (GetSecondMinCostFromVertex(adj, cur_path[level-1]) + GetFirstMinCostFromVertex(adj, i)) / 2;
            if(cur_bound + cur_weight < final_path[n+1]){
                cur_path[level] = i;
                visited[i] = true;
                TravelingSalesman_BNB_Calc(adj, cur_bound, cur_weight, level+1, cur_path, final_path, visited);
            }
            cur_weight -= adj[cur_path[level-1]][i];
            cur_bound = temp;
            fill(visited.begin(), visited.end(), false);
            for(int j=0; j<= level-1; j++)
                visited[cur_path[j]] = true;
        }
    }
}
vector<int> TravelingSalesman_BNB(vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> cur_path(n+1, -1);
    int cur_bound = 0;
    vector<bool> visited(n, false);
    vector<int> final_path(n+2, 0);// final_path[n+1] = final_result(=min cost)
    final_path[n+1] = INT_MAX;
    for(int i=0; i<n; i++)
        cur_bound += GetFirstMinCostFromVertex(adj, i) + GetSecondMinCostFromVertex(adj, i);
    cur_bound = (cur_bound & 1) ? (cur_bound >> 1) + 1 : cur_bound >> 1;
    visited[0] = true;
    cur_path[0] = 0;
    TravelingSalesman_BNB_Calc(adj, cur_bound, 0, 1, cur_path, final_path, visited);
    return final_path;
}

// Traverling Salesman Using Reduced Matrix Method
const int travel_size = 4;
struct TravelNode{
    vector<pair<int, int>> path;
    int rmat[travel_size][travel_size];
    int cost, vertex, level;// cost: lower bound, vertex: cur city, level: number of visited city
};
TravelNode* CreateTravelNode(int mat[travel_size][travel_size], vector<pair<int,int>> const& path, int level, int i, int j){
    TravelNode* node = new TravelNode;
    node->path = path;
    if(level != 0)
        node->path.push_back({i, j});
    memcpy(node->rmat, mat, sizeof(node->rmat));
    for(int k=0; level != 0 && k < travel_size; k++){
        node->rmat[i][k] = INF;// set row to INF(by moving col)
        node->rmat[k][j] = INF;// set col to INF(by moving row)
    }
    node->rmat[j][0] = INF;
    node->level = level;
    node->vertex = j;
    return node;
}
int RowReduction(int rmat[travel_size][travel_size], int row[travel_size]){
    fill_n(row, travel_size, INF);
    for(int i=0; i<travel_size; i++)
        for(int j=0; j<travel_size; j++)
            if(rmat[i][j] < row[i])
                row[i] = rmat[i][j];// get min val of each row
    for(int i=0; i<travel_size; i++)
        for(int j=0; j<travel_size; j++)
            if(rmat[i][j] != INF && row[i] != INF)
                rmat[i][j] -= row[i];
    return 0;
}
int ColReduction(int rmat[travel_size][travel_size], int col[travel_size]){
    fill_n(col, travel_size, INF);
    for(int i=0; i<travel_size; i++)
        for(int j=0; j<travel_size; j++)
            if(rmat[i][j] < col[j])
                col[j] = rmat[i][j];//get min val of each col
    for(int i=0; i<travel_size; i++)
        for(int j=0; j<travel_size; j++)
            if(rmat[i][j] != INF && col[j] != INF)
                rmat[i][j] -= col[j];
    return 0;
}
int CalcTravelCost(int rmat[travel_size][travel_size]){
    int cost = 0;
    int row[travel_size];
    int col[travel_size];
    RowReduction(rmat, row);
    ColReduction(rmat, col);
    for(int i=0; i<travel_size; i++)
        cost += (row[i] != INF) ? row[i] : 0, cost += (col[i] != INF) ? col[i] : 0;
    return cost;
}
void PrintTravelPath(vector<pair<int,int>> const& list){
    for(int i=0; i<list.size(); i++)
        cout << list[i].first + 1 << "->" << list[i].second + 1 << endl;
}
struct Min_Heap{
    bool operator()(const TravelNode* l, const TravelNode* r) const{
        return l->cost > r->cost;
    }
};
int TravelSalesman_ReducedMatrix(int mat[travel_size][travel_size]){
    priority_queue<TravelNode*, vector<TravelNode*>, Min_Heap> pq;// cost sort by ascending order
    vector<pair<int, int>> v;
    TravelNode* root = CreateTravelNode(mat, v, 0, -1, 0);
    root->cost = CalcTravelCost(root->rmat);
    pq.push(root);
    while(!pq.empty()){
        TravelNode* min = pq.top();
        pq.pop();
        int i = min->vertex;
        if(min->level == travel_size - 1){
            min->path.push_back({i, 0});
            PrintTravelPath(min->path);
            return min->cost;
        }
        for(int j=0; j<travel_size; j++){
            if(min->rmat[i][j] != INF){
                TravelNode* child = CreateTravelNode(min->rmat, min->path, min->level + 1, i , j);
                child->cost = min->cost + min->rmat[i][j] + CalcTravelCost(child->rmat);
                pq.push(child);
            }
        }
        delete min;
    }
    return 0;
}


// Job Assignment Problem
const int job_num = 4;
struct JobNode{
    JobNode* parent;
    int pathCost, cost, workerID, jobID;// pathcost contain cost for ancestor node including cur node
    bool assigned[job_num];
};
JobNode* CreateJobNode(int x, int y, bool assigned[], JobNode* parent){
    int n = job_num;
    JobNode* node = new JobNode;
    for(int i=0; i<n; i++)
        node->assigned[i] = assigned[i];// origin code(not use vector): node->assigned[i] = assigned[i]
    node->assigned[y] = true;
    node->parent = parent;
    node->workerID = x;
    node->jobID = y;
    return node;
}
int CalcJobAssignCost(vector<vector<int>>& mat, int x, int y, bool assigned[]){
    // Calculate least cost of node after worker x is assigned to job y
    int cost = 0;
    int n = mat.size();
    vector<bool> available(n, true);
    for(int i=x+1; i<n; i++){
        int min_val = INT_MAX, min_idx = -1;
        for(int j=0; j<n; j++){
            if(!assigned[j] && available[j] && mat[i][j] < min_val){
                min_idx = j;
                min_val = mat[i][j];
            }
        }
        cost += min_val;
        available[min_idx] = false;
    }
    return cost;
}
struct CompareJobCost{
    bool operator()(const JobNode* l, const JobNode* r) const {
        return l->cost > r->cost;
    }
};
void PrintJobAssignment(JobNode* min){
    if(min->parent == NULL)
        return;
    PrintJobAssignment(min->parent);// recursive call until root node is reached
    cout << char(min->workerID + 'A') << ", " << min->jobID << endl;
}
int MinCostJobAssignment(vector<vector<int>>& mat){
    int n = mat.size();
    priority_queue<JobNode*, vector<JobNode*>, CompareJobCost> pq;//ascending order
    bool assigned[job_num] = {false};
    // Dummy Node
    JobNode* root = CreateJobNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;
    pq.push(root);
    while(!pq.empty()){
        JobNode* min = pq.top();
        pq.pop();
        int i = min->workerID + 1;// i is workerID
        if(i == n){
            PrintJobAssignment(min);
            return min->cost;
        }
        for(int j=0; j<n; j++){// j is jobID
            if(!min->assigned[j]){
                JobNode* child = CreateJobNode(i, j, min->assigned, min);
                child->pathCost = min->pathCost + mat[i][j];// min->pathCost is ancestor node, mat is cur node
                child->cost = child->pathCost + CalcJobAssignCost(mat, i, j, child->assigned);
                pq.push(child);
            }
        }
    }
}

// Generate Binary Strings of Length N
class BinaryStringNode{
public:
    int* sol;
    int level;
    vector<BinaryStringNode*> child;
    BinaryStringNode* parent;
    BinaryStringNode(BinaryStringNode* parent, int level, int n){
        this->parent = parent;
        this->level = level;
        this->sol = new int[n];
    }
};
void GenerateBinaryStringN(int &n){
    BinaryStringNode* root = new BinaryStringNode(NULL, 0, n);
    queue<BinaryStringNode*> q;
    q.push(root);
    while(!q.empty()){
        BinaryStringNode* cur = q.front();
        q.pop();
        if(cur->level == n){
            for(int i=0; i<n; i++)
                cout << cur->sol[i];
            cout << endl;
        }
        else{
            int l = cur->level;
            for(int i=0; i<=1; i++){// binary char consists of 0 and 1
                BinaryStringNode* next = new BinaryStringNode(cur, l+1, n);
                for(int k=0; k<l; k++)
                    next->sol[k] = cur->sol[k];
                next->sol[l] = i;// store 0 or 1 
                cur->child.push_back(next);
                q.push(next);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    int n = 3;
    GenerateBinaryStringN(n);
    return 0;
}



