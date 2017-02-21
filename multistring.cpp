// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note:

// •The numbers can be arbitrarily large and are non-negative.
// •Converting the input string to integer is NOT allowed.
// •You should NOT use internal library such as BigInteger.




// Subscribe to see which companies asked this question
#include<vector>
#include<string>
#include <iostream>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		int sign1 = 1;
		int sign2 = 1;
		if (num1[0] == '-') {
			sign1 = -1;
			num1 = num1.substr(1, num1.size() - 1);
		}
		if (num2[0] == '-') {
			sign2 = -1;
			num2 = num2.substr(1, num1.size() - 1);
		}
		string result = "";
		int carry = 0;
		for (int i = num1.size() - 1; i >= 0; i--) {
			string line = "";
			for (int j = num2.size() - 1; j >= 0; j--) {
				int m = num1[i] - '0';
				int n = num2[j] - '0';
				int s = m*n + carry;
				carry = s / 10;
				int left = s % 10;
				char r = '0' + left;
				line = r + line;
			}
			if (carry != 0) {
				char r = '0' + carry;
				line = r + line;
				carry = 0;
			}
			for (int k = 0; k < num1.size() - i - 1; k++) {
				line.push_back('0');
			}
			result = add_string(result, line);
		}
		if (sign1 * sign2 == -1) {
			result = '-' + result;
		}
		return result;
	}


	string add_string(string s1, string s2) {
		int i = 0;
		int carry = 0;
		string result = "";
		while (true) {
			if (i >= s1.size() && i >= s2.size() && carry == 0) break;
			int m = 0, n = 0;
			if (i < s1.size()) {
				m = s1[s1.size() - i - 1] - '0';
			}
			if (i < s2.size()) {
				n = s2[s2.size() - i - 1] - '0';
			}
			int s = m + n + carry;
			carry = s / 10;
			int left = s % 10;
			char r = '0' + left;
			result = r + result; 
			i++;
		}
		return result;
	}
};



int main() {
	Solution s;
	string s1 = "-12345";
	string s2 = "-567";
	string ret = s.multiply(s1, s2);
	cout << ret << endl;
	return 0;

}