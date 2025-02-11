// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_JZERO.h : Declaración de la clase Instruccion_JZERO
//        En este fichero se declara la clase Instruccion_JZERO
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_JZERO_H
#define C_Instruccion_JZERO_H
#include "Instruccion.h"

/**
 * @class Clase para representar la instrucción JZERO
*/

class Instruccion_JZERO : public Instruccion {
  public:
   Instruccion_JZERO(MemoriaDatos* registros, map<string, int> etiquetas) : Instruccion(registros) { instruccion_ = "JZERO"; etiquetas_ = etiquetas;}
 
   int ejecutar(const string& operando) override;
 
  private:
   map<string, int> etiquetas_;
 };

#endif