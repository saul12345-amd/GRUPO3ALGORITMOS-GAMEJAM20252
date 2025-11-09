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

    //para el automatico
    int dirAutoX = 0;
    int dirAutoY = 0;
    int ticksDireccion = 0;
    int ticksMaxDireccion = 10;
    bool modoAutomatico;

public:
    JuegoService(int ancho, int alto);
    ~JuegoService();

    void moverFiguraActual(int dx, int dy);
    void generarFiguras();
    void moverFiguras();
    void verificarColisiones();
    void dibujar(Graphics^ graphics);

    //automatico:
    void setModoAutomatico(bool activo);
    void actualizarMovimientoAutomatico();

    // 🔹 Métodos para niveles
    int getNivel();
    int getPuntaje();
    void cambiarNivel(int nivel);
    void subirNivel();
    void posicionarFiguraActualSegunNivel();
    bool getAutomatico();

    // set de copiar figura
    void setFiguraActual(Figura* s);
    // 🔹 Getters útiles
    Figura* getFiguraActual();
    int getCantidadFigurasLanzadas();
};