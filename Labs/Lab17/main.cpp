//Troy Kayne
//Lab 17
//Graph

#include <iostream>
#include <vector>
using namespace std;

struct adjVertex;

struct vertex {
    string name;
    vector<adjVertex> adj;
};

struct adjVertex {
    vertex *v;
    int weight;
};

class Graph {
private:
    vector<vertex> vertices;
    vector<adjVertex> adj;
    int size;
public:
    void addVertex(string n);
    void addEdge(string v1, string v2, int weight);
    void displayEdges();
};

void Graph::addVertex(string n) {
    bool found = false;
    for(int i=0; i<vertices.size();i++)
    {
        if(vertices[i].name == n)
        {
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
            break;
        }
    }
    if(found==false)
    {
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}
void Graph::addEdge(string v1, string v2, int weight) {
    for(int i=0; i<vertices.size();i++)
    {
        if(vertices[i].name == v1)
        {
            for(int j=0; j<vertices.size();j++)
            {
                if(vertices[j].name == v2 && i!=j)
                {
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}
void Graph::displayEdges() {
    for(int i=0; i < vertices.size();i++)
    {
        cout<< vertices[i].name<<"-->";
        for(int j=0; j<vertices[i].adj.size();j++)
        {
            adjVertex av;
            cout<<vertices[i].adj[j].v->name<<" "<<vertices[i].adj[j].weight<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    Graph g;
    g.addVertex("Denver");
    g.addVertex("Santa Fe");
    g.addVertex("El Paso");
    g.addVertex("SLC");
    g.addVertex("Las Vegas");
    g.addVertex("Phoenix");
    g.addVertex("San Fran");
    g.addVertex("LA");
    g.addEdge("Denver", "Santa Fe", 2);
    g.addEdge("Denver", "SLC", 3);
    g.addEdge("Denver", "Phoenix", 5);
    g.addEdge("Santa Fe", "Phoenix", 3);
    g.addEdge("Santa Fe", "Denver", 2);
    g.addEdge("Santa Fe","El Paso", 2);
    g.addEdge("El Paso", "Santa Fe", 2);
    g.addEdge("El Paso", "Phoenix", 3);
    g.addEdge("El Paso", "LA", 6);
    g.addEdge("SLC", "Denver", 3);
    g.addEdge("SLC", "Las Vegas", 3);
    g.addEdge("SLC", "San Fran", 5);
    g.addEdge("Las Vegas", "SLC", 3);
    g.addEdge("Las Vegas", "LA", 2);
    g.addEdge("Phoenix", "Denver", 5);
    g.addEdge("Phoenix", "Santa Fe", 3);
    g.addEdge("Phoenix", "El Paso", 3);
    g.addEdge("Phoenix", "LA", 3);
    g.addEdge("San Fran", "SLC", 5);
    g.addEdge("San Fran", "LA", 3);
    g.addEdge("LA", "San Fran", 3);
    g.addEdge("LA", "Las Vegas", 2);
    g.addEdge("LA", "Phoenix", 3);
    g.addEdge("LA", "El Paso", 6);
    g.displayEdges();
    return 0;
}
