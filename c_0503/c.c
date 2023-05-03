#include <stdio.h>
#include <stdlib.h>
// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); //[juht]
}
// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
int main(void)
{

	QueueType queue;
	int element;
	init_queue(&queue);

	while (1) {
		int c = 0;
		printf("1_���ڻ��� 2_�ϳ� ��� 3_��� ��� 4_���� : ");
		scanf_s("%d", &c);

		switch (c) {
		case 1:
			if (!is_full(&queue)) {
				printf("���� �Է��Ͻʽÿ���: ");
				scanf_s("%d", &element);
				enqueue(&queue, element);
				queue_print(&queue);
				printf("--������ �߰� �Ϸ�--\n");
			}
			else {
				printf("ť�� ��ȭ�����Դϴ�.\n\n");
			}
			break;
		case 2:
			if (!is_empty(&queue)) {
				element = dequeue(&queue);
				printf("������ ����: %d \n", element);
				queue_print(&queue);
				printf("--������ ���� �Ϸ�--\n");
			}
			else {
				printf("ť�� ��������Դϴ�.\n");
			}break;
		case 3:
			while (!is_empty(&queue)) {
				printf("--������ ���� �ܰ�--\n");
				element = dequeue(&queue);
				printf("������ ����: %d \n", element);
				queue_print(&queue);
			}break;
		case 4:
			printf("����Ǿ����ϴ�.");
			return 0;
		}
	}
	return 0;
}