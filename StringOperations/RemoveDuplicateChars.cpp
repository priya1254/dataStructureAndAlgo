//Remove duplicate chars from the string.string is like aaabbbcccdde
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n = str.size();
    for(int i = 0; str[i]!= '\0'; i++)
    {

        for(int j = i+1; str[j]!= '\0'; j++)
        {
            if(str[i] == str[j])
            {

            int k;
            for(k = j; str[k+1]!= '\0'; k++)
            {
                cout<<str[k];
                str[k] = str[k+1];
                cout<<str[k]<<endl;
            }
                str[k ] = '\0';
                 j--;
            }
            cout<<str.size();

        }
        cout<<str<<endl;
        cout<<str.size()<<endl;
    }
  cout<<str<<endl;

    return(0);
}
