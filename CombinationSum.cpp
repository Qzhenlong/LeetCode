#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ����������һ������C��һ������T���ڼ���C���ҳ������Ӽ��ϣ��Ӽ��ϵ�������֮�͵���T���Ӽ��϶��������С�
�ҵ�˼·��
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
				//�ҵ���������棬���ǲ���ջ
				if (target == candidates[i])
				{
					intermediate.push_back(candidates[i]);
					result.push_back(intermediate);
					intermediate.pop_back();
				}
				//ע�⣺�������-û�н��һ���⣬������С��ֵ�����ڵ���target
				if(intermediate.empty()) return result;
				i = indices.back()+1;
				//ע�⣺������targetҲҪ�ָ���һ�����ֵ
				target += intermediate.back();
				intermediate.pop_back();  // �������ֵ�����Ϲ涨�������Ѿ��ҵ��˴�
				indices.pop_back();
				
				while (i == candidates.size())
				{//������������
					//ע�⣺����Ҫ�жϿ�ջ��ʱ�򷵻�ֵ
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
		vector<vector<int> > result; // ���ս��
		vector<int> intermediate; // �м���
		dfs(candidates, target, 0, intermediate, result);
		return result;
	}
	private:
	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate, vector<vector<int> > &result) {
		if (gap == 0) { // �ҵ�һ���Ϸ���
			result.push_back(intermediate);
			return;
		}
		for (size_t i = start; i < nums.size(); i++) { // ��չ״̬
			if (gap < nums[i]) return; // ��֦
			intermediate.push_back(nums[i]); // ִ����չ����
			dfs(nums, gap - nums[i], i, intermediate, result);
			intermediate.pop_back(); // ��������
		}
	}
};

int main()
{
	return 0;
}
