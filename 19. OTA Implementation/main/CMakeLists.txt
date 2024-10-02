idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS ".")

#Line to modify the build configuration (e.g., in your CMakeLists.txt) to not treat switch warnings as errors
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error=switch)
#target_compile_options(${COMPONENT_TARGET} PRIVATE -Wno-error=switch)

