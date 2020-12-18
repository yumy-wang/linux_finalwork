server : server.cpp client.cpp
	g++ -o server server.cpp function_main.cpp CPluginEnumerator.cpp CPluginController.cpp IPrintPlugin.cpp -ldl
	g++ -o client client.cpp -g


