import heapq
from collections import defaultdict
from sys import maxsize
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.E=0
        self.V=0

    def addEdge(self,u,v,w):
        self.graph[u].append([w,v])
        self.graph[v].append([w,u])
        self.E+=1
        self.V=len(self.graph)

    def dijkstra(self,start):
        dist={i:maxsize for i in self.graph.keys()}
        parent={i:"-" for i in self.graph.keys()}
        dist[start]=0
        visited=set()
        curr=start
        while len(visited)!=self.V:
            for i in self.graph[curr]:
                if i[1] not in visited:
                    if dist[i[1]]>i[0]+dist[curr]:
                            dist[i[1]]=i[0]+dist[curr]
                            parent[i[1]]=curr
                
            visited.add(curr)
            x=maxsize
            nxt=None
            for i in self.graph[curr]:
                if i[1] not in visited:
                    if x>i[0]:
                        x=i[0]
                        nxt=i
            if nxt!=None:
                curr=nxt[1]
            elif len(visited)!=self.V:
                for i in self.graph.keys():
                    if i not in visited:
                        curr=i
                        break
            else:
                break
            
        print("V : ",end="")
        for i in self.graph.keys():
            print(i,"\t",end=" ")
        print("\nD : ",end="")
        for i in dist.keys():
            print(dist[i],end="\t")
        print("\nP : ",end="")
        for i in dist.keys():
            print(parent[i],end="\t")
        print()
        for i in self.graph.keys():
            j=i
            path=j
            while parent[j]!=parent[start]:
                j=parent[j]
                path=j+"->"+path
            print(path)
        return dist,parent
    
g=Graph()
g.addEdge('a','b',4)
g.addEdge('a','c',4)
g.addEdge('a','d',5)
g.addEdge('a','g',6)
g.addEdge('b','c',6)
g.addEdge('b','e',3)
g.addEdge('b','h',-3)
g.addEdge('c','d',1)
g.addEdge('c','e',2)
g.addEdge('d','f',5)
g.addEdge('d','g',2)
g.addEdge('f','e',2)
g.addEdge('f','h',4)
g.addEdge('f','g',3)
g.addEdge('g','h',-6)
g.addEdge('e','h',2)

g.dijkstra('a')
g.dijkstra('h')
