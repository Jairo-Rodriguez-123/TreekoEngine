#pragma once
#include "Prerequisites.h"

/*
  *  @brief Represents a window in the Treeko Engine.
*/
class
	Window {
public:
	/*
   *  @brief Default constructor for Window.
	*/
	Window() = default;
	/*
   *  @brief Default destructor for Window.
	*/
	~Window() = default;

	/*
   *  @brief Initializes the window with the given instance, show command, and window procedure.
   *  @param hInstance Handle to the application instance.
   *  @param nCmdShow Show command for the window.
   *  @param wndproc Window procedure callback function.
   *  @return HRESULT indicating success or failure.
	*/
	HRESULT
		init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

	/*
   *  @brief Updates the window state.
	*/
	void
		update();

	/*
   *  @brief Renders the window contents.
	*/
	void
		render();

	/*
   *  @brief Destroys the window and releases resources.
	*/
	void
		destroy();

public:
	/*
   *  @brief Handle to the window.
	*/
	HWND m_hWnd = nullptr;
	/*
   *  @brief Width of the window.
	*/
	unsigned int m_width;
	/*
   *  @brief Height of the window.
	*/
	unsigned int m_height;
private:
	/*
   *  @brief Handle to the application instance.
	*/
	HINSTANCE m_hInst = nullptr;
	/*
   *  @brief Rectangle structure defining the window size and position.
	*/
	RECT m_rect;
	/*
   *  @brief Name of the window.
	*/
	std::string m_windowName = "TreekoEngine";
};