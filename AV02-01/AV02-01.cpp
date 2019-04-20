

//						AVALIAÇÃO 02 - 01
//	GRUPO: AUGUSTO - FÁBIO - GUILHERME VILELA - LAURO - PATRICK

#include "pch.h"
#include <iostream>
#include <string>
#define MAX 5
using namespace std;

int Menu() {
	cout << "1 - INSERIR\r\n";
	cout << "2 - REMOVER\r\n";
	cout << "3 - LISTAR\r\n";
	cout << "4 - ESVAZIAR\r\n";
	cout << "5 - MOSTRAR VAGAS\r\n";
	cout << "6 - CONSULTAR\r\n";
	cout << "7 - ORDERNAR POR NOME\r\n";
	cout << "8 - ORDERNAR POR SALARIO\r\n";
	cout << "0 - SAIR\r\n";
	cout << "AGUARDANDO COMANDO: ";
	int cmd = 0;
	cin >> cmd;
	return cmd;
}

typedef struct {
	string Nome;
	double Salario;
} Funcionario;

typedef struct {
	Funcionario Funcionarios[MAX];
	int Inicio, Fim;
} Lista;

bool Overflow(Lista *Lista) {
	return
		Lista->Fim == MAX ? true : false;
}

bool Underflow(Lista *Lista) {
	return
		Lista->Fim == 0 ? true : false;
}

void Esvaziar(Lista *Lista) {
	for (int i = 0; i < Lista->Fim; i++) {
		Lista->Funcionarios[i].Nome = "";
		Lista->Funcionarios[i].Salario = 0;
	}
	Lista->Fim = 0;
}

void Show(Lista *Lista) {
	if (Underflow(Lista)) {
		cout << "UNDERFLOW" << endl;
		return;
	}
	else
		for (int i = 0; i < Lista->Fim; i++) {
			cout << "[" << i << "]" << "FUNC.: " << Lista->Funcionarios[i].Nome << endl;
			cout << "[" << i << "]" << "SALARIO: " << Lista->Funcionarios[i].Salario << endl;
		}
}

void ShowEmpty(Lista *Lista) {
	if (Underflow(Lista)) {
		cout << "UNDERFLOW" << endl;
		return;
	}
	else
		for (int i = 0; i < MAX; i++) {
			if (Lista->Funcionarios[i].Nome == "" && Lista->Funcionarios[i].Salario == 0)
			{
				cout << "[" << i << "]" << "FUNC.: " << "N/A" << endl;
				cout << "[" << i << "]" << "SALARIO: " << "N/A" << endl;
			}
			else
			{
				cout << "[" << i << "]" << "FUNC.: " << Lista->Funcionarios[i].Nome << endl;
				cout << "[" << i << "]" << "SALARIO: " << Lista->Funcionarios[i].Salario << endl;
			}
		}
}

void Iniciar(Lista* Lista) {
	int i = 0;
	Lista->Inicio = 0;
	Lista->Fim = 0;
	//ZERA TODAS AS PROPRIEDADES DA ESTRUTURA
	while (i < MAX) {
		Lista->Funcionarios[i].Nome = "";
		Lista->Funcionarios[i].Salario = 0;
		i++;
	}
}

Funcionario Find(Funcionario Func, Lista * Lista) {
	Funcionario F;
	for (int i = 0; i < MAX; i++) {
		if (Lista->Funcionarios[i].Nome == Func.Nome)
			F = Lista->Funcionarios[i];
	}
	system("cls");
	return F;
}

void Inserir(Funcionario Funcionario, Lista *Lista) {
	if (Overflow(Lista))
		cout << "OVERFLOW" << endl;
	else {
		Lista->Funcionarios[Lista->Fim] = Funcionario;
		Lista->Fim++;
		system("cls");
		cout << "FUNCIONARIO INSERIDO COM SUCESSO" << endl;
	}
}

void Remover(Lista *Lista) {
	if (Underflow(Lista))
		cout << "UNDERFLOW";
	else
	{
		Lista->Funcionarios[Lista->Fim].Nome = "";
		Lista->Funcionarios[Lista->Fim].Salario = 0;
		Lista->Fim--;
	}
}

void OrderBy(Lista *Lista, int Tipo) // 0: NOME; 1: SALÁRIO
{
	if (Tipo == 1)
	{
		for (int i = 0; i < Lista->Fim; i++)
			for (int l = 0; l < Lista->Fim; l++)
				if (Lista->Funcionarios[i].Salario > Lista->Funcionarios[l].Salario)
				{
					Funcionario Aux = Lista->Funcionarios[l];
					Lista->Funcionarios[l] = Lista->Funcionarios[i];
					Lista->Funcionarios[i] = Aux;
				}
	}
	else
	{
		for (int i = 0; i < Lista->Fim - 1; i++)
			for (int l = 0; l < Lista->Fim; l++)
				if (Lista->Funcionarios[i].Nome > Lista->Funcionarios[l].Nome)
				{
					Funcionario Aux = Lista->Funcionarios[i];
					Lista->Funcionarios[i] = Lista->Funcionarios[l];
					Lista->Funcionarios[l] = Aux;
				}
	}
}

void BySalario(Lista Lista[MAX]){
	int flag, i;
	Funcionario aux;

	do {
		flag = 0;
		for (i = 0; i < (Lista->Fim - 1); i++) {
			if (Lista->Funcionarios[i].Salario > Lista->Funcionarios[i + 1].Salario) {
				aux = Lista->Funcionarios[i];
				Lista->Funcionarios[i] = Lista->Funcionarios[i + 1];
				Lista->Funcionarios[i + 1] = aux;
				flag = 1;
			}
		}
	} while (flag == 1);
}

void ByNome(Lista Lista[MAX]) {
	int flag, i;
	Funcionario aux;
	do {
		flag = 0;
		for (i = 0; i < (Lista->Fim - 1); i++) {
			if (Lista->Funcionarios[i].Nome > Lista->Funcionarios[i + 1].Nome) {
				aux = Lista->Funcionarios[i];
				Lista->Funcionarios[i] = Lista->Funcionarios[i + 1];
				Lista->Funcionarios[i + 1] = aux;
				flag = 1;
			}
		}
	} while (flag == 1);
}


int main() {
	Funcionario Funcionario;
	Lista Lista;
	Iniciar(&Lista);
	int cmd;
	do {
		cmd = Menu();
		if (cmd != 0)
			switch (cmd)
			{
			case 1: {
				cout << "NOME DO FUNCIONARIO: ";
				cin >> Funcionario.Nome;
				cout << "SALARIO: ";
				cin >> Funcionario.Salario;
				Inserir(Funcionario, &Lista);
			}; break;
			case 2: Remover(&Lista); break;
			case 3: Show(&Lista); break;
			case 4: Esvaziar(&Lista); break;
			case 5: ShowEmpty(&Lista); break;
			case 6: {
				cout << "NOME DO FUNCIONARIO: ";
				cin >> Funcionario.Nome;
				Funcionario = Find(Funcionario, &Lista);

				cout << "Resultados da busca: " << endl;
				cout << "Nome: " << Funcionario.Nome << endl;
				cout << "Salario: " << Funcionario.Salario << endl;
			}; break;
			case 7: OrderBy(&Lista, 0); Show(&Lista); break;
			case 8: BySalario(&Lista); Show(&Lista); break;
			//case 9: boble_sort(&Lista, MAX); Show(&Lista); break;
			default:
				return 0;
				break;
			}
	} while (cmd != 0);


	system("pause");
	return 0;
}

