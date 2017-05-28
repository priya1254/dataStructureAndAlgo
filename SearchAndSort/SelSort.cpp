#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,ch,small,pos,flag = 0, cnt = 0;
	vector<int> v;
	cin>>n>>x;
	for(int i = 0; i<n; i++)
	{
	    cin>>ch;
	    v.push_back(ch);
	}

    
        for(int i = 0; i<n; i++)
        {    
            if(cnt >= x)break;
            cnt++;
            flag = 0;
            small = v[i];
            for(int j = i+1 ; j < n; j++)
            {
               
                if(v[j] < small)
                {
                    small = v[j];
                    pos = j;
                    flag = 1;
                }
                
            }
             if(flag == 1)
                 {
                     v[pos] = v[i];
                     v[i] = small;
                 }
            
        }
        
    
    for(int i = 0; i<n; i++)
        {
            cout<< v[i]<<" ";
        }
        
        
	return 0;
}
