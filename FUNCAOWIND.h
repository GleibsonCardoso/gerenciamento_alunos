#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <algorithm>

using namespace std;


struct Alunos {
    string nome;
    string sobrenome;
    float notas[4];
    int serie;
    float media;
    int ativo;
};

Alunos estudante[100];

void menu();
void cadastrar();
void pesquisaMatricula();
void pesquisarSerie();
void media();
void mostrarLista();
void excluir();
void listarArqu();



void menu(){
   
   
   int opcao;
   
   do{
        system("cls");
         
   
    cout << "--------  MENU  ---------------" << endl;
    cout << "1 - CADASTRAR ALUNO" << endl; // CADASTRA O ALUNO COM OS PARAMETROS DEFINIDOS NO STRUCT;
    cout << "2 - PESQUISAR POR MATRICULA" << endl; // MOSTRA O CADASTRO DO ALUNO REFERENTE A MATRICULA DIGITADA;
    cout << "3 - PESQUISAR POR SÉRIE" << endl; // MOSTRA TODOS OS ALUNOS DA SERIE DIGITADA;
    cout << "4 - MÉDIA DE NOTAS POR SÉRIE" << endl; // MOSTRA A MEDIA DE NOTAS DE CADA ALUNO DA SERIE DIGITADA;
    cout << "5 - MOSTRAR ULTIMOS ALUNOS MATRICULADOS" << endl; // MOSTRA A LISTA DE ALUNOS MATRICULADOS EM SEQUENCIA NUMÉRICA GERANDO UM NÚMERO DE MATRÍCULA;
    cout << "6 - EXCLUIR ALUNO" << endl; // EXCLUI UM ALUNO NA LISTA;
    cout << "7 - LISTAR ATUALIZADA DE ALUNOS" << endl; // MOSTRA A LISTA DE ALUNOS QUE ESTÁ NO ARQUIVO .TXT;
    cout << "0 - SAIR "<< endl; // OPÇÃO PARA SAIR DO MENU;
    cout << endl << "DIGITE SUA OPÇÃO e PRESSIONE ENTER.: "; // OPÇÃO DE ESCOLHA DA AÇÃO;

    cin >> opcao;

    getchar();
    switch (opcao){
        case 1: cadastrar(); // chama a função de cadastro;
            break;
        case 2: pesquisaMatricula(); // chama a função de pesquisa por MATRICULA;
            break;
        case 3: pesquisarSerie(); // chama a função de pesquisa por serie;
            break;
        case 4: media(); // chama a função de média;
            break;
        case 5: mostrarLista(); // mostra toda os alunos matriculados;
            break;
        case 6: excluir(); // chama a função de excluir aluno;
            break;
        case 7: listarArqu(); // lista as informações do arquivo;
        break;
        }
    getchar();
    } while (opcao!=0);
}

void cadastrar(){
 
    string nome;
    string sobrenome;
    float notas[4];
    int serie;
    int op;

    do{
    system("cls");
     
   
        cout << endl << "Nome...............: ";
        cin >> nome;

        cout << endl << "Sobrenome..........: ";
        cin >> sobrenome;
       
        cout << endl << "SERIE..............: ";
        cin >> serie;      
       
        cout << endl << "------- NOTAS ---------" << endl;

        cout << endl << "1 - BIMESTRE.......: ";
        cin >> notas[0];
       
        cout << endl << "2 - BIMESTRE.......: ";
        cin >> notas[1];
       
        cout << endl << "3 - BIMESTRE.......: ";
        cin >> notas[2];

        cout << endl << "4 - BIMESTRE.......: ";
        cin >> notas[3];
       
    for (int i = 0; i < 100; i++){
        if (estudante[i].ativo==0){

            estudante[i].nome = nome;
            estudante[i].sobrenome = sobrenome;
            estudante[i].notas[0]= notas[0];
            estudante[i].notas[1]= notas[1];
            estudante[i].notas[2]= notas[2];
            estudante[i].notas[3]= notas[3];
            estudante[i].serie = serie;
            estudante[i].ativo=1;
            estudante[i].media = (notas[0]+notas[1]+notas[2]+notas[3])/4.0;
        break;
        }
    }
   
    ofstream arquivo;
                   
        arquivo.open("Alunos.txt",ios::app);
        arquivo << endl << "Nome: " << nome << " " << sobrenome;
        arquivo << endl << "SERIE..............: " << serie << endl;  
        arquivo << endl << "------- NOTAS ---------" << endl;
        arquivo << "1 - BIMESTRE.......: " << notas[0] << endl;
        arquivo << "2 - BIMESTRE.......: " << notas[1] << endl;
        arquivo << "3 - BIMESTRE.......: " << notas[2] << endl;
        arquivo << "4 - BIMESTRE.......: " << notas[3] << endl;
        arquivo << "MEDIA..............: " << (notas[0]+notas[1]+notas[2]+notas[3])/4.0 << endl;
        arquivo.close();
   
   
    cout << endl << "1 - CONTINUAR" << endl;
    cout << "0 - SAIR" << endl;
    cin >> op;

    } while(op!=0);
}
   

void mostrarLista(){
    system("cls");
     
   
    cout << "----------------------------" << endl;
    cout << " LISTA DE ULTIMOS CADASTROS " << endl;
    cout << "----------------------------" << endl;


       
    for (int i = 0; i < 100; i++){
        if (estudante[i].ativo == 1){
            cout << "Matricula: " << i+1 << endl;
            cout << "Nome:  " << estudante[i].nome << endl;
            cout << "SERIE: " << estudante[i].serie << "  Ano - Medio" << endl;
            cout << endl << "------- NOTAS ---------" << endl;
            cout << "1 BIM: " << estudante[i].notas[0] << endl;
            cout << "2 BIM: " << estudante[i].notas[1] << endl;
            cout << "3 BIM: " << estudante[i].notas[2] << endl;
            cout << "4 BIM: " << estudante[i].notas[3] << endl;
            cout << "Media: " << estudante[i].media << endl;
            cout << "--------------------" << endl;
        }
    }
    cout << "PRESSIONE ENTER E VOLTE PARA O MENU. ";    
}

void excluir(){
   
    system("cls");
     
   
    int matricula;
   
    for (int i = 0; i < 100; i++){
        if (estudante[i].ativo == 1){
            matricula = i+1;
        }
       
    }
   
    cout << "Digite a matricula para excluir: ";
    cin >> matricula;
    --matricula;
   
   if (estudante[matricula].ativo == true)
   { estudante[matricula].ativo=0;
     cout << "Aluno excluido com sucesso!" << endl;
     cout << "PRESSIONE ENTER E VOLTE PARA O MENU. ";  

    }
    else
    {
        cout << "Matricula invalida - PRESSIONE ENTER E VOLTE PARA O MENU. ";
   
    }

    getchar();
}

void pesquisaMatricula(){
    system("cls");
     
   
    cout << "-------------------------------" << endl;
    cout << "PESQUISA DE ALUNOS MATRICULADOS" << endl;
    cout << "-------------------------------" << endl;
    int matricula;
   
    for (int i = 0; i < 100; i++){
        if (estudante[i].ativo == 1){
            matricula = i;
        }
    }
    cout << "MATRICULA.........: ";
    cin >> matricula;
    --matricula;

    if (estudante[matricula].ativo == true){
            cout << endl;
            cout << "Nome:  " << estudante[matricula].nome << endl;
            cout << "SERIE: " << estudante[matricula].serie << "  Ano - Medio" << endl;
            cout << "1 BIM: " << estudante[matricula].notas[0] << endl;
            cout << "2 BIM: " << estudante[matricula].notas[1] << endl;
            cout << "3 BIM: " << estudante[matricula].notas[2] << endl;
            cout << "4 BIM: " << estudante[matricula].notas[3] << endl;
            cout << "--------------------" << endl;
     cout << "PRESSIONE ENTER E VOLTE PARA O MENU. ";  

    }
    else
    {
        cout << "Matricula invalida - PRESSIONE ENTER E VOLTE PARA O MENU. ";
   
    }

    getchar();

}

void pesquisarSerie(){
    system("cls");
     
    bool encontrei = false;
   
    cout << "-------------------------------" << endl;
    cout << " PESQUISA DE ALUNOS POR SERIE  " << endl;
    cout << "-------------------------------" << endl;
   
    int SERIE;

    cout << "SERIE....: ";
    cin >> SERIE;
   
    for (int i = 0; i < 100; i++){
       
        if (estudante[i].serie == SERIE){
           
            cout << "Nome:  " << estudante[i].nome << endl;
            cout << "1 BIM: " << estudante[i].notas[0] << endl;
            cout << "2 BIM: " << estudante[i].notas[1] << endl;
            cout << "3 BIM: " << estudante[i].notas[2] << endl;
            cout << "4 BIM: " << estudante[i].notas[3] << endl;
            cout << "Media: " << estudante[i].media << endl;
            cout << "--------------------" << endl;
            encontrei = true;
        }

    }
    if(encontrei==false){
    cout << "Serie nao cadastrada"<< endl;
}
    cout << "PRESSIONE ENTER E VOLTE PARA O MENU. ";
    getchar();  
}

void media(){
    system("cls");
     
    
    cout << "-------------------------------" << endl;
    cout << "  MEDIA DOS ALUNOS POR SERIE  " << endl;
    cout << "-------------------------------" << endl;
   
    int SERIE;
    bool encontrei = false;

    cout << "SERIE....: ";
    cin >> SERIE;
    float acumuladorTurma = 0;
    float mediaTurma = 0;
    
    for (int i = 0; i < 100; i++){
        
        if (estudante[i].serie == SERIE){
            cout << "Nome:  " << estudante[i].nome << endl;
            cout << "Media: " << estudante[i].media << endl;
            
            mediaTurma += estudante[i].media;

            acumuladorTurma +=1;
            
            encontrei = true;
        }
    }
    if (encontrei == true){
        cout << endl <<"A media desta turma é: " << mediaTurma/(acumuladorTurma) << endl;
    }
        
    if(encontrei==false){
        cout << "A série não contém alunos cadastrados"<< endl;
    }

    cout << endl;
    cout << "PRESSIONE ENTER E VOLTE PARA O MENU. "; 
    getchar();   
}

void listarArqu(){
    system("cls");
     

        ifstream arquivo;
        arquivo.open("Alunos.txt");
        string linha;

    while(getline(arquivo,linha) ){
        cout << linha;
        cout << endl;
    }

cout << "PRESSIONE ENTER E VOLTE PARA O MENU. ";

}