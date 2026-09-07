#!/usr/bin/env python3

import sys

lines = [line.rstrip("\n") for line in sys.stdin]
lines = [line for line in lines if ":" in line]
lines.sort(key=lambda line: int(line.split(": ", 1)[1].replace("0x", ""), 16))

for line in lines:
    print(line)
