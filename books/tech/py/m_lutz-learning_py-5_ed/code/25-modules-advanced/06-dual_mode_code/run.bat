@echo off

echo [example_01] - calling without params
py formats.py
echo.

echo [example 02] - calling with params
py formats.py 999999999 0
py formats.py 999999999 0
py formats.py 123456789012345 0
py formats.py 123456789012345 25
py formats.py 123.456 0
py formats.py -123.456 0
echo.

echo [example 03] - importing to another module and then calling
py main.py
