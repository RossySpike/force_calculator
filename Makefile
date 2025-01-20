compile:
	gcc force_calculator.c -o force_calculator
run:
	./force_calculator $(WEIGHT) $(DISTANCE) $(TIME)
clean:
	rm force_calculator

