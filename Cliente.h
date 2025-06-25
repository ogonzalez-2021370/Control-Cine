/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include <string>
#include <ctime>

class Cliente {
private:
    int codigo;
    std::string nombre;
    std::string apellido;
    std::string identificacion; 
    std::tm fechaNacimiento;
    std::string telefono;
    std::string correo;

public:
	// Aca tenemos nuestro constructor que inicializa todos los atributos de la clase Cliente
    Cliente(int codigo, const std::string& nombre, const std::string& apellido,
        const std::string& identificacion, const std::tm& fechaNacimiento,
        const std::string& telefono, const std::string& correo);

    // Getters
    int getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    std::string getIdentificacion() const { return identificacion; }
    std::tm getFechaNacimiento() const { return fechaNacimiento; }
    std::string getTelefono() const { return telefono; }
    std::string getCorreo() const { return correo; }

    // Setters
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setApellido(const std::string& nuevoApellido) { apellido = nuevoApellido; }
    void setIdentificacion(const std::string& nuevaIdentificacion) { identificacion = nuevaIdentificacion; }
    void setFechaNacimiento(const std::tm& nuevaFecha) { fechaNacimiento = nuevaFecha; }
    void setTelefono(const std::string& nuevoTelefono) { telefono = nuevoTelefono; }
    void setCorreo(const std::string& nuevoCorreo) { correo = nuevoCorreo; }

    std::string toString() const;
};
