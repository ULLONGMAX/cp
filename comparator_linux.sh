# NOT TESTED CODE

#!/bin/bash

# Este script compara la salida de dos programas, 'brute.exe' y 'd.exe',
# generando entradas aleatorias y deteniéndose si las salidas no coinciden.

for i in $(seq 1 100); do
    echo $i
    # Ejecutar gen.exe y redirigir su salida a inp.txt
    ./gen.exe > inp.txt

    # Ejecutar brute.exe con inp.txt como entrada y redirigir su salida a out_brute.txt
    ./brute.exe < inp.txt > out_brute.txt

    # Ejecutar d.exe con inp.txt como entrada y redirigir su salida a out_d.txt
    ./d.exe < inp.txt > out_d.txt

    # Comparar los archivos out_d.txt y out_brute.txt
    # diff retorna 0 si los archivos son identicos, y 1 si son diferentes.
    if ! diff out_d.txt out_brute.txt &> /dev/null; then
        echo "¡Diferencia encontrada! El script se detendrá."
        exit 1
    fi
done

echo "Todos los 100 casos de prueba fueron correctos. ✅"
exit 0
