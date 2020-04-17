#include <iostream>
using namespace std;
long long  GCD(long  a , long  b) {
	if (b == 0)
		return a; 
	long long A=a%b;
	
	return GCD(b,A); 
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << GCD(a, b) << endl;
  return 0;
}
