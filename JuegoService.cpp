
#include "JuegoService.h"
#include "Poligono.h"
#include <cstdlib>
#include <ctime>

// Constructor
JuegoService::JuegoService(int ancho, int alto) {
    srand((unsigned int)time(NULL));
    limiteFigurasActivas = 1;
    limiteAncho = ancho;
    limiteAlto = alto;

    // 🔹 Inicializar sistema de niveles
    nivelActual = 1;
    puntaje = 0;
    puntajeParaSiguienteNivel = 10;

    int colorAleatorio = rand() % 3;

    struct ColorRGB { int r, g, b; };
    ColorRGB colores[3] = {
        {0, 0, 255},     // Azul
        {255, 0, 0},     // Rojo
        {255, 255, 0}    // Amarillo
    };

    // Crear polígono inicial
    FiguraActual = new Poligono(50, alto / 2 - 40, 80, 80,
        colores[colorAleatorio].r,
        colores[colorAleatorio].g,
        colores[colorAleatorio].b,
        true, 3);
    FiguraActual->setSeMueve(true);
    FiguraActual->setNumero(0);

    // Posicionar según nivel inicial
    posicionarFiguraActualSegunNivel();
    this->modoAutomatico = false;
}

// Destructor
JuegoService::~JuegoService() {
    if (FiguraActual) delete FiguraActual;
    for each(Figura * fig in figurasLanzadas) delete fig;
}

// 🔹 Posicionar figura actual según el nivel
void JuegoService::posicionarFiguraActualSegunNivel() {
    if (nivelActual == 1) {
        // Nivel 1: Izquierda (figuras vienen de derecha)
        FiguraActual->setX(50);
        FiguraActual->setY(limiteAlto / 2 - 40);
    }
    else if (nivelActual == 2) {
        // Nivel 2: Abajo (figuras vienen de arriba)
        FiguraActual->setX(limiteAncho / 2 - 40);
        FiguraActual->setY(limiteAlto - 100);
    }
    else if (nivelActual == 3) {
        // Nivel 3: Derecha (figuras vienen de izquierda)
        FiguraActual->setX(limiteAncho - 130);
        FiguraActual->setY(limiteAlto / 2 - 40);
    }
}

// Mover jugador
void JuegoService::moverFiguraActual(int dx, int dy) {
    FiguraActual->setDirX(dx);
    FiguraActual->setDirY(dy);
    FiguraActual->mover(limiteAncho, limiteAlto);
    FiguraActual->setDirX(0);
    FiguraActual->setDirY(0);
}

void JuegoService::setModoAutomatico(bool activo) {
    modoAutomatico = activo;
}
bool JuegoService::getAutomatico() {
    return this->modoAutomatico;
}
void JuegoService::actualizarMovimientoAutomatico() {
    if (modoAutomatico && FiguraActual != nullptr) {
        if (ticksDireccion == 0) {

            do {
                dirAutoX = (rand() % 3) - 1;
                dirAutoY = (rand() % 3) - 1;
            } while (dirAutoX == 0 && dirAutoY == 0);
            ticksDireccion = ticksMaxDireccion;
        }

        FiguraActual->setDirX(dirAutoX);
        FiguraActual->setDirY(dirAutoY);
        FiguraActual->mover(limiteAncho, limiteAlto);
        FiguraActual->setDirX(0);
        FiguraActual->setDirY(0);

        ticksDireccion--;
    }
}
// Variables globales
int tipoAnteriorCarril[3] = { -1, -1, -1 };

void JuegoService::generarFiguras() {
    if (limiteFigurasActivas < 3) {

        int altoCarril = limiteAlto / 3;
        int anchoCarril = limiteAncho / 3;

        int tiposDisponibles[3] = { 3, 4, 5 };

        struct ColorRGB { int r, g, b; };
        ColorRGB colores[3] = {
            {0, 0, 255},     // Azul
            {255, 0, 0},     // Rojo
            {255, 255, 0}    // Amarillo
        };

        int rC, gC, bC;
        FiguraActual->getColor(rC, gC, bC);

        // Desordenar tipos
        for (int i = 0; i < 3; i++) {
            int j = rand() % 3;
            int temp = tiposDisponibles[i];
            tiposDisponibles[i] = tiposDisponibles[j];
            tiposDisponibles[j] = temp;
        }

        int carrilVerde = rand() % 3;

        // 🔹 Generar figuras según el nivel
        for (int i = 0; i < 3; i++) {
            int ladosFigura = tiposDisponibles[i];

            if (ladosFigura == tipoAnteriorCarril[i]) {
                int opciones[2] = { 3, 4 };
                if (ladosFigura == 3) opciones[0] = 4, opciones[1] = 5;
                else if (ladosFigura == 4) opciones[0] = 3, opciones[1] = 5;
                else opciones[0] = 3, opciones[1] = 4;
                ladosFigura = opciones[rand() % 2];
            }
            tipoAnteriorCarril[i] = ladosFigura;

            int x, y, dirX, dirY;

            // 🔹 Configurar posición y dirección según nivel
            if (nivelActual == 1) {
                // Nivel 1: Derecha → Izquierda
                x = limiteAncho;
                y = (altoCarril * i) + (altoCarril / 2) - 40;
                dirX = -1;
                dirY = 0;
            }
            else if (nivelActual == 2) {
                // Nivel 2: Arriba → Abajo
                x = (anchoCarril * i) + (anchoCarril / 2) - 40;
                y = -80;
                dirX = 0;
                dirY = 1;
            }
            else if (nivelActual == 3) {
                // Nivel 3: Izquierda → Derecha
                x = -80;
                y = (altoCarril * i) + (altoCarril / 2) - 40;
                dirX = 1;
                dirY = 0;
            }

            int r, g, b;
            if (i == carrilVerde) {
                r = rC; g = gC; b = bC;
            }
            else {
                ColorRGB c = colores[rand() % 3];
                r = c.r; g = c.g; b = c.b;
            }

            Figura* figura = new Poligono(x, y, 80, 80, r, g, b, true, ladosFigura);

            if (figura != nullptr) {
                figura->setNumero(rand() % 5 + 1);
                figura->setSeMueve(true);
                figura->setDirX(dirX);
                figura->setDirY(dirY);
                figurasLanzadas.push_back(figura);
                limiteFigurasActivas++;
            }
        }
    }
}
void JuegoService::setFiguraActual(Figura* s) {
      FiguraActual = s;
}
void JuegoService::moverFiguras() {
    for (int i = 0; i < figurasLanzadas.size(); i++) {
        figurasLanzadas[i]->mover(limiteAncho, limiteAlto);

        bool fueraDeLimites = false;
        int margen = 100; // Margen extra para asegurar que salió completamente

        // 🔹 Verificar límites según nivel
        if (nivelActual == 1) {
            // Nivel 1: Sale por la izquierda (vienen de derecha)
            fueraDeLimites = (figurasLanzadas[i]->getX()<= 0);
        }
        else if (nivelActual == 2) {
            // Nivel 2: Sale por abajo (vienen de arriba)
            fueraDeLimites = (figurasLanzadas[i]->getY()+ figurasLanzadas[i]->getAlto() > limiteAlto -50);
        }
        else if (nivelActual == 3) {
            // Nivel 3: Sale por la derecha (vienen de izquierda)
            fueraDeLimites = (figurasLanzadas[i]->getX() + figurasLanzadas[i]->getAncho()> limiteAncho - 50);
        }

        if (fueraDeLimites) {
            delete figurasLanzadas[i];
            figurasLanzadas.erase(figurasLanzadas.begin() + i);
            i--;
            limiteFigurasActivas--;
        }
    }
}

void JuegoService::verificarColisiones() {
    for (int i = 0; i < figurasLanzadas.size(); i++) {
        Figura* figLanzada = figurasLanzadas[i];

        if (figLanzada->getRectangulo().IntersectsWith(FiguraActual->getRectangulo())) {

            int rL, gL, bL;
            int rC, gC, bC;
            figLanzada->getColor(rL, gL, bL);
            FiguraActual->getColor(rC, gC, bC);

            bool mismoColor = (rL == rC && gL == gC && bL == bC);

            int ladosActuales = FiguraActual->getLados();
            int nuevosLados = ladosActuales;

            int numeroJugador = FiguraActual->getNumero();
            int numeroLanzado = figLanzada->getNumero();

            if (mismoColor) {
                nuevosLados++;
                if (nuevosLados > 10) nuevosLados = 10;
                numeroJugador += numeroLanzado;
                puntaje += numeroLanzado;
            }
            else {
                nuevosLados--;
                if (nuevosLados < 3) nuevosLados = 3;
                numeroJugador -= numeroLanzado;
                if (numeroJugador < 0) numeroJugador = 0;
                puntaje -= numeroLanzado;
                if (puntaje < 0) puntaje = 0;
            }

            FiguraActual->setLados(nuevosLados);
            FiguraActual->setNumero(numeroJugador);

            // ✅ ELIMINAR la figura antes de verificar cambio de nivel
            delete figLanzada;
            figurasLanzadas.erase(figurasLanzadas.begin() + i);
            i--;
            limiteFigurasActivas--;

            // ✅ Verificar si debe subir de nivel DESPUÉS de eliminar
            if (puntaje >= puntajeParaSiguienteNivel && nivelActual < 3) {
                subirNivel();
                // Como subirNivel() ya limpia las figuras, podemos salir
                return;
            }
        }
    }
}

void JuegoService::dibujar(Graphics^ graphics) {
    if (FiguraActual != nullptr) {
        FiguraActual->dibujar(graphics);
    }
    for each(Figura * figura in figurasLanzadas) {
        figura->dibujar(graphics);
    }
}

// 🔹 Métodos de niveles
int JuegoService::getNivel() {
    return nivelActual;
}

int JuegoService::getPuntaje() {
    return puntaje;
}

void JuegoService::cambiarNivel(int nivel) {
    if (nivel >= 1 && nivel <= 3) {
        nivelActual = nivel;

        // Limpiar figuras existentes
        for each(Figura * fig in figurasLanzadas) delete fig;
        figurasLanzadas.clear();
        limiteFigurasActivas = 1;

        // Reposicionar figura actual
        posicionarFiguraActualSegunNivel();
    }
}

void JuegoService::subirNivel() {
    if (nivelActual < 3) {
        nivelActual++;
        puntajeParaSiguienteNivel += 15; // Cada nivel requiere más puntos

        // Limpiar figuras existentes
        for each(Figura * fig in figurasLanzadas) delete fig;
        figurasLanzadas.clear();
        limiteFigurasActivas = 1;

        // Reposicionar figura actual
        posicionarFiguraActualSegunNivel();
    }
}

Figura* JuegoService::getFiguraActual() {
    return FiguraActual;
}

int JuegoService::getCantidadFigurasLanzadas() {
    return figurasLanzadas.size();
}