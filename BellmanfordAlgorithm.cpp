// Bellman Ford Algorithm in C++
#include <bits/stdc++.h>
// Struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //w of the edge (u,v)
};

// Graph - it consists of edges
struct Graphs {
  int Vertices;        // Total number of vertices in the graph
  int Edges;        // Total number of edges in the graph
  struct Edge* edge;  // Array of edges
};

// Creates a graph with V vertices and E edges
struct Graphs* createGraphs(int Vertices, int Edges) {
  struct Graphs* graph = new Graphs;
  graph->Vertices = Vertices;  // Total Vertices
  graph->Edges = Edges;  // Total edges

  // Array of edges for graph
  graph->edge = new Edge[Edges];
  return graph;
}

// Printing the solution
void printArr(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void BellmanFord(struct Graphs* graph, int u) {
  int Vertices = graph->Vertices;
  int Edges = graph->Edges;
  int distance[Vertices];

  // Step 1: fill the distance array and predecessor array
  for (int i = 0; i < Vertices; i++)
    distance[i] = INT_MAX;

  // Mark the source vertex
  distance[u] = 0;

  // Step 2: relax edges |V| - 1 times
  for (int i = 1; i <= Vertices - 1; i++) {
    for (int j = 0; j < Edges; j++) {
      // Get the edge data
      int u = graph->edge[j].u;
      int v = graph->edge[j].v;
      int w = graph->edge[j].w;
      if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        distance[v] = distance[u] + w;
    }
  }

  // Step 3: detect negative cycle
  // if value changes then we have a negative cycle in the graph
  // and we cannot find the shortest distances
  for (int i = 0; i < Edges; i++) {
    int u = graph->edge[i].u;
    int v = graph->edge[i].v;
    int w = graph->edge[i].w;
    if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
      printf("Graph contains negative w cycle");
      return;
    }
  }

  // No negative weight cycle found!
  // Print the distance and predecessor array
  printArr(distance, Vertices);

  return;
}

int main() {
  // Create a graph
  int Vertices = 5;  // Total vertices
  int Edges = 8;  // Total edges

  // Array of edges for graph
  struct Graphs* graph = createGraphs(Vertices, Edges);

  //------- adding the edges of the graph
  /*
		edge(u, v)
		where 	u = start vertex of the edge (u,v)
				v = end vertex of the edge (u,v)

		w is the weight of the edge (u,v)
	*/

  //edge 0 --> 1
  graph->edge[0].u = 0;
  graph->edge[0].v = 1;
  graph->edge[0].w = 5;

  //edge 0 --> 2
  graph->edge[1].u = 0;
  graph->edge[1].v = 2;
  graph->edge[1].w = 4;

  //edge 1 --> 3
  graph->edge[2].u = 1;
  graph->edge[2].v = 3;
  graph->edge[2].w = 3;

  //edge 2 --> 1
  graph->edge[3].u = 2;
  graph->edge[3].v = 1;
  graph->edge[3].w = 6;

  //edge 3 --> 2
  graph->edge[4].u = 3;
  graph->edge[4].v = 2;
  graph->edge[4].w = 2;

  BellmanFord(graph, 0);  //0 is the source vertex

  return 0;
}
