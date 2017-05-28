#include <bits/stdc++.h>
using namespace std;

long long partition(vector<long long>&v, long long l, long long r)
{
    long long temp;
    long long pivot = v[l];
    long long i = l+1;
    long long j = r;
    while(1)
    {

        while(pivot > v[i])
        {i++;}
        while(pivot < v[j] )
        {j--;}
        if(i >= j)
        {
            temp = v[j];
            v[j] = pivot;
            v[l] = temp;
            break;
        }

        else
        {

          if(v[i] == v[j])
          {
            i++;
            j--;
            continue;
          }

            temp = v[j];
            v[j] = v[i];
            v[i] = temp;

        }
    }

           return j;
}


void quicksort(vector<long long>&v, long long l, long long r)
{
    if(l<r)
    {
        long long q = partition(v, l, r);
        quicksort(v,l,q-1);
        quicksort(v,q+1,r);
        return;
    }
       return;
}
int main()
{
	long long n,ch,j,temp;
	vector<long long> v;

    cin>>n;
    for(long long i = 1; i <= n; i++)
    {
        cin>>ch;
	    v.push_back(ch);

    }

    quicksort(v,0,n-1);
     for(long long i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";

    }

    return 0;
}
