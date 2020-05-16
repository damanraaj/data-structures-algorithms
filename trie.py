class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        
        self.myTrie={}
        self.wordcount=0

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        self.wordcount+=1
        curr=self.myTrie
        for i in word:
            if i in curr:
                curr=curr[i]
            else:
                curr[i]={}
                curr=curr[i]
        curr['$']=True


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if self.wordcount==0:
            return False
        curr=self.myTrie
        for i in word:
            if i in curr:
                curr=curr[i]
            else:
                return False
        else:
            return "$" in curr

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if self.wordcount==0:
            return False
        curr=self.myTrie
        for i in prefix:
            if i in curr:
                curr=curr[i]
            else:
                return False
        else:
            return len(curr)>0
