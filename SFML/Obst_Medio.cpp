#include "Obst_Medio.hpp"

namespace entidades { 
	namespace obstaculos {

		ObstMedio::ObstMedio(Vector2f pos, Vector2f tam, bool dano):
			Obstaculo(pos,tam,dano)
		{

		}
		ObstMedio::~ObstMedio() {

		}


		void ObstMedio::executar() {
			attPos();
		}

		void ObstMedio::obstaculizar(entidades::personagens::Jogador* p) {
			if (p) {
				//IMPLEMENTAR DANO OU OQ QUER QUE SEJA NO FUTURO.	
			}
		}
	} 
}