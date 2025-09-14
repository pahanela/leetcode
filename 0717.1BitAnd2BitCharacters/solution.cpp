717. 1-bit and 2-bit Characters
Solved
Easy
Topics
premium lock icon
Companies
Hint
We have two special characters:

The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

 

Example 1:

Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.
Example 2:

Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.
 

Constraints:

1 <= bits.length <= 1000
bits[i] is either 0 or 1.


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        // corner case, [0] - only possible with one character
        if (bits.size() == 1)
            return true;

        // loop through all the characters to the one before the last
        int i = 0;
        for (i = 0; i < bits.size() - 2; ++i) {
            if (bits[i] == 1)
                i++;
        }
        // checking condition when all characters are already matched or when x, 0, 0
        if (i == bits.size() - 1 || (i == bits.size() - 2 && bits[i] == 0))
            return true;

        return false;
    }
};

