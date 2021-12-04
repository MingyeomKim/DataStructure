#include <iostream>
using namespace std;

int iterative(int i, int j);
int recursive(int n, int m);

int main() {
    int a, b;
    cout << "Enter two integer: ";
    cin >> a >> b;
    cout << "[Iteration] G.C.D. of " << a << " and " << b << " is " << iterative(a, b) << endl;
    cout << "[Recursion] G.C.D. of " << a << " and " << b << " is " << recursive(a, b) << endl;
}

int iterative(int i, int j) {
    int temp, q;
    if (i < j) {
        temp = i;
        i = j;
        j = temp;
    }

    while (j != 0) {
        q = i % j;
        i = j;
        j = q;
    }
    return i;
}

int recursive(int n, int m) {
    if (m == 0) {
        return n;
    }
    else {
        return recursive(m, n % m);
    }
}
