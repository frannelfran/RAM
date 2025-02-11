// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_JGTZ.h : Declaración de la clase Instruccion_JGTZ
//        En este fichero se declara la clase Instruccion_JGTZ
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_JGTZ_H
#define C_Instruccion_JGTZ_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción JGTZ
*/

class Instruccion_JGTZ : public Instruccion {
 public:
  Instruccion_JGTZ(MemoriaDatos* registros, map<string, int> etiquetas);
 
  int ejecutar(const string& operando) override;
 
 private:
  map<string, int> etiquetas_;
};

#endif