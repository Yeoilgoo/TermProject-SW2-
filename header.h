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
typedef struct node data; //�����͸� ������ ����Ʈ

void findfile(); 
int searchstring(char *filename); //���� ������ ���ڿ� �˻�
int ranking(char* filename, int count); //�˻� ����� ����Ʈ�� �����ϰ� ������ ����

char word[20]; //�˻��� ���ڿ�
data *head;//����Ʈ�� ����