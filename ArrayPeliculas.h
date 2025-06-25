/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once

#include "Pelicula.h"

class ArrayPeliculas {
private:
	Pelicula* peliculas;  // Este es nuestro Arreglo dinamico de Peliculas
	int capacidad;        // Capacidad actual del arreglo
	int cantidad;        // Cantidad actual de elementos    

   
    void redimensionar(int nuevaCapacidad);

public:
    // Aca tenemos nuestro Constructor
    ArrayPeliculas();

    // Aca esta nuestro Destructor para liberar memoria
    ~ArrayPeliculas();

    // Aca esta nuestro metodo para agregar una pelicula
    void agregar(const Pelicula& pelicula);

    // Aca esta nuestro metodo para obtener una pelicula por indice
    Pelicula obtener(int indice) const;

    // Aca esta el metodo para obtener un puntero a una pelicula por indice
    Pelicula* obtenerPuntero(int indice);
	

    // Aca esta el meotodo para modificar una película en un indice especifico
    void modificar(int indice, const Pelicula& nuevaPelicula);

    // Aca tenemos el metodo para eliminar una pelicula por indice
    void eliminar(int indice);

    // Aca esta el metodo para buscar una pelicula por codigo
    int buscarPorCodigo(int codigo) const;

    // Aca esta el metodo para obtener la cantidad de peliculas
    int getCantidad() const;

    // Aca esta el metodo para verificar si existe una pelicula con un codigo especifico
    bool existeCodigo(int codigo) const;

    void guardarEnArchivo(const std::string& ruta);
    void cargarDesdeArchivo(const std::string& ruta);

    void limpiar();

    void ordenarPorCodigo(bool ascendente = true);
    void generarReporteHTML(const std::string& ruta, bool ascendente = true);
};