#pragma once
#include "Circulo.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include <vector>
using namespace System;
using namespace std;
using namespace System::Drawing;

class JuegoService {
private:
    Figura* FiguraActual;
    vector<Figura*> figurasLanzadas;
    int limiteAncho, limiteAlto;
    int limiteFigurasActivas;

public:
    // Inicialización
    JuegoService(int ancho, int alto);
    ~JuegoService();

    // Mover jugador
    void moverFiguraActual(int,int);

    // Lanzar figuras
    void generarFiguras();

    // Actualizar figuras
    void moverFiguras();

    // Verificar impactos
    void verificarColisiones();

	// Dibujar escena (figuras)
    void dibujar(Graphics^ graphics);
};