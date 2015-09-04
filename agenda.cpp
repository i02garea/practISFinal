//Librerias básicas

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <list>
#include "paciente.hpp"
#include "agenda.hpp"
#include <sstream>

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
	int n=0;
	std::list<Paciente>::iterator it = agenda.begin();
	while (it != agenda.end() and n==0){
		if(it->getDNI()==DNI)
		{
			n=1;
			cout<<"Borrando\n";
			cout<<"**************************\n";
			cout<<"**************************\n";
			it=agenda.erase(it);
			it=agenda.end();
			cout<<"Registro Borrado Correctamente\n";
			
		}
		it++;
	}
	if(n==0)
	{
		cout<<"No se encontro al paciente.\n";
	}
	return agenda;
}


list<Paciente> Modificar(const string &DNI,list<Paciente> agenda)
{
	string dni,nombre, apellidos,telefono,fechaNac,cadena1;
	struct cita cita;
	//int telefono;
	int n;
	std::list<Paciente>::iterator it = agenda.begin();
	while(it != agenda.end())
	{ 
		if(it->getDNI()==DNI)
		{
			while(n!=0)
			{
				cout<<"entra aqui2"<<endl;
				cout<<"+++++++++++++++++++++++++++++++++\n";
				cout<<"\t-1. Modificar Nombre\n";
				cout<<"\t-2. Modificar Apellidos\n";
				cout<<"\t-3. Modificar DNI\n";
				cout<<"\t-4. Modificar Teléfono\n";
				cout<<"\t-5. Modificar Fecha de Nacimiento\n";
				cout<<"\t-6. Modificar Datos de la Cita\n";

				cout<<"\t-0. Salir\n";
				cout<<"+++++++++++++++++++++++++++++++++\n";
				cin>>n;
				switch(n)
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
					case 6:
						cout << "Introduce los datos da la nueva cita: ";
						cout << "Fecha de la cita:";
						cin >> cita.fecha;
						cout << "Hora de la cita:";
						cin >> cita.hora;
						cout << "Motivo:";
						cin >> cita.motivo;
						it->setCita(cita);
						break;
				}
			}
		}
		it++;
		
	}
	return agenda;
}

