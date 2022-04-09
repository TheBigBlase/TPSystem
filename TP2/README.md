# TP 2 (fork)

### make
J'ai fait un makefile, pour tester les questions 1-4, il faut executer
`make run` et pour la Q5 `make runq5`

### Q1 : 
On doit faire une chaine de N processus : 
on créer un nouveau processus si le processus parent
a pour PID 0. On recommence N fois.  

On attend ensuite que pour chaque processus, son fils soit sorti (exit)
puis on le ferme.  

Il y a un problème : en observant les processus a la sortie de la fonction
avec pstree, on voit que les processus ne s'`exit` pas, pourtant il ne continue
pas dans `main`. Je pense qu'il se bloquent sur le 
`while(wait(NULL)>0){exit(0);};` mais je ne sais pas pourquoi il ne s'`exit` pas.

### Q2 : 
On doit faire un arbre binaire de processus de profondeur N :
on boucle sur la profondeur souhaitée.
on part du parent. On creer un fils, puis un deuxieme en s'assurant que
le fils n'est pas affecté par cette opération. On attends ensuite que tout
ses fils s'arretent pour continuer.  

Il y a un problème : j'ai pas réussi à attendre le fils gauche.

### Q3 :
On doit créer un processus zombie pendant 10 secondes. 
On commence par fork un processus, on fait attendre le processus parent
et on exit l'enfant tout de suite.

### Q4 : 
On doit récupérer le code de retour d'un processus fils : pour cela on
utilise wait(&state), ou state est l'entier représentant le code de retour

### Q5 : 
On doit lancer n grep en paralelle, sur une liste de n fichier contenant un pattern.
On fork N foit, et on y execute `exec` sur un fichier de la liste.
On peut récupérer l'output et le pipe vers `STDOUT` pour bien verifier que 
cela fait ce que l'on veut.
