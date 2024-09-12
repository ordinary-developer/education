# Information
This subfolder contains my files (my code snippets and my synopses about the main book's topics) 
for the book  **"Qt 5.10"** by **Maks Shlee**.

# HOWTOs
## Run a qml app (5.X) with the MinGW compiler
- use a project from the `__qml_5_skeleton` directory
- open the project diretctory in the `cmd.exe` shell
- set the `PATH` environment variable
  ```
  set PATH=<path-to-qml-bin>;<path-to-mingw-bin>;%PATH%
  ```
  where:
  _path-to-qml-bin_ is the directory the `qml.exe` file (corresponding to the mingw compiler (x64 or x32 version))
  _path-mingw-bin_ is the directory with the `mingw32-make` file (corresponding to a previous qml's folder)
- compile the project
  ```
  qmake <proj_file>
  mingw32-make
  ```
  where _proj_file_ is the project file
  (to create a project file from stratch use `qmake -project`)
  (keep in mind that both for x64 and x32 MinGw compilers the name of the make utility is the same: `mingw32-make`)
- run the app (in the same cmd session)
  ```
  .\debug\your_exe_file
  ```
  where _your_exe_file_ is generated executable file