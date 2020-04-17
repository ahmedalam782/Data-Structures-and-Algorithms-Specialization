#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int dist,int tank,vector<int> & stops,int n, vector<int> x) {
    int numberRefill=0,currentRefill=0,lastRefill=0;
    while (currentRefill<=n)
    {
		lastRefill=currentRefill;
    	while (currentRefill <= n && x[currentRefill + 1] -x[lastRefill ]<=tank)
    	{
    		currentRefill++;
		}
		if (currentRefill == lastRefill)
		{
		    return -1;
        }
        if (currentRefill <= n)
            numberRefill++;
	}
    return numberRefill;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    vector<int> x(n+2);
    x.at(0)=0;
    x.at(n+1)=d;
    for (int i = 1; i < n+1; i++)
        x.at(i) = stops.at(i-1);
    cout << compute_min_refills(d, m, stops,n,x) << "\n";

    return 0;
}
