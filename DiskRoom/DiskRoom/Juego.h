#pragma once
#include <vector>
#include "Jugador.h"
#include "DiscoNormal.h"
#include "DiscoPerseguidor.h"
#include "Mapa.h"
#include "conio.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
class Juego
{
private:
	Jugador * j = new Jugador(250, 50);
	Mapa* mapaobj = new Mapa();
	DiscoNormal* discoNormal;
	vector<DiscoNormal*>* vecDiscoNormal = new vector<DiscoNormal*>;
	DiscoPerseguidor* discobj = new DiscoPerseguidor(100,100);
	vector<DiscoPerseguidor*>* vecDiscoPerseguidor = new vector<DiscoPerseguidor*>;
	bool invunerabilidad = false;
	int nivel;
	int numeroPoderes;
	int vidas;
public:

	Juego(int pnivel, int pvidas)
	{
		//VERIFICAR QUE NIVEL ES Y CREAR DISCOS EN BASE A ESO

		vecDiscoNormal->clear();
		if (pnivel == 1)
		{
			DiscoNormal* disco1 = new DiscoNormal(100, 100);
			vecDiscoNormal->push_back(disco1);
		}
		if (pnivel == 2)
		{
			DiscoNormal* disco1 = new DiscoNormal(150, 100);
			DiscoNormal* disco2 = new DiscoNormal(300, 300);
			vecDiscoNormal->push_back(disco1);
			vecDiscoNormal->push_back(disco2);
		}

		if (pnivel == 3)
		{
			DiscoNormal* disco1 = new DiscoNormal(100, 100);
			DiscoNormal* disco2 = new DiscoNormal(300, 130);
			DiscoNormal* disco3 = new DiscoNormal(310, 350);
			vecDiscoNormal->push_back(disco1);
			vecDiscoNormal->push_back(disco2);
			vecDiscoNormal->push_back(disco3);
		}

		if (pnivel == 4)
		{
			DiscoNormal* disco1 = new DiscoNormal(100, 100);
			DiscoNormal* disco2 = new DiscoNormal(320, 100);
			DiscoNormal* disco3 = new DiscoNormal(150, 350);
			vecDiscoNormal->push_back(disco1);
			vecDiscoNormal->push_back(disco2);
			vecDiscoNormal->push_back(disco3);
		}

		if (pnivel == 5)
		{
			DiscoNormal* disco1 = new DiscoNormal(104, 101);
			DiscoNormal* disco2 = new DiscoNormal(300, 100);
			DiscoNormal* disco3 = new DiscoNormal(320, 280);
			DiscoNormal* disco4 = new DiscoNormal(200, 250);
			vecDiscoNormal->push_back(disco1);
			vecDiscoNormal->push_back(disco2);
			vecDiscoNormal->push_back(disco3);
			vecDiscoNormal->push_back(disco4);
		}
		numeroPoderes = pnivel * 2 - 2;
		vidas = pvidas;
	}

	void dibujar(Graphics^ g, Bitmap^juegador, Bitmap^mapa, Bitmap^disco)
	{
		mapaobj->dibujar(g, mapa);
		j->dibujar(g, juegador);
		for (int i = 0; i < vecDiscoNormal->size(); i++)
		{
			vecDiscoNormal->at(i)->dibujar(g, disco);
			vecDiscoNormal->at(i)->mover(g);
		}
		discobj->dibujar(g, disco);
		discobj->mover(g, j->get_x(),j->get_y(), j->get_ancho(), j->get_alto());
		g->FillRectangle(Brushes::Black, 0, 0, 480, 20);
		g->DrawString("Vidas:  " + vidas.ToString(), gcnew Font("Impact", 12), Brushes::White, 22, 0);
		g->DrawString("Numero de Poderes:  " + numeroPoderes.ToString(), gcnew Font("Impact", 12), Brushes::White, 100, 0);
		invunerabilidad = colisionar();
	}

	void mover(Direcciones d, Graphics^ g)
	{
		j->mover(d, g);
	}

	bool PararTiempo()
	{
		if (numeroPoderes > 0)
		{
			for (int i = 0; i < vecDiscoNormal->size(); i++)
			{
				vecDiscoNormal->at(i)->set_dx(vecDiscoNormal->at(i)->get_dx() / 5);
				vecDiscoNormal->at(i)->set_dy(vecDiscoNormal->at(i)->get_dy() / 5);
			}

			discobj->set_dx(discobj->get_dx() / 3);
			discobj->set_dy(discobj->get_dy() / 3);
			numeroPoderes--;
			return true;
		}
		return false;
	}

	bool iniciarTiempo(int contador)
	{
		if (contador > 20 && numeroPoderes > 0)
		{
			for (int i = 0; i < vecDiscoNormal->size(); i++)
			{
				if(vecDiscoNormal->at(i)->get_dx()>0)
				vecDiscoNormal->at(i)->set_dx(10);
				else
					vecDiscoNormal->at(i)->set_dx(-10);

				if (vecDiscoNormal->at(i)->get_dy()>0)
				vecDiscoNormal->at(i)->set_dy(10);
				else
					vecDiscoNormal->at(i)->set_dy(-10);
			}

			discobj->set_dx(discobj->get_dx() * 3);
			discobj->set_dy(discobj->get_dy() * 3);
			return true;
		}
		return false;
	}
	bool colisionar()
	{
		for (int i = 0; i < vecDiscoNormal->size(); i++)
		{
			if (haycolision(j->get_x(), j->get_y(), j->get_ancho(), j->get_alto(),
				vecDiscoNormal->at(i)->get_x(), vecDiscoNormal->at(i)->get_y(),
				vecDiscoNormal->at(i)->get_ancho(), vecDiscoNormal->at(i)->get_largo()))
			{
				if (!invunerabilidad)
				vidas--;
				j->set_x(50);
				j->set_y(50);
				return true;
			}
		
		}
		if (haycolision(j->get_x(), j->get_y(), j->get_ancho(), j->get_alto(), discobj->get_x(), discobj->get_y(), discobj->get_ancho(), discobj->get_largo()))
		{
			if(!invunerabilidad)
			vidas--;
			return true;
		}
		return false;	
	}

	//MANDAS 2 OBJECTOS y RETORNA VERDAD O FALSO
	bool haycolision(int x, int y, int ancho, int largo, int px,int py, int pancho, int plargo)
	{
		if (((x + ancho >= px && x + ancho <= px + pancho) || (px + pancho >= x && px + pancho <= x + ancho)) 
			&& 
			((y +largo>= py && y + largo <= py + plargo) || (py + plargo>= y && py + plargo <= y + largo)))
			return true;
		else
			return false;
	}

	int get_vidas()
	{
		return vidas;
	}
};