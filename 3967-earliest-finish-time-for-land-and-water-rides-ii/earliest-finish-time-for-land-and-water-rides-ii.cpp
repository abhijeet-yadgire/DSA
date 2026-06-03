class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minLandEnd = 2e9;
        int minWaterEnd = 2e9;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        for(int i = 0; i < n; i++) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }
            
        for(int i = 0; i < m; i++) {
            minWaterEnd = min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
        }
        
        int earliestFinish = 2e9;
        
        for(int i = 0; i < m; i++) {
            int finishTime = max(minLandEnd, waterStartTime[i]) + waterDuration[i];
            earliestFinish = min(earliestFinish, finishTime);
        }
            
        for(int i = 0; i < n; i++) {
            int finishTime = max(minWaterEnd, landStartTime[i]) + landDuration[i];
            earliestFinish = min(earliestFinish, finishTime);
        }
            
        return earliestFinish;   
    }
};