#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,ele,q;
	pair<int,int> p;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i = 1; i <= n; i++)
	{
	    cin>>ele;
	    v.push_back(make_pair(ele, i));
	}
	sort(v.begin(), v.end());
		
	cin>>q;
	for(int k =1; k <= q; k++)
	{
		cin>>ele;
	    int l = 0;
	    int r = n-1;
		 
		while(l <= r)
		{
			int mid = (l + r) /2 ;
			if(v[mid].first  == ele)
			{
				cout<<mid +1<<endl;
				break;
			}
			else 
			{	if(v[mid].first  > ele)
				r = mid - 1;
				else 
				l = mid + 1;
			}
		}
		
	}
   
    return 0;
}
