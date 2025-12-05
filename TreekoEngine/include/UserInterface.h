#pragma once
#include "Prerequisites.h" 
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

class Device;
class DeviceContext;

/**
 * @class UserInterface
 * @brief Encapsula el ciclo de vida de Dear ImGui (Init, NewFrame, Render, Shutdown).
 */
class UserInterface {
public:
  UserInterface() = default;
  ~UserInterface() = default;

  /**
   * @brief Inicializa el contexto de ImGui y los backends de Win32 y DX11.
   * @param hWnd Handle de la ventana (necesario para el input).
   * @param device Referencia a tu wrapper de Device.
   * @param deviceContext Referencia a tu wrapper de DeviceContext.
   */
  void init(void* hWnd, Device& device, DeviceContext& deviceContext);

  /**
   * @brief Inicia un nuevo frame de ImGui. Llamar al principio del loop, antes de la logica del juego.
   */
  void update();

  /**
   * @brief Renderiza los datos de dibujo de ImGui. Llamar despues de dibujar tu escena 3D, pero antes del SwapChain->Present.
   */
  void render();

  /**
   * @brief Limpia los recursos de ImGui.
   */
  void destroy();
};