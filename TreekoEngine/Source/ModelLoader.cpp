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

  if (!modelFile.is_open()) {
    ERROR("ModelLoader.cpp", "loadModel", "El archivo no pudo ser abierto.");
    return false;
  }

  std::string currentLine;

  // "Piscinas" temporales para los datos del OBJ
  std::vector<XMFLOAT3> vertexPositions;
  std::vector<XMFLOAT2> textureCoords;
  std::vector<XMFLOAT3> vertexNormals;

  // Un "caché" para vértices únicos. Evita duplicar datos.
  // La clave (string) es el "v/vt/vn", el valor (int) es el índice final.
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

      // Itera sobre cada vértice de la cara (ej. "1/1/1", "2/2/2", etc.)
      while (lineStream >> vertexDataString) {

        int finalIndex = 0;

        // Busca si este vértice (ej. "1/1/1") ya ha sido procesado
        auto cacheEntry = vertexCache.find(vertexDataString);

        if (cacheEntry != vertexCache.end()) {
          // Si ya existe, usa su índice
          finalIndex = cacheEntry->second;
        }
        else {
          // Si es un vértice nuevo, hay que procesarlo
          int posIndex, uvIndex, normIndex;

          // CAMBIO ESTRUCTURAL: Usamos sscanf en lugar de un segundo stringstream.
          // Esto lee 3 enteros separados por '/'.
          int itemsRead = sscanf(vertexDataString.c_str(), "%d/%d/%d",
            &posIndex, &uvIndex, &normIndex);

          if (itemsRead != 3) {
            ERROR("ModelLoader.cpp", "loadModel", "Datos de cara malformados.");
            return false;
          }

          // Los índices de OBJ son 1-based, los vectores son 0-based.
          // Hay que restar 1.
          posIndex--;
          uvIndex--;
          normIndex--;

          // Comprobación de seguridad
          if (posIndex < 0 || posIndex >= vertexPositions.size() ||
            uvIndex < 0 || uvIndex >= textureCoords.size() ||
            normIndex < 0 || normIndex >= vertexNormals.size()) {

            ERROR("ModelLoader.cpp", "loadModel", "Índice de vértice fuera de rango.");
            return false;
          }

          // Construye el vértice final
          SimpleVertex newFinalVertex;
          newFinalVertex.Pos = vertexPositions[posIndex];
          newFinalVertex.Tex = textureCoords[uvIndex];

          // --- ¡CORRECCIÓN CRÍTICA! ---
          // Tu código original no asignaba la normal. Esta versión sí.
          newFinalVertex.Norm = vertexNormals[normIndex];

          // Añade el nuevo vértice a la lista final del mesh
          outMesh.m_vertex.push_back(newFinalVertex);

          // Obtenemos el índice de este nuevo vértice y lo guardamos
          int newFinalIndex = static_cast<int>(outMesh.m_vertex.size()) - 1;
          vertexCache[vertexDataString] = newFinalIndex;
          finalIndex = newFinalIndex;
        }

        // Añade el índice (nuevo o existente) a la lista de esta cara
        indicesForThisFace.push_back(finalIndex);
      }

      // Triangulación: Convierte la cara (tri o quad) en índices de triángulo
      if (indicesForThisFace.size() == 3) {
        // Es un triángulo
        outMesh.m_index.push_back(indicesForThisFace[0]);
        outMesh.m_index.push_back(indicesForThisFace[1]);
        outMesh.m_index.push_back(indicesForThisFace[2]);
      }
      else if (indicesForThisFace.size() == 4) {
        // Es un quad, se triangula (0,1,2) y (0,2,3)
        outMesh.m_index.push_back(indicesForThisFace[0]);
        outMesh.m_index.push_back(indicesForThisFace[1]);
        outMesh.m_index.push_back(indicesForThisFace[2]);

        outMesh.m_index.push_back(indicesForThisFace[0]);
        outMesh.m_index.push_back(indicesForThisFace[2]);
        outMesh.m_index.push_back(indicesForThisFace[3]);
      }
    }
  }

  // Guarda las cuentas finales en el mesh
  outMesh.m_numVertex = static_cast<int>(outMesh.m_vertex.size());
  outMesh.m_numIndex = static_cast<int>(outMesh.m_index.size());

  modelFile.close();
  return true;
}

// --- Funciones de ayuda (Helpers) ---
// (Cambiados los nombres de los parámetros)

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