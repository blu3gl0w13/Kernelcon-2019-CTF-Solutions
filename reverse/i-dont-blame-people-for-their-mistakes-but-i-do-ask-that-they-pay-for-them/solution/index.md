---
title: "i-dont-blame-people-for-their-mistakes-but-i-do-ask-that-they-pay-for-them"
date: "Fri Feb 22 20:21:39 UTC 2019"
layout: post
draft: false
path: ""
category: "REVERSE"
tags:
  - "reverse"
  - "strings"
  - "debugger"
description: "Somebody thought hiding the flag using hexadecimal was a good idea...."
---

##Start
Download the mistakes binary along with the main-func-dump.png. Use a debugger to identify
the flag. The characters making up the flag have been encoded in hexadecimal. Convert the
hexadecimal to retrieve the flag.

If you don't have a debugger installed, you can use the attached "main-func-dump.png" to
look at the main function disassembly.


```
$ gdb -q ./mistakes
(gdb) set disassembly-flavor intel
(gdb) layout asm
(gdb) layout reg
(gdb) break main
(gdb) run

OR

$ edb --run ./mistakes

```
Continue to use the "nexti" instruction until the last "mov" instruction executes, then type the following.

```
x/s $rsp

```
##Conclusion

Once all of the MOV instructions have executed, the stack should contain the whole flag. We can examine the stack using the "x/s $rsp" instruction.
