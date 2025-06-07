#include "./../../app/views/pages/home_view.cpp"
#include "./../../app/views/pages/about_view.cpp"
#include "./../../app/views/pages/services_view.cpp"
#include "./../../app/views/pages/contact_view.cpp"
#include "./../../app/views/pages/not_found_view.cpp"

class PagesController {
	public:
	 virtual ~PagesController() {}

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

		std::string services() {
			ServicesView services_view;
			services_view.buildContent();
			return services_view.buildHtmlPage();
		}

		std::string contact() {
			ContactView contact_view;
			contact_view.buildContent();
			return contact_view.buildHtmlPage();
		}

		std::string not_found(){
			NotFoundView not_found_view;
			not_found_view.buildContent();
			return not_found_view.buildHtmlPage();
		}
};
