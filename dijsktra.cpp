#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
#define MAX 99
#define INF 99999
#define pair pair< int, int >
#define pb(x) push_back(x)
 


int Dist[MAX];
priority_queue< pair, vector< pair >, greater< pair > > Q;

vector< pair > Graph[MAX];

bool visited[MAX];
 
int main() {
    int  u, v, w; 
    int nodes, edges; 
    int source;
 
    // create graph
    scanf("%d %d", &nodes, &edges);
    for(int i=0; i<edges; i++) {
      //input edges and its weight
        cin>>u>>v>>w;
        Graph[u].pb(pair(v, w));
        Graph[v].pb(pair(u, w)); // undirected graph
    }
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);
    
    
    // initialize distance 
    for(int i=1; i<=nodes; i++) 
      Dist[i] = INF;
    
    Dist[source] = 0;
    Q.push(pair(source, 0));
    
 
    // dijkstra
    while(!Q.empty()) {
        u = Q.top().first;
        Q.pop();
        if(visited[u]) 
	  continue;
	
        for(int i=0; i<Graph[u].size(); i++) {
            v = Graph[u][i].first;
            w = Graph[u][i].second;
            if(!visited[v] && Dist[u]+w < Dist[v]) {
                Dist[v] = Dist[u] + w;
                Q.push(pair(v, Dist[v]));
            }
        }
        visited[u] = 1; // done with u
    }
 
    // result
    for(int i=1; i<=nodes; i++) 
      printf("Node %d, Source to Node path weight = %d\n", i, Dist[i]);
    return 0;
    
}