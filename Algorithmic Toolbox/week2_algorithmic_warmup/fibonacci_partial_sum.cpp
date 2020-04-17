#include <iostream>
#include <vector>
using namespace std;
long long fibonacci_sum_fast(long long n) {
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    to = to%60;
    from = from%60-1;
    long long sum_from = fibonacci_sum_fast(from);
    long long sum_to = fibonacci_sum_fast(to);
    long diff = sum_to - sum_from;
    if(diff < 0)
	{
    	diff += 10;
	}
    return diff%10;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
