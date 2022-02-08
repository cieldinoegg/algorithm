//
// Created by msi on 2022-02-08.
//

#include <bits/stdc++.h>
using namespace std;

vector <tuple<int, int, int>> a;
vector <tuple<int, int, int>> result;

bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
    return get<0>(x) < get<0>(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        a.push_back({s, e, c});
    }
    sort(a.begin(), a.end(), cmp);
    int s, e, c;
    for (int i = 0; i < a.size(); i++) {
        if (i == 0) {
            s = get<0>(a[0]);
            e = get<1>(a[0]);
            c = get<2>(a[0]);
        }
        else {
            if (get<0>(a[i]) <= e) {
                e = max(e, get<1>(a[i]));
                c = min(c, get<2>(a[i]));
            }
            else {
                result.push_back({s, e, c});
                s = get<0>(a[i]);
                e = get<1>(a[i]);
                c = get<2>(a[i]);
            }
        }

        if (i == a.size() - 1) {
            result.push_back({s, e, c});
        }
    }

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << get<0>(result[i]) << " " << get<1>(result[i]) << " " << get<2>(result[i]) << "\n";
    }
    return 0;
}