.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"

#.extended
#	sti	r1, %:live, %1			;change live by the right value
#	sti	r1, %:live2, %1			;change live by the right value
#	ld	%1, r3
#	ld	%33, r6

	#While (r2 < 10)
forks:
	ld 98, r0
	aff r0
	add	r2, r0, r2		;increment r2
	aff r2                   ;if (r4) {carry = 0}
live2:
	live 	%4
	zjmp	%:endwhile		;if (carry)
	fork	%:forks
	ld	%0, r4			;carry = 1
	zjmp	%:forks
	#EndWhile
endwhile:
	ld	%0, r4			;carry = 1

live:
	live %4
	zjmp %:live
