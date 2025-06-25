/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#include "pch.h"
#include "Pelicula.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Aca tenemos el constructor por defecto
Pelicula::Pelicula() {
    this->codigo = 0;
    this->nombre = "";
    this->genero = "";
    this->clasificacion = "";
    this->idioma = "";
    this->formato = "";
    this->precio = 0.0;
    this->estado = false;
}

// Aca tenemos el constructor con parametros
Pelicula::Pelicula(int codigo, string nombre, string genero, string clasificacion,
    string idioma, string formato, double precio, bool estado) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->genero = genero;
    this->clasificacion = clasificacion;
    this->idioma = idioma;
    this->formato = formato;
    this->precio = precio;
    this->estado = estado;
}

// Nuestros metodos Getters
int Pelicula::getCodigo() const {
    return codigo;
}

string Pelicula::getNombre() const {
    return nombre;
}

string Pelicula::getGenero() const {
    return genero;
}

string Pelicula::getClasificacion() const {
    return clasificacion;
}

string Pelicula::getIdioma() const {
    return idioma;
}

string Pelicula::getFormato() const {
    return formato;
}

double Pelicula::getPrecio() const {
    return precio;
}

bool Pelicula::getEstado() const {
    return estado;
}

// Nuestros metodos Setter
void Pelicula::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Pelicula::setNombre(string nombre) {
    this->nombre = nombre;
}

void Pelicula::setGenero(string genero) {
    this->genero = genero;
}

void Pelicula::setClasificacion(string clasificacion) {
    this->clasificacion = clasificacion;
}

void Pelicula::setIdioma(string idioma) {
    this->idioma = idioma;
}

void Pelicula::setFormato(string formato) {
    this->formato = formato;
}

void Pelicula::setPrecio(double precio) {
    this->precio = precio;
}

void Pelicula::setEstado(bool estado) {
    this->estado = estado;
}

// Aca tenemos el metodo para convertir a string para presentación
string Pelicula::toString() const {
    stringstream ss;
    ss << "Codigo: " << codigo << "\n";
    ss << "Nombre: " << nombre << "\n";
    ss << "Genero: " << genero << "\n";
    ss << "Clasificacion: " << clasificacion << "\n";
    ss << "Idioma: " << idioma << "\n";
    ss << "Formato: " << formato << "\n";
    ss << "Precio: Q" << fixed << setprecision(2) << precio << "\n";
    ss << "Estado: " << (estado ? "Disponible" : "No disponible") << "\n";
    return ss.str();
}