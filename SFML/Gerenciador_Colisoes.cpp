#include "Gerenciador_Colisoes.hpp"

using namespace Gerenciadores;

GerenciadorColisoes::GerenciadorColisoes(entidades::personagens::Jogador* pJog, RenderWindow* win):
	LIs(),
	LOs(),
	LPs(),
	pJog1(pJog),
	window(win)
{

}

GerenciadorColisoes::~GerenciadorColisoes() {
}

const bool GerenciadorColisoes::verificarColisao(Entidade* pe1, Entidade* pe2) const {
	if (!pe1 || !pe2 || pe1 == pe2) {
		return false;
	}
	return pe1->getBounds().intersects(pe2->getBounds());
}


void GerenciadorColisoes::colidiu(Entidade* a, Entidade* b) {
	if (a && b && a != b) {

		FloatRect ra = a->getBounds();
		FloatRect rb = b->getBounds();
		FloatRect inter;
		if (ra.intersects(rb, inter)) {

			Vector2f mtv(0.f, 0.f);
			if (inter.width < inter.height) {
				const float aCx = ra.left + ra.width * 0.5f;
				const float bCx = rb.left + rb.width * 0.5f;

				mtv.x = (bCx > aCx) ? inter.width : -inter.width;
			}
			else {
				// Resolver no eixo Y
				const float aCy = ra.top + ra.height * 0.5f;
				const float bCy = rb.top + rb.height * 0.5f;

				mtv.y = (bCy > aCy) ? inter.height : -inter.height;
			}

			const bool aStatic = dynamic_cast<const entidades::obstaculos::Obstaculo*>(a) != NULL;
			const bool bStatic = dynamic_cast<const entidades::obstaculos::Obstaculo*>(b) != NULL;

			if (aStatic && !bStatic) {
				b->setPos(b->getPos() + mtv);
				return;
			}
			if (!aStatic && bStatic) {
				a->setPos(a->getPos() - mtv);
				return;
			}
			if (!aStatic && !bStatic) {
				mtv.x /= 2;
				mtv.y /= 2;
				a->setPos(a->getPos() - mtv);
				b->setPos(b->getPos() + mtv);
			}
		}
	}
}




void GerenciadorColisoes::tratarColisoesJogsObstacs() {
	
	if (pJog1) {
		list<entidades::obstaculos::Obstaculo*>::iterator it = LOs.begin();
		while (it != LOs.end()) {
			if (*it) {                                           
				FloatRect jog = pJog1->getBounds();
				FloatRect obs = (*it)->getBounds();
				if (verificarColisao(*it, pJog1)) {
					colidiu(*it, pJog1);
				}
				(*it)->obstaculizar(pJog1);
			}
			it++;
		}


	}
}
void GerenciadorColisoes::tratarColisoesJogsInimgs() {
	if (pJog1) {
		for (int i = 0; i < LIs.size(); i++) {
			if (LIs[i]) {
				FloatRect jog = pJog1->getBounds();
				FloatRect inim = LIs[i]->getBounds();
				if (verificarColisao(pJog1, LIs[i])) {
					colidiu(LIs[i], pJog1);
					LIs[i]->danificar();                //isso ta sugando a vida do jogador MT rapido, dps e bom dar uma olhada
				}
			}
		}
	}
}

void GerenciadorColisoes::tratarColisoesJogsProjeteis() {
	if (pJog1) {
		set<Projetil*>::iterator it = LPs.begin();
		while (it != LPs.end()) {
			FloatRect jog = pJog1->getBounds();
			FloatRect inim = (*it)->getBounds();
			if (verificarColisao(pJog1, *it)) {
				pJog1->tomarDano((*it)->getDano());               
				(*it)->setAtivo(false);
				it = LPs.erase(it);
				continue;
			}
			it++;
		}
	}
}


void GerenciadorColisoes::incluirInimigo(entidades::personagens::Inimigo* pi) {
	if (pi) {
		LIs.push_back(pi);
	}
}

void GerenciadorColisoes::incluirObstaculo(entidades::obstaculos::Obstaculo* pObstaculo) {
	if (pObstaculo) {
		LOs.push_back(pObstaculo);
	}
}

void GerenciadorColisoes::incluirProjetil(Projetil* pProjetil)
{
	if (pProjetil) {
		LPs.insert(pProjetil);
	}
}


void GerenciadorColisoes::limparObstaculos() {
	LOs.clear();
}

void GerenciadorColisoes::limparInimigos() {
	LIs.clear();
}

void GerenciadorColisoes::limparProjetis()
{
	LPs.clear();
}

void GerenciadorColisoes::executar() {
	limiteDeTela();
	tratarColisoesJogsObstacs();
	tratarColisoesJogsProjeteis();
	tratarColisoesJogsInimgs();
}

void GerenciadorColisoes::setJog(entidades::personagens::Jogador* pJog) {
	pJog1 = pJog;
}

void GerenciadorColisoes::setWindow(RenderWindow* win) {
	window = win;
}

void GerenciadorColisoes::limiteDeTela() {
	if (window) {
		if (pJog1) {

			FloatRect boundJog = pJog1->getBounds();
			Vector2u windowSize = window->getSize();

			const int X = windowSize.x - boundJog.width;
			const int Y = windowSize.y - boundJog.height;
			limiteDeTelaJogador(X, Y);
			limiteDeTelaProjeteis(X, Y);
		}
	}
}

void GerenciadorColisoes::limiteDeTelaJogador(int X, int Y) {

	if (pJog1->getPos().x < 0)   pJog1->setPos(Vector2f(0.f, pJog1->getPos().y));
	if (pJog1->getPos().y < 0)   pJog1->setPos(Vector2f(pJog1->getPos().x, 0.f));
	if (pJog1->getPos().x > X)   pJog1->setPos(Vector2f(X, pJog1->getPos().y));
	if (pJog1->getPos().y > Y)   pJog1->setPos(Vector2f(pJog1->getPos().x, Y));
}

void GerenciadorColisoes::limiteDeTelaProjeteis(int X, int Y) {

	set<Projetil*>::iterator it = LPs.begin();

	while (it != LPs.end()) {
		Projetil* projetil = *it;

		if (projetil) {
			Vector2f posProjetil = projetil->getPos();

			if (posProjetil.x  < 0 || posProjetil.y  < 0 || posProjetil.x > X || posProjetil.y > Y) {
				projetil->setAtivo(false); //fazer a devida alteracao	

				it = LPs.erase(it);
				continue;

			}
		}
		it++;
	}

}