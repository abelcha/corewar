.name "Torpille"
.comment "by sebc"
.extend

	xor	r4,r4,r4
//      08   54 04 04 04
//	     V
//	  01 = r = registre
//	3 registres donc 1010101 + 00 = 54 en hexa
	
debut:
	fork	%:debut2
//	0c	0044 
//		 V
//	adresse de ":debut2" = +68

	st	r1, :ld1+1
//	03   70 01	06 (on compte depuis le nb de l'instruction)
//           V
//	octet de c.	 70 = 0111000000 = 11 + 1 = reg + indirect
	
ld1:	live	%0
//	01	000000
//		V
//	numero du joueur --> situe dans la premiere valeur directe
	
	# process qui dit live pour T1
	st	r1, :live1+1
//	03	70  0014 (= n + 18 = addresse de live1)
	ld	%-10, r2
//	02  90	fffff06 ( = unsigned -10) 02 --> r2
//           V
//	octet de codage(10 + 01)	
	ld	%1, r3
live1:	live	%4
	add	r2, r3, r2
	zjmp	%:live1b
	xor	r4, r4, r4
	zjmp	%:live1
live1b:	ld	%-10, r2
	xor	r4, r4, r4
	zjmp	%:live1

debut2:
	st	r1, :live2+10
	# process qui dit live pour T2
	st	r1, :live2+1
	ld	%-10, r2
	ld	%1, r3

	fork	%:debut
live2:	live	%4
	add	r2, r3, r2
	zjmp	%:live2b
	xor	r4, r4, r4
	zjmp	%:live2

live2b:	ld	%-10, r2
	xor	r4, r4, r4
	zjmp	%:live2

