//Segment Tree
#include<bits/stdc++.h>
using namespace std;
#define N 1000099
#define VAL 3000000
#define infinity 0x7fffffff
#define MODULUS 1000000007
int arrayy[N],tree[VAL],propag[VAL];
void update_seg(int , int , int , int , int , int ) ;
void make_seg_tree(int , int , int );
int query_seg(int , int , int , int );


int main() {

    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        long ctr=0;
        char c;
        long n,k,l,r,v;
        cin>>n>>k;
        memset(propag, 0, sizeof propag);

        for(int i = 0; i < n; i++) arrayy[i] = 0;

        make_seg_tree(1, 0, n-1);
        for(int i=0;i<k;i++)
        {
            cin>>c;
            if(c=='i')
            {
                cin>>l>>r>>v;
                update_seg(1, 0, n-1, l-1, r-1, v);

            }
            if(c=='q')
            {
                cin>>v;
                ctr = (ctr%MODULUS + query_seg(1, 0, n-1, v-1))%MODULUS;
            }
       }

    cout<<"Case #"<<i1<<": "<<ctr<<"\n";
    }
}

void make_seg_tree(int vertex, int a, int b) {
    if(a > b) return;

    if(a == b) {
            tree[vertex] = arrayy[a];
        return;
    }

    make_seg_tree(vertex*2, a, (a+b)/2);
    make_seg_tree(vertex*2+1, 1+(a+b)/2, b);

    tree[vertex] = max(tree[vertex*2], tree[vertex*2+1]);
}

void update_seg(int vertex, int a, int b, int i, int j, int value) {

      if(a > b || a > j || b < i)
        return;

    if(a >= i && b <= j) {
            tree[vertex] = (tree[vertex]%MODULUS +value%MODULUS)%MODULUS;

        if(a != b) {
            propag[vertex*2] =(propag[vertex*2]%MODULUS + value%MODULUS)%MODULUS;
            propag[vertex*2+1] =(propag[vertex*2+1]%MODULUS+ value%MODULUS)%MODULUS;
        }

            return;
    }

    update_seg(vertex*2, a, (a+b)/2, i, j, value);
    update_seg(1+vertex*2, 1+(a+b)/2, b, i, j, value);
}
int query_seg(int vertex, int a, int b, int i) {


    if(a > b || a > i || b < i) return -infinity;
    if(propag[vertex] != 0) {
        tree[vertex] = (tree[vertex]%MODULUS +propag[vertex]%MODULUS)%MODULUS;

        if(a != b) {
            propag[vertex*2] =(propag[vertex*2]%MODULUS + propag[vertex]%MODULUS)%MODULUS;
                propag[vertex*2+1] =(propag[vertex*2+1]%MODULUS+ propag[vertex]%MODULUS)%MODULUS;
        }

        propag[vertex] = 0;
    }

    if(a == i && b == i)         return tree[vertex];

    int left = query_seg(vertex*2, a, (a+b)/2, i);
    int right = query_seg(1+vertex*2, 1+(a+b)/2, b, i);
    int answer=0;
    if(left!=-infinity && right!=-infinity)
    {
     answer = left+right;
    }
    else if(left==-infinity && right==-infinity)
    {
        answer=-infinity;
    }
    else if(right==-infinity)
    {
        answer=left;
    }
    else if(left==-infinity)
    {
        answer=right;
    }

    return answer;
}
