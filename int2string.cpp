#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

string int2string(int number)
{
       string s1,s2;
       s1 = "";
       int tmp = abs(number);
       
       while(tmp){
                     s1 += (tmp%10+'0');
                     tmp /= 10;
       }
       
       s2 = "";
       if(number == 0) s2 = "0";
       if(number < 0) s2 += '-';
       for(int i = s1.size()-1; i >= 0; i--) 
               s2 += s1[i];
       return s2;
}

int string2int(string s)
{
    int number = 0;
    int symbol = 0;
    for(int i = 0; i < s.size(); i++)
    {
            if(s[i] == '-'){ symbol = 1; continue;}
            number = number*10 + (s[i]-'0');
    }
    if(symbol) return -number;
    return number;
}

int main()
{
  cout<< int2string(1534236469) << endl;
  cout<< string2int("-200") << endl;
  while(1);
 
  return 1;   
}
