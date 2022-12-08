##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=UOCVaccine
ConfigurationName      :=Release
WorkspacePath          :=/home/uoc/Desktop/UOC20212
ProjectPath            :=/home/uoc/Desktop/UOC20212/UOCVaccine
IntermediateDirectory  :=../bin/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=uoc
Date                   :=19/05/22
CodeLitePath           :=/home/uoc/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../lib/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOCVaccine.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_date.c$(ObjectSuffix) $(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix) $(IntermediateDirectory)/src_person.c$(ObjectSuffix) $(IntermediateDirectory)/src_appointment.c$(ObjectSuffix) $(IntermediateDirectory)/src_stock.c$(ObjectSuffix) $(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IntermediateDirectory)/src_csv.c$(ObjectSuffix) $(IntermediateDirectory)/src_center.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/uoc/Desktop/UOC20212/.build-release"
	@echo rebuilt > "/home/uoc/Desktop/UOC20212/.build-release/UOCVaccine"

MakeIntermediateDirs:
	@test -d ../bin/Debug || $(MakeDirCommand) ../bin/Debug


../bin/Debug:
	@test -d ../bin/Debug || $(MakeDirCommand) ../bin/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_date.c$(ObjectSuffix): src/date.c $(IntermediateDirectory)/src_date.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/date.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_date.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_date.c$(DependSuffix): src/date.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_date.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_date.c$(DependSuffix) -MM src/date.c

$(IntermediateDirectory)/src_date.c$(PreprocessSuffix): src/date.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_date.c$(PreprocessSuffix) src/date.c

$(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix): src/vaccine.c $(IntermediateDirectory)/src_vaccine.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/vaccine.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_vaccine.c$(DependSuffix): src/vaccine.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_vaccine.c$(DependSuffix) -MM src/vaccine.c

$(IntermediateDirectory)/src_vaccine.c$(PreprocessSuffix): src/vaccine.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_vaccine.c$(PreprocessSuffix) src/vaccine.c

$(IntermediateDirectory)/src_person.c$(ObjectSuffix): src/person.c $(IntermediateDirectory)/src_person.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/person.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_person.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_person.c$(DependSuffix): src/person.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_person.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_person.c$(DependSuffix) -MM src/person.c

$(IntermediateDirectory)/src_person.c$(PreprocessSuffix): src/person.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_person.c$(PreprocessSuffix) src/person.c

$(IntermediateDirectory)/src_appointment.c$(ObjectSuffix): src/appointment.c $(IntermediateDirectory)/src_appointment.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/appointment.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_appointment.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_appointment.c$(DependSuffix): src/appointment.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_appointment.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_appointment.c$(DependSuffix) -MM src/appointment.c

$(IntermediateDirectory)/src_appointment.c$(PreprocessSuffix): src/appointment.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_appointment.c$(PreprocessSuffix) src/appointment.c

$(IntermediateDirectory)/src_stock.c$(ObjectSuffix): src/stock.c $(IntermediateDirectory)/src_stock.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/stock.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_stock.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_stock.c$(DependSuffix): src/stock.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_stock.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_stock.c$(DependSuffix) -MM src/stock.c

$(IntermediateDirectory)/src_stock.c$(PreprocessSuffix): src/stock.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_stock.c$(PreprocessSuffix) src/stock.c

$(IntermediateDirectory)/src_api.c$(ObjectSuffix): src/api.c $(IntermediateDirectory)/src_api.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/api.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_api.c$(DependSuffix): src/api.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_api.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_api.c$(DependSuffix) -MM src/api.c

$(IntermediateDirectory)/src_api.c$(PreprocessSuffix): src/api.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_api.c$(PreprocessSuffix) src/api.c

$(IntermediateDirectory)/src_csv.c$(ObjectSuffix): src/csv.c $(IntermediateDirectory)/src_csv.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/csv.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_csv.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_csv.c$(DependSuffix): src/csv.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_csv.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_csv.c$(DependSuffix) -MM src/csv.c

$(IntermediateDirectory)/src_csv.c$(PreprocessSuffix): src/csv.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_csv.c$(PreprocessSuffix) src/csv.c

$(IntermediateDirectory)/src_center.c$(ObjectSuffix): src/center.c $(IntermediateDirectory)/src_center.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/UOCVaccine/src/center.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_center.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_center.c$(DependSuffix): src/center.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_center.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_center.c$(DependSuffix) -MM src/center.c

$(IntermediateDirectory)/src_center.c$(PreprocessSuffix): src/center.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_center.c$(PreprocessSuffix) src/center.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../bin/Debug/


