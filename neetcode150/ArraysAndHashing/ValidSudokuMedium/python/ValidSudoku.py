class Solution:
    def isValidSudokuZero(self, board: List[List[str]]) -> bool: # brute force attempt, only passes the two given test cases, DOESN'T PASS SUBMISSION
        tiny_rows = [[row[0:3], row[3:6], row[6:]] for row in board] # split rows into sub boxes
        transposed_tiny_rows = [[tiny_row[i] for tiny_row in tiny_rows] for i in range(len(tiny_rows[0]))] # transpose sub box
        reduced_rows = [element for tiny_row in transposed_tiny_rows for element in tiny_row] # flatten transposed rows into a list
        reduced_column = [element for reduced_row in reduced_rows for element in reduced_row] # flatten into a list of all cells
        counter = [0 for _ in range(9)] # initialise frequency tracker
        for i, element in enumerate(reduced_column): # iterate through flattened list
            if element != ".": # skip empty cells
                if counter[int(element) - 1] > 0: # check if digit appeared more than once
                    return False # duplicate found
                counter[int(element) - 1] += 1 # increment count
            if (i + 1) % 9 == 0: # reset counter every 9 elements
                counter = [0 for _ in range(9)]  
        return True # no duplicates found
        # don't remember ever playing sudoku, don't know the rules, need to take a closer look introspection

        