//Replace all spaces in the string with %20
#include<bits/stdc++.h>
using namespace std;
int main()
{
string str;
getline(cin,str);
int countspaces = 0,i = 0;
while(str[i]!= '\0')
{

    if(str[i] == ' ')
        countspaces++;
        i++;
}

int len = str.size();
int newlen = len + countspaces*2;
str.resize(newlen+1);
str[newlen] = '\0';
int j;
for(int i = newlen-1, j = len-1; j != 0;)
{
    if(str[j] == ' ')
    {

        str[i--] = '0';
        str[i--] = '2';
        str[i--] = '%';
        j = j-1;
    }

    else
        str[i--] = str[j--];

}

cout<<str;
return(0);
}

