#include <iostream>
using namespace std;

char* reverseString(char *s)
{

 cout<<"hii";

  char *p,*q;
  p = &s[0];
  q = s;
  int i = 0;
  cout<<s[0]<<endl;
  cout<< q[0]<<endl;
  cout<<p[0]<<endl;
  while(s[i] != '\0')
  {
    //cout<<*q<<endl;
    i++;
    q++;

  }

  q--;
  //cout<<*q<<endl;
  cout<<sizeof(p)<<endl;
  cout<<sizeof(q)<<endl;
  while(p<q)
  {
    cout<<"inside second"<<endl;
     // cout<<*p<<" "<<*q<<endl;
      //cout<<p<<" "<<q<<endl;
    char temp;
    temp = *p;
    //cout<<temp<<endl;
    *p = *q;
    cout<<*p;
    *q = temp;
    //cout<<*p<<" "<<*q<<endl;
    //cout<<p<<" "<<q<<endl;
    p++;
    q--;



  }
  cout<<"hi";

  cout<<s;
  cout<<"\n";

  cout<<*s;
  return s;

}

// To execute C++, please define "int main()"
int main() {

 int a;
 int *p;
  p = &a;
  a = 2;
  cout<<"\n";
  cout<<a;
  cout<<"\n";
  cout<<*p;
  cout<<"\n";
  cout<<&a;
  cout<<"\n";
  cout<<p;
  cout<<"\n";
  cout<<&p;
  cout<<"\n";
  char *rev;
  char input[] = "PRIYA";
  cout<<&input<<" "<<input;
  char *st = "PRIYA";
   cout<<st<<endl;
  cout<< *st;
  cout<<"\n";
  cout<< *&st;
  cout<<"\n";
  //cout<< input;
  cout<<"\n";

  char const *p2 = input;
  p2 = "ravi";
  rev = reverseString(st);
  cout<<rev;
  return 0;
}
