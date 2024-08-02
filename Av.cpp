#include "windows.h"

// Esta función muestra un mensaje indicando que no hay malware presente.
void dont_execute()
{
    MessageBoxW(NULL, L"No malware here :)", L"Legit app", MB_OK);
}

// Esta función muestra un mensaje indicando que se está ejecutando código malicioso.
void execute()
{
    MessageBoxW(NULL, L"Malicious code is running", L"Malware", MB_OK);
}

int main()
{
    HKEY hKey;            // Variable para manejar la clave del registro
    LONG Resultado;       // Variable para almacenar el resultado de la operación del registro

    // Ruta de la clave del registro que se va a verificar
    const char *keyPath = "SYSTEM\\CurrentControlSet\\Services\\VBoxGuest";

    // Abre la clave del registro especificada con permiso de lectura
    Resultado = RegOpenKeyExA(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_READ, &hKey);

    // Verifica si la clave del registro se abrió con éxito
    if (Resultado == ERROR_SUCCESS)
    {
        // Si la clave existe, se ejecuta la función dont_execute()
        dont_execute();
    }
    else
    {
        // Si la clave no existe, se ejecuta la función execute()
        execute();
    }

    // Buenas conductas: retornar 0 indicando que el programa finalizó correctamente
    return 0;
}
