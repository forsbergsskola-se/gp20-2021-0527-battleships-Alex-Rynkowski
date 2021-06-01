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
    cout << FibonacciRec(n);
    cout << FibonacciIteration(n);
}
