@echo off

rem Set the compiler and flags
set COMPILER=g++
set FLAGS=-std=c++11 -Wall

rem Source files
set SOURCES=main.cpp network\net.cpp network\layer.cpp network\neuron.cpp optimizer\utils.cpp

rem Output executable name
set OUTPUT=neural_net.exe

rem Build command
%COMPILER% %FLAGS% %SOURCES% -o %OUTPUT%

rem Check if compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
) else (
    echo Compilation successful.
    exit /b 0
)
