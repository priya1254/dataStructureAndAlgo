//Use merge sort to chek no of pair such that a[i] greater than a[j] and i less than j
#include <bits/stdc++.h>
using namespace std;
long long no;
void merge(vector<long long> &v , long long p, long long q, long long r)
{
    vector<long long> v1;
    long long k = 0, i = p, j = q+1;
    while(i <= q && j <= r)
    {
        if(v[i]<= v[j])
        v1.push_back(v[i++]);

        else{
         v1.push_back(v[j++]);
         no += q-i+1 ;
        }
    }
     while(i <= q )
    {
         v1.push_back(v[i++]);
    }
     while(j <= r)
    {
          v1.push_back(v[j++]);
    }

    k = 0;

    for(long long x = p; x <= r ; x++)
    {
        v[x]= v1[k++];
    }

}




void mergesort(vector<long long> &v , long long l , long long r)
{
    long long mid;
    if(l < r)
    {
        mid = (l + r) /2;
        mergesort(v,l,mid);
        mergesort(v,mid+1, r);
        merge(v,l,mid,r);
        return;
    }

    return;
}


int main()
{
	long long n,ch,j,temp;
	vector<long long> v;
	no = 0;
    cin>>n;
    for(long long i = 1; i <= n; i++)
    {
        cin>>ch;
	    v.push_back(ch);

    }

    mergesort(v,0,n-1);
    for(long long i = 0; i < n; i++)
    {
      cout<<v[i]<<" ";

    }
    cout<<endl;
   cout<<no;
    return 0;
}
