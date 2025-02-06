// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo MemoriaDatos.h : Declaración de la clase MemoriaDatos
//        En este fichero se declara la clase MemoriaDatos
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_MemoriaDatos_H
#define C_MemoriaDatos_H
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @class Clase para representar el conjunto de registros
*/

class MemoriaDatos {
 public:
  MemoriaDatos() {}

  void SetDato(int posicion, int dato);
  int GetDato(int posicion);

  friend ostream& operator<<(ostream& os, const MemoriaDatos& memoria);

 private:
  vector<int> registros_;
};

#endif