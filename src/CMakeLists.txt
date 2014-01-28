CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT(src)

#----------------------------------------------------------------
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

#----------------------------------------------------------------
include_directories(
  ../inc
  /usr/include/qt4/QtExtSerialPort
  )

#----------------------------------------------------------------
set(OUTPUTNAME "SerialPortApp")

set(SRC_FILES
  main.cpp
  SerialPortClient.cpp
  )

set(INC_FILES
  ../inc/SerialPortClient.h
  )

qt5_wrap_cpp(MOC_FILES
  ${INC_FILES}
  )

#----------------------------------------------------------------
add_executable(
  ${OUTPUTNAME}.out
  ${SRC_FILES}
  ${MOC_FILES}
  )

target_link_libraries(
  ${OUTPUTNAME}.out
  qextserialport
  )

qt5_use_modules(
  ${OUTPUTNAME}.out
  Widgets
  Core
  )

#----------------------------------------------------------------
INSTALL(
  FILES
  	${PROJECT_BINARY_DIR}/${OUTPUTNAME}.out
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