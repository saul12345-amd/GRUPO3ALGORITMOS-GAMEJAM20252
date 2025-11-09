#include "Poligono.h"

const double PI = 3.14159265358979323846;

Poligono::Poligono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno, int lados)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    this->lados = lados;
}

Poligono::~Poligono() {}

int Poligono::getLados() {
    return lados;
}

void Poligono::dibujar(Graphics^ g) {
    // Calcular el centro y radio del polígono
    int centroX = x + ancho / 2;
    int centroY = y + alto / 2;
    int radio = (ancho < alto ? ancho : alto) / 2;

    // Crear array de puntos
    array<Point>^ puntos = gcnew array<Point>(lados);

    // Calcular ángulo inicial (para que el primer vértice esté arriba)
    double anguloInicial = -PI / 2;

    // Calcular puntos del polígono
    for (int i = 0; i < lados; i++) {
        double angulo = anguloInicial + (2 * PI * i / lados);
        int px = centroX + (int)(radio * cos(angulo));
        int py = centroY + (int)(radio * sin(angulo));
        puntos[i] = Point(px, py);
    }

    // Crear brocha y lápiz
    System::Drawing::Color color = Color::FromArgb(this->r, this->g,this->b);
    SolidBrush^ brocha = gcnew SolidBrush(color);
    Pen^ lapiz = gcnew Pen(color, 2);

    // Dibujar el polígono
    if (relleno) {
        g->FillPolygon(brocha, puntos);
    }
    else {
        g->DrawPolygon(lapiz, puntos);
    }

    // Liberar recursos
    delete brocha;
    delete lapiz;
    if (numero >= 0) {
        String^ texto = numero.ToString();
        System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 20, FontStyle::Bold);
        SolidBrush^ brochaTexto = gcnew SolidBrush(System::Drawing::Color::White);

        // Medir el tamaño del texto para centrarlo
        SizeF tamañoTexto = g->MeasureString(texto, fuente);
        float textoX = centroX - tamañoTexto.Width / 2;
        float textoY = centroY - tamañoTexto.Height / 2;

        g->DrawString(texto, fuente, brochaTexto, textoX, textoY);

        delete fuente;
        delete brochaTexto;
    }

}