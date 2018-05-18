#include <iostream>
int fibonacci_fast(int n){
	int *fibarr=(int*)malloc(sizeof(int)*(n+1));
    fibarr[0]=0;
    fibarr[1]=1;
	for (int i=2;i<=n;i++){
		fibarr[i]=fibarr[i-1]+fibarr[i-2];
	}
    return fibarr[n];
}
int main() {
    int n = 0;
    std::cin >> n;
	std::cout << fibonacci_fast(n) << '\n';
    
    return 0;
}

//cassert to assert something.
