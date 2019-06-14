#pragma once
#include <iostream>
#include "Jugador.h"
using namespace std;
using namespace System::Drawing;
class Mapa
{
private:
	int ancho;
	int alto;
public:
	Mapa() {
		ancho = 1200;
		alto = 1200;
	}
	void dibujar(Graphics^ g, Bitmap^bmp)
	{
		Rectangle porcion = Rectangle(0, 0, ancho, alto);
		Rectangle rectVis = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		g->DrawImage(bmp, rectVis, porcion, GraphicsUnit::Pixel);
	}
};

