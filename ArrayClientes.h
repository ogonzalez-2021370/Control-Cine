/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once
#include "Cliente.h"

class ArrayClientes {
private:
    Cliente** clientes;  
    int capacidad;       
    int cantidad;       

    void redimensionar(int nuevaCapacidad);

public:
    // Constructor
    ArrayClientes();

    // Destructor
    ~ArrayClientes();

    // Métodos CRUD
    void agregar(Cliente* cliente);
    void eliminar(int indice);
    void modificar(int indice, Cliente* nuevoCliente);

    // Métodos de acceso
    Cliente* obtener(int indice) const;
    int getCantidad() const;
    int buscarPorCodigo(int codigo) const;
    bool existeCodigo(int codigo) const;
    int buscarPorIdentificacion(const std::string& identificacion) const;

    void guardarEnArchivo(const std::string& ruta);
    void cargarDesdeArchivo(const std::string& ruta);

    void generarReporteHTML(const std::string& ruta, bool ascendente);
    void ordenarPorCodigo(bool ascendente);

};