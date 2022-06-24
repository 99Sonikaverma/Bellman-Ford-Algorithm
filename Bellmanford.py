# Bellman Ford Algorithm in Python
class Graphs:
    def __init__(self, vertices):
        self.Vertex = vertices   # Total number of vertices in the graph
        self.graph = []     # Array of edges

    # Add edges
    def add_edges(self, s, d, w):
        self.graph.append([s, d, w])

    # Print the solution
    def print_solution(self, distance):
        print("Vertex Distance from Source")
        for i in range(self.Vertex):
            print("{0}\t\t{1}".format(i, distance[i]))

    def bellman_ford(self, source):

        # Step 1: fill the distance array and predecessor array
        distance = [float("Inf")] * self.Vertex
        # Mark the source vertex
        distance[source] = 0

        # Step 2: relax edges |V| - 1 times
        for _ in range(self.Vertex - 1):
            for s, d, w in self.graph:
                if distance[s] != float("Inf") and distance[s] + w < distance[d]:
                    distance[d] = distance[s] + w

        # Step 3: detect negative cycle
        # if value changes then we have a negative cycle in the graph
        # and we cannot find the shortest distances
        for s, d, w in self.graph:
            if distance[s] != float("Inf") and distance[s] + w < distance[d]:
                print("Graph contains negative weight cycle")
                return

        # No negative weight cycle found!
        # Print the distance and predecessor array
        self.print_solution(distance)


g = Graphs(5)
g.add_edges(0, 1, 5)
g.add_edges(0, 2, 4)
g.add_edges(1, 3, 3)
g.add_edges(3, 2, 2)
g.add_edges(2, 1, 6)

g.bellman_ford(0)