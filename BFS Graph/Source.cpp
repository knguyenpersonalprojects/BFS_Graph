#include<iostream>
#include<list>
using namespace std;

class Graph
{
private:
	//number of vertices
	int vertices;
	//create a pointer that points to the list of the adj node
	list<int>* adj_node;

public:
	Graph(int v)
	{
		//constructor 
		vertices = v;
		adj_node = new list<int>[v];
	}
	void addEdge(int a, int b)
	{
		//creates an edge and pushes that into the list
		adj_node[a].push_back(b);
	}
	void BFS(int s)
	{
		//create a boolean list of visted node where each index represent the verticies 
		bool* visted_vertices = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{	
			visted_vertices[i] = false;
		}
		//create a queue list
		list<int> queue;
		// s is the starting vertices
		queue.push_back(s);

		list<int>::iterator i;
		while (!queue.empty())
		{
			//set s as the first element in the queue, and display it
			s = queue.front();
			cout << s << endl;
			queue.pop_front();
			// then check if vertices S is pointing to any other verticies if so add it to queue
			for (i = adj_node[s].begin(); i != adj_node[s].end(); i++)
			{

				if (!visted_vertices[*i])
				{
					visted_vertices[*i] = true;
					queue.push_back(*i);
				}
			}
		}
		delete[] visted_vertices;
	}
	~Graph()
	{
		delete[] adj_node;
		
	}
};


int main()
{
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
	g.~Graph();
	system("PAUSE");
}