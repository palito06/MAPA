#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    char A[20],B[20];
    char letrasDA[20];
    char letrasDB[20];

    system("cls");

    cout << "digite uma fraze qualquer: " ;
    cin >> A;
    cout << endl << "digite outra frase: " << endl;
    cin >> B;

    for (int i= 0 ; i < 19 ; i++)
    {
        for (int j = i + 1 ; j < 19 ; j++)
        {
            if (A[i] != B[j])
            {
                letrasDA[i] = A[i];
                letrasDB[i] = B[i];
            }
        }
    }

    for (int i= 0 ; i < 20 ; i++){
        cout << A[i];
    }
    
    cout <<"As letras diferentes sao: ";
    for( int i=0 ; i < 20 ; i++){
        cout << letrasDA << endl << letrasDB << endl;
    }

    return 0;
}