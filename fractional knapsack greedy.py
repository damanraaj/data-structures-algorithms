'''
Given weights and values of n items, which can be divided into smaller parts, 
put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
'''
def fractionalKnapsack(arr, W):
  '''
  arr: List[List[int]] - contains weight and value of items
  W: int - Capacity in weight of the Knapsack
  '''
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
  return out

arr=[
  [60,10],
  [100,20],
  [120,30]
]
W=50

fractionalKnapsack(arr, W)