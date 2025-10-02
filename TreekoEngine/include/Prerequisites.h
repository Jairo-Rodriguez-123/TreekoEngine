#pragma once

/*
  *  @brief Standard C++ libraries used in the project
*/
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
#include <thread>

/*
  *  @brief DirectX libraries required for rendering and resource management
*/
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

/*
  *  @brief Macro to safely release COM objects and set pointer to nullptr
*/
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

/*
  *  @brief Macro to output a debug message about resource creation
*/
#define MESSAGE( classObj, method, state )   \
{                                            \
   std::wostringstream os_;                  \
   os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
}

/*
  *  @brief Macro to output an error message to the debug output
*/
#define ERROR(classObj, method, errorMSG)                     \
{                                                             \
    try {                                                     \
        std::wostringstream os_;                              \
        os_ << L"ERROR : " << classObj << L"::" << method     \
            << L" : " << errorMSG << L"\n";                   \
        OutputDebugStringW(os_.str().c_str());                \
    } catch (...) {                                           \
        OutputDebugStringW(L"Failed to log error message.\n");\
    }                                                         \
}



/*
  *  @brief Structure representing a simple vertex with position and texture coordinates
*/
struct SimpleVertex
{
  /*
    *  @brief 3D position of the vertex
  */
  XMFLOAT3 Pos;
  /*
    *  @brief 2D texture coordinates of the vertex
  */
  XMFLOAT2 Tex;
};

/*
  *  @brief Constant buffer structure for view matrix (never changes)
*/
struct CBNeverChanges
{
  /*
    *  @brief View matrix
  */
  XMMATRIX mView;
};

/*
  *  @brief Constant buffer structure for projection matrix (changes on resize)
*/
struct CBChangeOnResize
{
  /*
    *  @brief Projection matrix
  */
  XMMATRIX mProjection;
};

/*
  *  @brief Constant buffer structure for world matrix and mesh color (changes every frame)
*/
struct CBChangesEveryFrame
{
  /*
    *  @brief World matrix
  */
  XMMATRIX mWorld;
  /*
    *  @brief Mesh color as a 4D vector
  */
  XMFLOAT4 vMeshColor;
};

/*
  *  @brief Enum representing supported image file extensions
*/
enum ExtensionType {
  /*
    *  @brief DDS file extension
  */
  DDS = 0,
  /*
    *  @brief PNG file extension
  */
  PNG = 1,
  /*
    *  @brief JPG file extension
  */
  JPG = 2
};
