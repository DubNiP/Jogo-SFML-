#include "FaseSegunda.hpp"

using namespace fases;

FaseSegunda::FaseSegunda(entidades::personagens::Jogador* pJog):
	Fase(pJog),
	maxChefoes(2)
{

}
FaseSegunda::~FaseSegunda() {

}


void FaseSegunda::criarInimigos() {
	criarChefoes();
}
void FaseSegunda::criarObstaculo() {
	criarObsMedios();
}


void FaseSegunda::criarChefoes() {

}

void FaseSegunda::criarObsMedios() {

}
//void criarProjeteis();