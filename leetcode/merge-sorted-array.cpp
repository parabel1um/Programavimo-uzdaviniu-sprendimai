class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int left=m;left<m+n;left++){
            nums1[left]=nums2[left-m];
        }
        sort(nums1.begin(), nums1.end());
    }
};