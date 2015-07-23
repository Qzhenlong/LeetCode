#include<iostream>
#include<stack>
using namespace std;
/*
��Ŀ��
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

��������·��������һ���ļ��ľ���·����Unix�������ؼ򻯺��·�������Ϊ/../��ʽ��·�����򷵻�/.
˼·����ʼû̫�������⣬��ʵ��linux·�������..��ʾ��һ��Ŀ¼��.��ʾ��ǰĿ¼�����Բ���
"/a/./b/../../c/" -> "/c",��ջ���߶�����ά������, ����..��ջ������.����

*/

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "", cur = "";
		stack<string > s;
		for(int i = 0; i < path.size(); i++){
			if(path[i] == '/'){
				if(cur == "" || cur == "."){
					cur = "";
					continue;
				}
				else{
					if(cur == ".." && !s.empty()) s.pop();
					else if(cur != "..") s.push(cur);
					cur = "";
				}
			}
			else cur += path[i];
			
		}
		if(cur != "" && cur != "."){
			if(cur == ".." && !s.empty()) s.pop();
			else if(cur != "..") s.push(cur);
		}	
		if(s.empty()) return "/";
		while(!s.empty()){
			ans = s.top() + ans;
			ans = "/" + ans;
			s.pop();
		}
		return ans;
    }
};

int main(){
	Solution c;
	cout << c.simplifyPath("/.");
	return 0;
}
