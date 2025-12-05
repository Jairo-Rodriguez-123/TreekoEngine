#include "UserInterface.h"
#include "Device.h"
#include "DeviceContext.h"

void UserInterface::init(void* hWnd, Device& device, DeviceContext& deviceContext) {
  // 1. Verificar contexto e inicializar Core de ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

  // Habilitar navegacion con teclado/gamepad si lo deseas
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      

  // 2. Configurar Estilo (Dark es el standard)
  ImGui::StyleColorsDark();

  // 3. Inicializar Backend de Plataforma (Win32)
  // Casteamos void* a HWND porque ImGui espera HWND
  if (!ImGui_ImplWin32_Init((HWND)hWnd)) {
    ERROR("UserInterface", "init", "Failed to initialize ImGui Win32 implementation");
    return;
  }

  // 4. Inicializar Backend de Renderizado (DX11)
  // OJO: Aqui asumo que tu clase Device tiene un metodo getDevice() que retorna ID3D11Device*
  // y DeviceContext tiene getDeviceContext() que retorna ID3D11DeviceContext*
  if (!ImGui_ImplDX11_Init(device.m_device, deviceContext.m_deviceContext)) {
    ERROR("UserInterface", "init", "Failed to initialize ImGui DX11 implementation");
    return;
  }
}

void UserInterface::update() {
  // Iniciar el frame de ImGui
  ImGui_ImplDX11_NewFrame();
  ImGui_ImplWin32_NewFrame();
  ImGui::NewFrame();

  // --- AQUI PODRIAS PONER VENTANAS GLOBALES DE DEBUG SI QUISIERAS ---
  // Ejemplo:
  // ImGui::Begin("Performance");
  // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
  // ImGui::End();
}

void UserInterface::render() {
  // Generar los datos de renderizado
  ImGui::Render();

  // Dibujar los datos usando DX11
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void UserInterface::destroy() {
  ImGui_ImplDX11_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();
}