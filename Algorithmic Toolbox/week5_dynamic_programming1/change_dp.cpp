#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int get_change(int m, vector<int> &coins) {
  vector<int> MinNumCoins(m + 1);
  MinNumCoins[0] = 0;
  int num_of_coins = 0;
  for(int i = 1; i <= m; i++){
    int MinNumCoins_temp = numeric_limits<int>::max();
    for(int j = 0; j < coins.size(); j++){
      if(i >= coins[j]){
        num_of_coins = MinNumCoins[i - coins[j]] + 1;
        if(num_of_coins < MinNumCoins_temp){MinNumCoins_temp = num_of_coins;}
      }
    }
    MinNumCoins[i] = MinNumCoins_temp;
  }
  return MinNumCoins[m];
}

int main() {
  vector<int> coins;
  coins.push_back(3);coins.push_back(1);coins.push_back(4);
  int m;
  std::cin >> m;
  std::cout << get_change(m, coins) << '\n';
}
