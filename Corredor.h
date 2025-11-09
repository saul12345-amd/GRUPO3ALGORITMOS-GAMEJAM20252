#pragma once
#include "Figura.h"
#include "Triangulo.h"
#include "Cuadrado.h"

#include <ctime>
#include <cstdlib>
class Corredor
{
private:
	Figura* figuraCorredor;
	int sumaDeAngulos;
	int nLados;
	bool automatico;
	int x, y, ancho, alto, r, g, b;
public:
	Corredor(int x, int y, int ancho, int alto, bool automatico, int lados);
	~Corredor();
	Figura* getFiguraCorredor();
	int getSumaDeAngulos();
	int getLados();
	void setSumaDeAngulos(int sumaDeAngulos);
	void setLados(int lados);
	void mover(int limiteAncho, int limiteAlto);
	void dibujar(Graphics^ graphics);
	bool getAutomatico();
	void getColor(int& r, int& g, int& b);
	void setAutomatico(bool automatico);
};

