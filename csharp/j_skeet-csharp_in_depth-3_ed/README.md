# Information
This folder contains materials (mainly code snippets) for the book "C# in depth" (third edition) by Jon Skeet.

[Link to Amazon](https://www.amazon.com/C-Depth-3rd-Jon-Skeet/dp/161729134X)


# Auxiliary inforation
To compile a code snippet run:
```
$ set CSC=c:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe
$ %CSC% /out:Program.exe /r:System.Collections.dll /t:exe main.cs
```
Also you must specify the necessary libraries by the "/r" parameter.
