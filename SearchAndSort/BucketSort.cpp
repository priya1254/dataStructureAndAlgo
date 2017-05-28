#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    float ch;
    vector<float> v;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>ch;
        v.push_back(ch);
    }
    int no = n  *sizeof(v[0]);
    vector<float> bucket[no];
   
    int cnt;
    for(int i = 0; i < n; i++)
    {
        cnt = n*v[i];
        bucket[cnt].push_back(v[i]);
    }
    
    for(int i = 0; i <no; i++)
    {
        sort(bucket[i].begin(),bucket[i].end());
        
    }
    
    int flag = 0;
    for(int i = 0; i < no; i++)
    {
        flag = 0;
        for(vector<float> :: iterator itr = bucket[i].begin(); itr < bucket[i].end() ; itr++)
        {
            cout<<*(itr)<<" ";
            flag = 1;
        }
        if(flag)cout<<endl;
    }

    return 0;
}
