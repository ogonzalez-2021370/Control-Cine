/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#include "pch.h"
#include "ArrayClientes.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>

ArrayClientes::ArrayClientes() : capacidad(10), cantidad(0) {
    clientes = new Cliente * [capacidad];
}

ArrayClientes::~ArrayClientes() {
    for (int i = 0; i < cantidad; i++) {
        delete clientes[i];
    }
    delete[] clientes;
}

void ArrayClientes::redimensionar(int nuevaCapacidad) {
    Cliente** nuevo = new Cliente * [nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = clientes[i];
    }
    delete[] clientes;
    clientes = nuevo;
    capacidad = nuevaCapacidad;
}

void ArrayClientes::agregar(Cliente* cliente) {
    if (cantidad >= capacidad) {
        redimensionar(capacidad * 2);
    }
    clientes[cantidad++] = cliente;
}

void ArrayClientes::eliminar(int indice) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    delete clientes[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    cantidad--;
}

void ArrayClientes::modificar(int indice, Cliente* nuevoCliente) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    delete clientes[indice];
    clientes[indice] = nuevoCliente;
}

Cliente* ArrayClientes::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return clientes[indice];
}

int ArrayClientes::getCantidad() const {
    return cantidad;
}

int ArrayClientes::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

bool ArrayClientes::existeCodigo(int codigo) const {
    return buscarPorCodigo(codigo) != -1;
}

int ArrayClientes::buscarPorIdentificacion(const std::string& identificacion) const {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getIdentificacion() == identificacion) {
            return i;
        }
    }
    return -1;
}

void ArrayClientes::guardarEnArchivo(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    for (int i = 0; i < cantidad; i++) {
        Cliente* c = clientes[i];
        std::tm fecha = c->getFechaNacimiento();
        archivo << c->getCodigo() << ","
            << c->getNombre() << ","
            << c->getApellido() << ","
            << c->getIdentificacion() << ","
            << std::put_time(&fecha, "%Y-%m-%d") << ","
            << c->getTelefono() << ","
            << c->getCorreo() << "\n";
    }

    archivo.close();
}

void ArrayClientes::cargarDesdeArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) return;

    // Limpiar los clientes actuales
    for (int i = 0; i < cantidad; i++) {
        delete clientes[i];
    }
    cantidad = 0;

    std::string linea;
    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string codigoStr, nombre, apellido, identificacion, fechaStr, telefono, correo;

        getline(ss, codigoStr, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, identificacion, ',');
        getline(ss, fechaStr, ',');
        getline(ss, telefono, ',');
        getline(ss, correo, ',');

        // Parsear fecha
        std::tm fecha = {};
        std::istringstream fechaStream(fechaStr);
        fechaStream >> std::get_time(&fecha, "%Y-%m-%d");

        Cliente* nuevo = new Cliente(
            std::stoi(codigoStr),
            nombre,
            apellido,
            identificacion,
            fecha,
            telefono,
            correo
        );

        agregar(nuevo);
    }

    archivo.close();
}

void ArrayClientes::generarReporteHTML(const std::string& ruta, bool ascendente) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    // Ordenar clientes
    std::vector<Cliente*> copia;
    for (int i = 0; i < cantidad; i++) copia.push_back(clientes[i]);

    std::sort(copia.begin(), copia.end(), [ascendente](Cliente* a, Cliente* b) {
        return ascendente ? a->getCodigo() < b->getCodigo() : a->getCodigo() > b->getCodigo();
        });

    archivo << "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
    archivo << "<meta charset=\"UTF-8\">\n";
    archivo << "<title>Reporte de Clientes</title>\n";
    archivo << "<style>\n";
    archivo << "body { font-family: Arial, sans-serif; margin: 20px; }\n";
    archivo << "table { border-collapse: collapse; width: 100%; }\n";
    archivo << "th, td { border: 1px solid #ddd; padding: 8px; }\n";
    archivo << "th { background-color: #4CAF50; color: white; }\n";
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }\n";
    archivo << "</style>\n";
    archivo << "</head>\n<body>\n";

    archivo << "<h2>Reporte de Clientes</h2>\n";
    archivo << "<table>\n";
    archivo << "<tr>"
        << "<th>Codigo</th><th>Nombre</th><th>Apellido</th><th>Identificacion</th>"
        << "<th>Fecha de Nacimiento</th><th>Telefono</th><th>Correo</th></tr>\n";

    for (Cliente* c : copia) {
        std::tm fecha = c->getFechaNacimiento();
        std::stringstream ssFecha;
        ssFecha << std::put_time(&fecha, "%Y-%m-%d");

        archivo << "<tr>"
            << "<td>" << c->getCodigo() << "</td>"
            << "<td>" << c->getNombre() << "</td>"
            << "<td>" << c->getApellido() << "</td>"
            << "<td>" << c->getIdentificacion() << "</td>"
            << "<td>" << ssFecha.str() << "</td>"
            << "<td>" << c->getTelefono() << "</td>"
            << "<td>" << c->getCorreo() << "</td>"
            << "</tr>\n";
    }

    archivo << "</table>\n</body>\n</html>";
    archivo.close();
}


void ArrayClientes::ordenarPorCodigo(bool ascendente) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = i + 1; j < cantidad; ++j) {
            if ((ascendente && clientes[i]->getCodigo() > clientes[j]->getCodigo()) ||
                (!ascendente && clientes[i]->getCodigo() < clientes[j]->getCodigo())) {
                std::swap(clientes[i], clientes[j]);
            }
        }
    }
}
