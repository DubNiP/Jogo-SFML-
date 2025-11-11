#include "Saida.hpp"

namespace entidades {
	namespace obstaculos {

		Saida::Saida(Vector2f pos, Vector2f tam) :
			Obstaculo(pos,tam),
			raio(150.f),
			aberta(false),
			Tfechada(),
			Taberta()
		{
			setSprite();
		}

		Saida::~Saida() {

		}

		void Saida::executar() {
			attPos();
		}

		void Saida::obstaculizar(entidades::personagens::Jogador* p) {
		}

		void Saida::setSprite() {
			if (!Tfechada.loadFromFile("Textures/Entrada.png")) {
				throw "Textura Saida.png não carregada";
			}
			if (!Taberta.loadFromFile("Textures/Saida.png")) {
				throw "Textura Entrada.png não carregada";
			}
			setScale(Vector2f(1.5f, 1.5f));
			setPos(pos);
			aplicarSpriteEstado();
		}

		void Saida::aplicarSpriteEstado() {
			if (Sprite* sp = getSprite()) {
				if (aberta) {
					sp->setTexture(Taberta, true);

				}
				else {
					sp->setTexture(Tfechada, true);
				}
			}
		}

		void Saida::atualizarPorProximidade(const FloatRect& boundsJogador) {
			const float cxJ = boundsJogador.left + boundsJogador.width * 0.5f;
			const float cyJ = boundsJogador.top + boundsJogador.height * 0.5f;


			const FloatRect bPorta = getBounds();
			const float cxP = bPorta.left + bPorta.width * 0.5f;
			const float cyP = bPorta.top + bPorta.height * 0.5f;

			const float dx = cxJ - cxP;
			const float dy = cyJ - cyP;
			const float dist2 = dx * dx + dy * dy;
			const float r2 = raio * raio;

			const bool abrir = dist2 <= r2;
			if (abrir != aberta) {
				aberta = abrir;
				aplicarSpriteEstado();
			}
		}
	}
}