#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here

  for(int i=0;i<weights.size();i++){
    int currindex;
  	if (capacity==0){return (value);}
  	double valbyw=0;
    double valbymax=-1;
  	for(int j=0;j<weights.size();j++){
  	  if (weights[j]>0){
  			valbyw=(double)values[j]/weights[j];
  			if (valbyw>valbymax){
  				valbymax=valbyw;
  				currindex=j;
  			}
  		}		
  	}
  	double a=(weights[currindex]<capacity?weights[currindex]:capacity);
  	value=value+a*((double)values[currindex]/weights[currindex]);
  	weights[currindex]=weights[currindex]-a;
  	capacity=capacity-a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout<<optimal_value<<std::endl;
  return 0;
}
