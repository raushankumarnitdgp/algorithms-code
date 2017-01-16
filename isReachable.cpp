#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int V;    
    list<int> *adj;    
public:
    Graph(int V); 
    void addEdge(int v, int w); 
    bool isReachable(bool visited[],int s, int d);  
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
//dfs code ,checking whether it is Reachable from s
bool Graph::isReachable(bool visited[],int s, int d)
{
    
    if (s == d)
      return true;

    visited[s]=true;
    bool reached=false;
    list<int>::iterator i;
    
    for(i=adj[s].begin();i!=adj[s].end();i++)
    {
      if(!visited[*i])
	reached=isReachable(visited,*i,d);
      if(reached==true)
	return true;
      
    }
    
   
    return false;
}
 

int main()
{
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    int V=4;
    bool *visited = new bool[V];
    
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    if(g.isReachable(visited,u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    
     
    // Mark all the vertices as not visited
    
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    
    if(g.isReachable(visited,u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
    
    cout<<"\n";
 
    return 0;
}