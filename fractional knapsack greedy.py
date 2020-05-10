arr=[
  [60,10],
  [100,20],
  [120,30]
]
W=50
for i in arr:
  print(i)
print("W = ",W)
coins=[[i[0]/i[1]]+i for i in arr]
coins.sort()
w=W
out=0
while(w):  
  if w>=coins[-1][2]:
    out+=coins[-1][1]
    w-=coins[-1][2]
    coins.pop()
  else:
    out+=coins[-1][0]*w
    w=0

print(out)
