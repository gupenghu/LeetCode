// Implement int sqrt(int x).

// Compute and return the square root of x.



// Subscribe to see which companies asked this question.
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) {
			return 0;
		}
		double m = x;
		double n = m/2;
		while(m/n - n > 0.000001 || n-m/n >0.000001){
			n = (n + m/n)/2;
		}
		return n;
	}
};