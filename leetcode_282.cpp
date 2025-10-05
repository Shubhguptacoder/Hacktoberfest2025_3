class Solution {
public:
    set<string> st;
    void solve(int i, int n, string& s, int target, string temp, long long prev , long long val,
               vector<string>& ans) {
        if (i == n) {
            if (val == target) {
                if (!st.count(temp)) {
                    ans.push_back(temp);
                    st.insert(temp);
                }
            }
            return;
        }
        string temp3 = "";
        for (int k = i; k < n; k++) {
            if (s[i] == '0' && k > i)
                break;
            temp3 += s[k];

            long long val4 = stoll(temp3);
            if (i > 0) {
                solve(k + 1, n, s, target, temp + '+' + temp3, val4 , val + val4, ans);

                solve(k + 1, n, s, target, temp + '-' + temp3, -val4 , val - val4, ans);
                 long long curr_val =  (val-prev)+(prev*val4);
                solve(k + 1, n, s, target, temp + '*' + temp3,prev*val4, curr_val, ans);
            } else
                solve(k + 1, n, s, target, temp + temp3,stoll(temp3), val4, ans);
        }
    }
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        int n = s.length();
        string temp = "";
        long long val = 0;
        long long prev  = 0 ;
        solve(0, n, s, target, temp, prev , val, ans);
        return ans;
    }
};
