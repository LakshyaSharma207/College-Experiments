def encrypt(text, key):
    rail = [['*' for _ in range(len(text))] for _ in range(key)]
    
    direction = True  # True means moving down, False means moving up
    row, col = 0, 0
    
    for char in text:
        rail[row][col] = char
        col += 1
        
        if row == 0:
            direction = True
        elif row == key - 1:
            direction = False
        
        if direction:
            row += 1
        else:
            row -= 1
    
    result = ''
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] != '*':
                result += rail[i][j]
    
    return result

def decrypt(cipher, key):
    if key <= 0:
        raise ValueError("Key must be a positive integer")

    rail = [['\n' for _ in range(len(cipher))] for _ in range(key)]
    
    direction = True
    row, col = 0, 0
    
    for _ in range(len(cipher)):
        rail[row][col] = '*'
        col += 1
        
        if row == 0:
            direction = True
        elif row == key - 1:
            direction = False
        
        if direction:
            row += 1
        else:
            row -= 1
    
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if rail[i][j] == '*' and index < len(cipher):
                rail[i][j] = cipher[index]
                index += 1
    
    result = ''
    direction = True
    row, col = 0, 0
    
    for _ in range(len(cipher)):
        if rail[row][col] != '\n':
            result += rail[row][col]
        col += 1
        
        if row == 0:
            direction = True
        elif row == key - 1:
            direction = False
        
        if direction:
            row += 1
        else:
            row -= 1
    
    return result


if __name__ == "__main__":
    text = input("Text: ")
    key = int(input("Key: "))
    
    if key < 1:
        print("Key must be at least 1.")
    else:
        cipher = encrypt(text, key)
        print("Encrypted:", cipher)
        
        decrypted_text = decrypt(cipher, key)
        print("Decrypted:", decrypted_text)
        
