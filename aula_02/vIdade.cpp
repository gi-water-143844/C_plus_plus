#include <iostream>
using namespace std;

void verifica_idade(int i){
    if (i < 15) {
        cout << "criança" << endl;
    }
    else if (i < 18) {
        cout << "adolescente" << endl;
    }
    else if (i < 60) {
        cout << "adulto" << endl;
    }
    else {
        cout << "idoso" << endl;
    }
}

int main() {
    int idade;
    cout << "informe sua idade: ";
    cin >> idade;
    verifica_idade(idade);
    return 0;
}