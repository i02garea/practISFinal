#ifndef _AGENDA_HPP_
#define _AGENDA_HPP_
#include"Paciente.hpp"
#include<list>
using namespace std;
class Agenda
{
	private:
	list<Paciente> agenda;
	public:
	Agenda(Paciente a)
	{
		agenda.push_back(a); 
	}
	inline void insertar(const Paciente &a)
	{
		agenda.push_back(a); 
	}
	inline void borrar(const Paciente &a)
	{
		std::list<Paciente>::iterator it = agenda.begin();
		while(it != agenda.end())
		{ 
		if(it->getDNI() == a.getDNI())
			it = agenda.erase(it);
		else
		        it++;
		}
	}
	inline list<Paciente> getAgenda() const
	{
		return agenda;
	}
	inline void setAgenda(list<Paciente> a) 
	{
		agenda=a;
	}

};
	void mostrar(list<Paciente> agenda);
	void BuscarNombre(string nombre,list<Paciente> agenda);
	list<Paciente> Borrar(const string &DNI,list<Paciente> agenda);
	list<Paciente> Modificar(const string &DNI,list<Paciente> agenda);

#endif

