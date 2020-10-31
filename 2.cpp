#include <bits/stdc++.h> 
using namespace std; 
#define V 4  
  
/* Define Infinite as a large enough 
value.This value will be used for  
vertices not connected to each other */
#define INF 99999  
int minKey(int key[], bool mstSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
    //loopOP
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
    return min_index; 
} 
 
// A utility function to print the 
// constructed MST stored in parent[] 
void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 
 
// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primMST(int graph[V][V]) 
{ 
    // Array to store constructed MST 
    int parent[V]; 
     
    // Key values used to pick minimum weight edge in cut 
    int key[V]; 
     
    // To represent set of vertices included in MST 
    bool mstSet[V]; 
 
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
 
    // Always include first 1st vertex in MST. 
    // Make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0; 
    parent[0] = -1; // First node is always root of MST 
 
    // The MST will have V vertices 
    for (int count = 0; count < V - 1; count++)
    { 
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST 
        int u = minKey(key, mstSet); 
 
        // Add the picked vertex to the MST Set 
        mstSet[u] = true; 
 
        // Update key value and parent index of 
        // the adjacent vertices of the picked vertex. 
        // Consider only those vertices which are not 
        // yet included in MST 
        for (int v = 0; v < V; v++) 
 
            // graph[u][v] is non zero only for adjacent vertices of m 
            // mstSet[v] is false for vertices not yet included in MST 
            // Update the key only if graph[u][v] is smaller than key[v] 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
 
    // print the constructed MST 
    printMST(parent, graph); 
}   
// A function to print the solution matrix  
void printSolution(int dist[][V]);  
  
// Solves the all-pairs shortest path  
// problem using Floyd Warshall algorithm  
void floydWarshall (int graph[][V])  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int dist[V][V], i, j, k;  
  
    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial values of shortest distances 
    are based on shortest paths considering  
    no intermediate vertex. */
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    /* Add all vertices one by one to  
    the set of intermediate vertices.  
    ---> Before start of an iteration,  
    we have shortest distances between all  
    pairs of vertices such that the  
    shortest distances consider only the  
    vertices in set {0, 1, 2, .. k-1} as 
    intermediate vertices.  
    ----> After the end of an iteration,  
    vertex no. k is added to the set of  
    intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    // Print the shortest distance matrix  
    printSolution(dist);  
}  
  
/* A utility function to print solution */
void printSolution(int dist[][V])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  
  
int numberOfSquares(int X[], int Y[], 
                    int N, int M) 
{ 
    // Stores the count of all possible 
    // distances in X[] & Y[] respectively 
    unordered_map<int, int> m1, m2; 
    int i, j, ans = 0; 
  
    // Find distance between all 
    // pairs in the array X[] 
    for (i = 0; i < N; i++) { 
        for (j = i + 1; j < N; j++) { 
  
            int dist = abs(X[i] - X[j]); 
            // Add the count to m1 
            m1[dist]++; 
        } 
    } 
  
    // Find distance between all 
    // pairs in the array Y[] 
    for (i = 0; i < M; i++) { 
        for (j = i + 1; j < M; j++) { 
  
            int dist = abs(Y[i] - Y[j]); 
  
            // Add the count to m2 
            m2[dist]++; 
        } 
    } 
  
    // Find sum of m1[i] * m2[i] 
    // for same distance 
    for (auto i = m1.begin(); 
         i != m1.end(); i++) { 
  
        // Find current count in m2 
        if (m2.find(i->first) 
            != m2.end()) { 
  
            // Add to the total count 
            ans += (i->second 
                    * m2[i->first]); 
        } 
    } 
  
    // Return the final count 
    return ans; 
}

int main() 
{ 
    // Given lines 
    int X[] = { 1, 3, 7 }; 
    int Y[] = { 2, 4, 6, 1 }; 
  
    int N = sizeof(X) / sizeof(X[0]); 
  
    int M = sizeof(Y) / sizeof(Y[0]); 
  
    // Function Call 
    cout << numberOfSquares(X, Y, N, M); 
  
    return 0; 
}

##c++ program to find largest three no


#include <iostream>
using namespace std;

int main() {    
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    if(n1 >= n2 && n1 >= n3)
        cout << "Largest number: " << n1;

    if(n2 >= n1 && n2 >= n3)
        cout << "Largest number: " << n2;
    
    if(n3 >= n1 && n3 >= n2)
        cout << "Largest number: " << n3;
  
    return 0;
}

# java programme to add two no 
public class AddTwoNumbers {

   public static void main(String[] args) {
        
      int num1 = 5, num2 = 15, sum;
      sum = num1 + num2;

      System.out.println("Sum of these numbers: "+sum);
   }
}
