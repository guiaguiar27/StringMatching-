all:
	gcc main.c Util/Driver.c Util/Cadeia.c ForcaBruta/ForcaBruta.c BMH/BMH.c ShiftAndAP/ShiftAndAP.c -o main
execute:
	./main
clean:
	rm main