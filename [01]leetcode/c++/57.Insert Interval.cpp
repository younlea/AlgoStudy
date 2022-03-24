class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int index = 0 ;
        //newInterval 보다 왼쪽에 있는것들을 자동으로 넣는다. 
        while(index < intervals.size() && intervals[index][1] < newInterval[0]){
            ret.push_back(intervals[index++]);
        }

        //겹치는 부분이 나오면 min, max 연산을 통해서 합친다. 
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[index][0]);
            newInterval[1] = max(newInterval[1],intervals[index][1]);
            ++index;
        }
        ret.push_back(newInterval);

        //newInterval 보다 오른쪽에 있는것들을 자동으로 넣는다. 
        while(index < intervals.size()){
            ret.push_back(intervals[index++]);
        }
        return ret;
    }
};
