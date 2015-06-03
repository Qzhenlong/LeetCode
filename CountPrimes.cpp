#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
       /* int c = 0;
        for(int i = 1; i < n; i++)
                if(isPrime(i)) c++;
        return c;
        */
        return Eeatosthese(n);
    }
    
    int Eeatosthese(int N)
    {
      int i, j, a[N];
      int c = 0;
      for (i = 2; i < N; i++) a[i] = 1;
      for (i = 2; i < N; i++)
        if (a[i])
          for (j = i+i; j < N; j += i) 
            a[j] = 0;
     
      for (i = 2; i < N; i++)
        if (a[i]) c++;
        return c;
    }
    bool isPrime(unsigned long n) {    
     if (n <= 3) {        return n > 1;    } 
     else if (n % 2 == 0 || n % 3 == 0) {        return false;    }
      else {        
           for (unsigned short i = 5; i * i <= n; i += 6) 
                      if (n % i == 0 || n % (i + 2) == 0) return false; 
                 
        return true; 
       }
}
};
int main()
{
  Solution c;
  cout << c.countPrimes(5)<< endl;
  while(1);
  return 1;   
}
