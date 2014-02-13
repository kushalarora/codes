#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define UNKNOWN_CHARACTER_EXCEPTION -1
#define ILLEGAL_FORMAT_EXCEPTION -2
class Regex {
    private:
        struct State {
            char val;
            bool wildcard;
        };
        vector<State> vec;
        bool matches_state(State state, char c) {
             if (c < 'a' || c > 'z')
                 return false;
            if (state.val == c || state.val == '.')
                return true;
            return false;
        }
    public:
        Regex(string str) {
            for (int i = 0; i < str.length(); i++) {
                char c = str[i];

                if (c >= 'a' && c <= 'z' || c == '.') {
                    State state;
                    state.val = c;
                    state.wildcard = false;
                    vec.push_back(state);
                } else if (c == '*') {
                        State& prev_state = vec[vec.size() - 1];
                        if (i == 0 || prev_state.val == '*')
                            throw ILLEGAL_FORMAT_EXCEPTION;

                        prev_state.wildcard = true;
                } else {
                    throw UNKNOWN_CHARACTER_EXCEPTION;
                }
            }
        }


    bool matches(string str) {
        int i, j;
        for (i = 0, j = 0; i < vec.size(), j < str.length(); i++) {
            // handle wildcard
            if (vec[i].wildcard) {
                // if not found, carry on
                if (!matches_state(vec[i], str[j]))
                    continue;

                // greedy matching
                while(matches_state(vec[i], str[j]))
                    j++;
            } else if (!matches_state(vec[i], str[j])) {
                // doesnt matches a-z or ., doesn't conform to regex
                return false;
            } else {
                // account for current char
                j++;
            }

        }

        if (i == vec.size())
            return true;
        return false;
    }
};


int main() {
    string str1, str2;

    cin >> str1;
    cin >> str2;

    Regex re(str1);
    cout << (re.matches(str2) ? "true" : "false");
}
