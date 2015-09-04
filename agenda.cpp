//Librerias básicas

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include "paciente.hpp"
#include "agenda.hpp"

//Espacio de nombres std
using namespace std;
void mostrar(list<Paciente> agenda)
{
	std::list<Paciente>::iterator it = agenda.begin();
	while(it != agenda.end())
	{ 
		imprimir(*it);

		it++;
	}
}
void BuscarNombre(string nombre,list<Paciente> agenda)
{
	int n=0;
	std::list<Paciente>::iterator it = agenda.begin();
	while(it != agenda.end())
	{ 
		if(it->getNombre()==nombre)
		{
			n=1;
			cout<<"Paciente encontrado"<<endl;
		}
		it++;
	}
	if(n==0)
	{
		cout<<"No se encuentra al paciente\n";
	}

}

list<Paciente> Borrar(const string &DNI,list<Paciente> agenda)
{
	int n;
	
	for (list<Paciente>::const_iterator it=agenda.begin() ; it!=agenda.end() ; it++) {
		if(it->getDNI()==DNI)
		{
			n=1;
			cout<<"Borrando\n";
			agenda.erase(it);
			it=agenda.end();
			
		}
	}
	if(n==0)
	{
		cout<<"No se encontro al paciente.\n";
	}
	return agenda;
}

list<Paciente> Modificar(const string &DNI,list<Paciente> agenda)
{
	string dni,nombre, apellidos,telefono,fechaNac;
	//int telefono;
	int t=0;
	std::list<Persona>::iterator it = agenda.begin();
	while(it != agenda.end())
	{ 
		if(it->getDNI()==DNI)
		{
			while(t!=10)
			{
				cout<<"+++++++++++++++++++++++++++++++++\n";
				cout<<"\t-1. Modificar Nombre\n";
				cout<<"\t-2. Modificar Apellidos\n";
				cout<<"\t-3. Modificar DNI\n";
				cout<<"\t-4. Modificar Teléfono\n";
				cout<<"\t-5. Modificar Fecha de Nacimiento\n";

				cout<<"\t-0. Salir\n";
				cout<<"+++++++++++++++++++++++++++++++++\n";
				cin>>t;
				switch(t)
				{
					case 1:
						cout<<"Introduce el nuevo nombre: ";
						cin>>nombre;
						it->setNombre(nombre);
						break;
					case 2:
						cout<<"Introduce los nuevos apellidos: ";
						cin>>apellidos;
						it->setApellidos(apellidos);
						break;
					case 3:
						cout<<"Introduce el nuevo DNI: ";
						cin>>dni;
						it->setDNI(dni);
						break;
					case 4:
						cout<<"Introduce el nuevo teléfono: ";
						cin>>telefono;
						it->setTelefono(telefono);
						break;
					case 5:
						cout<<"Introduce el nueva fecha de nacimiento: ";
						cin>>fechaNac;
						it->setFechaNac(fechaNac);
						break;

				}
			}
		}
			it++;
		
	}
	return agenda;
}

