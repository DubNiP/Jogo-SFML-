#pragma once

#include "Jogador.hpp"
#include "Entidade.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Obstaculo : public Entidade {
protected:
	bool danoso;
	int qntDano;
	/*   OS SEGUINTES ATRIBUTOS SERÃO DE CLASSES DERIVADAS DE OBSTÁCULO:    
		
		ah, ax q o obstaculo medio é a porta com alavanca e o dificil é a poça de água/fogo/acido.
	*/

	float largura;
	float altura;

public:
	Obstaculo(Vector2f pos, Vector2f tam, bool dano = false, int quantDano = 1);
	~Obstaculo();
	//void salvarDataBuffer();
	void executar();                //trocar para virtual no futuro
	//virtual void salvar() = 0;
	void obstaculizar(Jogador* p);             //trocar para virtual no futuro

	bool getDanoso() const;
	int getDano() const;

	/*   AS SEGUINTES FUNCOES SERAO DE CLASSES DERIVADAS DE OBSTÁCULO:   */

};