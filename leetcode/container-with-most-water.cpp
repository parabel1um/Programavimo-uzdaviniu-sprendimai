class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, area=0;
        while(left!=right){
            int curr=min(height[left], height[right])*(right-left);
            area=max(curr, area);
            if(height[right]<=height[left]) {
                right--;
            } else left++;
        }
        return area;
    }
};