#include<iostream>
#include<stack>
using namespace std;
/*
题目：
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

解析：简化路径，给定一个文件的绝对路径（Unix），返回简化后的路径，如果为/../形式的路径，则返回/.
思路：开始没太看懂题意，其实是linux路径的命令，..表示上一级目录，.表示当前目录，所以才有
"/a/./b/../../c/" -> "/c",用栈或者队列来维护即可, 遇到..出栈，遇到.跳过

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
