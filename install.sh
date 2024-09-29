#!/bin/sh

gcc src/main.c -o freaky -pedantic-errors -Werror
mv freaky /usr/local/bin/
