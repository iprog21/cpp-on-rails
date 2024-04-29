#ifndef APPLICATION_H
#define APPLICATION_H
#include<iostream>
#ifdef _WIN32
// Windows-specific includes and code
#include <winsock2.h>
#endif
#include "app/controllers/ApplicationController.h"
#include "config/routes.cpp"
class Application {
	public:
		int main(){
			call();

			return 0;
		}

 	void call(){
		// Start the HTTP server on port 8080 in a separate thread
			std::thread serverThread(runServer);

			// Wait for the server to start (optional)
			std::this_thread::sleep_for(std::chrono::seconds(1));

			// Open the browser and navigate to the URL
			openBrowser("http://localhost:" + std::to_string(chosenPort));

			// Join the server thread to wait for it to finish (optional)
			serverThread.join();
		}
};
#endif