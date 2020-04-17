#include <iostream>
#include <vector>
using namespace std;
long long fibonacci_sum_squares_fast(long long n) {
    if(n%60 == 0)
	{
    	n = 0;
	}
    else
	{
    	n = n%60+1;
	}
    int fib = 0;
    long long area = 0;
    if (n <= 1)
	{
	area = n;
	}
    else
    {
        vector<long long> fiblist(n+1);
        fiblist[0] = 0;
        fiblist[1] = 1;
        for (int i = 2; i < n+1 ; i++)
		{
		fiblist[i] = (fiblist[i-1] + fiblist[i-2])%10;
		}
        fib = fiblist[n];
        area = (fiblist[n]*fiblist[n-1])%10;
    }
    return area;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
