#include "./../../app/services/Html.h"
class HomeView : public Html {
	public:
		void buildContent() override {
			addStyle("h1#home", "padding-left", "5px");
			addElementTag("<h1 id='home'>Home Page</h1>");
		}
};