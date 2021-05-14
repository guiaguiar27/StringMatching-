all:
	gcc main.c Util/Driver.c Util/Chain.c BruteForce/BruteForce.c BMH/BMH.c ShiftAndAP/ShiftAndAP.c -o main
execute:
	./main
clean:
	rm main