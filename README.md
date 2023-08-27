# Caesar Cipher
This is a C language program that takes in a password and encrypts and decrypts a files.
It takes a password for verification and forms a key for the process.

## Variations:
    Library
    
    No Library
    
## Concepts Used:
    File handeling
    
    Bit Manipulation
    
    Static Library Building

## Design is as follows:
It includes 3 major functions ie as follows:
```c
    encrypt()

    decrypt()

    PasswordMatching/Key generator
``` 
It uses a simple Caesar Cypher method in which the alphabets used are shifted to encrypt/decrypt the text.

The user is asked for a Password which is then matched with the valid passwords provided in the file.

If the password is correct then the associated key is returned.

Then the keyis used for encrypting/decrypting the given file into the destination file as specified by the user.
