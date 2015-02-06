@echo off
:again
r.exe >input.dat
neuqd.exe < input.dat >output.dat
ceshi.exe <input.dat >outputb.dat
fc output.dat outputb.dat >nul
if not errorlevel 1 goto again