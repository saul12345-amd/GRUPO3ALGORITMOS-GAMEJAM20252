#include "Corredor.h"
Corredor::Corredor(int x, int y, int ancho, int alto,bool automatico, int lados) {
	sumaDeAngulos = 0;
	this->nLados = lados;
	this->automatico = automatico;
	int colorAleatorio = rand() % 3;
	struct ColorRGB { int r, g, b; };
	ColorRGB colores[3] = {
		{0, 0, 255},     // Azul
		{255, 0, 0},     // Rojo
		{255, 255, 0}    // Amarillo
	};
	if (colorAleatorio == 0) { r = 0, g = 0, b = 255; };
	if (colorAleatorio == 1) { r = 255, g = 0, b = 0; };
	if (colorAleatorio == 2) { r = 255, g = 255, b = 0; };
}
Corredor::~Corredor() {
	delete figuraCorredor;
}
Figura* Corredor::getFiguraCorredor() { return figuraCorredor; }
int Corredor::getSumaDeAngulos() { return (nLados - 2) * 180.0f; }
int Corredor::getLados() { return nLados; }
void Corredor::setSumaDeAngulos(int sumaDeAngulos){ 
	nLados = (sumaDeAngulos / 180) + 2;
}
void Corredor::setLados(int lados) {
	this->nLados = lados;
}
void Corredor::mover(int limiteAncho, int limiteAlto) {

}
void Corredor::dibujar(Graphics^ graphics) {
	if (nLados == 3) {
		figuraCorredor = new Triangulo(x, y, ancho, alto, r, g, b, true);
		figuraCorredor->dibujar(graphics);
	}
	else if (nLados == 4) {
		figuraCorredor = new Cuadrado(x, y, ancho, r, g, b, true);
		figuraCorredor->dibujar(graphics);
	}
	else if (nLados == 5) {

	}
	else if (nLados == 6) {

	}
	else if (nLados == 7){}
	else if (nLados == 8){}
	else if (nLados == 9){}
	else if (nLados == 10){}
}
void Corredor::getColor(int& r, int& g, int& b) {
	r = this->r;
	g = this->g;
	b = this->b;
}
bool Corredor::getAutomatico() { return automatico; }
void Corredor::setAutomatico(bool automatico) { this->automatico = automatico; }