//Trie Implemenatio
class TrieNode {
            // Initialize your data structure here.
            public TrieNode[] nodes;
            bool words = false;
            public TrieNode() {
                nodes = new TrieNode[26];
            }
        };


        public class Trie {
            private TrieNode root;

            public Trie() {
                root = new TrieNode();
            }

            // Inserts a word into the trie.
            public void insert(String word) {
                TrieNode current = root;
                int c;
                for(int i = 0; i<word.length(); i++){
                    c = word.charAt(i)-'a';
                    if(current.nodes[c] == null){
                        current.nodes[c] = new TrieNode();;
                    }
                    current = current.nodes[c];
                }
                current.words = true;
            }

            // Returns if the word is in the trie.
            public boolean search(String word) {
                TrieNode current = root;
                int c;
                for(int i = 0; i<word.length(); i++){
                    c = word.charAt(i)-'a';
                    if(current.nodes[c] == null) return false;
                    current = current.nodes[c];
                }
                return current.words;
            }

            // Returns if there is any word in the trie
            // that starts with the given prefix.
            public boolean startsWith(String word) {
                TrieNode current = root;
                int c;
                for(int i = 0; i<word.length(); i++){
                    c = word.charAt(i)-'a';
                    if(current.nodes[c] == null) return false;
                    current = current.nodes[c];
                }
                return true;
            }
        };
int main() {

    int t=0;
	long n;


	//cin>>t;
      Trie trie = new Trie();
        trie.insert("key");
         trie.search("key");


	/*for(int i1=1;i1<=t;i1++)
	{
	    //cin>>n;
	    /*string a[10001];

	    for(int i=0;i<n;i++)
        {
           getline (cin, a[i]);
            root.addWord(a[i]);
           cout<<"hi";
        }
    */
   /* root.addWord("Bob");
    root.addWord("Bobbby");
    root.addWord("Boba");
    root.addWord("charles");
    root.addWord("charly");
    root.addWord("julia");
    root.addWord("julian");
   cout<<"helllloooo";

	    cout<<"Case #"<<i1<<": ";
     //for(int i=0;i<n;i++)
       // {
           cout<<root.countPrefixes("Bob");
             cout<<"\n";


       // }


	    cout<<"\n";

	}
*/
	return 0;
}

        // Your Trie object will be instantiated and called as such:
        // Trie trie = new Trie();
        // trie.insert("somestring");
        // trie.search("key");
