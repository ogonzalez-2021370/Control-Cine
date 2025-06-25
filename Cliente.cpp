/* Autor:
     Oscar Ren� Gonzalez Rojas 9390-24-8224
 */

#include "pch.h"
#include "Cliente.h"
#include <sstream>
#include <iomanip>

Cliente::Cliente(int codigo, const std::string& nombre, const std::string& apellido,
    const std::string& identificacion, const std::tm& fechaNacimiento,
    const std::string& telefono, const std::string& correo) :
    codigo(codigo), nombre(nombre), apellido(apellido), identificacion(identificacion),
    fechaNacimiento(fechaNacimiento), telefono(telefono), correo(correo) {
}

std::string Cliente::toString() const {
    std::stringstream ss;
    ss << "C�digo: " << codigo << "\n"
        << "Nombre: " << nombre << " " << apellido << "\n"
        << "Identificaci�n: " << identificacion << "\n"
        << "Fecha Nacimiento: " << std::put_time(&fechaNacimiento, "%Y-%m-%d") << "\n"
        << "Tel�fono: " << telefono << "\n"
        << "Correo: " << correo << "\n";
    return ss.str();
}