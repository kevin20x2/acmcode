@echo off
:again
data.exe %random% >input
mytree.exe <input >output.a
duipai.exe <input >output.b
fc output.a output.b >nul
if not errorlevel 1 goto again
