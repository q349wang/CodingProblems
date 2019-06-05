#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax;
		vector<int> rightMax;

		int lmax = 0;
		for (int i = 0; i < height.size(); i++) {
			leftMax.push_back(lmax);
			if (height[i] > lmax) {
				lmax = height[i];
			}
		}

		int rmax = 0;
		for (int i = height.size() - 1; i >= 0; i--) {
			rightMax.push_back(rmax);
			if (height[i] > rmax) {
				rmax = height[i];
			}
		}

		int rain = 0;
		for (int i = 0; i < height.size(); i++) {
			if (leftMax[i] > rightMax[height.size()-i-1]) {
				int add = rightMax[height.size()-i-1]-height[i];
				if (add > 0) rain += add;
			}
			else {
				int add = leftMax[i]-height[i];
				if (add > 0) rain += add;
			}
		}

		return rain;
    }
};