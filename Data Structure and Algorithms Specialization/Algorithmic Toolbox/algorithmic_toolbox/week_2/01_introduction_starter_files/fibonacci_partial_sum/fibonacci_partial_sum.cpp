#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int fibonacci_sum_last_digit(long long n) {
    std::vector<long long> modarr={0,1};
    long long previous = 0;
    long long current  = 1;
    for (long long i = 2; i <=(n+2); ++i) {
	long long tmp=previous%10;
	previous=current%10;
	current=(current+tmp)%10;
	if ((current==0)&&((current+previous)==1)){
		break;
	}		
        modarr.push_back(current);
    }
    long long period=modarr.size();
    long long a_=modarr[(n+2)%period];
    return (a_-1)%10;
}
long long get_fibonacci_partial_sum_eff(long long from, long long to){
	long long lastdig=fibonacci_sum_last_digit(to)-fibonacci_sum_last_digit(from-1);
	return (lastdig<0?lastdig+10:lastdig);
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_eff(from, to) << '\n';
}
