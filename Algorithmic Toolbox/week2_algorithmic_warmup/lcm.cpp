#include <iostream>
using namespace std;
long long  GCD(long  a , long  b) {
	if (b == 0)
		return a; 
	long long A=a%b;
	
	return GCD(b,A); 
}
long long LCM(long long  a, long long  b) {
	return a*b /GCD(a,b);
}
int main() {
  int a, b;
  cin >> a >> b;
//  cout << GCD(a, b) << endl;
  cout <<LCM(a, b) << endl;
  return 0;
}
