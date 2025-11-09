#include "Rombo.h"

Rombo::Rombo(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
}

void Rombo::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    array<Point>^ puntos = gcnew array<Point>(4);
    puntos[0] = Point(x + ancho / 2, y);           // Punto superior (centro)
    puntos[1] = Point(x + ancho, y + alto / 2);    // Punto derecho (medio)
    puntos[2] = Point(x + ancho / 2, y + alto);    // Punto inferior (centro)
    puntos[3] = Point(x, y + alto / 2);            // Punto izquierdo (medio)

    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillPolygon(brush, puntos);
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawPolygon(pen, puntos);
    }

    // Dibujar número en el centro
    if (numero > 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        //MeasureString: mide el texto y devuelve sus dimensiones antes de dibujarl
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
		//2.0f asegura division decimal precisa. La f evita conversiones innecesarias a double
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto / 2.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);        
    }
}
