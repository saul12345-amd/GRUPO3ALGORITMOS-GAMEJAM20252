#include "Cuadrado.h"

Cuadrado::Cuadrado(int x, int y, int tamano, int r, int g, int b, bool relleno)
    : Figura(x, y, tamano, tamano, r, g, b, relleno) {
}

void Cuadrado::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillRectangle(brush, x, y, ancho, alto);        
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawRectangle(pen, x, y, ancho, alto);        
    }
    // Dibujar número en el centro
    if (numero >= 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        //MeasureString: mide el texto y devuelve sus dimensiones antes de dibujarl
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
        //2.0f asegura division decimal precisa. La f evita conversiones innecesarias a double
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto * 2 / 3.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);
    }
}

