all:
	$(MAKE) -C src $(MAKECMDGOALS)
	./src/sample.exe --help

clean:
	$(MAKE) -C src $(MAKECMDGOALS)
