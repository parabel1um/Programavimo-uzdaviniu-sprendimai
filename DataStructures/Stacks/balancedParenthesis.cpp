#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> st;
    map<char, char> br = {
        {'(', ')'}, {'{', '}'}, {'[', ']'}, // two cases
        {')', '('}, {'}', '{'}, {']', '['} 
    };

    string s;
    cin >> s;
    bool ok = true;

    for (char c : s) {
        if (br.count(c) && (br[c] == ')' || br[c] == '}' || br[c] == ']')) {
            st.push(c);
        }
        else if (br.count(c)) {
            if (st.empty() || st.top() != br[c]) {
                ok = false;
                break;
            }
            st.pop();
        }
    }

    if (!st.empty()) ok = false;
    cout << ok << "\n";
    return 0;
}
