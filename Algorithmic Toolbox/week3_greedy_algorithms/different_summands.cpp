#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int prize = 1;
  int temp = n;
  while(n != 0){
    if(n - prize >= prize && n - prize != prize){
      n -= prize;
      summands.push_back(prize);
      prize += 1;
      }
    else{
      summands.push_back(n);
      n = 0;
      break;
      }
  }
  return summands;
}

int main() {
  int n;
     cin >> n;
  vector<int> summands = optimal_summands(n);
     cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
     cout << summands[i] << ' ';
  }
}
