cmd_/root/all_test/rootko.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /root/all_test/rootko.ko /root/all_test/rootko.o /root/all_test/rootko.mod.o
