/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include <string>

class Sala {
private:
    int codigo;                 
    std::string nombre;        
    int capacidad;              // La capacidad debe ser de 40 o 56 sillas
    std::string ubicacion;      
    std::string nombreEncargado;
    std::string telefonoEncargado; 
    bool** sillas;              

public:
    // Constructores
    Sala();
    Sala(int codigo, std::string nombre, int capacidad, std::string ubicacion,
        std::string nombreEncargado, std::string telefonoEncargado);

    // Aca esta el destructor para liberar memoria de la matriz
    ~Sala();

    //Constructor de copia profundo y operador de asignación en Sala
    Sala(const Sala& otra);
    Sala& operator=(const Sala& otra);


    // Getters
    int getCodigo() const;
    std::string getNombre() const;
    int getCapacidad() const;
    std::string getUbicacion() const;
    std::string getNombreEncargado() const;
    std::string getTelefonoEncargado() const;
    bool** getSillas() const;

    // Setters
    void setCodigo(int codigo);
    void setNombre(std::string nombre);
    void setCapacidad(int capacidad);
    void setUbicacion(std::string ubicacion);
    void setNombreEncargado(std::string nombreEncargado);
    void setTelefonoEncargado(std::string telefonoEncargado);

    // Aca estan los metodos para la gestion de las sillas
    void inicializarSillas();   // Aca inicializamos la matriz de sillas
    void liberarSillas();       // Aca liberamos memoria de la matriz
    void resetearSillas();      // Aca colocamos todas las sillas como desocupadas
    bool verificarSilla(int fila, int columna) const; // Aca verficamos si una silla esta ocupada
    void ocuparSilla(int fila, int columna); // Aca marcamos una silla como ocupada

    std::string toString() const;
};