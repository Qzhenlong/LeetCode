#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument,
 please click the reload button  to reset your code definition.
 
����������һ���ַ������ж����Ƿ�Ϊ��Ч����
 
˼·��LeetCode��ͨ������͵�һ�⣬Ҫ���ǵ�����Ƚ϶�
 a.�Ƿ����룬�ַ���ͷβ�Ŀո���Ժ��ԣ���������пո����Ȼ���Ϸ�, 
 b. �����֣�e��E�ǺϷ��ģ���ѧ������e��ǰ��e������Գ��ַ��ţ����ǲ����ж��e
 c. �ദС����, ���Ϸ�
 d. ����
 c. ��������
 
*/

class Solution {
public:
    bool isNumber(string s) {
		const char *ss = s.c_str();
		return isValid(ss);
    }
	bool isValid(const char *s){
        while (*s == ' ') ++s; //������ʼ�ո�
        while (*s == '+' || *s == '-') ++s; //������ʼ������
        bool exp = false, space = false, point = false;
        bool number = false;
        while (*s != '\0') {
            if (isdigit(*s)) { 
                if (space) return false; //�����м���ֿո񣬲��Ϸ�
                else number = true; 
            } else if (*s == '.') { //С����
                if (!point && !space && !exp) { //��С���㣬�����ǿո񣬲���֮ǰ�й�С���㣬��ѧ������e���治�ܳ���С����
                    point = true;
                } else {
                    return false;
                }
            } else if (*s == 'e') { //��ѧ������
                if (!exp && number && !space) { //��ѧ����������������e������ǰ�������֣������пո�
                    exp = true;
                    number = false; //��ѧ��������������������ж�
                    while (*(s+1) == '+' || *(s+1) == '-') ++s; //��ѧ��������������з���
                } else {
                    return false;
                }
            } else if (*s == ' ') { //�ո�
                if (!space) { //�п��������Ŀո�ֻ���м�Ŀո�����
                    space = true;
                }
            } else { //֮ǰ�Ѿ��пո��ˣ��ֳ��ֿո��Ȼ���Ϸ�
                return false;
            }
            ++s;
        }
        return number;  
	}
};

int main(){
	Solution c;
	cout << c.isNumber("  +++3.0");
	return 0;
}
