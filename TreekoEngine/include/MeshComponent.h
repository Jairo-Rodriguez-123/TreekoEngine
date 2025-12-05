#pragma once
#include "Prerequisites.h"
#include "ECS\Component.h"

class DeviceContext;

/// <summary>
/// Componente ECS que almacena la informaci�n de geometr�a (malla) de un actor.
/// Contiene v�rtices, �ndices y contadores b�sicos de la malla.
/// </summary>
class
  MeshComponent : public Component {
public:
  /// <summary>
  /// Constructor por defecto.
  /// Inicializa la malla con cero v�rtices e �ndices y la marca como tipo MESH.
  /// </summary>
  MeshComponent() : m_numVertex(0), m_numIndex(0), Component(ComponentType::MESH) {}

  /// <summary>
  /// Destructor virtual por defecto.
  /// </summary>
  virtual
    ~MeshComponent() = default;

  /// <summary>
  /// Inicializa el componente de malla.
  /// Se puede extender en derivadas para reservar memoria o cargar datos.
  /// </summary>
  void
    init() override {};

  /// <summary>
  /// Actualiza la malla.
  /// �til para animaci�n de v�rtices o deformaciones en implementaciones futuras.
  /// </summary>
  /// <param name="deltaTime">Tiempo transcurrido desde la �ltima actualizaci�n.</param>
  void
    update(float deltaTime) override {};

  /// <summary>
  /// Renderiza la malla.
  /// Normalmente se usar�a para dibujar buffers asociados a la geometr�a.
  /// </summary>
  /// <param name="deviceContext">Contexto del dispositivo para operaciones gr�ficas.</param>
  void
    render(DeviceContext& deviceContext) override {};

  /// <summary>
  /// Libera recursos asociados al componente de malla.
  /// </summary>
  void
    destroy() override {};

public:
  // Nombre de la malla.
  std::string m_name;

  // Lista de v�rtices de la malla.
  std::vector<SimpleVertex> m_vertex;

  // Lista de �ndices que definen las primitivas de la malla.
  std::vector<unsigned int> m_index;

  // N�mero total de v�rtices en la malla.
  int m_numVertex;

  // N�mero total de �ndices en la malla.
  int m_numIndex;
};