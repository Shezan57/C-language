#include <stdio.h>
#include <stdlib.h>

int HashValue(char key, int * flag, int size) {
	// transform the key into a number, 'a' is 0, 'b' is 1  and so on.

	int key_value = key - 'a';
	int position = key_value % size;

	// hash fuction H(x) = x % size

	if(flag[position] == 0){
		flag[position] = 1;
		return position;
	}

	// use linear probing to deal with collision
	int i = 1;
	while(flag[(position+i)%size] != 0){
		i++;
	}
	flag[(position + i) % size] = 1;
	return (position + i) % size;
	
}

void HashLinear(char ** strs, int total, int size) {
	int * flag = (int *)malloc(sizeof(int) * size);
	int i;
	for (i = 0; i < size; i++) {
		flag[i] = 0;
	}
	for (i = 0; i < total; i++) {
		int value = HashValue(strs[i][0], flag, size);
		if (value != -1) {
			printf("%s: %d\n", strs[i], value);
		}
		else {
			printf("The table is full!\n");
			break;
		}
	}
	free(flag);
}

int main() {
	char * strs[10];
	strs[0] = "acos";
	strs[1] = "char";
	strs[2] = "ceil";
	strs[3] = "atan";
	strs[4] = "define";
	strs[5] = "floor";
	strs[6] = "clock";
	strs[7] = "float";
	strs[8] = "ctime";
	strs[9] = "exep";

	HashLinear(strs, 10, 26);

	return 0;
}