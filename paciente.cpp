#include "paciente.hpp"
#include<iostream>
using namespace std;
void imprimir(const Paciente &x)
{
	cout<<"****************************************\n";
	cout<<"Nombre: "<<x.getNombre()<<endl;
	cout<<"Apellidos: "<<x.getApellidos()<<endl;
	cout<<"DNI: "<<x.getDNI()<<endl;
	cout<<"Télefono: "<<x.getTelefono()<<endl;
	cout<<"Fecha de Nacimiento: "<<x.getFechaNac()<<endl;
	cout<<"Fecha de la cita: "<<x.getCita().fecha<<endl;
	cout<<"Hora de la cita: "<<x.getCita().hora<<endl;
	cout<<"Motivo de la cita: "<<x.getCita().motivo<<endl;

}
