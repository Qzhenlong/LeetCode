#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;
/*
原题：
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".

解析：给定两个二进制字符串，返回相加结果
思路：考虑上一位的进位，某位的相加情况有0，1，2，3，对各情况考虑在内即可
*/
class Solution {
public:
    string addBinary(string a, string b) {
        long ai = 0, bi = 0, ansi;
        string ans = "";
        if(a.size() == 0 && b.size() == 0) return "0";
        for(int i = 0; i < a.size(); i++) ai = ai * 2 + (a[i]-'0');
        for(int i = 0; i < b.size(); i++) bi = bi * 2 + (b[i]-'0');
        cout << ai << " " << bi <<endl;
        ansi = ai + bi;
        if(ansi == 0) return  "0";
        while(ansi)
        {
                   ans += (ansi%2 + '0');
                   ansi /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
       string addBinary1(string a, string b) {
        string ans = "";
        char c = '0'; //进位
        if(a.size() == 0 && b.size() == 0) return "0";
        if(a.size() == 0 || a == "0") return b;
        if(b.size() == 0 || b == "0") return a;
        int i = a.size()-1, j = b.size()-1;
        while(i >= 0 && j >= 0)
        {
            int cur = (a[i]-'0') + (b[j]-'0') + (c-'0');
            if(cur <= 1){ ans += (cur+'0'); c = '0';}
            else if(cur == 2){ ans += '0'; c = '1';}
            else if(cur == 3){ ans += '1'; c = '1';}
            i--; j--;
        } 
        while(i >= 0)
        {
             int cur = (a[i]-'0') + (c-'0');
            if(cur == 2){ ans += '0'; c = '1';}
            else { ans += (cur+'0'); c = '0';}
            i--;
        }
        while(j >= 0)
        {
            int cur = (b[j]-'0') + (c-'0');
            if(cur == 2){ ans += '0'; c = '1';}
            else { ans += (cur+'0'); c = '0';}
            j--;
        }       
        if(c == '1') ans += '1';
        reverse(ans.begin(), ans.end());     
        return ans;
    }
};
int main()
{
  Solution c;
  string a = "1111111111111111111111111111111111111111111", b = "1";
  cout << c.addBinary1(a,b)<< endl;
  while(1);
  return 1;   
}

