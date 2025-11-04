#pragma once
#include "Obstaculo.hpp"

namespace entidades {
    namespace obstaculos {

        class Bloco : public Obstaculo {
        public:
            Bloco(Vector2f pos, Vector2f tam);
            ~Bloco();

            void executar();
            void obstaculizar(entidades::personagens::Jogador*p);
            void carregarSprite();
        };

    }
}