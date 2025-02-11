// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_READ.h : Declaración de la clase Instruccion_READ
//        En este fichero se declara la clase Instruccion_READ
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_READ_H
#define C_Instruccion_READ_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción READ
*/

class Instruccion_READ : public Instruccion {
  public:
   Instruccion_READ(MemoriaDatos* registros, Lectura* cinta_lectura);
 
   int ejecutar(const string& operando) override;
 
  private:
   Lectura* cinta_lectura_;
 };

#endif