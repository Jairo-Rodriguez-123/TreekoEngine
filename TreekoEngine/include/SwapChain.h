#pragma once
#include "Prerequisites.h"
    
class Device;
/*
  *  @brief Represents a Direct3D 11 device context.
*/
class DeviceContext;
/*
  *  @brief Represents a window for rendering.
*/
class Window;
/*
  *  @brief Represents a texture resource.
*/
class Texture;

/*
  *  @brief Manages the swap chain for rendering and presentation.
*/
class
  SwapChain {
public:
  
  /*
    *  @brief Default constructor for SwapChain.
  */
  SwapChain() = default;

  /*
    *  @brief Default destructor for SwapChain.
  */
  ~SwapChain() = default;

  /*
    *  @brief Initializes the swap chain.
    *  @param device Reference to the device.
    *  @param deviceContext Reference to the device context.
    *  @param backBuffer Reference to the back buffer texture.
    *  @param window The window to associate with the swap chain.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device,
      DeviceContext& deviceContext,
      Texture& backBuffer,
      Window window);

  /*
    *  @brief Updates the swap chain state.
  */
  void
    update();

  /*
    *  @brief Renders using the swap chain.
  */
  void
    render();

  /*
    *  @brief Releases swap chain resources.
  */
  void
    destroy();
  
  /*
    *  @brief Presents the rendered image to the screen.
  */
  void
    present();

public:
  
  /*
    *  @brief Pointer to the underlying IDXGISwapChain.
  */
  IDXGISwapChain* m_swapChain = nullptr;

  /*
    *  @brief The driver type used for the swap chain.
  */
  D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:
  
  /*
    *  @brief The Direct3D feature level.
  */
  D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

  /*
    *  @brief The sample count for multi-sampling.
  */
  unsigned int m_sampleCount;
  
  /*
    *  @brief The quality levels for multi-sampling.
  */
  unsigned int m_qualityLevels;
  
  /*
    *  @brief Pointer to the underlying IDXGIDevice.
  */
  IDXGIDevice* m_dxgiDevice = nullptr;

  
  /*
    *  @brief Pointer to the underlying IDXGIAdapter.
  */
  IDXGIAdapter* m_dxgiAdapter = nullptr;

  /*
    *  @brief Pointer to the underlying IDXGIFactory.
  */
  IDXGIFactory* m_dxgiFactory = nullptr;
};