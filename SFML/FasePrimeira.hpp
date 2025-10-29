#pragma once
#include "Fase.hpp"
#include "Inim_Medio.hpp"
#include "Jogador.hpp"

namespace fases {

	class FasePrimeira : public Fase {
	private:
		const int maxInimMedios;
	protected:
		void criarInimigos();
		void criarObstaculo();


		void criarInimMedios();


		void criarObsMedios();

		void carregarFundo();
	public:
		FasePrimeira(entidades::personagens::Jogador* pJog);         //FASE ESTÁ CONHECENDO JOGADOR AQUI, E NO DIAGRAMA NÃO TEM NADA, PODE?
		~FasePrimeira();
	};

}