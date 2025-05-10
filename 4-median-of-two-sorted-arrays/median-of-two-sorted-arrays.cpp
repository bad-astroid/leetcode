class Solution {
public:
    int getNum(vector<int>& nums, int index) {
        if(index == -1) return -1e6 - 1;
        if((int) nums.size() == index) return 1e6 + 1;
        return nums[index];
    }
    int check(vector<int>& nums1, vector<int>& nums2, int m) {
        int index1 = m - 1;
        int index2 = (nums1.size() + nums2.size())/2 - m - 1;

        int n11 = getNum(nums1, index1);
        int n12 = getNum(nums1, index1 + 1);
        int n21 = getNum(nums2, index2);
        int n22 = getNum(nums2, index2 + 1);

        if(n21 > n12) {
            return 1;
        }

        if(n11 > n22) {
            return -1;
        }

        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0, r = nums1.size();
        while(l <= r) {
            int m = (l + r) / 2;
            int val = check(nums1, nums2, m);

            if(val == 0) {
                int index1 = m - 1;
                int index2 = (nums1.size() + nums2.size()) / 2 - m - 1;

                if((nums1.size() + nums2.size()) % 2 == 1) {
                    return min(getNum(nums1, index1 + 1), getNum(nums2, index2 + 1));
                }
                return (min(getNum(nums1, index1 + 1), getNum(nums2, index2 + 1)) + max(getNum(nums1, index1), getNum(nums2, index2)))/ 2.0;
            }

            if(val < 0) r = m - 1;
            else l = m + 1;
        }

        return 0;
    }
};