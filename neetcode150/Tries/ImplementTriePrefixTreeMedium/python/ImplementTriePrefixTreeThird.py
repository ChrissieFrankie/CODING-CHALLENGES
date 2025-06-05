class Trie: # Third attempt, Accepted, Optimized Once

    class TrieNode: # Nested record
        def __init__(self):
            self.letters = [None] * 26 # None stored
            self.exists = False # False confirmation

    def __init__(self):
        self.__head = Trie.TrieNode() # Start the Trie
        
    def insert(self, word: str) -> None:
        nodeLayer = self.__head # first layer is the head
        for c in word: # iterate through each char/layer
            index = ord(c) - 97 # convert char to index
            if nodeLayer.letters[index] is None: # node for letter doesn't exist
                nodeLayer.letters[index] = Trie.TrieNode() # create node for letter
            nodeLayer = nodeLayer.letters[index] # move on to the next layer
        nodeLayer.exists = True # mark as word

    def search(self, word: str) -> bool:
        nodeLayer = self.__head # first layer is the head
        for c in word: # iterate through each char/layer
            index = ord(c) - 97 # convert char to index
            if nodeLayer.letters[index] is None: # node for letter doesn't exist
                return False # word doesn't exist
            nodeLayer = nodeLayer.letters[index] # move on to the next layer
        return nodeLayer.exists # word exists?

    def startsWith(self, prefix: str) -> bool:
        nodeLayer = self.__head # first layer is the head
        for c in prefix: # iterate through each char/layer
            index = ord(c) - 97 # convert char to index
            if nodeLayer.letters[index] is None: # if layer doesn't exist
                return False # word doesn't exist
            nodeLayer = nodeLayer.letters[index] # move onto the next layer
        return True # layers exist, word exists
        
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)