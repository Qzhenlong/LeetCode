#inlcude<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a string of numbers and operators, return all possible results from computing all the different possible ways 
to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

解析：给定一个包含数字和+，-，*的字符串，可任意加入括号，返回所有可能的结果

思路: 没想出来，附上大神答案，http://www.cnblogs.com/ganganloveu/p/4681439.html
与Unique Binary Search Trees II思路类似，可以对照看。
左右子串分别计算所有可能，然后全排列。

*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for(int i = 0; i < input.size(); i ++)
        {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(int j = 0; j < left.size(); j ++)
                {
                    for(int k = 0; k < right.size(); k ++)
                    {
                        if(input[i] == '+')
                            ret.push_back(left[j] + right[k]);
                        else if(input[i] == '-')
                            ret.push_back(left[j] - right[k]);
                        else
                            ret.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if(ret.empty())
            ret.push_back(atoi(input.c_str()));
        return ret;
    }
};