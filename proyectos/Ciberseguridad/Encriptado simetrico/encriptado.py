from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes # type: ignore
from cryptography.hazmat.backends import default_backend # type: ignore
from cryptography.hazmat.primitives import padding # type: ignore
import base64

# Función para cifrar el mensaje
def cifrar_mensaje(mensaje, clave):
    # Aseguramos que la clave es de 16 bytes (128 bits)
    clave = clave.ljust(16)[:16].encode('utf-8')  # Rellenamos o recortamos a 16 bytes el mensajee

    # Rellenamos el mensaje para que su longitud sea múltiplo de 16 (bloques AES)
    padder = padding.PKCS7(128).padder()
    mensaje_padded = padder.update(mensaje.encode('utf-8')) + padder.finalize()

    # Configuramos el cifrado con AES en modo ECB
    cipher = Cipher(algorithms.AES(clave), modes.ECB(), backend=default_backend())
    encryptor = cipher.encryptor()

    # Ciframos el mensaje
    mensaje_cifrado = encryptor.update(mensaje_padded) + encryptor.finalize()

    # Devolvemos el mensaje cifrado en base64 para hacerlo legible codificacion estándar utf-8
    return base64.b64encode(mensaje_cifrado).decode('utf-8')
#-------------------------------------------------------------------------------------------#
# Función para descifrar el mensaje
def descifrar_mensaje(mensaje_cifrado, clave):
    # Aseguramos que la clave es de 16 bytes (128 bits)
    clave = clave.ljust(16)[:16].encode('utf-8')  # Rellenamos o recortamos a 16 bytes

    # Decodificamos el mensaje cifrado de base64
    mensaje_cifrado_bytes = base64.b64decode(mensaje_cifrado)

    # Configuramos el descifrado con AES en modo ECB
    cipher = Cipher(algorithms.AES(clave), modes.ECB(), backend=default_backend())
    decryptor = cipher.decryptor()

    # Desciframos el mensaje
    mensaje_descifrado_padded = decryptor.update(mensaje_cifrado_bytes) + decryptor.finalize()

    # Quitamos el padding del mensaje, para evitar errores con espacios en blanco.
    unpadder = padding.PKCS7(128).unpadder()
    mensaje_descifrado = unpadder.update(mensaje_descifrado_padded) + unpadder.finalize()

    return mensaje_descifrado.decode('utf-8')

def main():
    # Elegir si encriptar o desencriptar (if)
    accion = input("¿Deseas encriptar o desencriptar un mensaje? (e/d): ").lower()

    # Ingresar la clave y el mensaje
    clave = input("Ingresa la clave de 16 caracteres: ") #Siguiendo las pautas del modelo de encriptaci
    mensaje = input("Ingresa el mensaje: ")

    if accion == 'e':
        # Cifrar el mensaje
        mensaje_cifrado = cifrar_mensaje(mensaje, clave)
        print(f"Mensaje cifrado: {mensaje_cifrado}")
    elif accion == 'd':
        # Descifrar el mensaje
        mensaje_descifrado = descifrar_mensaje(mensaje, clave)
        print(f"Mensaje descifrado: {mensaje_descifrado}")
    else:
        print("Acción no válida. Debes elegir 'e' para encriptar o 'd' para desencriptar.")

if __name__ == '__main__': ## Esta es una variable especial en Python que contiene el nombre del módulo actual.
## "main": Es una cadena de texto que representa el nombre del módulo principal cuando un script se ejecuta directamente.
    main()

## el programa utiliza padding "PKCS7" para asegurarse de que el tamaño del mensaje sea un múltiplo de 16 bytes.
