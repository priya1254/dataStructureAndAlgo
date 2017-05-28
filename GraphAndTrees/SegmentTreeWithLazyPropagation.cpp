//Segment Tree with Lazy Propagation
#include<bits/stdc++.h>
using namespace std;

//code taken and modified from https://gist.github.com/shobhit6993/7088061
int N;
#define MAX (1+(10^6)) // Why? grin emoticon
#define inf 0x7fffffff

int arr[10000000];
int tree[100000000];
int lazy[100000000];

/**
* Build and init tree
*/
void build_tree(long long int node, long long int a, long long int b) {
	if (a > b) return; // Out of range

	if (a == b) { // Leaf node
		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node * 2, a, (a + b) / 2); // Init left child
	build_tree(node * 2 + 1, 1 + (a + b) / 2, b); // Init right child

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Init root value
}

/**
* Increment elements within range [i, j] with value value
*/
void update_tree(long long int node, long long int a, long long int b, int i, int j, int value) {

	if (lazy[node] != 0) { // This node needs to be updated
		tree[node] = lazy[node]; // Update it

		if (a != b) {
			lazy[node * 2] = lazy[node]; // Mark child as lazy
			lazy[node * 2 + 1] = lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if (a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

	if (a >= i && b <= j) { // Segment is fully within range
		tree[node] = value;

		if (a != b) { // Not leaf node
			lazy[node * 2] = value;
			lazy[node * 2 + 1] = value;
		}

		return;
	}

	update_tree(node * 2, a, (a + b) / 2, i, j, value); // Updating left child
	update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Updating root with max value
}

/**
* Query tree to get max element value within range [i, j]
*/
int query_tree(long long int node, long long int a, long long int b, int i, int j) {

	if (a > b || a > j || b < i) return -inf; // Out of range

	if (lazy[node] != 0) { // This node needs to be updated
		tree[node] = lazy[node]; // Update it

		if (a != b) {
			lazy[node * 2] = lazy[node]; // Mark child as lazy
			lazy[node * 2 + 1] = lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if (a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];


	int q1 = query_tree(node * 2, a, (a + b) / 2, i, j); // Query left child
	int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}
//***code from https://gist.github.com/shobhit6993/7088061**** ends
int main() {
	int test=0;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int n,w,h,off;
		cin >> n;
		int k;
		cin >> k;
		for (int i = 0; i < n; i++) arr[i] = 0;

		build_tree(1, 0, n - 1);

		memset(lazy, 0, sizeof lazy);
		memset(tree, 0, sizeof tree);

		cout << "Case #" << t << ": ";
		for (int i = 0; i < k; i++)
		{
			cin >> w >> h >> off;
			int max1 = query_tree(1, 0, n - 1, off, w + off - 1);
			update_tree(1, 0, n - 1, off, w + off - 1, max1 + h);
			cout << query_tree(1, 0, n - 1, 0, n - 1) << " ";
		}
		cout << endl;

	}
return 0;
}
