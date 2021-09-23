/* Neste código interativo, vamos fazer um código estruturado, contendo subrotinas de cadastro para manipular um struct com os atributos: nome, idade e sexo. */

#include <iostream>
#include <cstdlib>

using namespace std;

int pos = -1;

typedef struct cadastro reg; //define o tipo de typedef struct como nome de 'cadastro' com alias reg.

struct cadastro 
{
  string nome [3];
  int idade   [3];
  char sexo   [3];
};

reg tabCad;  //criando tabela como nome 'tabCad'
reg *ptrCad = &tabCad ; //criando ponteiro do tipo 'reg' e apontando para a tabela 'tabCad' utilizando & para fazer ref a memória, e assim acessar todo o struct através do ponteiro 'ptrCad'.

//minhas subrotinas
string lerNome  ();
int    lerIdade ();
char   lerSexo  ();
void   novoCad  ();
void   listCad  ();
void   controle ();

int main () {
  setlocale(LC_ALL, "Portuguese");
  controle ();
  return 0;
}

string lerNome  ()
{
  cin.ignore();
  string nome;
  cout << "\nDigite o Nome.: ";
  getline(cin, nome);
  return nome;
}

int    lerIdade ()
{
  int idade;
  cout << "\nDigite a Idade.: ";
  cin >> idade;
  return idade;
}

char   lerSexo  ()
{
  char sexo;
  cout << "\nDigite o Sexo (F/M).: ";
  cin >> sexo;
  return sexo;
}

void   novoCad  ()
{
  pos ++;
  if (pos >= 3) {
    cout << "\nLimite de dados foi atingido!" << endl;
    system ("sleep 4");
  }
  else {
    string auxNome        = lerNome ();
    ptrCad -> nome  [pos] = auxNome;
    ptrCad -> idade [pos] = lerIdade ();
    ptrCad -> sexo  [pos] = lerSexo  ();
  }
  
}

void   listCad  ()
{
  if (pos == -1) 
  {
    cout << "\nLista vazia!" << endl;
  }

  else
  {
    cout << "\nPosição  Nome    Idade   Sexo" << endl;
      for (int i = 0; i <= pos; i ++)
      {
        cout << i << "       " << ptrCad -> nome [i] << "     " << ptrCad -> idade [i] << "     " << ptrCad -> sexo [i] << endl;
      }
  }  
system ("sleep 4");
}

void   controle ()
{
  int opcItem;
  while (true)
  {
    system ("clear");
    cout << "\n***   Menu de Controle   ***";
    cout << "\n1 - Ler dados \n2 - Listar \n3 - Sair \nOpção.: ";
    cin >> opcItem;

    switch (opcItem)
    {
      case 1: novoCad(); break;
      case 2: listCad(); break;
      case 3: exit (0);  break;
      default: cout << "\nError: Opção Inválida!" << endl; system ("sleep 4"); break;
    }
  }
}