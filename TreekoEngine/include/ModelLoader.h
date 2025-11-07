#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"
    

/*
  *  @brief Loads 3D model data from files and parses it into MeshComponent objects.
*/
class ModelLoader {
public:
  
  /*
    *  @brief Default constructor for ModelLoader.
  */
  ModelLoader() = default;

  /*
    *  @brief Default destructor for ModelLoader.
  */
  ~ModelLoader() = default;

  /*
    *  @brief Loads a model from the specified file and outputs the mesh data.
    *  @param fileName Path to the model file.
    *  @param outMesh Reference to the MeshComponent to populate.
    *  @return True if the model was loaded successfully, false otherwise.
  */
  bool
    loadModel(const std::string& fileName, MeshComponent& outMesh);

private:
  
  /*
    *  @brief Parses a line containing a 2D vector and adds it to the output vector.
    *  @param streamLine Stream containing the line to parse.
    *  @param outVector Vector to store the parsed XMFLOAT2.
  */
  void
    parseVec2(std::stringstream& streamLine, std::vector<XMFLOAT2>& outVector);

  /*
    *  @brief Parses a line containing a 3D vector and adds it to the output vector.
    *  @param streamLine Stream containing the line to parse.
    *  @param outVector Vector to store the parsed XMFLOAT3.
  */
  void
    parseVec3(std::stringstream& streamLine, std::vector<XMFLOAT3>& outVector);
};