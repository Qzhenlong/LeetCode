#include<iostream>
using namespace std;
//��1-N�У�5�ı�������Ϊ|_N/5_|��|_ _|��ʾȡ��������
//��1-N�У�25�ı�������Ϊ|_N/25_|.��Ҫע�⵽����|_N/5_|�Ѿ�������|_N/25_|����25�ı���������2�����Կ��ǵ������ظ����㣬��N!�������ֽ���5��ָ��jΪ��
//j = |_N/5_|+|_N/25_|+|_N/5^3_|+...

class Solution{
      public:
      int trailingZeroes(int n) {
    /**    int zero=0; //���ӶȲ�����Ҫ�� 
        int i=5;
        while(i<=n)
        {
            zero+=n/i;
            i*=5;
        }
        return zero;
        */
        int ret = 0; //ʱ�临�Ӷ�Ϊlog(n) 
        while(n)
        {
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
      
};

int main()
{
  Solution c;
  int n = 5;
  cout << c.trailingZeroes(n) <<endl;
  while(1);
  return 1;   
}
