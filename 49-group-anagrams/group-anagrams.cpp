class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector <string>> anagrams;

        for(int i = 0; i < strs.size(); i++){
            string t = strs[i];
            sort(t.begin(),t.end());

            anagrams[t].push_back(strs[i]);
        }

        vector<vector<string>> answer;

        for(auto it : anagrams){
            answer.push_back(it.second);
        }

        return answer; 
    }
};