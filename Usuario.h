/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once
#include <string>
#include <ctime>

class Usuario {
private:
    std::string usuarioLogin;
    std::string contrasena;
	std::string tipoUsuario; // Si es operador o administrador
    std::string nombre;
    std::string apellido;
    std::string identificacion; 
    std::string telefono;
    std::string correo;
    std::string direccion;

public:
    // Aca tenemos nuestro constructor
    Usuario(const std::string& usuarioLogin, const std::string& contrasena,
        const std::string& tipoUsuario, const std::string& nombre,
        const std::string& apellido, const std::string& identificacion,
        const std::string& telefono, const std::string& correo,
        const std::string& direccion);

    // Getters
    std::string getUsuarioLogin() const { return usuarioLogin; }
    std::string getContrasena() const { return contrasena; }
    std::string getTipoUsuario() const { return tipoUsuario; }
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    std::string getIdentificacion() const { return identificacion; }
    std::string getTelefono() const { return telefono; }
    std::string getCorreo() const { return correo; }
    std::string getDireccion() const { return direccion; }

    // Setters
    void setContrasena(const std::string& nuevaContrasena) { contrasena = nuevaContrasena; }
    void setTipoUsuario(const std::string& nuevoTipo) { tipoUsuario = nuevoTipo; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setApellido(const std::string& nuevoApellido) { apellido = nuevoApellido; }
    void setTelefono(const std::string& nuevoTelefono) { telefono = nuevoTelefono; }
    void setCorreo(const std::string& nuevoCorreo) { correo = nuevoCorreo; }
    void setDireccion(const std::string& nuevaDireccion) { direccion = nuevaDireccion; }

    std::string toString() const;
};