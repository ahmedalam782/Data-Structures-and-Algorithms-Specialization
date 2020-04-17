#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>
using namespace std;
int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  int mid = 0;
  while(a[mid] != x){
    mid = floor((left+right)/2);
    if((mid == right || mid == left) && (mid != x))
	{
     	return -1;
	}
    else if(a[mid] < x)
	{
	left = mid;
	}
    else
	{
	right = mid;
	}
  }
  return mid;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
       cin >> a[i];
  }
  int m;
     cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
       cout << binary_search(a, b[i]) << ' ';
  }
}
