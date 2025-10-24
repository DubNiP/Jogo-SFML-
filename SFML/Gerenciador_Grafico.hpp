#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GerenciadorGrafico {
private:
    RenderWindow* window;
public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();
    void desenharEnte(const RectangleShape &shape);
    void clearWindow(Color cor = Color::Black);
    void drawWindow(const Drawable& corpo);
    void displayWindow();
    RenderWindow* getWindow() const;
};