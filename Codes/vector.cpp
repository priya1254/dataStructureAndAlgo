//vector implentation
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t=0;
	cin>>t;
	long n,m;


	for(int i1=1;i1<=t;i1++)
       {

       cin>>n>>m;
       long len[n+1];
       vector<long> v[n+1];
       vector<long>::iterator it;
       for(int i=0;i<n;i++)
       {
           cin>>len[i];
       }
       long min1=200001;
       long cnt;
       long num;
       for(long i=0;i<n;i++)
       {
          min1=200001;
           for(int j=0;j<m;j++)
           {
               if(min1>v[j].size())
               {
                   min1=v[j].size();
                   cnt=j;
               }

           }
           num=len[i];
           v[cnt].push_back(num);
       }
       long max1=0;
       long count1=0;
       for(int j=0;j<m;j++)
           {
               count1=0;
                for (it=v[j].begin(); it<v[j].end(); it++)
                     {
                        count1+=*it;
                      }
                      cout<<count1<<endl;
               if(max1<count1)
               {


                      max1=count1;

               }
               cout<<max1<<endl;

           }


	    cout<<"Case #"<<i1<<": "<<max1;
        cout<<"\n";

	}


	return 0;
}


