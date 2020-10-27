    ORG 0000H
	AJMP MAIN

	ORG 0100H
NUM1:   DB 99H,88H,77H
NUM2: 	DB 77H,88H,99H
N1:		DB 03H
NUM3:	DB 88H,88H
NUM4:	DB 79H
N2:		DB 02H
	
MAIN:
	MOV SP,#30H		;栈地址
	
	MOV A,#0		;0->A
	MOV DPTR,#N1	;#N1->DPTR
	MOVC A,@A+DPTR	;((A) + DPTR)->A
	MOV R7,A		;(A)->R7			;将N保存到R7
	ACALL ADD_N_N	;调用加法子程序
	ACALL SUB_N_N	;调用减法子程序
	
	MOV A,#0		;0->A
	MOV DPTR,#N2	;#N1->DPTR
	MOVC A,@A+DPTR	;((A) + DPTR)->A
	MOV R7,A		;(A)->R7			;将N保存到R7
	ACALL MUL_N_1	;调用加法子程序
	ACALL DIV_N_1	;调用减法子程序
	
	LJMP TO_END		;结束



ADD_N_N:
	MOV A,R7		;(R7)->A
	PUSH Acc		;保护A
	MOV R0,#58H		;结果保存在地址50H
    ;MOV R7,#03		;循环三次
LOOP_ADD:
    MOV A,R7		;(R7) -> A		
    DEC A			;A--,作为偏移地址

	MOV DPTR,#NUM1	;NUM1 -> DPTR,最为取值基地址
    MOVC A,@A+DPTR	;(A + DPTR) -> A,取字节
	MOV R1,A		;(A) -> R1
	
	MOV A,R7		;(R7) -> A		
    DEC A			;A--,作为偏移地址
    MOV DPTR,#NUM2	;NUM2 -> DPTR,最为取值基地址
    MOVC A,@A+DPTR	;(A + DPTR) -> A,取字节
	MOV R2,A		;(A) -> R2

    MOV A,R1		;(R1) -> A
    ADDC A,R2		;带进位的加法A = A + R2
    MOV @R0,A		;(A) -> (R0)
	INC R0			;R0++
    
    DJNZ R7,LOOP_ADD	;R7--,判断是否循环
	CLR A			;清空A
	ADDC A,#0		;将最终进位放入A
	MOV @R0,A		;(A) -> (R0)
	INC R0			;R0++
	POP Acc
	MOV R7,Acc
	RET
SUB_N_N:
	MOV R0,#60H		;结果保存在地址50H
    ;MOV R7,#03		;循环三次
	MOV A,R7
	PUSH Acc
LOOP_SUB:
	
    MOV A,R7		;(R7) -> A	
    DEC A			;A--,作为偏移地址

    MOV DPTR,#NUM1	;NUM1 -> DPTR,最为取值基地址
    MOVC A,@A+DPTR	;(A + DPTR) -> A,取字节
	MOV R1,A		;(A) -> R1
	
	MOV A,R7		;(R7) -> A		
    DEC A			;A--,作为偏移地址
    MOV DPTR,#NUM2	;NUM2 -> DPTR,最为取值基地址
    MOVC A,@A+DPTR	;(A + DPTR) -> A,取字节
	MOV R2,A		;(A) -> R2

    MOV A,R1		;(R1) -> A
    SUBB A,R2		;带进位的加法A = A + R2
    MOV @R0,A		;(A) -> (R0)
	INC R0			;R0++
    
    DJNZ R7,LOOP_SUB	;R7--,判断是否循环
	CLR A			;清空A
	SUBB A,#0		;将最终进位放入A
	MOV @R0,A		;(A) -> (R0)
	INC R0			;R0++
	POP Acc
	MOV R7,Acc
	RET
MUL_N_1:
	MOV A,R7		;(R7)->A
	PUSH Acc		;A入栈
	MOV R0,#68H		;68H->R0,结果保存的地址
	MOV A,#0		;0->A
	MOV DPTR,#NUM4	;#NUM4->DPTR
	MOVC A,@A+DPTR	;((A)+DPTR)->A	;取数
	MOV R1,A		;(A)->R1			;乘数放到R1
	MOV R3,#0		;#0->R3,置零
	CLR C			;Cy清零
LOOP_MUL:
	MOV A,R7		;(R7)->A
	DEC A			;A--
	MOV DPTR,#NUM3	;#NUM3->DPTR
	MOVC A,@A+DPTR	;((A)+DPTR)->A
	MOV B,R1		;(R1)->B
	MUL AB			;A*B，高位保存到B中，低位保存A中
	ADDC A,R3		;(A)+(R3)->A，加数加到低位中
	MOV @R0,A		;(A)->(R0)，保存到RAM中
	INC R0			;R0++，指向下一个
	MOV R3,B		;(B)->R3，高位变为下一个加数
	
	DJNZ R7,LOOP_MUL;循环，R7--
		
	MOV A,R3		;(R3)->A
	ADDC A,#0		;#0->A，将进位加到A中
	MOV @R0,A		;(A)->(R0)，保存到RAM中
	INC R0			;R0++,指向下一个
	POP Acc			;A出栈
	MOV R7,Acc		;(Acc)->R7
	RET				;返回子程序
	
DIV_N_1:
	MOV A,R7		;(R7)->A
	MOV R5,A		;备份次数
	PUSH Acc		;A入栈
	MOV R0,#70H		;70H->R0,结果保存的地址
	MOV A,#0		;0->A
	MOV DPTR,#NUM4	;#NUM4->DPTR
	MOVC A,@A+DPTR	;((A)+DPTR)->A	;取数
	MOV R1,A		;a除数->R1
	MOV R3,#00H		;R3清零
	CLR C			;Cy清零
	MOV R4,#0H		;R4 = 0
LOOP_DIV_1:
	MOV A,R5		;(R5)->A,总次数
	PUSH PSW		;PSW（cy）入栈
	SUBB A,R7		;A -= （R7），计算偏移地址
	POP PSW			;PSW出栈
	MOV DPTR,#NUM3	;#NUM3->DPTR
	MOVC A,@A+DPTR	;((A)+DPTR)->A	;取数
	MOV R2,A		;(A)->R2
	MOV R6,#08H		;每个字节循环次数8
LOOP_DIV_2:
	MOV A,R2		;(R2)->A
	CLR C			;C = 0
	RLC A			;带进位的左移
	MOV R2,A		;(R2)->A
	MOV A,R3		;(R3)->A
	RL A			;A左移
	ANL A,#0FEH		;末位置零
	ADDC A,R4		;连带R2的最高位和R4加到A中
	MOV R3,A		;(A)->R3

	MOV A,R4		;(R4)->A
	JNZ SET1		;比较并跳转
COMPARE:
	MOV A,R3		;(R3)->A
	MOV 50H,R1		;(R1)->50H,暂存R1在50H
	CJNE A,50H,NO_EQ	;R1 不等于 R3 则跳转到NO_EQ
	SJMP AEQ		;否则相等，跳转到AEQ
	
NO_EQ:
	JNC AEQ			;Cy == 0,R1 > R3,与等于的处理方式相同，跳转到AEQ
 	CLR C			;否则小于，Cy清零
	SJMP CMPLOW		;跳转到CMPLOW
AEQ:
	MOV A,R3		;（R3）-> A
	SUBB A,R1		;A = A - （R1）
	MOV R3,A		;（A）-> R3，减去一个除数
	MOV A,R2		;(R2)->A
	ORL A,#01H		;末位置一
	MOV R2,A		;(A)->R2
	SJMP NEXT		;跳转NEXT
CMPLOW:
	MOV A,R3		;（R3）-> A
	ADDC A,#80H		;A += #80H,判断最高位是否为1
	JC ONE			;如果为1，并且当前R1 < R3，需跳转ONE
	CLR C			;否则结果下一结果C = 0
	SJMP NEXT		;跳转Next
ONE:
	MOV A,#00H		;#100H(00H)-> A
	CLR C
	SUBB A,R1		;100H - R1 -> A
	MOV R4,A		;(A)->R4
	SJMP NEXT
SET1:
	MOV R4,#00H		;R4 = 0
	MOV A,R2		;(R2)->A
	ORL A,#01H		;末位置一
	MOV R2,A		;(A)->R2
	SJMP COMPARE	;跳转
NEXT:
	DJNZ R6,LOOP_DIV_2	;循环
	MOV A,R2		;(R2)->A
	MOV @R0,A		;保存结果
	INC R0			;R0++
	DJNZ R7,LOOP_DIV_1	;循环
	
	MOV @R0,#0ffH	;保存ff作为分隔符
	INC R0			;R0++
	MOV @R0,#0ffH	;保存ff作为分隔符
	INC R0			;R0++
	MOV A,R3		;(R3)->A
	MOV @R0,A		;保存余数
	INC R0			;R0++
	POP Acc			;A出栈
	MOV R7,Acc		;(A)->R7,恢复R7
	RET				;结束子程序
TO_END:		
END					;结束