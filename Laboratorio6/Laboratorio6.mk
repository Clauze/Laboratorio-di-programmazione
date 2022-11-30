##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Laboratorio6
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/hulk/9/cb2032599/Esercizi
ProjectPath            :=/home/hulk/9/cb2032599/Esercizi/Laboratorio6
IntermediateDirectory  :=../build-$(ConfigurationName)/Laboratorio6
OutDir                 :=../build-$(ConfigurationName)/Laboratorio6
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=CLAUDIO BATTISTIN
Date                   :=30/11/22
CodeLitePath           :=/home/hulk/9/cb2032599/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Laboratorio6/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Laboratorio6/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Laboratorio6"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Laboratorio6"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Laboratorio6/.d:
	@mkdir -p "../build-$(ConfigurationName)/Laboratorio6"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Laboratorio6/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Laboratorio6/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hulk/9/cb2032599/Esercizi/Laboratorio6/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Laboratorio6/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Laboratorio6/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Laboratorio6/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Laboratorio6/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Laboratorio6/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(ObjectSuffix): MyVector.cpp ../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hulk/9/cb2032599/Esercizi/Laboratorio6/MyVector.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyVector.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(DependSuffix): MyVector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(DependSuffix) -MM MyVector.cpp

../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(PreprocessSuffix): MyVector.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Laboratorio6/MyVector.cpp$(PreprocessSuffix) MyVector.cpp


-include ../build-$(ConfigurationName)/Laboratorio6//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


