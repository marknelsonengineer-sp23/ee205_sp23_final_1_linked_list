###############################################################################
### University of Hawaii, College of Engineering
### EE 205 - Spr 2023 - Final Exam 1 - Linked List
###
### @file    Makefile
### @author  Mark Nelson <marknels@hawaii.edu>
###############################################################################

TARGET = main

all:  $(TARGET)

CC        = g++
CFLAGS    = -Wall -Wextra $(DEBUG_FLAGS) -std=c++17 -march=native -mtune=native
MAKE      = make

debug: DEBUG_FLAGS = -g -DDEBUG -O0
debug: $(TARGET)

main: main.cpp Node.h List.h List.cpp
	$(CC) $(CFLAGS) -o main main.cpp List.cpp

test: test_Final.cpp Node.h List.h List.cpp
	$(CC) $(CFLAGS) -o boost_tests test_Final.cpp List.cpp
	./boost_tests --build_info --color_output --show_progress --report_format=HRF --report_level=short

doc: $(TARGET)
	.doxygen/stats.py
	doxygen .doxygen/Doxyfile
	rsync --recursive --mkpath --checksum --delete .doxygen/images  .doxygen/docs/html/.doxygen

publish: doc
	rsync --recursive --checksum --delete --compress --stats --chmod=o+r,Do+x .doxygen/docs/html/ marknels@uhunix.hawaii.edu:~/public_html/ee205/sp23_final_1_linked_list

clean:
	rm -f $(TARGET) *.o
