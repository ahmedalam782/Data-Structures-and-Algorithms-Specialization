#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_max_index(vector<double> vw_ratio){
  int max_index;
  max_index = max_element(vw_ratio.begin(),vw_ratio.end()) - vw_ratio.begin();
  return max_index;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> vw_ratio(weights.size());
  for(int i = 0;i < weights.size(); i++){
           vw_ratio[i] = values[i]/(double)weights[i];
  }
  while(capacity != 0){
    int max_index = get_max_index(vw_ratio);
    if(capacity >= weights[max_index]){
      value += weights[max_index]*vw_ratio[max_index];
      capacity -= weights[max_index];
    }
    else{
      value += capacity*vw_ratio[max_index];
      capacity = 0;
    }
    vw_ratio[max_index] = 0;
  }
  
  return value;
}


int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) 
    cin >> values[i] >> weights[i];
  double optimal_value = get_optimal_value(capacity, weights, values);
  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
