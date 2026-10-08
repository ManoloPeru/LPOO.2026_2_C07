#include "TipoEstacionController.h"

namespace SGPlantaReciclajeController {

    // ============================================================
    // CONSTRUCTOR
    // ============================================================
    TipoEstacionController::TipoEstacionController() {
        repositorio = gcnew List<TipoEstacion^>();
    }

    // ============================================================
    // OPERACIONES CRUD
    // ============================================================

    List<TipoEstacion^>^ TipoEstacionController::ListarTipos() {
        TipoEstacionDAO^ dao = gcnew TipoEstacionDAO();
        return dao->buscarTodosArchivo();
    }

    String^ TipoEstacionController::RegistrarTipo(TipoEstacion^ tipo) {
        TipoEstacionDAO^ dao = gcnew TipoEstacionDAO();

        if (tipo == nullptr)
            return "Tipo de estación nulo.";

        if (dao->buscarxIdArchivo(tipo->getIdTipoEstacion()) != nullptr)
            return "Ya existe un tipo de estación con el ID especificado.";

        if (dao->buscarxDescripcionArchivo(tipo->getDescripcion()) != nullptr)
            return "Ya existe un tipo de estación con la misma descripción.";

        dao->registrarTipoArchivo(tipo);
        return "";
    }

    TipoEstacion^ TipoEstacionController::ConsultarTipo(int idTipoEstacion) {
        TipoEstacionDAO^ dao = gcnew TipoEstacionDAO();
        return dao->buscarxIdArchivo(idTipoEstacion);
    }

    String^ TipoEstacionController::ModificarTipo(int idTipoEstacion, String^ nuevaDescripcion) {
        TipoEstacionDAO^ dao = gcnew TipoEstacionDAO();

        TipoEstacion^ tipo = dao->buscarxIdArchivo(idTipoEstacion);
        if (tipo == nullptr)
            return "Tipo de estación no encontrado.";

        if (String::IsNullOrWhiteSpace(nuevaDescripcion))
            return "La descripción no puede estar vacía.";

        tipo->setDescripcion(nuevaDescripcion);
        dao->modificarTipoArchivo(tipo);
        return "";
    }

    String^ TipoEstacionController::EliminarTipo(int idTipoEstacion) {
        TipoEstacionDAO^ dao = gcnew TipoEstacionDAO();

        if (dao->buscarxIdArchivo(idTipoEstacion) == nullptr)
            return "Tipo de estación no encontrado.";

        dao->eliminarTipoArchivo(idTipoEstacion);
        return "";
    }
}