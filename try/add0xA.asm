section .text
global _start
_start:
  mov rax, 1
  mov rdi, 1
  mov rsi, str
  ;add rsi, 0xA
  mov rdx, 12
  syscall

  mov rax, 60
  mov rdi, 0
  syscall


section .data
  str: db "Hello World", 0xA
