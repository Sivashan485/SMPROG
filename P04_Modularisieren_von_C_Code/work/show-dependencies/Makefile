SNP_SHARED_MAKEFILE := $(if $(SNP_SHARED_MAKEFILE),$(SNP_SHARED_MAKEFILE),"~/snp/shared.mk")

TARGET     := bin/dep2dot
# Add all additional c-files to the SOURCES variable
# BEGIN-STUDENTS-TO-ADD-CODE
SOURCES    := src/main.c
# END-STUDENTS-TO-ADD-CODE
TSTSOURCES := tests/tests.c

include $(SNP_SHARED_MAKEFILE)


# DEPFILES :=  ... define a list of png file names: %.c -> %.c.png
# BEGIN-STUDENTS-TO-ADD-CODE
DEPFILES := $(patsubst %.c, %.c.png, $(SOURCES))
# NOTES: Patsubst ersetzt die Endungen mit .c durch .c.Png 
# NOTES: $(SOURCES) ist die Variable die alle .c Dateien enthält. 
# END-STUDENTS-TO-ADD-CODE



# define dep target as .PHONEY
# BEGIN-STUDENTS-TO-ADD-CODE
.PHONEY: dep
# NOTES: .PHONEY ist ein pseudo ziel 

# BEGIN-STUDENTS-TO-ADD-CODE

dep: $(FULLTARGET)$(DEPFILES)
	@echo "the Target $@ is done"

# define dep target depending on FULLTARGET and DEPFILES above
# action: echo some text telling that the target is done using $@ - the echo command shall not be echoed before execution
# BEGIN-STUDENTS-TO-ADD-CODE


# BEGIN-STUDENTS-TO-ADD-CODE



# define new suffix rule for %.png depending on %.dot
# action: dot -Tpng $< >$@ || $(RM) $@
# BEGIN-STUDENTS-TO-ADD-CODE
%.png: %.dot
  dot -Tpng $< >$@ || $(RM) $@
# NOTES: png .dot ist die deklaration von dem suffix rule 
# NOTES: Der Befehl dot -Tpng $< >$@ || $(RM) $@ soll die .dot file in eine png.fil umwandlen.
# NOTES: Fall es kein Erfolg war soll die .png file gelöscht werden mittels RM befehls. 
# BEGIN-STUDENTS-TO-ADD-CODE



# define new suffix rule for %.dot depending on %.dep
# action: call $(TARGET) $(@:.dot=) <$< >$@ || $(RM) $@
# BEGIN-STUDENTS-TO-ADD-CODE
%.dot : %.dep
	$(TARGET) $(@:.dot=) <$< >$@ || $(RM) $@ 
#NOTES: Hier wird die Target befehl durchgeführt. 
#NOTES: Bei einem Fehlschlag wird die .dot file gelöscht mittels befehl RM.
#NOTES: @:.dot= ersetz die dot endung mit nichts
# BEGIN-STUDENTS-TO-ADD-CODE



# converts any .c file into a .c.dep file by means of GCC -H switch
# note: it removes intermediate files which were created as side effect
%.c.dep: %.c
	$(COMPILE.c) -H -o $@.x $< 2>$@ && $(RM) $@.x $@.d


# cleanup all results, including the ones od creating the dependencies
dep-clean: clean
	$(RM) $(DEPFILES) $(wildcard src/*.dep src/*.dot)

