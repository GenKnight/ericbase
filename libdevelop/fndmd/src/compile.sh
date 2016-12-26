g++ -fPIC -c FndMdClient.cpp -I/home/pztest/fndbase/lib/include/fndnet -I/home/pztest/fndbase/lib/include/fndmd  -I/home/pztest/fndbase/lib/include/market -I/home/pztest/fndbase/lib/include/s_utility
g++ -fPIC -c fndmd.cpp -I/home/pztest/fndbase/lib/include/fndnet -I/home/pztest/fndbase/lib/include/fndmd  -I/home/pztest/fndbase/lib/include/market -I/home/pztest/fndbase/lib/include/s_utility
ar rcs libfndmd.a fndmd.o FndMdClient.o
cp libfndmd.a /home/pztest/fndbase/lib/linux/

