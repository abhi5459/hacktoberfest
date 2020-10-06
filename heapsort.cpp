#include <iostream> 
using namespace std; 
typedef complex<double> cd; 
  const int ALPHABET_SIZE = 26; 
void edge(int a, int b) 
{ 
    g[a].pb(b); 
  
    // for undirected graph add this line 
    // g[b].pb(a); 
} 
  
void bfs(int u) 
{ 
    queue<int> q; 
  
    q.push(u); 
    v[u] = true; 
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop(); 
  
        cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
            } 
        } 
    } 
} 
    
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Recursive function of FFT 
vector<cd> fft(vector<cd>& a) 
{ 
    int n = a.size(); 
  
    // if input contains just one element 
    if (n == 1) 
        return vector<cd>(1, a[0]); 
  
    // For storing n complex nth roots of unity 
    vector<cd> w(n); 
    for (int i = 0; i < n; i++) { 
        double alpha = 2 * M_PI * i / n; 
        w[i] = cd(cos(alpha), sin(alpha)); 
    } 
  
    vector<cd> A0(n / 2), A1(n / 2); 
    for (int i = 0; i < n / 2; i++) { 
  
        // even indexed coefficients 
        A0[i] = a[i * 2]; 
  
        // odd indexed coefficients 
        A1[i] = a[i * 2 + 1]; 
    } 
  
    // Recursive call for even indexed coefficients 
    vector<cd> y0 = fft(A0);  
  
    // Recursive call for odd indexed coefficients 
    vector<cd> y1 = fft(A1); 
  
    // for storing values of y0, y1, y2, ..., yn-1. 
    vector<cd> y(n); 
  
    for (int k = 0; k < n / 2; k++) { 
        y[k] = y0[k] + w[k] * y1[k]; 
        y[k + n / 2] = y0[k] - w[k] * y1[k]; 
    } 
    return y; 
} 
 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 
