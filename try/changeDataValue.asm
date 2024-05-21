section .text
global _start
_start:
  mov rsi, val
  ;add rsi, 0xA
  mov rax, 1
  mov rdi, 1
  mov rdx, 12
  syscall

  mov rax, 60
  mov rdi, 0
  syscall

section .data
  val: db "Hello World"
