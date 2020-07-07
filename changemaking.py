"""
Given coins of different denominations and a total amount of money amount,
compute the fewest number of coins that you need to make up that amount.
"""
from typing import List
def coinChange(coins: List[int], amount: int) -> int:
    """
    amount: int - Amount of money to make up using combinations of given coins.
    coins: List[int] - different denominations of coins.
    return -1 if amount cannot be formed using any combination of given coins.
    """
    dp:List[int] = [float('inf') for j in range(amount + 1)]
    dp[0] = 0
    
    for c in coins:
        for i in range(c, amount + 1):
            dp[i] = min(dp[i], dp[i - c] + 1)
    
    if dp[-1] == float('inf'): return -1
    else: return dp[-1]
    