#pragma once
#include "Obstaculo.hpp"


namespace entidades {
	namespace obstaculos {

		class Saida : public Obstaculo {
		private:
			bool aberta;
			float raio;
			Texture Tfechada;
			Texture Taberta;
		public:
			Saida(Vector2f pos, Vector2f tam);
			~Saida();
			void executar();
			void obstaculizar(entidades::personagens::Jogador* p);
			void setSprite();
			void aplicarSpriteEstado();
			void atualizarPorProximidade(const FloatRect& boundsJogador);
		};
	}
}