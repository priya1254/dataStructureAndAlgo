//counting sort
#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long n,ch,j,temp,k = 0;
	long long freq[101];
    memset(freq, 0, sizeof(freq));
    cin>>n;
    for(long long i = 1; i <= n; i++)
    {
        cin>>ch;
	    k = max(k,ch);
	    freq[ch]++;

    }


     for(long long i = 1; i <= k; i++)
    {
       if(freq[i]>0)
       cout<<i<<" "<<freq[i]<<endl;

    }

    return 0;
}
