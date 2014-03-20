.name "lol"
.comment "lilolol"

	xor r4,r4,r4
debut:
	fork %:debut2
	st r1,:ld1
ld1:
	live %0
st	r1,:live1
	ld	%-10,r2
	ld	%1,r3

live1:
	live %4

	add r2,r3,r2
