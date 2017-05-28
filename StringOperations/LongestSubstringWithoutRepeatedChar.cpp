//find longest substring without repeated character, Sliding Window
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    map<char,int> map1;
    int len = 0;
    int j = 0;
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(map1.find(str[i]) != map1.end())
        {

            len = max(len, i -j);
            cout<<str.substr(j,i-j)<<endl;

            i = map1[str[i]];
            j = map1[str[i]] +1;

            map1.clear();

        }
        else
            map1.insert(make_pair(str[i],i));


    }
    len = max(len, i -j);
     cout<<len<<endl;
    return(0);
}
