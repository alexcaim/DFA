
*************************

Pentru implementare am folosit o matrice de perechi cu n coloane,
o matrice care arată pe poziția (i,j) care a fost starea precedenta de pe
linia i - 1, precum și simbolul utilizat pentru tranziție. Cu un algoritm
de programare dinamică am construit matricea până în momentul în care 
am ajuns într-o stare finală. 

Odată găsit răspunsul, am reconstruit traseul, pornind din starea finală.
Acest string a fost inversat ulterior.

Pentru a optimiza căutarea am ales să găsesc înainte de construirea matricii
nodurile care nu au drum către o stare finală, astfel în momentul în care 
întâlneam un astfel de nod, nu realizam nicio tranziție.
