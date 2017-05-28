//check if  one string is a rotation of another string or not.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    string str = str1 + str1;
    size_t found =str.find(str2);
    if(found)
    cout<<true;
    else cout<<false;
    return(0);
}
