#include <iostream>
#include <vector>
/*long long fib(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
    if (f[n])
        return f[n];
 
    int k = (n & 1)? (n+1)/2 : n/2;

    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
           : (2*fib(k-1) + fib(k))*fib(k);
 
    return f[n];
}
*/

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

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_last_digit(n)<<std::endl;
}
