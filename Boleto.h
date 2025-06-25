/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "Cliente.h"
#include <string>
#include <ctime>

class Boleto {
private:
    long long codigo;
    Pelicula* pelicula;
    Sala* sala;
    Cliente* cliente;
    std::string horario;
    int fila;
    int columna;
    std::tm fechaCompra;
    double total;

public:
    Boleto(long long codigo, Pelicula* pelicula, Sala* sala, Cliente* cliente,
        const std::string& horario, int fila, int columna,
        const std::tm& fechaCompra, double total);

    // Getters
    long long getCodigo() const { return codigo; }
    Pelicula* getPelicula() const { return pelicula; }
    Sala* getSala() const { return sala; }
    Cliente* getCliente() const { return cliente; }
    std::string getHorario() const { return horario; }
    int getFila() const { return fila; }
    int getColumna() const { return columna; }
    std::tm getFechaCompra() const { return fechaCompra; }
    double getTotal() const { return total; }

    std::string toString() const;
};