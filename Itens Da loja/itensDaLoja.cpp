#include "Itens.h"
#include <iostream>

using namespace std;
#pragma region Item

Item::Item(int ID, string _Nome, string _Tipo, double _Custo, int _Unidades) {
	this->NumeroIdentificador = ID; 
	this->Nome = _Nome;
	this->Tipo = _Tipo;
	this->Custo = _Custo;
	this->Unidade = _Unidades;

}

void Item::imprime_Dados() {
	cout << " \n** DADOS DO ITEM ** " << endl;
	cout << " ID do item: " << NumeroIdentificador << "\n";
	cout << " Nome do item: " << Nome << "\n";
	cout << " Tipo do item: " << Tipo << "\n";
	cout << " Custo do item: " << Custo << " PO" << "\n";
	cout << " O item tem: " << Unidade << " Unidades" << "\n";

}

#pragma endregion 

// --------Armamento----------- //

#pragma region Armamento
Armamento::Armamento(int ID, string _Nome, string _Tipo, double _Custo, int _Unidades, int _Dano): 
					Item{ID,_Nome,_Tipo, _Custo, _Unidades}, Dano{_Dano} {
	this->Dano = _Dano;
}

void Armamento::imprime_Dados() {
	Item::imprime_Dados();
	cout << " Dano do item: " << Dano << endl;
}

#pragma endregion

// ---------Armadura---------- //

#pragma region Armadura
Armadura::Armadura(int ID, string _Nome, string _Tipo, double _Custo, int _Unidades,int _Durabilidade) :
					Item{ ID,_Nome,_Tipo, _Custo, _Unidades}, Durabilidade{ _Durabilidade } {
	this->Durabilidade = _Durabilidade;
}

void Armadura::imprime_Dados() {
	Item::imprime_Dados();
	cout << " Durabilidade do item: " << Durabilidade << endl;
}
#pragma endregion

// ----------Comsumiveis--------- //

#pragma region Consumiveis
Consumivel::Consumivel(int ID, string _Nome, string _Tipo, double _Custo, int _Unidades, int _Usos):
						Item{ ID,_Nome,_Tipo, _Custo, _Unidades }, Usos{ _Usos } {
	this->Usos = _Usos;
}

void Consumivel::imprime_Dados() {
	Item::imprime_Dados();
	cout << " Usos do item: " << Usos << endl;
}
#pragma endregion

