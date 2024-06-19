class Solution {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int min, max, mid; // for binary search
		int nflowers, nwreaths; // to calculate wreaths

		// see if solution possible
		if (1L * m * k > bloomDay.size()) {
			return -1;
		}

		// binary search
		min = 0;
		max = *max_element(bloomDay.begin(), bloomDay.end());
		while (max > min) {
			mid = (min + max) / 2;
			// count number of wreaths
			nflowers = 0;
			nwreaths = 0;
			for (int bloom : bloomDay) {
				if (mid >= bloom) {
					nflowers++;
					if (nflowers >= k) {
						nwreaths++;
						nflowers = 0;
					}
					if (nwreaths >= m) {
						break;
					}
				}
				else {
					nflowers = 0;
				}
			}
			// adjust binary search
			if (nwreaths < m) {
				min = mid + 1;
			}
			else {
				max = mid;
			}
		}

		return min;
	}
};
