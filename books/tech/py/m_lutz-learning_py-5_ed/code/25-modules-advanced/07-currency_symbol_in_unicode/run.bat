@echo off

echo [example 01] - printing currencies using unicode
py main1.py
echo.

echo [example 02] - open a file with currencies in notepad
chcp 65001
set PYTHONIOENCODING=utf-8
py main1.py > tmp
type tmp
notepad tmp
echo.

echo [example 03] - more fun with unicode
py main2.py
echo.
