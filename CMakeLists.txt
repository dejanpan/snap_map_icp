cmake_minimum_required(VERSION 2.8.3)
project(snap_map_icp)

find_package(catkin REQUIRED std_msgs nav_msgs laser_geometry sensor_msgs geometry_msgs tf)

find_package(Eigen REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})
add_definitions(${EIGEN_DEFINITIONS})

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})


catkin_package(
  CATKIN_DEPENDS std_msgs nav_msgs laser_geometry sensor_msgs geometry_msgs tf
  )

include_directories(${catkin_INCLUDE_DIRS}
  )

add_executable(SnapMapICP src/SnapMapICP.cpp)
add_executable(TFpub src/TFpub.cpp)
add_executable(FreezeCloud2 src/FreezeCloud2.cpp)

target_link_libraries(SnapMapICP ${catkin_LIBRARIES} ${PCL_LIBRARIES})
target_link_libraries(TFpub ${catkin_LIBRARIES})
target_link_libraries(FreezeCloud2 ${catkin_LIBRARIES})