#Mukundan Sridharan (mukundan.sridharan@samraksh.com)
#Copyright: The Samraksh Company


param (
    [Parameter(HelpMessage="Specify app bin file to convert")][string]$BinFile,
    [Parameter(HelpMessage="Specify app platform to be used: stm32|adapt|sf2")][string]$GCCVER = "5.4.1",
    [Parameter(HelpMessage="Specify app platform to be used: stm32|adapt|sf2")][string]$Platform = "stm32"
)

if ($BinFile -eq ""){
    echo "Pass a binary file as first argument that needs to converted to S19  ";
    exit
}


#$Binfile="TestSuite.dat";
$ToolDir= "..\Tools\";
#$ObjDir = $MFDir + "\BuildOutput\public\Debug\Client\dat";
$ToolChainBin = "..\Compilers\GCC" + $GCCVER + "\bin\" ;
$ObjTool = "$ToolChainBin\arm-none-eabi-objcopy.exe";
$Tool = "$ToolDir\binToSrec.exe";


#Output files
$OTemp = "$BinFile.srec";
#Remove .dat from input file and replace with .S19
$OutFile = $BinFile + ".s19" ;


#Find a suitable baseaddress for the platform
$BaseAddress;
if($Platform -eq "stm32") {
    $BaseAddress="080a0000";
}
elseif ($Platform -eq "adapt") {
    $BaseAddress="80700000";
}
elseif ($Platform -eq "sf2") {
    $BaseAddress="60065800";
}

write-host "Using App base address $BaseAddress, assuming its for  ...";
write-host "Converting file $BinFile ...";

#chdir $ObjDir;
$cmd = "$Tool -b $BaseAddress -i $BinFile -o $OTemp";
write-host "Executing: $cmd";
Invoke-Expression $cmd;
$cmd = "$ObjTool $OTemp $OutFile";
write-host "Executing: $cmd";
Invoke-Expression $cmd;

write-host "Done.";