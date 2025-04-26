def encrypt(text, shift):
    result = ""
    
    for i in range(len(text)):
        char = text[i]
        
        if (char.isupper()):
            result += chr((ord(char) + shift - 65) % 26 + 65)

        else:
            result += chr((ord(char) + shift - 97) % 26 + 97)
        
    return result
        
if __name__=="__main__":
    text = input("Text: ")
    shift = int(input("Shift: "))
    cipher = encrypt(text, shift)
    print("Cipher: " + cipher)
    print("Decrypt: " + encrypt(cipher, -shift))