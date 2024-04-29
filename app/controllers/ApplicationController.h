#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H
#include<iostream>
#include <string>
#include "./../../app/views/home_view.cpp"
#include "./../../app/views/about_view.cpp"
class ApplicationController {
	public:
	 virtual ~ApplicationController() {}

 	std::string home() {
				HomeView home_view;
				home_view.buildContent();
				return home_view.buildHtmlPage();
		}

		std::string about() {
				AboutView about_view;
				about_view.buildContent();
				return about_view.buildHtmlPage();
		}
};
#endif
