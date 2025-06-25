/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#include "pch.h"
#include "Sala.h"
#include <stdexcept>

Sala::Sala() : codigo(0), capacidad(0), sillas(nullptr) {}

Sala::Sala(int codigo, std::string nombre, int capacidad, std::string ubicacion,
    std::string nombreEncargado, std::string telefonoEncargado)
    : codigo(codigo), nombre(nombre), capacidad(capacidad), ubicacion(ubicacion),
    nombreEncargado(nombreEncargado), telefonoEncargado(telefonoEncargado) {
    inicializarSillas();
}

Sala::~Sala() {
    liberarSillas();
}

Sala::Sala(const Sala& otra) {
    this->codigo = otra.codigo;
    this->nombre = otra.nombre;
    this->capacidad = otra.capacidad;
    this->ubicacion = otra.ubicacion;
    this->nombreEncargado = otra.nombreEncargado;
    this->telefonoEncargado = otra.telefonoEncargado;

    int filas = (capacidad == 40) ? 5 : 7;
    int columnas = 8;

    
    sillas = new bool* [filas];
    for (int i = 0; i < filas; ++i) {
        sillas[i] = new bool[columnas];
        for (int j = 0; j < columnas; ++j) {
            sillas[i][j] = otra.sillas[i][j];
        }
    }
}

Sala& Sala::operator=(const Sala& otra) {
    if (this != &otra) {
        // Aca liberamos memoria actual
        liberarSillas();

        // Copiar valores
        this->codigo = otra.codigo;
        this->nombre = otra.nombre;
        this->capacidad = otra.capacidad;
        this->ubicacion = otra.ubicacion;
        this->nombreEncargado = otra.nombreEncargado;
        this->telefonoEncargado = otra.telefonoEncargado;

        int filas = (capacidad == 40) ? 5 : 7;
        int columnas = 8;

        sillas = new bool* [filas];
        for (int i = 0; i < filas; ++i) {
            sillas[i] = new bool[columnas];
            for (int j = 0; j < columnas; ++j) {
                sillas[i][j] = otra.sillas[i][j];
            }
        }
    }
    return *this;
}


// Aca vamos a implementar los getters
int Sala::getCodigo() const { return codigo; }
std::string Sala::getNombre() const { return nombre; }
int Sala::getCapacidad() const { return capacidad; }
std::string Sala::getUbicacion() const { return ubicacion; }
std::string Sala::getNombreEncargado() const { return nombreEncargado; }
std::string Sala::getTelefonoEncargado() const { return telefonoEncargado; }
bool** Sala::getSillas() const { return sillas; }

// Aca vamos a implementar los setters
void Sala::setCodigo(int codigo) { this->codigo = codigo; }
void Sala::setNombre(std::string nombre) { this->nombre = nombre; }
void Sala::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
    liberarSillas();
    inicializarSillas();
}
void Sala::setUbicacion(std::string ubicacion) { this->ubicacion = ubicacion; }
void Sala::setNombreEncargado(std::string nombreEncargado) { this->nombreEncargado = nombreEncargado; }
void Sala::setTelefonoEncargado(std::string telefonoEncargado) { this->telefonoEncargado = telefonoEncargado; }

// Aca esta nuestro metodo para gestion de sillas
void Sala::inicializarSillas() {
    int filas = (capacidad == 40) ? 5 : 7;
    int columnas = 8;

    sillas = new bool* [filas];
    for (int i = 0; i < filas; ++i) {
        sillas[i] = new bool[columnas];
        for (int j = 0; j < columnas; ++j) {
            sillas[i][j] = false; // Aca indicamos que todas estan desocupadas inicialmente
        }
    }
}

void Sala::liberarSillas() {
    if (sillas != nullptr) {
        int filas = (capacidad == 40) ? 5 : 7;
        for (int i = 0; i < filas; ++i) {
            delete[] sillas[i];
        }
        delete[] sillas;
        sillas = nullptr;
    }
}

void Sala::resetearSillas() {
    liberarSillas();
    inicializarSillas();
}

bool Sala::verificarSilla(int fila, int columna) const {
    int filas = (capacidad == 40) ? 5 : 7;
    if (fila < 0 || fila >= filas || columna < 0 || columna >= 8) {
        throw std::out_of_range("Posición de silla inválida");
    }
    return sillas[fila][columna];
}

void Sala::ocuparSilla(int fila, int columna) {
    int filas = (capacidad == 40) ? 5 : 7;
    if (fila < 0 || fila >= filas || columna < 0 || columna >= 8) {
        throw std::out_of_range("Posición de silla inválida");
    }
    sillas[fila][columna] = true;
}

std::string Sala::toString() const {
    return "Sala #" + std::to_string(codigo) + ": " + nombre +
        " (" + std::to_string(capacidad) + " asientos)";
}