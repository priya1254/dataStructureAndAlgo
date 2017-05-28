//check if edge exist or not
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m,q1,a,b;
    cin>>n>>m;
    vector<int> v[1000];
    for(int i = 0; i<m; i++)
    {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
    }

    cin>>q1;
    int p,q;
    for(int k = 1; k<= q1; k++)
    {
        cin>>p>>q;
        if(find(v[p].begin(),v[p].end(),q)!= v[p].end())
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    return 0;
}
