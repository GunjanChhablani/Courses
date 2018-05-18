#include <iostream>
#include <vector>

using std::vector;
vector<int> summands;
vector<int> optimal_summands(int n,int l) {
  //write your code here
  int k=n;
  if (k<=2*l){
  	summands.push_back(k);
  	return summands;
  }
  else{
  	summands.push_back(l);
  }
  optimal_summands(k-l,l+1);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n,1);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
