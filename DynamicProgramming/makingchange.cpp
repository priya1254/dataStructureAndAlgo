//Dynamic Programming Making Change
#include <bits/stdc++.h>
using namespace std;
long ar[101][101];
long visited[100001];
long func(long x,long y,long a1[101],long n,long count1,long num)
{

    long m= n;
    if(y==0)
    return count1;
    if(visited[y]==1)
    {
        long z=count1+1;
    ar[num][x]=z;
    cout<<"setting ";
    cout<<num<<" "<<x<<" ";
    cout<<ar[num][x];
    cout<<"\n";

        return z;
    }
    count1+= y/x;

    ar[num][x]=count1;
    cout<<"setting ";
    cout<<num<<" "<<x<<" ";
    cout<<ar[num][x];
    cout<<"\n";

  long rem= y% x;
  n=n-1;
  while(a1[n]> rem)
  {
      if(n==0)
        break;
     n--;

  }

  count1=func(a1[n],rem,a1,m,count1,num);
  return count1;
}

int main() {
	int t=0;
	long n,c;


	cin>>t;

	for(int i1=1;i1<=t;i1++)
	{
	    cin>>n;
	    cin>>c;
	    long a[n+1];
	    long val;
	    long count;
	    long min1=1000001;

	    memset(visited,0,sizeof(visited));
	    for(int i=1;i<=10001;i++)
        {
            for(int j=1;j<=10001;j++)
            {
                ar[i][j]=0;
            }
        }
	    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            visited[a[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            count=func(a[i],c,a,n,0,a[i]);
            if(count<min1)
            {
                min1=count;
                val=a[i];
                cout<<"min1"<<" "<<min1<<" "<<"val1"<<val<<"\n";
            }

        }

	    cout<<"Case #"<<i1<<": ";
	    for(int i=1;i<=n;i++)
        {
            cout<<ar[val][a[i]]<<" ";
        }
	    cout<<"\n";

	}

	return 0;
}

