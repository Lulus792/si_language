section .text
global _start
_start:
  mov rax, 10
  push rax
  mov rax, 5
  push rax
  mov rax, 0

_stack:
  pop rax
  ;mov rax, 1        ; doesnt shange the value
  ;mov (rax), 1 
  mov rbx, [rsp]
  ;mov rax, [rsp-4]  ; does not work
  
_exit:
  mov rax, 60
  syscall
