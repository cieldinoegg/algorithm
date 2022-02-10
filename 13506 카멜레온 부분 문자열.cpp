//
// Created by msi on 2022-02-10.
//


using namespace std;
#include <iostream>
#include <string>
#include <vector>

vector<int> pi;

void getPi(string p) {
    int m = p.size(), j = 0;
    pi.resize(m);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    string p;
    cin >> p;
    getPi(p);
    int x = pi[p.length() - 1];
    bool check = false;
    while (x) {
        for (int i = 1; i < p.length() - 1; i++) {
            if (pi[i] == x) {
                for (int j = 0; j < x; j++) {
                    cout << p[j];
                }
                check = true;
                break;
            }
        }
        if (check) {
            break;
        }
        x = pi[x - 1];
    }
    if (!check) {
        cout << -1;
    }
    return 0;
}
