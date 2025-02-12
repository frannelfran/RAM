// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_LOAD.h : Declaración de la clase Instruccion_LOAD
//        En este fichero se declara la clase Instruccion_LOAD
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_LOAD_H
#define C_Instruccion_LOAD_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción LOAD
*/

class Instruccion_LOAD : public Instruccion {
  public:
   Instruccion_LOAD(MemoriaDatos* registros, string& operando);
 
   int ejecutar() override;
 };

#endif