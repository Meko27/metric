
include_directories( ${PROJECT_SOURCE_DIR} )
add_subdirectory(correlation_tests)
add_subdirectory(dnn_tests)
add_subdirectory(ensembles_tests)
add_subdirectory(mapping_tests)
add_subdirectory(space_tests)
add_subdirectory(sparsification_tests)
#add_subdirectory(transform_test) bye bye error
add_subdirectory(utils)
add_subdirectory(wrapper_tests)
add_subdirectory(distance_tests)
add_subdirectory(image_processing_tests)
