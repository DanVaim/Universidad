from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import padding
import os

# Función para encriptar el archivo PDF
def encriptar_pdf(input_pdf_path, output_pdf_path, key):
    # Asegurarse de que la clave tenga 16 bytes (128 bits)
    key = key.ljust(16, '\0').encode('utf-8')  # Rellenamos con ceros si es más corta

    # Abrir el archivo PDF original
    with open(input_pdf_path, 'rb') as file:
        data = file.read()

    # Asegurarse de que el tamaño de los datos sea un múltiplo de 16 bytes
    padder = padding.PKCS7(128).padder()
    padded_data = padder.update(data) + padder.finalize()

    # Configurar el cifrador AES con ECB
    cipher = Cipher(algorithms.AES(key), modes.ECB(), backend=default_backend())
    encryptor = cipher.encryptor()

    # Encriptar los datos
    encrypted_data = encryptor.update(padded_data) + encryptor.finalize()

    # Guardar el archivo encriptado
    with open(output_pdf_path, 'wb') as encrypted_file:
        encrypted_file.write(encrypted_data)

# Clave fija '271t17' para AES-128 (se rellena con ceros para hacerla de 16 bytes)
key = '271t17'

# Rutas de los archivos
input_pdf = 'Evaluacion #2.pdf'  # Cambia por tu archivo PDF
encrypted_pdf = 'Evaluacion #2 encriptada.pdf'

# Encriptar el archivo PDF
encriptar_pdf(input_pdf, encrypted_pdf, key)
print(f'Archivo encriptado guardado como: {encrypted_pdf}')


#### ---------------------------------- #####
#### DESENCRIPTAR EL ARCHIVO ENCRIPTADO #####
#### ---------------------------------- #####


# from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
# from cryptography.hazmat.backends import default_backend
# from cryptography.hazmat.primitives import padding

# # Función para desencriptar el archivo PDF
# def desencriptar_pdf(input_pdf_path, output_pdf_path, key):
#     # Asegurarse de que la clave tenga 16 bytes (128 bits)
#     key = key.ljust(16, '\0').encode('utf-8')  # Rellenamos con ceros si es más corta

#     # Abrir el archivo PDF encriptado
#     with open(input_pdf_path, 'rb') as file:
#         encrypted_data = file.read()

#     # Configurar el cifrador AES con ECB
#     cipher = Cipher(algorithms.AES(key), modes.ECB(), backend=default_backend())
#     decryptor = cipher.decryptor()

#     # Desencriptar los datos
#     decrypted_data = decryptor.update(encrypted_data) + decryptor.finalize()

#     # Deshacer el padding de los datos
#     unpadder = padding.PKCS7(128).unpadder()
#     unpadded_data = unpadder.update(decrypted_data) + unpadder.finalize()

#     # Guardar el archivo desencriptado
#     with open(output_pdf_path, 'wb') as decrypted_file:
#         decrypted_file.write(unpadded_data)

# # Clave fija '271t17' para AES-128 (se rellena con ceros para hacerla de 16 bytes)
# key = '271t17'

# # Rutas de los archivos
# input_pdf = 'Evaluacion #2 encriptada.pdf'  # Cambia por tu archivo PDF encriptado
# decrypted_pdf = 'Evaluacion #2 desencriptado.pdf'

# # Desencriptar el archivo PDF
# desencriptar_pdf(input_pdf, decrypted_pdf, key)
# print(f'Archivo desencriptado guardado como: {decrypted_pdf}')

# # https://cryptography.io/en/latest/glossary/ <- Documentación de criptography