#include "Menu.hpp"

Menu::Menu() :
	window(NULL),
	winclose(NULL),
	font(NULL),
	image(NULL),
	bg(NULL)
{
	window = new RenderWindow();
	winclose = new RectangleShape();
	font = new Font();
	image = new Texture();
	bg = new Sprite();
	set_values();
}

Menu::~Menu() {
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;

	window = NULL;
	winclose = NULL;
	font = NULL;
	image = NULL;
	bg = NULL;
}

void Menu::set_values() {
	window->create(VideoMode(1280, 720), "Menu SFML");
	window->setPosition(Vector2i(0, 0));

	pos = 1;
	pressed = theselect = false;
	if (!font->loadFromFile("Fonts/Newsreader-VariableFont_opsz,wght.ttf")) {
		throw "Deu Merda aqui";
	}
	if (!image->loadFromFile("Textures/Fundo_menu.png")) {
		throw "Deu Merda aqui";
	}
	bg->setTexture(*image);

	pos_mouse = { 0,0 };
	mouse_coord = { 0,0 };

	options = { "Nome_Jogo","Jogar","Opções","Sair" };
	texts.resize(4);
	coords = { {490,180},{620,350},{600,420},{630,490} };
	sizes = { 80,50,50,50 };
	texts[1].setOutlineThickness(4);
	for (size_t i{}; i < texts.size(); i++) {
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setPosition(coords[i]);
		texts[i].setOutlineColor(Color::Black);
	}
}

void Menu::loop_events(){
	Event event;
	while (window->pollEvent(event)) {
		if (event.type == Event::Closed ||
			Keyboard::isKeyPressed(Keyboard::Escape)) {
			window->close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && !pressed) {
			if (pos < 3) {
				pos++;
				pressed = true;
				texts[pos].setOutlineThickness(4);
				texts[pos-1].setOutlineThickness(0);
				pressed = false;
				theselect = false;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) && !pressed) {
			if (pos > 1) {
				pos--;
				pressed = true;
				texts[pos].setOutlineThickness(4);
				texts[pos + 1].setOutlineThickness(0);
				pressed = false;
				theselect = false;
				cout << "pos: " << pos << "\n";
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && !theselect) {
			theselect = true;                                                    //OBS: os outros botões n fazem nada por enquanto..
			if (pos == 3) {
				window->close();
			}
			cout << options[pos] << endl;
		}
	}
}

void Menu::draw_all() {
	window->clear();
	window->draw(*bg);
	for (auto i : texts) {
		window->draw(i);
	}
	window->display();
}

void Menu::executar() {
	while (window->isOpen()) {
		loop_events();
		draw_all();
	}
}