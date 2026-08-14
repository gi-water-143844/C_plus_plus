/*Giovana Ferreira Waterkemper - Estojo de Joias

n -> tamanho da matriz NxN, onde n >= 2 e n <= 50

Objetivo -> Descobrir quantas rotações de 90 graus no sentido anti-horário são
necessárias para que a matriz fique correta. A regra é: Cada linha e cada coluna 
deve estar organizada de forma crescente. Como a caixa é quadrada, há apenas 4 possíveis posições.

entrada: 'n' e os valores de cada posição a[i][j]
saída: total de rotações da caixa de joias

Comentário: eu analisei cada exemplo do site, e como cada um ficaria a cada rotação,
e percebi que havia um padrão, onde é feito a transposta da matriz, transformando coluna em linhas
a cada rotação, da última coluna, até a primeira. Portanto, segui esse raciocínio para resolver
o problema.

link: https://codeforces.com/gym/105327/problem/E

*/

#include <iostream>
#include <vector>
using namespace std;

/*Função responsável por rotacionar a matriz do estojo 90 graus no sentido anti-horário*/
void rotaciona(vector<vector<int>>& estojo, int n) {
    
    //cria uma matriz auxiliar para guardar a matriz rotacionada
    vector<vector<int>> aux(n);     

    //variável auxiliar 'k' para começarmos pela última coluna da matriz original
    int k = n-1;                    
    
    //percorre as linhas da nova matriz
    for(int i=0; i<n; i++) {
        aux[i].resize(n);

        //preenche a linha com os elementos da coluna 'k' da matriz original
        for(int j=0; j<n; j++) {
            aux[i][j] = estojo[j][k];
        }

        //vai uma coluna para 'trás'
        k--;
    }

    //substitui a matriz original pela matriz rotacionada
    estojo = aux;
}

/*Verifica se a matriz está na condição esperada.
Caso contrário, rotaciona e consequentemente vai contando quantas rotações foram necessárias*/
int contador(vector<vector<int>>& estojo, int n) {

    int ct = 0;             //contador de rotações realizadas
    bool teste = false;     //indica se a matriz já está na ordem correta

    //como o estojo é quadrado, há apenas 4 posições possíveis
    while(ct < 4 && !teste){

        //assumimos que está correto antes de verificar
        teste = true;

        //percorre o estojo comparando o elemento atual com o da direita e com o de baixo
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-1; j++) {
                
                //se o elemento atual for maior que algum dos vizinhos analisados, a matriz não está correta (false)
                if((estojo[i][j] > estojo[i+1][j]) || (estojo[i][j] > estojo[i][j+1])) {
                    teste = false;
                }
            }
        }

        //se a matriz não estiver correta, será rotacionada e o código será executado novamente
        //analisando tudo denovo
        if(!teste) {
            rotaciona(estojo,n);
            ct++;                   //houve rotação, logo deve ser contado
        }
    }

    //retorna o número de rotações necessárias
    return ct;
}

int main() {
    int n;
    cin >> n;   //lê o tamanho n da matriz NxN

    //verifica se n está no limite permitido
    if(n>=2 && n<=50){

        //instancia a matriz
        vector<vector<int>> estojo(n);

        //lê todos os valores da matriz
        for(int i=0; i<n; i++) {
            estojo[i].resize(n);
            for(int j=0; j<n; j++) {
                cin >> estojo[i][j];
            }
        }

        //verifica a matriz e guarda a quantidade de rotações necessárias
        int v = contador(estojo, n);

        //mostra o resultado
        cout << v << endl;

    } else {
        // Se o tamanho informado não estiver entre 2 e 50, mostra uma mensagem de erro
        cout << "\nerro!" << endl;
    }
}