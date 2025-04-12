from ast import List, literal_eval

class Solution:

    def encodeOne(self, strs: List[str]) -> str: # super lazy brute force attempt
        return repr(strs)
    def decodeOne(self, s: str) -> List[str]:
        return literal_eval(s)
    
    def encodeTwo(self, strs: List[str]) -> str: """I'll come up with something that uses
                                                    some fancy math because this problem 
                                                    is boring not useful to visualise
                                                 """
        pass
    def decodeTwo(self, s: str) -> List[str]:
        pass