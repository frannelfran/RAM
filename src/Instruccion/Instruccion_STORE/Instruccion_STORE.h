// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_STORE.h : Declaración de la clase Instruccion_STORE
//        En este fichero se declara la clase Instruccion_STORE
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_STORE_H
#define C_Instruccion_STORE_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción STORE
*/

class Instruccion_STORE : public Instruccion {
 public:
  Instruccion_STORE(MemoriaDatos* registros, string& operando);
  int ejecutar() override;
};

#endif