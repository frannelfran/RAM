// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo MemoriaPrograma.h : Declaración de la clase MemoriaPrograma
//        En este fichero se declara la clase MemoriaPrograma
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_MemoriaPrograma_H
#define C_MemoriaPrograma_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>    // Para std::istringstream
#include <algorithm>  // Para std::transform
#include <cctype>     // Para ::toupper

using namespace std;

vector<string> fichero_to_line(string fichero);

class MemoriaPrograma {
 public:
  MemoriaPrograma(vector<string> lineas_de_codigo);
  pair<string, string> Leer_instruccion(int direccion);
  map<string, int> GetEtiquetas() { return etiqueta_a_dirección_; };
  friend ostream& operator<<(ostream& os, const MemoriaPrograma& memoria);

 private:
  vector<pair<string,string>> memoria_programa_; // vector de pares de string que contiene las instrucciones y sus operandos
  map<string,int> etiqueta_a_dirección_; // relaciona las etiquetas con la dirección de la instrucción
};

#endif