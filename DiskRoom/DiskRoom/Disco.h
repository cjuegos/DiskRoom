#pragma once
#include "iostream"
using namespace std;

class Disco
{
protected:
	int x, y, ancho, largo, dx, dy;
public:
	Disco()
	{

	}

	void set_x(int px)
	{
		x = px;
	}
	int get_x()
	{
		return x;
	}

	void set_y(int py)
	{
		y = py;
	}
	int get_y()
	{
		return y;
	}

	void set_ancho(int pancho)
	{
		ancho = pancho;
	}
	int get_ancho()
	{
		return ancho;
	}

	void set_largo(int plargo)
	{
		largo = plargo;
	}
	int get_largo()
	{
		return largo;
	}

	void set_dx(int pdx)
	{
		dx = pdx;
	}
	int get_dx()
	{
		return dx;
	}

	void set_dy(int pdy)
	{
		dy = pdy;
	}
	int get_dy()
	{
		return dy;
	}
};