#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    char linha [200];
    FILE *arquivo;

    arquivo = fopen("textoLeitura.txt" , "r");

    if (arquivo == nullptr){
        cout << " desculpa, mas nao a nada para ler aq." << endl;
        system("pause");
    }else{
        rewind(arquivo);
        while (!feof(arquivo)){
            fgets(linha,200,arquivo);
            cout << linha ;

        }
        fclose(arquivo);

    }

    return 0;
}