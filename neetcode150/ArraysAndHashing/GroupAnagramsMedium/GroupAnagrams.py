class Solution:
    def groupAnagramsOne(self, strs: List[str]) -> List[List[str]]: # brute force attempt
        template = [0] * 26 # template of zeros
        memoryBank = {} # plan to use a fingerpint to group the strings
        def charToIndex(c): # char to index for fingerprinting
            return (ord(c) - 97)
        for word in strs: # iterate through strings
            binaryFingerprint = template.copy() # get a blank slate
            for letter in word: # iterate through each char
                binaryFingerprint[charToIndex(letter)] += 1 # fingerprint the blank slate
            binaryFingerprintT = tuple(binaryFingerprint) # get touple of fingerprint
            if binaryFingerprintT in memoryBank: # if in bank, append word 
                memoryBank[binaryFingerprintT].append(word)
            else:
                memoryBank[binaryFingerprintT] = [word] # if not in bank, set to list with word
        return memoryBank.values() # leetcode needs you to typecast it to a list, neetcode doesnt