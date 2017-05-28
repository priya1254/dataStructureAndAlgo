#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    int n,q;
    cin>>n;
    while(n)
    {
        long ch;cin>>ch;
        pq.push(ch);n--;
    }
    cin>>q;
    int op;
    long x;
    while(q)
    {
        cin>>op;
        if(op == 1)
        {cin>>x;pq.push(x);}
        else
        cout<<pq.top()<<endl;
        q--;
    }
return(0);
}

