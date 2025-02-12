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
#include "../Instruccion/Instruccion.h"
#include "../MemoriaDatos/MemoriaDatos.h"
#include "../Instruccion/Instruccion_ADD/Instruccion_ADD.h"
#include "../Instruccion/Instruccion_DIV/Instruccion_DIV.h"
#include "../Instruccion/Instruccion_JGTZ/Instruccion_JGTZ.h"
#include "../Instruccion/Instruccion_JUMP/Instruccion_JUMP.h"
#include "../Instruccion/Instruccion_JZERO/Instruccion_JZERO.h"
#include "../Instruccion/Instruccion_LOAD/Instruccion_LOAD.h"
#include "../Instruccion/Instruccion_MUL/Instruccion_MUL.h"
#include "../Instruccion/Instruccion_READ/Instruccion_READ.h"
#include "../Instruccion/Instruccion_STORE/Instruccion_STORE.h"
#include "../Instruccion/Instruccion_SUB/Instruccion_SUB.h"
#include "../Instruccion/Instruccion_WRITE/Instruccion_WRITE.h"
#include "../Instruccion/Instruccion_HALT/Instruccion_HALT.h"
#include "../Escritura/Escritura.h"
#include "../Lectura/Lectura.h"
#include <regex>
#include <utility>


using namespace std;

class MemoriaPrograma {
 public:
  MemoriaPrograma(const string& file);
  pair<string, string> Leer_instruccion(int direccion);

  map<string, int> GetEtiquetas() { return etiqueta_a_dirección_; };
  vector<Instruccion*> GetVectorInstrucciones(MemoriaDatos *registros, Lectura *cinta_lectura, Escritura *cinta_escritura);
  void CrearInstruccion(unsigned long i, std::vector<Instruccion *> &instrucciones, MemoriaDatos *registros, Lectura *cinta_lectura, Escritura *cinta_escritura);
  string ObtenerDireccionEtiqueta(const string& etiqueta);
  // Para manejar las lineas del fichero
  void InsertarEtiqueta(string& etiqueta, int direccion);
  void InsertarInstruccion(string& Instruccion);
  
  friend ostream& operator<<(ostream& os, const MemoriaPrograma& memoria);

 private:
  vector<pair<string, string>> memoria_programa_; // vector de pares de string que contiene las instrucciones y sus operandos
  map<string,int> etiqueta_a_dirección_; // relaciona las etiquetas con la dirección de la instrucción
};

#endif