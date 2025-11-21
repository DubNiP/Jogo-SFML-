#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "Mago.hpp"
#include "Menu.hpp"
#include "Subject.hpp"

namespace Gerenciador {

    class GerenciadorEvento : public subject {
    private:
        static GerenciadorEvento* pEvento;
        entidades::personagens::Mago* pMago;
        bool prevUp;
        bool prevDown;
        bool prevEnter;

        GerenciadorEvento();

    public:
        ~GerenciadorEvento();

        static GerenciadorEvento* getGerenciadorEvento();

        void setMago(entidades::personagens::Mago* pj);

        void executar();
        void executarMenu();
        void soltaTeclas();
        bool verificarEventosJanela(RenderWindow* window);


    };

}