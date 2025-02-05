// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es, Franco Alla
// Fecha: 02/04/25
// Archivo Instruccion.h : Declaración de la clase Instruccion
//        En este fichero se declara la clase Instruccion
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código
#ifndef C_Instruccion_H
#define C_Instruccion_H
#include <string>
#include "../Escritura/Escritura.h"
#include "../Lectura/Lectura.h"
#include "../MemoriaDatos/MemoriaDatos.h"
#include <map>

using namespace std;

/**
 * @class Clase para representar una instrucción
*/

class Instruccion {
 public:
  Instruccion(MemoriaDatos* registros) : registros_(registros) {}

  // Método para ejecutar la instrucción
  virtual void ejecutar(const string& operando) = 0;

  // Getters 
  inline string GetNombre() { return instruccion_; } // Obtener el nombre de la instrucción

 protected:
  string instruccion_;
  MemoriaDatos* registros_; // Conjunto de registros
  Escritura* cinta_escritura_; // Cinta de escritura
  Lectura* cinta_lectura_; // Cinta de lectura

};

/**
 * @class Clase para representar la instrucción LOAD
*/

class Instruccion_LOAD : public Instruccion {
 public:
  Instruccion_LOAD(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "LOAD"; }

  void ejecutar(const string& operando) override;
};

/**
 * @class Clase para representar la instrucción STORE
*/

class Instruccion_STORE : public Instruccion {
 public:
  Instruccion_STORE(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "STORE"; }

  void ejecutar(const string& operando) override;
};

/**
 * @class Clase para representar la instrucción ADD
*/

class Instruccion_ADD : public Instruccion {
 public:
  Instruccion_ADD(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "ADD"; }

  void ejecutar(const string& operando) override;
};

/**
 * @class Clase para representar la instrucción SUB
*/

class Instruccion_SUB : public Instruccion {
 public:
  Instruccion_SUB(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "SUB"; }

  void ejecutar(const string& operando) override {};
};

/**
 * @class Clase para representar la instrucción MUL
*/

class Instruccion_MUL : public Instruccion {
 public:
  Instruccion_MUL(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "MUL"; }

  void ejecutar(const string& operando) override {};
};

/**
 * @class Clase para representar la instrucción DIV
*/

class Instruccion_DIV : public Instruccion {
 public:
  Instruccion_DIV(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "DIV"; }

  void ejecutar(const string& operando) override {};
};

/**
 * @class Clase para representar la instrucción READ
*/

class Instruccion_READ : public Instruccion {
 public:
  Instruccion_READ(MemoriaDatos* registros, Lectura* cinta_lectura): Instruccion(registros) { instruccion_ = "READ", cinta_lectura = cinta_lectura_; }

  void ejecutar(const string& operando) override {};

 private:
  Lectura* cinta_lectura_;
};

/**
 * @class Clase para representar la instrucción WRITE
*/

class Instruccion_WRITE : public Instruccion {
 public:
  Instruccion_WRITE(MemoriaDatos* registros, Escritura* cinta_escritura) : Instruccion(registros) { instruccion_ = "WRITE"; }

  void ejecutar(const Escritura& cinta_escritura, int operando) {};

 private:
  Escritura* cinta_escritura_;
};

/**
 * @class Clase para representar la instrucción JUMP
*/

class Instruccion_JUMP : public Instruccion {
 public:
  Instruccion_JUMP(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "JUMP"; }

  void ejecutar(const string& operando) override {};

 private:
  map<string, int> etiquetas_;
};

/**
 * @class Clase para representar la instrucción JZERO
*/

class Instruccion_JZERO : public Instruccion {
 public:
  Instruccion_JZERO(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "JZERO"; }

  void ejecutar(const string& operando) override {};

 private:
  map<string, int> etiquetas_;
};

/**
 * @class Clase para representar la instrucción JGTZ
*/

class Instruccion_JGTZ : public Instruccion {
 public:
  Instruccion_JGTZ(MemoriaDatos* registros) : Instruccion(registros) { instruccion_ = "JGTZ"; }

  void ejecutar(const string& operando) override {};

 private:
  map<string, int> etiquetas_;
};


#endif