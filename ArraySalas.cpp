/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#include "pch.h"
#include "ArraySalas.h"
#include <stdexcept>
#include <fstream>
#include <sstream>

ArraySalas::ArraySalas() : capacidad(10), cantidad(0) {
    salas = new Sala[capacidad];
}

ArraySalas::~ArraySalas() {
    delete[] salas;
}

void ArraySalas::redimensionar(int nuevaCapacidad) {
    Sala* nuevoArreglo = new Sala[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevoArreglo[i] = salas[i];
    }
    delete[] salas;
    salas = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

void ArraySalas::agregar(const Sala& sala) {
    if (cantidad == capacidad) {
        redimensionar(capacidad * 2);
    }
    salas[cantidad++] = sala;
}

Sala ArraySalas::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return salas[indice];
}

void ArraySalas::modificar(int indice, const Sala& nuevaSala) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    salas[indice] = nuevaSala;
}

void ArraySalas::eliminar(int indice) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    for (int i = indice; i < cantidad - 1; ++i) {
        salas[i] = salas[i + 1];
    }
    cantidad--;
}

int ArraySalas::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < cantidad; ++i) {
        if (salas[i].getCodigo() == codigo) {
            return i;
        }
    }
    return -1; 
}

bool ArraySalas::existeCodigo(int codigo) const {
    return buscarPorCodigo(codigo) != -1;
}

bool ArraySalas::verificarSilla(int indiceSala, int fila, int columna) const {
    if (indiceSala < 0 || indiceSala >= cantidad) {
        throw std::out_of_range("Índice de sala inválido");
    }
    return salas[indiceSala].verificarSilla(fila, columna);
}

void ArraySalas::ocuparSilla(int indiceSala, int fila, int columna) {
    if (indiceSala < 0 || indiceSala >= cantidad) {
        throw std::out_of_range("Índice de sala inválido");
    }
    salas[indiceSala].ocuparSilla(fila, columna);
}

void ArraySalas::resetearSillas(int indiceSala) {
    if (indiceSala < 0 || indiceSala >= cantidad) {
        throw std::out_of_range("Índice de sala inválido");
    }
    salas[indiceSala].resetearSillas();
}

int ArraySalas::getCantidad() const {
    return cantidad;
}

Sala* ArraySalas::obtenerPuntero(int indice) {
    if (indice >= 0 && indice < cantidad) {
        return &salas[indice];
    }
    return nullptr;
}

void ArraySalas::guardarEnArchivo(const std::string& ruta) {
    std::ofstream archivo(ruta);
    for (int i = 0; i < cantidad; i++) {
        Sala* s = &salas[i];
        archivo << s->getCodigo() << ","
			<< s->getNombre() << ","
            << s->getCapacidad() << ","
            << s->getUbicacion() << ","
            << s->getNombreEncargado() << ","
            << s->getTelefonoEncargado() << "\n";
    }
    archivo.close();
}

void ArraySalas::cargarDesdeArchivo(const std::string& ruta) {
    limpiar();
    std::ifstream archivo(ruta);
    std::string linea;
    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string codigoStr, nombre, capacidadStr, ubicacion, encargado, telefono;

        getline(ss, codigoStr, ',');
        getline(ss, nombre, ',');
        getline(ss, capacidadStr, ',');
        getline(ss, ubicacion, ',');
        getline(ss, encargado, ',');
        getline(ss, telefono, ',');

        int codigo = std::stoi(codigoStr);
        int capacidad = std::stoi(capacidadStr);

        Sala s(codigo, nombre, capacidad, ubicacion, encargado, telefono);
        agregar(s);
    }
    archivo.close();
}

void ArraySalas::limpiar() {
    cantidad = 0;
}

void ArraySalas::generarReporteHTML(const std::string& ruta, bool ascendente) {
    ordenarPorCodigo(ascendente);
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    archivo << "<!DOCTYPE html>\n<html>\n<head>\n";
    archivo << "<meta charset=\"UTF-8\">\n";
    archivo << "<title>Reporte de Salas</title>\n";
    archivo << "<style>\n";
    archivo << "body { font-family: Arial, sans-serif; margin: 20px; }\n";
    archivo << "table { border-collapse: collapse; width: 100%; }\n";
    archivo << "th, td { border: 1px solid #ddd; padding: 8px; }\n";
    archivo << "th { background-color: #4CAF50; color: white; }\n";
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }\n";
    archivo << "</style>\n";
    archivo << "</head>\n<body>\n";
    archivo << "<h2>Reporte de Salas</h2>\n";
    archivo << "<table>\n";
    archivo << "<tr><th>Codigo</th><th>Nombre</th><th>Capacidad</th><th>Ubicacion</th>"
        "<th>Encargado</th><th>Telefono</th></tr>";

    for (int i = 0; i < cantidad; ++i) {
        archivo << "<tr>";
        archivo << "<td>" << salas[i].getCodigo() << "</td>";
        archivo << "<td>" << salas[i].getNombre() << "</td>";
        archivo << "<td>" << salas[i].getCapacidad() << "</td>";
        archivo << "<td>" << salas[i].getUbicacion() << "</td>";
        archivo << "<td>" << salas[i].getNombreEncargado() << "</td>";
        archivo << "<td>" << salas[i].getTelefonoEncargado() << "</td>";
        archivo << "</tr>";
    }

    archivo << "</table></body></html>";
    archivo.close();
}


void ArraySalas::ordenarPorCodigo(bool ascendente) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
            bool condicion = ascendente ?
                (salas[j].getCodigo() > salas[j + 1].getCodigo()) :
                (salas[j].getCodigo() < salas[j + 1].getCodigo());
            if (condicion) {
                Sala temp = salas[j];
                salas[j] = salas[j + 1];
                salas[j + 1] = temp;
            }
        }
    }
}


