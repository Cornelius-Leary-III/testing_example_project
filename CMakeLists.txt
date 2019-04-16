cmake_minimum_required(VERSION 3.13)
project(testing_example_project)

set(CMAKE_CXX_STANDARD 14)

########## GOOGLE TEST ##########

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

######## END GOOGLE TEST ########

#add_executable(testing_example_project
#               main.cpp
#               MathOperations.cpp MathOperations.h
#               unit_test_Operation.cpp
#               unit_test_MathOperations.cpp
#               mock_test_MathOperations.cpp
#               Operation.cpp Operation.h)


########## Executables ##########

### MathOperation class - unit tests

add_executable(math_test
               MathOperations.h MathOperations.cpp
               Operation.h Operation.cpp
               unit_test_MathOperations.cpp)

target_link_libraries(math_test
                      gtest_main)

add_test(NAME test_math
         COMMAND math_test)

### Operation class - unit tests

add_executable(operations_test
               Operation.h Operation.cpp
               unit_test_Operation.cpp)

target_link_libraries(operations_test
                      gtest_main)

add_test(NAME test_Operation
         COMMAND operations_test)

### MathOperation class & Operation class - integration tests

add_executable(math_integration_test
               MathOperations.h MathOperations.cpp
               Operation.h Operation.cpp
               integration_test_MathOperations.cpp)

target_link_libraries(math_integration_test
                      gtest_main)

add_test(NAME integration_test_math
         COMMAND math_integration_test)
