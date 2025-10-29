#pragma once
#include "Fase.hpp"

namespace fases {

	class FaseSegunda :public Fase {
	private:
		const int maxChefoes;
	protected:

		void criarInimigos();
		void criarObstaculo();
		void criarChefoes();
		void criarObsMedios();
		//void criarProjeteis();
	public:
		FaseSegunda(entidades::personagens::Jogador* pJog);                   //FASE ESTÁ CONHECENDO JOGADOR AQUI, E NO DIAGRAMA NÃO TEM NADA, PODE?
		~FaseSegunda();
	};

}