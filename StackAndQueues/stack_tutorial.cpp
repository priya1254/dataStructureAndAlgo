#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    stack<long> s;
    cin>>q;
    long ch,cost;
    while(q)
    {
	    cin>>ch;
	    if(ch == 1)
	    {
	    	if(s.empty())cout<<"No Food"<<endl;
	    	else{
	    	cout<<s.top()<<endl;
	    	s.pop();
	    	}
	    }
	    else
	    {
		    cin>>cost;
		    s.push(cost);
	    }
	    q--;
   }
return(0);
}
