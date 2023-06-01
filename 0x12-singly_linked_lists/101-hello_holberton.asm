section .data
	format db 'Hello, Holberton\n', 0

section .text
	extern printf

global main
main:
	sub rsp, 8
	mov edi, format
	xor eax, eax
	call printf
	add rsp, 8
	mov eax, 0
	ret
