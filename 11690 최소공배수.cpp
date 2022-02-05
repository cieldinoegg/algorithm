//
// Created by msi on 2022-02-05.
//
#include <vector>
#include <iostream>
using namespace std;

bool check[100000001] = {};

vector <long long> prime_num;
void prime(int n) {
    for (long long i = 2; i <= n; i++) {
        if (!check[i]) {
            prime_num.push_back(i);
            for (long long j = i * i; j <= n; j += i) check[j] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    prime(n);
    long long result = 1;
    long long mod = 4294967296;
    for (int i = 0; i < prime_num.size(); i++) {
        long long temp = 1;
        while (true) {
            if (temp * prime_num[i] <= n) {
                temp *= prime_num[i];
            }
            else {
                break;
            }
        }
        result *= temp;
        result %= mod;
    }
    cout << result;
    return 0;
}