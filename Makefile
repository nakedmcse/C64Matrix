all: C64Matrix.c
	gcc -O3 -o C64Matrix C64Matrix.c

c64:
	cl65 -o c64matrix.prg C64Matrix.c

disk:
	c1541 -format c64matrix,id d64 C64Matrix.d64 -attach C64Matrix.d64 -write c64matrix.prg

clean:
	rm -f C64Matrix.o
	rm -f c64matrix.prg