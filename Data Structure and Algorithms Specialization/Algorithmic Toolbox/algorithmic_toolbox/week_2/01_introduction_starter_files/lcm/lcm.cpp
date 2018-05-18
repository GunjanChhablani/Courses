#include <iostream>
long long gcd_eff(long long a, long long b){
	if (b==0){
		return a;
	}
	long long a_=a%b;
	return gcd_eff(b,a_);

}
long long lcm_eff(long long a, long long b) {
  return (a*b)/(gcd_eff(a,b));
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_eff(a, b) << std::endl;
  return 0;
}
