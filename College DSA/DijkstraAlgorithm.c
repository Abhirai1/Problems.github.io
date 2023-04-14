#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distanceance value, from the set of vertices not yet included
// in shortest path tree
int mindistanceance(int distance[], bool visitedOrNot[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (visitedOrNot[v] == false && distance[v] <= min)
			min = distance[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distanceance
// array
void printSolution(int distance[])
{
	printf("Vertex \t\t distanceance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, distance[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int distance[V]; // minimum distanceance save karne ke liye

	bool visitedOrNot[V]; // visitedOrNot[i] will be true if vertex i is
				// included in shortest
	// path tree or shortest distanceance from src to i is
	// finalized

	// initial value dena ka step
	for (int i = 0; i < V; i++)
		distance[i] = INT_MAX, visitedOrNot[i] = false;

	// distanceance of source from itself is always 0
	distance[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distanceance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = mindistanceance(distance, visitedOrNot);

		// Mark the picked vertex as processed
		visitedOrNot[u] = true;

		// Update distance value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update distance[v] only if is not in visitedOrNot,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of distance[v]
			 if (!visitedOrNot[v] && graph[u][v]
				 && distance[u] != INT_MAX
				&& distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u] + graph[u][v];
	}

	// print the constructed distanceance array
	printSolution(distance);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}
