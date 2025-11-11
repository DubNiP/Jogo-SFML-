#include "Menu.hpp"
#include "Gerenciador_Grafico.hpp"

Menu::Menu() :
	Ente(),
	pos(1),
	sair(false),
	iniciar(false),
	font(),
	texts()
{
	if (!font.loadFromFile("Fonts/ByteBounce.ttf")) {
		throw "Textura não carregada";
	}
	if (!carregarTexturaSprite("Textures/background 1.png")) {
		throw "Textura não carregada";
	}
	if (Sprite* sp = getSprite()) {
		if (const Texture* tex = sp->getTexture()) {
			Vector2u tamText = tex->getSize();
			if (tamText.x > 0 && tamText.y > 0) {
				float escalaX = 1280.f / tamText.x;
				float escalaY = 720.f / tamText.y;
				setScale(Vector2f(escalaX, escalaY));
			}
		}
	}

	set_values();
}

Menu::~Menu() {
}

void Menu::set_values() {

	const char* options[] = {"Nome_Jogo", "Jogar","Ranking","Sair"};                                //Classe de objetos gráficos, vale a pena olhar no futuro..
	const Vector2f posi[] = {{490.f,110.f},{620.f,380.f},{600.f,450.f},{630.f,520.f}};
	const unsigned int tam[] = {80u,50u,50u,50u};

	texts.clear();
	texts.reserve(4);


	for (size_t i = 0; i < 4; i++) {
		Text t;
		t.setFont(font);
		t.setString(options[i]);
		t.setCharacterSize(tam[i]);
		t.setPosition(posi[i]);
		t.setOutlineColor(Color::Black);
		t.setOutlineThickness(0.f);
		texts.push_back(t);
	}
}


void Menu::executar() {          //WTFFFFFFFFF

}

void Menu::moverBaixo() {
    if (pos < 3) {
        texts[pos].setOutlineThickness(0);
        pos++;
        texts[pos].setOutlineThickness(6);
    }
}

void Menu::moverCima() {
	if (pos > 1) {
		texts[pos].setOutlineThickness(0);
		pos--;
		texts[pos].setOutlineThickness(6);;
	}
}

void Menu::confirmar() {
	if (pos == 1) {
		iniciar = true;
	}

	if (pos == 3) {
		sair = true;
	}
}


void Menu::draw_menu() {
	if (pGG){
		pGG->clearWindow();

		desenhar();
		
		for (auto& t : texts) {
			pGG->desenharEnte(t);
		}
		pGG->displayWindow();
	}
}

bool Menu::getSair() const {
	return sair;
}


bool Menu::getIniciar() const {
	return iniciar;
}

void Menu::reseta() {
	iniciar = false;
	sair = false;
}