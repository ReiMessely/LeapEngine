#Graphics engine cmake
add_library(GraphicsEngine STATIC
"DirectX/DirectXEngine.cpp"
"Interfaces/IRenderer.h" 
"Camera.h"
"Camera.cpp"
"DirectX/DirectXMeshRenderer.cpp"
"DirectX/DirectXMaterial.cpp"
"Data/Vertex.h"
"Interfaces/IMaterial.h"
"Shader.h"
"Shaders/Pos3D.cpp"
"DirectX/DirectXShaderReader.h"
"DirectX/DirectXShaderReader.cpp"
"ShaderDelete.cpp"
"MeshLoader.h"
"Shaders/PosNorm3D.h"
"Shaders/PosNorm3D.cpp"
"DirectX/DirectXMeshLoader.h"
"DirectX/DirectXMeshLoader.cpp"
"Interfaces/ITexture.h"
"DirectX/DirectXTexture.h"
"DirectX/DirectXTexture.cpp"
"Shaders/PosNormTex3D.h"
"Shaders/PosNormTex3D.cpp"
"Data/CustomMesh.h"
"DirectX/DirectXRenderTarget.h"
"DirectX/DirectXRenderTarget.cpp"
"DirectX/DirectXShadowRenderer.h"
"DirectX/DirectXShadowRenderer.cpp"
"Shaders/ShadowMap.h"
"Shaders/ShadowMap.cpp"
"DirectionalLight.h"
"DirectionalLight.cpp"
"ImGui/imgui.cpp"
"ImGui/imgui_demo.cpp"
"ImGui/imgui_draw.cpp"
"ImGui/imgui_tables.cpp"
"ImGui/imgui_widgets.cpp"
"ImGui/imgui_impl_glfw.cpp"
"DirectX/imgui_impl_dx11.cpp"
"DirectX/DirectXSpriteRenderer.h"
"DirectX/DirectXSpriteRenderer.cpp"
"Data/SpriteVertex.h"
"Data/Sprite.h"
"Shaders/Sprites.h"
"Shaders/Sprites.cpp" 
"DirectX/DirectXDefaults.h" 
"DirectX/DirectXDefaults.cpp")

# DirectXTex
set(DIRECTX_TEX_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/DirectXTex/include")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(DIRECTX_TEX_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/DirectXTex/lib/debug/DirectXTex.lib")
else()
	set(DIRECTX_TEX_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/DirectXTex/lib/release/DirectXTex.lib")
endif()

# FX11
set(FX11_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/FX11/include")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
set(FX11_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/FX11/lib/debug/Effects11.lib")
else()
set(FX11_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/FX11/lib/release/Effects11.lib")
endif()

set(GraphicsEngineIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

target_include_directories(GraphicsEngine PUBLIC ${DIRECTX_TEX_INCLUDE_DIR} ${FX11_INCLUDE_DIR})
target_link_libraries(GraphicsEngine PUBLIC ${FX11_LIBRARY_DIR})