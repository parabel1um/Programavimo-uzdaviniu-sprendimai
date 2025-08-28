class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        // auto it = upper_bound(numbers.begin(), numbers.end(), target);
        // int right = static_cast<int>(it-numbers.begin())-1; // converts ssize_t(it-numbers.begin()) to int
        int right=numbers.size()-1;

        while(numbers[left]+numbers[right]!=target){
            long long numberToLook=target-numbers[left];
            if(numbers[right]>numberToLook) right--;
            else left++;
        }
        return {min(left, right)+1, max(left, right)+1};
    }
};