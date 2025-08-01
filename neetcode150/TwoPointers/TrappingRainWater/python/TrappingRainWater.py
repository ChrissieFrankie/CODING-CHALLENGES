class Solution:
    def trapFirst(self, height: List[int]) -> int: # brute force attempt, only passes first 50 test cases
        starting_index = -1
        max_height = 0
        # find the starting height and max height
        for i in range(len(height)): 
            current_height = height[i]
            if current_height > 0 and starting_index == -1: # frist greater than 0
                starting_index = i
            if current_height > max_height: # max height
                max_height = current_height
        if max_height == 0: # nothing to trap
            return 0
        # start level
        current_level = 1
        starting_section_index = -1
        ending_section_index = -1
        pay_attention_increasing = False
        trapped = 0
        # scan through map level by level
        while True:
            for i in range(starting_index, len(height)): # scan through map
                h = height[i] # current height
                if h == current_level and not pay_attention_increasing and starting_section_index == -1: # current level starting bar found
                    starting_section_index = i
                elif h <= current_level - 1 and starting_section_index != -1: # dip
                    pay_attention_increasing = True
                elif h < current_level and pay_attention_increasing and starting_section_index != -1: # false alert
                    pay_attention_increasing = False
                elif pay_attention_increasing: 
                    if h >= current_level: # dip ended
                        ending_section_index = i
                        for i in range(starting_section_index + 1, ending_section_index): # dip
                            trapped += current_level - height[i] # trapped water
                            height[i] = current_level # flatten dip
                        starting_section_index = -1 # reset
                        ending_section_index = -1
                        pay_attention_increasing = False
            starting_section_index = -1 #reset
            ending_section_index = -1
            if max_height == current_level: # traversed map
                break
            current_level += 1

        return trapped