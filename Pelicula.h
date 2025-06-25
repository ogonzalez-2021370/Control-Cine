/* Autor:
     Oscar Ren� Gonzalez Rojas 9390-24-8224
 */

#pragma once

#include <string>

class Pelicula {
private:
    int codigo;         // C�digo (num�rico y �nico)
    std::string nombre; // Nombre
    std::string genero; // G�nero (Acci�n, aventuras, ciencia ficci�n, comedias, drama, documental, etc.)
    std::string clasificacion; // Clasificaci�n (14A, 18A, PG, etc.)
    std::string idioma; // Idioma (Doblada / Subtitulada)
    std::string formato; // Formato (2D, 3D, Digital)
    double precio;      // Precio funci�n (en Quetzales)
    bool estado;        // Estado (disponible / no disponible)

public:
    // Constructor por defecto
    Pelicula();

    // Constructor con par�metros
    Pelicula(int codigo, std::string nombre, std::string genero, std::string clasificacion,
        std::string idioma, std::string formato, double precio, bool estado);

    // M�todos getter
    int getCodigo() const;
    std::string getNombre() const;
    std::string getGenero() const;
    std::string getClasificacion() const;
    std::string getIdioma() const;
    std::string getFormato() const;
    double getPrecio() const;
    bool getEstado() const;

    // M�todos setter
    void setCodigo(int codigo);
    void setNombre(std::string nombre);
    void setGenero(std::string genero);
    void setClasificacion(std::string clasificacion);
    void setIdioma(std::string idioma);
    void setFormato(std::string formato);
    void setPrecio(double precio);
    void setEstado(bool estado);

    // M�todo para convertir a string para presentaci�n
    std::string toString() const;
};
