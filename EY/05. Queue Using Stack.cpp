//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> s1, s2;
public:

    void enqueue(int x) {
        
        while(s1.size()!=0){
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        
        s1.push(x);
        
        while(s2.size()!=0){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if(s1.size()==0) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends
