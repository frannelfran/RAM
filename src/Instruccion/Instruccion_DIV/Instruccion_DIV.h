// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_DIV.h : Declaración de la clase Instruccion_DIV
//        En este fichero se declara la clase Instruccion_DIV
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_DIV_H
#define C_Instruccion_DIV_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción DIV
*/

class Instruccion_DIV : public Instruccion {
  public:
   Instruccion_DIV(MemoriaDatos* registros);
 
   int ejecutar(const string& operando) override;
 };

#endif