#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/*
  *  @brief Encapsulates a Direct3D 11 input layout object for vertex input configuration.
*/
class
  InputLayout {
public:
  
  /*
    *  @brief Default constructor for InputLayout.
  */
  InputLayout() = default;

  /*
    *  @brief Default destructor for InputLayout.
  */
  ~InputLayout() = default;

  /*
    *  @brief Initializes the input layout with the given device, input element descriptions, and vertex shader data.
    *  @param device Reference to the Device object.
    *  @param Layout Vector of input element descriptions.
    *  @param VertexShaderData Pointer to the compiled vertex shader data.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device,
      std::vector<D3D11_INPUT_ELEMENT_DESC>& Layout,
      ID3DBlob* VertexShaderData);

  /*
    *  @brief Updates the input layout state if necessary.
  */
  void
    update();

  /*
    *  @brief Sets the input layout in the device context for rendering.
    *  @param deviceContext Reference to the DeviceContext object.
  */
  void
    render(DeviceContext& deviceContext);

  /*
    *  @brief Releases the input layout resources.
  */
  void
    destroy();

public:

  /*
    *  @brief Pointer to the underlying ID3D11InputLayout object.
  */
  ID3D11InputLayout* m_inputLayout = nullptr;
};