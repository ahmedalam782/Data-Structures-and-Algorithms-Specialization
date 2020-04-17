  
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int ED_matrix[str1.size()+1][str2.size()+1];
  int i, j, insertion, deletion, match, mismatch;
  for(i = 0; i <= str1.size(); i++){ED_matrix[i][0] = i;}
  for(j = 0; j <= str2.size(); j++){ED_matrix[0][j] = j;}
  for(j = 1; j <= str2.size(); j++){
    for(i = 1; i <= str1.size(); i++){
      insertion = ED_matrix[i][j-1] + 1;
      deletion = ED_matrix[i-1][j] + 1;
      match = ED_matrix[i-1][j-1];
      mismatch = ED_matrix[i-1][j-1] + 1;
      if(str1[i-1] == str2[j-1]){ ED_matrix[i][j] = min( min(insertion, deletion), match); }
      else{ ED_matrix[i][j] = min( min(insertion, deletion), mismatch); }
    }
  }
  return ED_matrix[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
