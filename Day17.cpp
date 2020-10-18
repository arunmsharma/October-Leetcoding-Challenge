//Day 17
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>st;
        unordered_set<string>ans;
        int n = s.size();
        if(n<10){   
            return {};
        }
        for(int i=0;i+9<n;i++){
            string t = s.substr(i,10);
            if(st.find(t)!=st.end()){
                ans.insert(t);
            }
            st.insert(t);
        }
        vector<string>v;
        for(string x:ans){
            v.push_back(x);
        }
        // sort(v.begin(),v.end());
        return v;
    }
};
