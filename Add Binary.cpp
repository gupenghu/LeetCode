// Given two binary strings, return their sum (also a binary string). 

// For example,
//  a = "11"
//  b = "1"
//  Return "100". 

class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int carry = 0;
		int first = a.find('1');
		int second = b.find('1');
		if (first == -1) a = "0";
		else a  = a.substr(first);
		if (second == -1) b = "0";
		else b  = b.substr(second);
		int max_sz = a.size() > b.size() ? a.size():b.size();
		for (int i =0; i < max_sz; i++){
			int temp = 0;
			if (i < a.size())	temp = a[a.size() - i - 1] - '0';
			if (i < b.size())	temp = temp + b[b.size() - i - 1] - '0';
			temp = temp + carry;
			if(temp > 1)	carry = 1;
			else carry = 0;
			result.insert(result.begin(),(temp%2) + '0');
		}
		if(carry){
			result.insert(result.begin(),carry + '0');
		}
		return result;
	}
};