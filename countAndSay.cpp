class Solution {
public:
	string countAndSay(int n) {
		string str = "1";
		for (int i = 1; i < n; ++i) {
			str = generateNext(str);
		}
		return str;
	}

	string generateNext(string str) {
		string result = "";
		int num = 1;
		for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
			if (iter + 1 == str.end() || *iter != *(iter + 1)) {
				result += '0' + num ;
				result += *iter;
				num = 1;
				cout << result << endl;
			}
			else {
				num = num + 1;
			}
		}
		return result;
	}
};