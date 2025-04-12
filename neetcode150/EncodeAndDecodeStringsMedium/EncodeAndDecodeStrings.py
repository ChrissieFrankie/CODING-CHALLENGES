from ast import List, literal_eval

class Solution:

    def encodeOne(self, strs: List[str]) -> str: # super lazy brute force attempt
        return repr(strs)
    def decodeOne(self, s: str) -> List[str]:
        return literal_eval(s)