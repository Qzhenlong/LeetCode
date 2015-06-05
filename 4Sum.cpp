#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
ԭ�⣺
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a �� b �� c �� d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
�������ҳ��������ĸ���֮�͵���target���������У����е�����
˼·1����3Sum��˼·���ƣ�����һ����ϣ�ݴ��������ĺͣ����ڴ���һ�Զ�Ĺ�ϵ�����Ҫʹ��multimap�������ʱ
˼·2: ��3Sum��˼·���ƣ���һ��ѭ�������м�б�
*/

class Solution {
public:
	//��ʱ������������STL����
    vector<vector<int > > fourSum(vector<int >& nums, int target) {
		vector<vector<int > > ans;
		if(nums.size() < 4) return ans;
		sort(nums.begin(), nums.end()); //��������
		
        multimap<int, pair<int, int> > hm;
		//map<vector<int >, int > ad; //ȥ��
		for(int i = 0; i < nums.size(); i++)
			for(int j = i+1; j < nums.size(); j++)
				hm.insert(make_pair(nums[i]+nums[j], make_pair(i,j)));
		
		for(multimap<int, pair<int, int> >::iterator it = hm.begin(); it != hm.end(); it++){
			int bound = target - it->first;
			pair<multimap<int, pair<int, int> >::iterator, multimap<int, pair<int, int> >::iterator> tmp = hm.equal_range(bound); //equal_range()����ָ��Ԫ�ص�keyΪָ��ֵ�ĵ�������
			for(multimap<int, pair<int, int> >::iterator j = tmp.first; j != tmp.second; j++){ //���е���bound�����
				int a = it->second.first;
				int b = it->second.second;
				int c = j->second.first;
				int d = j->second.second;
				if(a != c && a != d && b != c && b != d){ //�������
					vector<int > cur; 
					cur.push_back(nums[a]); cur.push_back(nums[b]);
					cur.push_back(nums[c]); cur.push_back(nums[d]); 
					sort(cur.begin(), cur.end());
					ans.push_back(cur);
					/*if(ad.find(cur) == ad.end()){
						ans.push_back(cur);
						ad[cur] = 1;
					}*/
				}
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
    }
	//ͨ������һ�㻹�ǲ��üбƷ���
	vector<vector<int > > fourSum1(vector<int >& nums, int target){
        vector<vector<int > > ans;
		if(nums.size() < 4) return ans;
		sort(nums.begin(), nums.end());
		for(int x = 0; x < nums.size()-3; x++){
			for(int i = x+1; i < nums.size()-2; i++){
				int j = i+1, k = nums.size()-1;
				while(j < k)
				{
					if((nums[x] + nums[i] + nums[j] + nums[k]) < target) j++;
					else if((nums[x] + nums[i] + nums[j] + nums[k]) > target) k--;
					else{
						//ans.push_back({ nums[x], nums[i], nums[j], nums[k] });
						vector<int > cur;
						cur.push_back(nums[x]); cur.push_back(nums[i]); cur.push_back(nums[j]); cur.push_back(nums[k]); 
						ans.push_back(cur);
						j++; k--;
						while(j < k && nums[j] == nums[j-1]) j++; //����nums������ģ����Խ���������Ԫ���Ƿ��ظ�����
						while(j < k && nums[k] == nums[k+1]) k--; 
					}
				}
				while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
			}
			while(x < nums.size()-3 && nums[x] == nums[x+1]) x++;
		}
		return ans;	
	}
};

int main(){
	Solution c;
	int A[] = {1, 0, -1, 0, -2, 2};
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<vector<int > > ans = c.fourSum1(num,0);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
