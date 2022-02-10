//
// Created by msi on 2022-02-10.
//

using namespace std;
#include <iostream>
#include <string>
#include <vector>

vector<int> getPi(string p) {
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

vector<int> kmp(string s, string p) {
    vector<int> pi = getPi(p);
    vector<int> ans;
    int n = s.size(), m = p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m-1) {
                ans.push_back(i-m+1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ans;
}

int main() {
    string s, p;
    cin >> s >> p;
    vector<int> matched1 = kmp(s, p);
    int temp1 = matched1.size();
    s = s + s;
    vector<int> matched2 = kmp(s, p);
    int temp2 = matched2.size();
    cout << temp2 - temp1;
    return 0;
}
