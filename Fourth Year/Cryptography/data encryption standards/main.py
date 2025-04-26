from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

def generate_round_keys(key):
    # Permuted Choice 1 (PC-1) permutation
    pc1 = [57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2,
           59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39,
           31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37,
           29, 21, 13, 5, 28, 20, 12, 4]

    # Permuted Choice 2 (PC-2) permutation
    pc2 = [14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4,
           26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40,
           51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32]

    # Rotate the key
    def rotate_left(key, n):
        return key[n:] + key[:n]

    # Convert the key to a 64-bit binary string
    key_bits = ''.join(format(byte, '08b') for byte in key)

    # Apply the PC-1 permutation
    key = [key_bits[j-1] for j in pc1]

    # Generate the round keys
    round_keys = []
    left, right = key[:28], key[28:]
    for i in range(16):
        if i in [1, 2, 9, 16]:
            left = rotate_left(left, 2)
            right = rotate_left(right, 2)
        else:
            left = rotate_left(left, 1)
            right = rotate_left(right, 1)
        round_key = left + right
        round_key = [round_key[j-1] for j in pc2]
        round_keys.append(''.join(round_key))

    return round_keys

def des_encrypt(plain_text, key):
    # Generate the round keys
    round_keys = generate_round_keys(key)

    # Create a DES cipher object with the key
    cipher = DES.new(key, DES.MODE_ECB)
    
    # Pad the plain text to a multiple of the block size
    padded_data = pad(plain_text.encode(), DES.block_size)
    
    # Encrypt the padded plain text
    encrypted_data = cipher.encrypt(padded_data)
    
    return encrypted_data

def des_decrypt(encrypted_data, key):
    # Generate the round keys
    round_keys = generate_round_keys(key)

    # Create a DES cipher object with the key
    cipher = DES.new(key, DES.MODE_ECB)
    
    # Decrypt the encrypted data
    decrypted_padded_data = cipher.decrypt(encrypted_data)
    
    # Unpad the decrypted data
    decrypted_data = unpad(decrypted_padded_data, DES.block_size)
    
    return decrypted_data.decode()

# The key must be 8 bytes long
key = b'\x01\x02\x03\x04\x05\x06\x07\x08'

plain_text = input("Enter plain text: ")

encrypted_data = des_encrypt(plain_text, key)

decrypted_data = des_decrypt(encrypted_data, key)

print("Encrypted Data:", encrypted_data.hex())
print("Decrypted Data:", decrypted_data)

