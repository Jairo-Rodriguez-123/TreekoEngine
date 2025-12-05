#pragma once
#include "Prerequisites.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <imgui_internal.h>

/**
 * @class UserInterface
 * @brief Gesti�n de la interfaz gr�fica basada en ImGui.
 *
 * Esta clase encapsula la inicializaci�n, actualizaci�n, renderizado y destrucci�n
 * de una interfaz de usuario utilizando la biblioteca ImGui junto con DirectX 11.
 */
class
  UserInterface {
public:
  /**
   * @brief Constructor de la clase UserInterface.
   */
  UserInterface();

  /**
   * @brief Destructor de la clase UserInterface.
   */
  ~UserInterface();

  /**
   * @brief Inicializa ImGui y su conexi�n con Win32 y DirectX 11.
   * @param window Puntero a la ventana nativa (HWND).
   * @param device Dispositivo DirectX 11.
   * @param deviceContext Contexto del dispositivo DirectX 11.
   */
  void
    init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);

  /**
   * @brief Actualiza el estado interno de la interfaz (frame ImGui).
   */
  void
    update();

  /**
   * @brief Renderiza todos los elementos de la interfaz construidos en el frame.
   */
  void
    render();

  /**
   * @brief Libera y desmonta todos los recursos asociados a ImGui.
   */
  void
    destroy();

  /**
   * @brief Control personalizado para manejar un vector 3 dentro de la UI.
   * @param label Etiqueta visible del control.
   * @param values Puntero a un arreglo de 3 floats (x, y, z).
   * @param resetValues Valor al que se restablecen los componentes.
   * @param columnWidth Ancho de la columna de la etiqueta.
   */
  void
    vec3Control(std::string label,
      float* values,
      float resetValues = 0.0f,
      float columnWidth = 100.0f);

private:


};#pragma once
