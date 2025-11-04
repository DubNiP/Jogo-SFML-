#include "Bloco.hpp"

namespace entidades {
    namespace obstaculos {

        Bloco::Bloco(Vector2f pos, Vector2f tam)
            : Obstaculo(pos, tam)
        {
            carregarSprite();
        }

        Bloco::~Bloco() {
        }

        void Bloco::obstaculizar(entidades::personagens::Jogador* p) {

        }
        void Bloco::executar() {
            attPos();
        }

        void Bloco::carregarSprite() {
            if (!carregarTexturaSprite("Textures/DungeonTile.png", true, false)) {
                throw "Textura não carregada";
            }
            if (Sprite* sp = getSprite()) {
                sp->setTextureRect(IntRect(0, 0, static_cast<int>(largura), static_cast<int>(altura)));
            }
            setScale(Vector2f(1.f, 1.f));
            setPos(pos);
        }

    }
}