void probFundamental1() {
	int x;
	int* p;

	p = &x;
	*p = 12;

	printf("%d\n", x);
}

void probFundamental2() {
	char str[] = "hello world";

	// ポインタを使用して 'h' と 'w' を大文字にする
	char* p = str;
	*p = toupper(*p);     // 'h' を大文字に変更

	p += 6;               // ポインタを6文字目に移動
	*p = toupper(*p);     // 'w' を大文字に変更

	printf("%s\n", str);
}

void probFundamental3() {
	int arrayInt[] = {12, 43, 23, 91, 74, 3, 15, 23, 9, 31};
	int sizeArray = sizeof(arrayInt) / sizeof(arrayInt[0]);
	int* instance = arrayInt + sizeArray - 1;

	for (int i = 0; i < sizeArray; i++) {
		printf("%d ", *(instance));
		instance -= 1;
	}
	printf("\n");
}
