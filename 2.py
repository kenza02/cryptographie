from pypresent import Present
import Padding

text = input("Enter the plaintext: ")
k = int(input("Enter the key (as an integer): "))

text = Padding.appendPadding(text, blocksize=8, mode='CMS')

print('Text:\t', text)
print('Key:\t', k)
print('--------')

key = k.to_bytes(10, byteorder='big')
cipher = Present(key)

encrypted = cipher.encrypt(text.encode())
print('Cipher:\t\t', encrypted.hex())

decrypted = cipher.decrypt(encrypted)
print('Decrypted:\t', decrypted.hex())
print('Decrypted:\t', Padding.removePadding(decrypted.decode(), blocksize=8, mode='CMS'))
