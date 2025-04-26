import numpy as np
from numpy.linalg import inv
from sympy import Matrix

def getKeyMatrix(key, n):
    keyMatrix = [[0] * n for _ in range(n)]
    k = 0
    for i in range(n):
        for j in range(n):
            keyMatrix[i][j] = ord(key[k]) % 65
            k += 1
    return keyMatrix

def isValidKeyMatrix(keyMatrix):
    determinant = int(np.round(np.linalg.det(keyMatrix))) % 26
    if determinant == 0 or np.gcd(determinant, 26) != 1:
        return False
    return True

def printMatrix(matrix):
    for row in matrix:
        print(" ".join(str(x) for x in row))

def decrypt(cipherText, inverseKeyMatrix, n):
    decryptedText = []
    for i in range(0, len(cipherText), n):
        cipherVector = [ord(cipherText[j]) % 65 for j in range(i, i + n)]
        cipherVector = np.reshape(cipherVector, (n, 1))
        decryptedMatrix = np.dot(inverseKeyMatrix, cipherVector) % 26
        decryptedText.extend([chr(int(decryptedMatrix[j][0]) + 65) for j in range(n)])
    return ''.join(decryptedText)

def encrypt(message, keyMatrix, n):
    cipherText = []
    for i in range(0, len(message), n):
        messageVector = [ord(message[j]) % 65 for j in range(i, i + n)]
        messageVector = np.reshape(messageVector, (n, 1))
        cipherMatrix = np.dot(keyMatrix, messageVector) % 26
        for j in range(n):
            cipher_char = chr(int(cipherMatrix[j][0]) + 65)
            cipherText.append(cipher_char)  
    return ''.join(cipherText)

def HillCipher(message, key):
    n = int(len(key) ** 0.5)
    if n * n != len(key):
        print("Invalid key length. Key length must be a perfect square (e.g., 4, 9, 16).")
        return

    keyMatrix = getKeyMatrix(key, n)

    print("Key Matrix:")
    printMatrix(keyMatrix)

    if not isValidKeyMatrix(keyMatrix):
        print("Invalid key matrix. The matrix is not invertible or not relatively prime to 26.")
        return

    while len(message) % n != 0:
        message += 'X'

    cipherText = encrypt(message, keyMatrix, n)
    print("Ciphertext: ", cipherText)

    # Calculate the inverse key matrix in mod 26
    mod_inv_matrix = Matrix(keyMatrix).inv_mod(26)
    invMatrix = np.array(mod_inv_matrix).astype(int)

    ogmessage = decrypt(cipherText, invMatrix, n)
    print("OG Message: ", ogmessage)

if __name__ == "__main__":
    message = input("Enter the message: ").upper()
    key = input("Enter the key (length must be a perfect square): ").upper()
    HillCipher(message, key)
