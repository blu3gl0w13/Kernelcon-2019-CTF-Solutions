---
title: "creation-is-an-act-of-sheer-will"
date: "Fri Feb 22 23:55:23 CST 2019"
layout: post
draft: false
path: ""
category: "MISC"
tags:
  - "obfuscation"
  - "strings"
  - "hexadecimal editor'
description: "Hatch the egg to find the flag..."
---

##Start
Use a hexadecimal tool against the JPG file to see two .jpg files archived within. Use 'unzip'
to extract the multiple contained JPG files. Use 'xxd' against the hatched.jpg to find the flag.

```
$ xxd mystery-egg.jpg
$ unzip mystery-egg.jpg 

When prompted, pick 'y' to overwrite mystery-egg.jpg

$ xxd hatched.jpg
```

##Conclusion

The flag is appended to the end of the hatched.jpg file.
