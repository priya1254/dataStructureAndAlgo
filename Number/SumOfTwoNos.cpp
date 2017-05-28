//check if  sum of two numbers in array is K or not
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int arr[] = {2,4,4,8};
   int sum = 8;
   multimap<int,int> m1;
   for(int i = 0; i <4; i ++)
   {
      m1.insert(make_pair(arr[i], i));

   }
   for(multimap<int,int>::iterator it = m1.begin(); it!= m1.end(); it ++)
   {
       cout<<"map elements"<<endl;
              cout<<it->first<<" ";
              cout<<it->second<<endl;
   }
  for(int i = 0; i < 4; i ++)
   {
      if(m1.find(sum -arr[i]) != m1.end())
      {
          multimap<int,int>::iterator it = m1.find(sum - arr[i]);
          if(it->second == i)
          {
              cout<<"inside if"<<endl;
              cout<<it->first<<" ";
              cout<<it->second<<endl;
              continue;
          }

          else
            {
                cout<<"inside else"<<endl;
                cout<<it->first<<" ";
                cout<<it->second<<endl;
                cout<<true<<endl;
                break;

            }

      }


   }

    return(0);

}
