#include "Obst_Medio.hpp"

namespace entidades { 
	namespace obstaculos {

		ObstMedio::ObstMedio(Vector2f pos, Vector2f tam):
			Obstaculo(pos,tam)
		{
			carregarSprite();
		}
		ObstMedio::~ObstMedio() {

		}


		void ObstMedio::executar() {
			attPos();
		}

		void ObstMedio::obstaculizar(entidades::personagens::Jogador* p) {
			if (p) {
				p->setVelocidade(p->getVelocidade() / 3);
			}
		}

		void	ObstMedio::carregarSprite() {
			if (!carregarTexturaSprite("Textures/Web3.png", true, false)) {
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