enum{
	Char,
	Match,
	Jmp,
	Split
};

struct Inst{
	int opcode;
	int c;
	Inst *x;
	Inst *y;
};

struct Thread{
	Inst *pc;
	char *sp;
};

enum{ MAXTHREAD = 1000 };
Thread ready[MAXTHREAD];
