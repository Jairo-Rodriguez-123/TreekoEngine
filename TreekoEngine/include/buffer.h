#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"

/*
  *  @brief Forward declaration for Device class.
*/
class Device;
/*
  *  @brief Forward declaration for DeviceContext class.
*/
class DeviceContext;


/*
  *  @brief Encapsulates a Direct3D 11 buffer and provides methods for initialization, update, rendering, and destruction.
*/
class
  Buffer {
public:

  /*
    *  @brief Default constructor for Buffer.
  */
  Buffer() = default;

  /*
    *  @brief Default destructor for Buffer.
  */
  ~Buffer() = default;

  /*
    *  @brief Initializes the buffer using a mesh and bind flag.
    *  @param device Reference to the Device object.
    *  @param mesh Reference to the MeshComponent containing vertex/index data.
    *  @param bindFlag Flags specifying how the buffer will be bound to the pipeline.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device, const MeshComponent& mesh, unsigned int bindFlag);

  /*
    *  @brief Initializes the buffer with a specified byte width.
    *  @param device Reference to the Device object.
    *  @param ByteWidth Size of the buffer in bytes.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    init(Device& device, unsigned int ByteWidth);

  /*
    *  @brief Updates the contents of a resource.
    *  @param deviceContext Reference to the DeviceContext.
    *  @param pDstResource Pointer to the destination resource.
    *  @param DstSubresource Index of the destination subresource.
    *  @param pDstBox Optional box that defines the portion of the resource to update.
    *  @param pSrcData Pointer to the source data.
    *  @param SrcRowPitch Row pitch of the source data.
    *  @param SrcDepthPitch Depth pitch of the source data.
  */
  void
    update(DeviceContext& deviceContext,
      ID3D11Resource* pDstResource,
      unsigned int    DstSubresource,
      const D3D11_BOX* pDstBox,
      const void* pSrcData,
      unsigned int    SrcRowPitch,
      unsigned int    SrcDepthPitch);

  /*
    *  @brief Renders the buffer by binding it to the pipeline.
    *  @param deviceContext Reference to the DeviceContext.
    *  @param StartSlot Index of the first buffer to bind.
    *  @param NumBuffers Number of buffers to bind.
    *  @param setPixelShader Whether to set the pixel shader stage.
    *  @param format Format of the index buffer if used.
  */
  void
    render(DeviceContext& deviceContext,
      unsigned int   StartSlot,
      unsigned int   NumBuffers,
      bool           setPixelShader = false,
      DXGI_FORMAT    format = DXGI_FORMAT_UNKNOWN);

  /*
    *  @brief Releases the buffer and its resources.
  */
  void
    destroy();

  /*
    *  @brief Creates a Direct3D buffer with the specified description and initial data.
    *  @param device Reference to the Device object.
    *  @param desc Reference to the buffer description.
    *  @param initData Pointer to the initial data for the buffer.
    *  @return HRESULT indicating success or failure.
  */
  HRESULT
    createBuffer(Device& device,
      D3D11_BUFFER_DESC& desc,
      D3D11_SUBRESOURCE_DATA* initData);

private:

  /*
    *  @brief Pointer to the underlying ID3D11Buffer.
  */
  ID3D11Buffer* m_buffer = nullptr;

  /*
    *  @brief Stride of the buffer elements in bytes.
  */
  unsigned int m_stride = 0;
  /*
    *  @brief Offset in bytes from the start of the buffer.
  */
  unsigned int m_offset = 0;
  /*
    *  @brief Flags specifying how the buffer is bound to the pipeline.
  */
  unsigned int m_bindFlag = 0;
};
