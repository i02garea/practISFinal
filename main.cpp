//Includes del resto de archivos

#include "funcionalidad.hpp"


//Librerias básicas

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdlib>


//Espacio de nombres std

using namespace std;



int main()
{

	int opcion,n=0;
	

	Agenda a;
	Funcionalidad f(a);

	const int TAM=200;

	while(opcion!=0){
		system("clear");
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
					system("clear");
					f.Insertar();
					n++;
				}

				if (n==TAM){
					cout<<"La agenda esta completa. Contiene 200 registros."<<endl;
				 	cout<<"Borre algun registro para poder insertar."<<endl;
				} 

				break;

			case 2:
				system("clear");
				f.guardarAgenda();
		 		break;

		 	case 3:
		 		system("clear");
		 		f.cargarAgenda();
		 		break;
		 		cout<<"Agenda cargada correctamente."<<endl;


		 	case 4:
		 		system("clear");
				f.listarAgenda();
		 		break;

		 	case 5:
		 		system("clear");
		 		f.buscarPaciente();
				break;

			case 6:
				system("clear");
		 		f.eliminarPaciente();
				break;

			case 7:
				system("clear");
				f.modificarPaciente();
		 		break;
		}
	}
	return 0;

}
