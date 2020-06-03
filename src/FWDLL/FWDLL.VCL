<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: FWDLL - Win32 (WCE x86em) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\banwait.CSE\LOCALS~1\Temp\RSP776.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "i486" /D UNDER_CE=300 /D _WIN32_WCE=300 /D "WIN32" /D "STRICT" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "WIN32_PLATFORM_PSPC" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_AFXDLL" /D "_AFXEXT" /FR"X86EMDbg/" /Fp"X86EMDbg/FWDLL.pch" /Yu"stdafx.h" /Fo"X86EMDbg/" /Fd"X86EMDbg/" /Gz /c 
"Z:\Embedded Systems\Prism\EVC++\FWDLL\AcceptConnectionThread.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\BottomBorderConnector.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\Connection.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\DetectDisconnectionThread.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\MonitorConnectionThread.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\ReadConnectionThread.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\ReconnectThread.cpp"
"Z:\Embedded Systems\Prism\EVC++\FWDLL\TopBorderConnector.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\banwait.CSE\LOCALS~1\Temp\RSP776.tmp" 
Creating temporary file "C:\DOCUME~1\banwait.CSE\LOCALS~1\Temp\RSP777.tmp" with contents
[
/nologo /stack:0x10000,0x1000 /dll /incremental:yes /pdb:"X86EMDbg/FWDLL.pdb" /debug /def:".\FWDLL.def" /out:"X86EMDbg/FWDLL.dll" /implib:"X86EMDbg/FWDLL.lib" /windowsce:emulation /MACHINE:IX86 
".\X86EMDbg\AcceptConnectionThread.obj"
".\X86EMDbg\Address.obj"
".\X86EMDbg\Architecture.obj"
".\X86EMDbg\ArchitectureAdapter.obj"
".\X86EMDbg\ArchitectureEvent.obj"
".\X86EMDbg\BottomBorderConnector.obj"
".\X86EMDbg\Brick.obj"
".\X86EMDbg\BrickThread.obj"
".\X86EMDbg\C2Object.obj"
".\X86EMDbg\Component.obj"
".\X86EMDbg\ComponentThread.obj"
".\X86EMDbg\Connection.obj"
".\X86EMDbg\Connector.obj"
".\X86EMDbg\ConnectorThread.obj"
".\X86EMDbg\DetectDisconnectionThread.obj"
".\X86EMDbg\Dispatch.obj"
".\X86EMDbg\EventObject.obj"
".\X86EMDbg\FIFODispatch.obj"
".\X86EMDbg\FWDLL.obj"
".\X86EMDbg\Long.obj"
".\X86EMDbg\Message.obj"
".\X86EMDbg\Monitor.obj"
".\X86EMDbg\MonitorConnectionThread.obj"
".\X86EMDbg\Notification.obj"
".\X86EMDbg\Peer.obj"
".\X86EMDbg\PeerConnector.obj"
".\X86EMDbg\PeerConnectorThread.obj"
".\X86EMDbg\ReadConnectionThread.obj"
".\X86EMDbg\ReconnectThread.obj"
".\X86EMDbg\Request.obj"
".\X86EMDbg\RoundRobinScheduler.obj"
".\X86EMDbg\Scaffold.obj"
".\X86EMDbg\Scheduler.obj"
".\X86EMDbg\StdAfx.obj"
".\X86EMDbg\TopBorderConnector.obj"
".\X86EMDbg\WorkerThread.obj"
".\X86EMDbg\FWDLL.res"
]
Creating command line "link.exe @C:\DOCUME~1\banwait.CSE\LOCALS~1\Temp\RSP777.tmp"
<h3>Output Window</h3>
Compiling...
AcceptConnectionThread.cpp
BottomBorderConnector.cpp
Connection.cpp
DetectDisconnectionThread.cpp
MonitorConnectionThread.cpp
ReadConnectionThread.cpp
ReconnectThread.cpp
TopBorderConnector.cpp
Generating Code...
Linking...
LINK : LNK6004: X86EMDbg/FWDLL.dll not found or not built by the last incremental link; performing full link
   Creating library X86EMDbg/FWDLL.lib and object X86EMDbg/FWDLL.exp
Creating temporary file "C:\DOCUME~1\banwait.CSE\LOCALS~1\Temp\RSP77D.tmp" with contents
[
/nologo /o"X86EMDbg/FWDLL.bsc" 
".\X86EMDbg\StdAfx.sbr"
".\X86EMDbg\AcceptConnectionThread.sbr"
".\X86EMDbg\Address.sbr"
".\X86EMDbg\Architecture.sbr"
".\X86EMDbg\ArchitectureAdapter.sbr"
".\X86EMDbg\ArchitectureEvent.sbr"
".\X86EMDbg\BottomBorderConnector.sbr"
".\X86EMDbg\Brick.sbr"
".\X86EMDbg\BrickThread.sbr"
".\X86EMDbg\C2Object.sbr"
".\X86EMDbg\Component.sbr"
".\X86EMDbg\ComponentThread.sbr"
".\X86EMDbg\Connection.sbr"
".\X86EMDbg\Connector.sbr"
".\X86EMDbg\ConnectorThread.sbr"
".\X86EMDbg\DetectDisconnectionThread.sbr"
".\X86EMDbg\Dispatch.sbr"
".\X86EMDbg\EventObject.sbr"
".\X86EMDbg\FIFODispatch.sbr"
".\X86EMDbg\FWDLL.sbr"
".\X86EMDbg\Long.sbr"
".\X86EMDbg\Message.sbr"
".\X86EMDbg\Monitor.sbr"
".\X86EMDbg\MonitorConnectionThread.sbr"
".\X86EMDbg\Notification.sbr"
".\X86EMDbg\Peer.sbr"
".\X86EMDbg\PeerConnector.sbr"
".\X86EMDbg\PeerConnectorThread.sbr"
".\X86EMDbg\ReadConnectionThread.sbr"
".\X86EMDbg\ReconnectThread.sbr"
".\X86EMDbg\Request.sbr"
".\X86EMDbg\RoundRobinScheduler.sbr"
".\X86EMDbg\Scaffold.sbr"
".\X86EMDbg\Scheduler.sbr"
".\X86EMDbg\TopBorderConnector.sbr"
".\X86EMDbg\WorkerThread.sbr"]
Creating command line "bscmake.exe @C:\DOCUME~1\banwait.CSE\LOCALS~1\Temp\RSP77D.tmp"
Creating browse info file...
<h3>Output Window</h3>



<h3>Results</h3>
FWDLL.dll - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
