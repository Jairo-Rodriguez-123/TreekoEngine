#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"
    

/*
 * @brief Utility class for loading 3D model data from files.
 * @note This class is designed to parse geometry files (like .obj)
 * and populate a MeshComponent with the resulting vertex and index data.
*/
class ModelLoader {
public:

  /*
   * @brief Default constructor for ModelLoader.
  */
  ModelLoader() = default;

  /*
   * @brief Default destructor for ModelLoader.
  */
  ~ModelLoader() = default;

  /*
   * @brief Loads a model from the specified file and populates the outMesh.
   * @param fileName The file path to the 3D model file (e.g., "model.obj").
   * @param outMesh A reference to the MeshComponent to be filled with geometry data.
   * @return bool True if the model was loaded and parsed successfully, false otherwise.
  */
  bool
    loadModel(const std::string& fileName, MeshComponent& outMesh);

private:

  /*
   * @brief Helper function to parse a 2-component vector (XMFLOAT2) from a line stream.
   * @param streamLine The stringstream containing the line data (e.g., "0.5 0.5").
   * @param outVector The vector pool where the parsed data will be stored.
  */
  void
    parseVec2(std::stringstream& streamLine, std::vector<XMFLOAT2>& outVector);

  /*
   * @brief Helper function to parse a 3-component vector (XMFLOAT3) from a line stream.
   * @param streamLine The stringstream containing the line data (e.g., "1.0 2.0 3.0").
   * @param outVector The vector pool where the parsed data will be stored.
  */
  void
    parseVec3(std::stringstream& streamLine, std::vector<XMFLOAT3>& outVector);
};