#pragma once
using namespace System;
using namespace System::Drawing;

class Figura {
protected:
    int x, y, ancho, alto;
    int r, g, b;
    bool relleno;
    int dirX, dirY;
    bool seMueve;
    int numero;
    int lados; // ?? Cantidad de lados

public:
    Figura(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);
    virtual ~Figura();

    // ?? Métodos virtuales para heredar
    virtual void dibujar(Graphics^ g) = 0; // abstracto ? las subclases lo implementan
    virtual int getLados();                // devuelve número de lados

    // Getters
    int getX();
    int getY();
    int getAncho();
    int getAlto();
    int getR();
    int getG();
    int getB();
    bool getRelleno();
    int getDirX();
    int getDirY();
    bool getSeMueve();
    int getNumero();
    void getColor(int& r, int& g, int& b);
    Color getColor();

    // Setters
    void setX(int x);
    void setY(int y);
    void setDirX(int dirX);
    void setDirY(int dirY);
    void setSeMueve(bool seMueve);
    void setNumero(int numero);

    // Movimiento
    void mover(int limiteAncho, int limiteAlto);

    // Colisión
    Rectangle getRectangulo();
};
