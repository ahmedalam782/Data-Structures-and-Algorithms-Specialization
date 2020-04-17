#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool ContainMajority(vector<int> Arr, int n) {
	map<int, int> Freq; 
	for (size_t i = 0; i < n; i++)
		Freq[Arr[i]]++;

	for (int i = 0; i <n; i++)
		if (Freq[Arr[i]] > (n / 2))
			return true; 
	
	return false;
}
int main() {
	int n;
	cin >> n; 
	
	vector<int> Arr(n); 
	for (size_t i = 0; i < n; i++)
		cin >> Arr[i];
	
	cout << ContainMajority(Arr, n) << endl;
}
