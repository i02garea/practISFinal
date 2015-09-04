#ifndef _GESTORAGFICHERO_HPP_
#define _GESTORAGFICHERO_HPP_
#include<stdio.h>
#include "agenda.hpp"
#include <list>
using namespace std;

void guardar(const list<Paciente> & pacientes, string fichero);
list<Paciente> cargar(std::string fichero);

#endif
