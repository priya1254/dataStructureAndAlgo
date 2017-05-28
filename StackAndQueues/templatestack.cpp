#include<bits/stdc++.h>
using namespace std;
template <class T>
class stack1
{
   int top1, top2;
   T *mst,*s;
   public:
   stack1()
   {
       mst = new T[100];
       s = new T[100];
       top1 = -1;
       top2 = -1;

   }
   T pop();
   void push(T item);
   T minstack();

};

template <class T>
T stack1<T>:: pop()
{
  T item,item2;
  if(top1 == -1) return 0;
  item = s[top1];
  top1--;
  item2 = mst[top2];
  top2--;
  return item;
}

template <class T>
T stack1<T>:: minstack()
{
    T item;
    if(top2 == -1) return 0;
    item = mst[top2];
    return item;

}

template <class T>
T  getmax(T a, T b)
{
    return (a<b?b:a) ;

}

template <class T>
void stack1<T>::push(T a)
{
    if(top1 == -1)
    {
        top1 = 0;
        s[top1] = a;
     }
     else
    {
        top1++;
        s[top1] = a;

    }
     if(top2 == -1)
        {
          top2 = 0;
           mst[top2] = a;
        }
    else
    {

        if(a > mst[top2])
        {

            mst[top2 +1] = mst[top2];
            top2++;
        }
        else
        {

            mst[top2 +1] = a;
            top2++;
        }
    }

}

int main()
{
    stack1<int> st;
     int a,b,n;
     cin>>n;
     string str = "abc  def   ghi    jkl";
     str = str + " hi";
     stringstream ss(str);
     string str3;
     //cin>>str2;
     while(getline(ss,str3,' '))
     {
       cout<<str3<<endl;
     }

//    cout<<"enter elements"<<endl;
//    for(int i = 0; i < n; i++)
//        {
//            cin>>a;
//            st.push(a);
//        }
//
//       a = st.pop();
//       b = st.minstack();
//       cout<<a<<" "<<b<<endl;
//       int p = getmax<int>(2,3);
//       cout<<p;
 return 0;
}
