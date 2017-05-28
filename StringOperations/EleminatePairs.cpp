//remove adjacent characters with same letters
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int i,j;
    j = -1;
    i = 0;
    while( i < str.size())
    {


        if(str[i] == str[j] && j >= 0)
        {
            j--;

        }
        else
            str[++j] = str[i];
       i++;
    }
    str[j+1] = '\0';
    cout<<str;
    return(0);
}
