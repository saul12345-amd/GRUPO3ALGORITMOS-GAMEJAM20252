#include "JuegoService.h"
#include <cstdlib>
#include <ctime>
// Constructor
JuegoService::JuegoService(int ancho, int alto) {
    srand((unsigned int)time(NULL));
    limiteFigurasActivas = 1;
    limiteAncho = ancho;
    limiteAlto = alto;

    // Triangulo controolabel (izquierda)
	FiguraActual = new Triangulo(50, alto / 2 - 40, 80, 80, 0, 255, 0, true); // Verde
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

        // Obtener el color actual (verde del jugador)
        int rC, gC, bC;
        FiguraActual->getColor(rC, gC, bC);

        // Desordenar tipos
        for (int i = 0; i < 3; i++) {
            int j = rand() % 3;
            int temp = tiposDisponibles[i];
            tiposDisponibles[i] = tiposDisponibles[j];
            tiposDisponibles[j] = temp;
        }

        // 🔸 Elegir al azar qué carril tendrá la figura verde
        int carrilVerde = rand() % 3;

        // Generar una figura por cada carril
        for (int i = 0; i < 3; i++) {
            int tipo = tiposDisponibles[i];

            // Evitar repetir tipo en mismo carril
            if (tipo == tipoAnteriorCarril[i]) {
                tipo = (tipo + 1 + rand() % 2) % 3;
            }
            tipoAnteriorCarril[i] = tipo;

            int y = (altoCarril * i) + (altoCarril / 2) - 40;
            Figura* figura = nullptr;

            int r, g, b;

            // 🔸 Si es el carril elegido → color igual al jugador (verde)
            if (i == carrilVerde) {
                r = rC; g = gC; b = bC;
            }
            else {
                // 🔸 Elegir un color distinto (azul, rojo o amarillo)
                ColorRGB c = colores[rand() % 3];
                r = c.r; g = c.g; b = c.b;
            }

            // Crear figura según tipo
            if (tipo == 0)
                figura = new Triangulo(x, y, 80, 80, r, g, b, true);
            else if (tipo == 1)
                figura = new Rectangulo(x, y, 80, 80, r, g, b, true);
            else if (tipo == 2)
                figura = new Rombo(x, y, 80, 80, r, g, b, true);

            if (figura != nullptr) {
                figura->setNumero(rand() % 10 + 1);
                figura->setSeMueve(true);
                figura->setDirX(-1);
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

        if (figLanzada->getRectangulo().IntersectsWith(FiguraActual->getRectangulo())) {

            // Obtener colores
            int rL, gL, bL;
            int rC, gC, bC;
            figLanzada->getColor(rL, gL, bL);
            FiguraActual->getColor(rC, gC, bC);

            bool mismoColor = (rL == rC && gL == gC && bL == bC);

            // 🔹 Obtener lados y número actual
            int ladosActuales = FiguraActual->getLados();
            int nuevosLados = ladosActuales;

            int numeroJugador = FiguraActual->getNumero();
            int numeroLanzado = figLanzada->getNumero();

            // 🔹 Aumentar o disminuir lados según color
            if (mismoColor) {
                nuevosLados++;
                if (nuevosLados > 10) nuevosLados = 10;
                numeroJugador += numeroLanzado; // Suma número si es del mismo color
            }
            else {
                nuevosLados--;
                if (nuevosLados < 3) nuevosLados = 3;
                numeroJugador -= numeroLanzado; // Resta número si es diferente color
                if (numeroJugador < 0) numeroJugador = 0; // Evitar negativos
            }

            // 🔸 Guardar datos actuales antes de recrear la figura
            int x = FiguraActual->getX();
            int y = FiguraActual->getY();
            int ancho = FiguraActual->getAncho();
            int alto = FiguraActual->getAlto();
            int r, g, b;
            FiguraActual->getColor(r, g, b);

            delete FiguraActual; // eliminar figura anterior

            // 🔹 Crear nueva figura según el número de lados
            if (nuevosLados == 3)
                FiguraActual = new Triangulo(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 4)
                FiguraActual = new Rectangulo(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 5)
                FiguraActual = new Pentagono(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 6)
                FiguraActual = new Hexagono(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 7)
                FiguraActual = new Heptagono(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 8)
                FiguraActual = new Octogono(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 9)
                FiguraActual = new Eneagono(x, y, ancho, alto, r, g, b, true);
            else if (nuevosLados == 10)
                FiguraActual = new Decagono(x, y, ancho, alto, r, g, b, true);

            // Configurar nueva figura actual
            FiguraActual->setSeMueve(true);
            FiguraActual->setNumero(numeroJugador);

            // 🔹 Eliminar figura lanzada
            delete figLanzada;
            figurasLanzadas.erase(figurasLanzadas.begin() + i);
            i--;
            limiteFigurasActivas--;
        }
    }
}


// Renderizar escena
void JuegoService::dibujar(Graphics^ graphics) {
    // Solo dibuja, no modifica el estado del juego
    if (FiguraActual != nullptr) {
        FiguraActual->dibujar(graphics);
    }
    for each (Figura * figura in figurasLanzadas) {
        figura->dibujar(graphics);
    }
}