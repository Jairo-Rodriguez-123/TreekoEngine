#pragma once
#include "Prerequisites.h"

#include "imgui.h"
#include <imgui_internal.h>
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "ImGuizmo.h"

class Viewport;
class Window;
class Device;
class DeviceContext;
class Actor;
class Camera;

class
  GUI {
public:
	/*
	  *  @brief Default constructor for the GUI class.
	*/
  GUI() = default;
	/*
	  *  @brief Default destructor for the GUI class.
	*/
  ~GUI() = default;

	/*
	  *  @brief Called to perform early initialization tasks for the GUI system.
	*/
  void
    awake();

	/*
	  *  @brief Initializes the GUI system with the given window, device, and device context.
	  *  @param window Reference to the Window object.
	  *  @param device Reference to the Device object.
	  *  @param deviceContext Reference to the DeviceContext object.
	*/
  void
    init(Window& window, Device& device, DeviceContext& deviceContext);

	/*
	  *  @brief Updates the GUI system, typically called once per frame.
	  *  @param window Reference to the Window object.
	*/
  void
    update(Window& window);

	/*
	  *  @brief Renders the GUI elements to the screen.
	*/
  void
    render();

	/*
	  *  @brief Cleans up and destroys the GUI system.
	*/
  void
    destroy();

	/*
	  *  @brief Draws the main toolbar of the GUI.
	*/
  void
    ToolBar();

	/*
	  *  @brief Triggers the application close process from the GUI.
	*/
  void
    closeApp();

	/*
	  *  @brief Displays tooltip data in the GUI.
	*/
  void
    toolTipData();

	/*
	  *  @brief Applies a custom Apple-like liquid style to the GUI.
	  *  @param opacity Opacity value between 0 and 1.
	  *  @param accent Accent color as an ImVec4.
	*/
  void
    appleLiquidStyle(float opacity /*0..1f*/, ImVec4 accent /*=#0A84FF*/);

	/*
	  *  @brief Draws a control for editing a 3-component vector.
	  *  @param label Label for the control.
	  *  @param values Pointer to the float array representing the vector.
	  *  @param resetValues Value to reset the vector components to.
	  *  @param columnWidth Width of the label column.
	*/
  void
    vec3Control(const std::string& label,
      float* values,
      float resetValues = 0.0f,
      float columnWidth = 100.0f);

	/*
	  *  @brief Displays the general inspector panel for the given actor.
	  *  @param actor Shared pointer to the Actor to inspect.
	*/
  void
    inspectorGeneral(EU::TSharedPointer<Actor> actor);

	/*
	  *  @brief Displays the container inspector panel for the given actor.
	  *  @param actor Shared pointer to the Actor to inspect.
	*/
  void
    inspectorContainer(EU::TSharedPointer<Actor> actor);

	/*
	  *  @brief Displays the outliner panel listing all actors.
	  *  @param actors Vector of shared pointers to Actor objects.
	*/
  void
    outliner(const std::vector<EU::TSharedPointer<Actor>>& actors);

	/*
	  *  @brief Allows editing of the transform of the given actor using gizmos.
	  *  @param view View matrix.
	  *  @param projection Projection matrix.
	  *  @param actor Shared pointer to the Actor to edit.
	*/
  void
    editTransform(const XMMATRIX& view, const XMMATRIX& projection, EU::TSharedPointer<Actor> actor);

	/*
	  *  @brief Draws the toolbar for selecting and using gizmos.
	*/
  void
    drawGizmoToolbar();
private:
	/*
	  *  @brief State variable for a checkbox in the GUI.
	*/
  bool checkboxValue = true;
	/*
	  *  @brief State variable for a second checkbox in the GUI.
	*/
  bool checkboxValue2 = false;
	/*
	  *  @brief Stores the names of objects for display in the GUI.
	*/
  std::vector<const char*> m_objectsNames;
	/*
	  *  @brief Stores tooltips for GUI elements.
	*/
  std::vector<const char*> m_tooltips;

	/*
	  *  @brief State variable to control the visibility of the exit popup.
	*/
  bool show_exit_popup = false; // Variable de estado para el popup


public:
	/*
	  *  @brief Index of the currently selected actor in the outliner.
	*/
  int selectedActorIndex = -1;
};
