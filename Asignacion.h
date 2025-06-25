/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include <string>

class Asignacion {
private:
    int codigo;
    Pelicula* pelicula;
    Sala* sala;
    std::string horario;
    std::string fechaEstreno;

public:
    Asignacion(int codigo, Pelicula* pelicula, Sala* sala, std::string horario, std::string fechaEstreno);
    ~Asignacion() {}

    int getCodigo() const { return codigo; }
    Pelicula* getPelicula() const { return pelicula; }
    Sala* getSala() const { return sala; }
    std::string getHorario() const { return horario; }
    std::string getFechaEstreno() const { return fechaEstreno; }

    void setHorario(std::string nuevoHorario) { horario = nuevoHorario; }
    void setFechaEstreno(std::string nuevaFecha) { fechaEstreno = nuevaFecha; }

    std::string toString() const;
};