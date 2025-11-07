#include "ModelLoader.h"
#include <fstream>      
#include <sstream>      
#include <string>       
#include <vector>       
#include <map>          
//#include <cstdio>       

bool
ModelLoader::loadModel(const std::string& fileName, MeshComponent& outMesh) {
  std::ifstream modelFile(fileName);

  if (!modelFile.is_open()) 
  {
    ERROR("ModelLoader.cpp", "loadModel", "El archivo pudo abrirse.");
    return false;
  }

  std::string currentLine;

  std::vector<XMFLOAT3> vertexPositions;
  std::vector<XMFLOAT2> textureCoords;
  std::vector<XMFLOAT3> vertexNormals;

  std::map<std::string, int> vertexCache;

  while (std::getline(modelFile, currentLine)) {
    std::stringstream lineStream(currentLine);
    std::string lineHeader;
    lineStream >> lineHeader;

    if (lineHeader == "vt") {
      parseVec2(lineStream, textureCoords);
    }
    else if (lineHeader == "vn") {
      parseVec3(lineStream, vertexNormals);
    }
    else if (lineHeader == "v") {
      parseVec3(lineStream, vertexPositions);
    }
    else if (lineHeader == "f") {
      std::string vertexDataString;
      std::vector<int> indicesForThisFace;

      while (lineStream >> vertexDataString) {

        int finalIndex = 0;

        auto cacheEntry = vertexCache.find(vertexDataString);

        if (cacheEntry != vertexCache.end()) {
         
          finalIndex = cacheEntry->second;
        }
        else {
          
          int posIndex, uvIndex, normIndex;

          int itemsRead = sscanf(vertexDataString.c_str(), "%d/%d/%d",
            &posIndex, &uvIndex, &normIndex);

          if (itemsRead != 3) {
            ERROR("ModelLoader.cpp", "loadModel", "Datos no completados.");
            return false;
          }

          posIndex--;
          uvIndex--;
          normIndex--;

          if (posIndex < 0 || posIndex >= vertexPositions.size() ||
            uvIndex < 0 || uvIndex >= textureCoords.size() ||
            normIndex < 0 || normIndex >= vertexNormals.size()) {

            ERROR("ModelLoader.cpp", "loadModel", "Índice de vértice fuera de rango.");
            return false;
          }

          SimpleVertex newFinalVertex;
          newFinalVertex.Pos = vertexPositions[posIndex];
          newFinalVertex.Tex = textureCoords[uvIndex];

          newFinalVertex.Norm = vertexNormals[normIndex];

          outMesh.m_vertex.push_back(newFinalVertex);

          int newFinalIndex = static_cast<int>(outMesh.m_vertex.size()) - 1;
          vertexCache[vertexDataString] = newFinalIndex;
          finalIndex = newFinalIndex;
        }

        indicesForThisFace.push_back(finalIndex);
      }

      if (indicesForThisFace.size() == 3) {
       
        outMesh.m_index.push_back(indicesForThisFace[0]);
        outMesh.m_index.push_back(indicesForThisFace[1]);
        outMesh.m_index.push_back(indicesForThisFace[2]);
      }
      else if (indicesForThisFace.size() == 4) {
        
        outMesh.m_index.push_back(indicesForThisFace[0]);
        outMesh.m_index.push_back(indicesForThisFace[1]);
        outMesh.m_index.push_back(indicesForThisFace[2]);

        outMesh.m_index.push_back(indicesForThisFace[0]);
        outMesh.m_index.push_back(indicesForThisFace[2]);
        outMesh.m_index.push_back(indicesForThisFace[3]);
      }
    }
  }


  outMesh.m_numVertex = static_cast<int>(outMesh.m_vertex.size());
  outMesh.m_numIndex = static_cast<int>(outMesh.m_index.size());

  modelFile.close();
  return true;
}

void
ModelLoader::parseVec2(std::stringstream& lineData, std::vector<XMFLOAT2>& dataPool) {
  XMFLOAT2 v2;
  lineData >> v2.x >> v2.y;
  dataPool.push_back(v2);
}

void
ModelLoader::parseVec3(std::stringstream& lineData, std::vector<XMFLOAT3>& dataPool) {
  XMFLOAT3 v3;
  lineData >> v3.x >> v3.y >> v3.z;
  dataPool.push_back(v3);
} 