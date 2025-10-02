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
  *  @brief Forward declaration of DepthStencilView class.
*/
class DepthStencilView;

/*
  *  @brief Encapsulates a Direct3D 11 Render Target View.
*/
class
  RenderTargetView {
public:
  
  /*
    *  @brief Default constructor for RenderTargetView.
  */
  RenderTargetView() = default;

  
  /*
    *  @brief Default destructor for RenderTargetView.
  */
  ~RenderTargetView() = default;

  
  /*
    *  @brief Initializes the render target view with a back buffer texture and format.
    *  @param device Reference to the device used for creation.
    *  @param backBuffer Reference to the back buffer texture.
    *  @param Format The DXGI format for the render target view.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device, Texture& backBuffer, DXGI_FORMAT Format);

  
  /*
    *  @brief Initializes the render target view with a texture, view dimension, and format.
    *  @param device Reference to the device used for creation.
    *  @param inTex Reference to the input texture.
    *  @param ViewDimension The view dimension for the render target view.
    *  @param Format The DXGI format for the render target view.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device,
      Texture& inTex,
      D3D11_RTV_DIMENSION ViewDimension,
      DXGI_FORMAT Format);

  
  /*
    *  @brief Updates the render target view. (Currently does nothing.)
  */
  void
    update();

  
  /*
    *  @brief Sets the render target and depth stencil view, and clears the render target view with the specified color.
    *  @param deviceContext Reference to the device context.
    *  @param depthStencilView Reference to the depth stencil view.
    *  @param numViews Number of render target views.
    *  @param ClearColor Array of four floats representing the clear color.
  */
  void
    render(DeviceContext& deviceContext,
      DepthStencilView& depthStencilView,
      unsigned int numViews,
      const float ClearColor[4]);

  
  /*
    *  @brief Sets the render target view for rendering.
    *  @param deviceContext Reference to the device context.
    *  @param numViews Number of render target views.
  */
  void
    render(DeviceContext& deviceContext,
      unsigned int numViews);

  
  /*
    *  @brief Releases the render target view and associated resources.
  */
  void
    destroy();
private:
  
  /*
    *  @brief Pointer to the underlying ID3D11RenderTargetView.
  */
  ID3D11RenderTargetView* m_renderTargetView = nullptr;
};
