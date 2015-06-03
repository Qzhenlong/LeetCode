#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1,n2,i=0;
        int v1[version1.size()];
        int v2[version2.size()];
        n1 = getVersion(v1,version1);
        n2 = getVersion(v2,version2);
        while(i < n1 && i < n2){
                if(v1[i] > v2[i]) return 1;
                if(v1[i] < v2[i]) return -1;
                i++;
        }
        while(i < n1){   //¿ÉÄÜ1Óë1.0 
                if(v1[i] != 0) return 1;
                i++;
        }
        while(i < n2){
                if(v2[i] != 0) return -1;
                i++;
        }
        return 0;
    }
    int getVersion(int v[], string version)
    {
        int s = 0,c = 0;
        char vc[version.size()];
        for(int i = 0; i < version.size(); i++)
        {
                if(version[i] != '.'){
                                vc[c] = version[i];
                                c++;
                                }
                if(version[i] == '.' || i == version.size()-1){
                                 vc[c] = '\0';
                                 v[s] = atoi(vc);
                                 c = 0;
                                 s++;              
                }
        }
        return s; 
     }
};
int main()
{
  Solution c;
  string v1 = "1", v2 = "1.0";
  cout << c.compareVersion(v1,v2) << endl;
  while(1);
  return 1;   
}

