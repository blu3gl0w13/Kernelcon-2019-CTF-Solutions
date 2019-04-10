---
title: "he-is-going-to-eat-the-goat"
date: "Fri Feb 22 18:09:10 UTC 2019"
layout: post
draft: false
path: ""
category: "REVERSE"
tags:
  - "reverse"
  - "strings"
  - "base64"
description: "Hunt the flag like the T-Rex hunts the goat..."
---

##Start
Download the 'trex.jpg' and either run strings against it to find the base64 encoded flag in the output,
or use xxd.

```

$ strings trex.jpg
$ xxd trex.jpg
$ echo [base64 encoded flag] |base64 -d -

```

##Conclusion

The flag is a base64 encoded blob hidden within a binary appended to the end of the JPG file.
