"""
Given coins of different denominations and a total amount of money.
Compute the number of combinations that make up that amount, assume that you have infinite number of each kind of coin.
"""
from typing import List
def change(amount: int, coins: List[int]) -> int:
    """
    Compute the number of combinations of given coins that make up amount.
    
    amount: int - Amount of money to make up using combinations of given coins.
    coins: List[int] - different denominations of coins.
    """
    if amount == 0:
        return 1
    if len(coins) == 0:
        return 0

    dp=[[0]*len(coins) for i in range(amount+1)]
    for coin in range(len(coins)):
        dp[0][coin] = 1

    for i in range(1,amount+1):
        for j in range(len(coins)):
            if i >= coins[j]:
                excluded = dp[i - coins[j]][j]
            else:
                excluded = 0

            included = dp[i][j-1] if j else 0

            dp[i][j] = included + excluded
    return dp[amount][len(coins)-1]
