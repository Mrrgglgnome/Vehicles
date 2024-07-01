@echo off

echo cmake_minimum_required(VERSION 3.10) > CMakeLists.txt
echo project(Vehicles) >> CMakeLists.txt
echo add_executable(VehiclesCMake Vehicles.cpp) >> CMakeLists.txt
mkdir VehiclesCMake
cd VehiclesCmake
cmake ../
cmake --build .