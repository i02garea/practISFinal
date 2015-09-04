#ifndef _GESTORAGINTERFAZ_HPP_
#define _GESTORAGINTERFAZ_HPP_
#include<stdio.h>
#include "agenda.hpp"
#include<list>
using namespace std;
	class GestorAGInterfaz
	{
		public:
			GestorAGInterfaz()
			{
				
			}


			virtual void guardar(const list<Persona> &contactos, string fichero, int n)=0;
			virtual list<Persona> cargar(string fichero)=0;
	};

#endif
