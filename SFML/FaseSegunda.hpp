#pragma once
#include "Fase.hpp"

namespace fases {

    class FaseSegunda : public Fase {
    private:
        const int maxChefoes;

    protected:
        void criarInimigos();
        void criarObstaculo();
        void criarChefoes();
        void criarBlocos();
        void carregarFundo();

    public:
        FaseSegunda(entidades::personagens::Mago* pJog);
        ~FaseSegunda();
    };

}