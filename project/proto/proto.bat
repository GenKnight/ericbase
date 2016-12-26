set rpc_proto_dir=G:\SolutionSample\project\BasePlatform\src\proto
set cpp_out_dir=G:\SolutionSample\project\BasePlatform\src\proto

"G:\SolutionSample\contrib\google\protobuf\bin\protoc.exe" --proto_path=%rpc_proto_dir% --cpp_out=%cpp_out_dir% ^
%rpc_proto_dir%\basehead.proto ^
%rpc_proto_dir%\ReqSubProcessListInfo.proto ^
%rpc_proto_dir%\ReqSubSystemInfo.proto ^
%rpc_proto_dir%\RtnProcessLogInfo.proto