#include <vector>
#include <iostream>
#include <unordered_set>

class ContainsDuplicate
{
    public:
        bool containsDuplicateUno(std::vector<int> &nums) // For large vectors, duplicate may be apparent earlier
        {
            std::unordered_set<int> previousNums; // Order doesn't matter
            for (int num: nums) // Iterate through the nums
            {
                if (previousNums.find(num) != previousNums.end()) // Something was found in the set 
                {
                    return true; // There's a duplicate
                }
                previousNums.insert(num); // Num is a previous num
            }
            return false; // No duplicates found
        }

        bool containsDuplicateDos(std::vector<int> &nums) // For small vectors
        {
            std::unordered_set<int> s(nums.begin(), nums.end()); // Convert to set
            return (s.size() != nums.size()); // Size matters lol
        }
};