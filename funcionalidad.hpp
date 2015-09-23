#ifndef _MENU_HPP_
#define _MENU_HPP_

//Includes del resto de archivos
#include "agenda.hpp"
#include "paciente.hpp"
#include "GestorAGFichero.hpp"


//Librerias básicas

#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;


#include<list>
using namespace std;
class Funcionalidad
{
	private:
	Agenda _agenda;
	public:

		Funcionalidad(Agenda a):_agenda(a){};

		void enter(){
			cout<<"------Presione Enter para continuar------"<<endl;
			getchar();
			getchar();
		}

		void Insertar(){
			string nombre, apellidos, dni, telefono, fechaNac;
			struct cita cita;
			Paciente p;
			int motivo;
			
			getchar();
			cout<<"Introduce el nombre: "<<endl;
			getline(std::cin,nombre);
					
			cout<<"Introduce apellidos: "<<endl;
			getline(std::cin,apellidos);
					
			cout<<"Introduce el dni: \n";
			cin>>dni;
			getchar();
			cout<<"Introduce el telefono: \n";
			cin>>telefono;
			cout<<"Introduce la fecha de Nacimiento: \n";
			getchar();
			getline(cin,fechaNac);
			cout<<"Introduce el Fecha de Cita:\n";
			getchar();
			getline(cin,cita.fecha);
			cout<<"Introduce el Hora de Cita:\n";
			getchar();
			getline(cin,cita.hora);
					
			cout<<"Elija motivo de la cita:\n";
			cout<<"  1-Consulta Medica.\n";
			cout<<"  2-Receta Medica.\n";
			cout<<"  3-Revision Enfermedad\n";
			cout<<"  Opcion elegida: ";
			cin>>motivo;
			switch(motivo)
			{
				case 1:
					cita.motivo="Consulta";
					break;
				case 2:
					cita.motivo="Receta";
					break;
				case 3:
					cita.motivo="Revision";
					break;
			}
			p.setNombre(nombre);
			p.setApellidos(apellidos);
			p.setDNI(dni);
			p.setTelefono(telefono);
			p.setFechaNac(fechaNac);
			p.setCita(cita);
			_agenda.insertar(p);
			enter();
		}

		void guardarAgenda(){
			string fichero;
			GestorAGFichero gestor;

			cout<<"Introduce el nombre del fichero para guardar tu agenda: "<<endl;
			getchar();
			getline(cin,fichero);
			gestor.setFichero(fichero);
			gestor.guardar(_agenda.getAgenda());
			cout<<"Agenda Guardada correctamente."<<endl;
			enter();
		}

		void cargarAgenda(){
			string fichero;
			GestorAGFichero gestor;

			cout<<"Introduce el nombre del fichero desde donde quieres cargar la agenda:"<<endl;
			getchar();
			getline(cin,fichero);
			gestor.setFichero(fichero);
			_agenda.setAgenda(gestor.cargar());

		 	cout<<"Agenda cargada correctamente."<<endl;
		 	enter();
		}

		void listarAgenda(){
			mostrar(_agenda.getAgenda());
			enter();
		}

		void buscarPaciente(){
			string c;

			getchar();
			cout<<"Introduce el nombre: \n";
			getline(cin,c);
			BuscarNombre(c,_agenda.getAgenda());
			enter();
		}

		void eliminarPaciente(){
			string dni;

			cout<<"Introduce el dni: \n";
			cin>>dni;
			_agenda.setAgenda(Borrar(dni,_agenda.getAgenda()));
			enter();
		}

		void modificarPaciente(){
			string dni;

			cout << "Introduzca el dni del paciente que desea modificar:"<<endl;
			cin>>dni;
			_agenda.setAgenda(Modificar(dni,_agenda.getAgenda()));
			enter();
		}

};

#endif
