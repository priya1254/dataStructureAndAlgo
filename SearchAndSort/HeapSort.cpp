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
   }
}



int main()
{
	long long n,ch,j,temp,a,b,c,k = 0;
	vector<long long> v;

    cin>>n;
    v.push_back(0);
    for(long long i = 1; i <= n; i++)
    {
        if(i == 1 || i == 2)
        {
            cin>>ch;
            v.push_back(-1* ch);
            cout<<"-1"<<" "<<endl;
            continue;
        }
        if(i ==3)
        {
            
            cin>>ch;
	        v.push_back(-1* ch);
            heapsort(v,3);
            cout<<-1*v[1]<<" "<<-1*v[2]<<" "<<-1*v[3]<<endl;
            continue;
        }
        else
        {
             cin>>ch;
            if(-1* ch < v[1])
            { 
                 v[1] = -1 * ch;
                 heapsort(v,3);
                 cout<<-1*v[1]<<" "<<-1*v[2]<<" "<<-1*v[3]<<endl;
            }
            else
            cout<<-1*v[1]<<" "<<-1*v[2]<<" "<<-1*v[3]<<endl;
        }
        
    }

    return 0;
}