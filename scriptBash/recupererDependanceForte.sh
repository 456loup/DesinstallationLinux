#!/bin/bash



apt rdepends $1 > depForte.txt 2> /dev/null

sed -E 's/\(.*\)//' depForte.txt > transition

sed -E '/.*(Dépend|Pre-Depends|Recommande).*/!d' transition > depForte.txt

sed -E 's/^.*://'  depForte.txt > transition

sed -E 's/[[:space:]]//' transition > depForte.txt

sed '/^$/d'  depForte.txt > transition

cat transition > depForte.txt


rm transition
