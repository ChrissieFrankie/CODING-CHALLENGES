class Trie: # First attempt, not working, brute force

    def __init__(self):
        self.__trie = self.__newFrequencyCounter() # frequency counter
        
    def __newFrequencyCounter(self):
        return [None for _ in range(26)] # return None representing prescence of letters

    def insert(self, word: str) -> None:
        self.__indexes = [(ord(c) - 97) for c in word] # store indexes of word
        if len(self.__indexes) == 0: # blank word
            return
        current_layer = self.__trie # get current layer of trie
        while len(self.__indexes) != 0: # an index layer exists
            layer_index = self.__indexes.pop(0) # transfer first index
            if current_layer[layer_index] is None: # nothing at index
                current_layer[layer_index] = self.__newFrequencyCounter() # load index
            current_layer = current_layer[layer_index] # update layer
            if current_layer is None:
                return False
    
    def search(self, word: str) -> bool:
        self.__indexes = [(ord(c) - 97) for c in word] # store indexes of word
        if len(self.__indexes) == 0: # blank word
            return False
        current_layer = self.__trie # get current layer of trie
        while len(self.__indexes) != 0: # an index layer exists
            layer_index = self.__indexes.pop(0) # transfer first index
            print(layer_index)
            if current_layer[layer_index] is None: # if layer doesn't exist
                return False # word doesn't exist
            current_layer = current_layer[layer_index] # update layer
        return True # layers exist, word exists
            
    def startsWith(self, prefix: str) -> bool:
        return self.search(prefix)

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)