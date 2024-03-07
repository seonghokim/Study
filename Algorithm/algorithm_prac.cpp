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

//----------------------- BackTracking --------------------

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

//----------------------- Greedy --------------------

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
int X[] = {-1, 0, 0, 1};
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
void MultiplyMaxtirx(int f[2][2], int m[2][2]){
    int x = f[0][0] * m[0][0] + f[0][1] * m[1][0];
    int y = f[0][0] * m[0][1] + f[0][1] * m[1][1];
    int z = f[1][0] * m[0][0] + f[1][1] * m[1][0];
    int w = f[1][0] * m[0][1] + f[1][1] * m[1][1];
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = w;
}
void Power(int f[2][2], int n){
    if(n==0 || n==1)
        return;
    int m[2][2] = {{1, 1}, {1, 0}};
    Power(f, n/2);
    MultiplyMaxtirx(f, f);
    if(n%2 != 0)
        MultiplyMaxtirx(f, m);
}
int Finonacci_PowerOfMatrix(int n){// O(log n)
    int f[2][2] = {{1, 1}, {1, 0}};
    if(n == 0)
        return 0;
    Power(f, n-1);
    return f[0][0];
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
int CutRod_UnboundedKnap(vector<int>& price, int n)

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    int index = n-1;
    cout << CutRod_BottomUp(price, n) << " ";
    return 0;
}



