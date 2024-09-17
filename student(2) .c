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

//建立节点
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

//插入节点(添加学生)
void insetNode(Node* headList)
{
	char id[10];
	char name[10];
	int age;
	char ban[10];
	int score;
	printf("请输入学生的学号：\n");
	scanf("%s", id, 10);
	printf("请输入学生的姓名：\n");
	scanf("%s", name, 10);
	printf("请输入学生的年龄：\n");
	scanf("%d", &age);
	printf("请输入学生的班级：\n");
	scanf("%s", ban, 10);
	printf("请输入学生成绩：\n");
	scanf("%d", &score);
	printf("\n添加成功\n\n");
	Node* newNode = setNode(id, name, age, ban,score);
	newNode->next = headList->next;
	headList->next = newNode;
}

//删除节点(删除学生信息)
void deleteList(Node* headList)
{
	printf("请输入要删除学生的姓名：\n");
	char name[10] = { " " };
	scanf_s("%s", name, 10);
	Node* pre = headList;
	Node* pMove = headList->next;
	if (pMove == NULL)
	{
		printf("您还没有添加学生\n");
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
			printf("没有该学生的学号，无法删除");
		}

		pre->next = pMove->next;
		free(pMove);    //清理内存 
	}
	printf("\n删除成功\n\n");
}

//修改学生信息 
void reviseList(Node* list)
{
	Node* pre = list;
	Node* pMove = list->next;
	printf("请输入要修改的学生的学号：\n");
	char ID[10] = { " " };
	scanf_s("%s", ID, 10);
	while (pMove != NULL)
	{
		if (strcmp(pMove->student.id, ID) == 0)
		{
			printf("请输入要修改的学生信息：\n");
			printf("1.学号\n");
			printf("2.姓名\n");
			printf("3.年龄\n");
			printf("4.班级\n");
			printf("5.成绩\n");
			char op = _getch();
			switch (op)
			{
			case '1':
				printf("请输入新的学号：\n");
				scanf("%s", &pMove->student.id);
				break;
			case '2':
				printf("请输入新的姓名：\n");
				scanf("%s", &pMove->student.name);
				break;
			case '3':
				printf("请输入新的年龄：\n");
				scanf_s("%d", &pMove->student.age);
				break;
			case '4':
				printf("请输入新的班级：\n");
				scanf("%s", &pMove->student.ban);
				break;
			case '5':
				printf("请输入新的成绩：\n");
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
		printf("\n没有找到该生的信息\n");
	}
	else
	{
		printf("\n\n修改成功\n\n");
	}
}


//查找学生信息
void findList(Node* list)
{
	Node* pre = list;
	Node* pMove = list->next;

	printf("请输入要查找学生的学号:\n");
	char id[10] = { " " };
	scanf_s("%s", id, 10);
	while (pMove != NULL)
	{
		if (strcmp(pMove->student.id, id) == 0)
		{
			printf("\n查找成功\n\n");
			printf("|---------------|---------------|---------------|-------------|-----------------|\n");
			printf("|学号\t\t|姓名\t\t|年龄\t\t|班级\t      |成绩\t\t|\n");
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
		printf("\n没有找到该生的信息\n");
	}

}

//显示全部学生信息
void printList(Node* list)
{
	Node* pMove = list->next;
	if (pMove == NULL)
	{
		printf("链表为空\n");
		return;
	}
	printf("|---------------|---------------|---------------|-------------|-----------------|\n");
	printf("|学号\t\t|姓名\t\t|年龄\t\t|班级\t      |成绩\t\t|\n");
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

//统计学生人数
void countStudent(Node* list) {
	printf("--------------------------\n");
	printf("*      统计结果如下      *\n");
	printf("--------------------------\n");
	int count = 0;
	Node* move = list->next;
	while (move != NULL) {
		count++;
		move = move->next;
	}
	printf("学生总人数为:\t%d\n", count);
	printf("--------------------------\n");
	system("pause");//暂停
	//清屏
	system("cls");
}

//成绩排序
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




//删除全部相同元素
void DeleteAll(Node* headList)
{
	printf("请输入要删除学生的姓名：\n");
	char name[10] = { " " };
	scanf_s("%s", name, 10);

	Node* p = headList->next;
	Node* q = headList;
	Node* s;
	if (p == NULL)
	{
		printf("链表为空\n");
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
	printf("\n删除成功\n");
}

//菜单
void Menu()
{
	printf("|====================================|");
	printf("\n|      欢迎来到学生信息管理系统      |\n");
	printf("|------------------------------------|\n");
	printf("|         1.添加学生信息             |\n");
	printf("|------------------------------------|\n");
	printf("|         2.删除学生信息             |\n");
	printf("|------------------------------------|\n");
	printf("|         3.修改学生信息             |\n");
	printf("|------------------------------------|\n");
	printf("|         4.查找学生信息             |\n");
	printf("|------------------------------------|\n");
	printf("|         5.显示全部学生信息         |\n");
	printf("|------------------------------------|\n");
	printf("|         6.删除名字相同的所有学生   |\n");
	printf("|------------------------------------|\n");
	printf("|         7.统计学生人数             |\n");
	printf("|------------------------------------|\n");
	printf("|         8.对学生成绩进行排序       |\n");
	printf("|------------------------------------|\n");
	printf("|         0.退出程序                 |\n");
	printf("|====================================|\n\n");
	printf("请输入您的选择：\n");
}

//操作
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