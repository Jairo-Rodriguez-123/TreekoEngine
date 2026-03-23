#pragma once
#include "Prerequisites.h"

/*
  *  @brief Utility class to build D3D11 input layouts in a fluent style.
*/
class LayoutBuilder
{
public:
  /*
    *  @brief Adds a new input element to the layout (per-vertex by default).
    *  @param semantic The semantic name (e.g., "POSITION", "TEXCOORD").
    *  @param format The DXGI_FORMAT of the element.
    *  @param semanticIndex The semantic index (default 0).
    *  @param inputSlot The input slot (default 0).
    *  @param alignedByteOffset The aligned byte offset (default D3D11_APPEND_ALIGNED_ELEMENT).
    *  @param slotClass The input slot class (default D3D11_INPUT_PER_VERTEX_DATA).
    *  @param instanceStepRate The instance step rate (default 0).
    *  @return Reference to this LayoutBuilder for chaining.
  */
  LayoutBuilder& Add(
    const char* semantic,
    DXGI_FORMAT format,
    UINT semanticIndex = 0,
    UINT inputSlot = 0,
    UINT alignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT,
    D3D11_INPUT_CLASSIFICATION slotClass = D3D11_INPUT_PER_VERTEX_DATA,
    UINT instanceStepRate = 0)
  {
    D3D11_INPUT_ELEMENT_DESC d{};
    d.SemanticName = semantic;
    d.SemanticIndex = semanticIndex;
    d.Format = format;
    d.InputSlot = inputSlot;
    d.AlignedByteOffset = alignedByteOffset;
    d.InputSlotClass = slotClass;
    d.InstanceDataStepRate = instanceStepRate;
    m_elems.push_back(d);
    return *this;
  }

  /*
    *  @brief Shortcut for adding an instanced input element.
    *  @param semantic The semantic name.
    *  @param format The DXGI_FORMAT of the element.
    *  @param semanticIndex The semantic index (default 0).
    *  @param inputSlot The input slot (default 1).
    *  @param alignedByteOffset The aligned byte offset (default D3D11_APPEND_ALIGNED_ELEMENT).
    *  @param instanceStepRate The instance step rate (default 1).
    *  @return Reference to this LayoutBuilder for chaining.
  */
  LayoutBuilder& AddInstance(
    const char* semantic,
    DXGI_FORMAT format,
    UINT semanticIndex = 0,
    UINT inputSlot = 1,
    UINT alignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT,
    UINT instanceStepRate = 1)
  {
    return Add(semantic, format, semanticIndex, inputSlot, alignedByteOffset,
      D3D11_INPUT_PER_INSTANCE_DATA, instanceStepRate);
  }

  /*
    *  @brief Gets the vector of D3D11_INPUT_ELEMENT_DESC built so far.
    *  @return Const reference to the vector of input element descriptions.
  */
  const std::vector<D3D11_INPUT_ELEMENT_DESC>& Get() const { return m_elems; }

  /*
    *  @brief Gets the number of input elements in the layout.
    *  @return The count of input elements.
  */
  UINT Count() const { return (UINT)m_elems.size(); }

private:
  /*
    *  @brief Stores the input element descriptions being built.
  */
  std::vector<D3D11_INPUT_ELEMENT_DESC> m_elems;
};