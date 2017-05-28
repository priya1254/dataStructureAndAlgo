//How to implement a hashmap
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<string,string>umap;

int main()
{
    int t=0;
    cin>>t;

    for(int i1=1;i1<=t;i1++)
	{
	    int n,d,a;
	    string s;
	    string p[256];
	    string r;
	    int len;

     cin>>n>>d>>a>>s;


     for(int i=0;i<n;i++)
     {
         int k=0;
         cin>>p[i];
         len=p[i].length();
         for(int j=2;j<len;j++)
         {
             r[k++]=p[i][j];
         }
         umap[p[i][0]]=r;

     }
     len=strlen(s);
     for(int i=0;i<len;i++)
     {
         s[0]=umap[s[0]];
         cout<<s[0]<<endl;

     }






      cout<<"Case #"<<i1<<": "<<endl;

 printf("%0.4lf\n",r);






	}
    return 0;
}
