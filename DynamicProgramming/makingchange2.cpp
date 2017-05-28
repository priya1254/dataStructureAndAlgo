#include <bits/stdc++.h>
using namespace std;
long visited[100005];
long rep[100005][2];
void func(long rem)
{

   long a=rep[rem][0];
  // cout<<a<<"\n";

   long b=rep[rem][1];
   // cout<<b<<"\n";
   if(a==0)
   {
       visited[b]++;
       //cout<<b<<" "<<visited[b]<<endl;
       return;
   }
    if(b==0)
   {
       visited[a]++;
        //cout<<a<<" "<<visited[a]<<endl;
       return;
   }
   func(a);
   func(b);
   return;

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
	    long count[c+1];
	    memset(a,0,sizeof(0));

	    for(long i=1;i<=n;i++)
        {
            cin>>a[i];

        }

 for(long k=0;k<=c;k++)
   {
     count[k]=LONG_MAX;
     visited[k]=0;
     rep[k][0]=0;
     rep[k][1]=0;
   }

count[0]=1;
         for(long i=1;i<=c;i++)
         {
             for(long j=1;j<=n;j++)
             {
                if(a[j]<=i)
                {

                    if(a[j]==i)
                    {
                        rep[i][0]=i;
                        rep[i][1]=0;
                        //cout<<i<<" hello"<<" "<<rep[i][0]<<" "<<rep[i][1]<<"\n";

                        count[i]=1;
                    }
                    else
                    {
                        if((count[i-a[j]]+1)<count[i])
                        {

                            count[i]=count[i-a[j]]+1;
                            rep[i][0]=i-a[j];
                            rep[i][1]=a[j];
                             //cout<<i<<" "<<"hello2"<<" "<<rep[i][0]<<" "<<rep[i][1]<<"\n";
                        }
                    }
                }

             }
         }
        //cout<<"\n"<<"hiiiiii";
       func(c);




	    cout<<"Case #"<<i1<<": ";
	    for(long i=1;i<=n;i++)
        {
            cout<<visited[a[i]]<<" ";
        }
	    cout<<"\n";

	}

	return 0;
}


