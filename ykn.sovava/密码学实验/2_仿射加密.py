import gmpy2
str='yemcbumeyv fvmqjomyem.befmzytcbzdmcjgmiffzm,zyqzmbzmcfvteyvgucbvfmistmqcjtmcfmty.gmcb uf.elmjumtymcbumvfj.mhcjvjhtfvkmcjgmbzeyv jtbyzmiffzmbzmcfvmxyqfvkmucfmcjgmzfrfvmef.tmjmqbucmyembzwsbvbzdlmcbumhysztfzjzhfkmrybhfkmjzgm jzzfvmcjgmfutji.bucfgmcb mjtmyzhfmbzmtcfmxyuufuubyzmyemfrfvomrbvtsflmucfmtvbfgmtymvfhy..fhtmuy fmbzutjzhfmyemdyygzfuukmuy fmgbutbzdsbucfgmtvjbtmyembztfdvbtomyvmifzfry.fzhfkmtcjtm bdctmvfuhsfmcb mevy mtcfmjttjh,umyem vlmgjvho;myvmjtm.fjutkmiomtcfmxvfgy bzjzhfmyemrbvtsfkmjtyzfmeyvmtcyufmhju'

lenstr=len(str)
C=[]
P=[]
def printff():
	for an in range(0,500):
		if P[an]==26 and P[an+1]==(ord('h')-97) and P[an+2]==(ord('e')-97) and P[an+3]==26:
			for j in P:
				if j==26:
					print(' ',end="")
				elif j==27:
					print('.',end="")
				elif j==28:
					print(',',end="")
				else:
					print(chr(j+97),end="")
			print('\n')

for i in range(len(str)):
	if 'a'<=str[i]<='z':
		C.append(ord(str[i])-97)
	elif str[i]==' ':
		C.append(26)
	elif str[i]=='.':
		C.append(27)
	else:   #######注意不要在最后用elif############################
		C.append(28)

count=0
for b in range(0,29):
	for a in range(2,29):
		count=0		
		nia=gmpy2.invert(a,29)
		for c in C:
			P.append(((c-b)*nia)%29)
		for c in P:
			if c==(ord('e')-97):
				count+=1
		if count/lenstr>0.08:
			printff()
		P.clear()
