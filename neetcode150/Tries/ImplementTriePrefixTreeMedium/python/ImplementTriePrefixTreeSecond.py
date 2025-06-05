class Trie: # Second attempt, Accepted

    class TrieNode: # Nested record
        def __init__(self):
            self.letters = [None] * 26 # None stored
            self.exists = False # False confirmation

    def __init__(self):
        self.__head = Trie.TrieNode() # Start the Trie
        
    def insert(self, word: str) -> None:
        indexes = [(ord(c) - 97) for c in word] # save the indexes
        nodeLayer = self.__head # first layer is the head
        while len(indexes) != 0: # while an index is present
            index = indexes.pop(0) # extract next index
            if nodeLayer.letters[index] is None: # node for letter doesn't exist
                nodeLayer.letters[index] = Trie.TrieNode() # create node for letter
            nodeLayer = nodeLayer.letters[index] # move on to the next layer
        nodeLayer.exists = True # mark as word

    def search(self, word: str) -> bool:
        indexes = [(ord(c) - 97) for c in word] # save the indexes
        nodeLayer = self.__head # first layer is the head
        while len(indexes) != 0: # while an index is present
            index = indexes.pop(0) # extract next index
            if nodeLayer.letters[index] is None: # node for letter doesn't exist
                return False # word doesn't exist
            nodeLayer = nodeLayer.letters[index] # move on to the next layer
        return nodeLayer.exists # word exists?

    def startsWith(self, prefix: str) -> bool:
        indexes = [(ord(c) - 97) for c in prefix] # store indexes of word
        nodeLayer = self.__head # first layer is the head
        while len(indexes) != 0: # while an index is present
            index = indexes.pop(0) # transfer first index
            if nodeLayer.letters[index] is None: # if layer doesn't exist
                return False # word doesn't exist
            nodeLayer = nodeLayer.letters[index] # move onto the next layer
        return True # layers exist, word exists