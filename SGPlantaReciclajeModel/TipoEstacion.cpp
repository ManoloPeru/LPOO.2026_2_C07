#include "TipoEstacion.h"

using namespace SGPlantaReciclajeModel;

// ============================================================
// CONSTRUCTOR VACÍO
// ============================================================
TipoEstacion::TipoEstacion() {
    this->idTipoEstacion = 0;
    this->descripcion = "Sin descripción";
}

// ============================================================
// CONSTRUCTOR CON PARÁMETROS
// ============================================================
TipoEstacion::TipoEstacion(int idTipoEstacion, String^ descripcion) {
    this->idTipoEstacion = idTipoEstacion;
    this->descripcion = descripcion;
}

// ============================================================
// GETTERS Y SETTERS
// ============================================================
int TipoEstacion::getIdTipoEstacion() {
    return idTipoEstacion;
}

void TipoEstacion::setIdTipoEstacion(int id) {
    this->idTipoEstacion = id;
}

String^ TipoEstacion::getDescripcion() {
    return descripcion;
}

void TipoEstacion::setDescripcion(String^ descripcion) {
    this->descripcion = descripcion;
}

// ============================================================
// MÉTODOS AUXILIARES
// ============================================================
String^ TipoEstacion::ToString() {
    return descripcion;
}