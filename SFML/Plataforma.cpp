#include "Plataforma.hpp"

namespace entidades {
	namespace obstaculos {

		Plataforma::Plataforma(Vector2f pos, Vector2f tam, bool dano, float ampl, float per) :
			Obstaculo(pos, tam, dano),
			amplitude(ampl),
			periodo(per > 0.f ? per : 2.f),
			yIn(pos.y),
			yAnt(pos.y),
			altura(),
			ativa(false),
			tempo()
		{
			tempo.restart();
		}

		Plataforma::~Plataforma() {

		}

		void Plataforma::executar() {
			yAnt = pos.y;

			// Oscilação senoidal centrada em yIn: [yIn - amplitude, yIn + amplitude]
			const float t = tempo.getElapsedTime().asSeconds();
			const float omega = 2.f * 3.1415f / periodo;
			pos.y = yIn + amplitude * sin(omega * t);

			attPos();
		}

		void Plataforma::obstaculizar(entidades::personagens::Jogador* p) {
			if (p) {

				const FloatRect pj = p->getBounds();
				const FloatRect pf = getBounds();


				const float eps = 3.f;
				const bool overlapX = (pj.left + pj.width) > pf.left && pj.left < (pf.left + pf.width);
				const bool onTop = abs((pj.top + pj.height) - pf.top) <= eps && overlapX;

				if (onTop) {
					// Move o jogador junto com a plataforma usando deltaY do frame
					const float deltaY = pos.y - yAnt;

					Vector2f jp = p->getPos();
					jp.y += deltaY;

					// Garante alinhamento perfeito no topo (evita afundar/folgar por erro de arredondamento)
					const float alturaJog = pj.height;
					jp.y = pf.top - alturaJog;

					p->setPos(jp);
				}
			}
		}

	}
}