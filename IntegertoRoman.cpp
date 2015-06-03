#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/* Roman Number
1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
4、正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
5、罗马数字没有负数 
*/
class Solution {
public:
   string intToRoman(int num) {
        string roman[][10] = {  
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
            {"", "M", "MM", "MMM",  "",   "",  "",    "",   "",     "",}  
        };  
          
        string ans = "";  
        int digit = 0;  
        while (num != 0) {  
            int remain = num % 10;  
            ans = roman[digit][remain] + ans;  
            digit++;  
            num /= 10;  
        }  
          
        return ans;
    }
};
int main()
{
  Solution c;
  cout << c.intToRoman(3999) << endl;
  while(1);
  return 1;   
}
