//Trir Implementation
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;

const unsigned int MAX = 10005;

struct Trie {
    int v, a[30];
    bool isWord;
    Trie () {
        v = 0;
        isWord = false;
        memset(a, 0, sizeof(a));
    }
};

int st,l, n, r;
char str[MAX];

inline int get_Trie () {
    return st++;
}

void add(Trie trie[], int state, int curr) {

    if (curr == l){
    	trie[state].isWord = true;
        return;
    }

    int in = str[curr] - 'a';
    if (trie[state].a[in] == 0){
        trie[state].a[in] = get_Trie();
    }
    add(trie, trie[state].a[in], curr+1);
}

int compute(Trie trie[], int state) {

    int& sol = trie[state].v;
    sol = 0;

    if(trie[state].isWord){
    	sol = 2;
    	return 3-sol;
    }

    bool flag = true;

    for (int i = 0; i < 26; i++) {
        if (trie[state].a[i]) {
        		flag = false;
            	sol |= compute(trie,trie[state].a[i]);
        }
    }

    if (flag){
        sol = 2;
    }
    return 3-sol;
}

int main () {
	int tc,c=1;
	cin>>tc;
	while(c<=tc){
		cin>>r>>n;
		Trie trie[300*MAX];
		st = 1;
		for (int i = 0; i < n; i++) {
		    cin>>str;
		    l = strlen(str);
		    add(trie, 0, 0);
		}
		compute(trie, 0);
		cout<<"Case #"<<c<<": "<<endl;
		int sol = trie[0].v;

		//Scenario 1
		if(sol>=2){
			cout<<"victory\n";
		}else if(sol==1){
			if(r&1){
				cout<<"defeat\n";
			}else{
				cout<<"victory\n";
			}
		}else{
			cout<<"defeat\n";
		}

		//Scenario 2
		if (sol < 2)
		    cout<<"defeat\n";
		else if (sol == 2)
			if(r&1){
				cout<<"victory\n";
			}else{
				cout<<"defeat\n";
			}
		else
		    cout<<"victory\n";

		//Scenario 3
		if(sol>=2){
			cout<<"defeat\n";
		}else if(sol==1){
			if(r&1){
				cout<<"victory\n";
			}else{
				cout<<"defeat\n";
			}
		}else{
			cout<<"victory\n";
		}

		if (sol < 2)
		    cout<<"victory\n";
		else if (sol == 2)
		    if(r&1){
				cout<<"defeat\n";
			}else{
				cout<<"victory\n";
			}
		else
		    cout<<"defeat\n";

		c++;
	}
    return 0;
}
