CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
PROJECT(slic_egbis_segmentation)


SET(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmmx -msse -msse -msse2 -msse3 -mssse3")
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMakeModules/")


FIND_PACKAGE(OpenCV REQUIRED)
LIST(APPEND LINK_LIBS 
	${OpenCV_LIBRARIES}
)


INCLUDE_DIRECTORIES(include test)

ADD_LIBRARY(libsuperpixel SHARED
	include/libsuperpixel/superpixel.cpp
	include/libsuperpixel/superpixel.h
)

ADD_LIBRARY(slic SHARED
	include/slic_modified/slic.cpp
	include/slic_modified/slic.h
)
TARGET_LINK_LIBRARIES(slic libsuperpixel)

ADD_LIBRARY(egbis SHARED 
	include/egbis/convolve.h
	include/egbis/disjoint-set.h
	include/egbis/filter.h
	include/egbis/image.h
	include/egbis/imconv.h
	include/egbis/imutil.h
	include/egbis/misc.h
	include/egbis/segment-graph.h
	include/egbis/segment-image.h
	include/egbis/egbis.h
	include/egbis/egbis.cpp
)
TARGET_LINK_LIBRARIES(egbis libsuperpixel)


ADD_EXECUTABLE(test_egbis_superpixel_segmentation test/test_egbis_superpixel_segmentation.cpp)
TARGET_LINK_LIBRARIES(test_egbis_superpixel_segmentation ${LINK_LIBS})
TARGET_LINK_LIBRARIES(test_egbis_superpixel_segmentation egbis)

ADD_EXECUTABLE(test_slic_superpixel_segmentation test/test_slic_superpixel_segmentation.cpp)
TARGET_LINK_LIBRARIES(test_slic_superpixel_segmentation ${LINK_LIBS})
TARGET_LINK_LIBRARIES(test_slic_superpixel_segmentation slic)

ADD_EXECUTABLE(test_histogram_superpixel_comparison test/test_histogram_superpixel_comparison.cpp)
TARGET_LINK_LIBRARIES(test_histogram_superpixel_comparison ${LINK_LIBS})
TARGET_LINK_LIBRARIES(test_histogram_superpixel_comparison slic)
TARGET_LINK_LIBRARIES(test_histogram_superpixel_comparison egbis)








