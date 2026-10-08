#pragma once

#include "BaseDAO.h"   // ← NUEVO: incluir BaseDAO para heredar clase Base

namespace SGPlantaReciclajeDAO {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace SGPlantaReciclajeModel;

	// ============================================================
	// CLASE: TipoEstacionDAO
	// ============================================================
	// Data Access Object (DAO) para la entidad TipoEstacion.
	// HEREDA de BaseDAO para reutilizar la ruta centralizada de
	// la carpeta BD\TXT\ donde se almacenan los archivos de datos.
	//
	// Formato del archivo "TipoEstaciones.txt" (cada línea):
	//   idTipoEstacion;descripcion
	//
	// Ejemplo:
	//   1;Neumática
	//   2;Magnética
	public ref class TipoEstacionDAO : public BaseDAO {   // ← HERENCIA
		private:
			// Métodos auxiliares privados (si es necesario) pueden ir aquí.
			String^ nombreArchivo = "TipoEstaciones.txt"; // Nombre del archivo de datos

		public:
			// Constructor por defecto
			TipoEstacionDAO();

			// ---------- OPERACIONES DE LECTURA ----------

			List<TipoEstacion^>^ buscarTodosArchivo();

			TipoEstacion^ buscarxIdArchivo(int idTipoEstacion);

			TipoEstacion^ buscarxDescripcionArchivo(String^ descripcion);

			// ---------- OPERACIONES DE ESCRITURA ----------

			void registrarTipoArchivo(TipoEstacion^ tipo);

			void modificarTipoArchivo(TipoEstacion^ tipo);

			void eliminarTipoArchivo(int idTipoEstacion);

			void escribirArchivo(List<TipoEstacion^>^ listaTipos);
	};

}