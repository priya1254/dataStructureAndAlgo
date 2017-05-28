//Decode a string if 123 it can be abc or lc or aw
#include<bits/stdc++.h>
using namespace std;
//int decode(string str)
//{
//    int n = str.size();
//    if(n == 1) return  0;
//    if(n == 2) {
//            stringstream ss;
//        ss<<str;
//        int val;
//        ss>>val;
//        if(val > 10 && val <= 26)
//            return 1;
//         else
//                return 0;
//        }
//    int way1 = 0,way2 = 0,ways = 0;
//    way1 = decode(str.substr(1,n-1));
//    way2 = decode(str.substr(0,n-1));
//    ways = way1 +way2;
//    return ways;
//}
int main()
{
    string str;
    cin>>str;
    int n = str.size();
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int index = 1;index <n; index++)
    {

        if(str[index]-'0' != 0)
            dp[index+1] = dp[index];
        stringstream ss;
        ss<<str.substr(index-1,2);
        int val;
        ss>>val;
        cout<<"index is "<<index<<endl;
        cout<<"val is "<<val<<endl;

        if(val > 10 && val <= 26 )
            dp[index+1]+= dp[index -1];
    }
    cout<<"n is"<<n<<endl;
    cout<<dp[n];




//    int way = decode(str);
//    way+=1;
//    cout<<"ways are"<<way<<endl;
    return(0);
}
