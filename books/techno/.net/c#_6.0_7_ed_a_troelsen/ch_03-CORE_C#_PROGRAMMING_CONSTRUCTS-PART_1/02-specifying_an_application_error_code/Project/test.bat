@echo off

rem A batch file for the main application
rem which captures the app's return value

bin\Debug\Project.exe
@if %ERRORLEVEL% == "0" goto success

:fail
    echo This application failed!
    echo return value = %ERRORLEVEL%!
    goto end
:success
    echo This application has succeeded!
    echo return value = %ERRORLEVEL%
    goto end
:end
echo All Done.