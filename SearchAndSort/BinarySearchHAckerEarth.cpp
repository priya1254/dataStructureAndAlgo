#include <bits/stdc++.h>
using namespace std;

void bs(vector<int> v , int a)
{
    int l = 0, r = v.size()-1;


    while(l <= r)
    {
         int mid = (l + r)/2;
         if(v[mid] == a)
         {

            cout<< mid +1;
            break;
         }
        else
        {
            if(v[mid] > a)
            r = mid-1;
            else
            l = mid+1;
        }
    }



}


int main()
{
	int n,ch,j,temp;
	vector<int> v,v1;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>ch;
	    v.push_back(ch);
	    v1.push_back(ch);
    }
    for(int i = 1; i < n; i++)
    {

    	j = i-1;
        temp = v[i];
    	while(v[j] > temp && j>= 0)
    	{
    	    //cout<<"hi";
    		v[j+1] = v[j];
    		j--;
    	}
    	v[j+1] = temp;
    }
      for(int i = 0; i < n; i++)
    {
	    cout<<v[i]<<" ";
    }
    cout<<endl;

     for(int i = 0; i < n; i++)
    {

	    bs(v,v1[i]);
	    cout<<" ";
    }
    return 0;
}
