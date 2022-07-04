from collections import defaultdict
class Graph:

	def __init__(self, vert):
		self.V = vert 
		self.graph = [] 
		

	
	def Edge(self, u, v, m):
		self.graph.append([u, v, m])

	
	def find(self, parent, i):
		if parent[i] == i:
			return i
		return self.find(parent, parent[i])

	
	def union(self, parent, rank, x, y):
		xroot = self.find(parent, x)
		yroot = self.find(parent, y)

		
		if rank[xroot] < rank[yroot]:
			parent[xroot] = yroot
		elif rank[xroot] > rank[yroot]:
			parent[yroot] = xroot

		
		else:
			parent[yroot] = xroot
			rank[xroot] += 1

	
	def Kruskal(self):

		result = [] 
		
		
		i = 0
		
		
		e = 0

		
		self.graph = sorted(self.graph,
                                    key=lambda item: item[2])

		parent = []
		rank = []

		
		for node in range(self.V):
			parent.append(node)
			rank.append(0)

		
		while e < self.V - 1:

			
			u, v, m = self.graph[i]
			i = i + 1
			x = self.find(parent, u)
			y = self.find(parent, v)

			if x != y:
				e = e + 1
				result.append([u, v, m])
				self.union(parent, rank, x, y)
			

		minimumCost = 0
		print ("Edges")
		for u, v, weight in result:
			minimumCost += weight
			print("%d -- %d == %d" % (u, v, weight))
		print("MST" , minimumCost)


g = Graph(5)
g.Edge(0, 1, 1)
g.Edge(0, 2, 6)
g.Edge(0, 3, 5)
g.Edge(1, 3, 1)
g.Edge(2, 3, 4)
g.Edge(1, 4, 5)


g.Kruskal()

