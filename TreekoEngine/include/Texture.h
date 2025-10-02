#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/*
  *  @brief Represents a texture resource and its associated views.
*/
class
  Texture {
public:
  
  /*
    *  @brief Default constructor for Texture.
  */
  Texture() = default;

  
  /*
    *  @brief Default destructor for Texture.
  */
  ~Texture() = default;

  
  /*
    *  @brief Initializes the texture from a file.
    *  @param device Reference to the device used for resource creation.
    *  @param textureName Name of the texture file.
    *  @param extensionType Type of the file extension.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device,
      const std::string& textureName,
      ExtensionType extensionType);

  
  /*
    *  @brief Initializes the texture with specified dimensions and format.
    *  @param device Reference to the device used for resource creation.
    *  @param width Width of the texture.
    *  @param height Height of the texture.
    *  @param Format Format of the texture.
    *  @param BindFlags Bind flags for the texture.
    *  @param sampleCount Number of samples for multisampling.
    *  @param qualityLevels Quality levels for multisampling.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device,
      unsigned int width,
      unsigned int height,
      DXGI_FORMAT Format,
      unsigned int BindFlags,
      unsigned int sampleCount = 1,
      unsigned int qualityLevels = 0);

  
  /*
    *  @brief Initializes the texture from another texture with a specific format.
    *  @param device Reference to the device used for resource creation.
    *  @param textureRef Reference to the source texture.
    *  @param format Format for the new texture.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device, Texture& textureRef, DXGI_FORMAT format);

  
  /*
    *  @brief Updates the texture resource.
  */
  void
    update();

  
  /*
    *  @brief Renders the texture using the provided device context.
    *  @param deviceContext Reference to the device context.
    *  @param StartSlot The starting slot for the shader resource view.
    *  @param NumViews Number of views to set.
  */
  void
    render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int NumViews);

  
  /*
    *  @brief Releases the texture and associated resources.
  */
  void
    destroy();

public:
 
  /*
    *  @brief Pointer to the underlying ID3D11Texture2D resource.
  */
  ID3D11Texture2D* m_texture = nullptr;

  
  /*
    *  @brief Pointer to the shader resource view created from an image.
  */
  ID3D11ShaderResourceView* m_textureFromImg = nullptr;

  
  /*
    *  @brief Name of the texture resource.
  */
  std::string m_textureName;
};
