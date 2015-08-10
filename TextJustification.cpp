#include<iostream>
#include<vector>
using namespace std;
/*
题目：
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

解析：给定一个单词数组和一个长度L，将文本格式化（两端对齐），每个解包含恰好L个字符，且完全合理
	  通过一个贪心算法选取单词，尽可能多的选取单词，可通过增加额外的空格来填够L个字符
	  空格应该尽可能均匀的分布，如果不能均匀的分布，那么单词之间，左边的空格数多于右边的
	  最后一行必须是左对齐，不能有额外的空格插入在单词之间。
	  
	  保证每个单词的长度都不超过L

思路：合理分配每行的单词数，再插入空格
主要分情况判断。首先分两大类，末行和非末行；然后末行所有单词间放一个空格，最后面补充空格；非末行再分两类，
如果只有一个单词就靠左放，右边补空格；如果有多个单词，即计算有几个间隔num和几个多余的空格extra
（除每两个单词间一个空格外多余的），每个间隔再多方extra/num个，前extra%num个间隔再多放个空格。
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
            while (j < N && length + words[j].size() + (j-i) <= L) //每行达到L的字符，单词数加空格数
                length += words[j++].size();
            // build line
            string s(words[i]); //构建一行
            bool isLastLine = (j == N); //判断是否为最后一行，最后一行处理比较简单，其它复杂一点
            bool oneWord = (j == i + 1); //如果一行只有一个单词，那靠左放就行了
			
            int average = isLastLine || oneWord ? 1 : (L - length) / (j - i - 1); // 空格的均值，最后一行都只插入一个空格
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1); //多少个额外的空格
            for (int k = i + 1; k < j; ++k) {
                s.append(extra > 0 ? average + 1 : average, ' '); //如果有多余的空格，从左边开始挨个间隔都插入一个额外空格
                s.append(words[k]);
                extra--;
            }
            s.append(L - s.size(), ' '); //长度不足则补充空格即可
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
