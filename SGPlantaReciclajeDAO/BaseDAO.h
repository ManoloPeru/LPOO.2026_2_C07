#pragma once

namespace SGPlantaReciclajeDAO {

	using namespace System;
	using namespace System::IO;

	// ============================================================
	// CLASE: BaseDAO
	// ============================================================
	// Clase base para todos los DAO del sistema SGPlantaReciclaje.
	//
	// Su responsabilidad es centralizar la RUTA donde se almacenan
	// los archivos de datos (TXT, BIN, etc.), de modo que los DAO
	// concretos (EstacionDAO, EstadoOperativoDAO, TipoEstacionDAO,
	// etc.) no tengan que recalcularla cada uno por su cuenta.
	//
	// La ruta se calcula como:
	//   <Raíz del proyecto>\BD\TXT\
	//
	// donde <Raíz del proyecto> se obtiene subiendo desde el
	// directorio de ejecución (Application::StartupPath) hasta
	// encontrar la carpeta que contiene el archivo .sln.
	//
	// Ejemplo de ruta resultante:
	//   C:\Users\Alumno\source\repos\SGPlantaReciclaje\BD\TXT\

	public ref class BaseDAO {

		protected:
			// Ruta absoluta de la carpeta donde se almacenan los TXT.
			// Termina siempre con el separador de directorio.
			String^ rutaCarpetaTXT;

			// ------------------------------------------------------------
			// Método auxiliar protegido: obtiene la ruta absoluta de la
			// carpeta BD\TXT\ subiendo desde StartupPath hasta encontrar
			// la raíz del proyecto (donde está el .sln).
			// ------------------------------------------------------------
			String^ ObtenerRutaCarpetaTXT();

		public:
			// Constructor: calcula y almacena la ruta de la carpeta TXT.
			BaseDAO();

			// ---------- GETTERS ----------

			// getRutaCarpetaTXT: devuelve la ruta absoluta de la carpeta TXT.
			String^ getRutaCarpetaTXT();

			// ---------- MÉTODOS AUXILIARES PARA LOS DAO HIJOS ----------

			// ObtenerRutaArchivo: devuelve la ruta completa de un archivo
			// dentro de la carpeta BD\TXT\. Ejemplo:
			//   ObtenerRutaArchivo("Estaciones.txt")
			//     → "C:\...\SGPlantaReciclaje\BD\TXT\Estaciones.txt"
			String^ ObtenerRutaArchivo(String^ nombreArchivo);

			// AsegurarExistenciaCarpeta: verifica que la carpeta BD\TXT\
				// exista; si no, la crea. Útil antes de escribir un archivo.
			void AsegurarExistenciaCarpeta();
	};
}