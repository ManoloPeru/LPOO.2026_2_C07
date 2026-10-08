#include "EstadoOperativoController.h"

namespace SGPlantaReciclajeController {

    // ============================================================
    // CONSTRUCTOR
    // ============================================================
    EstadoOperativoController::EstadoOperativoController() {
        repositorio = gcnew List<EstadoOperativo^>();
    }

    // ============================================================
    // OPERACIONES CRUD
    // ============================================================

    List<EstadoOperativo^>^ EstadoOperativoController::ListarEstados() {
        EstadoOperativoDAO^ dao = gcnew EstadoOperativoDAO();
        return dao->buscarTodosArchivo();
    }

    String^ EstadoOperativoController::RegistrarEstado(EstadoOperativo^ estado) {
        EstadoOperativoDAO^ dao = gcnew EstadoOperativoDAO();

        if (estado == nullptr)
            return "Estado operativo nulo.";

        if (dao->buscarxIdArchivo(estado->getIdEstadoOperativo()) != nullptr)
            return "Ya existe un estado operativo con el ID especificado.";

        if (dao->buscarxDescripcionArchivo(estado->getDescripcion()) != nullptr)
            return "Ya existe un estado operativo con la misma descripción.";

        dao->registrarEstadoArchivo(estado);
        return "";
    }

    EstadoOperativo^ EstadoOperativoController::ConsultarEstado(int idEstadoOperativo) {
        EstadoOperativoDAO^ dao = gcnew EstadoOperativoDAO();
        return dao->buscarxIdArchivo(idEstadoOperativo);
    }

    String^ EstadoOperativoController::ModificarEstado(int idEstadoOperativo, String^ nuevaDescripcion) {
        EstadoOperativoDAO^ dao = gcnew EstadoOperativoDAO();

        EstadoOperativo^ estado = dao->buscarxIdArchivo(idEstadoOperativo);
        if (estado == nullptr)
            return "Estado operativo no encontrado.";

        if (String::IsNullOrWhiteSpace(nuevaDescripcion))
            return "La descripción no puede estar vacía.";

        estado->setDescripcion(nuevaDescripcion);
        dao->modificarEstadoArchivo(estado);
        return "";
    }

    String^ EstadoOperativoController::EliminarEstado(int idEstadoOperativo) {
        EstadoOperativoDAO^ dao = gcnew EstadoOperativoDAO();

        if (dao->buscarxIdArchivo(idEstadoOperativo) == nullptr)
            return "Estado operativo no encontrado.";

        dao->eliminarEstadoArchivo(idEstadoOperativo);
        return "";
    }
}