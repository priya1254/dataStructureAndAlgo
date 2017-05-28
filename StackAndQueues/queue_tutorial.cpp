//wap to implement a queue
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    queue<long> s;
    cin>>q;
    char ch;
    long cost;
    while(q)
    {
	    cin>>ch;
	    if(ch == 'D')
	    {
	    	if(s.empty())cout<<"-1 0"<<endl;
	    	else{

	    	cout<<s.front()<<" ";
	    	s.pop();
	    	cout<<s.size()<<endl;

	    	}
	    }
	    else
	    {
		    cin>>cost;
		    s.push(cost);
		    cout<<s.size()<<endl;
	    }
	    q--;
   }
return(0);
}

