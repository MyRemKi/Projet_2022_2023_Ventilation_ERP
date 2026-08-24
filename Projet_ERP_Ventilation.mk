##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Projet_ERP_Ventilation
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/ir2/rkalkan/Documents/Projet_ERP_Ventilation/Projet_ERP_Ventilation
ProjectPath            :=/home/ir2/rkalkan/Documents/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Projet_ERP_Ventilation
IntermediateDirectory  :=../build-$(ConfigurationName)/Projet_ERP_Ventilation
OutDir                 :=../build-$(ConfigurationName)/Projet_ERP_Ventilation
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Remi KALKAN
Date                   :=05/22/23
CodeLitePath           :=/home/ir2/rkalkan/.codelite
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
LinkOptions            :=  $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)PocoDataODBC $(LibrarySwitch)PocoData $(LibrarySwitch)PocoFoundation 
ArLibs                 :=  "PocoDataODBC" "PocoData" "PocoFoundation" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Projet_ERP_Ventilation/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Projet_ERP_Ventilation"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Projet_ERP_Ventilation"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Projet_ERP_Ventilation/.d:
	@mkdir -p "../build-$(ConfigurationName)/Projet_ERP_Ventilation"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/rkalkan/Documents/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Projet_ERP_Ventilation/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(ObjectSuffix): Acces_BDD.cpp ../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/rkalkan/Documents/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Acces_BDD.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Acces_BDD.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(DependSuffix): Acces_BDD.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(DependSuffix) -MM Acces_BDD.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(PreprocessSuffix): Acces_BDD.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/Acces_BDD.cpp$(PreprocessSuffix) Acces_BDD.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(ObjectSuffix): App.cpp ../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/rkalkan/Documents/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Projet_ERP_Ventilation/App.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/App.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(DependSuffix): App.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(DependSuffix) -MM App.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(PreprocessSuffix): App.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/App.cpp$(PreprocessSuffix) App.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(ObjectSuffix): Thread_Puissance.cpp ../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/rkalkan/Documents/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Projet_ERP_Ventilation/Thread_Puissance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Thread_Puissance.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(DependSuffix): Thread_Puissance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(DependSuffix) -MM Thread_Puissance.cpp

../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(PreprocessSuffix): Thread_Puissance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Projet_ERP_Ventilation/Thread_Puissance.cpp$(PreprocessSuffix) Thread_Puissance.cpp


-include ../build-$(ConfigurationName)/Projet_ERP_Ventilation//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


