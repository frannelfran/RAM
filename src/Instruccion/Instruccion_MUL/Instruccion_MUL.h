// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_MUL.h : Declaración de la clase Instruccion_MUL
//        En este fichero se declara la clase Instruccion_MUL
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_MULT_H
#define C_Instruccion_MULT_H
#include "Instruccion.h"

/**
 * @class Clase para representar la instrucción MUL
*/

class Instruccion_MUL : public Instruccion {
  public:
   Instruccion_MUL(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "MUL"; }
 
   int ejecutar(const string& operando) override;
 };

#endif