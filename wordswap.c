#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define STRING_LENGTH 300
#define STRING_WORDS_NUMBER 30
#define WORD_LENGTH 10

char* ltrim(char* p){
	char* res = (char*)malloc(STRING_LENGTH);
	strcpy(res, "");

	int length = strlen(p);

	for(int i=0; i<length; i++){
		if(!isspace(p[i])){
			int j = 0;
			while(i<length){
				res[j++] = p[i++];
			}
			res[i] = 0;
			break;
		}
	}

	return res;
}

char* rtrim(char* p){
	char* res = (char*)malloc(STRING_LENGTH);
	strcpy(res, "");

	int length = strlen(p), ei, i;

	for(int i=length - 1; i>=0; i--){
		if(!isspace(p[i])){
			ei = i;
			break;
		}
	}

	for(i=0; i<=ei; i++){
		res[i] = p[i];
	}

	res[i] = 0;

	return res;
}

char* trim(char* p){
	char* res = (char*)malloc(STRING_LENGTH);
	int length = strlen(p);
	int space = 1, i, j;

	for(i=0, j=0; i<length; i++){
		if(!space || !isspace(p[i])){
			res[j++] = p[i];
		}

		space = isspace(p[i]);
	}

	if(isspace(res[j-1])){
		res[j-1] = 0;
	}else{
		res[j] = 0;
	}

	return res;
}


char* strstrpos(char* p, int si, int ei){
	char* rs = malloc(STRING_LENGTH);
	strcpy(rs, "");

	int length = strlen(p);
	if(si <= length && ei <= length){
		for(int i=si, j=0; i<=ei; i++, j++){
			rs[j] = p[i];
		}
	}

	return rs;
}

char* strsubstr(char* p, int si, int l){
	int ei = si + l - 1;

	return strstrpos(p, si, ei);
}


int indexofspace(char* p, int s){
	int length = strlen(p);

	for(int i=s; i<length; i++){
		if(isspace(p[i])){
			return i;
		}
	}

	return -1;
}

int indexofnonspace(char* p, int s){
	int length = strlen(p);

	for(int i=s; i<length; i++){
		if(!isspace(p[i])){
			return i;
		}
	}

	return -1;
}

int CountWords(char* ps){
	char* p = trim(ps);
	int c = 0;

	int length = strlen(p);
	int bs = 0;
	if(length){
		for(int i=0; i<length; i++){
			if(p[i] == 32 && !bs){
				c += 1;
				bs = 1;
			}else{
				if(p[i] != 32){
					bs = 0;
				}
			}
		}

		return c + 1;
	}else{
		return 0;
	}
}

char* WordSwap(char* str){
	if(CountWords(str) < 4){
		return "Invalid";
	}
	char* res = (char*)malloc(STRING_LENGTH);
	char* p = trim(str);
	char** wordsarray = (char**)malloc(STRING_WORDS_NUMBER * sizeof(char*));

	int length = strlen(p);

	int wordindex = 0;

	int ei = 0, si = 0;

	while(ei < length){
		si = indexofnonspace(p, ei);
		ei = indexofspace(p, si);

		if(ei == -1){
			ei = length;
			wordsarray[wordindex++] = strstrpos(p, si, ei - 1);
			break;
		}else{
			wordsarray[wordindex++] = strstrpos(p, si, ei - 1);
		}
	}


	char* im = wordsarray[1];
	wordsarray[1] = wordsarray[wordindex - 2];
	wordsarray[wordindex - 2] = im;

	strcpy(res, "");

	for(int i = 0; i<wordindex - 1; i++){
		strcat(res, wordsarray[i]);
		strcat(res, " ");
	}

	strcat(res, wordsarray[wordindex - 1]);

	return res;
}
