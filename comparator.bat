@echo off
for /L %%i in (1,1,100) do (
    echo %%i
    rem Ejecutar gen.exe y redirigir su salida a in.txt
    gen.exe > inp.txt

    rem Ejecutar brute.exe con in.txt como entrada y redirigir su salida a out_brute.txt
    brute.exe < inp.txt > out_brute.txt

    rem Ejecutar d.exe con in.txt como entrada y redirigir su salida a out_d.txt
    d.exe < inp.txt > out_d.txt

    rem Comparar los archivos out_d.txt y out_brute.txt
    fc out_d.txt out_brute.txt > nul
    if errorlevel 1 (
       rem Los archivos son diferentes, romper el bucle
       goto :end
    )
)

:end
echo Fin del script.
