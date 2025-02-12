// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es, Franco Alla
// Fecha: 02/04/25
// Archivo Instruccion.h : Declaración de la clase Instruccion
//        En este fichero se declara la clase Instruccion
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_Instruccion_H
#define C_Instruccion_H
#include <string>
#include "../Escritura/Escritura.h"
#include "../Lectura/Lectura.h"
#include "../MemoriaDatos/MemoriaDatos.h"
#include <map>

using namespace std;

/**
 * @class Clase para representar una instrucción
*/

class Instruccion {
 public:
  Instruccion(MemoriaDatos* registros, string& operando) : operando_(operando), registros_(registros) {}

  // Método para ejecutar la instrucción
  virtual int ejecutar() = 0;

  // idea: podemos hacer una clase 
  int Inmediato(const string& operando);
  int DireccionamientoDirecto(const string& operando);
  int DireccionamientoIndirecto(const string& operando);

  // Getters
  inline string GetNombre() { return instruccion_; } // Obtener el nombre de la instrucción

 protected:
  string instruccion_;
  string operando_;
  MemoriaDatos* registros_; // Conjunto de registros
};


#endif