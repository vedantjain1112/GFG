//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
     Solution() {
        minEle = -1;
    }

    int getMin() {
        if (s.empty()) {
            return -1; 
        }
        return minEle;
    }

    int pop() {
        if (s.empty()) {
            return -1; 
        }

        int poppedElement = s.top();
        s.pop();

        if (poppedElement < minEle) {
            int newMin = 2 * minEle - poppedElement;
            poppedElement = minEle;
            minEle = newMin;
        }

        return poppedElement;
    }

    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        } else {
            if (x < minEle) {
                s.push(2 * x - minEle);
                minEle = x;
            } else {
                s.push(x);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends