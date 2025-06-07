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
                // Start the HTTP server on port 8080 in a separate thread (a different port may be chosen if 8080 is unavailable)
			std::thread serverThread(runServer);

			// Wait for the server to start (optional)
			std::this_thread::sleep_for(std::chrono::seconds(1));

                        // Optionally open the browser in development builds
#ifdef OPEN_BROWSER
                        openBrowser("http://localhost:" + std::to_string(chosenPort));
#endif

			// Join the server thread to wait for it to finish (optional)
			serverThread.join();
		}
};
#endif
