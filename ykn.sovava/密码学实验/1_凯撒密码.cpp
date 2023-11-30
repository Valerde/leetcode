#include<iostream>
#include<string>
using namespace std;
//char str[510] = "A fwnwj af eq daxw kso sfqlzafy egjw wdwysfl lzsf lzwaj vjwkkwk. A vsjw ksq lzw dsuw mhgf Ejk. Zmjkl'k ygof--\"  Zwjw kzw osk aflwjjmhlwv sysaf. Ej. Twffwl hjglwklwv sysafkl sfq vwkujahlagf gx xafwjq. Kzw osk lzwjwxgjw gtdaywv lg kwwc sfglzwj tjsfuz gx lzw kmtbwul, sfv jwdslwv, oalz emuz tallwjfwkk gx khajal sfv kgew wpsyywjslagf, lzw kzgucafy jmvwfwkk gx Ej. Vsjuq.  \"Tml A usf skkmjw qgm,\" kzw svvwv, \"lzsl Darrq vgwk fgl dgkw emuz tq fgl kmalafy _zak_ xsfuq; xgj zw ak s egkl vaksyjwwstdw, zgjjav esf, fgl s";
int main(void) {
	//	char str[100]="\"Pi! tipdljoh!\" dsjfe Njtt Cjohmfz. \"J ofwfs ifbse bozuijoh tp bcpnjobcmf. Ipx tibmm xf qvojti ijn gps tvdi b tqffdi?\"  \"Opuijoh tp fbtz, jg zpv ibwf cvu uif jodmjobujpo,\" tbje Fmjabcfui. \"Xf dbo bmm qmbhvf boe qvojti pof bopuifs. Ufbtf ijn--mbvhi bu ijn. Joujnbuf bt zpv bsf, zpv nvtu lopx ipx ju jt up cf epof.\"  \"Cvu vqpo nz ipopvs, J ep _opu_. J ep bttvsf zpv uibu nz joujnbdz ibt opu zfu ubvhiu nf _uibu_. Ufbtf dbmnoftt pg nboofs boe qsftfodf pg njoe! Op, op; J gffm if nbz efgz vt uifsf. Boe bt up mbvh";
	string str = "V kmjhdnz ja nzxmzxt rvn ja xjpmnz qzmt ypodapggt bdqzi, wpo do xjpgy ijo wz fzko rdocjpo ydaadxpgot; ajm ocz xpmdjndot zsxdozy wt cdn gjib vwnzixz wpmno ajmoc di npxc qzmt ydmzxo lpznodjin ji cdn mzopmi vn mzlpdmzy njhz dibzipdot oj zqvyz, viy cz rvn vo ocz nvhz odhz zszmxdndib bmzvo nzga-yzidvg, ajm cz rvn gjibdib oj kpwgdnc cdn kmjnkzmjpn gjqz.  Vn cz rvn oj wzbdi cdn ejpmizt ojj zvmgt ji ocz hjmmjr oj nzz vit ja ocz avhdgt, ocz xzmzhjit ja gzvqz-ovfdib rvn kzmajmhzy rczi ocz gvydzn hjqzy ajm ocz idbco;";

	int i = 0, j = 1, key;
	cin >> key;
	while (key == 1 && j < 26) {
		while (str[i] != '\0') {
			if (str[i] >= 'a' && str[i] <= 'z')
				cout << char((str[i] - 'a' + j) % 26 + 'a');
			else if ((str[i] >= 'A' && str[i] <= 'Z'))
				cout << char((str[i] - 'A' + j) % 26 + 'A');
			else
				cout << str[i];
			i++;
		}
		j++;
		i = 0;
		cout << endl;
		cin >> key;
	}
	return 0;
}