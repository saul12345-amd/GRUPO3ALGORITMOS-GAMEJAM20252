#pragma once
#include "Figura.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Cuadrado.h"

class Casa : public Figura
{
public:

	Casa();
	Casa(int x, int y, int ancho, int alto, int r, int g, int b);
	~Casa();
	void dibujar(Graphics^ g) override;
	void verificarColisiones(int anchoForm, int altoForm);
};
