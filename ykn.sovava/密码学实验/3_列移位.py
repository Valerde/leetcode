str=' r bmyey taumgoo sse  ge d e sd. ni  enhcrs .ceeo .hop  ew ru  b i metfa s fgeIa dyc t" rt ue a piom eectye"vtyahudm Mo ftpt  etaRCihw xIvsenfenxfhooiYeosrasdeoyril phiophbeoe apcfeaa  nopu  uno  e tarrf  tydeasftalaldwrue  irtettrsac gumflc lee rb  oat  atill imzewhd hn, ea oo  elfoy slceeater uyn sliEttzdhi tec hslwnfom a,uoosyoalrhs mnocthynlhhliatco oIos av nult sufe usiee tywuehm,si ,entha fu w iyiiesetmir swroe sno or,ee ,zs  g enyork mn nt.taeyn m osnvbeo hr   nM"ao"mlIr oranty acs" vr ,ryiresir:tmataoet'

lenstr=len(str)
for a in range(3,13):
    if lenstr%a==0:
        for j in range(0,len(str)//a):
            for i in range(0,a):
                print(str[j+lenstr//a*i],end="")
        print('#end\n')
