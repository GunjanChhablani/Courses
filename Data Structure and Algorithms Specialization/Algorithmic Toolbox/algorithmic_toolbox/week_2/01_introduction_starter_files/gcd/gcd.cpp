#include <iostream>

int gcd_eff(int a, int b) {
	if (b==0){
		return a;
  }
	int a_=a%b;
	return gcd_eff(b,a_);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_eff(a, b) << std::endl;
  return 0;
}
