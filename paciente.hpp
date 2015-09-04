#ifndef _PACIENTE_HPP_
#define _PACIENTE_HPP_
#include<string>
using namespace std;
#include <cstdlib>
struct cita
{
	string fecha;
	string hora;
	string motivo;
};

class Paciente
{
	private:
		string _nombre;
		string _apellidos;
		string _DNI;
		string _telefono;
		string _fechaNac;
		struct cita _cita;
	public:
		Paciente(string nombre=" ",string apellidos=" ",string DNI=" ",string telefono=" ", string fecha=" ")
		{
			setNombre(nombre);
			setApellidos(apellidos);
			setDNI(DNI);
			setTelefono(telefono);
			setFechaNac(fecha);
		}
		Paciente(const Paciente &a)
		{
			*this=a;
		}
		//Observadores
	
		string getNombre() const
		{
			return _nombre;
		}
		string getApellidos() const
		{
			return _apellidos;
		}
		string getFechaNac() const
		{
			return _fechaNac;
		}
		string getDNI() const
		{
			return _DNI;
		}
		string getTelefono() const
		{
			return _telefono;
		}
		struct cita getCita()const
		{
			return _cita;
		}
	
		//Modificadores
	
		void setNombre(const string nombre)
		{
			_nombre=nombre;
		}
		void setFechaNac(const string fecha)
		{
			_fechaNac=fecha;
		}
		void setApellidos(const string apellidos)
		{
			_apellidos=apellidos;
		}
		void setDNI(const string &DNI)
		{
			_DNI=DNI;
		}
		void setTelefono(const string telefono)
		{
			_telefono=telefono;
		}
		void setCita(const struct cita cita)
		{
			_cita=cita;
		}
};
void imprimir(const Paciente &x);
#endif
