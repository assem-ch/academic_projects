#!python

import Image
import sys

 
encoding = {
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
    '1': '.----',
    '2': '..---',
    '3': '...--',
    '4': '....-',
    '5': '.....',
    '6': '-....',
    '7': '--...',
    '8': '---..',
    '9': '----.',
    '0': '-----',
    # Seen in use on the uncyclopedia:
    "'": '.----.' }

decoding = {'---': 'O', '--.': 'G', '-....': '6', '-..-': 'X', '.-.': 'R', '--.-': 'Q', '--..': 'Z', '.--': 'W', '..---': '2', '.-': 'A', '..': 'I', '-.-.': 'C', '..-.': 'F', '-.--': 'Y', '-': 'T', '.': 'E', '.-..': 'L', '...': 'S', '..-': 'U', '.----': '1', '-----': '0', '-.-': 'K', '-..': 'D', '----.': '9', '.---': 'J', '.--.': 'P', '....-': '4', '--': 'M', '---..': '8', '-.': 'N', '....': 'H', '.----.': "'", '...-': 'V', '--...': '7', '.....': '5', '...--': '3'}

#decoding = {}
#for key, val in encoding.items(): decoding[val] = key

def encode(text):
    # should really pre-process {'.': 'stop', ',': 'comma', '-': 'dash', ...}
    return ' '.join(map(lambda x, g=encoding.get: g(x, ' '), text.upper()))

def decode(message):
    ans = ''.join(map(lambda x, g=decoding.get: g(x, ' '), message.split(' ')))
    return ' '.join(ans.split()) # tidy up spacing

def decipher(message):
    # like decode, but when there are no spaces.
    row = [ ('', message) ]
    while filter(lambda x: x[1], row):
        old = row
        row = []
        for it in old:
            txt, code = it
            if code:
                for (t, c) in encoding.items():
                    if code[:len(c)] == c:
                        row.append((txt + t, code[len(c):]))
                # NB we discard it if no initial segment of code matches an encoding.
            else: row.append(it)

    return map(lambda it: it[0], row)
    
def decode_(text):
	part = ""
	res = ""	
	for ch in text:
		if ch == " ":
			res += decoding[part]
			part = ""
		elif ch == "/":
			res += " "
		else:
			part += ch	
		
	return res
    


#open image 
im = Image.open(sys.argv[1], "r");
#print im.getcolors();

x0 = -1;str0 = "";first = True;
for y in range(0, 30):
    for x in range(0, 100):
        x0 += 1;
        pix = im.getpixel((x, y))
        if (pix == 1):
			 ch = chr(x0)
			 str0 += chr(x0)
			 x0 = 0;
		


for k in encoding:
	decoding[encoding[k]] = k

print str0
print decode(str0).lower();
print decode_(str0)


