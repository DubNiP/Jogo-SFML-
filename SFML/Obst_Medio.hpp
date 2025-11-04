#pragma once

#include "Obstaculo.hpp"

namespace entidades {
	namespace obstaculos {

		class ObstMedio :public Obstaculo {
		private:
			//float largura;
		public:
			ObstMedio(Vector2f pos, Vector2f tam);
			~ObstMedio();
			void executar();
			void obstaculizar(entidades::personagens::Jogador* p);
			void carregarSprite();
		};
	} 
}