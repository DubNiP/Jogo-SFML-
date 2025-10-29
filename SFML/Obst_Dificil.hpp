#pragma once
#include "Obstaculo.hpp"

namespace entidades {
	namespace obstaculos {

		class ObstDificil : public Obstaculo {
		private:
			short int danosidade;
		public:
			ObstDificil(Vector2f pos, Vector2f tam, bool dano = false, int quantDano = 1);
			~ObstDificil();
			//void salvarDataBuffer();
			void executar();
			void obstaculizar(entidades::personagens::Jogador* p);
			int getDanosidade() const;
			void carregarSprite();
		};
	} 
}


