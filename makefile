# IMS project 2022 - 09 Balistika ve vojenstvi
# @authors: 
#	xmaria03 <xmaria03 AT stud.fit.vutbr.cz>,
#	xmacej03 <xmacej03 AT stud.fit.vutbr.cz>
#

CC=g++
CFLAGS=-g -O2 -Wall -std=c++11
LDFLAGS=-lsimlib -lm
SOURCES=main.cpp missile.cpp sim_specs.cpp hamas.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=iron_dome_sim

all:
	$(CC) $(CFLAGS) -DNORMAL $(LDFLAGS) $(SOURCES) -o $(EXE)
#	$(CC) $(CFLAGS) -DE_PEAK $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXE)_peak
#	$(CC) $(CFLAGS) -DE_OPENING $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXE)_opening
#	$(CC) $(CFLAGS) -DE_CLOSING $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXE)_closing
#	$(CC) $(CFLAGS) -DE_NORMAL $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXE)_normal

#run:
#	@echo "Running experiments"
#	@rm -rf ./experiments
#	@mkdir experiments 2>/dev/null
#	./$(EXECUTABLE) > ./experiments/typical.output
#	./$(EXECUTABLE)_opening > ./experiments/opening.output
#	./$(EXECUTABLE)_normal > ./experiments/normal.output
#	./$(EXECUTABLE)_peak > ./experiments/peak.output
#	./$(EXECUTABLE)_closing > ./experiments/closing.output

#clean:
#	@rm -rf $(EXECUTABLE)* *.o* ./experiments