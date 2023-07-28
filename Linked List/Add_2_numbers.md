from collections import defaultdict

class Graph:
    def __init__(self, v):
        self.V = v
        self.l = defaultdict(list)

    def addEdge(self, i, j, undir=True):
        self.l[i].append(j)
        if undir:
            self.l[j].append(i)

    def printGraph(self):
        for i in range(self.V):
            print(i, "--->", ", ".join(str(a) for a in self.l[i]))

    def printDFS(self, source, visited):
        visited[source] = True
        print(source, end=", ")

        for nbr in self.l[source]:
            if not visited[nbr]:
                self.printDFS(nbr, visited)

# Graph:-
#         2 ---- 3
#        /       | \
#       /        |  \
#      1         |   5
#       \        |  / \
#        \       | /   \
#         0 ---- 4      6

g = Graph(7)
g.addEdge(1, 2)
g.addEdge(0, 1)
g.addEdge(2, 3)
g.addEdge(0, 4)
g.addEdge(5, 3)
g.addEdge(4, 3)
g.addEdge(5, 6)
g.addEdge(4, 5)

visited = [False] * 7

print("Adjacency List:")
g.printGraph()

print("\nDFS Traversal:")
g.printDFS(1, visited)
