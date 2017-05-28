#include <hash_map>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define _DEFINE_DEPRECATED_HASH_CLASSES 0

using namespace std;

int main()
{
	hash_map<string, int> yeah;
	string hello = "hello";

	yeah["hello"] = yeah.comp("hello");
	yeah["Mellow Gold"] = 233;
	if (yeah["mellow Gold"])
		cout << "YEY!" << endl;
	cout << yeah.comp("hello");
	cout << yeah["hello"];

	yeah["okay"] = 23;
	cout << endl << yeah["okay"] << endl;

	return 0;
}
Edit & Run
