cmake_minimum_required(VERSION 3.12)

project(matrix)

#option(WITH_BOOST_TEST "Whether to build Boost test" ON)
# Опция для включения Doxygen
option(WITH_DOXYGEN "Build Doxygen documentation" OFF)

add_executable(matrix main.cpp)

set_target_properties(matrix PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


# Тест (если файл test.cpp существует)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
    # Ищем установленный gtest
    find_package(GTest REQUIRED)
    
    # Тестовый исполняемый файл
    add_executable(matrix_tests test.cpp)
    
    # Линкуем с системным gtest
    target_link_libraries(matrix_tests PRIVATE GTest::gtest GTest::gtest_main)
    
    # Тесты
    enable_testing()
    add_test(NAME AllTests COMMAND matrix_tests)
else()
    message(WARNING "test.cpp not found, tests will not be built")
endif()


if (MSVC)
    target_compile_options(matrix PRIVATE
        /W4
    )
else ()
    target_compile_options(matrix PRIVATE
        -Wall -Wextra -pedantic -Werror -Wunused -Wunused-variable -Wunused-parameter
    )
endif()

target_compile_definitions(matrix PRIVATE 
    $<$<CONFIG:Debug>:ENABLE_DEBUG_LOGGING>
    $<$<CONFIG:RelWithDebInfo>:ENABLE_DEBUG_LOGGING>
)


install(TARGETS matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_DEBIAN_FILE_NAME "matrix.deb")
set(CPACK_PACKAGE_CONTACT example@example.com)


include(CPack)

