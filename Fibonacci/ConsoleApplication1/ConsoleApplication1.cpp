#include <chrono>
#include <iostream>
using namespace std;

int FibonacciRec(int n){
    if (n == 1 || n == 0){
        return n;
    }
    return FibonacciRec(n - 1) + FibonacciRec(n - 2);
}

int FibonacciIteration(int n){
    int num1 = 0, num2 = 1, num = 0;;
    for (int i = 1; i < n; i++){
        num = num1 + num2;
        num1 = num2;
        num2 = num;
    }
    return num;
}

int main(){
    int n;
    cin >> n;
    clock_t begin = clock();

    cout << FibonacciRec(n);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << " Time elapsed: " << elapsed_secs << endl;
    begin = clock();
    cout << FibonacciIteration(n);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << " Time elapsed: " << elapsed_secs;
}
