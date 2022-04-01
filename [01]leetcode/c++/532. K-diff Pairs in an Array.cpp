//recommend problem
// EASY : https://leetcode.com/problems/minimum-absolute-difference-in-bst/  (530. Minimum Absolute Difference in BST)
// EASY : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/  (2006. Count Number of Pairs With Absolute Difference K)
// HARD : https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/ (2040. Kth Smallest Product of Two Sorted Arrays)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ret = 0;
        //sorting
        sort(nums.begin(), nums.end(), greater<int>());
        
        if(k == 0)
        {
            int cnt = 0;
            int back = nums[0];
            for(int i =1; i < nums.size(); i++)
            {
                if(back == nums[i])
                {
                    cnt++;
                    while( i <= nums.size()-1)
                    {
                        if(back!=nums[i])
                        {
                            back = nums[i];        
                            break;
                        }
                        i++;                            
                    }
                }else
                    back = nums[i];
            }
            return cnt;
        
        }    
        //delete same vlaue
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        //for loop
        for(int i =0; i < nums.size(); i++)
            for(int j=i+1; j < nums.size(); j++)
            {
                if(nums[i]-nums[j] == k)
                {
                    // cout << nums[i] << "," <<  nums[j] << "(" << i<< "," << j<< ")"<< endl;
                    ret++;  
                    break;
                }
            }
        
        return ret;
    }
};