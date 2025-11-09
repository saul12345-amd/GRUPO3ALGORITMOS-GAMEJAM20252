#pragma once
#include "Figura.h"
#include <vector>
using namespace std;
using namespace System::Drawing;

class JuegoService {
private:
    Figura* FiguraActual;
    vector<Figura*> figurasLanzadas;
    int limiteFigurasActivas;
    int limiteAncho;
    int limiteAlto;

    // 🔹 Sistema de niveles
    int nivelActual;
    int puntaje;
    int puntajeParaSiguienteNivel;

public:
    JuegoService(int ancho, int alto);
    ~JuegoService();

    void moverFiguraActual(int dx, int dy);
    void generarFiguras();
    void moverFiguras();
    void verificarColisiones();
    void dibujar(Graphics^ graphics);

    // 🔹 Métodos para niveles
    int getNivel();
    int getPuntaje();
    void cambiarNivel(int nivel);
    void subirNivel();
    void posicionarFiguraActualSegunNivel();

    // set de copiar figura
    void setFiguraActual(Figura* s);
    // 🔹 Getters útiles
    Figura* getFiguraActual();
    int getCantidadFigurasLanzadas();
};