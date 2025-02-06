// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo UnidadDeControl.h : Declaración de la clase UnidadDeControl
//        En este fichero se declara la clase UnidadDeControl
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_UnidadDeControl_H
#define C_UnidadDeControl_H
#include <vector>
#include "../Instruccion/Instruccion.h"
#include "../MemoriaPrograma/MemoriaPrograma.h"

using namespace std;

class UnidadDeControl {
 public:

  // Constructor por defecto
  UnidadDeControl() {}
  
  void Inicializar(MemoriaDatos* registros, MemoriaPrograma* programa, Lectura* cinta_lectura, Escritura* cinta_escritura); // Inicializa la unidad de control

  // Método para ejecutar la instrucción
  int EjecutarInstruccion(const string& instruccion, const string& operando);
  void EjecutarPrograma(); // Ejecuta el programa

  friend ostream& operator<<(ostream& os, const UnidadDeControl& UDC);

 private:
  vector<Instruccion*> instrucciones_;
  MemoriaDatos* registros_;
  MemoriaPrograma* programa_;
  Lectura* cinta_lectura_;
  Escritura* cinta_escritura_;
  int PC_;
};

#endif