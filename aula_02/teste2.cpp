#include <iostream>
using namespace std;
 
int main() {
    int a,b,c,d,x,y;
    cin >> a >> b >> c >> d;
    x = c+d;
    y = a+b;
    if (b>c && d>a && x>y && c>0 && d>0 && a%2==0) {
        cout << "valores aceitos" << endl;
    } else {
        cout << "valores não aceitos" << endl;
    }
    return 0;
}