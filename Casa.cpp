#include "Casa.h"


Casa::Casa() : Figura(50, 50, 120, 100, 139, 69, 19, true) {
	// Inicializar
	this->dirX = 1;
	this->dirY = 1;
	this->seMueve = true;
}


Casa::Casa(int x, int y, int ancho, int alto, int r, int g, int b)
	: Figura(x, y, ancho, alto, r, g, b,false) {
	this->dirX = 1;
	this->dirY = 1;
	this->seMueve = true;
}

Casa::~Casa() {
}


void Casa::dibujar(Graphics^ graphics) {
	// Calcular dimensiones
	int altoTecho = (alto / 3);
	int altoParedes = (alto - altoTecho);
	int yParedes = (y + altoTecho);

	// 1. TECHO - Triangulo (rojo ladrillo)
	Triangulo* techo = new Triangulo(x, y, ancho, altoTecho, 178, 34, 34, relleno);
	techo->dibujar(graphics);

	// 2. PAREDES - Rectangulo (color del usuario - se ingresa desde el formulario)
	Rectangulo* paredes = new Rectangulo(x, yParedes, ancho, altoParedes, r, g, b, relleno);
	paredes->dibujar(graphics);

	// 3. PUERTA - Rectangulo (marr�n oscuro)
	int anchoPuerta = (ancho / 4);
	int altoPuerta = (altoParedes / 2);
	int espacioSobrante = (ancho - anchoPuerta);
	int xPuerta = (x + (espacioSobrante / 2));
	int yPuerta = (y + alto - altoPuerta);
	Rectangulo* puerta = new Rectangulo(xPuerta, yPuerta, anchoPuerta, altoPuerta, 101, 67, 33, true);
	puerta->dibujar(graphics);

	delete techo;
	delete paredes;
	delete puerta;
}

void Casa::verificarColisiones(int anchoForm, int altoForm) {
	if (x + ancho >= anchoForm || x <= 0) {
		dirX = -dirX; 
	}

	if (y + alto >= altoForm || y <= 0) {
		dirY = -dirY;  
	}
}
