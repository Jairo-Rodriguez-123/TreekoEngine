#include "Model3D.h"

bool
Model3D::InitializeFBXManager() {
  // Initialize the FBX SDK manager
  LSdkManager = FbxManager::Create();
  if (!LSdkManager) {
    ERROR("ModelLoader", "FbxManager::Create()", "Unable to create FBX Manager!");
    return false;
  }
  else {
    MESSAGE("ModelLoader", "ModelLoader", "Autodesk FBX SDK version " << LSdkManager->GetVersion())
  }

  //Create an IOSettings object
  FbxIOSettings* ios = FbxIOSettings::Create(LSdkManager, IOSROOT);
  LSdkManager->SetIOSettings(ios);

  //Create an FBX Scene
  LScene = FbxScene::Create(LSdkManager, "My Scene");
  if (!LScene) {
    ERROR("ModelLoader", "FbxScene::Create()", "Unable to create FBX scene!");
    return false;
  }
  else {
    MESSAGE("ModelLoader", "ModelLoader", "FBX Scene created successfully.");
  }
  return true;
}

std::vector<MeshComponent>
Model3D::LoadFBXModel(const std::string& filePath) {
  //01 . Initialize the SDK from Fbx Manager
  if (InitializeFBXManager()) {
    //02. Create an importer using the SDK manager
    FbxImporter* LImporter = FbxImporter::Create(LSdkManager, "");
    if (!LImporter) {
      ERROR("ModelLoader", "FbxImporter::Create()", "Unable to create FBX Importer!");
      return std::vector<MeshComponent>();
    }
    else {
      MESSAGE("ModelLoader", "ModelLoader", "FBX Importer created successfully.");
    }

    //03. Use the first argument as the filename for the importer.
    if (!LImporter->Initialize(filePath.c_str(), -1, LSdkManager->GetIOSettings())) {
      ERROR("ModelLoader", "FbxImporter::Initialize()", 
        "Unable to initialize FBX Importer! Error: " << LImporter->GetStatus().GetErrorString());
      LImporter->Destroy();
      return std::vector<MeshComponent>();
    }
    else {
      MESSAGE("ModelLoader", "ModelLoader", "FBX Importer initialized successfully with file: ");
    }

    //04. Import the scene from the file into the scene
    if (!LImporter->Import(LScene)) {
      ERROR("ModelLoader", "FbxImporter::Import()", 
        "Unable to import FBX scene! Error: " << LImporter->GetStatus().GetErrorString());
      LImporter->Destroy();
      return std::vector<MeshComponent>();
    }
    else {
      MESSAGE("ModelLoader", "ModelLoader", "FBX Scene imported successfully.");
      m_name = LImporter->GetFileName();
    }

    FbxAxisSystem::DirectX.ConvertScene(LScene);
    FbxSystemUnit::m.ConvertScene(LScene);
    FbxGeometryConverter gc(LSdkManager);
    gc.Triangulate(LScene, /*remplace*/ true);

    //05. Destroy the importer
    FbxNode* LRootNode = LScene->GetRootNode();

    if (LRootNode) {
      MESSAGE("ModelLoader", "ModelLoader", "Processing model from the scene root node.");
      for (int i = 0; i < LRootNode->GetChildCount(); i++) {
        ProcessFBXNode(LRootNode->GetChild(i));
      }
      return m_meshes;
    }
    else {
      ERROR("ModelLoader", "FbxScene::GetRootNode()",
        "Unable to get root node from FBX Scene!");
      return std::vector<MeshComponent>();
    }
  }
  return m_meshes;
}