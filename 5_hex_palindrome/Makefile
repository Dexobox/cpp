all: hex_pal rev_pal

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

