set rpc_proto_dir=I:\Ericbase\project\Person_\src
set cpp_out_dir=I:\Ericbase\project\Person_\src

"I:\Ericbase\contrib\google\protobuf\bin\protoc.exe" --proto_path=%rpc_proto_dir% --cpp_out=%cpp_out_dir% ^
%rpc_proto_dir%\person.proto