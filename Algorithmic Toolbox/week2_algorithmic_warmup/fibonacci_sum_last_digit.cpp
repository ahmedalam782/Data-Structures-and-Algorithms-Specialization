#include <iostream>
#include <vector>
using namespace std;
long long fibonacci_sum_fast(unsigned long long n) {
    n = n%60 + 1;
    long long fib = 0;
    long long fib_sum = 0;
    if (n <= 1)
	{
    	fib = n;
	}
    else
    {
        vector<long long> fiblist(n);
        fiblist[0] = 0;
        fiblist[1] = 1;
        fib_sum += 1;
        for (int i = 2; i < n ; i++){
            fiblist[i] = fiblist[i-1] + fiblist[i-2];
            fib_sum += fiblist[i];
            }
    }
    return fib_sum%10;
}

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_fast(n)<<endl;
}
