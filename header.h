#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#pragma warning (disable:4996)

struct node {
	char filename[20];
	int num;
	struct node* next;
};
typedef struct node data; //데이터를 저장할 리스트

void findfile(); 
int searchstring(char *filename); //파일 내에서 문자열 검색
int ranking(char* filename, int count); //검색 결과를 리스트에 저장하고 순서를 나열

char word[20]; //검색할 문자열
data *head;//리스트의 시작