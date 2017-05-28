//move all the spaces in the string to front of the string
#include<bits/stdc++.h>
using namespace std;
int main()Find first non repeating character in a string
{
    string str;
    getline(cin,str);
    int len = str.size();
    int j = len  -1;
    for(int i = len-1; i >= 0; i--)
    {
        if(str[i] == ' '){}
        else
            str[j--] = str[i];


    }
    while(j>=0)
    {
        str[j] = ' ';
        j--;
    }

    cout<<str;
    return(0);
}
