#include <iostream>
#include <vector>
#include <map>
//#include <hash_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> IntMap;
        int major;
        for(int i = 0; i < num.size(); i++) IntMap[num[i]] = 0;
        for(int i = 0; i < num.size(); i++) IntMap[num[i]]++;
        for(int i = 0; i < num.size(); i++)
                if(IntMap[num[i]] > num.size()/2){ 
                             major = num[i];
                             break;
                             }
        return major;
    }
};
int main()
{
  Solution c;
  int el[] = {1,1,1,2,5,5,5,5,5};
  int n = 9;
  vector<int > num;
  for(int i = 0; i < n; i++) num.push_back(el[i]);
  printf("%d", c.majorityElement(num));
  while(1);
  return 1;   
}
