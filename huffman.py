import heapq
n=int(input())
arr=[]
for i in range(n):
    character,frequency=list(input().split(" "))
    arr.append([int(frequency),character])

def getcode(hp,code=""):
    if hp[2]==None and hp[3]==None:
        print(hp[1],hp[0],code)
        return len(code)
    if hp[2]!=None:
        l=getcode(hp[2],code+"0")
    else:
        l=0
    if hp[3]!=None:
        r=getcode(hp[3],code+"1")
    else:
        r=0
    return l+r
    
    
def huffmancode(arr):
    hp=[i+[None,None] for i in arr]
    heapq.heapify(hp)
    for i in range(n-1):    
        l=heapq.heappop(hp)
        r=heapq.heappop(hp)
        z=[l[0]+r[0],l[1]+r[1],l,r]
        heapq.heappush(hp,z)
    getcode(hp[0])
    return hp[0]

huffmancode(arr)
