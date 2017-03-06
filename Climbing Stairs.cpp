class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
			return 0;
		}
		double m = x;
		double n = m/2;
		double EPS = 0.000001;
		while(m/n - n > EPS || n-m/n >EPS){
			n = (n + m/n)/2;
		}
		return n;
    }
};