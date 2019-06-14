#pragma once
#include "Disco.h"
using namespace System;
using namespace System::Drawing;
class DiscoNormal : public Disco
{
private:
public:
	DiscoNormal(int px, int py)
	{
		x = px;
		y = py;
		ancho = 40;
		largo = 40;
		dx = 10;
		dy = 10;
	}

	void dibujar(Graphics^ g, Bitmap^disco)
	{
		g->DrawImage(disco, x, y, ancho, largo);
	}

	void mover(Graphics^ g)
	{
		if (x + dx  < 45 || x + dx + ancho > g->VisibleClipBounds.Width - 50)
		{
			dx = -1 * dx;
		}

		if (y + dy < 45 || y + dy + largo > g->VisibleClipBounds.Height - 50)
		{
			dy = -1 * dy;
		}

		x = x + dx;
		y = y + dy;
	}
};