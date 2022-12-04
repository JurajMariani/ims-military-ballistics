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
	$(CC) $(CFLAGS) -DEXP1	 $(LDFLAGS) $(SOURCES) -o $(EXE)_exp1
	$(CC) $(CFLAGS) -DEXP2	 $(LDFLAGS) $(SOURCES) -o $(EXE)_exp2
	$(CC) $(CFLAGS) -DEXP3	 $(LDFLAGS) $(SOURCES) -o $(EXE)_exp3
	

clean:
	@rm -f $(EXE)
	@rm -f $(EXE)_exp1
	@rm -f $(EXE)_exp2
	@rm -f $(EXE)_exp3
	
