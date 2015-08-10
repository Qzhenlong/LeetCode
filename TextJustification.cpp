#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary

 so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, 

the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

����������һ�����������һ������L�����ı���ʽ�������˶��룩��ÿ�������ǡ��L���ַ�������ȫ����
	  ͨ��һ��̰���㷨ѡȡ���ʣ������ܶ��ѡȡ���ʣ���ͨ�����Ӷ���Ŀո����L���ַ�
	  �ո�Ӧ�þ����ܾ��ȵķֲ���������ܾ��ȵķֲ�����ô����֮�䣬��ߵĿո��������ұߵ�
	  ���һ�б���������룬�����ж���Ŀո�����ڵ���֮�䡣
	  
	  ��֤ÿ�����ʵĳ��ȶ�������L

˼·���������ÿ�еĵ��������ٲ���ո�
��Ҫ������жϡ����ȷ������࣬ĩ�кͷ�ĩ�У�Ȼ��ĩ�����е��ʼ��һ���ո�����油��ո񣻷�ĩ���ٷ����࣬
���ֻ��һ�����ʾͿ���ţ��ұ߲��ո�����ж�����ʣ��������м������num�ͼ�������Ŀո�extra
����ÿ�������ʼ�һ���ո������ģ���ÿ������ٶ෽extra/num����ǰextra%num������ٶ�Ÿ��ո�
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> res;
        int i = 0, N = words.size(), L = maxWidth;
        while (i < N)
        {
            int length = words[i].size();
            int j = i + 1;
            while (j < N && length + words[j].size() + (j-i) <= L) //ÿ�дﵽL���ַ����������ӿո���
                length += words[j++].size();
            // build line
            string s(words[i]); //����һ��
            bool isLastLine = (j == N); //�ж��Ƿ�Ϊ���һ�У����һ�д���Ƚϼ򵥣���������һ��
            bool oneWord = (j == i + 1); //���һ��ֻ��һ�����ʣ��ǿ���ž�����
			
            int average = isLastLine || oneWord ? 1 : (L - length) / (j - i - 1); // �ո�ľ�ֵ�����һ�ж�ֻ����һ���ո�
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1); //���ٸ�����Ŀո�
            for (int k = i + 1; k < j; ++k) {
                s.append(extra > 0 ? average + 1 : average, ' '); //����ж���Ŀո񣬴���߿�ʼ�������������һ������ո�
                s.append(words[k]);
                extra--;
            }
            s.append(L - s.size(), ' '); //���Ȳ����򲹳�ո񼴿�
            // push line
            res.push_back(s);
            i = j;
        }
        return res;       
    }
};

int main(){
	Solution c;
	string s[] = {"This", "is", "an", "example", "of", "text", "justification."};
	vector<string > words;
	for(int i = 0; i < 7; ++i) words.push_back(s[i]);
	vector<string > ans = c.fullJustify(words, 16);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
	return 0;
}
