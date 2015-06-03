#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int len = 0;
        //if(n == 1) return s;
        for(int i = 0; i < n-1; i++)
        {
                string tmp = "";
                string cur = s.substr(0,1);
                len = 1;
                for(int j = 1; j < s.size(); j++)
                {
                    if(cur == s.substr(j,1)) len++;
                    else{
                         tmp += (int2string(len) + cur); 
                         cur = s.substr(j,1); 
                         len = 1;
                    }   
                }  
                tmp += (int2string(len) + cur);                
                s = tmp;
                //cout << s << endl;
        }
        return s;
    }
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
};
int main()
{
  Solution c;
  cout << c.countAndSay(3)<< endl;
  while(1);
  return 1;   
}
