#pragma once
#include "Prerequisites.h"
#include "EngineUtilities/Vectors/Vector3.h"
#include "Component.h"

/*
  *  @brief Represents a transformation component in the ECS, handling position, rotation, scale, and transformation matrix.
*/
class
  Transform : public Component {
public:
  
  /*
    *  @brief Default constructor. Initializes position, rotation, scale, and matrix.
  */
  Transform() : position(),
    rotation(),
    scale(),
    matrix(),
    Component(ComponentType::TRANSFORM) {
  }

  /*
    *  @brief Initializes the transform, setting scale to one and matrix to identity.
  */
  void
    init() {
    scale.one();
    matrix = XMMatrixIdentity();
  }

  /*
    *  @brief Updates the transformation matrix based on position, rotation, and scale.
    *  @param deltaTime Time elapsed since last update.
  */
  void
    update(float deltaTime) override {
    
    XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);
    
    XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
    
    XMMATRIX translationMatrix = XMMatrixTranslation(position.x, position.y, position.z);

    matrix = scaleMatrix * rotationMatrix * translationMatrix;
  }

  /*
    *  @brief Renders the transform component. (Empty implementation)
    *  @param deviceContext Device context for rendering.
  */
  void
    render(DeviceContext& deviceContext) override {}

  /*
    *  @brief Destroys the transform component. (Empty implementation)
  */
  void
    destroy() {}

  /*
    *  @brief Gets the position vector.
    *  @return Reference to the position vector.
  */
  const EU::Vector3&
    getPosition() const { return position; }

  /*
    *  @brief Sets the position vector.
    *  @param newPos New position vector.
  */
  void
    setPosition(const EU::Vector3& newPos) { position = newPos; }

  /*
    *  @brief Gets the rotation vector.
    *  @return Reference to the rotation vector.
  */
  const EU::Vector3&
    getRotation() const { return rotation; }

  /*
    *  @brief Sets the rotation vector.
    *  @param newRot New rotation vector.
  */
  void
    setRotation(const EU::Vector3& newRot) { rotation = newRot; }

  /*
    *  @brief Gets the scale vector.
    *  @return Reference to the scale vector.
  */
  const EU::Vector3&
    getScale() const { return scale; }

  /*
    *  @brief Sets the scale vector.
    *  @param newScale New scale vector.
  */
  void
    setScale(const EU::Vector3& newScale) { scale = newScale; }

  /*
    *  @brief Sets position, rotation, and scale vectors.
    *  @param newPos New position vector.
    *  @param newRot New rotation vector.
    *  @param newSca New scale vector.
  */
  void
    setTransform(const EU::Vector3& newPos,
      const EU::Vector3& newRot,
      const EU::Vector3& newSca) {
    position = newPos;
    rotation = newRot;
    scale = newSca;
  }

  /*
    *  @brief Translates the position by a given vector.
    *  @param translation Translation vector.
  */
  void
    translate(const EU::Vector3& translation);

private:
  /*
    *  @brief Position vector of the transform.
  */
  EU::Vector3 position;  
  /*
    *  @brief Rotation vector of the transform.
  */
  EU::Vector3 rotation;  
  /*
    *  @brief Scale vector of the transform.
  */
  EU::Vector3 scale;     

public:
  /*
    *  @brief Transformation matrix representing the combined scale, rotation, and translation.
  */
  XMMATRIX matrix;    
};