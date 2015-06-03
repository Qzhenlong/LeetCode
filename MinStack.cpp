#include <iostream>
#include <vector>
#include <string> 
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
         st.push(x);
         if(st_min.empty() || x <= st_min.top()) st_min.push(x);
    }

    void pop() {
        int top = st.top();
        st.pop();
        if(top <= st_min.top()) st_min.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st_min.top();
    }
private:
    stack<int > st;
    stack<int > st_min;
};
int main()
{
  MinStack ms;
  ms.push(1);
  ms.push(4);
  ms.push(6);
  ms.push(3);
  cout << ms.top() << endl;
  cout << ms.getMin() << endl;
  while(1);
  return 1;   
}
