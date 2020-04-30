from typing import List
def seivePrimes(N:int)->List[int]:
    primes=[1]*N
    primes[:2]=[0,0]
    for i in range(2,N):
        if primes[i]==1:
            for j in range(2*i,N,i):
                primes[j]=0
    return primes
primes=seivePrimes(10**5)