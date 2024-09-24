#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int N = 4, M = 6;
    
    cout << "The LCM of " << N << " and " << M << " is: " 
         << lcm(N, M) << endl;

    return 0;
}
