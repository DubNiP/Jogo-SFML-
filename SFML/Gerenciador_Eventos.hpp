#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Menu.hpp"

namespace Gerenciador {

    class GerenciadorEvento {
    private:
        static GerenciadorEvento* pEvento;
        entidades::personagens::Jogador* pJogador;
        Menu* pMenu;

        bool prevUp;
        bool prevDown;
        bool prevEnter;

        GerenciadorEvento();

    public:
        ~GerenciadorEvento();

        static GerenciadorEvento* getGerenciadorEvento();

        void setJogador(entidades::personagens::Jogador* pj);
        void setMenu(Menu* pm);

        void executar();
        void executarMenu();

    };

}