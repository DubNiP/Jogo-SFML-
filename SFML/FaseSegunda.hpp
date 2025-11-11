#pragma once
#include "Fase.hpp"

namespace fases {

    class FaseSegunda : public Fase {
    private:
        const int maxChefoes;

<<<<<<< HEAD
    protected:
        void criarInimigos() override;
        void criarObstaculo() override;
        void criarChefoes();
        void criarObsMedios();
        void criarPlataformas();
        void criarAlavancas();
        void criarBlocos() override;
        void carregarFundo() override;
=======
	protected:
		void criarInimigos();
		void criarObstaculo();
		void criarChefoes();
		void criarTeias();
		void criarBlocos();
		void carregarFundo();
>>>>>>> a1f82eca9fe1299c2c02932883d6b05fc3da183d

    public:
        FaseSegunda(entidades::personagens::Jogador* pJog);
        ~FaseSegunda();
    };

}