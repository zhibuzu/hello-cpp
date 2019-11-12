PROJECT(ENDIAN-TEST)
SET(SRC_LIST test_endian.cpp)
MESSAGE(STATUS "This is Binary Dir " ${ENDIAN-TEST_BIRNARY_DIR})
MESSAGE(STATUS "This is Source Dir " ${ENDIAN-TEST_SOURCE_DIR})
ADD_EXECUTABLE(endian_demo ${SRC_LIST})
# install to /usr/bin
#INSTALL(TARGETS endian_demo
#    RUNTIME DESTINATION bin
#    )
