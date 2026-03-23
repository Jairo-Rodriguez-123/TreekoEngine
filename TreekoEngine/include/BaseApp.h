#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "SwapChain.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "ShaderProgram.h"
#include "MeshComponent.h"
#include "Buffer.h"
#include "SamplerState.h"
#include "Model3D.h"
#include "ECS/Actor.h"
#include "EngineUtilities\GUI/GUI.h"
#include "SceneGraph\SceneGraph.h"
#include "EngineUtilities\Utilities\Camera.h"
#include "EngineUtilities\Utilities\Skybox.h"
#include "EngineUtilities\Utilities\LayoutBuilder.h"
		
extern IMGUI_IMPL_API
LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

/*
 *  @brief Main application base class for the engine.
 */
class
	BaseApp {
public:
	/*
	 *  @brief Default constructor.
	 */
	BaseApp() = default;
	/*
	 *  @brief Destructor. Calls destroy().
	 */
	~BaseApp() { destroy(); }

	/*
	 *  @brief Initializes resources before the main loop.
	 *  @return HRESULT status code.
	 */
	HRESULT
		awake();

	/*
	 *  @brief Runs the main application loop.
	 *  @param hInst Application instance handle.
	 *  @param nCmdShow Show command for the window.
	 *  @return Exit code.
	 */
	int
		run(HINSTANCE hInst, int nCmdShow);

	/*
	 *  @brief Initializes the application and its subsystems.
	 *  @return HRESULT status code.
	 */
	HRESULT
		init();

	/*
	 *  @brief Updates the application state.
	 *  @param deltaTime Time elapsed since last update.
	 */
	void
		update(float deltaTime);

	/*
	 *  @brief Renders the current frame.
	 */
	void
		render();

	/*
	 *  @brief Releases all resources and cleans up.
	 */
	void
		destroy();

	/*
	 *  @brief Handles window resize events.
	 *  @param newW New width.
	 *  @param newH New height.
	 */
	void
    onResize(UINT newW, UINT newH);

private:
	/*
	 *  @brief Windows procedure callback for handling window messages.
	 *  @param hWnd Window handle.
	 *  @param message Message identifier.
	 *  @param wParam Additional message information.
	 *  @param lParam Additional message information.
	 *  @return LRESULT result of message processing.
	 */
	static LRESULT CALLBACK
		WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	/*
	 *  @brief Main application window.
	 */
	Window                              m_window;
	/*
	 *  @brief Direct3D device.
	 */
	Device															m_device;
	/*
	 *  @brief Device context for rendering commands.
	 */
	DeviceContext												m_deviceContext;
	/*
	 *  @brief Swap chain for double buffering.
	 */
	SwapChain                           m_swapChain;
	/*
	 *  @brief Back buffer texture.
	 */
	Texture                             m_backBuffer;
	/*
	 *  @brief Render target view for the back buffer.
	 */
	RenderTargetView									  m_renderTargetView;
	/*
	 *  @brief Depth stencil texture.
	 */
	Texture                             m_depthStencil;
	/*
	 *  @brief Depth stencil view.
	 */
	DepthStencilView									  m_depthStencilView;
	/*
	 *  @brief Viewport configuration.
	 */
	Viewport                            m_viewport;
	/*
	 *  @brief Main shader program.
	 */
	ShaderProgram												m_shaderProgram;
	/*
	 *  @brief Indicates if Direct3D is ready.
	 */
  bool m_d3dRready = false;
	/*
	 *  @brief Constant buffer for shaders.
	 */
	Buffer															m_constantBuffer;
	/*
	 *  @brief Structure for main constant buffer data.
	 */
	CBMain															m_constantBufferStruct;
	/*
	 *  @brief Albedo texture for the cyber gun model.
	 */
	Texture 														m_cyberGunAlbedo;
	/*
	 *  @brief Texture for the skybox.
	 */
	Texture															m_skyboxTex;

	/*
	 *  @brief Main camera.
	 */
	Camera															m_camera;

	/*
	 *  @brief Scene graph for managing scene objects.
	 */
	SceneGraph													m_sceneGraph;

	/*
	 *  @brief List of actor pointers in the scene.
	 */
	std::vector<EU::TSharedPointer<Actor>> m_actors;
	/*
	 *  @brief Shared pointer to the cyber gun actor.
	 */
	EU::TSharedPointer<Actor> m_cyberGun;

	/*
	 *  @brief Pointer to the 3D model.
	 */
	Model3D* m_model;

	/*
	 *  @brief Constant buffer for resize-dependent data.
	 */
	CBChangeOnResize										cbChangesOnResize;
	/*
	 *  @brief Constant buffer for data that never changes.
	 */
	CBNeverChanges											cbNeverChanges;
	/*
	 *  @brief GUI manager.
	 */
	GUI																m_gui;

	/*
	 *  @brief Camera position vector.
	 */
	EU::Vector3 m_cameraPos;

	/*
	 *  @brief Skybox utility.
	 */
	Skybox m_skybox;
	/*
	 *  @brief Texture for the skybox.
	 */
  Texture m_skyboxTex;
	/*
	 *  @brief Default rasterizer state.
	 */
	RasterizerState m_defaultRasterizer;
	/*
	 *  @brief Default depth stencil state.
	 */
	DepthStencilState m_defaultDepthStencil;
};