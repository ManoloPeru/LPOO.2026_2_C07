#include "BrazoNeumaticoClasificador.h"

using namespace SGPlantaReciclajeModel; 


BrazoNeumaticoClasificador::BrazoNeumaticoClasificador() : UnidadClasificadora() {
    this->presionSuccionMin = 0.0;
    this->presionSuccionMax = 0.0;
    this->velocidadDesplazamiento = 0.0;
}

BrazoNeumaticoClasificador::BrazoNeumaticoClasificador(int idUnidadClasificadora, String^ fabricante, double tiempoOperacionHoras,
    double presionSuccionMin, double presionSuccionMax, double velocidadDesplazamiento)
    : UnidadClasificadora(idUnidadClasificadora, fabricante, tiempoOperacionHoras) {
    this->presionSuccionMin = presionSuccionMin;
    this->presionSuccionMax = presionSuccionMax;
    this->velocidadDesplazamiento = velocidadDesplazamiento;
}

double BrazoNeumaticoClasificador::getPresionSuccionMin() {
    return presionSuccionMin;
}

void BrazoNeumaticoClasificador::setPresionSuccionMin(double presion) {
    this->presionSuccionMin = presion;
}

double BrazoNeumaticoClasificador::getPresionSuccionMax() {
    return presionSuccionMax;
}

void BrazoNeumaticoClasificador::setPresionSuccionMax(double presion) {
    this->presionSuccionMax = presion;
}

double BrazoNeumaticoClasificador::getVelocidadDesplazamiento() {
    return velocidadDesplazamiento;
}

void BrazoNeumaticoClasificador::setVelocidadDesplazamiento(double velocidad) {
    this->velocidadDesplazamiento = velocidad;
}

void BrazoNeumaticoClasificador::ajustarPresionSuccion(double presion) {
    if (presion >= presionSuccionMin && presion <= presionSuccionMax) {
        // Presión ajustada dentro del rango permitido
    }
}

void BrazoNeumaticoClasificador::moverBrazo(double velocidad) {
    this->velocidadDesplazamiento = velocidad;
}

void BrazoNeumaticoClasificador::succionarPolimero() {
    // Ejecuta maniobra de succión de polímeros
}

String^ BrazoNeumaticoClasificador::leerTelemetria() {
    return "Telemetria Brazo Neumatico - Temp: 25°C, Vibracion: 50 Hz";
}

List<String^>^ BrazoNeumaticoClasificador::verificarAlertas() {
    List<String^>^ alertas = gcnew List<String^>();
    return alertas;
}
