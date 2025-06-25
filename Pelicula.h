/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once

#include <string>

class Pelicula {
private:
    int codigo;         // Código (numérico y único)
    std::string nombre; // Nombre
    std::string genero; // Género (Acción, aventuras, ciencia ficción, comedias, drama, documental, etc.)
    std::string clasificacion; // Clasificación (14A, 18A, PG, etc.)
    std::string idioma; // Idioma (Doblada / Subtitulada)
    std::string formato; // Formato (2D, 3D, Digital)
    double precio;      // Precio función (en Quetzales)
    bool estado;        // Estado (disponible / no disponible)

public:
    // Constructor por defecto
    Pelicula();

    // Constructor con parámetros
    Pelicula(int codigo, std::string nombre, std::string genero, std::string clasificacion,
        std::string idioma, std::string formato, double precio, bool estado);

    // Métodos getter
    int getCodigo() const;
    std::string getNombre() const;
    std::string getGenero() const;
    std::string getClasificacion() const;
    std::string getIdioma() const;
    std::string getFormato() const;
    double getPrecio() const;
    bool getEstado() const;

    // Métodos setter
    void setCodigo(int codigo);
    void setNombre(std::string nombre);
    void setGenero(std::string genero);
    void setClasificacion(std::string clasificacion);
    void setIdioma(std::string idioma);
    void setFormato(std::string formato);
    void setPrecio(double precio);
    void setEstado(bool estado);

    // Método para convertir a string para presentación
    std::string toString() const;
};
