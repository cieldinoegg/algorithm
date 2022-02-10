//
// Created by msi on 2022-02-10.
//

using namespace std;
#include <iostream>
#include <string>
#include <vector>

char s[200001];
int siz = 0;


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

vector<int> kmp(string p) {
    vector<int> ans;
    vector<int> pi = getPi(p);
    int n = siz, m = p.size(), j = 0;
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
    string a, p;
    cin >> a >> p;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9') {
            continue;
        }
        else {
            s[siz] = a[i];
            siz++;
        }
    }
    vector<int> matched = kmp(p);
    if (matched.empty()) {
        cout << "0";
    }
    else {
        cout << "1";
    }
    return 0;
}
