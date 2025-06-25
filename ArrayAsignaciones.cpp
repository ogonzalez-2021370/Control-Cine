/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#include "pch.h"
#include "ArrayAsignaciones.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

ArrayAsignaciones::ArrayAsignaciones() : capacidad(10), cantidad(0) {
    asignaciones = new Asignacion * [capacidad];
    arrayPeliculas = nullptr;
    arraySalas = nullptr;
}

ArrayAsignaciones::~ArrayAsignaciones() {
    for (int i = 0; i < cantidad; i++) {
        delete asignaciones[i];
    }
    delete[] asignaciones;
}

void ArrayAsignaciones::redimensionar(int nuevaCapacidad) {
    Asignacion** nuevo = new Asignacion * [nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = asignaciones[i];
    }
    delete[] asignaciones;
    asignaciones = nuevo;
    capacidad = nuevaCapacidad;
}

void ArrayAsignaciones::agregar(Asignacion* asignacion) {
    if (cantidad >= capacidad) {
        redimensionar(capacidad * 2);
    }
    asignaciones[cantidad++] = asignacion;
}

void ArrayAsignaciones::eliminar(int indice) {
    if (indice < 0 || indice >= cantidad) throw std::out_of_range("Índice fuera de rango");
    delete asignaciones[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        asignaciones[i] = asignaciones[i + 1];
    }
    cantidad--;
}

void ArrayAsignaciones::modificar(int indice, Asignacion* nuevaAsignacion) {
    if (indice < 0 || indice >= cantidad) throw std::out_of_range("Índice fuera de rango");
    delete asignaciones[indice];
    asignaciones[indice] = nuevaAsignacion;
}

Asignacion* ArrayAsignaciones::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) throw std::out_of_range("Índice fuera de rango");
    return asignaciones[indice];
}

int ArrayAsignaciones::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < cantidad; i++) {
        if (asignaciones[i]->getCodigo() == codigo) return i;
    }
    return -1;
}

bool ArrayAsignaciones::existeCodigo(int codigo) const {
    return buscarPorCodigo(codigo) != -1;
}

bool ArrayAsignaciones::salaDisponible(int codigoSala, const std::string& horario) const {
    for (int i = 0; i < cantidad; i++) {
        if (asignaciones[i]->getSala()->getCodigo() == codigoSala &&
            asignaciones[i]->getHorario() == horario) {
            return false;
        }
    }
    return true;
}

bool ArrayAsignaciones::salaDisponible(int codigoSala, std::string horario, int codigoAsignacionIgnorar) const {
    for (int i = 0; i < cantidad; i++) {
        if (asignaciones[i]->getCodigo() == codigoAsignacionIgnorar) continue;
        if (asignaciones[i]->getSala()->getCodigo() == codigoSala &&
            asignaciones[i]->getHorario() == horario) {
            return false;
        }
    }
    return true;
}

void ArrayAsignaciones::guardarEnArchivo(const std::string& ruta) {
    std::ofstream archivo(ruta);
    for (int i = 0; i < cantidad; i++) {
        Asignacion* a = asignaciones[i];
        archivo << a->getCodigo() << ","
            << a->getPelicula()->getCodigo() << ","
            << a->getSala()->getCodigo() << ","
            << a->getPelicula()->getNombre() << ","
            << a->getPelicula()->getFormato() << ","
            << a->getPelicula()->getIdioma() << ","
            << a->getSala()->getNombre() << ","
            << a->getSala()->getCapacidad() << ","
            << a->getHorario() << ","
            << a->getFechaEstreno() << "\n";
    }
    archivo.close();
}

int ArrayAsignaciones::getCantidad() const {
    return cantidad;
}

void ArrayAsignaciones::cargarDesdeArchivo(const std::string& ruta) {
    limpiar();
    std::ifstream archivo(ruta);
    std::string linea;

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string codStr, codPelStr, codSalaStr, nombreP, formato, idioma;
        std::string nombreS, capacidadStr, horario, fecha;

        getline(ss, codStr, ',');
        getline(ss, codPelStr, ',');
        getline(ss, codSalaStr, ',');
        getline(ss, nombreP, ',');
        getline(ss, formato, ',');
        getline(ss, idioma, ',');
        getline(ss, nombreS, ',');
        getline(ss, capacidadStr, ',');
        getline(ss, horario, ',');
        getline(ss, fecha, ',');

        int codigo = std::stoi(codStr);
        int codPelicula = std::stoi(codPelStr);
        int codSala = std::stoi(codSalaStr);

        int indicePel = arrayPeliculas->buscarPorCodigo(codPelicula);
        int indiceSala = arraySalas->buscarPorCodigo(codSala);

        Pelicula* pelicula = arrayPeliculas->obtenerPuntero(indicePel);
        Sala* sala = arraySalas->obtenerPuntero(indiceSala);

        if (pelicula && sala) {
            Asignacion* nueva = new Asignacion(codigo, pelicula, sala, horario, fecha);
            agregar(nueva);
        }
    }

    archivo.close();
}

void ArrayAsignaciones::limpiar() {
    for (int i = 0; i < cantidad; i++) {
        delete asignaciones[i];
    }
    cantidad = 0;
}

void ArrayAsignaciones::setReferencias(ArrayPeliculas* arrPeliculas, ArraySalas* arrSalas) {
    arrayPeliculas = arrPeliculas;
    arraySalas = arrSalas;
}

void ArrayAsignaciones::ordenarPorCodigo(bool ascendente) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = i + 1; j < cantidad; ++j) {
            if (ascendente) {
                if (asignaciones[i]->getCodigo() > asignaciones[j]->getCodigo()) {
                    std::swap(asignaciones[i], asignaciones[j]);
                }
            }
            else {
                if (asignaciones[i]->getCodigo() < asignaciones[j]->getCodigo()) {
                    std::swap(asignaciones[i], asignaciones[j]);
                }
            }
        }
    }
}

void ArrayAsignaciones::generarReporteHTML(const std::string& ruta, bool ascendente) {
    ordenarPorCodigo(ascendente);

    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    archivo << "<!DOCTYPE html>\n<html>\n<head>\n";
    archivo << "<meta charset=\"UTF-8\">\n";
    archivo << "<title>Reporte de Asignaciones</title>\n";
    archivo << "<style>\n";
    archivo << "body { font-family: Arial, sans-serif; margin: 20px; }\n";
    archivo << "table { border-collapse: collapse; width: 100%; }\n";
    archivo << "th, td { border: 1px solid #ddd; padding: 8px; }\n";
    archivo << "th { background-color: #4CAF50; color: white; }\n";
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }\n";
    archivo << "</style>\n";
    archivo << "</head>\n<body>\n";
    archivo << "<h2>Reporte de Asignaciones</h2>\n";
    archivo << "<table>\n";
    archivo << "<tr><th>Codigo</th><th>Pelicula</th><th>Formato</th><th>Idioma</th><th>Sala</th><th>Horario</th><th>Fecha</th></tr>\n";

    for (int i = 0; i < cantidad; ++i) {
        Asignacion* a = asignaciones[i];
        archivo << "<tr>";
        archivo << "<td>" << a->getCodigo() << "</td>";
        archivo << "<td>" << a->getPelicula()->getNombre() << "</td>";
        archivo << "<td>" << a->getPelicula()->getFormato() << "</td>";
        archivo << "<td>" << a->getPelicula()->getIdioma() << "</td>";
        archivo << "<td>" << a->getSala()->getNombre() << "</td>";
        archivo << "<td>" << a->getHorario() << "</td>";
        archivo << "<td>" << a->getFechaEstreno() << "</td>";
        archivo << "</tr>\n";
    }

    archivo << "</table>\n</body>\n</html>";
    archivo.close();
}
