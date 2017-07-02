The library Microsoft.Office.Interop.Excel.dll may be not exist, 
to add it to your project run Install-Package Microsoft.Office.Interop.Excel in the Package Console (in VS or ShaprpDevelop) and the copy it to your folder and then run the standard compiliation in cmd.exe

to build 
```
> set CSC=c:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe
> %CSC% /out:Program.exe /r:System.Collections.dll /r:System.ComponentModel.dll /r:System.Linq.dll /r:Microsoft.Office.Interop.Excel.dll /t:exe main.cs
```

(it compiles, but doesn't run (runs with an exception))