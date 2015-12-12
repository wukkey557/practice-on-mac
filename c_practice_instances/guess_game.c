/*
猜拳小程序

键盘缓冲区数据只有在遇到回车时才会把数据流传到输入流缓冲区(stdin),scanf(or getchar)只从输入流缓冲区读数据,如果输入流缓冲区为空,
则等待用户输入(若输入流缓冲区不为空则不等待用户输入),用户输入完毕之后,数据从键盘缓冲区传送到输入流缓冲区,
scanf检测到输入流缓冲区有数据后,按照指定format取数据;

test:

#include <stdio.h>

int main() {
	char player;
	char a;

	scanf("%c", &player);
	scanf("%c", &a);

	printf("%d, %d\n", player, a);
}

输入1后即输出49和10,即字符1和换行符line feed;
说明键盘缓冲区: '1', '\n' ----> 输入流缓冲区: '1', '\n' --->  scanf取走'1',输入流缓冲区残留'\n' ---> 第二次scanf直接读取'\n',不等待输入;

mingw:

typedef struct _iobuf
{
	char*	_ptr;//指向当前缓冲区读取位置
	int	_cnt;//缓冲区中剩余数据长度
	char*	_base;
	int	_flag;
	int	_file;
	int	_charbuf;
	int	_bufsiz;
	char*	_tmpfname;
} FILE;

getchar实现:

__CRT_INLINE int __cdecl __MINGW_NOTHROW getchar (void)
{
  return (--stdin->_cnt >= 0)
    ?  (int) (unsigned char) *stdin->_ptr++
    : _filbuf (stdin);
}

其中stdin为File*类型;

fgets(buf, BUF_LEN, stdin) : 会取输入的前BUF_LEN个字符,然后末尾加上'\n';

为清楚缓冲区,比较好的方法:

int a;
while ((a = getchar()) != '\n' && a != EOF);

或:

scanf("%c%*c", &a); //从缓冲区多输出一个字符,但不赋值;

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static int NUM_FOR_ROCKS = 10;
static int NUM_FOR_PAPERS = 13;
static int NUM_FOR_SCISSORS = 16;

int main() {
	int pc;
	char player;
	int result;

	while (1) {
		printf("please enter your choice:\n");
		printf("A: rocks\n");
		printf("B: papers\n");
		printf("C: scissors\n");
		printf("D: exit game\n");
		scanf("%c%*c", &player);

		switch (player) {
			case 'A':
			case 'a':
				result = NUM_FOR_ROCKS;
				printf("you chose rocks\n");
				break;
			case 'B':
			case 'b':
				result = NUM_FOR_PAPERS;
				printf("you chose papers\n");
				break;
			case 'C':
			case 'c':
				result = NUM_FOR_SCISSORS;
				printf("you chose scissors\n");
				break;
			case 'D':
			case 'd':
				printf("game's over\n");
				return 0;
			default:
				printf("input illegal\n");
				system("clear");
				return 0;
		}

		srand( (unsigned)time(NULL) );
		pc = rand() % 3;

		switch (pc) {
			case 0:
				printf("pc chose rocks\n");
				result += 0;
				break;
			case 1:
				printf("pc chose papers\n");
				result += 1;
				break;
			case 2:
				printf("pc chose scissors\n");
				result += 2;
				break;
		}
		/*
		  所有组合数为3 * 3 == 9种, 
		  玩家获胜: 10+2 || 13+0 || 16+1
		  电脑获胜: 10+1 || 13+2 || 16+0
		  否则平局
		*/
		if (result == 12 || result == 13 || result == 17) {
			printf("you win!\n");
		} else if (result == 11 || result == 15 || result == 16) {
			printf("pc wins!\n");
		} else {
			printf("play even\n");
		}

		system("read -n 1 && clear");
	}

	return 0;
}