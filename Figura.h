#pragma once

using namespace System;
using namespace System::Drawing;
enum Direccion { ARRIBA, ABAJO, IZQUIERDA, DERECHA, NINGUNO };
class Figura {
protected:
    int x, y;
    int ancho, alto;
    int r, g, b;
    bool relleno;
    int dirX, dirY;
    bool seMueve;
    int numero;
public:
    Figura(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);    
    ~Figura();
    
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
    void setX(int x);
    void setY(int y);
    void setDirX(int dirX);
    void setDirY(int dirY);
    void setSeMueve(bool seMueve);
    void setNumero(int numero);

    void mover(int limiteAncho, int limiteAlto);
    virtual void dibujar(Graphics^ graphics) = 0;
    Rectangle getRectangulo();
};