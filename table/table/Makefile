$(TABLE)/$(STATIC):$(OBJ1)
	ar rcs    $@ $^ 
$(TABLE)/src/%.o:$(TABLE)/src/%.cpp
	$(CC) $(DEBUG) $(CXXFLAGS) $@ -c $^ $(INCLUDE_DIR) 
