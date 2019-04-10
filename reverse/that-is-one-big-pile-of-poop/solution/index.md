---
title: "that-is-one-big-pile-of-poop"
date: "Sat Feb 23 17:31:52 CST 2019"
layout: post
draft: false
path: ""
category: "REVERSE"
tags:
  - "reverse"
  - "strings"
  - "debugger"
  - "hexadecimal"
description: "One of the dinosaurs ate the flag and, um, 'processed' it..."
---

##Start
Download the poop.jpg and the dinoDookie binary.
Run the binary to find out there's a shared library missing.

```
./dinoDookie

./dinoDookie: error while loading shared libraries: libtriceratop.so: cannot open shared object file: No such file or directory
+++ exited (status 127) +++
```
```
Examine the poop.jpg image using a hexadecimal viewer.

```
$ hexdump -C poop.jpg |grep ELF
```

Notice the ELF magic bytes are present. We need to grep for ELF
in the poop.jpg to figure out how many bytes into the jpg the
ELF binary exists. 

The output should resemble the following:

```
000213b0: 3fa9 7e10 799f ffd9 7f45 4c46 0201 0100  ?.~.y....ELF....
```

The ELF header always starts with the bytes 7F 45 4C 46. In
the above output, those bytes begin 8 bytes into that line. The
line starts at 000213b0, add 8 and we get 000213b8. Now we need
to convert that to ASCII. We do that with python.

```
python
>>> int('000213b8', 16)
136120
```

Now that we know how many bytes to skip in the JPG file, we
use 'dd' to copy from the JPG at the offset identified
out of the poop.jpg into a new file called 'libtriceratop.so'.

```
dd bs=1 skip=136120 if=poop.jpg of=libtriceratop.so

```

From here, sudo copy libtriceratop.so to /usr/local/lib/, or
export LD_LIBRARY_PATH environment variable to the local
directory.

```
export LD_LIBRARY_PATH=/path/to/libtriceratop.so:$LD_LIBRARY_PATH

```
Next, run "ltrace" against the binary to see if anything stands out.

```
ltrace ./dinoDookie
```
We notice the binary is looking for an environment variable called
SUSPECT. We'll need to find what this value should be.


```
getenv("SUSPECT")  
```

Next, examine the binary with GDB or EDB to learn the value of the
environment variable called 'SUSPECT' in order to decode
the hidden flag in the pile of poop. We need to run the binary
with the environment variable set on the command line.

Next either use GDB or EDB to visualize the correct password. Look
for the LEA/MOV instructions before the call to !getenv
Each LEA instruction should be examined using the "x/s <address>" 
command and each combination tried until the correct combination is found.

EDB Instructions
```
edb --run ./dinoDookie
press "Run"
scroll down the main disassembly window until you find the
possible passwords.

```
GDB Instructions
```
gdb -q ./dinoDookie
(gdb) set disassembly-flavor intel
(gdb) layout asm
(gdb) layout reg
(gdb) break main
(gdb) run
(gdb) nexti # continue until you see the first lea eax,[...]
(gdb) x/s 0x555555554e88   # prints smellyflag
(gdb) x/s 0x555555554e93   # prints stinkyflag
(gdb) x/s 0x555555554e9e   # prints smellystinkyflag (this is the correct password)
(gdb) x/s 0x555555554eaf   # prints SUSPECT (this is the environment variable)
(gdb) x/s 0x555555554f22   # prints brontosaurus
(gdb) x/s 0x555555554f69   # prints velociraptor
(gdb) x/s 0x555555554fa5   # prints stegasaurus
(gdb) x/s 0x555555555002   # prints triceratops
(gdb) x/s 0x555555555010   # prints "\n you might be onto something...." (this is the clue that triceratops is the correct value)

```


##Conclusion

Run the binary with the libtriceratop.so library in the local
directory and the correct 'SUSPECT' environment variable and
password like so.

```
$ SUSPECT="triceratops" ./dinoDookie smellystinkyflag

```
