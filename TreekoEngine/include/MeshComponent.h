#pragma once
#include "Prerequisites.h"

/*
  *  @brief Forward declaration of DeviceContext class.
*/
  class DeviceContext;

/*
  *  @brief Represents a mesh component with vertex and index data for rendering.
*/
class
  MeshComponent  {
public:
  
  /*
    *  @brief Default constructor. Initializes vertex and index counts to zero.
  */
  MeshComponent() : m_numVertex(0), m_numIndex(0) {}

  /*
    *  @brief Virtual destructor for MeshComponent.
  */
  virtual
    ~MeshComponent() = default;

  /*
    *  @brief Initializes the mesh component.
  */
  void
    init();

  /*
    *  @brief Updates the mesh component with the given delta time.
    *  @param deltaTime Time elapsed since last update.
  */
  void
    update(float deltaTime);

  /*
    *  @brief Renders the mesh using the provided device context.
    *  @param deviceContext Reference to the DeviceContext used for rendering.
  */
  void
    render(DeviceContext& deviceContext);

  /*
    *  @brief Destroys the mesh component and releases resources.
  */
  void
    destroy();

public:
  
  /*
    *  @brief Name of the mesh component.
  */
  std::string m_name;

  /*
    *  @brief Vertex data of the mesh.
  */
  std::vector<SimpleVertex> m_vertex;

  /*
    *  @brief Index data of the mesh.
  */
  std::vector<unsigned int> m_index;

  /*
    *  @brief Number of vertices in the mesh.
  */
  int m_numVertex;
  /*
    *  @brief Number of indices in the mesh.
  */
  int m_numIndex;
};
