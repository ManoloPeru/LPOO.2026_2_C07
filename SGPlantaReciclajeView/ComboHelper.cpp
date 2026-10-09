#include "ComboHelper.h"

namespace SGPlantaReciclajeView {

    // ============================================================
    // LlenarComboTipo
    // ============================================================
    void ComboHelper::LlenarComboTipo(ComboBox^ cmbTipo, int idSeleccionado) {
        // 1. Obtener la lista de tipos desde el Controller
        TipoEstacionController^ tipoController = gcnew TipoEstacionController();
        List<TipoEstacion^>^ listaTipos = tipoController->ListarTipos();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbTipo->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (TipoEstacion ^ tipo in listaTipos) {
            // KeyValuePair es un tipo valor (value, key)
            KeyValuePair<String^, String^> option(tipo->getIdTipoEstacion().ToString(), tipo->getDescripcion());
            // Agregamos a la lista.
            items->Add(option);
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbTipo->DataSource = items;
        cmbTipo->DisplayMember = "Value";  // Muestra la descripción
        cmbTipo->ValueMember = "Key";      // Mantiene el ID como valor

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbTipo, idSeleccionado);
    }

    // ============================================================
    // LlenarComboEstado
    // ============================================================
    void ComboHelper::LlenarComboEstado(ComboBox^ cmbEstado, int idSeleccionado) {
        // 1. Obtener la lista de estados desde el Controller
        EstadoOperativoController^ estadoController = gcnew EstadoOperativoController();
        List<EstadoOperativo^>^ listaEstados = estadoController->ListarEstados();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbEstado->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (EstadoOperativo ^ estado in listaEstados) {
            // Agregamo a la lista el KeyValuePair en una sola linea
            items->Add(KeyValuePair<String^, String^>(estado->getIdEstadoOperativo().ToString(),estado->getDescripcion()));
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbEstado->DataSource = items;
        cmbEstado->DisplayMember = "Value";
        cmbEstado->ValueMember = "Key";

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbEstado, idSeleccionado);
    }

    // ============================================================
    // ObtenerIdSeleccionado
    // ============================================================
    int ComboHelper::ObtenerIdSeleccionado(ComboBox^ cmb) {
        if (cmb->SelectedIndex == -1 || cmb->SelectedItem == nullptr) {
            return -1;
        }
        KeyValuePair<String^, String^> item = safe_cast<KeyValuePair<String^, String^>>(cmb->SelectedItem);
        return Convert::ToInt32(item.Key);
    }

    // ============================================================
    // Método privado: SeleccionarPorId
    // ============================================================
    void ComboHelper::SeleccionarPorId(ComboBox^ cmb, int idSeleccionado) {
        if (idSeleccionado <= 0) {
            cmb->SelectedIndex = -1;
            return;
        }

        for (int i = 0; i < cmb->Items->Count; i++) {
            KeyValuePair<String^, String^> item = safe_cast<KeyValuePair<String^, String^>>(cmb->Items[i]);
            if (Convert::ToInt32(item.Key) == idSeleccionado) {
                cmb->SelectedIndex = i; //Retorna la posición en donde esta ubicado el elemento, dentro del Combo
                return;
            }
        }
        // Si no se encontró, no seleccionar nada
        cmb->SelectedIndex = -1;
    }

}