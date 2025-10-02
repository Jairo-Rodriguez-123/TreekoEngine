#pragma once
#include "Prerequisites.h"

/*
  *  @brief Represents a Direct3D 11 device and provides methods for resource creation and management.
*/
class
  Device {
public:
  /*
    *  @brief Default constructor for Device.
  */
  Device() = default;
  /*
    *  @brief Default destructor for Device.
  */
  ~Device() = default;

  /*
    *  @brief Initializes the device.
  */
  void
    init();

  /*
    *  @brief Updates the device state.
  */
  void
    update();

  /*
    *  @brief Renders using the device.
  */
  void
    render();

  /*
    *  @brief Releases device resources.
  */
  void
    destroy();

  /*
    *  @brief Creates a render target view for a resource.
    *  @param pResource The resource to create the view for.
    *  @param pDesc The render target view description.
    *  @param ppRTView The address of a pointer to the render target view.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateRenderTargetView(ID3D11Resource* pResource,
      const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
      ID3D11RenderTargetView** ppRTView);

  /*
    *  @brief Creates a 2D texture.
    *  @param pDesc The texture description.
    *  @param pInitialData The initial data for the texture.
    *  @param ppTexture2D The address of a pointer to the texture.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
      const D3D11_SUBRESOURCE_DATA* pInitialData,
      ID3D11Texture2D** ppTexture2D);

  /*
    *  @brief Creates a depth stencil view for a resource.
    *  @param pResource The resource to create the view for.
    *  @param pDesc The depth stencil view description.
    *  @param ppDepthStencilView The address of a pointer to the depth stencil view.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateDepthStencilView(ID3D11Resource* pResource,
      const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
      ID3D11DepthStencilView** ppDepthStencilView);

  /*
    *  @brief Creates a vertex shader.
    *  @param pShaderBytecode Pointer to the compiled shader bytecode.
    *  @param BytecodeLength Length of the shader bytecode.
    *  @param pClassLinkage Class linkage interface.
    *  @param ppVertexShader The address of a pointer to the vertex shader.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateVertexShader(const void* pShaderBytecode,
      unsigned int BytecodeLength,
      ID3D11ClassLinkage* pClassLinkage,
      ID3D11VertexShader** ppVertexShader);

  /*
    *  @brief Creates an input layout object.
    *  @param pInputElementDescs Array of input element descriptions.
    *  @param NumElements Number of elements in the array.
    *  @param pShaderBytecodeWithInputSignature Shader bytecode with input signature.
    *  @param BytecodeLength Length of the shader bytecode.
    *  @param ppInputLayout The address of a pointer to the input layout.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
      unsigned int NumElements,
      const void* pShaderBytecodeWithInputSignature,
      unsigned int BytecodeLength,
      ID3D11InputLayout** ppInputLayout);

  /*
    *  @brief Creates a pixel shader.
    *  @param pShaderBytecode Pointer to the compiled shader bytecode.
    *  @param BytecodeLength Length of the shader bytecode.
    *  @param pClassLinkage Class linkage interface.
    *  @param ppPixelShader The address of a pointer to the pixel shader.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreatePixelShader(const void* pShaderBytecode,
      unsigned int BytecodeLength,
      ID3D11ClassLinkage* pClassLinkage,
      ID3D11PixelShader** ppPixelShader);

  /*
    *  @brief Creates a buffer resource.
    *  @param pDesc The buffer description.
    *  @param pInitialData The initial data for the buffer.
    *  @param ppBuffer The address of a pointer to the buffer.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
      const D3D11_SUBRESOURCE_DATA* pInitialData,
      ID3D11Buffer** ppBuffer);

  /*
    *  @brief Creates a sampler state object.
    *  @param pSamplerDesc The sampler state description.
    *  @param ppSamplerState The address of a pointer to the sampler state.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
      ID3D11SamplerState** ppSamplerState);

public:
  /*
    *  @brief Pointer to the underlying ID3D11Device.
  */
  ID3D11Device* m_device = nullptr;
};
