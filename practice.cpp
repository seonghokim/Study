#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void EvenOddCompare(int n);
void SumOfEachEvenOddNum(int n);
void CheckLargestNum(int n1, int n2, int n3);
void Swap(int* a, int* b);
int SumOfDigits(int n, char* str, int mode);
int FindMaxAmongSameDigitsNum(int n);
void NumVowelsNConsonants(char* str);
bool CheckPrimeNum(int n);
bool CheckPerfectNum(int n);
bool CheckStrongNum(int n);
bool CheckArmstrongNum(int n);
long ReverseNum(long n);
bool CheckPalindrome(int n);
long AddBinaryNum(long n1, long n2);


int main(void){
    int input;
    int input1, input2, input3;
    char i_str[100];
    int result1=0, result2=0;
    bool state1, state2, state3;
    long linput1, linput2;
    long lresult1;
    //printf("Enter 1 number: ");
    //scanf("%d",&input);
    printf("Enter 2 number: ");
    scanf("%ld %ld",&linput1, &linput2);
    //printf("Enter string: ");
    //scanf("%[^\n]s",i_str);
    
    //EvenOddCompare(input); // 1
    //SumOfEachEvenOddNum(input); // 2
    //scanf("%d %d %d",&input1, &input2, &input3); // 3
    //CheckLargestNum(input1,input2,input3); // 3
    //scanf("%d %d", &input1, &input2);
    //Swap(&input1, &input2);
    //result1 = SumOfDigits(input,NULL, 0);
    //result2 = SumOfDigits(0, i_str, 2);
    //printf("result: %d, result: %d\n", result1, result2);
    //result1 = FindMaxAmongSameDigitsNum(input);
    //printf("result: %d\n",result1);
    //NumVowelsNConsonants(i_str);
    //state1 = CheckPrimeNum(input);
    //state2 = CheckPerfectNum(input);
    //state3 = CheckStrongNum(input);
    //printf("prime %d perfect %d stroing %d\n", state1, state2, state3);
    //state1 = CheckArmstrongNum(input);
    //printf("armstrongnum %d \n", state1);
    //result1 = ReverseNum(input);
    //state1 = CheckPalindrome(input);
    //printf("reversed num %d is palindrome %d \n", result1, state1);
    lresult1 = AddBinaryNum(linput1, linput2);
    printf("Binarynum: %ld\n", lresult1);
    return 0;
}


void EvenOddCompare(int n){
     if(n%2==0)// (n&1 == 1) is using bitwise operator 
        printf("%d is even number\n", n);
    else
        printf("%d is odd number\n", n);
}
void SumOfEachEvenOddNum(int n){
    int i;
    int sum_even = 0;
    int sum_odd = 0;

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
void CheckLargestNum(int n1, int n2, int n3)
{
    int temp = (n1>n2) ? (n1>n3 ? n1 : n3) : (n2>n3 ? n2 : n3);
    printf("Largest number among 3 numbers is %d\n", temp);
}
void Swap(int* a, int* b)
{
    printf("Num A: %d, Num B: %d is swaped.\n", *a, *b);
    // Native approach
    int temp;
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
int SumOfDigits(int n, char* str, int mode)
{
    // Mode 0 isn't recursive, Mode 1 is recursive
    // Mode 2 is string version
    if(mode == 0){// Not recursive
        int sum1 = 0;
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
        int i;
        int sum2 = 0;
        int len = strlen(str);

        for(i=0 ; i<len ; i++){
            if(str[i] >= '0' && str[i] <= '9')
                sum2 += (str[i]-'0');
        }
        printf("Sum2 of Digits = %d\n", sum2);
        return sum2;
    }

    return -1;// Error
}
int FindMaxAmongSameDigitsNum(int n)
{
    int temp[20]={0,};
    int i=0;
    int len = 0;
    int maxValue = 0;
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
    int i = 0;
    int num_vowel = 0;
    int num_consonant = 0;
    int num_special = 0;
    
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
bool CheckPrimeNum(int n)
{
    int i;
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
bool CheckPerfectNum(int n)
{
    int i;
    int sum = 0;
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
bool CheckStrongNum(int n)
{
    int i;
    int temp;
    int multiple;
    int sum = 0;
    int org = n;
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
bool CheckArmstrongNum(int n)
{
    int i;
    int sum = 0;
    int count_digits = 0;
    int temp = n;
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
bool CheckPalindrome(int n)
{
    int revNum = ReverseNum(n);
    if(n == revNum)
        return true;
    else
        return false;
}
long AddBinaryNum(long n1, long n2)
{
    long temp = n1 + n2;
    long lsb_bit = 0;
    int i = 0, j = 0;
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


