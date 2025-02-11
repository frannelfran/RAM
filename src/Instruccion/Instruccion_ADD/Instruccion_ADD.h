// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_ADD.h : Declaración de la clase Instruccion_ADD
//        En este fichero se declara la clase Instruccion_ADD
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_ADD_H
#define C_Instruccion_ADD_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción ADD
*/

class Instruccion_ADD : public Instruccion {
  public:
   Instruccion_ADD(MemoriaDatos* registros);
 
   int ejecutar(const string& operando) override;
};

#endif