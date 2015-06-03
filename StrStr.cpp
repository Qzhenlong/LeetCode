#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) { //Brute-Force 
        int i=0, j=0;
        if(needle.size()==0) return 0;   //注意边界情况 
        while(i < haystack.size() && j < needle.size())
        {
                if(haystack[i] == needle[j]){ i++; j++;}
                else{ i = i-j+1; j=0; } //注意对i变换完成再变换j 
                
                if(j == needle.size()) return (i-j);
        }
        return -1;
    }
    void getNext(string needle, int next[]) //递推求Next数组 
    {
         int j = 0, k = -1;
         next[0] = -1;
         while(j < needle.size()-1)
         {
                 if(k == -1 || needle[j] == needle[k]){ j++; k++; next[j] = k;} //next[j] = next[j-1] + 1 = k; 
                 else k = next[k];
         }
    }
    void getNext1(string needle, int next[]) //非递推求Next数组
    {
         for(int i = 0; i < needle.size(); i++)
         {
                 if(i == 0) next[i] = -1;
                 else if(i == 1) next[i] = 0;
                 else{
                      for(int j = i-1; j > 0; j--)
                      {
                              int k = 0, l = i-j;
                              for(; k < j && l < i; k++,l++)
                              {
                                      if(needle[k] != needle[l]) break;
                              }
                              if(k == j || l == i){ next[i] = k; break;}
                              else next[i] = 0;
                      }
                 }
         }
    } 
    void getNextval(string needle, int next[]) //求Next数组的优化算法
    {
         int j = 0, k = -1;
         next[0] = -1;
         while(j < needle.size())
         {
                 if(k == -1 || needle[j] == needle[k]){ 
                      j++; k++;
                      if(needle[j] != needle[k]) next[j] = k;
                      else next[j] = next[k];
                      }
                 else k = next[k];
         } 
    } 
    int strStr1(string haystack, string needle) { //KMP 
        int i = 0, j = 0; 
        int MAX=65535;
        int n1 = haystack.size(), n2 = needle.size();
        if(needle.size()==0) return 0;
        int next[MAX];
        getNext1(needle, next);
        //for(int k = 0; k < 10; k++) cout << next[k] << " ";
        while(i < n1 && j < n2)
        {
                if(j == -1 || haystack[i] == needle[j]){i++; j++;}
                else j = next[j]; 
                //cout << needle.size() << endl;
               if(j == needle.size())
                             return i-j; 
        } 
        if(j >= needle.size()) return i - needle.size();
        return -1;
    }
};
int main()
{
  Solution c;
  string s = "aaaaaaaa";
  string t = "aaa";
  cout << c.strStr1(s,t)<< endl;
  while(1);
  return 1;   
}
