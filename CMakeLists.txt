# CMakeList.txt: generate_sql 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("generate_sql")
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)
set(BOOST_ROOT "D:/workfile/lib/boost")
#set(FindBoost_INCLUDE_DIRS "${Boost_INCLUDE_DIRS}"))
find_package(Boost REQUIRED COMPONENTS regex REQUIRED )
MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
MESSAGE( STATUS "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}.")
MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
# 将源代码添加到此项目的可执行文件。
add_executable (generate_sql "generate_sql.cpp" "generate_sql.h" "preprocessfile.cpp")

target_link_libraries(generate_sql Boost::regex)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET generate_sql PROPERTY CXX_STANDARD 23)
endif()

# TODO: 如有需要，请添加测试并安装目标。
