#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,ch,temp, count = 0;
	vector<int> v;
	cin>>n;
	for(int i = 0 ;i<n; i++)
	{
	    cin>>ch;
	    v.push_back(ch);
	}
	for(int i = 0; i < n-1; i++)
	{
	    for(int j = 0 ; j < n-i -1; j++)
	    {
	        if(v[j] > v[j+1])
	        {
	          
	            count++;
	            temp = v[j];
	            v[j] = v[j+1];
	            v[j+1] = temp;
	        }
	    }
	}
	cout<<count;
	    return 0;
}
