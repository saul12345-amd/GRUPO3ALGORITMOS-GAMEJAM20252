#include "FigurasService.h"

// Constructor
FigurasService::FigurasService() {
}

// Destructor
FigurasService::~FigurasService() {
    limpiar();
}

// Agregar figura
void FigurasService::agregarFigura(Figura* figura) {
    figuras.push_back(figura);
}

// Dibujar todas figuras
void FigurasService::dibujarTodas(Graphics^ graphics) {
    for (auto figura : figuras) {
        figura->dibujar(graphics);
    }
}


// Limpiar figuras
void FigurasService::limpiar() {
    for (auto figura : figuras) {
        delete figura;
    }
    figuras.clear();
}

// Obtener cantidad
int FigurasService::getCantidadFiguras() {
    return figuras.size();
}