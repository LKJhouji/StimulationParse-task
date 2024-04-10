# StimulationParse-task

FileReader includes MAT/MDF(didn't finish)/MF4/CSV/STI FileReader

+ STI FileReader input file path, output SignalDescriptionSet. The STI file's version is 2.2.0.
+ MAT FileReader use Matio to parse, input file path, output SignalValue. But the 'fcnVector' of SignalValue seems like working worse. Always return 0. I try to read many documents about how to use Matio. But it doesn't work. If you want to learn about Matio or something else to parse MAT file, you can some help-documents I provide in helpDocument file.
+ MDF FileReader is the only one I can't finish. I didn't find a useful tool to parse MDF file in c++. But I can provide a tool in C# which may be able to parse MDF file. It called OrcaMDF. You can search it on github. SQL MDF server can provide you with opening MDF file. But I tried, with the result error. I don't know why.
+ MF4 FileReader I provide two tools to parse it. Firstone is mdf4lib-linux. It gives me two interfaces to read or write MF4 file. I use read-one. Another tool is libmdf4. I didn't use this, because there is no help-document for me to know how to use it.
+ CSV FileReader use Stream class can be parsed.

ParseXml includes parse sti file and put it into SignalDescriptionSet. You can use ParseXmlTest to know those function's meaning.

SignalDescription includes all kinds of signals and their relationship. SOSignalDescription's pointer points to SegmentSignalDescription or OperationSignalDescription. 

SignalGenerator helps SignalDescriptionSet switch to SignalValue. It is used in STI file.

TinyXml is a famous tool to parse STI file. You can download or git pull it from github.

Value includes SignalValue and SignalGroupValue. You only use SignalValue to load data.