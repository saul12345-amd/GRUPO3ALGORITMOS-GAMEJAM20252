#pragma once
#include "Figura.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Linea.h"
#include <vector>
using namespace System;
using namespace std;
using namespace System::Drawing;

class FigurasService
{
private:
    vector<Figura*> figuras;

public:
    // Inicialización
    FigurasService();
    ~FigurasService();

    // Agregar figura
    void agregarFigura(Figura* figura);

    // Dibujar todas figuras
    void dibujarTodas(Graphics^ graphics);

    // Limpiar figuras
    void limpiar();

    // Obtener cantidad
    int getCantidadFiguras();
};