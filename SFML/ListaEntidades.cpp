#include "ListaEntidades.hpp"

using namespace std;

namespace listas {

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

void ListaEntidades::excluir(Entidade* pE)
{
	if (pE)
		LEs.deletar(pE);
}

void ListaEntidades::limpar()                                           //OBSERVAÇÃO: DOUBLE DELETE?
{
    for (int i = 0; i < LEs.getSize(); ++i) {
        Entidade* e = LEs.getItem(i);
        if (e) {
            delete e;
        }
    }
	LEs.limpar();
}

void ListaEntidades::limparPreservando(Entidade* keep) {                  //isso é zoado, é bom dar um jeito de remover isso...
    for (int i = 0; i < LEs.getSize(); i++) {
        Entidade* e = LEs.getItem(i);
        if (e && e != keep) {
            delete e;
        }
    }
    LEs.limpar();
}


void ListaEntidades::executarTodos() {
    for (int i = 0; i < LEs.getSize(); i++) {
        Entidade* e = LEs.getItem(i);
        if (e) e->executar();
    }

    removerProjetis();
}

void ListaEntidades::removerProjetis() {                     //olhar dps
    int i = 0;
    while (i < LEs.getSize()) {
        Entidade* e = LEs.getItem(i);
        if (e) {
            Projetil* proj = dynamic_cast<Projetil*>(e);
            if (proj && !proj->getAtivo()) {
                delete e;
                LEs.deletar(e);
                continue;
            }
        }
        i++;
    }
}


void ListaEntidades::desenharTodos() {
    for (int i = 0; i < LEs.getSize(); i++) {
        Entidade* e = LEs.getItem(i);
        if (e) e->desenhar();
    }
}

Entidade* ListaEntidades::getItem(int pos) const {
    return LEs.getItem(pos);
}

}
