#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    map<long,string> m;
    cin>>q;
    string ch;
    long roll;
    while(q)
    {
    	cin>>roll;
	    cin>>ch;
	   	m.insert(make_pair(roll,ch));
	    q--;
   }
   int x;
   cin>>x;
   while(x)
   {
   	cin>>roll;
   	cout<<m[roll]<<endl;
   	x--;
   }
return(0);
}

