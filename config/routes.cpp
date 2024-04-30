#include "./../lib/httplib.h"
#include "./../app/controllers/ApplicationController.h"

int chosenPort = 8080;

void runServer(){
	httplib::Server svr;

	svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
			PagesController controller;
			res.set_content(controller.home(), "text/html");
	});

	svr.Get("/about", [](const httplib::Request& req, httplib::Response& res) {
			PagesController controller;
			res.set_content(controller.about(), "text/html");
	});

	svr.Get("/services", [](const httplib::Request& req, httplib::Response& res) {
			PagesController controller;
			res.set_content(controller.services(), "text/html");
	});

	svr.Get("/contact", [](const httplib::Request& req, httplib::Response& res) {
			PagesController controller;
			res.set_content(controller.contact(), "text/html");
	});

	svr.set_error_handler([](const httplib::Request& req, httplib::Response& res) {
		res.status = 404; // Set HTTP status code to 404
		PagesController controller;
  res.set_content(controller.not_found(), "text/html"); // Response body
	});

	// Attempt to run the HTTP server on the chosen port
	if (!svr.listen("localhost", chosenPort)) {
			std::cerr << "Failed to start server on port " << chosenPort << ". Trying a different port." << std::endl;

			// Try generating a new random port and run the server again
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> dist(8081, 65535); // Start from 8081 to avoid privileged ports
			chosenPort = dist(gen);
			runServer(); // Recursively try a new port
	}
}

// Function to open the default web browser and navigate to the specified URL
void openBrowser(const std::string& url) {
			#ifdef _WIN32
			// Windows-specific code using ShellExecute
			ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
			#elif __APPLE__
			// macOS-specific code using system call to open
			system(("open " + url).c_str());
			#else
			// Linux-specific code using system call to xdg-open
			system(("xdg-open " + url).c_str());
			#endif
}
