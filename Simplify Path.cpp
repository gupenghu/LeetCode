// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

// class Solution {
class Solution {
public:
	string simplifyPath(string path) {
		vector<string> result;
		int pos = 0;
		while (pos < path.size()) {
			if (path[pos] == '/') {
				int flag = path.find("/",pos + 1);
				string temp = "";
				if (flag != -1) {
					temp = path.substr(pos + 1, flag - pos - 1);
				}
				else {
					temp = path.substr(pos + 1);
				}

				pos = pos + temp.size() + 1;
				if (temp == "..")
				{
					if (result.size() != 0) {
						result.pop_back();
					}
					else {
						//break;
					}

				}
				else if (temp == ".") {

				}
				else if(temp != "")result.push_back(temp);
			}
			else
			{
				pos++;
			}
		}
		string ret = "/";
		for (int i = 0; i < result.size(); ++i)
		{
			ret = ret + result[i];
			if (i != result.size() - 1) {
				ret = ret + '/';
			}
		}
		return ret;
	}
};