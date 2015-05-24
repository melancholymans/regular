#include <assert.h>
#include <stdio.h>
#include "reg.h"


Thread thread(Inst *pc, char *sp)
{
	ready[]
}

//非再帰的な実装
int backtraackingvm(Inst *prog, char *input)
{
	int nready;
	Inst *pc;
	char *sp;

	ready[0] = thread(prog, input);
	return 0;
}

//ループと再帰を組み合わせた実装
int recursiveloop(Inst *pc, char *sp)
{
	for (;;){
		switch (pc->opcode){
		case Char:
			if (*sp != pc->c){
				return 0;
			}
			pc++;
			sp++;
			continue;
		case Match:
			return 1;
		case Jmp:
			pc = pc->x;
			continue;
		case Split:
			if (recursiveloop(pc->x, sp)){
				return 1;
			}
			pc = pc->y;
			continue;
		}
		assert(0);
		return 1;
	}
}

//再帰的な実装
int recursive(Inst *pc, char *sp)
{
	switch(pc->opcode){
	case Char:
		if (*sp != pc->c){
			return 0;
		}
		return recursive(pc + 1, sp + 1);
	case Match:
		return 1;
	case Jmp:
		return recursive(pc->x, sp);
	case Split:
		if (recursive(pc->x, sp)){
			return 1;
		}
		return recursive(pc->y, sp);
	}
	assert(0);
	return 1;
}

int main()
{
	char str[] = "aab";
	struct Inst op_string[16];
	//a+b+の定義,正規表現(a+b+)をこの仮想語に変換するのはどのプログラムだろう
	op_string[0].opcode = Char;
	op_string[0].c = 'a';
	op_string[1].opcode = Split;
	op_string[1].x = &op_string[0];
	op_string[1].y = &op_string[2];
	op_string[2].opcode = Char;
	op_string[2].c = 'b';
	op_string[3].opcode = Split;
	op_string[3].x = &op_string[2];
	op_string[3].y = &op_string[4];
	op_string[4].opcode = Match;

	//printf("recursive = %d\n",recursive(op_string,str));
	printf("recursive = %d\n", recursiveloop(op_string, str));
	getchar();
	return 0;
}