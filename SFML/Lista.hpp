#pragma once

#include <iostream>

using namespace std;

template <class TL>
class Lista
{
private:
    template <class TE>
    class Elemento {
    private:
        Elemento<TE>* pProx;
        TE* pInfo;

    public:
        Elemento() : pProx(NULL), pInfo(NULL) {};
        ~Elemento() = default;

        void setProx(Elemento<TE>* pE) { pProx = pE; }
        void setInfo(TE* p) { pInfo = p; }
        Elemento<TE>* getProx() const { return pProx; }
        TE* getInfo() const { return pInfo; }
    };

    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;
    int size;

public:
    Lista() : pPrimeiro(NULL), pUltimo(NULL), size(0) {}
    ~Lista() { limpar();  }

    int getSize() { return size; }
    bool vazia() const { return pPrimeiro == NULL; }
    Elemento<TL>* getPrimeiro() const { return pPrimeiro; }
    Elemento<TL>* getUltimo() const { return pUltimo; }

    void incluir(TL* item) {
        if (pPrimeiro == NULL) {
            pPrimeiro = new Elemento<TL>();
            pPrimeiro->setInfo(item);
            pUltimo = pPrimeiro;
        }
        else {
            Elemento<TL>* temp = new Elemento<TL>();
            temp->setInfo(item);
            pUltimo->setProx(temp);
            pUltimo = temp;
        }
        size++;
    }
    void deletar(TL* item) {
        if (pPrimeiro == NULL || item == NULL) {
            return;
        }

        Elemento<TL>* temp = pPrimeiro;
        Elemento<TL>* tempAnt = NULL;

        while (temp && temp->getInfo() != item) {
            tempAnt = temp;
            temp = temp->getProx();
        }


        if (temp == NULL) {
            return;
        }

        if (temp == pPrimeiro) {
            pPrimeiro = temp->getProx();

            if (pPrimeiro == NULL) {
                pUltimo = NULL;
            }
        }
        else if (temp == pUltimo) {
            tempAnt->setProx(NULL);
            pUltimo = tempAnt;
        }
        else {
            tempAnt->setProx(temp->getProx());
        }

        delete temp;
        size--;
    }
    TL* getItem(int posicao) const {
        if (posicao < 0 || posicao >= size || !pPrimeiro) {
            return NULL;
        }

        Elemento<TL>* temp = pPrimeiro;

        for (int i = 0; i < posicao; i++) {
            temp = temp->getProx();
        }

        return temp->getInfo();
    }
    void limpar()
    {
        Elemento<TL>* atual = pPrimeiro;

        while (atual) {
            Elemento<TL>* proximo = atual->getProx();
            delete atual;
            atual = proximo;
        }
        pPrimeiro = NULL;
        pUltimo = NULL;
        size = 0;
    }
};