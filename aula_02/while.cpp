#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Informe um valor n: ";
    cin >> n;

    cout << "Tabuada do " << n << endl;
    for (int i=0; i<=10; i++) {
        cout << n << " x " << i << " = " << n*i << endl;
    }
}