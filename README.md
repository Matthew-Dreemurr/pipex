# Pipex



## Why does the code look weird ?

The 42 curriculum asks us to code according to the `Norme`, this standard forbids us certain control structures (like `do while`, `for`, ...), a limit of 25 lines and 5 variables per function, 5 function max per `.c` and and other constraints.

This project has been coded according to the `NormeV3` standard.

[NormeV3 PDF](https://github.com/42School/norminette) used in this projetc

[Norme repo](https://github.com/42School/norminette)



## How does the pipe work ?

To reproduce the pipe behviour we need too create a pipe that will redirect the input and output of eatch command we are going to execute a a child with `fork();`.

`ls -l | wc -l`

```
(stdin)  +-------+
-------->| ls -l |--+
         +-------+  |
                    | (stdout)
                   +-+
                   |P|
                   |I|
                   |P|
                   |E|
                   +-+
                    |
 (stdout) +------+  |(stdin)
<---------|wc -l |--+
          +------+
```




---
This work is published under the terms of **[42 Unlicense](https://github.com/gcamerli/42unlicense)**.
