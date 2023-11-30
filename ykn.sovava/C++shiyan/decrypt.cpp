#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
//flag{Hell0!_Fr0m_Aur0r@B1nS3c_CSU}

static char buf[0x100];
static char key = 0x67;

// 全局常量定义
const char* base64char = "ZYXABCDEFGHIJKLMNOPQRSTUVWzyxabcdefghijklmnopqrstuvw0123456789+/";
//const char padding_char = '=';
//static unsigned char str[0x100];
//static char base64encode[0x100];
//static char buffer[0x1000];
static char cipher1[0x30] = { 48, 13, 18, 2, 48, 84, 22, 33, 48, 51, 18, 23, 45, 63, 36, 4, 40, 12, 33, 19, 30, 52, 95, 90 };
static unsigned int cipher2[0x30] = { 4082864189, 3674921777, 4033020472, 3157788679, 595834044, 659704428, 2321028455, 146270356, 3232710920, 3999809776, 1271388422, 3959914972, 348432882, 2599787200, 1784650661, 3358288901 };

void decode_base64(char* cipher, int* result) {
	for (int i = 0; i < 24; i++) {
		int j = 0;
		while (base64char[j++] != cipher[i]);
		cipher[i] = j - 1;
	}
	int j = 0;
	for (int i = 0; i < 24; i+=4) {
		result[j++] = (cipher[i] << 2) & 0b11111100 | (cipher[i + 1] >> 4) & 0b00000011;
		result[j++] = (cipher[i + 1] << 4) & 0b11110000 | (cipher[i + 2] >> 2) & 0b00001111;
		result[j++] = (cipher[i + 2] << 6) & 0b11000000 | cipher[i + 3] & 0b00111111;
		//printf("%d  ", result[j-1]);
	}

}
//解密函数
void decode(unsigned int* v, unsigned int const* k) {

	unsigned int v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i; /* set up */
	unsigned int delta = 0x9e3779b9;                   /* a key schedule constant */
	unsigned int k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3]; /* cache key */
	for (i = 0; i < 32; i++) {                     /* basic cycle start */
		v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
		v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		sum -= delta;
	}                                              /* end cycle */
	v[0] = v0;
	v[1] = v1;
}


int main() {
	
	int result[20];
	for (int i = 0; i < 24; i++) {
		cipher1[i] ^= key;
		//printf("%d ", cipher1[i]);
	}
	decode_base64(cipher1, result);
	for (int i = 0; i < 18; i++) {
		printf("%c", char(result[i]));
	}
	unsigned int v[2] = { 0,0 };
	unsigned int k[4] = { 2, 2, 3, 4 };
	for (int i = 0; i < 16; i +=2) {
		v[0] = cipher2[i],v[1] = cipher2[i + 1];
		decode(v, k);
		printf("%c%c", char(v[0]), char(v[1]));
	}
	printf("}");
	return 0;
	
	
}
