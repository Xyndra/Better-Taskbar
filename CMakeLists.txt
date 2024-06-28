cmake_minimum_required(VERSION 3.28)
project(better_taskbar)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_DIR ./dependencies/glfw)
add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)
include_directories(${GLFW_DIR}/include)

set(IMGUI_DIR ./dependencies/imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)

set(Vulkan_LIBRARY "C:\\VulkanSDK\\1.3.283.0\\Lib\\vulkan-1.lib")
set(Vulkan_INCLUDE_DIR "C:\\VulkanSDK\\1.3.283.0\\Include")
find_package(Vulkan REQUIRED)
set(LIBRARIES "glfw;Vulkan::Vulkan")

include_directories(${GLFW_DIR}/deps)

file(GLOB sources *.cpp *.h)

add_executable(better_taskbar ${sources} ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_demo.cpp ${IMGUI_DIR}/imgui_tables.cpp ${IMGUI_DIR}/imgui_widgets.cpp)
target_link_libraries(better_taskbar ${LIBRARIES})
target_compile_definitions(better_taskbar PUBLIC -DImTextureID=ImU64)