set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

if(NOT EXISTS ${IMGUI_DIR}/imgui.h)
  message(FATAL_ERROR "ImGui missing. Run: git submodule update --init --recursive")
endif()

add_library(imgui STATIC
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  ${IMGUI_DIR}/imgui_demo.cpp
  ${IMGUI_DIR}/backends/imgui_impl_win32.cpp
  ${IMGUI_DIR}/backends/imgui_impl_dx11.cpp
)

target_include_directories(imgui PUBLIC
  ${IMGUI_DIR}
  ${IMGUI_DIR}/backends
)

target_link_libraries(imgui PUBLIC d3d11 dxgi d3dcompiler)