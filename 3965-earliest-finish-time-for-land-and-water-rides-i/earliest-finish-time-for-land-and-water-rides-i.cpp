class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int ans = 2000000000;

        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                
                int landEnd = landStartTime[i] + landDuration[i];
                int waterEnd = waterStartTime[j] + waterDuration[j];
                
                int planA = max(landEnd, waterStartTime[j]) + waterDuration[j];
                int planB = max(waterEnd, landStartTime[i]) + landDuration[i];
                
                ans = min({ans, planA, planB});
            }
        }
    
        return ans;

    }
};