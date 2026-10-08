#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    // ============================================================
    // CLASE: TipoEstacionController
    // ============================================================
    // Capa de control que gestiona las operaciones CRUD sobre los
    // tipos de estación, utilizando persistencia en archivo de texto.
    public ref class TipoEstacionController {
    private:
        // Repositorio en memoria para almacenar los tipos de estación
        List<TipoEstacion^>^ repositorio;

    public:
        // Constructor: inicializa el repositorio vacío
        TipoEstacionController();

        // ---------- OPERACIONES CRUD ----------

        // ListarTipos: devuelve la lista completa de tipos de estación.
        List<TipoEstacion^>^ ListarTipos();

        // RegistrarTipo: registra un nuevo tipo. Devuelve "" si
        // tuvo éxito o un mensaje de error en caso contrario.
        String^ RegistrarTipo(TipoEstacion^ tipo);

        // ConsultarTipo: busca un tipo por su ID.
        TipoEstacion^ ConsultarTipo(int idTipoEstacion);

        // ModificarTipo: actualiza la descripción de un tipo.
        // Devuelve "" si tuvo éxito o un mensaje de error.
        String^ ModificarTipo(int idTipoEstacion, String^ nuevaDescripcion);

        // EliminarTipo: elimina un tipo por su ID.
        // Devuelve "" si tuvo éxito o un mensaje de error.
        String^ EliminarTipo(int idTipoEstacion);
    };
}