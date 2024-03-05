#LDFLAGS = -L./src_so -L./dataBase_so
#LIBS = -ljson-c -lsqlite3

$(TARGET):$(OBJ)
# $(CXX) -g $^ $(LDFLAGS) $(LIBS) -o $@
	$(CXX) -g $^ -o $@
%.o:%.cpp
	$(CXX) -g -c $^ -o $@

.PHONY:clean

clean:
	@$(RM) $(OBJ) $(TARGET)

show:
	@echo $(RM)
	@echo $(CC)
	@echo $(wildcard ./*.c)
	@echo $(OBJ)
	@echo $(CXX)