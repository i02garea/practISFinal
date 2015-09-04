#ifndef _GESTORAGFICHERO_HPP_
#define _GESTORAGFICHERO_HPP_
#include<list>
#include <fstream>
#include<iostream>
#include "GestorAGInterfaz.hpp"
#include "agenda.hpp"
using namespace std;
	class GESTORAGFICHERO:public GestorAGInterfaz
	{
		public:
		GESTORAGFICHERO():GestorDBInterfaz()
		{
		}
		
		list<Paciente> cargar(std::string fichero)
		{
			
			list <Paciente> agenda;
			ifstream flujoEntrada;				//Declaración del flujo de entrada
			flujoEntrada.open(fichero.c_str(),ios::in);	//Se abre el fichero para leer
			string nombre,apellido1,apellido2,apellidos,dni,telefono,direccionsF,direccion,fechaNac;
			struct cita cita;
			
			if(flujoEntrada)
			{
				while (flujoEntrada>>nombre)//Mientras no se llegue al final del fichero
				{
					//flujoEntrada>>nombre;
					flujoEntrada>>apellido1;
					flujoEntrada>>apellido2;
					flujoEntrada>>telefono;
					flujoEntrada>>dni;
					flujoEntrada>>email;
					flujoEntrada>>fechaNac;
					flujoEntrada>>cita.fecha;
					flujoEntrada>>cita.hora;
					flujoEntrada>>cita.motivo;

					//flujoEntrada.getline(direccionsF,30);
					
					//Los apellidos serán el apellido1 y el apellido 2
					apellidos=apellido1+" "+apellido2;
					//Introducimos los datos en el objeto de tipo Contacto aux
					//aux.setNombre(nombre);
					//aux.setApellidos(apellidos);
					//aux.setTelefono(telefono);
					//aux.setDNI(dni);
					//aux.setDirec(direccion);
					//aux.setEmail(email);
					//Insertamos el contacto leido en la lista
					Paciente aux(nombre,apellidos,dni,telefono,direccion,fechaNac);
					aux.setCita(cita);
					agenda.push_back(aux);
					
				}
				
				//Cerramos el fichero
				flujoEntrada.close();
				
			}
			return agenda;
		}
		
		void guardar(const list<Paciente> & contactos, string fichero)
		{
			list<Paciente>::const_iterator it; //Declaración de iterador const_iterator it para recorrer el vector
			
			//Declaración del flujo de salida
			ofstream flujoSalida;
			//Se abre el fichero para escribir
			flujoSalida.open(fichero.c_str(),ios::out);
			
			//El fichero se ha abierto correctamente
			if(flujoSalida)
			{
				for (it= contactos.begin();it!= contactos.end() ; it++) { //Recorremos el vector
					
					//Guardamos cada contacto en el fichero
					flujoSalida<<it->getNombre()<<endl;				//Nombre
					flujoSalida<<it->getApellidos()<<endl;				//Apellidos
					flujoSalida<<it->getTelefono()<<endl;				//Telefono
					flujoSalida<<it->getDNI()<<endl;				//DNI
					flujoSalida<<it->getFechaNac()<<endl;				//Fecha de Nacimiento
					flujoSalida<<it->getCita().fecha<<endl;				//Fecha de Cita
					flujoSalida<<it->getCita().hora<<endl;				//Hora de Cita
					flujoSalida<<it->getCita().motivo<<endl;			//Motivo de Cita

					
				}
				flujoSalida.close(); //Cerramos el fichero
			}
			else
			{
				cout<<"Error en la apertura del fichero"<<endl;
				exit(-1);
			}
			
		}
		
	};

#endif
