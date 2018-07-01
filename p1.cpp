#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        int fron;
        void push(int x) {
            if(stack_oldest_on_top.size()==0)
            {
                stack_newest_on_top.push(x);
            }
            else
            {
                while(stack_oldest_on_top.size()!=0)
                {
                    stack_newest_on_top.push(stack_oldest_on_top.top());
                    stack_oldest_on_top.pop();
                }
                stack_newest_on_top.push(x);
            }
                   
        }

        void pop() {
            int i;
            if(stack_oldest_on_top.size()==0)
            {    
                while(stack_newest_on_top.size()!=0)
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            stack_oldest_on_top.pop();
            }
            else
            {
                stack_oldest_on_top.pop();
            }
        }

        int front() {
            int c;
            if(stack_newest_on_top.size()!=0)
            {
                c= get_element(stack_newest_on_top);
                return c;
            }
            else
            {
                return stack_oldest_on_top.top();
            }
                
        }
        int get_element(stack<int> a)
        {
            stack<int> display;
            while(a.size()!=0)
                {
                    display.push(a.top());
                    a.pop();
                }
            return display.top();
        }
       
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
