# Print VM
A simple VM that only does printing

### How it works
It reads in 8 chars at a time. If first char is 0, it consider rest 7 chars as function definition. Otherwise, it considers rest as function execution. 


Function definition: first 3 chars are function name, next 3 chars are function definition, last char is useless


Function execution: first 3 chars are function name, next 4 chars are function arguments (each arg is one char)


In CFG:
```FUNCTION_NAME -> 001 | 011 | 111 | 100 | 110 | 000
FUNCTION_ARGS -> 1 | 0 | FUNCTION_ARGS
FUNCTION_DEF -> FUNCTION_NAME.FUNCTION_NAME.FUNCTION_ARGS1
FUNCTION_EXEC -> FUNCTION_NAME.FUNCTION_ARGS
PROGRAM -> 0FUNCTION_DEF | 1FUNCTION_EXEC
```

### Run
```
mkdir build && cd build
cmake .. && make
./vm testfile
```

