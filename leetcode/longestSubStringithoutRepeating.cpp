class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int maxLength=0;
        int left=0;
        for(int right=0; right<s.size(); right++){
            freq[s[right]]++;

            // we use a while loop instead of an if because
            // theres no guarantee that the duplicate is gone.
            // It may need to KEEP shrinking until the window is valid again.
            
            while (freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            maxLength=max(maxLength, right-left+1);
        }
        return maxLength;
    }
};