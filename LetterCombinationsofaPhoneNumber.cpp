#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
Ë¼Â·£º
  
*/
class Solution {
public:
    vector<string > letterCombinations(string digits) {
        string letter[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string > ans;
		if(digits.size() == 0) return ans;
		ans.push_back("");
		int cn = 1;
		for(int i = 0; i < digits.size(); i++)
		{
			int t = digits[i]-'0', k = 0;
			vector<string > cur;
			if(t == 1) continue;
			for(int j = 0; j < cn; j++)
				for(int k = 0; k < letter[t].size(); k++)
					cur.push_back(ans[j] + letter[t][k]);
			ans.clear();
			ans = cur;
			cur.clear();
			cn *= letter[t].size();
		}
		return ans;
    }
};

int main()
{
	Solution c;
	string s = "9";
	vector<string > ans = c.letterCombinations(s);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " | ";
	return 0;
}
