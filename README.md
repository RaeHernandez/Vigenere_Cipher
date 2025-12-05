# Vigenère Cipher Encryption-Decryption App

## Overview

This C++ console application implements the **Vigenère cipher**, a classical encryption algorithm. It allows users to **encrypt plaintext messages** into ciphertext and **decrypt ciphertext** back to plaintext using a secret key.

The project demonstrates **encryption logic, string manipulation, and algorithm implementation**, core skills in **security engineering**.

## Relevance to Security Engineering

* **Encryption/Decryption Logic:** Understanding how data can be transformed and reversed securely is fundamental in protecting sensitive information.
* **Cryptography Foundations:** Classical ciphers like Vigenère provide insight into key management, modular arithmetic, and character encoding, essential for modern cryptography.
* **Algorithm Implementation:** Translating cryptographic algorithms into functional code demonstrates practical skills that extend to secure application development and secure coding practices.
* **Security Mindset:** Handling keys and analyzing cipher patterns helps develop analytical skills for identifying vulnerabilities in real-world systems.

## How the Algorithm Works

### Encryption

1. Each letter in the plaintext is first converted to a number using its **ASCII value** (`'A' = 0`, `'B' = 1`, ..., `'Z' = 25`).
2. The key is repeated to match the length of the plaintext.
3. Each plaintext character is **shifted by the corresponding key character** using modular arithmetic:
   [
   \text{cipherChar} = (\text{plainChar} + \text{keyChar}) \mod 26
   ]
4. The result is converted back to a capital letter using ASCII.

### Decryption

1. Each ciphertext character is converted to a number (`'A' = 0`, etc.).
2. Using the same repeated key, each ciphertext character is **shifted back**:
   [
   \text{plainChar} = (\text{cipherChar} - \text{keyChar} + 26) \mod 26
   ]
3. The result is converted back to a letter to recover the original plaintext.

> The `+26` in decryption ensures we avoid negative numbers when subtracting the key value.

### Example

```
Plaintext: HELLO
Key: KEY
Ciphertext: RIJVS
Decryption recovers: HELLO
```

## Code Snippet

Core Vigenère encryption/decryption logic:

```cpp
string vigenere(string text,string key,bool EncDec) {
    string newkey = key, newtext;
    // Repeat key until it matches text length
    while(newkey.length()<text.length())
    {
        newkey+=key;
    }
    if (EncDec==0)
    {
        // Encryption
        for(int i = 0; i < text.length(); i++) 
        {
            newtext+=(text[i] + newkey[i])%26 + 65;
        }

    }else{
        // Decryption
        for(int i = 0; i < text.length(); i++) 
        {
            newtext+=(text[i] - newkey[i] + 26)%26 + 65;
        }
    }
    return newtext;

}
```

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/RaeHernandez/Vigenere_Cipher.git
   ```
2. Compile the source code:

   ```bash
   g++ VigenereApp.cpp -o vigenere
   ```
3. Run the application:

   ```bash
   ./vigenere
   ```
4. Follow the prompts to encrypt or decrypt messages.


## Demo

Below is a screenshot showing the application encrypting and decrypting a message in the terminal:

![Vigenère Cipher Terminal Demo](terminal_demo.png)

## Repository Structure

```
Vigenere_Cipher/
├─ VigenereApp.cpp     # main encryption/decryption application
├─ snippets.png        # demo run
└─ README.md           # project description
```

