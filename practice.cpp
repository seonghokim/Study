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

int main(void){
    int input;
    int input1, input2, input3;
    char i_str[100];
    int result1=0, result2=0;
    //printf("Enter 1 number: ");
    //scanf("%d",&input);

    printf("Enter string: ");
    scanf("%[^\n]s",i_str);
    
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
    NumVowelsNConsonants(i_str);
    
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
int CheckPrimeNum(int n)
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
// Writing Function CheckPrimeNum(...)









