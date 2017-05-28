#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<long long> &v, long long i ,long long arrsize)
{

    long long large = i;
    long long left = 2*i;
    long long right = 2*i + 1;

    if(left <= arrsize && v[large] <v[left])
    large= left;

    if(right <= arrsize && v[large] <v[right])
    large= right;

    if(large!=i)
    {
        long long temp = v[large];
        v[large] = v[i];
        v[i] = temp;
        max_heapify(v,large,arrsize);
    }

}

void buildheap(vector<long long> &v, long long n)
{
    for(long long i = n/2; i >= 1; i--)
    {
        max_heapify(v,i,n);


    }

}




void heapsort(vector<long long> &v, long long n)
{
   buildheap(v,n);

    long long temp = v[1];
    v[1] = v[n];
    v[n] = temp;
   for(long long i = n-1; i >= 2 ;i--)
   {
       max_heapify(v,1,i);
       long long temp = v[1];
       v[1] = v[i];
       v[i] = temp;


    for(long long k = 1; k <= n; k++)
    {
       cout<<v[k]<<" ";
    }
    cout<<endl;
   }

}

int main()
{
	long long n,ch,j,temp,k = 0;
	vector<long long> v;

    cin>>n;
    v.push_back(0);
    for(long long i = 1; i <= n; i++)
    {
        cin>>ch;
	    v.push_back(ch);

    }

    heapsort(v, n);


    return 0;
}
