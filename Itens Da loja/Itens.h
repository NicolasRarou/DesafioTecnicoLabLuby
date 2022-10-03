#ifndef ITENS_H
#define ITENS_H


#include <string>

using namespace std;

class Item {
	
private:
	int NumeroIdentificador;
	string Nome; 
	string Tipo;
	double Custo ;
	int Unidade ;

public:
	Item(int, string, string, double, int);
	~Item() {	}
	
	 virtual void imprime_Dados();

};

class Armamento : public Item {
private:
	int Dano;

public:
	Armamento(int, string, string, double, int, int);
	~Armamento() { }
	void imprime_Dados();
};

class Armadura : public Item {
private:
	int Durabilidade;

public:
	Armadura(int, string, string, double, int,int);
	~Armadura() { };

	void imprime_Dados();
};

class Consumivel : public Item {
private:
	int Usos;

public:
	Consumivel(int, string, string, double, int, int);
	~Consumivel() { };

	void imprime_Dados();
};

#endif // !ITENS_H