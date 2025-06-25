/* Autores:
     Oscar Ren� Gonzalez Rojas 9390-24-8224
     Francisco Estuardo P�rez L�pez 9390-24-4397
 */

#include "pch.h"
#include "Usuario.h"
#include <sstream>

Usuario::Usuario(const std::string& usuarioLogin, const std::string& contrasena,
    const std::string& tipoUsuario, const std::string& nombre,
    const std::string& apellido, const std::string& identificacion,
    const std::string& telefono, const std::string& correo,
    const std::string& direccion) :
    usuarioLogin(usuarioLogin), contrasena(contrasena), tipoUsuario(tipoUsuario),
    nombre(nombre), apellido(apellido), identificacion(identificacion),
    telefono(telefono), correo(correo), direccion(direccion) {
}

std::string Usuario::toString() const {
    std::stringstream ss;
    ss << "Usuario: " << usuarioLogin << "\n"
        << "Tipo: " << tipoUsuario << "\n"
        << "Nombre: " << nombre << " " << apellido << "\n"
        << "Identificaci�n: " << identificacion << "\n"
        << "Tel�fono: " << telefono << "\n"
        << "Correo: " << correo << "\n"
        << "Direcci�n: " << direccion << "\n";
    return ss.str();
}