#pragma once

namespace SGPlantaReciclajeView {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace SGPlantaReciclajeController;
    using namespace SGPlantaReciclajeModel;

    // ============================================================
    // CLASE: ComboHelper
    // ============================================================
    // Clase auxiliar (Helper) que centraliza el llenado de los
    // ComboBox de Tipo de Estación y Estado Operativo.
    //
    // Evita duplicar la lógica en múltiples formularios y permite
    // que, si mañana se agrega un nuevo formulario con los mismos
    // ComboBox, solo se invoque a este Helper.
    public ref class ComboHelper {

    public:
        // ------------------------------------------------------------
        // LlenarComboTipo: puebla un ComboBox con los tipos de estación
        // obtenidos desde el TipoEstacionController.
        //
        // Parámetros:
        //   cmbTipo         → ComboBox a poblar.
        //   idSeleccionado  → ID del tipo a preseleccionar (0 = ninguno).
        //                     Útil para el formulario de edición.
        // ------------------------------------------------------------
        static void LlenarComboTipo(ComboBox^ cmbTipo, int idSeleccionado);

        // ------------------------------------------------------------
        // LlenarComboEstado: puebla un ComboBox con los estados
        // operativos obtenidos desde el EstadoOperativoController.
        //
        // Parámetros:
        //   cmbEstado       → ComboBox a poblar.
        //   idSeleccionado  → ID del estado a preseleccionar (0 = ninguno).
        // ------------------------------------------------------------
        static void LlenarComboEstado(ComboBox^ cmbEstado, int idSeleccionado);

        // ------------------------------------------------------------
        // ObtenerIdSeleccionado: devuelve el ID (Key) seleccionado
        // en un ComboBox poblado con KeyValuePair<String^, String^>.
        // Devuelve -1 si no hay selección.
        // ------------------------------------------------------------
        static int ObtenerIdSeleccionado(ComboBox^ cmb);

        // ------------------------------------------------------------
        // SekeccionarPorId: recorre los ítems del ComboBox y selecciona aquel cuyo Key
        // coincida con el idSeleccionado. Si idSeleccionado <= 0, no
        // selecciona nada (SelectedIndex = -1).
        // ------------------------------------------------------------
        static void SeleccionarPorId(ComboBox^ cmb, int idSeleccionado);
    };

}