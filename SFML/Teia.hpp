#pragma once

#include "Obstaculo.hpp"

namespace entidades {
	namespace obstaculos {

		class Teia :public Obstaculo {
		private:
			//float largura;
		public:
			Teia(Vector2f pos, Vector2f tam);
			~Teia();
			void executar();
			void obstaculizar(entidades::personagens::Jogador* p);
			void carregarSprite();
		};
	} 
}