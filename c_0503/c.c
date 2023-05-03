#include <stdio.h>
#include <stdlib.h>
// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); //[juht]
}
// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐 출력 함수
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
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
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
		printf("1_숫자삽입 2_하나 출력 3_모두 출력 4_종료 : ");
		scanf_s("%d", &c);

		switch (c) {
		case 1:
			if (!is_full(&queue)) {
				printf("숫자 입력하십시오오: ");
				scanf_s("%d", &element);
				enqueue(&queue, element);
				queue_print(&queue);
				printf("--데이터 추가 완료--\n");
			}
			else {
				printf("큐는 포화상태입니다.\n\n");
			}
			break;
		case 2:
			if (!is_empty(&queue)) {
				element = dequeue(&queue);
				printf("꺼내진 정수: %d \n", element);
				queue_print(&queue);
				printf("--데이터 삭제 완료--\n");
			}
			else {
				printf("큐는 공백상태입니다.\n");
			}break;
		case 3:
			while (!is_empty(&queue)) {
				printf("--데이터 삭제 단계--\n");
				element = dequeue(&queue);
				printf("꺼내진 정수: %d \n", element);
				queue_print(&queue);
			}break;
		case 4:
			printf("종료되었습니다.");
			return 0;
		}
	}
	return 0;
}