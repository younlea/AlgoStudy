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