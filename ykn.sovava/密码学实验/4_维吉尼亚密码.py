import gmpy2
str=' khdswgcc mmmw qgw bdueyqww gwkqddy mgm zl ykd mexxlcww; tnr zx bggrhfncc mm simkgzgrw dnj yagnr s otskrdj me tl zhsq.    Vfzhmcq 14   Btjblf wgmfxp, Fp. Ucmfxr kvyquxjx lnncx zl ykd; amm vzxl lac kxpusgrr pcqw uhlabqspl, ac lamtyar am safc lh gsoc khkd vmmnxprsmgnf uhla gal fmxqs, ymv rgwkcegkc kmyqlxb s qttccbl gm pfhua gw cwhxasww gaf sg qgagc, uw guqdjogmy rgsm gw qdwfcc ocqq dnjmsmsmc ag gal osmpnfxqr. Jzvr Bsmfdjbld wc Thsqya\'r trswgrhgg sg fhk uhkacr, ymv anflgcwkysahl xhp zbq uhkegkr, tnowtpdv tdjr qwfyqctzkw. Lj. Awgldl anmeb fhr zttd vfnkxl txrswk. Ek. Uhjkagq otq wempmxls bl zxp hkyhkx. Lac knziwvr wecusmcc agl mm ehpd mfzf srmtj khjdeggsq me fymfxp, tlc pgsz y ehqs bkogkrzfm zkicbl fd ipnlxqsww sztr "ac ztb fxtdj gm agr egew uhlgcrkxb knag ucgsognmk hf y hxprgg nx pzfd--knag tdesugkamw sgb uhlcwladflgnf, zk fd ayc aglkxje xvowkgdfvcc ypne Jzvr Bsmfdjbld. Qgw fzv zdwg fjtahgnqkq nkwtqdv rn tnojhtd hd thrg hd lac vbqbgnprwl vzbag ac ztb sepdsww ztb lac zhlnmk nx nqwtagage txdnjx gwk. Kac ztb seqn tq'

STR=[]
middle=[]
count_same_len=ji=i=OK=j=k=jj=0
distance=[]
while i<(len(str)):#最外层循环
    j=i
    while j<(len(str)-len(STR)):#计算重叠
        for k in range(len(STR)):#
            if STR[k]==str[j+k]:
                count_same_len+=1
            else:
                break
        if count_same_len==len(STR) and len(STR)!=0 and len(STR)!=3 and len(STR)!=2:
            distance.append(j-jj)
        j=j+k+1
        count_same_len=0
    STR.clear()
    ii=i
    while ii<len(str):
        if str[ii]==' ':
            STR.append(str[ii])
            ii+=1
            while ii<len(str) and str[ii]!=' ':
                STR.append(str[ii])
                ii+=1
            STR.append(' ')
            break
    jj=ii-len(STR)+1
    i=ii
##########
dis=distance[0]
for i in range(len(distance)):
    dis=gmpy2.gcd(dis,distance[i])
print(dis)

def count(pingxing):
    CountLetter=[0 for x in range(0,26)]
    countlen=0
    IC=0
    for i in range(len(pingxing)):
        if 'a' <= pingxing[i] <='z':
            CountLetter[ord(pingxing[i])-97]+=1
            countlen+=1
        elif 'A'<=pingxing[i]<='Z':
            CountLetter[ord(pingxing[i])-65]+=1
            countlen+=1
        else:
            continue
    for i in range(0,26):
        IC+=(CountLetter[i]-1)*CountLetter[i]/(countlen*(countlen-1))
    if 0.06<=IC<=0.07:
        print("IC",IC)
        return 1
    CountLetter.clear()
    return 0
i=0
j=0
pingxing=[]
yiwei=[]
A=[]
for l in range(1,dis):
    if dis%l==0:
        A.append(dis//l)

for k in A:
    j=0
    print("A",k)#k表示平行移位数
    for i in range(0,k):#i表示pingxing的第一个字母来自str第几个
        j=0
        while j+i < len(str):
            pingxing.append(str[i+j])
            j=j+k
        #print(pingxing)
        ou = count(pingxing)
        if ou==1:
            print(k)
            OK=k
        pingxing.clear()
count_ch=[]
def count_change(OK):
    for i in range(OK):
      
        for j in range(1,26):
           countlen=0
           middle=[0 for x in range(0,26)]
           k=i
           while k <len(str):
               if 'a'<=str[k]<='z':
                  middle[((ord(str[k])-97+j)%26)]+=1
                  countlen+=1
               elif 'A'<=str[k]<='Z':
                   middle[((ord(str[k])-65+j)%26)]+=1
                   countlen+=1
               else:
                    pass
               k+=OK
           if middle[4]/countlen>0.12:
                count_ch.append(j)
               
count_change(OK)
print(count_ch)

for i in range(len(str)):
    if 'a'<=str[i]<='z':
        print(chr((ord(str[i])-97+count_ch[i%len(count_ch)])%26+97),end="")
    elif 'A'<=str[i]<='Z':
        print(chr((ord(str[i])-65+count_ch[i%len(count_ch)])%26+65),end="")
    else:
        print(str[i],end="")
print("\n")
for i in count_ch:
    print(chr(ord('a')+26-i),end="")
print("\n")
   






