#pragma once
#include "Lista.hpp"
#include "Entidade.hpp"
#include "Projetil.hpp"

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
    void removerProjetis();

    Entidade* getItem(int pos) const;
};
