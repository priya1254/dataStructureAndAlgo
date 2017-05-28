//wap to check if string has all unique chars

#include<bits/stdc++.h>
using namespace std;
int main()
{

 string str;
 getline(cin,str);
 int i= 0;
 int bitvector = 0;
 while(str[i] != '\0')
  {

      if(bitvector && 1<<i) {
          cout<<"false"<<endl;
        break;
      }
      else
      {
          bitvector = bitvector | (1<<i);
      }
      i++;
  }
if(str[i] == '\0')cout<<"true"<<endl;


return(0);
}

