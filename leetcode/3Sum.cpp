class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i=0;i<nums.size()-1;i++){
            // Jeigu yra besidubliuojančių skaičių
            if (i>0 && nums[i]== nums[i-1]) continue; // tęsiame toliau
            int left = i+1;
            int right = nums.size()-1;

            while(left<right) {
                if(nums[left]+nums[right]+nums[i]==0) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // we have to go to THE VERY LAST OCCURANCE OF A NUMBER
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;

                    left++; right--; // Nes reikia grąžinti ir likusias masyve reikšmes
                } else if (nums[left]+nums[right]+nums[i]>0){
                    right--;
                } else{
                    left++;
                }
            }
        }
        return res;
    }
};