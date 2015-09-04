//Includes del resto de archivos

#include "agenda.hpp"
#include "paciente.hpp"
#include "GestorAGFichero.hpp"



//Librerias básicas

#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>

//Espacio de nombres std

using namespace std;



int main()
{

	int opcion,n=0,motivo;
	string c, nombre, apellidos, dni, telefono, fechaNac;
	struct cita cita;
	Paciente p;
	Agenda a;
	string fichero;

	const int TAM=200;

	while(opcion!=0){
		cout<<"---------------------------------------------"<<endl;
		cout<<"---------------------------------------------"<<endl;
		cout<<"\t-1. Insertar un nuevo paciente\n";
		cout<<"\t-2. Introducir lista de pacientes en fichero\n";
		cout<<"\t-3. Leer lista de pacientes del fichero\n";
		cout<<"\t-4. Mostrar agenda\n";
		cout<<"\t-5. Buscar paciente mediante el nombre\n";
		cout<<"\t-6. Eliminar paciente mediante su dni\n";
		cout<<"\t-7. Modificar paciente\n";
		cout<<"\t-0. Salir\n";
		cout<<"---------------------------------------------"<<endl;
		cout<<"---------------------------------------------"<<endl;		
		cin>>opcion;
		switch(opcion)
		{
			case 1:  //Insertar nuevo Paciente
				if(n<=TAM){	
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
					a.insertar(p);
					n++;
				}

				if (n==TAM){
					cout<<"La agenda esta completa. Contiene 200 registros."<<endl;
				 	cout<<"Borre algun registro para poder insertar."<<endl;
				} 

				break;

			case 2:
				cout<<"Introduce el nombre del fichero para guardar tu agenda: "<<endl;
				getchar();
				getline(cin,fichero);
				guardar(a.getAgenda(),fichero);
		 		break;

		 	case 3:
		 		cout<<"Introduce el nombre del fichero desde donde quieres cargar la agenda:"<<endl;
				getchar();
				getline(cin,fichero);
				a.setAgenda(cargar(fichero));
		 		break;

		 	case 4:

				mostrar(a.getAgenda());
		 		break;

		 	case 5:
		 		getchar();
				cout<<"Introduce el nombre: \n";
				getline(cin,c);
				BuscarNombre(c,a.getAgenda());
				break;

			case 6:
				cout<<"Introduce el dni: \n";
				cin>>dni;
				a.setAgenda(Borrar(dni,a.getAgenda()));
				break;

			case 7:
				cout<<"Introduce el dni\n";
				getchar();
				cin>>dni;
				a.setAgenda(Modificar(dni,a.getAgenda()));
		 		break;
		}
	}
	return 0;

}
