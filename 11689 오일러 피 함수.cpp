#include <iostream>
#include <vector>
using namespace std;
using namespace std;
#define N 1000000

bool check[N + 1];
vector<long long> prime_num;
void prime() {
    for (int i = 2; i <= N; i++) check[i] = true;
    for (long long i = 2; i <= N; i++)
        if (check[i]) {
            prime_num.push_back(i);
            for (long long j = i*i; j <= N; j += i) check[j] = false;
        }
}

long long euler (long long v) {
    long long result = 1;
    for(auto now: prime_num){
        long long temp = 1;
        while (v % now == 0) {
            v /= now;
            temp *= now;
        }
        if (temp != 0){
            result *= (temp - (temp / now));
        }
    }
    if (v != 1) result = (v - 1);
    return result;
}

int main() {
    long long n;
    cin >> n;
    prime();
    cout << euler(n);
}