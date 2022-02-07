//
// Created by msi on 2022-02-07.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> a[5001];
vector<pair<int, int>> h;
int high[5001] = {};

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second > y.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> high[i];
        h.push_back({i, high[i]});
    }
    sort(h.begin(), h.end(), cmp);
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        if (high[temp_1] > high[temp_2]) {
            a[temp_2].push_back(temp_1);
        }
        else {
            a[temp_1].push_back(temp_2);
        }
    }
    int result[5001] = {};
    for (int i = 0; i < n; i++) {
        int temp = h[i].first;
        for (int j = 0; j < a[temp].size(); j++) {
            result[temp] = max(result[temp], result[a[temp][j]]);
        }
        result[temp]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
    return 0;
};