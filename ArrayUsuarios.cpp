/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#include "pch.h"
#include "ArrayUsuarios.h"
#include <stdexcept>
#include <fstream>
#include <sstream>

ArrayUsuarios::ArrayUsuarios() : capacidad(10), cantidad(0) {
    usuarios = new Usuario * [capacidad];
}

ArrayUsuarios::~ArrayUsuarios() {
    for (int i = 0; i < cantidad; i++) {
        delete usuarios[i];
    }
    delete[] usuarios;
}

void ArrayUsuarios::redimensionar(int nuevaCapacidad) {
    Usuario** nuevo = new Usuario * [nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = usuarios[i];
    }
    delete[] usuarios;
    usuarios = nuevo;
    capacidad = nuevaCapacidad;
}

void ArrayUsuarios::agregar(Usuario* usuario) {
    if (cantidad >= capacidad) {
        redimensionar(capacidad * 2);
    }
    usuarios[cantidad++] = usuario;
}

void ArrayUsuarios::eliminar(int indice) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    delete usuarios[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }
    cantidad--;
}

void ArrayUsuarios::modificar(int indice, Usuario* nuevoUsuario) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    delete usuarios[indice];
    usuarios[indice] = nuevoUsuario;
}

Usuario* ArrayUsuarios::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return usuarios[indice];
}

int ArrayUsuarios::getCantidad() const {
    return cantidad;
}

// Aca realizamos la busqueda
int ArrayUsuarios::buscarPorUsuarioLogin(const std::string& usuarioLogin) const {
    for (int i = 0; i < cantidad; i++) {
        if (usuarios[i]->getUsuarioLogin() == usuarioLogin) {
            return i;
        }
    }
    return -1;
}

bool ArrayUsuarios::existeUsuarioLogin(const std::string& usuarioLogin) const {
    return buscarPorUsuarioLogin(usuarioLogin) != -1;
}

int ArrayUsuarios::buscarPorIdentificacion(const std::string& identificacion) const {
    for (int i = 0; i < cantidad; i++) {
        if (usuarios[i]->getIdentificacion() == identificacion) {
            return i;
        }
    }
    return -1;
}

void ArrayUsuarios::guardarEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    for (int i = 0; i < cantidad; i++) {
        Usuario* u = usuarios[i];
        archivo << u->getUsuarioLogin() << ","
            << u->getContrasena() << ","
            << u->getTipoUsuario() << ","
            << u->getNombre() << ","
            << u->getApellido() << ","
            << u->getIdentificacion() << ","
            << u->getTelefono() << ","
            << u->getCorreo() << ","
            << u->getDireccion() << "\n";
    }
    archivo.close();
}

void ArrayUsuarios::cargarDesdeArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) return;

    for (int i = 0; i < cantidad; i++) {
        delete usuarios[i];
    }
    cantidad = 0;

    std::string linea;
    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string usuarioLogin, contrasena, tipoUsuario, nombre, apellido;
        std::string identificacion, telefono, correo, direccion;

        getline(ss, usuarioLogin, ',');
        getline(ss, contrasena, ',');
        getline(ss, tipoUsuario, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, identificacion, ',');
        getline(ss, telefono, ',');
        getline(ss, correo, ',');
        getline(ss, direccion, '\n');

        // Aca vamos a evitar duplicados 
        if (!existeUsuarioLogin(usuarioLogin)) {
            Usuario* nuevo = new Usuario(
                usuarioLogin, contrasena, tipoUsuario,
                nombre, apellido, identificacion,
                telefono, correo, direccion
            );
            agregar(nuevo);
        }
    }
    archivo.close();
}

void ArrayUsuarios::ordenarPorUsuario(bool ascendente) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
            std::string usuario1 = usuarios[j]->getUsuarioLogin();
            std::string usuario2 = usuarios[j + 1]->getUsuarioLogin();
            bool condicion = ascendente ? (usuario1 > usuario2) : (usuario1 < usuario2);
            if (condicion) {
                Usuario* temp = usuarios[j];
                usuarios[j] = usuarios[j + 1];
                usuarios[j + 1] = temp;
            }
        }
    }
}

void ArrayUsuarios::generarReporteHTML(const std::string& ruta, bool ascendente) {
    ordenarPorUsuario(ascendente);
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    archivo << "<!DOCTYPE html>\n<html>\n<head>\n";
    archivo << "<meta charset=\"UTF-8\">\n";
    archivo << "<title>Reporte de Usuarios</title>\n";
    archivo << "<style>\n";
    archivo << "body { font-family: Arial, sans-serif; margin: 20px; }\n";
    archivo << "table { border-collapse: collapse; width: 100%; }\n";
    archivo << "th, td { border: 1px solid #ddd; padding: 8px; }\n";
    archivo << "th { background-color: #4CAF50; color: white; }\n";
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }\n";
    archivo << "</style>\n";
    archivo << "</head>\n<body>\n";
    archivo << "<h2>Reporte de Usuarios</h2>\n";
    archivo << "<table>\n";
    archivo << "<tr><th>Usuario</th><th>Tipo</th><th>Nombre</th><th>Apellido</th>"
        << "<th>Identificacion</th><th>Telefono</th><th>Correo</th><th>Direccion</th></tr>";

    for (int i = 0; i < cantidad; ++i) {
        Usuario* u = usuarios[i];
        archivo << "<tr>";
        archivo << "<td>" << u->getUsuarioLogin() << "</td>";
        archivo << "<td>" << u->getTipoUsuario() << "</td>";
        archivo << "<td>" << u->getNombre() << "</td>";
        archivo << "<td>" << u->getApellido() << "</td>";
        archivo << "<td>" << u->getIdentificacion() << "</td>";
        archivo << "<td>" << u->getTelefono() << "</td>";
        archivo << "<td>" << u->getCorreo() << "</td>";
        archivo << "<td>" << u->getDireccion() << "</td>";
        archivo << "</tr>";
    }

    archivo << "</table></body></html>";
    archivo.close();
}

