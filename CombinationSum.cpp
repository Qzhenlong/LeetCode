#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目描述：给定一个集合C和一个数字T，在集合C中找出所有子集合，子集合的所有数之和等于T，子集合都升序排列。
我的思路：
*/
class Solution {
public:
	vector<vector<int > > combinationSum1(vector<int > &candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());
		vector<int > intermediate;
		vector<vector<int > > result;
		vector<int > indices;
		for (size_t i = 0; i < candidates.size(); ) 
		{
			if(target <= candidates[i])
			{
				//找到结果，保存，但是不入栈
				if (target == candidates[i])
				{
					intermediate.push_back(candidates[i]);
					result.push_back(intermediate);
					intermediate.pop_back();
				}
				//注意：特殊情况-没有解或一个解，数字最小的值都大于等于target
				if(intermediate.empty()) return result;
				i = indices.back()+1;
				//注意：别忘了target也要恢复上一层的数值
				target += intermediate.back();
				intermediate.pop_back();  // 本层改数值不符合规定，或者已经找到了答案
				indices.pop_back();
				
				while (i == candidates.size())
				{//别忘了这个情况
					//注意：都需要判断空栈的时候返回值
					if(intermediate.empty()) return result;
					i = indices.back()+1;
					target += intermediate.back();
					intermediate.pop_back();  
					indices.pop_back();
				}
			}
			else 
			{
				intermediate.push_back(candidates[i]);
				indices.push_back(i);
				target -= candidates[i];
			}
		}
		return result;
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > result; // 最终结果
		vector<int> intermediate; // 中间结果
		dfs(candidates, target, 0, intermediate, result);
		return result;
	}
	private:
	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate, vector<vector<int> > &result) {
		if (gap == 0) { // 找到一个合法解
			result.push_back(intermediate);
			return;
		}
		for (size_t i = start; i < nums.size(); i++) { // 扩展状态
			if (gap < nums[i]) return; // 剪枝
			intermediate.push_back(nums[i]); // 执行扩展动作
			dfs(nums, gap - nums[i], i, intermediate, result);
			intermediate.pop_back(); // 撤销动作
		}
	}
};

int main()
{
	return 0;
}
