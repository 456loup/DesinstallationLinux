
#!/bin/bash

apt rdepends $1 | sed -E "s/.*://" > transition.txt

sed "/$1/d"   transition.txt > autre.txt 

sed "/^$/d" autre.txt > transition.txt 

sed "s/[[:space:]]//" transition.txt > autre.txt

rm transition.txt 
