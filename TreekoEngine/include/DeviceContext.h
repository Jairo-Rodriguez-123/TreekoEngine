#pragma once
#include "Prerequisites.h"

    /*
     *  @brief Encapsulates a Direct3D 11 device context and provides methods for rendering operations.
     */
class
  DeviceContext {
public:
    /*
     *  @brief Default constructor for DeviceContext.
     */
    DeviceContext() = default;
    /*
      *  @brief Default destructor for DeviceContext.
     */
    ~DeviceContext() = default;

    /*
      *  @brief Initializes the device context.
     */
    void
      init();

    /*
      *  @brief Updates the device context state.
     */
    void
      update();

    /*
      *  @brief Renders using the current device context state.
     */
    void
      render();

    /*
      *  @brief Releases resources and destroys the device context.
     */
    void
      destroy();

    /*
      *  @brief Sets the viewports for rasterization.
      *  @param NumViewports Number of viewports to set.
      *  @param pViewports Pointer to an array of D3D11_VIEWPORT structures.
     */
    void
      RSSetViewports(unsigned int NumViewports, const D3D11_VIEWPORT* pViewports);

    /*
      *  @brief Sets shader resources for the pixel shader stage.
      *  @param StartSlot Index of the first shader resource to set.
      *  @param NumViews Number of shader resources to set.
      *  @param ppShaderResourceViews Array of shader resource view pointers.
     */
    void
      PSSetShaderResources(unsigned int StartSlot,
        unsigned int NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

    /*
      *  @brief Sets the input layout for the input assembler stage.
      *  @param pInputLayout Pointer to the input layout object.
     */
    void
      IASetInputLayout(ID3D11InputLayout* pInputLayout);

    /*
      *  @brief Sets the vertex shader for the pipeline.
      *  @param pVertexShader Pointer to the vertex shader object.
      *  @param ppClassInstances Array of class instance pointers.
      *  @param NumClassInstances Number of class instances.
     */
    void
      VSSetShader(ID3D11VertexShader* pVertexShader,
        ID3D11ClassInstance* const* ppClassInstances,
        unsigned int NumClassInstances);

    /*
      *  @brief Sets the pixel shader for the pipeline.
      *  @param pPixelShader Pointer to the pixel shader object.
      *  @param ppClassInstances Array of class instance pointers.
      *  @param NumClassInstances Number of class instances.
     */
    void
      PSSetShader(ID3D11PixelShader* pPixelShader,
        ID3D11ClassInstance* const* ppClassInstances,
        unsigned int NumClassInstances);

    /*
      *  @brief Updates a subresource with new data.
      *  @param pDstResource Destination resource.
      *  @param DstSubresource Index of the destination subresource.
      *  @param pDstBox Optional box that defines the portion of the resource to update.
      *  @param pSrcData Pointer to the source data.
      *  @param SrcRowPitch Row pitch of the source data.
      *  @param SrcDepthPitch Depth pitch of the source data.
     */
    void
      UpdateSubresource(ID3D11Resource* pDstResource,
        unsigned int DstSubresource,
        const D3D11_BOX* pDstBox,
        const void* pSrcData,
        unsigned int SrcRowPitch,
        unsigned int SrcDepthPitch);

    /*
      *  @brief Sets the vertex buffers for the input assembler stage.
      *  @param StartSlot Index of the first vertex buffer to set.
      *  @param NumBuffers Number of vertex buffers to set.
      *  @param ppVertexBuffers Array of vertex buffer pointers.
      *  @param pStrides Array of stride values for each buffer.
      *  @param pOffsets Array of offset values for each buffer.
     */
    void
      IASetVertexBuffers(unsigned int StartSlot,
        unsigned int NumBuffers,
        ID3D11Buffer* const* ppVertexBuffers,
        const unsigned int* pStrides,
        const unsigned int* pOffsets);

    /*
      *  @brief Sets the index buffer for the input assembler stage.
      *  @param pIndexBuffer Pointer to the index buffer.
      *  @param Format Format of the index data.
      *  @param Offset Offset in bytes from the start of the buffer.
     */
    void
      IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
        DXGI_FORMAT Format,
        unsigned int Offset);

    /*
      *  @brief Sets sampler states for the pixel shader stage.
      *  @param StartSlot Index of the first sampler to set.
      *  @param NumSamplers Number of samplers to set.
      *  @param ppSamplers Array of sampler state pointers.
     */
    void
      PSSetSamplers(unsigned int StartSlot,
        unsigned int NumSamplers,
        ID3D11SamplerState* const* ppSamplers);

    /*
      *  @brief Sets the rasterizer state.
      *  @param pRasterizerState Pointer to the rasterizer state object.
     */
    void
      RSSetState(ID3D11RasterizerState* pRasterizerState);

    /*
      *  @brief Sets the blend state for the output merger stage.
      *  @param pBlendState Pointer to the blend state object.
      *  @param BlendFactor Array of blend factors.
      *  @param SampleMask Sample mask.
     */
    void
      OMSetBlendState(ID3D11BlendState* pBlendState,
        const float BlendFactor[4],
        unsigned int SampleMask);

    /*
      *  @brief Sets the render targets for the output merger stage.
      *  @param NumViews Number of render target views.
      *  @param ppRenderTargetViews Array of render target view pointers.
      *  @param pDepthStencilView Pointer to the depth stencil view.
     */
    void
      OMSetRenderTargets(unsigned int NumViews,
        ID3D11RenderTargetView* const* ppRenderTargetViews,
        ID3D11DepthStencilView* pDepthStencilView);

    /*
      *  @brief Sets the primitive topology for the input assembler stage.
      *  @param Topology Primitive topology type.
     */
    void
      IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

    /*
      *  @brief Clears a render target view with a specific color.
      *  @param pRenderTargetView Pointer to the render target view.
      *  @param ColorRGBA Array of four color components.
     */
    void
      ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
        const float ColorRGBA[4]);

    /*
      *  @brief Clears a depth stencil view.
      *  @param pDepthStencilView Pointer to the depth stencil view.
      *  @param ClearFlags Flags indicating which parts to clear.
      *  @param Depth Depth value to clear.
      *  @param Stencil Stencil value to clear.
     */
    void
      ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
        unsigned int ClearFlags,
        float Depth,
        UINT8 Stencil);

    /*
      *  @brief Sets constant buffers for the vertex shader stage.
      *  @param StartSlot Index of the first constant buffer to set.
      *  @param NumBuffers Number of constant buffers to set.
      *  @param ppConstantBuffers Array of constant buffer pointers.
     */
    void
      VSSetConstantBuffers(unsigned int StartSlot,
        unsigned int NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    /*
      *  @brief Sets constant buffers for the pixel shader stage.
      *  @param StartSlot Index of the first constant buffer to set.
      *  @param NumBuffers Number of constant buffers to set.
      *  @param ppConstantBuffers Array of constant buffer pointers.
     */
    void
      PSSetConstantBuffers(unsigned int StartSlot,
        unsigned int NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    /*
      *  @brief Draws indexed, non-instanced primitives.
      *  @param IndexCount Number of indices to draw.
      *  @param StartIndexLocation Index of the first index to draw.
      *  @param BaseVertexLocation Value added to each index before reading a vertex from the vertex buffer.
     */
    void
      DrawIndexed(unsigned int IndexCount,
        unsigned int StartIndexLocation,
        int BaseVertexLocation);
public:
    /*
      *  @brief Pointer to the underlying ID3D11DeviceContext.
     */
        ID3D11DeviceContext* m_deviceContext = nullptr;

};
