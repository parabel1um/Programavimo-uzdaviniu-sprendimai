class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxSum=sum;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i]-nums[i-k];
            maxSum=max(maxSum, (double)sum);
        }

        // use this for setprecision when we dont need to print 
        double res=maxSum/k;
        return round(res*100000.0)/100000.0;
    }
};