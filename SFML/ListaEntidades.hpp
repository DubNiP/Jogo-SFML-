#pragma once
#include "Lista.hpp"
#include "Entidade.hpp"
#include "Inimigo.hpp"
#include "Projetil.hpp"
#include "Teia.hpp"

namespace listas {

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
		void salvarTodos();
        void retomarTodos();
        void removerProjetis();
        void removerMorto();

        Lista<Entidade>::Iterator begin() { return LEs.begin(); }
        Lista<Entidade>::Iterator end() { return LEs.end(); }
    };

}
