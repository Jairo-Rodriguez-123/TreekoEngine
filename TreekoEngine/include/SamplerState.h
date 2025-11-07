#pragma once
#include "Prerequisites.h"

/*
  *  @brief Represents a Direct3D 11 device.
*/
class Device;
/*
  *  @brief Encapsulates a Direct3D 11 device context.
*/
class DeviceContext;


/*
  *  @brief Manages a Direct3D 11 sampler state.
*/
class
  SamplerState {
public:
  
  /*
    *  @brief Default constructor for SamplerState.
  */
  SamplerState() = default;

  
  /*
    *  @brief Default destructor for SamplerState.
  */
  ~SamplerState() = default;

  
  /*
    *  @brief Initializes the sampler state using the provided device.
    *  @param device Reference to the device used for initialization.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device);

  
  /*
    *  @brief Updates the sampler state.
  */
  void
    update();

  
  /*
    *  @brief Sets the sampler state to the pixel shader stage.
    *  @param deviceContext Reference to the device context.
    *  @param StartSlot Index of the first sampler to set.
    *  @param NumSamplers Number of samplers to set.
  */
  void
    render(DeviceContext& deviceContext,
      unsigned int StartSlot,
      unsigned int NumSamplers);

  
  /*
    *  @brief Releases the sampler state resources.
  */
  void
    destroy();

public:
  /*
    *  @brief Pointer to the underlying ID3D11SamplerState.
  */
  ID3D11SamplerState* m_sampler = nullptr;
};
