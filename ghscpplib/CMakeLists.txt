add_library("${PROJECT_NAME}" "")
add_library(GhsCppLib::GhsCppLib ALIAS "${PROJECT_NAME}")

set(GHSCPPLIB_EXPORT_FILE "GhsCppLib-Exports")
install(TARGETS "${PROJECT_NAME}" EXPORT "${GHSCPPLIB_EXPORT_FILE}")

target_include_directories("${PROJECT_NAME}" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" #ghscpplib_export.h
	"$<INSTALL_INTERFACE:include>" #${CMAKE_INSTALL_PREFIX}/include
)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DGHSCPPLIB_STATIC_DEFINE)
endif()

#Rename target GhsCppLib
set_target_properties("${PROJECT_NAME}" PROPERTIES
	DEBUG_POSTFIX "${STATIC_POSTFIX}-d" 
	RELEASE_POSTFIX "${STATIC_POSTFIX}"
	MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
	RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)

include("GenerateExportHeader")
generate_export_header("${PROJECT_NAME}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ghscpplib_export.h" DESTINATION "include")


add_subdirectory("include")
add_subdirectory("src")

set(GHSCPPLIB_CONFIG_DIR "lib/cmake/${PROJECT_NAME}")
configure_file("${GhsCppLib_SOURCE_DIR}/cmake/GhsCppLibConfig.cmake.in" "${GhsCppLib_BINARY_DIR}/${GHSCPPLIB_CONFIG_DIR}/GhsCppLibConfig.cmake")
install(FILES "${GhsCppLib_BINARY_DIR}/${GHSCPPLIB_CONFIG_DIR}/GhsCppLibConfig.cmake" DESTINATION "${GHSCPPLIB_CONFIG_DIR}")
install(EXPORT "${GHSCPPLIB_EXPORT_FILE}" DESTINATION "${GHSCPPLIB_CONFIG_DIR}" NAMESPACE "GhsCppLib::")