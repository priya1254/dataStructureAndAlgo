#include <bits/stdc++.h>
using namespace std;

long long range = 10;

void countsort(vector<long long> &v, long long place)
{
    long long n = v.size();
    long long output[n];
    long long freq[10];
    memset(freq,0, sizeof(freq));

    for(long long i = 0; i < v.size(); i++)
    {
        freq[(v[i]/place) % range]++;

    }
     for(long long i = 1; i < 10; i++)
    {
       freq[i] += freq[i-1];

    }

      for(long long i = n-1; i >=0 ; i--)
    {
      output[freq[(v[i]/place)%range]-1] = v[i];
      freq[(v[i]/place)%range]--;

    }
      for(long long i = 0; i < n; i++)
    {
       v[i] = output[i];
       cout<<output[i]<<" ";
    }
    cout<<endl;

    return;

}




void radixsort(vector<long long> &v, long long maxx)
{
    long long mul = 1;

    while(maxx)
    {
        countsort(v,mul);
        mul*=10;
        maxx = maxx/10;

    }

}

int main()
{
	long long n,ch,j,temp,k = 0;
	vector<long long> v;

    cin>>n;
    for(long long i = 1; i <= n; i++)
    {
        cin>>ch;
	    v.push_back(ch);
	    k = max(k,ch);

    }

    radixsort(v,k);


    return 0;
}
