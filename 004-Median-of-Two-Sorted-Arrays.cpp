class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int count = nums1.size() + nums2.size();

		if (count & 0x01) {
			return findKSmallest(&*nums1.begin(), nums1.size(), &*nums2.begin(), nums2.size(), count / 2 + 1);
		} else {
			return (findKSmallest(&*nums1.begin(), nums1.size(), &*nums2.begin(), nums2.size(), count / 2) + findKSmallest(&*nums1.begin(), nums1.size(), &*nums2.begin(), nums2.size(), count / 2 + 1)) / 2.0;
		}
	}

private:
	int findKSmallest(int *nums1, int len1, int *nums2, int len2, int k) {
		if (len1 > len2) {
			return findKSmallest(nums2, len2, nums1, len1, k);
		}

		if (len1 == 0) {
			return nums2[k - 1];
		}

		if (k == 1) {
			return nums1[0] <= nums2[0] ? nums1[0] : nums2[0];
		}

		int a = k / 2;
		if (a > len1) {
			a = len1;
		}

		int b = k - a;

		if (nums1[a - 1] < nums2[b - 1]) {
			return findKSmallest(nums1 + a, len1 - a, nums2, len2, b);
		} else if (nums1[a - 1] > nums2[b - 1]) {
			return findKSmallest(nums1, len1, nums2 + b, len2 - b, a);
		} else {
			return nums1[a - 1];
		}
	}
};