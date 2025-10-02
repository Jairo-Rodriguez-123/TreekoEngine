#pragma once
#include "Prerequisites.h"

class Device;
/*
  *  @brief Forward declaration of DeviceContext class.
*/
class DeviceContext;
/*
  *  @brief Forward declaration of Texture class.
*/
class Texture;

/*
  *  @brief Encapsulates a Direct3D 11 Depth Stencil View.
*/
class
  DepthStencilView {
public:
  
  /*
    *  @brief Default constructor for DepthStencilView.
  */
  DepthStencilView() = default;

  
  /*
    *  @brief Default destructor for DepthStencilView.
  */
  ~DepthStencilView() = default;

  
  /*
    *  @brief Initializes the depth stencil view with the given device, texture, and format.
    *  @param device Reference to the device used for creation.
    *  @param depthStencil Reference to the texture to be used as depth stencil.
    *  @param format The DXGI format for the depth stencil view.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device, Texture& depthStencil, DXGI_FORMAT format);

  
  /*
    *  @brief Updates the depth stencil view. (Currently does nothing.)
  */
  void
    update() {};

  
  /*
    *  @brief Sets the depth stencil view for rendering in the given device context.
    *  @param deviceContext Reference to the device context.
  */
  void
    render(DeviceContext& deviceContext);

  
  /*
    *  @brief Releases the depth stencil view and associated resources.
  */
  void
    destroy();

public:
  
  /*
    *  @brief Pointer to the underlying ID3D11DepthStencilView.
  */
  ID3D11DepthStencilView* m_depthStencilView = nullptr;
};
