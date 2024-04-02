class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> s_to_t_mapping;
        unordered_map<char, char> t_to_s_mapping;

        for (int i = 0; i < s.size(); ++i) {
            char s_char = s[i];
            char t_char = t[i];

            // Check if the mapping from s to t is consistent
            if (s_to_t_mapping.find(s_char) != s_to_t_mapping.end()) {
                if (s_to_t_mapping[s_char] != t_char)
                    return false;
            } else {
                s_to_t_mapping[s_char] = t_char;
            }

            // Check if the mapping from t to s is consistent
            if (t_to_s_mapping.find(t_char) != t_to_s_mapping.end()) {
                if (t_to_s_mapping[t_char] != s_char)
                    return false;
            } else {
                t_to_s_mapping[t_char] = s_char;
            }
        }

        return true;
    }
};