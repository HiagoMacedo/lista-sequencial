APP = main.out
CXX = g++
VERSION = c++11
CXXFLAGS = -Wall -Werror -std=$(VERSION)
RM = rm -f

SRCS = main.cpp 
OBJS = $(subst .cpp,.o,$(SRCS))

all: $(APP) ;

$(APP): $(OBJS)
	$(CXX) -o $(APP) $(OBJS) 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(APP)