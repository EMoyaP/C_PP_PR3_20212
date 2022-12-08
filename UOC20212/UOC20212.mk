##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=UOC20212
ConfigurationName      :=Release
WorkspacePath          :=/home/uoc/Desktop/UOC20212
ProjectPath            :=/home/uoc/Desktop/UOC20212
IntermediateDirectory  :=build-$(ConfigurationName)
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
OutputFile             :=./bin/$(ProjectName)d
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOC20212.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)test/include $(IncludeSwitch)UOCVaccine/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UOCVaccine 
ArLibs                 :=  "libUOCVaccine.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr3.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d build-$(ConfigurationName) || $(MakeDirCommand) build-$(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d build-$(ConfigurationName) || $(MakeDirCommand) build-$(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix): test/src/test.c $(IntermediateDirectory)/test_src_test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/test/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test.c$(DependSuffix): test/src/test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test.c$(DependSuffix) -MM test/src/test.c

$(IntermediateDirectory)/test_src_test.c$(PreprocessSuffix): test/src/test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test.c$(PreprocessSuffix) test/src/test.c

$(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix): test/src/test_pr2.c $(IntermediateDirectory)/test_src_test_pr2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/test/src/test_pr2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr2.c$(DependSuffix): test/src/test_pr2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr2.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr2.c$(DependSuffix) -MM test/src/test_pr2.c

$(IntermediateDirectory)/test_src_test_pr2.c$(PreprocessSuffix): test/src/test_pr2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr2.c$(PreprocessSuffix) test/src/test_pr2.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix): test/src/test_suite.c $(IntermediateDirectory)/test_src_test_suite.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/test/src/test_suite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_suite.c$(DependSuffix): test/src/test_suite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_suite.c$(DependSuffix) -MM test/src/test_suite.c

$(IntermediateDirectory)/test_src_test_suite.c$(PreprocessSuffix): test/src/test_suite.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_suite.c$(PreprocessSuffix) test/src/test_suite.c

$(IntermediateDirectory)/test_src_test_pr3.c$(ObjectSuffix): test/src/test_pr3.c $(IntermediateDirectory)/test_src_test_pr3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/test/src/test_pr3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr3.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr3.c$(DependSuffix): test/src/test_pr3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr3.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr3.c$(DependSuffix) -MM test/src/test_pr3.c

$(IntermediateDirectory)/test_src_test_pr3.c$(PreprocessSuffix): test/src/test_pr3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr3.c$(PreprocessSuffix) test/src/test_pr3.c

$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix): test/src/test_pr1.c $(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOC20212/test/src/test_pr1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix): test/src/test_pr1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix) -MM test/src/test_pr1.c

$(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix): test/src/test_pr1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix) test/src/test_pr1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r build-$(ConfigurationName)/


