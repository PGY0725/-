#define  _CRT_SECURE_NO_WARNINGS
#include"student.h"
Node* headNode()
{
	Node* list = (Node*)malloc(sizeof(Node));
	if (!list)
	{
		return NULL;
	}
	list->next = NULL;
	return list;
}

//�����ڵ�
Node* setNode(char id[10], char name[10], int age, char ban[10],int score)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode)
	{
		return NULL;
	}
	strcpy(newNode->student.id, id);
	strcpy(newNode->student.name, name);
	newNode->student.age = age;
	strcpy(newNode->student.ban, ban);
	newNode->student.score = score;
	return newNode;
}

//����ڵ�(���ѧ��)
void insetNode(Node* headList)
{
	char id[10];
	char name[10];
	int age;
	char ban[10];
	int score;
	printf("������ѧ����ѧ�ţ�\n");
	scanf("%s", id, 10);
	printf("������ѧ����������\n");
	scanf("%s", name, 10);
	printf("������ѧ�������䣺\n");
	scanf("%d", &age);
	printf("������ѧ���İ༶��\n");
	scanf("%s", ban, 10);
	printf("������ѧ���ɼ���\n");
	scanf("%d", &score);
	printf("\n��ӳɹ�\n\n");
	Node* newNode = setNode(id, name, age, ban,score);
	newNode->next = headList->next;
	headList->next = newNode;
}

//ɾ���ڵ�(ɾ��ѧ����Ϣ)
void deleteList(Node* headList)
{
	printf("������Ҫɾ��ѧ����������\n");
	char name[10] = { " " };
	scanf_s("%s", name, 10);
	Node* pre = headList;
	Node* pMove = headList->next;
	if (pMove == NULL)
	{
		printf("����û�����ѧ��\n");
	}
	else
	{
		while (strcmp(pMove->student.name, name) != 0)
		{
			pre = pMove;
			pMove = pMove->next;
		}
		if (pMove == NULL)
		{
			printf("û�и�ѧ����ѧ�ţ��޷�ɾ��");
		}

		pre->next = pMove->next;
		free(pMove);    //�����ڴ� 
	}
	printf("\nɾ���ɹ�\n\n");
}

//�޸�ѧ����Ϣ 
void reviseList(Node* list)
{
	Node* pre = list;
	Node* pMove = list->next;
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
	char ID[10] = { " " };
	scanf_s("%s", ID, 10);
	while (pMove != NULL)
	{
		if (strcmp(pMove->student.id, ID) == 0)
		{
			printf("������Ҫ�޸ĵ�ѧ����Ϣ��\n");
			printf("1.ѧ��\n");
			printf("2.����\n");
			printf("3.����\n");
			printf("4.�༶\n");
			printf("5.�ɼ�\n");
			char op = _getch();
			switch (op)
			{
			case '1':
				printf("�������µ�ѧ�ţ�\n");
				scanf("%s", &pMove->student.id);
				break;
			case '2':
				printf("�������µ�������\n");
				scanf("%s", &pMove->student.name);
				break;
			case '3':
				printf("�������µ����䣺\n");
				scanf_s("%d", &pMove->student.age);
				break;
			case '4':
				printf("�������µİ༶��\n");
				scanf("%s", &pMove->student.ban);
				break;
			case '5':
				printf("�������µĳɼ���\n");
				scanf("%d",&pMove->student.score);
				break;
			}
			break;
		}
		pre = pMove;
		pMove = pMove->next;
	}
	if (pre->next == NULL)
	{
		printf("\nû���ҵ���������Ϣ\n");
	}
	else
	{
		printf("\n\n�޸ĳɹ�\n\n");
	}
}


//����ѧ����Ϣ
void findList(Node* list)
{
	Node* pre = list;
	Node* pMove = list->next;

	printf("������Ҫ����ѧ����ѧ��:\n");
	char id[10] = { " " };
	scanf_s("%s", id, 10);
	while (pMove != NULL)
	{
		if (strcmp(pMove->student.id, id) == 0)
		{
			printf("\n���ҳɹ�\n\n");
			printf("|---------------|---------------|---------------|-------------|-----------------|\n");
			printf("|ѧ��\t\t|����\t\t|����\t\t|�༶\t      |�ɼ�\t\t|\n");
			printf("|---------------|---------------|---------------|-------------|-----------------|\n");
			printf("|%s\t\t|%s\t\t|%d\t\t|%s\t      |%d\t\t|", pMove->student.id, pMove->student.name, pMove->student.age, pMove->student.ban, pMove->student.score);
			printf("\n");
			printf("|---------------|---------------|---------------|-------------|-----------------|\n");
			break;
		}
		pre = pMove;
		pMove = pMove->next;
	}
	if (pre->next == NULL)
	{
		printf("\nû���ҵ���������Ϣ\n");
	}

}

//��ʾȫ��ѧ����Ϣ
void printList(Node* list)
{
	Node* pMove = list->next;
	if (pMove == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	printf("|---------------|---------------|---------------|-------------|-----------------|\n");
	printf("|ѧ��\t\t|����\t\t|����\t\t|�༶\t      |�ɼ�\t\t|\n");
	printf("|---------------|---------------|---------------|-------------|-----------------|\n");
	while (pMove != NULL)
	{
		printf("|%s\t\t|%s\t\t|%d\t\t|%s\t      |%d\t\t|", pMove->student.id, pMove->student.name, pMove->student.age, pMove->student.ban, pMove->student.score);
		printf("\n");
		pMove = pMove->next;
	}
	printf("|---------------|---------------|---------------|-------------|-----------------|\n");
	printf("\n");
}

//ͳ��ѧ������
void countStudent(Node* list) {
	printf("--------------------------\n");
	printf("*      ͳ�ƽ������      *\n");
	printf("--------------------------\n");
	int count = 0;
	Node* move = list->next;
	while (move != NULL) {
		count++;
		move = move->next;
	}
	printf("ѧ��������Ϊ:\t%d\n", count);
	printf("--------------------------\n");
	system("pause");//��ͣ
	//����
	system("cls");
}

//�ɼ�����
void sortStudent(Node* list) {
	Node* save = NULL;
	Node* move = NULL;
	for (Node* turn = list->next; turn->next != NULL; turn = turn->next) {
		for (move = list->next; move->next != save; move = move->next) {
			if (move->student.score > move->next->student.score) {
				Student temp = move->student;
				move->student = move->next->student;
				move->next->student = temp;
			}
		}
		save = move;
	}
	printList(list);
}




//ɾ��ȫ����ͬԪ��
void DeleteAll(Node* headList)
{
	printf("������Ҫɾ��ѧ����������\n");
	char name[10] = { " " };
	scanf_s("%s", name, 10);

	Node* p = headList->next;
	Node* q = headList;
	Node* s;
	if (p == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	while (p != NULL)
	{
		if (strcmp(p->student.name, name) == 0)
		{
			s = p;
			p = p->next;
			q->next = p;
			free(s);
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	printf("\nɾ���ɹ�\n");
}

//�˵�
void Menu()
{
	printf("|====================================|");
	printf("\n|      ��ӭ����ѧ����Ϣ����ϵͳ      |\n");
	printf("|------------------------------------|\n");
	printf("|         1.���ѧ����Ϣ             |\n");
	printf("|------------------------------------|\n");
	printf("|         2.ɾ��ѧ����Ϣ             |\n");
	printf("|------------------------------------|\n");
	printf("|         3.�޸�ѧ����Ϣ             |\n");
	printf("|------------------------------------|\n");
	printf("|         4.����ѧ����Ϣ             |\n");
	printf("|------------------------------------|\n");
	printf("|         5.��ʾȫ��ѧ����Ϣ         |\n");
	printf("|------------------------------------|\n");
	printf("|         6.ɾ��������ͬ������ѧ��   |\n");
	printf("|------------------------------------|\n");
	printf("|         7.ͳ��ѧ������             |\n");
	printf("|------------------------------------|\n");
	printf("|         8.��ѧ���ɼ���������       |\n");
	printf("|------------------------------------|\n");
	printf("|         0.�˳�����                 |\n");
	printf("|====================================|\n\n");
	printf("����������ѡ��\n");
}

//����
void Keydown(Node* list)
{
	char op = _getch();
	switch (op)
	{
	case '1':
		insetNode(list);
		break;
	case '2':
		deleteList(list);
		break;
	case '3':
		reviseList(list);
		break;
	case '4':
		findList(list);
		break;
	case '5':
		printList(list);
		break;
	case '6':
		DeleteAll(list);
		break;
	case '7':
		countStudent(list);
		break;
	case '8':
		sortStudent(list);
		break;
	case '0':
		exit(0);
	}
}
int main()
{
	Node* list = headNode();
	while (1)
	{
		Menu();
		Keydown(list);
		system("pause");
		system("cls");
	}
	return 0;
}