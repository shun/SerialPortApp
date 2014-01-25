CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(src)

#----------------------------------------------------------------                                          
find_package( Qt4 COMPONENTS QtCore QtGui QtXml REQUIRED)

INCLUDE_DIRECTORIES(
    ../inc
    /usr/include/qt4
    /usr/include/qt4/QtExtSerialPort
)

LINK_DIRECTORIES(
  /usr/local/lib
  )

LINK_LIBRARIES(
  )

#----------------------------------------------------------------                                          
SET(OUTPUTNAME "SerialPortApp")


SET(SRC_FILES
	main.cpp
	SerialPortClient.cpp
)

SET(HDR_FILES
	../inc/SerialPortClient.h
)

include(${QT_USE_FILE})
QT4_WRAP_CPP( MOC_SRC_FILES ${HDR_FILES})

ADD_EXECUTABLE(
  ${OUTPUTNAME}
  ${SRC_FILES}
  ${MOC_SRC_FILES}
  )

target_link_libraries(
    ${OUTPUTNAME}
    ${QT_LIBRARIES}
	qextserialport
)

#----------------------------------------------------------------                                          

#----------------------------------------------------------------                                          
INSTALL(

    FILES
        ${PROJECT_BINARY_DIR}/${OUTPUTNAME}
    DESTINATION
        ${CMAKE_SOURCE_DIR}/bin
    PERMISSIONS
        OWNER_READ
        OWNER_EXECUTE
        GROUP_READ
        GROUP_EXECUTE
        WORLD_READ
        WORLD_EXECUTE
        )

