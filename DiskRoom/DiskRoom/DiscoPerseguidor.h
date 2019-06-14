#pragma once
#include "Disco.h"
using namespace System;
using namespace System::Drawing;
class DiscoPerseguidor : public Disco
{
private:
public:
	DiscoPerseguidor(int px, int py)
	{
		x = px;
		y = py;
		ancho = 20;
		largo = 20;
		dx = 3;
		dy = 3;
	}

	void dibujar(Graphics^ g, Bitmap^disco)
	{
		g->DrawImage(disco, x, y, ancho, largo);
	}

	void mover(Graphics^ g, int px, int py, int pancho, int plargo)
	{
		if (px < x)
			dx = -3;
		if (px > x + ancho)
			dx = 3;
		if (py < y)
			dy = -3;
		if (py > y+largo)
			dy = 3;

		if ((x > px && x + ancho < px + pancho) || (px > x && px + pancho < x + ancho))
			dx = 0;

		if ((y > py && y + largo < py + plargo) || (py > x && py + plargo < x + ancho))
			dy = 0;

		if (dx == 0 && dy == 0)
		{
			dx = 2;
			dy = 2;
		}
		x = x + dx;
		y = y + dy;
	}
};