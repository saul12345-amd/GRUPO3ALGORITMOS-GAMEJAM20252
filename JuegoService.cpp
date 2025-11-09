#include "JuegoService.h"
#include <cstdlib>
#include <ctime>
// Constructor
JuegoService::JuegoService(int ancho, int alto) {
    srand((unsigned int)time(NULL));
    limiteFigurasActivas = 1;
    limiteAncho = ancho;
    limiteAlto = alto;

    // Circulo controlable (izquierda)
    FiguraActual = new Circulo(50, alto / 2 - 30, 60, 0, 0, 255, true);
    FiguraActual->setSeMueve(true);  // El círculo siempre puede moverse
    FiguraActual->setNumero(0);
}

// Destructor
JuegoService::~JuegoService() {
    if (FiguraActual) delete FiguraActual;
    for each (Figura * fig in figurasLanzadas) delete fig;
}

// Mover jugador
void JuegoService::moverFiguraActual(int dx, int dy){
    // Configurar dirección y mover círculo
    FiguraActual->setDirX(dx);
    FiguraActual->setDirY(dy);
    FiguraActual->mover(limiteAncho, limiteAlto);

    FiguraActual->setDirX(0);
    FiguraActual->setDirY(0);
}

// Lanzar figuras

// Variables globales o de clase sugeridas para recordar el tipo anterior de cada carril
int tipoAnteriorCarril[3] = { -1, -1, -1 };

void JuegoService::generarFiguras() {
    if (limiteFigurasActivas < 3) {

        int x = limiteAncho;
        int altoCarril = limiteAlto / 3;

        // Tipos base disponibles (0=Triángulo, 1=Rectángulo, 2=Rombo)
        int tiposDisponibles[3] = { 0, 1, 2 };

        // Colores predefinidos: azul, rojo, amarillo
        struct ColorRGB { int r, g, b; };
        ColorRGB colores[3] = {
            {0, 0, 255},     // Azul
            {255, 0, 0},     // Rojo
            {255, 255, 0}    // Amarillo
        };

        // Desordenar los tipos manualmente usando rand()
        for (int i = 0; i < 3; i++) {
            int j = rand() % 3;
            int temp = tiposDisponibles[i];
            tiposDisponibles[i] = tiposDisponibles[j];
            tiposDisponibles[j] = temp;
        }

        // Generar una figura por cada carril
        for (int i = 0; i < 3; i++) {
            int tipo = tiposDisponibles[i];

            // Evitar repetir el mismo tipo en el mismo carril
            if (tipo == tipoAnteriorCarril[i]) {
                tipo = (tipo + 1 + rand() % 2) % 3;
            }
            tipoAnteriorCarril[i] = tipo;

            int y = (altoCarril * i) + (altoCarril / 2) - 40; // Centrado en carril
            Figura* figura = nullptr;

            // Asignar color según tipo (mismo índice)
            ColorRGB c = colores[tipo];

            // Crear figura según tipo
            if (tipo == 0) {
                figura = new Triangulo(x, y, 80, 80, c.r, c.g, c.b, true);
            }
            else if (tipo == 1) {
                figura = new Rectangulo(x, y, 80, 80, c.r, c.g, c.b, true);
            }
            else if (tipo == 2) {
                figura = new Rombo(x, y, 80, 80, c.r, c.g, c.b, true);
            }

            if (figura != nullptr) {
                figura->setNumero(rand() % 10 + 1);
                figura->setSeMueve(true);
                figura->setDirX(-1); // Hacia la izquierda
                figura->setDirY(0);
                figurasLanzadas.push_back(figura);
                limiteFigurasActivas++;
            }
        }
    }
}


// Actualizar figuras
void JuegoService::moverFiguras() {
    // Mover y filtrar figuras lanzadas
    for (int i = 0; i < figurasLanzadas.size(); i++) {
        figurasLanzadas[i]->mover(limiteAncho, limiteAlto);

        // Eliminar si salió de los límites
        if (figurasLanzadas[i]->getX()  <= 0) {
            delete figurasLanzadas[i];
            figurasLanzadas.erase(figurasLanzadas.begin() + i);
            i--;  // Decrementar para compensar la eliminación
            limiteFigurasActivas--;
        }
    }
}

void JuegoService::verificarColisiones() {
    for (int i = 0; i < figurasLanzadas.size(); i++) {
        Figura* figLanzada = figurasLanzadas[i];

        // Verificar colisión con el círculo del jugador
        if (figLanzada->getRectangulo().IntersectsWith(FiguraActual->getRectangulo())) {

            // Obtener colores RGB
            int rL, gL, bL;
            int rC, gC, bC;

            figLanzada->getColor(rL, gL, bL);
            FiguraActual->getColor(rC, gC, bC);

            bool mismoColor = (rL == rC && gL == gC && bL == bC);

            if (mismoColor) {
                // ✅ Mismo color → sumar
                FiguraActual->setNumero(FiguraActual->getNumero() + figLanzada->getNumero());
            }
            else {
                // ❌ Diferente color → restar
                FiguraActual->setNumero(FiguraActual->getNumero() - figLanzada->getNumero());

                // Evitar números negativos
                if (FiguraActual->getNumero() < 0)
                    FiguraActual->setNumero(0);
            }

            // Eliminar figura lanzada
            delete figLanzada;
            figurasLanzadas.erase(figurasLanzadas.begin() + i);
            i--;  // Ajustar índice tras eliminar
            limiteFigurasActivas--;
        }
    }
}

// Renderizar escena
void JuegoService::dibujar(Graphics^ graphics) {
    // Solo dibuja, no modifica el estado del juego
    FiguraActual->dibujar(graphics);
    for each (Figura * figura in figurasLanzadas) {
        figura->dibujar(graphics);
    }
}