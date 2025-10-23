#include "ListaEntidades.hpp"

#include <iostream>
using namespace std;

ListaEntidades::ListaEntidades() : LEs()
{
}

ListaEntidades::~ListaEntidades()
{
	limpar();
}

void ListaEntidades::incluir(Entidade* pE)
{
	if (pE)
		LEs.incluir(pE);

}

void ListaEntidades::percorrer() {
	for (int i = 0; i < LEs.getSize(); ++i) {
		Entidade* e = LEs.getItem(i);
		if (e) e->executar();
	}
}

void ListaEntidades::excluir(Entidade* pE)
{
	if (pE)
		LEs.deletar(pE);
}

void ListaEntidades::limpar()
{
	LEs.limpar();
}
