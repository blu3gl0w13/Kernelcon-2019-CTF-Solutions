---
title: "they-should-all-be-destroyed"
date: "Sat Feb 23 03:41:42 UTC 2019"
layout: post
draft: false
path: ""
category: "REVERSE"
tags:
  - "reverse"
  - "strings"
  - "debugger"
description: "The velociraptors are very clever, kill and dissect the beast to find the flag."
---

##Start
Use a hexadecimal tool against the JPG file.

```
$ xxd velociraptor.jpg
$ echo '[b64 encoded blob]' |base64 -d
```

##Conclusion

The base64 encoded flag is near the bottom of the file.
