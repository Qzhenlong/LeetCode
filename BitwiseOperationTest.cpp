#include<stdio.h>
#include<iostream>
using namespace std;
unsigned int oct2dec(unsigned int oct) //8����ת����10���ƣ���ֻ����λ 
{
         return oct/10*8 + oct%10;
         } 

int main()
{
    unsigned short int i = 0;
    printf("%f\n",5);
    printf("%d\n",5.01);
    printf("%d\n", oct2dec(90));
    printf("%d\n", --i);
    cout << --i << endl;
    //
    while(1);
    return 1;
} 
