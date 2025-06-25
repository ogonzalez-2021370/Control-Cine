/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "Sala.h"

class ArraySalas {
private:
    Sala* salas;          
    int capacidad;        
    int cantidad;         

    void redimensionar(int nuevaCapacidad);

public:
    ArraySalas();

    ~ArraySalas();

    void agregar(const Sala& sala);
    Sala obtener(int indice) const;
    Sala* obtenerPuntero(int indice);
    void modificar(int indice, const Sala& nuevaSala);
    void eliminar(int indice);

    int buscarPorCodigo(int codigo) const;
    bool existeCodigo(int codigo) const;

    bool verificarSilla(int indiceSala, int fila, int columna) const;
    void ocuparSilla(int indiceSala, int fila, int columna);
    void resetearSillas(int indiceSala);

    int getCantidad() const;

    void guardarEnArchivo(const std::string& ruta);
    void cargarDesdeArchivo(const std::string& ruta);
    void limpiar();

    void ordenarPorCodigo(bool ascendente);
    void generarReporteHTML(const std::string& ruta, bool ascendente);


};