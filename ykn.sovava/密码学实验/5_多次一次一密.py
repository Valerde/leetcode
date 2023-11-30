
import binascii
ciphertexts = [
    "0d06275f404a196b1027397663303927594b506c3549074f1c542018510c364a3b425b580f0b3646216b412d0e265444286a",
    "11002351040b5a4355742b384579332546475b293804024f584a2e1958046f1e38474f1d034e2c03242345204b39154f3f6a",
    "1108345116025c061a262f32482d772f530e40222f5403581153264c47152c027d59465b074e3d573a244a2745753959686a",
    "3d0822121b4a4b4309382333457920294146092b2e410b5e58542f1846053f0339425744510b7e011e2257274b1018423c2b",
    "1b0c241942285c4817313e780379776278475a3f7c610643025c230940086f2838454d581f0a7c03212e54310a21114f6607",
    "101a23512003574115313378017b1e605443092d30484a4b0b492e025d132707384557134b63315473274b3a0c751c4a356a",
    "0a013551000f5c4859273f3549793660534f5f232956035e1d026c41550e2b4a2d594244470b294b3625043506753d0b3225",
    "591e39020a4a40490c74203958667560150c7d243d504a430b1d241455033b06240b57550e0b2f563638503d043b545c2e23",
    "1a017038420f41561c373e3345792e2f400e5d237c451941561d004c58012b137a580354064a394a3d2a503d043b5442356a",
    "0f0c22084218585610307176482d772a4043593f7c421845151d200859093d0b29424c534b5f31033f245231477512592927",
]
NUM_CIPHER = len(ciphertexts)#NUM_CIPHER=11
THRESHOLD_VALUE = 6#如果两两异或的结果为字母数大于7次，就认为该字符为空格,该值更改会影响最终结果

def strxor(a, b):
    #两个字符串的异或
    if len(a) > len(b):
        # 形成二元组，异或,返回新字符串
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len(b)], b)])
    else:
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b[:len(a)])])

def letter_position(s):
    #返回给定字符串中给定字母的位置
    position = []
    for idx in range(len(s)):
        #考虑到空格异或为0的情况可能较多
        if (s[idx] >= 'A' and s[idx] <= 'Z') or (s[idx] >= 'a' and s[idx] <= 'z') or s[idx] == chr(0):
            position.append(idx)
    return position

def find_space(cipher):
    #寻找空字符
    space_position = {}
    space_possible = {}
    #双重循环，每一条密文均与其他密文异或
    for cipher_idx_1 in range(NUM_CIPHER):
        space_xor = []#用于保存可能空格符对应的位置
        c = ''.join([chr(int(d, 16)) for d in [cipher[cipher_idx_1][i:i + 2] for i in range(0, len(cipher[cipher_idx_1]), 2)]])
        for cipher_idx_2 in range(NUM_CIPHER):
            #将十六进制字符串处理成对应ascii字符（每两个字符代表一个ascii符号）
            e = ''.join([chr(int(d, 16)) for d in [cipher[cipher_idx_2][i:i+2] for i in range(0, len(cipher[cipher_idx_2]), 2)]])
            plain_xor = strxor(c, e)
            if cipher_idx_2 != cipher_idx_1:
                # 记录明文中可能空格符的位置
                space_xor.append(letter_position(plain_xor))
        space_possible[cipher_idx_1] = space_xor  #形成三维列表,新列表为11*10*n

    #进一步判断已记录的位置是否为空字符，其准确性受到文本数量的影响
    for cipher_idx_1 in range(NUM_CIPHER):
        spa = []
        for position in range(400):
            count = 0
            for cipher_idx_2 in range(NUM_CIPHER - 1):
                if position in space_possible[cipher_idx_1][cipher_idx_2]:
                    count += 1
            if count > THRESHOLD_VALUE:  # 如果异或后字母出现次数大于7次，认为明文中此处为空格
                spa.append(position)
        space_position[cipher_idx_1] = spa  #构成二维列表，11 * n
    return space_position

#计算获得对应密钥Key
def calculate_key(cipher):
    key = [0] * 200  #存放key
    space = find_space(cipher)
    #print(space)
    for cipher_idx_1 in range(NUM_CIPHER):
        for position in range(len(space[cipher_idx_1])):
            idx = space[cipher_idx_1][position] * 2 #十六进制，用2位表示
            a = cipher[cipher_idx_1][idx] + cipher[cipher_idx_1][idx + 1]
            key[space[cipher_idx_1][position]] = int(a ,16) ^ ord(' ') # 计算密钥，获得结果十进制(ascii码）

    key_str = ""#空串用于存放密钥
    for k in key:
        key_str += chr(k)#转化为
    return key_str  #获得密钥串

result = ""
key = calculate_key(ciphertexts)
key_hex = ''.join([hex(ord(c)).replace('0x', '') for c in key])#十六进制key
print("key=",key)
print("key_hex=",key_hex)

f = ''.join([chr(int(d, 16)) for d in [ciphertexts[9][i:i+2] for i in range(0, len(ciphertexts[9]), 2)]])
for letter in strxor(f,key):
         if (letter>=' ' and letter<='~ '):#打印从32-126的可见字符
             result+=letter
         else:
             result+='0'#不可打印字符用0代替，以区别空格符
#print(result)

#打印所有密文对应的明文
for j in range(10):
    f = ''.join([chr(int(d, 16)) for d in [ciphertexts[j][i:i + 2] for i in range(0, len(ciphertexts[j]), 2)]])
    for letter in strxor(f,key):
         if (letter>=' ' and letter<='~ '):
             result+=letter
         else:
             result+='0'
    print(result)
    result = '' #将result清空，再次使用





#没办法的办法了_法解秘钥
import libnum
m="v0ry rapid  i  jumps frEm ldY0rasio` tm lov1, from"
m="very rapid  i  jumps from ldY0rasio` to love, from"
m="very rapid; it jumps from admiration to love, from"
c=0x0f0c22084218585610307176482d772a4043593f7c421845151d200859093d0b29424c534b5f31033f245231477512592927
cipher=hex(c^libnum.s2n(m))
print(cipher)
0x79695071626a392679544a5621595740352e294c5c246a2a783d416c34604f6a5d2b233d6b2b5e23534b24546b55742b464a
