#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
	public:	
		int V;
	list<int> *adj;

	public:
		Graph(int V);
	void addEdge(int v,int w);
	void BFS(int s);
		
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

void Graph::BFS(int s)
{
	// create a boolean array to mark them if they are visited or no
	// and set the array to false as at the begin all the nodes is not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	// make the starting node = true
	visited[s] = true;
	queue.push_back(s);
	/* now explore all the neighboors of this node */
	while (!queue.empty())
	{
		//get the front of queue and print it the pop it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		//iterator to the list of type int
		list<int>::iterator i;
		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	

}

int main()
{
	// Create a graph given in the above diagram 
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);
}