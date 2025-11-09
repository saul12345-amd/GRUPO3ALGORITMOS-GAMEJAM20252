#include "Figura.h"

Figura::Figura(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno) {
    this->x = x;
    this->y = y;
    this->ancho = ancho;
    this->alto = alto;
    this->r = r;
    this->g = g;
    this->b = b;
    this->relleno = relleno;
    this->dirX = 0;
    this->dirY = 0;
    this->seMueve = false;
    this->numero = 0;
    this->lados = 0; // 🔹 valor por defecto, se redefine en las subclases
}

Figura::~Figura() {}

// 🔹 Devuelve el número de lados de la figura
int Figura::getLados() {
    return lados;
}

// ---------------------- Getters ----------------------
int Figura::getX() { return x; }
int Figura::getY() { return y; }
int Figura::getAncho() { return ancho; }
int Figura::getAlto() { return alto; }
int Figura::getR() { return r; }
int Figura::getG() { return g; }
int Figura::getB() { return b; }
bool Figura::getRelleno() { return relleno; }
int Figura::getDirX() { return dirX; }
int Figura::getDirY() { return dirY; }
bool Figura::getSeMueve() { return seMueve; }
int Figura::getNumero() { return numero; }

void Figura::getColor(int& r, int& g, int& b) {
    r = this->r;
    g = this->g;
    b = this->b;
}

Color Figura::getColor() {
    return Color::FromArgb(r, g, b);
}

// ---------------------- Setters ----------------------
void Figura::setX(int x) { this->x = x; }
void Figura::setY(int y) { this->y = y; }
void Figura::setDirX(int dirX) { this->dirX = dirX; }
void Figura::setDirY(int dirY) { this->dirY = dirY; }
void Figura::setSeMueve(bool seMueve) { this->seMueve = seMueve; }
void Figura::setNumero(int numero) { this->numero = numero; }

// ---------------------- Movimiento ----------------------
void Figura::mover(int limiteAncho, int limiteAlto) {
    if (!seMueve) return;

    x += dirX * 5;
    y += dirY * 5;

    // Mantener dentro de los límites
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > limiteAncho - ancho) x = limiteAncho - ancho;
    if (y > limiteAlto - alto) y = limiteAlto - alto;
}

// ---------------------- Colisión ----------------------
Rectangle Figura::getRectangulo() {
    return Rectangle(x, y, ancho, alto);
}
