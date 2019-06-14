#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

enum Direcciones { Ninguna, Arriba, Abajo, Izquierda, Derecha };

class Jugador
{
private:
	int x;
	int y;
	int dx, dy;
	int ancho;
	int alto;
	int IndiceX;
	int IndiceY;
	int vidas;
	Direcciones ultimatecla;
public:
	Jugador() {}
	~Jugador() {}
	Direcciones direccion;
	Jugador(int _x, int _y)
	{
		x = _x;
		y = _y;
		dx = 0;
		dy = 0;
		ultimatecla = Direcciones::Abajo;
		direccion = Direcciones::Ninguna;
		ancho = 32;
		alto = 48;
		IndiceX = 0;
		IndiceY = 0;
	}
	void dibujar(Graphics^ g, Bitmap^bmp)
	{
		int recX = x + ((ancho * 1.5) / 4);
		int recY = y + (alto * 1.5) - ((alto * 1.5) / 4);
		int recAncho = (ancho * 1.5) / 2;
		int recAlto = (alto * 1.5) / 4;

		Rectangle rec = Rectangle(recX, recY, recAncho, recAlto);
		//buffer->Graphics->DrawRectangle(Pens::Black, rec);

		Rectangle porcion = Rectangle(IndiceX*ancho, IndiceY*alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho*1.5, alto*1.5);
		g->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);

		IndiceX = 0;
	}
	void mover(Direcciones d, Graphics^ g)
	{
		switch (d) {
		case::Direcciones::Arriba:
			IndiceY = 3;
			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 0;
			dy = -5;
			ultimatecla = Arriba;
			break;
		case::Direcciones::Abajo:
			IndiceY = 0;
			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 0;
			dy = 5;
			ultimatecla = Abajo;
			break;

		case::Direcciones::Izquierda:
			IndiceY = 1;
			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 0;
			dx = -5;
			ultimatecla = Izquierda;
			break;

		case::Direcciones::Derecha:
			IndiceY = 2;
			if (IndiceX >= 0 && IndiceX < 3)
				IndiceX++;
			else
				IndiceX = 0;
			dx = 5;
			ultimatecla = Derecha;
			break;
		}

		if (x + dx >40 && x + ancho +dx< g->VisibleClipBounds.Width - 60)
		{
			x = dx + x;
		}

		if (y + dy >40 && y + alto +dy< g->VisibleClipBounds.Height - 60)
		{
			y = dy + y;
		}
		dx = 0;
		dy = 0;
	}

	int get_x()
	{
		return x;
	}

	int get_y()
	{
		return y;
	}

	int get_ancho()
	{
		return ancho;
	}

	int get_alto()
	{
		return alto;
	}

	void set_x(int px)
	{
		x = px;
	}

	void set_y(int py)
	{
		y = py;
	}
};
