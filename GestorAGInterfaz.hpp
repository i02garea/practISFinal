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


			virtual void guardar(const list<Paciente> &contactos, string fichero, int n)=0;
			virtual list<Paciente> cargar(string fichero)=0;
	};

#endif
