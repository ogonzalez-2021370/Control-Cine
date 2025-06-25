/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#include "pch.h"
#include "Asignacion.h"
#include <sstream>

Asignacion::Asignacion(int codigo, Pelicula* pelicula, Sala* sala, std::string horario, std::string fechaEstreno)
    : codigo(codigo), pelicula(pelicula), sala(sala), horario(horario), fechaEstreno(fechaEstreno) {
}

std::string Asignacion::toString() const {
    std::stringstream ss;
    ss << "Código: " << codigo << "\n"
        << "Película: " << pelicula->getNombre() << " (" << pelicula->getCodigo() << ")\n"
        << "Sala: " << sala->getNombre() << " (" << sala->getCodigo() << ")\n"
        << "Horario: " << horario << "\n"
        << "Fecha Estreno: " << fechaEstreno << "\n";
    return ss.str();
}