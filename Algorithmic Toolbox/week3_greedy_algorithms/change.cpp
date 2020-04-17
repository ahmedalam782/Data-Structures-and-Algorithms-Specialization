#include <iostream>
#include <math.h>
using namespace std;
int get_change(int m) {
  int n = 0;
  if(m>=10){
     n += floor(m/10); 
     m = m%10;
  }
  if(m>=5){
      n += floor(m/5);
      m = m%5;
  }
  if(m>=1){
     n += floor(m);
     m = m%1;
  }
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
