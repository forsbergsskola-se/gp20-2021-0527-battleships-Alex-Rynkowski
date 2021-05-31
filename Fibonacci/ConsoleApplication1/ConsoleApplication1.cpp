#include <iostream>
using namespace std;

int FibonacciRec(int n){
    if (n == 1 || n == 0){
        return n;
    }
    return FibonacciRec(n - 1) + FibonacciRec(n - 2);
}

void FibonacciIteration(int n){
    int num1 = 0, num2 = 1;
    for (int i = 0; i < n; i++){
        cout << " " << num1;
        const int num = num1 + num2;
        num1 = num2;
        num2 = num;
    }
}

int main(){
    const int n = 20;
    int i = 0;
    while (i < n){
        cout << " " << FibonacciRec(i);
        i++;
    }
    cout << endl;
    FibonacciIteration(n);
}
