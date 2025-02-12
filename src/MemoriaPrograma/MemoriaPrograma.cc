// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo MemoriaPrograma.cc: Implementación de MemoriaPrograma
//        En este fichero se implementa las funciones de la clase MemoriaPrograma
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"MemoriaPrograma.h"

/**
 * @brief Función para insertar una etiqueta en la memoria del programa
 * @param etiqueta Etiqueta a insertar
 * @param direccion Dirección de la instrucción
*/

void MemoriaPrograma::InsertarEtiqueta(string& etiqueta, int direccion) {
  regex patron(":");
  etiqueta = regex_replace(etiqueta, patron, " ");
  // Separo la etiqueta de la instruccion
  string instruccion = etiqueta.substr(etiqueta.find(' ') + 1);
  // Inserto la etiqueta
  etiqueta_a_dirección_.insert(make_pair(etiqueta.substr(0, etiqueta.find(' ')), direccion));
  // Inserto la instrucción
  if (instruccion == "HALT") {
    InsertarInstruccion(instruccion);
    return;
  }
  InsertarInstruccion(instruccion);
}

/**
 * @brief Función para insertar una instruccion en la memoria del programa
 * @param instruccion Instrucción a insertar
 * @param direccion Dirección de la instrucción
*/

void MemoriaPrograma::InsertarInstruccion(string& instruccion) {
  if (instruccion.find('=') != string::npos || instruccion.find('*') != string::npos) {
    regex patron("([=|*])");
    instruccion = regex_replace(instruccion, patron, " $1");
  }
  else if (instruccion.find("JUMP") != string::npos || instruccion.find("JZERO") != string::npos || instruccion.find("JGTZ") != string::npos) {
    regex patron("(JUMP|JZERO|JGTZ)");
    instruccion = regex_replace(instruccion, patron, "$1 ");
  }
  else if (instruccion == "HALT") {
    memoria_programa_.push_back(make_pair(instruccion, ""));
    return;
  }
  else {
    regex patron("([0-9]+)");
    instruccion = regex_replace(instruccion, patron, " $1");
  }
  memoria_programa_.push_back(make_pair(instruccion.substr(0, instruccion.find(' ')), instruccion.substr(instruccion.find(' ') + 1)));
}

/** MemoriaPrograma::MemoriaPrograma()
  * @brief Crea el objeto de la clase MemoriaPrograma.
  * @param nombre_fichero Nombre del fichero
  * @return objeto de la clase MemoriaPrograma
*/

MemoriaPrograma::MemoriaPrograma(const string& nombre_fichero) {
  ifstream file(nombre_fichero);
  int num_linea = 0;
  string linea;
  while (getline(file, linea)) {
    if (linea.find('#') != string::npos || linea.empty() || regex_match(linea, regex("^\\s+$"))) {
      continue;
    }
    // Eliminar espacios en blanco y saltos de linea
    linea.erase(remove_if(linea.begin(), linea.end(), ::isspace), linea.end());

    // Convertir a mayúsculas
    transform(linea.begin(), linea.end(), linea.begin(), ::toupper);

    if (linea.find(':') != string::npos) {
      InsertarEtiqueta(linea, num_linea);
    }
    else {
      InsertarInstruccion(linea);
    }
    num_linea++;
  }
}

/**
 * @brief Función para leer la instrucción en la dirección dada
 * @param direccion Dirección de la instrucción
 * @return pair<string, string> Instrucción y operando
*/

pair<string, string> MemoriaPrograma::Leer_instruccion(int direccion) {
  if (static_cast<long unsigned int>(direccion) >= memoria_programa_.size()) {
    throw out_of_range("Error: Se ha intentado leer más allá de la memoria de programa");
  }
  return memoria_programa_[direccion];
}


/**
 * @brief Función para imprimir la memoria de programa
 * @param os ostream
 * @param memoria MemoriaPrograma
 * @return ostream
*/

ostream& operator<<(ostream& os, const MemoriaPrograma& memoria) {
  os << "---Etiquetas---" << endl;
  for (auto& etiqueta : memoria.etiqueta_a_dirección_) {
    os << etiqueta.first << " "<< etiqueta.second << endl;
  }
  os << "---Instrucciones---" << endl;
  for (auto& instruccion : memoria.memoria_programa_) {
    os << instruccion.first << " " << instruccion.second << endl;
  }
  return os;
}
