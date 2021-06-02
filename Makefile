CC = g++
CFLAGS = -g -Wall -Werror

TARGET = bank

OBJS = \
        main.o\
	./login-module/login.o\
	./get_info/getinfo.o\
	./create-user/signup.o\

EXEC = \
        bank\


$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.o : 
	$(CC) $(CFLAGS) -c $@.cpp -o $@.o

clear : $(OBJS) $(EXEC)
	rm $?
