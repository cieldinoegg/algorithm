//
// Created by msi on 2022-02-09.
//

#include <iostream>
using namespace std;
#define N 500000

int check[N + 1] = {};
int number = 0;
void prime(int n) {
    number++;
    check[1] = 1;
    for (long long i = 2; i <= n; i++) {
        if (check[i] == 0) {
            number++;
            check[i] = number;
            for (long long j = i * i; j <= n; j += i) check[j] = number;
        }
    }
}

int main() {
    long long n;
    cin >> n;
    prime(n);
    cout << number << "\n";
    for (int i = 1; i <= n; i++) {
        cout << check[i] << " ";
    }
}