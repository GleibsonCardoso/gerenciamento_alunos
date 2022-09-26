#include <iostream>
#include "FUNCAO.h"

int main(){

setlocale(LC_ALL,"Portuguese");

int select;

    cout << "***********************************" << endl << endl;
    cout << "        Cadrastro de alunos       " << endl << endl;
    cout << "***********************************" << endl << endl;
    
    cout << " 1 - cotinuar" << endl;
    cout << " 0 - sair" << endl << endl;
    cout << "DIGITE SUA OPÇÃO e PRESSIONE ENTER.: ";
    cin >> select;

    if (select == 1){
        menu ();
    }else{
        system("clear");
        system("cls");
    }
    return 0;
}

