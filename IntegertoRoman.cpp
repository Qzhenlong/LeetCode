#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/* Roman Number
1����ͬ��������д������ʾ����������Щ������ӵõ��������磺�� = 3��
2��С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ������� �磺�� = 8���� = 12��
3��С�����֣������ڢ�X ��C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ��������磺��= 4����= 9��
4������ʹ��ʱ����д�������ظ����ó������Ρ��������ϵ��ĵ��ӡ�IIII�����⣩
5����������û�и��� 
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
