// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

// You may assume the integer do not contain any leading zero, except the number 0 itself.

// The digits are stored such that the most significant digit is at the head of the list.



// Subscribe to see which companies asked this question.
 
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		bool carry = true;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if(carry){
				digits[i] = digits[i] + 1;
			}
			if(digits[i] == 10){
				carry = true;
				digits[i] = 0;
			}else carry = false;
		}
		if (carry){
			digits.insert(digits.begin(),1);
		}
		return digits;
	}
};