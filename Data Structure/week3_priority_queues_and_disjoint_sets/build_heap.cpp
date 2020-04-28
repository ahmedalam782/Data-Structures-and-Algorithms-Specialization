#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  // Returns the index of element i on the array data_
  int Parent_idx(int child_idx) {
	  return int((child_idx + 1) / 2);
  }

  int left_child_idx(int parent_idx) {
	  return 2 * parent_idx + 1;
  }

  int right_child_idx(int parent_idx) {
	  return 2 * parent_idx + 2;
  }

  void bubble_down(int idx) {
	  int min_idx = idx;
	
	  int l_idx = left_child_idx(idx);
	  int r_idx = right_child_idx(idx);
	  if ((l_idx < data_.size()) && (data_[l_idx] < data_[min_idx]))
		  min_idx = l_idx;
	  if ((r_idx < data_.size()) && (data_[r_idx] < data_[min_idx]))
		  min_idx = r_idx;

	  if (min_idx != idx) {
		  swap(data_[idx], data_[min_idx]);
		  swaps_.push_back(make_pair(idx, min_idx));
		  bubble_down(min_idx);
	  }
  }

  void GenerateSwaps() {
    swaps_.clear();
	for (int i = int(data_.size()/2); i >= 0; --i)
	{
		
		bubble_down(i);
	}
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
