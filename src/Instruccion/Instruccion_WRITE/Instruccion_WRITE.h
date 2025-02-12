// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_WRITE.h : Declaración de la clase Instruccion_WRITE
//        En este fichero se declara la clase Instruccion_WRITE
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código
#ifndef C_Instruccion_WRITE_H
#define C_Instruccion_WRITE_H
#include "../Instruccion.h"

/**
 * @class Clase para representar la instrucción WRITE
*/

class Instruccion_WRITE : public Instruccion {
 public:
  Instruccion_WRITE(MemoriaDatos* registros, Escritura* cinta_escritura, string& operando);
  int ejecutar() override;
 private:
  Escritura* cinta_escritura_;
};

#endif