#pragma once
#include "Lista.hpp"
#include "Entidade.hpp"

class ListaEntidades
{
private:
    Lista<Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidade* pE);
    void excluir(Entidade* pE);
    void limpar();
    void limparPreservando(Entidade* keep);

    void executarTodos();
    void desenharTodos();

    Entidade* getItem(int pos) const;
};
