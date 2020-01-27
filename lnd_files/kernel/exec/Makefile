CC = gcc
CFLAGS = 

default : 
	@echo -e "No targets specified\nUsage: make <target>"
	
execl : exec.c
	$(CC) $(CFLAGS) -DEXECL=1 $^ -o $@

execlp : exec.c
	$(CC) $(CFLAGS) -DEXECLP=1 $^ -o $@

execv : exec.c
	$(CC) $(CFLAGS) -DEXECV=1 $^ -o $@

execvp : exec.c
	$(CC) $(CFLAGS) -DEXECVP=1 $^ -o $@

execve : exec.c
	$(CC) $(CFLAGS) -DEXECVE=1 $^ -o $@

execle : exec.c
	$(CC) $(CFLAGS) -DEXECLE=1 $^ -o $@

execvpe : exec.c
	$(CC) $(CFLAGS) -DEXECVPE=1 $^ -o $@
	
envp : envp.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f execl execle execv execve execlp execvp execvpe envp
