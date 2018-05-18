#include <iostream>
#include <vector>
using namespace std;
long long get_fibonacci_huge_eff(long long n, long long m) {
    vector<long long> modarr={0,1};
    long long previous = 0;
    long long current  = 1;
    for (long long i = 2; i <= n; ++i) {
	long long tmp=previous%m;
	previous=current%m;
	current=(current+tmp)%m;
	if ((current==0)&&((current+previous)==1)){
		break;
	}		
        modarr.push_back(current);
    }
    long long period= modarr.size();
    long long a_=modarr[n%period];
    return a_;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_eff(n, m) << '\n';
}
