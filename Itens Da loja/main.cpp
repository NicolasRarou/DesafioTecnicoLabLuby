#include "Itens.h" // Header
#include <iostream> // cout e cin
#include<cstdlib> // Biblioteca geral
#include<fstream> // pega dados ofstream e ifstream 


using namespace std;

int NumerosPrimos(int Numero) {
	int i;
	int NumerosPrimos = 0;

	for (i = 1; i <= Numero; i++) {
		if ((Numero % i) == 0) {
			NumerosPrimos++;
		}
	}

	if (NumerosPrimos == 2) {
		return 1;
	}
	else {
		return 0;
	}
}
void Limpeza() {
	char l;
	while ((l = getchar()) != '\n' && l != EOF);
}

int CapturaErrorInt(int Valor) {
	while (cin.good() == false)
	{
		cout << "Input invalido, insira um valor valido \n";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cin >> Valor;
	}

	return Valor;
}

double CapturaErrorIntDouble(double Valor) {
	while (cin.good() == false)
	{
		cout << "Input invalido, insira um valor valido \n";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cin >> Valor;
	}

	return Valor;
}


#pragma region Menus
//=============== Menu Principal ================//
void ConsoleMenu() {
	cout << " ** BEM VINDO AVENTUREIROS!!! **" << endl << endl;
	cout << " ** O que podemos fazer por voces? **" << endl << endl;
	cout << "1- Cadastrar / Venda Item" << endl;
	cout << "2- Lista de Item" << endl;
	cout << "3- Remover Item" << endl;
	cout << "4- Exportar estoque" << endl;
	cout << "5- Importar estoque" << endl;
	cout << "6- Sair" << endl;

	cout << "Opcao: ";
	cout << "\n " << endl;
}
//=============== Menu de cadastro de Itens ================//
void CadastroMenu() {
	cout << "\n** Escolha a categoria de item que deseja cadastrar **" << endl;
	cout << "1- Armamento" << endl;
	cout << "2- Armadura" << endl;
	cout << "3- Consumivéis" << endl;
};

//=============== Menu de Listagem de Itens ================//
void ListaMenu() {
	cout << "\n** Qual Itens deseja ver? **" << endl;
	cout << "1- Itens Iniciais" << endl;
	cout << "2- Lista de Armas Registradas" << endl;
	cout << "3- Lista de Armaduras Registradas" << endl;
	cout << "4- Lista de Consumiveis Registrados" << endl;
	cout << "5- Sair" << endl;
};
//=============== Menu de Remoção de Itens ================//
void RemoçãoMenu() {
	cout << "** Escolha a categoria de item que deseja remover **" << endl;
	cout << "1- Armamento" << endl;
	cout << "2- Armadura" << endl;
	cout << "3- Consumivéis" << endl;
	cout << "4- Estoque" << endl;
	cout << "5- Sair" << endl;
}

//=============== Menu de Venda de Itens ================//
void VendaMenu() {
	cout << "** Escolha a categoria de item que deseja vender **" << endl;
	cout << "1- Armamento" << endl;
	cout << "2- Armadura" << endl;
	cout << "3- Consumivéis" << endl;
	cout << "4- Sair" << endl;
}
#pragma endregion

//=============== Cadastro de Itens ================//
void CadastroItem() {
	// ==============Variaveis de cadastro===================== //
	int ID_AUX = 0;
	string Nome_AUX;
	double Custo_AUX = 0;
	int Unidade_AUX = 0;
	int Dano_AUX = 0;
	int Durabilidade_AUX = 0;
	int Usos_AUX = 0;
	short categoria = 0;
	short Registro = 0;
	short SairCadastro = 0;
	ofstream EstoqueDaLoja;
	// ==============Variaveis de Venda===================== //
	short venda = 0;
	int IDVenda_AUX = 0;
	double QuantidadeVendida_AUX = 0;
	double DescontoPO;
	int desconto = 2;
	int primos = 0;
	int aux = 0;
	int PO_AUX = 0;
	double GastoTotal = 0;
	double DescontoPorcent = 0;
	double DesconteValue = 0;
	double ValorComDesconto = 0;
	short SairVenda = 0;
	short CategoriaVenda = 0;
	ofstream LogDaVenda;
	short SalvarVenda = 0;

	// ============== Input Geral ===================== //
			CadastroMenu();
			cin >> categoria;
			CapturaErrorInt(categoria);
			Limpeza();
			cout << "** Por favor digite os dados do item que deseja registrar ** " << endl;
			cout << " Digite o ID do Item:  ";
			cin >> ID_AUX;
			CapturaErrorInt(ID_AUX);
			Limpeza();
			cout << " Digite o Nome do Item: ";
			getline(cin, Nome_AUX);
			cout << " Digite o Custo do Item: ";
			cin >> Custo_AUX;
			CapturaErrorIntDouble(Custo_AUX);
			Limpeza();
			cout << " Digite o Numero de unidades disponivéis: ";
			cin >> Unidade_AUX;
			CapturaErrorInt(Unidade_AUX);
			Limpeza();

			switch (categoria)
			{	
				// ============== Input Armamento ===================== //

			case 1: {
				cout << " Qual o dano do seu item? ";
				cin >> Dano_AUX;
				CapturaErrorInt(Dano_AUX);
				Limpeza();
				Item* Ataque = new Armamento{ ID_AUX, Nome_AUX, "Armamento", Custo_AUX,Unidade_AUX, Dano_AUX };
				Ataque->imprime_Dados();

				// ==============Registro Armamento===================== //
				cout << "Deseja Cadastrar essa arma com esses dados? Digite 1 para sim e outro numero para nao" << endl;
				cin >> Registro;
				if (Registro == 1) {
					EstoqueDaLoja.open("Registro de Armamento.txt", ios::out);
					EstoqueDaLoja
						<< "\n** DADOS DO ITEM **" << endl
						<< "\n ID do item: " << ID_AUX
						<< "\n Nome do item: " << Nome_AUX
						<< "\n Tipo do item: Armamento "
						<< "\n Custo do item: " << Custo_AUX << " PO"
						<< "\n Unidades do item: " << Unidade_AUX
						<< "\n Dano do item: " << Dano_AUX
						<< endl;
					EstoqueDaLoja.close();
				}

			}
			break;

			// ==============Input Armadura===================== //
			case 2: {
				cout << " Qual a durabilidade do seu item? ";
				cin >> Durabilidade_AUX;
				Limpeza();
				Item* Defesa = new Armadura{ ID_AUX, Nome_AUX, "Armadura", Custo_AUX,Unidade_AUX, Durabilidade_AUX };
				Defesa->imprime_Dados();
				// ==============Registro Armadura===================== //
				cout << "Deseja Cadastrar um consumivel com esses dados? Digite 1 para sim e outro numero para nao" << endl;
				cin >> Registro;
				if (Registro == 1) {
					EstoqueDaLoja.open("Registro de Armadura.txt", ios::out);
					EstoqueDaLoja
						<< "\n** DADOS DO ITEM **" << endl
						<< "\n ID do item: " << ID_AUX
						<< "\n Nome do item: " << Nome_AUX
						<< "\n Tipo do item: Armadura "
						<< "\n Custo do item: " << Custo_AUX << " PO"
						<< "\n Unidades do item: " << Unidade_AUX
						<< "\n Durabilidade do item: " << Durabilidade_AUX
						<< endl;
					EstoqueDaLoja.close();
					}
				}
				break;

				// ==============Input Consumível===================== //
			case 3: {
				cout << "Quantos usos tem seu item? ";
				cin >> Usos_AUX;
				Limpeza();
				Item* Utilitario = new Consumivel{ ID_AUX, Nome_AUX, "Consumivel", Custo_AUX, Unidade_AUX, Usos_AUX };
				Utilitario->imprime_Dados();
				// ==============Registro Consumível===================== //
				cout << "Deseja Cadastrar um consumivel com esses dados? Digite 1 para sim e outro numero para nao" << endl;
				cin >> Registro;
				if (Registro == 1) {
					EstoqueDaLoja.open("Registro de Consumivel.txt", ios::out);
					EstoqueDaLoja
						<< "\n** DADOS DO ITEM **" << endl
						<< "\n ID do item: " << ID_AUX
						<< "\n Nome do item: " << Nome_AUX
						<< "\n Tipo do item: Consumivel "
						<< "\n Custo do item: " << Custo_AUX << " PO"
						<< "\n Unidades do item: " << Unidade_AUX
						<< "\n Usos do item: " << Usos_AUX
						<< endl;
					EstoqueDaLoja.close();
				}
			} break;

			default:
				cout << "Alternativa inexistente ";
				break;

			}
			// ==============Registro de Venda===================== //

			cout << "\nDeseja vender um item com esses dados? Digite 1 para sim e outro numero para nao" << endl;
			cin >> venda;
			if (venda == 1) {
				cout << " Digite o ID da sua venda: ";
				cin >> IDVenda_AUX;
				CapturaErrorInt(IDVenda_AUX);
				Limpeza();
				cout << " Quantos Itens deseja vender: ";
				cin >> QuantidadeVendida_AUX;
				CapturaErrorIntDouble(QuantidadeVendida_AUX);
				Limpeza();
				while (QuantidadeVendida_AUX > Unidade_AUX)
				{
					cout << "Você não tem unidades suficientes, digite uma quantidade igual ao menor a seu numero de unidades \n";
					cin >> QuantidadeVendida_AUX;
					CapturaErrorIntDouble(QuantidadeVendida_AUX);
					Limpeza();

				}
				cout << " Quantos POs Você tem? ";
				cin >> PO_AUX;
				CapturaErrorInt(PO_AUX);
				Limpeza();
				cout << endl;

				//=======DESCONTO CALCULO========//
				for (aux; aux <= QuantidadeVendida_AUX; aux++) {
					if (NumerosPrimos(aux) == 1) {
						primos++;
						DesconteValue = primos;
					}
				}
				DescontoPorcent = DesconteValue * desconto;
				DescontoPO = (Custo_AUX * QuantidadeVendida_AUX * DescontoPorcent) / 100;
				ValorComDesconto = DescontoPO;

				cout << " a quantidade de itens vendidos foi : " << QuantidadeVendida_AUX << endl;
				//==============Calculo final================//
				if (ValorComDesconto == Custo_AUX) {
					cout << "Não houve Desconto." << endl;
					GastoTotal = PO_AUX - (Custo_AUX * QuantidadeVendida_AUX);
					cout << " Seus fundos atuais são: " << GastoTotal << endl;
					 if (GastoTotal < 0 ) {
						cout << " Fundos insuficientes, encenrando venda" << endl;
						exit(1);
					}
				}
				else if (ValorComDesconto != Custo_AUX) {
					cout << " O Seu desconto em porcentagem e: " << DescontoPorcent << endl;
					cout << " O Seu desconto em PO e: " << DescontoPO << endl;
					cout << " O Valor do Item com Desconto e: " << ValorComDesconto << endl;
					GastoTotal = PO_AUX - (ValorComDesconto*Custo_AUX*QuantidadeVendida_AUX);
					cout << "Seus fundos atuais sao: " << GastoTotal << endl;
					if (GastoTotal < 0) {
						cout << "Fundos insuficientes, encenrando venda";
						exit(1);
					}
				}
				// ============== Log Da venda Venda===================== //
				cout << "\n Confirmação de Venda, deseja confirmar sua venda com esses dados? 1-Sim e outro numero para nao ";
				cin >> SalvarVenda;
				CapturaErrorInt(SalvarVenda);
				Limpeza();
				if (SalvarVenda == 1) {
					LogDaVenda.open("Log Venda.txt", ios::app);
					LogDaVenda
						<< "\n** DADOS DO ITEM **" << endl
						<< "\n ID do item: " << ID_AUX
						<< "\n Nome do item: " << Nome_AUX
						<< "\n Custo do item(Sem Desconto): " << Custo_AUX << " PO"
						<< "\n Unidades do item: " << Unidade_AUX
						<< "\n ID da venda: " << IDVenda_AUX
						<< "\n Quantidade de itens vendidos: " << QuantidadeVendida_AUX
						<< "\n Custo Total: " << GastoTotal
						<< endl;
					LogDaVenda.close();

					cout << " Log Registrado com sucesso!!" << endl;
				}

			}


};

//=============== Listagem de Itens ================//
void ListaItem() {
	ifstream _ListaDaLoja;
	string LerLoja;
	short Lista = 0;
	short SairLista = 0; 

	while (SairLista != 2)
	{
		ListaMenu();
		cin >> Lista;
		CapturaErrorInt(Lista);
		Limpeza();
		switch (Lista)
		{
		case 5:
			SairLista = 2;
			break;
			// ============== Itens Iniciais ===================== //

		case 1: {
			Item* Espada = new Armamento{ 1, "Espada de madeira", "Armamento", 1, 100, 1 };
			Espada->imprime_Dados();

			Item* ArmaduraLeve = new Armadura{ 1, "Gibao de pele", "Armadura", 10, 100, 4 };
			ArmaduraLeve->imprime_Dados();

			Item* pocaodemana = new Consumivel{ 1, "Pocaoo de mana", "Consumivel", 10, 100, 1 };
			pocaodemana->imprime_Dados();
		} break;
			  // ==============Lista Armamento===================== //

		case 2: {
			_ListaDaLoja.open("Registro de Armamento.txt", ios::in);
			if (_ListaDaLoja.is_open()) {
				while (getline(_ListaDaLoja, LerLoja))
				{
					cout << LerLoja << endl;
				}
			}
			else {
				cout << "Não há itens no estoque";
			}
			_ListaDaLoja.close();
		} break;

			// ==============Lista Armadura ===================== //
		case 3: {
			_ListaDaLoja.open("Registro de Armadura.txt", ios::in);
			if (_ListaDaLoja.is_open()) {
				while (getline(_ListaDaLoja, LerLoja))
				{
					cout << LerLoja << endl;
				}
			}
			else {
				cout << "Não há itens no estoque";
			}
			_ListaDaLoja.close();
		} break;
			  // ==============Lista Consumível===================== //
			case 4: {
				_ListaDaLoja.open("Registro de Consumivel.txt", ios::in);
				if (_ListaDaLoja.is_open()) {
					while (getline(_ListaDaLoja, LerLoja))
					{
						cout << LerLoja << endl;
					}
				}
				else {
					cout << "Não há itens no estoque";
				}
				_ListaDaLoja.close();
			} break;

			default:
				cout << "Essa Alternativa não existe" << endl;
				break;
		}
	}
}

//=============== Exportação de Estoque ================//
void ExportarEstoque() {
	ifstream RegistroArma("Registro de Armamento.txt", ios::binary);
	ifstream RegistroArmadura("Registro de Armadura.txt", ios::binary);
	ifstream RegistroConsumivel("Registro de Consumivel.txt", ios::binary);
	ofstream Estoque("Estoque.txt", ios::binary);

	Estoque << RegistroArma.rdbuf() << RegistroArmadura.rdbuf() << RegistroConsumivel.rdbuf();
}

//=============== Importação de Estoque ================//
void ImportarEstoque() {
	ifstream ImportarItem;
	string Importação;
	ofstream Exportado;
	string LerExportação;
	cout << "Qual Arquivo deseja importar? \n";
	cin.ignore();
	getline(cin, Importação);
	cout << endl;

	ImportarItem.open(Importação);
	if (ImportarItem.is_open()) {
		Exportado.open("Estoque.txt");
		while (getline(ImportarItem, LerExportação ))
		{
			Exportado << LerExportação << endl;
		}
	}
	else if(!ImportarItem) {
		cerr << "O Arquivo não pode ser aberto";
		exit(1);  
	}
	Exportado.close();
}

//=============== Remoção de Itens ================//
void RemoverItem() {
	int sair_Remoção = 0;
	int _removerItens = 0;

	while (sair_Remoção != 5)
	{
		RemoçãoMenu();
		cin >>_removerItens;
		CapturaErrorInt(_removerItens);
		Limpeza();
		switch (_removerItens) {
		case 5:
			sair_Remoção = 5;
			break;
		case 1: {
			if (remove("Registro de Armamento.txt") != 0)
				perror("Armamento inexistente ");
			else
				puts("Armamento removido com sucesso");
		} break;

		case 2: {
			if (remove("Registro de Armadura.txt") != 0)
				perror("Armadura inexistente ");
			else
				puts("Armadura removido com sucesso");
			} break;

		case 3: {
			if (remove("Registro de Consumivel.txt") != 0)
				perror("Consumivel inexistente ");
			else
				puts("Consumivel removido com sucesso");
			} break;

		case 4: {
			if (remove("Estoque.txt") != 0)
				perror("Consumivel inexistente ");
			else
				puts("Estoque removido com sucesso");
			} break;
		}
	}
}

#pragma region Menus
int main() {
	int opcao = 0;
	int sair = 20;
	int sair_Remoção = 0;
	int removerItem = 0;

	while (sair != 10) {
		ConsoleMenu();
		cin >> opcao;
		CapturaErrorInt(opcao);
		Limpeza();
		switch (opcao) {
		case 6:
			sair = 10;
			break;

		case 1: 
			CadastroItem();
			  break;

		case 2: 
			ListaItem();
			break;
		
		case 3: 
			RemoverItem();
			break;

		case 4:
			ExportarEstoque();
			cout << "\nEstoque exportado com sucesso" << endl;
			break;

		case 5:
			ImportarEstoque();
			cout << "\n Estoque importado com sucesso" << endl;
			break;

		default:
			cout << "opcao inexistente" << endl;
			break;
		}

	}
	return 0;
}
#pragma endregion
