/*GRUPO COMPOSTO POR TRÊS ALUNOS:

Aluno:  Gleibson Cardoso Rodrigues
Matrícula: 20192430010
Aluno: Ronaldo Paulo da Silva Filho
Matrícula: 20192430021
Aluno: Leandro Freire de Mendonça Soares
Matrícula: 20192430012

Usamos uma biblioteca externa chamada FUNCAO.h para guardar o struct e as funções usadas pelo sistema*/

#include <iostream>
#include "FUNCAOWIND.h"

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
        system("cls");
        
    }
    return 0;
}

