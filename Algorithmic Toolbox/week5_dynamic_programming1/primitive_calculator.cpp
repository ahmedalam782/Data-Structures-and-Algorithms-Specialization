#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n){
  vector<int> sequence;
  if (n == 0) {
    sequence.push_back(0);
    return sequence;
    }
  else if(n==1){
    sequence.push_back(1);
    return sequence;
    }
  vector<int> forward_seq(n+1);
  forward_seq[0] = 0;
  for (int i = 1;i <= n;i++){
    forward_seq[i] = forward_seq[i-1] + 1;
    if (i%2 == 0){
      if (i == 2){forward_seq[i] = 1;}
      else{forward_seq[i] = min(forward_seq[i/2] + 1, forward_seq[i]);}
      }
    if (i%3==0){
      if (i == 3){forward_seq[i] = 1;}
      else{forward_seq[i] = min(forward_seq[i/3]+1, forward_seq[i]);}
      }
  }
  while (n > 0){
    sequence.push_back(n);
      if (n==2 || n==3){
        sequence.push_back(1);
        return sequence;
    }
    if (forward_seq[n] == forward_seq[n-1] + 1) {n -= 1;}
    else if (n % 2 == 0 && forward_seq[n] == forward_seq[n/2] + 1) {n /= 2;}
    else if (n % 3 == 0 && forward_seq[n] == forward_seq[n/3] + 1) {n /= 3;}
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
